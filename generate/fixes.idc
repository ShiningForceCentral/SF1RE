
/*
 *	FIXES SCRIPT 
 *	This script will contain all instruction for fixes
 *	on the IDB after the main IDC script has been applied.
 *
 *
 *	TABLE FIXES :
 * 	IDA's IDC export function does not properly export 
 *	the following structures, when they
 *	are located after address 0xFFFF :
 *	- Relative Jump Tables (RJT, labeled with prefix "rjt_")
 *	- Branch Tables (BT, labeled with prefix "bt_")
 *	- Relative Pointer Tables (RPT, labeled with prefix "rpt_")
 *	This script contains the needed instructions to 
 *	fix all the RJTs/BTs/RPTs that are defined in the IDB. 
 *	Beware :
 *	Everytime a new RJT/BT/RPT is defined after 0xFFFF, 
 *	it also has	to be defined in this script.
 *
 *	
 *	INSTRUCTION FIXES :
 *	Some instructions are not properly represented by IDA.
 *	Details in more comments below.
 *
 */

#include <idc.idc>

static main(void) {

	Message("FIXING...\n");

	Message("Relative Jump Tables...");
	fixRJTs();
	
	Message(" DONE.\nRelative Pointer Tables...");		
	fixRPTs();
	
/*	Message(" DONE.\nMap Setups RJTs...");	
	fixMapSetups();
	fixMapSetupsSection4();

	Message(" DONE.\nBranch Tables...");		
	fixBTs();
	Message(" DONE.\nInstruction Representations...");			
	fixInstructionRepresentations();
	Message(" DONE.\nSingle Instructions...");		
	fixSingleInstructions(); */
	
	Message(" DONE.\n");
	
	Message("END OF FIXES.\n");
	Batch(0);

}

static fixRJTs() {
	//makeRjt(0x10408,0x10410);
	//makeRjtWithOneWordBetweenEachEntry(0x22A22,0x22A48);
	makeRjt(0x1D6A,0x1D90);
	makeRjt(0x343A,0x3442);	
	makeRjt(0x3B06,0x3B16);	
	makeRjt(0x3F26,0x3F36);		
	makeRjt(0x3F4C,0x3F5A);		
	makeRjt(0x3F6E,0x3F76);	
	makeRjt(0x407C,0x408E);		
	makeRjt(0x40A2,0x40A8);	
	makeRjt(0x41EC,0x41F4);		
	makeRjt(0x4208,0x420B);		
	makeRjt(0x42EA,0x42FC);	
	makeRjt(0x4310,0x4316);		
	makeRjt(0x437A,0x4380);		
	makeRjt(0x43FE,0x4406);		
	makeRjt(0x44A0,0x44AE);		
	makeRjt(0x44C2,0x44C8);		
	makeRjt(0x45E2,0x45EE);		
	makeRjt(0x46FA,0x4706);	
	makeRjt(0x482A,0x4840);	
	makeRjt(0x4C22,0x4C32);
	makeRjt(0x5A78,0x5A80);	
	makeRjt(0x5B84,0x5B8C);	
	makeRjt(0x6038,0x6040);	
	makeRjt(0x628A,0x6292);
	makeRjt(0x6916,0x691E);		
	makeRjt(0x8DB8,0x8DC0);			
	makeRjt(0x93E4,0x944C);			
	makeRjt(0xA1A6,0xA1AE);			
	makeRjt(0xA374,0xA37C);			
	makeRjt(0xAB08,0xAB10);			
	makeRjt(0xABEE,0xABF6);			
	makeRjt(0xAC78,0xAC80);			
	makeRjt(0xADC8,0xADD0);		
	
	makeRjt(0x1240A8,0x1240CE);	
	makeRjt(0x124A14,0x124A1A);	
	makeRjt(0x124B8A,0x124B90);	
	makeRjt(0x124EE8,0x124F1A);	
	makeRjt(0x126498,0x126532);	
	makeRjt(0x127258,0x127283);	
	makeRjt(0x127E04,0x127E0C);	
	makeRjt(0x127E04,0x127E0C);		
	makeRjt(0x128106,0x12810E);	
	makeRjt(0x1282A8,0x1282B0);	
	makeRjt(0x128554,0x12855A);
	makeRjt(0x128FD6,0x129011);
	makeRjt(0x12A4EE,0x12A52A);		
	makeRjt(0x12ABE0,0x12AC1C);	
	makeRjt(0x12C200,0x12C208);	
	makeRjt(0x12C49C,0x12C4A6);	
									
}

static fixRPTs() {
	makeRpt(0x1E892,0x1E8D6);
}

static fixBTs() {
	//makeBt(0x4F1C,0x4FBC);
}


