
/*
 *    Attempt at producing ASM file from IDC script 
 *    instead of IDA's function, for more flexibility.
 */

#include <idc.idc>

static main(void) {

    Message("PRODUCING ASM...\n");

    //produceMacros();
    produceEnums();
    produceConst();
    produceMain();
    
    Message("\nEND OF ASM PRODUCTION.\n");

}

static produceMacros(){
    auto file;
    Message("\nWriting Macros to sf1macros.asm ...");    
    file = fopen("disasm\\sf1macros.asm","w");
    writestr(file,"; ---------------------------------------------------------------------------\n");
    writestr(file,"; Align and pad\n");
    writestr(file,"; input: length to align to, value to use as padding (default is $FF)\n");
    writestr(file,"; ---------------------------------------------------------------------------\n");
    writestr(file,"\n");
    writestr(file,"align:    macro\n");
    writestr(file,"    if (narg=1)\n");
    writestr(file,"    dcb.b \\1-(*%\\1),$FF\n");
    writestr(file,"    else\n");
    writestr(file,"    dcb.b \\1-(*%\\1),\\2\n");
    writestr(file,"    endc\n");
    writestr(file,"    endm\n");
    writestr(file,"\n");
    fclose(file);    
    Message("DONE.");    
}

static produceEnums(){
    auto i,j,enumQty,id,enumName,bmask,enumCount,constant,constId,constCmt,output,file;
    file = fopen("disasm\\sf1enums.asm","w");
    Message("\nWriting Enums to sf1enums.asm ...");
    enumQty = GetEnumQty();
    for(i=0;i<enumQty;i++){
        id = GetnEnum(i);
        enumName = GetEnumName(id);
        writestr(file,"\n\n; ---------------------------------------------------------------------------\n");
        bmask = GetFirstBmask(id);
        if(bmask==-1){writestr(file,form("\n; enum %s",enumName));}
        else{writestr(file,form("\n; enum %s (bitfield)",enumName));}
        
        /* Iterate bitmasks */
        while(bmask!=0){
            enumCount = GetEnumSize(id);
            constant = GetFirstConst(id,bmask);
            
            /* Iterate constants */
            while(enumCount>0){
                j=0;
                constId = GetConstEx(id,constant,j,bmask);
                while(constId != -1){
                    output = conditionalEnumOutput(id,enumName,enumCount,constant,constId);
                    writestr(file,form("\n%s", output));
                    j++;
                    constId = GetConstEx(id,constant,j,bmask);
                }
                constant = GetNextConst(id,constant,bmask);
                enumCount--;
            }
            
            /* Break out of loop after iterating last bitmask */
            if(bmask==-1){break;}
            bmask = GetNextBmask(id,bmask);
        }
    }
    fclose(file);
    Message("DONE.");
}

static conditionalEnumOutput(id,enumName,enumCount,constant,constId){
    auto i,j,constName,constCmt,enumMember,enumFlags,output;
    constName = GetConstName(constId);
    
    /* Format comment string */
    constCmt = GetConstCmt(constId,0);
    if(constCmt==""){
        constCmt = GetConstCmt(constId,1);
        if(constCmt!=""){
            constCmt = formatRptCmt(constCmt);
        }
    }
    if(constCmt!="" && constCmt!=" "){
        constCmt = form(" ; %s",constCmt);
    }
    //Message(form("constId(%d): \"%s\"\n", constId, constCmt));
    
    /* Format enum member string using the proper numerical representation */
    enumFlags = GetEnumFlag(id);
    if(constant>=0 && constant<10 || (enumFlags&FF_1NUMD)!=0){
        output = form("%s", formEnumMember(constName,constant,constCmt));
    }
    else if((enumFlags&FF_1NUMH)!=0){
        output = form("%s", formEnumMemberWithHex(constName,constant,constCmt));
    }
    else{
        output = form("%s", formEnumMemberWithBin(constName,constant,constCmt));
    }
    //Message(form("output: \"%s\"\n", output));
    
    return output;
    
}

static formEnumMember(constName,constant,constCmt) {
    auto enumMember;
    enumMember = formEnumMemberEx(constName,constant,constCmt,0);
    return enumMember;
}

static formEnumMemberWithHex(constName,constant,constCmt) {
    auto enumMember;
    enumMember = formEnumMemberEx(constName,constant,constCmt,1);
    return enumMember;
}

static formEnumMemberWithBin(constName,constant,constCmt) {
    auto enumMember;
    enumMember = formEnumMemberEx(constName,constant,constCmt,-1);
    return enumMember;
}

static formEnumMemberEx(constName,constant,constCmt,rep) {
    auto operand,constStr,enumMember;
    if(rep==0){
        operand = "";
        constStr = ltoa(constant,10);
    }
    else if(rep==1){
        operand = "$";
        constStr = ltoa(constant,16);
    }
    else{
        operand = "%";
        constStr = ltoa(constant,2);
    }
    enumMember = form("%s: equ %s%s%s", constName, operand, constStr, constCmt);
    //Message(form("enumMember: \"%s\"\n", enumMember));
    
    return enumMember;
}


static produceConst(void) {
    auto seg,end,ea,segName,name,comment,commentEx,file;
    Message("\nWriting offset constants to sf1const.asm ...");
    file = fopen("disasm\\sf1const.asm","w");
    writestr(file,"; SF1CONST.ASM INCLUDED AT START OF SF1.ASM\n\n");
    seg = FirstSeg();
    seg = NextSeg(seg);
    while(seg != BADADDR){
        end = SegEnd(seg);
        segName = SegName(seg);
        writestr(file,form("; START OF SEGMENT %s OFFSETS FROM %a TO %a\n",segName, seg, end));
        ea = seg;
        while(ea<end){
            name = GetTrueNameEx(ea,ea);
            if(name==""){
                name = Name(ea);
            }
            comment = CommentEx(ea,0);
            if(comment==""){
                comment = CommentEx(ea,1);
                if(comment!=""){
                    comment = formatRptCmt(comment);
                }
            }
            if(comment!="" && comment!=" "){
                comment = form(" ; %s",comment);
            }
            if(name!=""){
                writestr(file,form("%s: equ $%s%s\n",name,ltoa(ea,16),comment));
            }
            ea = ea + ItemSize(ea);
        }
        writestr(file,form("; END OF SEGMENT %s OFFSETS FROM %a TO %a\n\n",segName, seg, end));
        seg = NextSeg(seg);
    }
    fclose(file);
    Message("DONE.\n");
}


