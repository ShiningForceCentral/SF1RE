
static parseBattleEndScript(start,end){
    auto nodeLength;
    ea = start;
    
    if(Word(ea)==0x343C&&Byte(ea+4)==0x61&&Byte(ea+8)==0x66){
        nodeLength = 12;
        MakeUnknown(ea,nodeLength,DOUNK_SIMPLE);
        MakeCode(ea);
        SetManualInsn(ea,form("braIfEntityAlive %d, %s",Word(ea+2),GetOpnd(Word(ea+6),0)));
    }else if(Byte(ea)==0x70&&Word(ea+2)==0x4EB9&&Dword(ea+4)==0x802C){
        nodeLength = 8;
        MakeUnknown(ea,nodeLength,DOUNK_SIMPLE);
        MakeCode(ea);
        SetManualInsn(ea,form("displayPortrait %d",Byte(ea+1)));
    }else if(Byte(ea)==0x72&&Word(ea+2)==0x6100){
        nodeLength = 6;
        MakeUnknown(ea,nodeLength,DOUNK_SIMPLE);
        MakeCode(ea);
        SetManualInsn(ea,form("setSpeechSfx %d",Byte(ea+1)));
    }else if(Word(ea)==0x4E45){
        nodeLength = 2;
        MakeUnknown(ea,nodeLength,DOUNK_SIMPLE);
        MakeCode(ea);
        SetManualInsn(ea,form("openMessageWindow"));
    }else if(Word(ea)==0x303C&&Word(ea+4)==0x4E48){
        nodeLength = 8;
        MakeUnknown(ea,nodeLength,DOUNK_SIMPLE);
        MakeCode(ea);
        SetManualInsn(ea,form("displayMessage %d",Word(ea+6)));
    }else if(Word(ea)==0x4EB9&&Dword(ea+2)==0x334){
        nodeLength = 18;
        MakeUnknown(ea,nodeLength,DOUNK_SIMPLE);
        MakeCode(ea);
        SetManualInsn(ea,form("yesNoPrompt %s",GetOpnd(ea+12,0)));
    }else if(Word(ea)==0x4E46){
        nodeLength = 2;
        MakeUnknown(ea,nodeLength,DOUNK_SIMPLE);
        MakeCode(ea);
        SetManualInsn(ea,form("closeMessageWindow"));
    }else if(Word(ea)==0x4EB9&&Dword(ea+2)==0x8030){
        nodeLength = 6;
        MakeUnknown(ea,nodeLength,DOUNK_SIMPLE);
        MakeCode(ea);
        SetManualInsn(ea,form("clearPortrait"));
    }else if(Byte(ea)==0x70&&Word(ea+2)==0x4EB9&&Dword(ea+4)==0x244){
        nodeLength = 8;
        MakeUnknown(ea,nodeLength,DOUNK_SIMPLE);
        MakeCode(ea);
        SetManualInsn(ea,form("sleep %d",Byte(ea+1)));
    }
    
}