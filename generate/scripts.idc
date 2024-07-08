static parseDialogueScript(start,end){
    auto nodeLength;
    ea = start;
    Message(form("\nDialogue script starting from 0x%s ...",ltoa(ea,16)));
    
    if(Word(ea)==0x3C3C){
        // Set message bank
        nodeLength = 4;
        MakeUnknown(ea,nodeLength,DOUNK_SIMPLE);
        MakeCode(ea);
        SetManualInsn(ea,form("setMessageBank %s",ltoa(Word(ea+2),10)));
    }else if(Word(ea)==0x3F06){
        // Backup message bank
        nodeLength = 2;
        MakeUnknown(ea,nodeLength,DOUNK_SIMPLE);
        MakeCode(ea);
        SetManualInsn(ea,form("backupMessageBank"));
    }else if(Word(ea)==0x3C1F){
        // Restore message bank
        nodeLength = 2;
        MakeUnknown(ea,nodeLength,DOUNK_SIMPLE);
        MakeCode(ea);
        SetManualInsn(ea,form("restoreMessageBank"));
    }else if(Word(ea+2)==0x4E94){
        // Set portrait
        nodeLength = 4;
        MakeUnknown(ea,nodeLength,DOUNK_SIMPLE);
        MakeCode(ea);
        MakeCode(ea+2);
        SetManualInsn(ea,form("setPortrait %s",ltoa(Byte(ea+1),10)));
    }else if(){
        // Set text sound
        nodeLength = 12;
        MakeUnknown(ea,nodeLength,DOUNK_SIMPLE);
        MakeCode(ea);
        MakeCode(ea+2);
        MakeCode(ea+6);
        MakeCode(ea+10);
        SetManualInsn(ea,form("setTextSound %s",ltoa(Byte(ea+5),10)));
    }else if(){
        // Set sprite direction
        nodeLength = 14;
        MakeUnknown(ea,nodeLength,DOUNK_SIMPLE);
        MakeCode(ea);
        MakeCode(ea+2);
        MakeCode(ea+4);
        SetManualInsn(ea,form("setSpriteDirection %s, %s",ltoa(Byte(ea+1),10),ltoa(Byte(ea+3),10)));
    }else if(Word(ea+2)==0x4E95){
        // Display message
        nodeLength = 4;
        MakeUnknown(ea,nodeLength,DOUNK_SIMPLE);
        MakeCode(ea);
        MakeCode(ea+2);
        SetManualInsn(ea,form("displayMessage %s",ltoa(Byte(ea+1),10)));
    }else if(){
        // Display yes/no prompt
        nodeLength = 8;
        MakeUnknown(ea,nodeLength,DOUNK_SIMPLE);
        
        SetManualInsn(ea,form("displayYesNo %s, %s",ltoa(Word(ea+3)&0xFF00/256,10),ltoa(Word(ea+3)&0xFF,10)));
    }else if (){
        // Execute church menu
        nodeLength = 30;
        MakeUnknown(ea,nodeLength,DOUNK_SIMPLE);
        
        SetManualInsn(ea,form("executeChurchMenu"));
    }else if(){
        // Execute shop menu
        nodeLength = 32;
        MakeUnknown(ea,nodeLength,DOUNK_SIMPLE);
        
        SetManualInsn(ea,form("executeShopMenu %s",ltoa(Byte(ea+1),10)));
    }else if(Dword(ea+4)==0x6100FA92){
        // Set event
        nodeLength = 8;
        MakeUnknown(ea,nodeLength,DOUNK_SIMPLE);
        
        SetManualInsn(ea,form("setEvent %s",ltoa(Word(ea+3),10)));
    }else if(){
        // Branch on 'No'
        nodeLength = 6;
        MakeUnknown(ea,nodeLength,DOUNK_SIMPLE);
        
        SetManualInsn(ea,form("branchOnNo %s",GetOpnd(ea+4,0)));
    }else if(Word(ea)==0x4E75){
        // End
        nodeLength = 2;
        MakeUnknown(ea,nodeLength,DOUNK_SIMPLE);
        MakeCode(ea);
        SetManualInsn(ea,form("end"));
    }else if(Word(ea)==0x0C01&&Word(ea+4)==0x6700){
        // Check dialogue number
        nodeLength = 8;
        MakeUnknown(ea,nodeLength,DOUNK_SIMPLE);
        MakeCode(ea);
        MakeCode(ea+4);
        SetManualInsn(ea,form("checkDialogueNumber"));
    }else if(Word(ea)==0x0C42){
        // Check dialogue group
        nodeLength = 8;
        MakeUnknown(ea,nodeLength,DOUNK_SIMPLE);
        MakeCode(ea);
        MakeCode(ea+4);
        SetManualInsn(ea,form("checkDialogueGroup"));
    }
    
    
    
    
    
    
}