static produceMain(){

    auto seg,end,ea,itemSize,action,currentLine,previousLine,file;
    auto output, name, indent, comment, commentEx, commentIndent;
    Message("Writing main assembly file to sf1.asm ...");    
    action = 1;
    file = fopen("disasm\\sf1.asm","w");
    writeHeader(file);
    
    /*
    produceSection(file,"01",   0x0,        0x8000,     0x8000-0x7E22,      "Technical layer, low level game engine, menu engine, ...");
    produceSection(file,"02",   0x8000,     0x10000,    0x10000-0xFD58,     "");
    produceSection(file,"03",   0x10000,    0x20000,    0x20000-0x1F068,    "Exploration engine, ...");
    produceSection(file,"04",   0x20000,    0x2C000,    0x2C000-0x2BF85,    "Stats engine, ...");
    produceSection(file,"05",   0x2C000,    0x38000,    0x38000-0x37B38,    "Region check, variable width font, portraits");
    produceSection(file,"06",   0x38000,    0x58000,    0x58000-0x57F5F,    "Map sprites, misc. uncompressed graphics");
    produceSection(file,"07",   0x58000,    0x80000,    0x80000-0x7F6FF,    "Map tilesets");
    produceSection(file,"08",   0x80000,    0xBC000,    0xBC000-0xBA3ED,    "Sprite sets, map sprite scripts, map data, tile animation data");
    produceSection(file,"09",   0xBC000,    0xC0000,    0xC0000-0xBEDAC,    "Sound test");
    produceSection(file,"10",   0xC0000,    0xCC000,    0xCC000-0xCB8C5,    "Ending, intro, title and chapter screens graphics and palettes");
    produceSection(file,"11",   0xCC000,    0x100000,   0x100000-0xFFD3D,   "Base tiles loading and ending credits functions, battle backgrounds");
    produceSection(file,"12",   0x100000,   0x124000,   0x124000-0x122758,  "Enemy battlesprites and animations");
    produceSection(file,"13",   0x124000,   0x130000,   0x130000-0x12FE14,  "Spell graphics and animations");
    produceSection(file,"14",   0x130000,   0x144000,   0x144000-0x13E92C,  "Game intro, title screen, text banks");
    produceSection(file,"15",   0x144000,   0x164000,   0x164000-0x163FFA,  "Ally battlesprites and animations, weapon sprites and palettes, battle platforms");
    produceSection(file,"16",   0x164000,   0x168000,   0x168000-0x167FEA,  "");
    produceSection(file,"17",   0x168000,   0x180000,   0,                  "PCM banks, Music banks, Sound driver, YM instruments");
    */
    
    produceLayoutFile();
    
    fclose(file);
    Message("\nDONE.");    
}

static produceLayoutFile(){

    auto file;
    file = fopen("disasm\\layout\\sf1-00-romlayout.asm","w");
    
    writestr(file,"\n; ROM LAYOUT FILE\n;\n");

    produceSpecificSectionOne(file,         "01",   0x0,        0x8000,     478,    "0x000000..0x008000 : Technical layer, low level game engine, menu engine, ...");
    produceSpecificSectionTwo(file,         "02",   0x8000,     0x10000,    680,    "0x008000..0x010000 : ");
    produceSpecificSectionThree(file,       "03",   0x10000,    0x20000,    3992,   "0x010000..0x020000 : Exploration engine, ...");
    produceSpecificSectionFour(file,        "04",   0x20000,    0x2C000,    123,    "0x020000..0x02C000 : Stats engine, ...");
    produceSpecificSectionFive(file,        "05",   0x2C000,    0x38000,    1224,   "0x02C000..0x038000 : Region check, variable width font, portraits");
    produceSpecificSectionSix(file,         "06",   0x38000,    0x58000,    161,    "0x038000..0x058000 : Map sprites, misc. uncompressed graphics");
    produceSpecificSectionSeven(file,       "07",   0x58000,    0x80000,    2305,   "0x058000..0x080000 : Map tilesets");
    produceSpecificSectionEight(file,       "08",   0x80000,    0xBC000,    7187,   "0x080000..0x0BC000 : Sprite sets, map sprite scripts, map data, tile animation data");
    produceSpecificSectionNine(file,        "09",   0xBC000,    0xC0000,    1254,   "0x0BC000..0x0C0000 : Sound test");
    produceLayoutSection(file,              "10",   0xC0000,    0xCC000,    1851,   "0x0C0000..0x0CC000 : Ending, intro, title and chapter screens graphics and palettes");
    produceSpecificSectionEleven(file,      "11",   0xCC000,    0x100000,   707,    "0x0CC000..0x100000 : Base tiles loading and ending credits functions, battle backgrounds");
    produceSpecificSectionTwelve(file,      "12",   0x100000,   0x124000,   6312,   "0x100000..0x124000 : Enemy battlesprites and animations");
    produceSpecificSectionThirteen(file,    "13",   0x124000,   0x130000,   492,    "0x124000..0x130000 : Spell graphics and animations");
    produceSpecificSectionFourteen(file,    "14",   0x130000,   0x144000,   22228,  "0x130000..0x144000 : Game intro, title screen, text banks");
    produceSpecificSectionFifteen(file,     "15",   0x144000,   0x164000,   6,      "0x144000..0x164000 : Ally battlesprites and animations, weapon sprites and palettes, battle platforms");
    produceSpecificSectionSixteen(file,     "16",   0x164000,   0x168000,   22,     "0x164000..0x168000 : ");
    produceLayoutSection(file,              "17",   0x168000,   0x180000,   0,      "0x168000..0x180000 : PCM banks, Music banks, Sound driver, YM instruments");

    fclose(file);

}


