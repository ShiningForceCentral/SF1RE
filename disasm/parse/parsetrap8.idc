
/*
 *	PARSETRAP8 SCRIPT 
 *	This script will scan "TRAP 8" instructions 
 *  and parse the preceding word to add corresponding dialog line in the comment,
 *  for easier code readability.
 *  Corresponding line is taken from the game's uncompressed scriptbanks,
 *  all compiled into one txt file thanks to rubixcuber's SF1Edit program.
 *  
 *  Execution requirement : put gamescript.txt in IDB directory.
 * 
 */

#include <idc.idc>

static main(void) {

	Message("SCANNING TRAP 8...\n");
	
	scanTrap8();
	Message("\nDONE.\n");
	
	Message("END OF TRAP 8 SCAN.\n");
	Batch(0);

}


static scanTrap8(){

	auto addr; // current location
	auto parameter; // parameter found after TRAP 8
	auto action; // comment update confirmation asked to user
	auto cont; // script continuation asked to user
	auto dialogLine;
	auto newComment; // comment to add
	auto textbanksFile, currentLine, lineNumber; 
	action = 1;
	cont = 1;
	addr=0;
	lineNumber = 0;
	action = AskYN(1,form("Start from current location 0x%s ?", ltoa(ScreenEA(),16)));
	if (action==-1) return;
	if (action==1){
		addr = ScreenEA();
	}
	Message(form("\nStarting from address 0x%s",ltoa(addr,16)));
	
	for(addr=FindBinary(addr+1,7,"4E 48");addr!=BADADDR;addr=FindBinary(addr+1,7,"4E 48")){
		dialogLine = "";
		Jump(addr);
		if(isCode(GetFlags(addr))){
		
			OpEnumEx(addr,0,GetEnum("Traps"),0);
		
			parameter = ltoa(Word(addr-2),16);
			while(strlen(parameter)<4){
				parameter=form("0%s",parameter);
			}
			Message(form("\nBinary value 0x4E48 with parameter value 0x%s at address 0x%s in code : searching for dialog line.",ltoa(Word(addr-2),16),ltoa(addr,16)));
			
			textbanksFile = fopen("gamescript.txt","r");
            lineNumber = 0;
			while(dialogLine==""){
				currentLine = readstr(textbanksFile);
                //Message(form("\nReading line %d : %s",lineNumber, currentLine));
				if(currentLine==-1){
					Message(form("\nCould not find dialog line for current parameter 0x%s",parameter));
					break;
				}
				if(lineNumber==Word(addr-2)){
					dialogLine = form("\"%s\"",substr(currentLine,0,strlen(currentLine)-1));
				}
                lineNumber = lineNumber + 1;
			}
			fclose(textbanksFile);
			
			if (dialogLine!=""){
				newComment = form(dialogLine);
				//action = AskYN(1,form("Update comment ? \nFrom %s\nTo : %s",CommentEx(addr-4,1), newComment));
				if (action==-1) return;
				if (action==1){
					Message(form("\n0x%s : %s changed to %s",ltoa(addr-2,16),CommentEx(addr-4,1), newComment));  
					MakeComm(addr-4,""); 
					MakeRptCmt(addr-4,newComment);
				}
				else{
					Message(form("\n0x%s : %s NOT changed to %s",ltoa(addr-2,16),CommentEx(addr-4,1), newComment));
				}
			}
			//cont = AskYN(1,"Continue ?");
			if (cont==-1 || cont==0) return;	
		}
		else{
			Message(form("\nBinary value 0x4E48 with parameter value 0x%s at address 0x%s not in code",ltoa(Word(addr-2),16),ltoa(addr,16)));
		}
	}
	
}


