
/*
 *    PARSETRAP0 SCRIPT 
 *    This script will scan "TRAP 0" instructions 
 *  and parse the following word to add corresponding sound command 
 *  as a constant from an Enum, for easier code readability.
 * 
 */

#include <idc.idc>



static main(void) {

    Message("\nINITIALIZING ARRAYS...\n");
    initializeArrays();

    Message("SCANNING TRAPS...\n");
    
    parseSoundTrap();
    parseOpenTextTrap();
    parseCloseTextTrap();
    parseClearTextTrap();
    parseTextTrap();

    Message("DELETING ARRAYS...\n");
    deleteArrays();
    
    Message("END OF TRAPS SCAN.\n");
    
    // Check if script running in batch mode, and exit once done
    if (Batch(1) == 1) {
        Exit(0);                              // exit to OS, error code 0 - success		
    }
    else {
        Batch(0);
    }

}



/* INITIALIZE ARRAYS OF STRINGS TO OPTIMIZE EXTERNAL FILE ACCESS */

static initializeArrays(){
    
    loadArray("flags.txt","Flags");
    loadArray("text.txt","Text");    
    
}

static loadArray(fileName, arrayName){

    auto file, arrayId, idx, str;
    
    file = fopen(fileName,"r");
    arrayId = CreateArray(arrayName);
    idx = 0;
    while(str!=-1){
        str = readstr(file);
        if(str!=-1){
            str = form("%s",substr(str,0,strlen(str)-1));
            SetArrayString(arrayId, idx, str);
        }
        idx++;
    }
    fclose(file);
    
}

/* DELETE ARRAYS FROM IDB AFTER USAGE */

static deleteArrays(){

    DeleteArray(GetArrayId("Flags")); 
    DeleteArray(GetArrayId("Text")); 
    
}



static parseSoundTrap(void) {

    Message("SCANNING TRAP 0...\n");
    
    scanTrap0();
    Message("\nDONE.\n");
    
    Message("END OF TRAP 0 SCAN.\n");

}



/* SOUND */


static scanTrap0(){

    auto addr; // current location
    auto parameter; // parameter found after TRAP 0
    auto action; 
    auto cont; // script continuation asked to user
    auto param;
    action = 0;
    cont = 1;
    addr = 0;
    //action = AskYN(1,form("Start from current location 0x%s ?", ltoa(ScreenEA(),16)));
    if (action==-1) return;
    if (action==1){
        addr = ScreenEA();
    }
    Message(form("\nStarting from address 0x%s",ltoa(addr,16)));
    
    for(addr=FindBinary(addr+1,7,"4E 40");addr!=BADADDR;addr=FindBinary(addr+1,7,"4E 40")){

        //Jump(addr);
        if(GetFunctionAttr(addr, FUNCATTR_START)!=-1){
        
            OpEnumEx(addr,0,GetEnum("Traps"),0);
            MakeWord(addr+2);
        
            parameter = Word(addr+2);

            //Message(form("\nBinary value 0x4E40 with parameter value 0x%s at address 0x%s in code.",ltoa(parameter,16),ltoa(addr,16)));
            
            if(parameter == 0x20
                    || (parameter >= 0xF0 &&  parameter <= 0xFFFF)){
                    OpEnumEx(addr+2,0,GetEnum("SoundCommands"),0);
                    param = GetConstName(GetConstEx(GetEnum("SoundCommands"),parameter,0,0));
            }
            else if(parameter >= 0 && parameter <= 0x27){
                    OpEnumEx(addr+2,0,GetEnum("Music"),0);
                    param = GetConstName(GetConstEx(GetEnum("SoundCommands_Music"),parameter,0,0));
            }
            else if(parameter >= 0x41 && parameter <= 0x69){
                    OpEnumEx(addr+2,0,GetEnum("Sfx"),0);
                    param = GetConstName(GetConstEx(GetEnum("SoundCommands_Sfx"),parameter,0,0));
            }    
            else{
                param = form("$%s",ltoa(addr+2,16));
                Message(form("%s: could not process trap 0 value %d",ltoa(addr,16),parameter));
            }                    
            
            /* Macro formatting */
            if(addr!=GetFunctionAttr(addr,FUNCATTR_START)){
                MakeUnkn(addr,DOUNK_DELNAMES);
                MakeUnkn(addr+1,DOUNK_DELNAMES);
                MakeUnkn(addr+2,DOUNK_DELNAMES);
                MakeUnkn(addr+3,DOUNK_DELNAMES);
                MakeData(addr,FF_BYTE,4,1);
                SetManualInsn(addr, form("sndCom  %s", param));
            }else{
                SetManualInsn(addr, " ");
                SetManualInsn(addr+2, form("sndCom  %s", param));
            }
            
            //cont = AskYN(1,"Continue ?");
            //if (cont==-1 || cont==0) return;    
        }
        else{
            Message(form("\n0x%s: Binary value 0x4E40 with parameter value 0x%s not in code",ltoa(addr,16),ltoa(Word(addr+2),16)));
        }
    }
    
}