static produceSpecificSectionOne(mainFile,sectionName,start,end,fs,sectionComment){
    auto ea,itemSize,action,currentLine,previousLine,fileName,file;
    auto output, name, indent, comment, commentEx, commentIndent;
    fileName = form("layout\\sf1-%s-0x00000%s-0x00%s.asm",sectionName,ltoa(start,16),ltoa(end,16));
    Message(form("Writing assembly section %s to %s (%s) ... ",sectionName,fileName,sectionComment));    
    action = 1;
    writestr(mainFile,form("\t\tinclude \"%s\"\t\t; %s\n",fileName,sectionComment));
    file = fopen(form("disasm\\%s",fileName),"w");
    writestr(file,form("\n; GAME SECTION %s :\n; %s\n",sectionName,sectionComment));
    writestr(file,form("; FREE SPACE : %d bytes.\n\n\n",fs));
    
    produceAsmScript(file,"code\\romheader",0x0,0x200,"ROM Header");
    produceAsmSection(file,0x200,0x398);
    produceAsmScript(file,"code\\gameflow\\start\\initsystem",0x398,0x47A,"System init functions");
    produceAsmScript(file,"code\\gameflow\\start\\start",0x47A,0x5FA,"Program start function");
    produceAsmScript(file,"code\\common\\tech\\interrupts\\trap0_soundcommand",0x5FA,0x62E,"Trap 0 - Sound command");
    produceAsmScript(file,"code\\common\\tech\\interrupts\\errors",0x62E,0x698,"Error interrupts");
    produceAsmScript(file,"code\\common\\tech\\interrupts\\trap5_",0x698,0x6A8,"Trap 5 - ");
    produceAsmScript(file,"code\\common\\tech\\interrupts\\trap6_",0x6A8,0x6B8,"Trap 6 - ");
    produceAsmScript(file,"code\\common\\tech\\interrupts\\trap7_",0x6B8,0x6C8,"Trap 7 - ");
    produceAsmScript(file,"code\\common\\tech\\interrupts\\trap8_displaymessage",0x6C8,0x6D8,"Trap 8 - Display message");
    produceAsmScript(file,"code\\common\\tech\\interrupts\\vintengine_1",0x6D8,0xB4C,"Vertical Interrupt Engine - Main Technical Engine - Triggered at each frame display");
    produceAsmScript(file,"data\\graphics\\tech\\fadingdata",0xB4C,0xB9C,"Fading data table");
    produceAsmScript(file,"code\\common\\tech\\interrupts\\vintengine_2",0xB9C,0x137E,"Vertical Interrupt Engine - Main Technical Engine - Triggered at each frame display");
    produceAsmScript(file,"code\\common\\scripting\\text\\asciinumber",0x137E,0x1410,"ASCII number function");
    produceAsmScript(file,"code\\common\\tech\\input",0x1410,0x14EE,"Input functions");
    produceAsmScript(file,"code\\common\\tech\\randomnumbergenerator",0x14EE,0x150E,"RNG function");
    produceAsmScript(file,"code\\common\\tech\\sound\\music",0x150E,0x1526,"Sound function");
    produceAsmScript(file,"code\\common\\tech\\bytecopy",0x1526,0x1550,"Byte-copy function");
    produceAsmScript(file,"code\\common\\tech\\graphics\\graphics",0x1550,0x2046,"Graphics functions");
    produceAsmScript(file,"code\\common\\scripting\\text\\textfunctions",0x2046,0x25D0,"Text functions");
    produceAsmScript(file,"code\\common\\tech\\graphics\\graphicsdecompressors",0x25D0,0x2F72,"Graphics decompression functions");
    produceAsmScript(file,"code\\common\\tech\\interrupts\\trap1_",0x2F72,0x2F94,"Trap 1 - ");
    produceAsmScript(file,"code\\common\\tech\\interrupts\\trap2_",0x2F94,0x2FB6,"Trap 2 - ");
    produceAsmScript(file,"code\\common\\tech\\interrupts\\trap3_",0x2FB6,0x2FD8,"Trap 3 - ");
    produceAsmScript(file,"code\\common\\tech\\interrupts\\trap4_",0x2FD8,0x2FFA,"Trap 4 - ");
    produceAsmScript(file,"code\\common\\scripting\\eventflags",0x2FFA,0x309A,"Event flags functions");
    produceAsmScript(file,"code\\gameflow\\start\\initgame",0x309A,0x327E,"Game init functions");
    produceAsmSection(file,0x327E,0x3284);
    produceAsmScript(file,"code\\specialscreens\\readerscreen\\readerfunctions_1",0x3284,0x3660,"Simone screen functions, part 1");
    produceAsmScript(file,"code\\common\\tech\\sram\\sramfunctions",0x3660,0x3852,"SRAM functions");
    produceAsmScript(file,"code\\specialscreens\\readerscreen\\readerfunctions_2",0x3852,0x394C,"Simone screen functions, part 2");
    produceAsmSection(file,0x394C,0x39CC);
    produceAsmScript(file,"data\\graphics\\specialscreens\\readerscreen\\shiningforcelogolayout",0x39CC,0x3A44,"Shining Force logo layout");
    produceAsmScript(file,"code\\specialscreens\\chapterscreen\\chapterfunctions",0x3A44,0x3F0E,"Display chapter screen functions");
    produceAsmScript(file,"code\\common\\scripting\\battleexits",0x3F0E,0x49EE,"Battle exit scripts functions");
    produceAsmScript(file,"data\\graphics\\specialscreens\\chapterscreen\\chapterscreenlayouts",0x49EE,0x4C0E,"Chapter screen layouts");
    produceAsmScript(file,"code\\gameflow\\special\\sub_4C0E",0x4C0E,0x4D9A,"Related to the battle test debug function");
    produceAsmScript(file,"code\\gameflow\\special\\chaptertest",0x4D9A,0x4F00,"Chapter test functions");
    produceAsmScript(file,"code\\gameflow\\special\\battletest",0x4F00,0x50E2,"Battle test functions");
    produceAsmSection(file,0x50E2,0x51D2);
    produceAsmScript(file,"code\\gameflow\\special\\messagetest",0x51D2,0x530E,"Message test functions");
    produceAsmScript(file,"data\\graphics\\tech\\windowlayouts\\testscreens",0x530E,0x550C,"Test screens window layouts");
    produceAsmScript(file,"code\\common\\menus\\goldwindow",0x550C,0x55CC,"Gold window functions");
    produceAsmScript(file,"data\\graphics\\tech\\windowlayouts\\gold",0x55CC,0x560C,"Gold window layout");
    produceAsmScript(file,"code\\common\\menus\\menuengine",0x560C,0x66FA,"Menu engine");
    produceAsmScript(file,"code\\gameflow\\headquarters\\headquartersfunctions",0x66FA,0x69D4,"Headquarters functions");
    produceAsmScript(file,"data\\maps\\global\\headquartersmemberspositions",0x69D4,0x6A2E,"Headquarters force members positions table");
    produceAsmScript(file,"code\\gameflow\\end\\endingcutscenefunctions",0x6A2E,0x6AB8,"Ending cutscene functions");
    produceAsmScript(file,"data\\scripting\\ending\\endingcutscenecombatantdata",0x6AB8,0x6B38,"Ending cutscene combatant data table");
    produceAsmScript(file,"code\\common\\menus\\menuactions",0x6B38,0x75A0,"Menu actions");
    produceAsmScript(file,"data\\graphics\\tech\\windowlayouts\\equipmenu",0x75A0,0x77A4,"Equip menu window layouts");
    produceAsmSection(file,0x77A4,0x7B58);
    produceAsmScript(file,"data\\graphics\\tech\\windowlayouts\\battleoptions",0x7B58,0x7E22,"Battle options window layouts");
    produceAsmSection(file,0x7E22,0x8000);
    
    fclose(file);
    Message("DONE.\n");    
}    


static produceSpecificSectionTwo(mainFile,sectionName,start,end,fs,sectionComment){
    auto ea,itemSize,action,currentLine,previousLine,fileName,file;
    auto output, name, indent, comment, commentEx, commentIndent;
    fileName = form("layout\\sf1-%s-0x00%s-0x0%s.asm",sectionName,ltoa(start,16),ltoa(end,16));
    Message(form("Writing assembly section %s to %s (%s) ... ",sectionName,fileName,sectionComment));    
    action = 1;
    writestr(mainFile,form("\t\tinclude \"%s\"\t\t; %s\n",fileName,sectionComment));
    file = fopen(form("disasm\\%s",fileName),"w");
    writestr(file,form("\n; GAME SECTION %s :\n; %s\n",sectionName,sectionComment));
    writestr(file,form("; FREE SPACE : %d bytes.\n\n\n",fs));
    
    produceAsmSection(file,0x8000,0xB982);
    produceAsmScript(file,"data\\graphics\\tech\\windowlayouts\\statusscreen",0xB982,0xBE3A,"Status screen window layouts");
    produceAsmSection(file,0xBE3A,0xC900);
    produceAsmScript(file,"data\\graphics\\tech\\windowlayouts\\C900",0xC900,0xCC90,"Unknown layout");
    produceAsmScript(file,"data\\graphics\\tech\\windowlayouts\\CC90",0xCC90,0xCCD8,"Unknown layout");
    produceAsmSection(file,0xCCD8,0xD230);
    produceAsmScript(file,"data\\graphics\\tech\\windowlayouts\\ministatus",0xD230,0xD32C,"Mini status window layouts");
    produceAsmSection(file,0xD32C,0xD39A);
    produceAsmDataEntries(file,"data\\graphics\\tech\\windowlayouts\\miscmessages\\","miscmessage",0xD39A,0xD3BE,0xD75A,0xD75A,9,1,"Misc message window layout");
    produceAsmSection(file,0xD75A,0xDD1C);
    produceAsmScript(file,"data\\graphics\\tech\\windowlayouts\\battleequipmenu",0xDD1C,0xDEC0,"Battle equip menu window layouts");
    produceAsmScript(file,"code\\common\\menus\\landeffectwindow",0xDEC0,0xDF8C,"Land effect window functions");
    produceAsmScript(file,"data\\graphics\\tech\\windowlayouts\\landeffect",0xDF8C,0xDFEC,"Land effect window layout");
    produceAsmSection(file,0xDFEC,0xE156);
    produceAsmScript(file,"code\\common\\menus\\portraitfunctions",0xE156,0xE322,"Portrait functions");
    produceAsmScript(file,"data\\graphics\\tech\\windowlayouts\\portrait",0xE322,0xE49E,"Portrait window layouts");
    produceAsmScript(file,"code\\common\\menus\\shopscreen",0xE49E,0xEA66,"Shop screen functions");
    produceAsmScript(file,"code\\common\\menus\\memberslistscreen",0xEA66,0xF1CA,"Members list screen functions");
    produceAsmScript(file,"data\\graphics\\tech\\windowlayouts\\shopinventory",0xF1CA,0xF344,"Shop inventory window layouts");
    produceAsmSection(file,0xF344,0xF364);
    produceAsmScript(file,"data\\graphics\\tech\\windowlayouts\\shopitemnameandprice",0xF364,0xF3C8,"Shop item name and price window layout");
    produceAsmScript(file,"data\\graphics\\tech\\windowlayouts\\memberslistscreen",0xF3C8,0xF48E,"Members list screen window layouts");
    produceAsmScript(file,"data\\graphics\\tech\\windowlayouts\\itemmenuitemname",0xF48E,0xF4DE,"Item menu : Item name window layout");
    produceAsmSection(file,0xF4DE,0x10000);
    
    fclose(file);
    Message("DONE.\n");    
}    


