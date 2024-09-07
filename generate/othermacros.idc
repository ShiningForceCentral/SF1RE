


#include <idc.idc>


static main(void){

    Message("\nINITIALIZING ARRAYS...\n");
    initializeArrays();
    
    Message("PARSING DATA STRUCTURES INTO MACROS ...\n");
    
    parseVdpSprite_1C0E();
    parseShiningForceLogoLayout();
    parseChapterScreenLayouts();
    parseDebugWindowLayouts();
    parseGoldWindowLayout();
    parseVdpSprite_73EE();
    parseEquipMenuWindowLayouts();
    parseBattlefieldWindowLayouts();
    parseVdpSprites_8854();
    parseStatusScreenLayouts();
    parseVdpSprites_C792();
    parseLayouts_C900();
    parseWindowLayout_D230();
    parseMiscMessageWindowLayouts();
    parseBattleEquipWindowLayouts();
    parseLandEffectWindowLayout();
    parsePortraitLayouts();
    parseShopScreenWindowLayouts();
    parseVdpSprite_1E67A();
    parseLayout_1E712();
    parseLayout_BDC38();
    parseTextInputWindowLayout();
    parseSoundTestWindowLayout();
    parseTitleScreenLayout();
    parseVdpSprites_1254A4();
    parsePressStartButtonLayout();
    parseWindowLayouts_164990();

    Message("DELETING ARRAYS...\n");
    deleteArrays();
      
    Message("END OF PARSING.\n");  

    // Check if script running in batch mode, and exit once done
    if (Batch(1) == 1) {
        Exit(0);                              // exit to OS, error code 0 - success		
    }
    else {
        Batch(0);
    }

}



static parseVdpSprite_1C0E(){
    parseVdpSprite(0x1C0E,0x1CC6);
}


static parseShiningForceLogoLayout(){
    parseLayout(0x39CC,0x3A44);
}


static parseChapterScreenLayouts(){
    parseLayout(0x49EE,0x4BEE);
    parseLayout(0x4BEE,0x4C0E);
}


static parseDebugWindowLayouts(){
    parseWindowLayout(0x530E,0x53B8);
    parseWindowLayout(0x53B8,0x5462);
    parseWindowLayout(0x5462,0x550C);
}


static parseGoldWindowLayout(){
    parseWindowLayout(0x55CC,0x560C);
}


static parseVdpSprite_73EE(){
    parseVdpSprite(0x73EE,0x740E);
}


static parseEquipMenuWindowLayouts(){
    parseWindowLayout(0x75A0,0x75E8);
    parseWindowLayout(0x75E8,0x76C0);
    parseWindowLayout(0x76C0,0x772C);
    parseWindowLayout(0x772C,0x77A4);
}


static parseBattlefieldWindowLayouts(){
    parseWindowLayout(0x7B58,0x7C46);
    parseWindowLayout(0x7C46,0x7D34);
    parseWindowLayout(0x7D34,0x7E22);
}


static parseVdpSprites_8854(){
    parseVdpSprite(0x8854,0x8914);
    parseVdpSprite(0x8914,0x891C);
}


static parseStatusScreenLayouts(){
    parseWindowLayout(0xB982,0xBDFA);
    parseWindowLayout(0xBDFA,0xBE3A);
}


static parseVdpSprites_C792(){
    parseVdpSprite(0xC792,0xC7B2);
    parseVdpSprite(0xC7B2,0xC7C2);
}


static parseLayouts_C900(){
    parseWindowLayout(0xC900,0xCC90);
    parseLayout(0xCC90,0xCCD8);
}


static parseWindowLayout_D230(){
    parseWindowLayout(0xD230,0xD24E);
    parseWindowLayout(0xD24E,0xD258);
    parseWindowLayout(0xD258,0xD28A);
    parseWindowLayout(0xD28A,0xD32C);
}


static parseMiscMessageWindowLayouts(){
    parseWindowLayout(0xD3C0,0xD408);
    parseWindowLayout(0xD40A,0xD44C);
    parseWindowLayout(0xD44E,0xD48A);
    parseWindowLayout(0xD48C,0xD4EC);
    parseWindowLayout(0xD4EE,0xD56C);
    parseWindowLayout(0xD56E,0xD5EC);
    parseWindowLayout(0xD5EE,0xD66C);
    parseWindowLayout(0xD66E,0xD6E6);
    parseWindowLayout(0xD6E8,0xD75A);
}


static parseBattleEquipWindowLayouts(){
    parseWindowLayout(0xDD1C,0xDDF4);
    parseWindowLayout(0xDDF4,0xDEC0);
}


static parseLandEffectWindowLayout(){
    parseWindowLayout(0xDF8C,0xDFEC);
}


static parsePortraitLayouts(){
    parseLayout(0xE322,0xE3C2);
    parseLayout(0xE3C2,0xE462);
    parseLayout(0xE462,0xE49E);
}


static parseShopScreenWindowLayouts(){
    parseWindowLayout(0xF1CA,0xF2D8);
    parseWindowLayout(0xF2D8,0xF30E);
    parseWindowLayout(0xF30E,0xF344);
    
    parseWindowLayout(0xF364,0xF3C8);
    parseWindowLayout(0xF3C8,0xF410);
    parseWindowLayout(0xF410,0xF43A);
    parseWindowLayout(0xF43A,0xF464);
    parseWindowLayout(0xF464,0xF48E);
    parseWindowLayout(0xF48E,0xF4DE);
}