/* TEXT */

static parseOpenTextTrap(void){

    Message("SCANNING TRAP 5...\n");
    
    scanTrap5();
    Message("\nDONE.\n");
    
    Message("END OF TRAP 5 SCAN.\n");

}


static parseCloseTextTrap(void){

    Message("SCANNING TRAP 6...\n");
    
    scanTrap6();
    Message("\nDONE.\n");
    
    Message("END OF TRAP 6 SCAN.\n");

}


static parseClearTextTrap(void){

    Message("SCANNING TRAP 7...\n");
    
    scanTrap7();
    Message("\nDONE.\n");
    
    Message("END OF TRAP 7 SCAN.\n");

}


static parseTextTrap(void) {

    Message("SCANNING TRAP 8...\n");
    
    scanTrap8();
    Message("\nDONE.\n");
    
    Message("END OF TRAP 8 SCAN.\n");

}



static scanTrap5(){
    
    auto addr; // current location
    auto parameter; // parameter found after TRAP 8
    auto action; // comment update confirmation asked to user
    auto cont; // script continuation asked to user
    auto newComment; // comment to add
    auto textbanksFile, currentLine, lineNumber; 
    action = 1;
    cont = 1;
    addr = 0;
    lineNumber = 0;
    //action = AskYN(1,form("Start from current location 0x%s ?", ltoa(ScreenEA(),16)));
    //if (action==-1) return;
    //if (action==1){
    //    addr = ScreenEA();
    //}
    Message(form("\nStarting from address 0x%s",ltoa(addr,16)));
    
    for(addr=FindBinary(addr+1,7,"4E 45");addr!=BADADDR;addr=FindBinary(addr+1,7,"4E 45")){
        
        if(GetFunctionAttr(addr, FUNCATTR_START)!=-1){
        
            OpEnumEx(addr,0,GetEnum("Traps"),0);   
            MakeUnkn(addr,DOUNK_DELNAMES);
            MakeUnkn(addr+1,DOUNK_DELNAMES);
            MakeData(addr,FF_BYTE,2,1);
            SetManualInsn(addr, form("openTxt"));
            
        }else{
            
            Message(form("\n0x%s: Binary value 0x4E45 not in code",ltoa(addr,16),ltoa(Word(addr-2),16)));
        }
    }
}


static scanTrap6(){
    
    auto addr; // current location
    auto parameter; // parameter found after TRAP 8
    auto action; // comment update confirmation asked to user
    auto cont; // script continuation asked to user
    auto newComment; // comment to add
    auto textbanksFile, currentLine, lineNumber; 
    action = 1;
    cont = 1;
    addr = 0;
    lineNumber = 0;
    //action = AskYN(1,form("Start from current location 0x%s ?", ltoa(ScreenEA(),16)));
    //if (action==-1) return;
    //if (action==1){
    //    addr = ScreenEA();
    //}
    Message(form("\nStarting from address 0x%s",ltoa(addr,16)));
    
    for(addr=FindBinary(addr+1,7,"4E 46");addr!=BADADDR;addr=FindBinary(addr+1,7,"4E 46")){
        
        if(GetFunctionAttr(addr, FUNCATTR_START)!=-1){
        
            OpEnumEx(addr,0,GetEnum("Traps"),0);   
            MakeUnkn(addr,DOUNK_DELNAMES);
            MakeUnkn(addr+1,DOUNK_DELNAMES);
            MakeData(addr,FF_BYTE,2,1);
            SetManualInsn(addr, form("closeTxt"));
            
        }else{
            
            Message(form("\n0x%s: Binary value 0x4E46 not in code",ltoa(addr,16),ltoa(Word(addr-2),16)));
        }
    }
}