static produceSpecificSectionThree(mainFile,sectionName,start,end,fs,sectionComment){
    auto ea,itemSize,action,currentLine,previousLine,fileName,file;
    auto output, name, indent, comment, commentEx, commentIndent;
    fileName = form("layout\\sf1-%s-0x0%s-0x0%s.asm",sectionName,ltoa(start,16),ltoa(end,16));
    Message(form("Writing assembly section %s to %s (%s) ... ",sectionName,fileName,sectionComment));    
    action = 1;
    writestr(mainFile,form("\t\tinclude \"%s\"\t\t; %s\n",fileName,sectionComment));
    file = fopen(form("disasm\\%s",fileName),"w");
    writestr(file,form("\n; GAME SECTION %s :\n; %s\n",sectionName,sectionComment));
    writestr(file,form("; FREE SPACE : %d bytes.\n\n\n",fs));    
    
    produceAsmSection(file,0x10000,0x10050);
    produceAsmSection(file,0x10050,0x168FE);
    produceAsmScript(file,"code\\common\\shopactions",0x168FE,0x16DAE,"Shop menu functions");
    produceAsmSection(file,0x16DAE,0x16F62);
    produceAsmScript(file,"data\\stats\\items\\shopdata",0x16F62,0x17028,"Shop data");
    produceAsmScript(file,"code\\common\\churchactions",0x17028,0x175DE,"Church menu functions");
    produceAsmSection(file,0x175DE,0x17BBC);
    produceAsmScript(file,"data\\stats\\spritespeechsfx",0x17BBC,0x17C5E,"Sprite dialog bleeps");
    produceAsmSection(file,0x17C5E,0x1D3B2);
    produceAsmDataEntries(file,"data\\battles\\global\\exits\\","battleexits",0x1D3B2,0x1D3D2,0x1D68E,0x1D68E,8,1,"Battle exits table");
    produceAsmScript(file,"data\\battles\\global\\battlechests",0x1D68E,0x1DA8E,"Chest data");
    produceAsmSection(file,0x1DA8E,0x1E892);
    produceAsmSection(file,0x1E892,0x1EFE0);
    produceAsmScript(file,"code\\common\\scripting\\text\\huffmandecoder",0x1EFE0,0x1F068,"Text decoding functions");    
    produceAsmSection(file,0x1F068,0x20000);
    
    fclose(file);
    Message("DONE.\n");    
}    


static produceSpecificSectionFour(mainFile,sectionName,start,end,fs,sectionComment){
    auto ea,itemSize,action,currentLine,previousLine,fileName,file;
    auto output, name, indent, comment, commentEx, commentIndent;
    fileName = form("layout\\sf1-%s-0x0%s-0x0%s.asm",sectionName,ltoa(start,16),ltoa(end,16));
    Message(form("Writing assembly section %s to %s (%s) ... ",sectionName,fileName,sectionComment));    
    action = 1;
    writestr(mainFile,form("\t\tinclude \"%s\"\t\t; %s\n",fileName,sectionComment));
    file = fopen(form("disasm\\%s",fileName),"w");
    writestr(file,form("\n; GAME SECTION %s :\n; %s\n",sectionName,sectionComment));
    writestr(file,form("; FREE SPACE : %d bytes.\n\n\n",fs));    
    
    produceAsmSection(file,0x20000,0x20404);
    produceAsmScript(file,"code\\gameflow\\battle\\battlefieldengine",0x20404,0x20A04,"Battlefield engine");
    produceAsmScript(file,"code\\gameflow\\battle\\battleactionsengine",0x20A04,0x21520,"Battle actions engine");
    produceAsmScript(file,"code\\gameflow\\battle\\battlescenes\\battlesceneengine",0x21520,0x21AEE,"Battlescene engine");
    produceAsmScript(file,"code\\gameflow\\start\\newgame",0x21AEE,0x21B80,"New game initialization functions");
    produceAsmScript(file,"code\\common\\stats\\statsengine_1",0x21B80,0x23178,"Character stats engine");
    produceAsmScript(file,"data\\stats\\ranges\\rangedata",0x23178,0x23378,"Battleactions range data table");
    produceAsmScript(file,"code\\common\\stats\\statsengine_2",0x23378,0x23A1E,"Character stats engine");
    produceAsmScript(file,"data\\stats\\allies\\promotedportraits",0x23A1E,0x23A3E,"Portraits used for promoted allies");
    produceAsmScript(file,"code\\common\\stats\\statsengine_3",0x23A3E,0x23ACE,"Character stats engine");
    produceAsmScript(file,"data\\stats\\allies\\outfits",0x23ACE,0x23AD6,"Character outfits data");
    produceAsmScript(file,"code\\common\\stats\\statsengine_4",0x23AD6,0x24006,"Character stats engine");
    produceAsmScript(file,"data\\stats\\enemies\\specialaiactions",0x24006,0x2401C,"Special AI actions");
    produceAsmScript(file,"code\\common\\stats\\statsengine_5",0x2401C,0x240DC,"Character stats engine");
    produceAsmScript(file,"data\\stats\\enemies\\darkdragonspells",0x240DC,0x240E8,"Dark Dragon spells table");
    produceAsmScript(file,"data\\battles\\global\\aipriority",0x240E8,0x244CA,"AI priority values by movetype and class");
    produceAsmScript(file,"code\\common\\stats\\statsengine_6",0x244CA,0x246EC,"Character stats engine");
    produceAsmScript(file,"code\\common\\stats\\levelup",0x246EC,0x24BAC,"Level up functions");
    produceAsmScript(file,"code\\common\\stats\\statsfunctions",0x24BAC,0x24FC4,"Stats functions");
    produceAsmScript(file,"code\\gameflow\\battle\\battlefunctions",0x24FC4,0x25154,"Battle functions");
    produceAsmScript(file,"data\\stats\\allies\\characterdata",0x25154,0x25604,"Initial character data");
    produceAsmScript(file,"data\\stats\\allies\\battlespritedata",0x25604,0x25640,"Ally battlesprites table");
    produceAsmScript(file,"data\\stats\\items\\itemnames",0x25640,0x25916,"Item names");
    produceAsmScript(file,"data\\stats\\items\\itemdata",0x25916,0x25D06,"Item definitions");
    produceAsmScript(file,"data\\stats\\items\\weaponsprites",0x25D06,0x25D2C,"Weaponsprite table");
    produceAsmScript(file,"data\\stats\\items\\itemtypes",0x25D2C,0x25D6C,"Item types table");
    produceAsmScript(file,"data\\stats\\classes\\classnames",0x25D6C,0x260BC,"Names for enemies and ally classes");
    produceAsmScript(file,"data\\stats\\classes\\classdata",0x260BC,0x26404,"Enemy and ally class definitions");
    produceAsmScript(file,"data\\stats\\spells\\spellnames",0x26404,0x26466,"Spell names");
    produceAsmScript(file,"data\\stats\\spells\\spelldata",0x26466,0x26566,"Spell definitions");
    produceAsmScript(file,"data\\battles\\global\\movecosts",0x26566,0x265E6,"Move costs table");
    produceAsmScript(file,"data\\battles\\global\\landeffects",0x265E6,0x26666,"Land effect table");
    produceAsmScript(file,"data\\stats\\allies\\allyanimations",0x26666,0x2688E,"Ally battlescene animations data");
    produceAsmScript(file,"data\\stats\\enemies\\enemyanimations",0x2688E,0x269FE,"Enemy battlescene animations data");
    produceAsmScript(file,"data\\battles\\global\\terraindefs",0x269FE,0x26BF2,"Battlefield terrain definitions");
    produceAsmSection(file,0x26BF2,0x26BF6);
    produceAsmScript(file,"data\\stats\\allies\\growthcurves",0x26BF6,0x26C1A,"Growth curve tables");
    produceAsmScript(file,"data\\stats\\allies\\charactergrowths",0x26C1A,0x26D70,"Ally growth tables");
    produceAsmScript(file,"data\\stats\\allies\\spelllearningdata",0x26D70,0x26E16,"Ally spell tables");
    produceAsmScript(file,"code\\gameflow\\end\\endingcreditsbattlescenes_1",0x26E16,0x26EE4,"Ending credits battle scenes, part 1");
    produceAsmScript(file,"data\\stats\\allies\\endcreditsforcedata",0x26EE4,0x26F0A,"Ally data for credits scenes");
    produceAsmScript(file,"code\\gameflow\\end\\endingcreditsbattlescenes_2",0x26F0A,0x26F46,"Ending credits battle scenes, part 2");
    produceAsmScript(file,"code\\gameflow\\battle\\battleinit",0x26F46,0x2704E,"Battle initialization functions");
    produceAsmScript(file,"data\\battles\\global\\battlemapheaders",0x2704E,0x2751A,"Battle map headers relative pointer table");
    produceAsmSection(file,0x2751A,0x2751C);
    produceAsmScript(file,"data\\stats\\enemies\\enemydefs",0x2751C,0x27AC4,"Enemy definitions");
    produceAsmScript(file,"data\\battles\\global\\battleterrain",0x27AC4,0x29EA4,"Battle terrain data");
    produceAsmScript(file,"data\\battles\\global\\battledata",0x29EA4,0x2BF84,"Position/enemy/ai data for battles");
    produceAsmSection(file,0x2BF84,0x2C000);
    
    fclose(file);
    Message("DONE.\n");
}