/*
 *	IDC SCRIPT : FIX INSTRUCTION REPRESENSATIONS
 *
 * 	It is known that IDA's mc68 module doesn't
 *	properly output certain instructions with 
 *	specific addressing modes. 
 *
 *	This script helps to fix these 
 *	instructions :  
 *	move.l a6,usp were displayed as move a6,usp.
 *	jsr (loc).w were displayed as jsr loc.
 *	jsr loc(pc) were displayed as jsr loc.
 *	jmp (loc).w were displayed as jmp loc.
 *	jmp loc(pc) were displayed as jmp loc.  
 *	lea loc(pc),a0 were displayed as lea loc, a0.
 *	lea loc(pc),a1 were displayed as lea loc, a1. 
 *	lea loc(pc),a2 were displayed as lea loc, a2. 
 *	lea loc(pc),a3 were displayed as lea loc, a3. 
 *	lea loc(pc),a4 were displayed as lea loc, a4. 
 *	lea loc(pc),a5 were displayed as lea loc, a5. 
 *	lea loc(pc),a6 were displayed as lea loc, a6. 
 *	lea loc(pc),a7 were displayed as lea loc, a7.
 *
 *	It finds every instructions 
 *	in formatted code and asks for each one
 *	of them if you want it to be properly formatted.
 *
 *	"No" skips the instruction.
 *	"Cancel" stops the script.
 *
 *	Be aware that it will only find instructions if they have been formatted as code. 
 *	They won't be identified if they are still known as pure data. 
 *
 */
static fixInstructionRepresentations(){
	
	auto batch;
	
	Batch(0);
	//batch = AskYN(1,"Fix Instruction Represensations : BATCH MODE ?");
	//if (batch==-1) return;
	//Batch(batch);
	
	fix("4E 66","move.l  a6,usp","move a6,usp","move.l a6,usp");
	
	fix("4E B8","jsr     (%s).w","jsr loc","jsr (loc).w");
	fix("4E BA","jsr     %s(pc)","jsr loc","jsr loc(pc)");
	fix("4E F8","jmp     (%s).w","jmp loc","jmp (loc).w");
	fix("4E FA","jmp     %s(pc)","jmp loc","jmp loc(pc)");
	
	fix("41 FA","lea     %s(pc), a0","lea loc, a0","lea loc(pc),a0");
	fix("43 FA","lea     %s(pc), a1","lea loc, a1","lea loc(pc),a1");
	fix("45 FA","lea     %s(pc), a2","lea loc, a2","lea loc(pc),a2");
	fix("47 FA","lea     %s(pc), a3","lea loc, a3","lea loc(pc),a3");
	fix("49 FA","lea     %s(pc), a4","lea loc, a4","lea loc(pc),a4");
	fix("4B FA","lea     %s(pc), a5","lea loc, a5","lea loc(pc),a5");
	fix("4D FA","lea     %s(pc), a6","lea loc, a6","lea loc(pc),a6");
	fix("4F FA","lea     %s(pc), a7","lea loc, a7","lea loc(pc),a7");

}

/*
 *	fixSingleInstructions()
 *
 *  Add a line to this function for every specific instruction that
 *  needs to be changed with its own individual logic.
 *
 *  For example, here we use OpHex commands to change falsely
 *  identified offsets into just hex values, so IDA doesn't create
 *  false xrefs and names.
 *
 */
 
static fixSingleInstructions(){

	OpHex(0x128C0,1);
	OpHex(0x19C58,0);	
	OpHex(0x1B3A0,0);
	OpHex(0x27982,1);
	OpHex(0x27A36,1);
	OpHex(0x27B16,0);
	OpHex(0x478A6,0);	

}

static fix(pattern, manualInstruction, wrongInstString, newInstString){

	auto addr; // current location
	auto opnd; // operand found at current location
	auto action; // action asked to user
	auto rep; // proper representation of instruction
	action = 1;
	
	// Start search from current address on screen
	for(addr=0;addr!=BADADDR;addr=FindBinary(addr+1,7,pattern)){
		opnd = GetOpnd(addr,0);
		if (opnd!=""){
			rep = form(manualInstruction,opnd);
			//Jump(addr);
			//action = AskYN(1,form("Change representation from %s to %s ?",wrongInstString, newInstString));
			if (action==-1) break;
			if (action==1){
				//Message(form("\n0x%d : %s changed to %s",addr,wrongInstString, newInstString));
				SetManualInsn(addr,rep);
			}
			else{
				//Message(form("\n0x%d : %s NOT changed to %s",addr,wrongInstString, newInstString));
			}
		}
	}
}