static parseVdpSprite_1E67A(){
    parseVdpSprite(0x1E67A,0x1E712);
}


static parseLayout_1E712(){
    parseLayout(0x1E712,0x1E892);
}


static parseLayout_BDC38(){
    parseLayout(0xBDC38,0xBE338);
}


static parseSoundTestWindowLayout(){
    parseWindowLayout(0xBE470,0xBE510);
}


static parseTitleScreenLayout(){
    parseLayout(0xC6984,0xC7084);
}


static parseTextInputWindowLayout(){
    parseWindowLayout(0xD301A,0xD32DA);
}


static parseVdpSprites_1254A4(){
    parseVdpSprite(0x1254A4,0x125534);
    parseVdpSprite(0x125534,0x1255B4);
    parseVdpSprite(0x1255B4,0x1255CC);
}


static parsePressStartButtonLayout(){
    parseLayout(0x130464,0x130488);
}


static parseWindowLayouts_164990(){
    parseWindowLayout(0x164990,0x1649CC);
    parseWindowLayout(0x164A58,0x164AD4);
    parseWindowLayout(0x164AD4,0x164C74);
}



static parseLayout(start,end){
    auto addr, j, vdpTile;
    addr = start;
    while(addr<end){
        for(j=addr;j<addr+2;j++){undefineByte(j);}
        MakeWord(addr);
        vdpTile = getVdpTileShorthand(Word(addr));
        SetManualInsn(addr, form("vdpTile %s", vdpTile));
        addr = addr+2;
    }
}


static parseWindowLayout(start,end){
    auto addr, j, vdpTile;
    addr = start;
    while(addr<end){
        for(j=addr;j<addr+2;j++){undefineByte(j);}
        MakeWord(addr);
        vdpTile = getVdpTileShorthand(Word(addr)&0x1FFF);
        SetManualInsn(addr, form("vdpBaseTile %s", vdpTile));
        addr = addr+2;
    }
}


static parseVdpSprite(start,end){
    auto addr, i, j, ypos, size, sizeAndLink, vdpTile, xpos;
    addr = start;
    while(addr<end){
        for(j=addr;j<addr+8;j++){undefineByte(j);}
        MakeData(addr,FF_BYTE,8,1);
        ypos = ltoa(Word(addr),10);
        size = getVdpSpriteSizeShorthand(Word(addr+2)&0xFF00);
        sizeAndLink = form("%s|%s", size, ltoa(Word(addr+2)&0xFF,10));
        vdpTile = form("%s|%s", ltoa(Word(addr+4)&0x7FF,10), getVdpTileShorthand(Word(addr+4)&0xF800));
        xpos = ltoa(Word(addr+6),10);
        SetManualInsn(addr, form("vdpSprite %s, %s, %s, %s", ypos, sizeAndLink, vdpTile, xpos));
        addr = addr+8;
    }
}



static getVdpSpriteSizeShorthand(cmd){
    return getBitfieldShorthands(cmd,"VdpSpriteSize","VDPSPRITESIZE_");
}

static getVdpTileShorthand(cmd){
    return getBitfieldShorthands(cmd,"VdpTiles","VDPTILE_");
}



static getBitfieldShorthands(cmd,enumName,prefix){
    auto id, bitmask, output, value, next;
    id = GetEnum(enumName);
    bitmask = GetFirstBmask(id);
    output = "";
    while(bitmask!=-1){
        value = cmd & bitmask;
        next = getShorthandEx(value,enumName,prefix,bitmask);
        if(next!=""&&next!="0"){
            if(output==""){
                output = next;
            }else{
                output = form("%s|%s",output,next);
            }
        }
        bitmask = GetNextBmask(id,bitmask);
    }
    return output;
}

static getShorthand(cmd,enumName,prefix){
    return getShorthandEx(cmd,enumName,prefix,-1);
}

static getShorthandEx(cmd,enumName,prefix,bitmask){
    auto id, constant, j, constId;
    id = GetEnum(enumName);
    constant = GetFirstConst(id,bitmask);
    while(constant!=-1){
        j=0;
        constId = GetConstEx(id,constant,j,bitmask);
        while(constId!=-1){
            if(constant==cmd){
                return substr(GetConstName(constId),strlen(prefix),-1);
            }
            j++;
            constId = GetConstEx(id,constant,j,bitmask);
        }
        constant = GetNextConst(id,constant,bitmask);
    }
    return form("%d",cmd);
}

/* 
 *  Makes sure byte at addr is
 *  clean for new formatting
 */
static undefineByte(addr){
        auto from;
        from = DfirstB(addr);
        /*
        while(from!=BADADDR){
            //Message(form("Removed DATA XRef at addr %a, from %a\n",addr, from));
            del_dref(from,addr);
            from=DnextB(addr,from);
        }        
        from = RfirstB(addr);
        while(from!=BADADDR){
            //Message(form("Removed Code XRrf at addr %a, from %a\n",addr, from));
            DelCodeXref(from,addr,1);
            from=RnextB(addr,from);      
        }    
        */            
        MakeUnkn(addr,DOUNK_DELNAMES);
        //MakeNameEx(addr,"",0);
        SetManualInsn(addr,"");
}



/* INITIALIZE ARRAYS OF STRINGS TO OPTIMIZE EXTERNAL FILE ACCESS */

static initializeArrays(){
    
    //loadArray("flags.txt","Flags");
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

    //DeleteArray(GetArrayId("Flags")); 
    DeleteArray(GetArrayId("Text")); 
    
}