static produceSpecificSectionFive(mainFile,sectionName,start,end,fs,sectionComment){
    auto ea,itemSize,action,currentLine,previousLine,fileName,file;
    auto output, name, indent, comment, commentEx, commentIndent;
    fileName = form("layout\\sf1-%s-0x0%s-0x0%s.asm",sectionName,ltoa(start,16),ltoa(end,16));
    Message(form("Writing assembly section %s to %s (%s) ... ",sectionName,fileName,sectionComment));
    action = 1;
    writestr(mainFile,form("\t\tinclude \"%s\"\t\t; %s\n",fileName,sectionComment));
    file = fopen(form("disasm\\%s",fileName),"w");
    writestr(file,form("\n; GAME SECTION %s :\n; %s\n",sectionName,sectionComment));
    writestr(file,form("; FREE SPACE : %d bytes.\n\n\n",fs));
    
    produceAsmSection(file,0x2C000,0x2C008);
    produceAsmScript(file,"code\\gameflow\\start\\regioncheck",0x2C008,0x2C13E,"Region check functions");
    produceAsmSection(file,0x2C13E,0x2D13E);
    produceAsmScript(file,"data\\graphics\\portraits\\entries",0x2D13E,0x37B38,"Portraits");
    produceAsmSection(file,0x37B38,0x38000);
    
    fclose(file);
    Message("DONE.\n");
}


static produceSpecificSectionSix(mainFile,sectionName,start,end,fs,sectionComment){
    auto ea,itemSize,action,currentLine,previousLine,fileName,file;
    auto output, name, indent, comment, commentEx, commentIndent;
    fileName = form("layout\\sf1-%s-0x0%s-0x0%s.asm",sectionName,ltoa(start,16),ltoa(end,16));
    Message(form("Writing assembly section %s to %s (%s) ... ",sectionName,fileName,sectionComment));    
    action = 1;
    writestr(mainFile,form("\t\tinclude \"%s\"\t\t; %s\n",fileName,sectionComment));
    file = fopen(form("disasm\\%s",fileName),"w");
    writestr(file,form("\n; GAME SECTION %s :\n; %s\n",sectionName,sectionComment));
    writestr(file,form("; FREE SPACE : %d bytes.\n\n\n",fs));
    
    //produceAsmSection(file,0x38000,0x39928);
    produceAsmScript(file,"data\\graphics\\mapsprites\\entries",0x38000,0x58000,"Map sprites");
    //produceAsmSection(file,0x57F5E,0x58000);
    
    fclose(file);
    Message("DONE.\n");    
}


static produceSpecificSectionSeven(mainFile,sectionName,start,end,fs,sectionComment){
    auto ea,itemSize,action,currentLine,previousLine,fileName,file;
    auto output, name, indent, comment, commentEx, commentIndent;
    auto battleCutscenesFile, mapSetupsFile;
    fileName = form("layout\\sf1-%s-0x0%s-0x0%s.asm",sectionName,ltoa(start,16),ltoa(end,16));
    Message(form("Writing assembly section %s to %s (%s) ... ",sectionName,fileName,sectionComment));    
    action = 1;
    writestr(mainFile,form("\t\tinclude \"%s\"\t\t; %s\n",fileName,sectionComment));
    file = fopen(form("disasm\\%s",fileName),"w");
    writestr(file,form("\n; GAME SECTION %s :\n; %s\n",sectionName,sectionComment));
    writestr(file,form("; FREE SPACE : %d bytes.\n\n\n",fs));    
    
    produceAsmSection(file,0x58000,0x58014);
    produceAsmScript(file,"data\\graphics\\maps\\maptilesets\\entries",0x58014,0x7F344,"Map tilesets");
    produceAsmSection(file,0x7F344,0x80000);
    
    fclose(file);
    Message("DONE.\n");
}


static produceSpecificSectionEight(mainFile,sectionName,start,end,fs,sectionComment){
    auto ea,itemSize,action,currentLine,previousLine,fileName,file;
    auto output, name, indent, comment, commentEx, commentIndent;
    fileName = form("layout\\sf1-%s-0x0%s-0x0%s.asm",sectionName,ltoa(start,16),ltoa(end,16));
    Message(form("Writing assembly section %s to %s (%s) ... ",sectionName,fileName,sectionComment));    
    action = 1;
    writestr(mainFile,form("\t\tinclude \"%s\"\t\t; %s\n",fileName,sectionComment));
    file = fopen(form("disasm\\%s",fileName),"w");
    writestr(file,form("\n; GAME SECTION %s :\n; %s\n",sectionName,sectionComment));
    writestr(file,form("; FREE SPACE : %d bytes.\n\n\n",fs));    
    
    produceAsmSection(file,0x80000,0x80010);
    produceAsmScript(file,"data\\maps\\spritesets\\entries",0x80010,0x80EE0,"Sprite sets");
    produceAsmScript(file,"code\\common\\scripting\\getmapspritescriptaddress",0x80EE0,0x80EFE,"Mapsprite script address getter function");
    produceAsmScript(file,"data\\scripting\\mapspritescripts\\entries",0x80EFE,0x820CC,"Map sprite scripts");
    produceAsmScript(file,"data\\maps\\entries",0x820CC,0xB97F4,"Map data");
    produceAsmScript(file,"data\\maps\\tileanimations\\entries",0xB97F4,0xBA3EC,"Tile animation data");
    produceAsmSection(file,0xBA3EC,0xBC000);

    fclose(file);
    Message("DONE.\n");    
}