static makeRpt(base, end){
	auto addr;
	addr = base;
	while(addr < end){
		//Jump(addr);
		MakeData(addr, FF_WORD, 0x2, 0);
		if(Word(addr) > 0x8000) {
			OpOffEx(addr, -1, REF_OFF32, base + Word(addr) - 0x10000, base, 0x10000);
		}
		else{
			OpOffEx(addr, -1, REF_OFF32, -1, base, 0);
		}
		addr = addr+2;
	}
}

static makeBt(base, end){
	auto addr;
	addr = base;
	while(addr < end){
		//Jump(addr);
		MakeData(addr, FF_WORD, 0x2, 0);
		if(Word(addr) > 0x8000) {
			OpOffEx(addr, -1, REF_OFF32, base + Word(addr) - 0x10000, base, 0x10000);
		}
		else{
			OpOffEx(addr, -1, REF_OFF32, -1, base, 0);
		}
		addr = addr+2;
	}
}

static makeRjt(base, end){
	auto addr;
	addr = base;
	while(addr < end){
		//Jump(addr);
		MakeData(addr, FF_WORD, 0x2, 0);
		if(Word(addr) > 0x8000) {
			OpOffEx(addr, -1, REF_OFF32, base + Word(addr) - 0x10000, base, 0x10000);
		}
		else{
			OpOffEx(addr, -1, REF_OFF32, -1, base, 0);
		}
		addr = addr+2;
	}
}

static makeRjtWithOneWordBetweenEachEntry(base, end){
	auto addr;
	addr = base;
	while(addr < end){
		//Jump(addr);
		MakeData(addr, FF_WORD, 0x2, 0);
		addr = addr+2;
		MakeData(addr, FF_WORD, 0x2, 0);
		if(Word(addr) > 0x8000) {
			OpOffEx(addr, -1, REF_OFF32, base + Word(addr) - 0x10000, base, 0x10000);
		}
		else{
			OpOffEx(addr, -1, REF_OFF32, -1, base, 0);
		}
		addr = addr+2;
	}
}



static fixMapSetups(){

	auto ea,start;
	start = 0x4F6E2;
	ea = start;
	while(Word(ea)!=0xFFFF){
		while(Word(ea)!=0xFFFD){
			fixSingleMapSetup(Dword(ea+2));
			ea = ea + 6;
		}
		ea = ea + 2;
	}
}


static fixSingleMapSetup(ea){
	fixMapSetupSection2(Dword(ea+4));
	fixMapSetupSection3(Dword(ea+8));
	fixMapSetupSection5(Dword(ea+16));
}

static fixMapSetupSection2(ea){
	auto base;
	base = ea;
	if(Word(ea)==0x4E75){
		return;
	}
	while(Byte(ea)!=0xFD){
		makeRelativeOffset(ea+2,base);
		ea = ea + 4;
	}
	makeRelativeOffset(ea+2,base);
}

static fixMapSetupSection3(ea){
	auto base;
	base = ea;
	if(Word(ea)==0x4E75){
		return;
	}
	while(Byte(ea)!=0xFD){
		makeRelativeOffset(ea+2,base);
		ea = ea + 4;
	}
	makeRelativeOffset(ea+2,base);
}

static fixMapSetupSection5(ea){
	auto base;
	base = ea;
	if(Word(ea)==0x4E75){
		return;
	}
	while(Byte(ea)!=0xFD){
		makeRelativeOffset(ea+4,base);
		ea = ea + 6;	
	}
	makeRelativeOffset(ea+4,base);
}

static fixMapSetupsSection4(){
	fixSingleMapSetuSection4(0x4FCDE);
	fixSingleMapSetuSection4(0x54D4C);
	fixSingleMapSetuSection4(0x54D9A);
	fixSingleMapSetuSection4(0x561FC);
	fixSingleMapSetuSection4(0x5D584);
	fixSingleMapSetuSection4(0x5E736);
	fixSingleMapSetuSection4(0x5F41E);
	fixSingleMapSetuSection4(0x5FE34);
	fixSingleMapSetuSection4(0x60558);
}

static fixSingleMapSetuSection4(ea){
	auto base;
	base = ea;
	while(Byte(ea)!=0xFD){
		if(Byte(ea+3)!=0){
			makeRelativeOffset(ea+4,base);
		}		
		ea = ea + 6;	
	}
}

static makeRelativeOffset(ea,base){
		if(Word(ea) > 0x8000) {
			OpOffEx(ea, -1, REF_OFF32, base + Word(ea) - 0x10000, base, 0x10000);
		}
		else{
			OpOffEx(ea, -1, REF_OFF32, -1, base, 0);
		}
}