static scanTrap7(){
    
    auto addr; // current location
    auto parameter; // parameter found after TRAP 8
    auto action; // comment update confirmation asked to user
    auto cont; // script continuation asked to user
    auto newComment; // comment to add
    auto textbanksFile, currentLine, lineNumber; 
    action = 1;
    cont = 1;
    addr = 0;
    lineNumber = 0;
    //action = AskYN(1,form("Start from current location 0x%s ?", ltoa(ScreenEA(),16)));
    //if (action==-1) return;
    //if (action==1){
    //    addr = ScreenEA();
    //}
    Message(form("\nStarting from address 0x%s",ltoa(addr,16)));
    
    for(addr=FindBinary(addr+1,7,"4E 47");addr!=BADADDR;addr=FindBinary(addr+1,7,"4E 47")){
        
        if(GetFunctionAttr(addr, FUNCATTR_START)!=-1){
        
            OpEnumEx(addr,0,GetEnum("Traps"),0);   
            MakeUnkn(addr,DOUNK_DELNAMES);
            MakeUnkn(addr+1,DOUNK_DELNAMES);
            MakeData(addr,FF_BYTE,2,1);
            SetManualInsn(addr, form("clearTxt"));
            
        }else{
            
            Message(form("\n0x%s: Binary value 0x4E47 not in code",ltoa(addr,16),ltoa(Word(addr-2),16)));
        }
    }
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
    addr = 0;
    lineNumber = 0;
    //action = AskYN(1,form("Start from current location 0x%s ?", ltoa(ScreenEA(),16)));
    //if (action==-1) return;
    //if (action==1){
    //    addr = ScreenEA();
    //}
    Message(form("\nStarting from address 0x%s",ltoa(addr,16)));
    
    for(addr=FindBinary(addr+1,7,"4E 48");addr!=BADADDR;addr=FindBinary(addr+1,7,"4E 48")){
        
        dialogLine = "";
        if(GetFunctionAttr(addr, FUNCATTR_START)!=-1){
        
            OpEnumEx(addr,0,GetEnum("Traps"),0);
            if(Word(addr-4)==0x303C){       
            
                dialogLine = GetArrayElement(AR_STR, GetArrayId("Text"), Word(addr-2));
                if(dialogLine==-1){
                    dialogLine="";
                }else{
                    dialogLine = form("\"%s\"",dialogLine);
                }
                
                if(addr!=GetFunctionAttr(addr,FUNCATTR_START)){
                    MakeUnkn(addr-4,DOUNK_DELNAMES);
                    MakeUnkn(addr-3,DOUNK_DELNAMES);
                    MakeUnkn(addr-2,DOUNK_DELNAMES);
                    MakeUnkn(addr-1,DOUNK_DELNAMES);
                    MakeUnkn(addr,DOUNK_DELNAMES);
                    MakeUnkn(addr+1,DOUNK_DELNAMES);
                    MakeData(addr-4,FF_BYTE,6,1);
                    SetManualInsn(addr-4, form("txt     %s", ltoa(Word(addr-2),10)));
                    MakeRptCmt(addr-4,dialogLine);
                }else{
                    SetManualInsn(addr-4, " ");
                    SetManualInsn(addr, form("txt     %s", ltoa(Word(addr-2),10)));
                    MakeRptCmt(addr-4,"");
                    MakeRptCmt(addr,dialogLine);
                }        
                
            }else{
                
                if(Word(addr-3)!=0x4E40){
                    if (addr!=0xBC1EB){
                        MakeUnkn(addr,DOUNK_DELNAMES);
                        MakeUnkn(addr+1,DOUNK_DELNAMES);
                        MakeData(addr,FF_BYTE,2,1);
                        SetManualInsn(addr, form("txtD0"));
                    }
                }
            }
            
        }else{
            
            Message(form("\n0x%s: Binary value 0x4E48 with parameter 0x%s not in code",ltoa(addr,16),ltoa(Word(addr-2),16)));
        }
    }
}