static produceSpecificSectionNine(mainFile,sectionName,start,end,fs,sectionComment){
    auto ea,itemSize,action,currentLine,previousLine,fileName,file;
    auto output, name, indent, comment, commentEx, commentIndent;
    fileName = form("layout\\sf1-%s-0x0%s-0x%s.asm",sectionName,ltoa(start,16),ltoa(end,16));
    Message(form("Writing assembly section %s to %s (%s) ... ",sectionName,fileName,sectionComment));    
    action = 1;
    writestr(mainFile,form("\t\tinclude \"%s\"\t\t; %s\n",fileName,sectionComment));
    file = fopen(form("disasm\\%s",fileName),"w");
    writestr(file,form("\n; GAME SECTION %s :\n; %s\n",sectionName,sectionComment));
    writestr(file,form("; FREE SPACE : %d bytes.\n\n\n",fs));    
    
    produceAsmSection(file,0xBC000,0xBC01C);
    produceAsmScript(file,"code\\gameflow\\special\\soundtest",0xBC01C,0xBC29E,"Sound test functions");
    produceAsmSection(file,0xBC29E,0xBDC38);
    produceAsmScript(file,"data\\graphics\\specialscreens\\soundtest\\soundtestscreenlayout",0xBDC38,0xBE338,"Sound test screen layout");
    produceAsmSection(file,0xBE338,0xBE470);
    produceAsmScript(file,"data\\graphics\\tech\\windowlayouts\\soundtestwindowlayout",0xBE470,0xBE510,"Sound test window layout");
    produceAsmSection(file,0xBE510,0xC0000);
    
    fclose(file);
    Message("DONE.\n");    
}


static produceSpecificSectionEleven(mainFile,sectionName,start,end,fs,sectionComment){
    auto ea,itemSize,action,currentLine,previousLine,fileName,file;
    auto output, name, indent, comment, commentEx, commentIndent;
    fileName = form("layout\\sf1-%s-0x%s-0x%s.asm",sectionName,ltoa(start,16),ltoa(end,16));
    Message(form("Writing assembly section %s to %s (%s) ... ",sectionName,fileName,sectionComment));    
    action = 1;
    writestr(mainFile,form("\t\tinclude \"%s\"\t\t; %s\n",fileName,sectionComment));
    file = fopen(form("disasm\\%s",fileName),"w");
    writestr(file,form("\n; GAME SECTION %s :\n; %s\n",sectionName,sectionComment));
    writestr(file,form("; FREE SPACE : %d bytes.\n\n\n",fs));    
    
    produceAsmSection(file,0xCC000,0xCC030);
    produceAsmScript(file,"code\\gameflow\\start\\basetiles",0xCC030,0xCC05E,"Base tiles loading");
    produceAsmSection(file,0xCC05E,0xD2EA4);
    produceAsmScript(file,"code\\gameflow\\end\\endingcredits",0xD2EA4,0xD301A,"Ending credits functions");
    produceAsmScript(file,"data\\graphics\\tech\\windowlayouts\\textinput",0xD301A,0xD32DA,"Text input window layout");
    produceAsmSection(file,0xD32DA,0xD398E);
    produceAsmScript(file,"data\\graphics\\battles\\backgrounds\\entries",0xD398E,0xFFD3C,"Backgrounds");
    produceAsmSection(file,0xFFD3C,0x100000);
    
    fclose(file);
    Message("DONE.\n");    
}


static produceSpecificSectionTwelve(mainFile,sectionName,start,end,fs,sectionComment){
    auto ea,itemSize,action,currentLine,previousLine,fileName,file;
    auto output, name, indent, comment, commentEx, commentIndent;
    fileName = form("layout\\sf1-%s-0x%s-0x%s.asm",sectionName,ltoa(start,16),ltoa(end,16));
    Message(form("Writing assembly section %s to %s (%s) ... ",sectionName,fileName,sectionComment));    
    action = 1;
    writestr(mainFile,form("\t\tinclude \"%s\"\t\t; %s\n",fileName,sectionComment));
    file = fopen(form("disasm\\%s",fileName),"w");
    writestr(file,form("\n; GAME SECTION %s :\n; %s\n",sectionName,sectionComment));
    writestr(file,form("; FREE SPACE : %d bytes.\n\n\n",fs));    
    
    produceAsmSection(file,0x100000,0x100008);
    produceAsmScript(file,"data\\graphics\\battles\\battlesprites\\enemies\\entries",0x100008,0x122252,"Enemy battlesprites");
    produceAsmScript(file,"data\\graphics\\battles\\battlesprites\\enemies\\animations\\entries",0x122252,0x122758,"Enemy battle animations");
    produceAsmSection(file,0x122758,0x124000);
    
    fclose(file);
    Message("DONE.\n");
}


static produceSpecificSectionThirteen(mainFile,sectionName,start,end,fs,sectionComment){
    auto ea,itemSize,action,currentLine,previousLine,fileName,file;
    auto output, name, indent, comment, commentEx, commentIndent;
    fileName = form("layout\\sf1-%s-0x%s-0x%s.asm",sectionName,ltoa(start,16),ltoa(end,16));
    Message(form("Writing assembly section %s to %s (%s) ... ",sectionName,fileName,sectionComment));    
    action = 1;
    writestr(mainFile,form("\t\tinclude \"%s\"\t\t; %s\n",fileName,sectionComment));
    file = fopen(form("disasm\\%s",fileName),"w");
    writestr(file,form("\n; GAME SECTION %s :\n; %s\n",sectionName,sectionComment));
    writestr(file,form("; FREE SPACE : %d bytes.\n\n\n",fs));    
    
    produceAsmSection(file,0x124000,0x12407C);
    produceAsmScript(file,"code\\gameflow\\battle\\battlesceneengine",0x12407C,0x12647E,"Battle scene engine");
    produceAsmScript(file,"code\\gameflow\\battle\\spellanimations",0x12647E,0x128F98,"Spell animation functions");
    produceAsmScript(file,"code\\common\\scripting\\beforebattlecutscenes",0x128F98,0x12A4C4,"Before-battle cutscenes");
    produceAsmScript(file,"code\\common\\scripting\\endofbattlecutscenes",0x12A4C4,0x12ABCC,"End-of-battle cutscenes");
    produceAsmScript(file,"code\\common\\scripting\\afterbattlecutscenes",0x12ABCC,0x12BF42,"After-battle cutscenes");
    produceAsmScript(file,"code\\common\\scripting\\battlecutscenefunctions",0x12BF42,0x12C7B0,"Battle-related cutscene functions");
    produceAsmSection(file,0x12C7B0,0x130000);

    fclose(file);
    Message("DONE.\n");    
}


static produceSpecificSectionFourteen(mainFile,sectionName,start,end,fs,sectionComment){
    auto ea,itemSize,action,currentLine,previousLine,fileName,file;
    auto output, name, indent, comment, commentEx, commentIndent;
    fileName = form("layout\\sf1-%s-0x%s-0x%s.asm",sectionName,ltoa(start,16),ltoa(end,16));
    Message(form("Writing assembly section %s to %s (%s) ... ",sectionName,fileName,sectionComment));    
    action = 1;
    writestr(mainFile,form("\t\tinclude \"%s\"\t\t; %s\n",fileName,sectionComment));
    file = fopen(form("disasm\\%s",fileName),"w");
    writestr(file,form("\n; GAME SECTION %s :\n; %s\n",sectionName,sectionComment));
    writestr(file,form("; FREE SPACE : %d bytes.\n\n\n",fs));    

    produceAsmSection(file,0x130000,0x130004);
    produceAsmScript(file,"code\\gameflow\\start\\gameintro",0x130004,0x131A1C,"Game intro");
    produceAsmScript(file,"data\\scripting\\text\\textbanks\\entries",0x131A1C,0x13E92A,"Text banks");
    produceAsmSection(file,0x13E92A,0x144000);

    fclose(file);
    Message("DONE.\n");
}


