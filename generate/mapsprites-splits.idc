
    splitPT(0x39928, 0x39BA8, 0x57DF4, 0x57DF4, "pt_MapSprites1", "MapSprite1", "data/graphics/mapsprites/", "mapsprite1", 3, 0, file);
    splitPT(0x39BA8, 0x39E28, 0x57EAA, 0x57EAA, "pt_MapSprites2", "MapSprite2", "data/graphics/mapsprites/", "mapsprite2", 3, 0, file);
    splitPT(0x39E28, 0x3A0A8, 0x57F5F, 0x57F5F, "pt_MapSprites3", "MapSprite3", "data/graphics/mapsprites/", "mapsprite3", 3, 0, file);

    
static splitMapSprites(file) {
    
    auto i;
    auto start,end,addr,addr2,addr3,lastEntryDataEnd,chunkEnd,action,dref,dref2,dref3;
    
    i = 0;
    start = 0x39928;
    end = 0x39BA8;
    
    addr = start;
    addr2 = 0x39BA8;
    addr3 = 0x39E28;
    
    //end2 = 0x39E28;
    //end3 = 0x3A0A8;
    
    lastEntryDataEnd = 0x;
    chunkEnd = 0x57F5F;
    action=1;
    
    //Message("Cleaning from %a to %a ...\n",start,chunkEnd);        
    for(j=start;j<chunkEnd;j++){undefineByte(j);}
    MakeNameEx(addr,"pt_MapSprites_FacingDown",0);
    MakeNameEx(addr2,"pt_MapSprites_FacingLeft",0);
    MakeNameEx(addr3,"pt_MapSprites_FacingUp",0);
    
    while(addr<end&&action==1){
        
        MakeDword(addr);
        MakeDword(addr2);
        MakeDword(addr3);
        
        dref = Dword(addr);
        dref2 = Dword(addr2);
        dref3 = Dword(addr3);
        
        add_dref(addr,dref,dr_O);
        add_dref(addr2,dref2,dr_O);
        add_dref(addr3,dref3,dr_O);
        
        dref = Dfirst(addr);
        dref2 = Dfirst(addr2);
        dref3 = Dfirst(addr3);
        
        //Jump(dref);
        index = ltoa(i,10);
        if(strlen(index)==1)index=form("0%s",index);
        if((dref>=end)&&(strstr(GetTrueName(dref),"MapTileset")==-1)){        
            MakeNameEx(dref,form("MapTileset%s",index),0);
        }
        addr=addr+4;
        i++;
    }
    
}