static produceSpecificSectionFifteen(mainFile,sectionName,start,end,fs,sectionComment){
    auto ea,itemSize,action,currentLine,previousLine,fileName,file;
    auto output, name, indent, comment, commentEx, commentIndent;
    fileName = form("layout\\sf1-%s-0x%s-0x%s.asm",sectionName,ltoa(start,16),ltoa(end,16));
    Message(form("Writing assembly section %s to %s (%s) ... ",sectionName,fileName,sectionComment));    
    action = 1;
    writestr(mainFile,form("\t\tinclude \"%s\"\t\t; %s\n",fileName,sectionComment));
    file = fopen(form("disasm\\%s",fileName),"w");
    writestr(file,form("\n; GAME SECTION %s :\n; %s\n",sectionName,sectionComment));
    writestr(file,form("; FREE SPACE : %d bytes.\n\n\n",fs));    
    
    produceAsmSection(file,0x144000,0x144014);
    produceAsmScript(file,"data\\graphics\\battles\\battlesprites\\allies\\entries",0x144014,0x1602E2,"Ally battlesprites");
    produceAsmScript(file,"data\\graphics\\battles\\weapons\\entries",0x1602E2,0x16186E,"Weapon sprites");
    produceAsmSection(file,0x16186E,0x161A66);
    produceAsmScript(file,"data\\graphics\\battles\\battlesprites\\allies\\animations\\entries",0x161A66,0x16226A,"Ally battlesprite animations");
    produceAsmScript(file,"data\\graphics\\battles\\platforms\\entries",0x16226A,0x163FFA,"Platform sprites");
    produceAsmSection(file,0x163FFA,0x164000);
    
    fclose(file);
    Message("DONE.\n");
}


static produceSpecificSectionSixteen(mainFile,sectionName,start,end,fs,sectionComment){
    auto ea,itemSize,action,currentLine,previousLine,fileName,file;
    auto output, name, indent, comment, commentEx, commentIndent;
    fileName = form("layout\\sf1-%s-0x%s-0x%s.asm",sectionName,ltoa(start,16),ltoa(end,16));
    Message(form("Writing assembly section %s to %s (%s) ... ",sectionName,fileName,sectionComment));    
    action = 1;
    writestr(mainFile,form("\t\tinclude \"%s\"\t\t; %s\n",fileName,sectionComment));
    file = fopen(form("disasm\\%s",fileName),"w");
    writestr(file,form("\n; GAME SECTION %s :\n; %s\n",sectionName,sectionComment));
    writestr(file,form("; FREE SPACE : %d bytes.\n\n\n",fs));    
    
    produceAsmSection(file,0x164000,0x16401C);
    produceAsmSection(file,0x16401C,0x1674E4);
    produceAsmScript(file,"code\\specialscreens\\segalogo\\segalogo",0x1674E4,0x167FEA,"SEGA logo functions");
    produceAsmSection(file,0x167FEA,0x168000);

    fclose(file);
    Message("DONE.\n");    
}




static produceAsmDataEntries(mainFile,sectionName,entryName,start,end,lastEntryDataEnd,chunkEnd,maxIndex,indexLength,sectionComment){
    auto fileName, file, addr, i, j, dref, dataEnd, from, index, entryFileName, entryComment;
    /* Produce main file */
    fileName = form("%sentries", sectionName);
    produceAsmScript(mainFile,fileName,start,end,sectionComment);
    file = fopen(form("disasm\\%s.asm", fileName),"a");
    /* Produce individual entry files */
    addr = start;
    i = 0;
    while(addr<end&&i<maxIndex){
        dref = Dfirst(addr);
        dataEnd = 0;
        j = dref+1;
        /* Finding entry's data end */
        while(dataEnd==0){
            from = DfirstB(j);
            while(from!=BADADDR){
                if(from>=start&&from<lastEntryDataEnd){dataEnd = j;}
                from = DnextB(addr,from);
            }
            j++;
            if(j==lastEntryDataEnd){dataEnd = lastEntryDataEnd;}
        }
        index = ltoa(i,10);
        while(strlen(index)<indexLength){index = form("0%s", index);}
        entryFileName = form("%s%s%s", sectionName,entryName,index);
        entryComment = form("%s %s", sectionComment,index);
        produceAsmScript(file,entryFileName,dref,dataEnd,entryComment);
        addr = addr+4;
        i++;
    }
    if(lastEntryDataEnd<chunkEnd){
        produceAsmSection(file,lastEntryDataEnd,chunkEnd);
    }
    fclose(file);
}


static produceSection(mainFile,sectionName,start,end,fs,sectionComment){
    auto fileName;
    fileName = form("sf1-%s.asm",sectionName);
    produceSectionWithPrettyPrintParam(mainFile,sectionName,start,end,fs,sectionComment,1,fileName);
}


static produceLayoutSection(mainFile,sectionName,start,end,fs,sectionComment){
    auto fileName;
    fileName = form("layout\\sf1-%s-0x%s-0x%s.asm",sectionName,ltoa(start,16),ltoa(end,16));
    produceSectionWithPrettyPrintParam(mainFile,sectionName,start,end,fs,sectionComment,1,fileName);
}


static produceSectionWithPrettyPrintParam(mainFile,sectionName,start,end,fs,sectionComment,prettyPrint,fileName){
    auto ea,itemSize,action,currentLine,previousLine,file;
    //auto ea,itemSize,action,currentLine,previousLine,fileName,file;
    auto output, name, indent, comment, commentEx, commentIndent;
    //fileName = form("sf1-%s.asm",sectionName);
    Message(form("Writing assembly section %s to %s (%s) ... ",sectionName,fileName,sectionComment));    
    action = 1;
    writestr(mainFile,form("\t\tinclude \"%s\"\t\t; %s\n",fileName,sectionComment));
    file = fopen(form("disasm\\%s",fileName),"w");
    writestr(file,form("\n; GAME SECTION %s :\n; %s\n",sectionName,sectionComment));
    writestr(file,form("; FREE SPACE : %d bytes.\n\n\n",fs));    
    ea = start;
    while(ea<end){
        itemSize = ItemSize(ea);
        if(GetFunctionAttr(ea,FUNCATTR_START)==ea){    
            writeFunctionHeader(file,ea,prettyPrint);
        }
        else if(GetFchunkAttr(ea,FUNCATTR_START)==ea){    
            writeFChunkHeader(file,ea,prettyPrint);
        }        
        writeItem(file,ea);
        if(GetFunctionAttr(ea,FUNCATTR_END)==(ea+itemSize)){
            writeFunctionFooter(file,ea,prettyPrint);
        }        
        else if(GetFchunkAttr(ea,FUNCATTR_END)==(ea+itemSize)){
            writeFChunkFooter(file,ea,prettyPrint);
        }                
        ea = ea + itemSize;
    }
    fclose(file);
    Message("DONE.\n");    

}

static produceAsmScript(mainFile,sectionName,start,end,sectionComment){
    auto ea,itemSize,action,currentLine,previousLine,fileName,file;
    auto output, name, indent, comment, commentEx, commentIndent, offsets;
    fileName = form("%s.asm",sectionName);
    Message(form("Writing assembly script section %s to %s (%s) ... ",sectionName,fileName,sectionComment));    
    action = 1;
    writestr(mainFile,form("\t\tinclude \"%s\"\t\t; %s\n",fileName,sectionComment));
    file = fopen(form("disasm\\%s",fileName),"w");
    offsets = form("0x%s..0x%s",ltoa(start,16),ltoa(end,16));
    writestr(file,form("\n; ASM FILE %s.asm :\n; %s : %s\n",sectionName,offsets,sectionComment));    
    produceAsmSection(file,start,end);
    fclose(file);
    Message("DONE.\n");    

}

static produceAsmSection(file,start,end){
    produceAsmSectionWithPrettyParam(file,start,end,1);
}

static produceAsmSectionNoPretty(file,start,end){
    produceAsmSectionWithPrettyParam(file,start,end,0);
}

static produceAsmSectionWithPrettyParam(file,start,end,prettyWriteFunctions){
    auto ea,itemSize;
    ea = start;
    while(ea<end){
        itemSize = ItemSize(ea);
        if(GetFunctionAttr(ea,FUNCATTR_START)==ea){    
            writeFunctionHeader(file,ea,prettyWriteFunctions);
        }
        else if(GetFchunkAttr(ea,FUNCATTR_START)==ea){    
            writeFChunkHeader(file,ea,prettyWriteFunctions);
        }        
        writeItemWithPrettyPrintParam(file,ea,prettyWriteFunctions);
        if(GetFunctionAttr(ea,FUNCATTR_END)==(ea+itemSize)){
            writeFunctionFooter(file,ea,prettyWriteFunctions);
        }        
        else if(GetFchunkAttr(ea,FUNCATTR_END)==(ea+itemSize)){
            writeFChunkFooter(file,ea,prettyWriteFunctions);
        }                
        ea = ea + itemSize;
    }
}

static writeHeader(file){
    writestr(file,"\n");
    writestr(file,"   include \"sf1macros.asm\"\n");    
    writestr(file,"   include \"sf1patches.asm\"\n");    
    writestr(file,"   include \"sf1enums.asm\"\n");
    writestr(file,"   include \"sf1const.asm\"\n");
    writestr(file,"\n");
    writestr(file,"   include \"layout\\sf1-00-romlayout.asm\"\n");
}

static writeFooter(file){
    writestr(file,"        END");
}

static writeFunctionHeader(file, ea, prettyWriteFunctions){
    auto funcCmt;
    if(prettyWriteFunctions!=0){
        writestr(file,"\n; =============== S U B R O U T I N E =======================================\n\n");
    }
    funcCmt = GetFunctionCmt(ea,0);
    if(funcCmt!=""){
        writestr(file,form("; %s\n",funcCmt));
        if(prettyWriteFunctions!=0){
            writestr(file,"\n");
        }
    }
    else{
        funcCmt = GetFunctionCmt(ea,1);
        if(funcCmt!=""){
            funcCmt = formatFuncRptCmt(funcCmt);
            writestr(file,form("; %s\n",funcCmt));
            if(prettyWriteFunctions!=0){
                writestr(file,"\n");
            }            
        }
    }
    undefineLocalVars(file,ea);
}

static undefineLocalVars(file,ea){
    auto id, i, firstM, lastM, mName, mSize, mFlag;
    id = GetFrame(ea);
    firstM = GetFirstMember(id);
    lastM = GetLastMember(id);
    i=firstM;
    while(i<=lastM){
        if(i!=-1&&GetMemberName(id,i)!=""&&GetMemberName(id,i)!=" r"&&GetMemberName(id,i)!=" s"){
            mName = GetMemberName(id,i); // Get the name
            mSize = GetMemberSize(id, i); // Get the size (in byte)
            mFlag = GetMemberFlag(id, i); // Get the flag
            Message("\n%a : undefined %s %d %x", ea, mName, mSize, mFlag);
            DelStrucMember(id,i);        
            i = i+mSize;
        }
        else{
            i++;
        }    
    }
}

static undefineMultipleLineArray(ea){
    auto type;
            type = GuessType(ea);
            if(strstr(type,"char[")!=-1&&(strstr(GetDisasm(ea),"incbin")==-1)){
                    Message(form("\n%a : %s \t\t<== UNDEFINE if on multiple lines.",ea,GuessType(ea)));
            }    
}

static writeFunctionFooter(file, ea,prettyWriteFunctions){
    auto funcName;
    funcName = GetFunctionName(ea);
    if(prettyWriteFunctions!=0){
        writestr(file,form("\n    ; End of function %s\n\n",funcName));
    }
}

static writeItem(file,ea){
    writeItemWithPrettyPrintParam(file,ea,1);
}

static writeItemWithPrettyPrintParam(file,ea,prettyPrint){
    auto name,tabLength,ln,indent,disasm,cmtIdx,commentIndent,comment,commentEx,i,line,lineA,lineB,type,output;
    tabLength = 8;
    indent = "\t\t";
    commentIndent = "\t\t\t\t";
    name = GetTrueNameEx(ea,ea);        // Get local label name if it exists
    if(name==""){
        name = Name(ea);
    }
    if(name!=""){
        name=form("%s:",name);
        if(GetFunctionAttr(ea,FUNCATTR_START)!=-1){
            if(prettyPrint!=0){
                ln = "\n";
            }else{
                ln = "";
            }
            name = form("%s%s%s",name,ln,indent);
        }
        else{
            while(strlen(name)<(strlen(indent)*tabLength)){
                name = form("%s ",name);
            }        
            undefineMultipleLineArray(ea);
        }
    }
    else {
        name = indent;
    }
    commentEx = CommentEx(ea,0);
    if(commentEx!=""){
        comment = commentEx;
    }
    else{
        commentEx = CommentEx(ea,1);
        if(commentEx!=""){
            comment = formatRptCmt(commentEx);
        }
    }
    lineA = LineA(ea,0);
    disasm = GetDisasm(ea);
    cmtIdx = strstr(disasm,";");
    lineB = LineB(ea,0);
    if(lineA!=""){
        lineA = form("%s\n",lineA);
    }
    if(lineB!=""){
        lineB = form("%s\n",lineB);
    }    
    if(cmtIdx!=-1){
        disasm = substr(disasm,0,cmtIdx);
    }
    if(comment!=""){
        comment = form("; %s",comment);
    }
    if(strlen(name)>(strlen(indent)*tabLength)){
        name = form("%s\n%s",name,indent);
    }
    if(strstr(lineA,"\n")!=-1){
        lineA = form("%s%s",lineA,indent);
    }
    if(strlen(disasm)>(strlen(commentIndent)*tabLength)&&comment!=""){
        disasm = form("%s\n%s%s",disasm,indent,commentIndent);
    }
    //Message(form("\nname=%s,lineA=%s,disasm=%s,comment=%s,lineB=%s",name,lineA,disasm,comment,lineB));        
    output = form("%s%s%s%s\n%s",name,lineA,disasm,comment,lineB);
    writestr(file,output);
}

static writeFChunkHeader(file,ea,prettyWriteFunctions){
    auto text,functionName;
    text = "; START OF FUNCTION CHUNK FOR ";
    functionName = GetFunctionName(ea);
    writestr(file,form("\n%s%s\n\n",text,functionName));
}

static writeFChunkFooter(file,ea,prettyWriteFunctions){
    auto text,functionName;
    text = "; END OF FUNCTION CHUNK FOR ";
    functionName = GetFunctionName(ea);
    writestr(file,form("\n%s%s\n\n",text,functionName));
}

static formatFuncRptCmt(cmt){
    auto index, before, after, result;
    index = strstr(cmt,"\n");
    if(index!=-1){
        before = substr(cmt,0,index+1);
        after = substr(cmt,index+1,strlen(cmt));
        result = form("%s; %s",before,formatFuncRptCmt(after));
        return result;
    }
    else{
        return cmt;
    }
}

static formatRptCmt(cmt){
    auto index, before, after, result;
    index = strstr(cmt,"\n");
    if(index!=-1){
        before = substr(cmt,0,index+1);
        after = substr(cmt,index+1,strlen(cmt));
        result = form("%s\t\t\t\t\t\t\t\t\t\t\t\t\t\t; %s",before,formatRptCmt(after));
        return result;
    }
    else{
        return cmt;
    }
}