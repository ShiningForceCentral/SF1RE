

#include <idc.idc>



static main(void){


    splitAll();


}







static splitAll(){
    auto file;

    Message("SPLITTING...\n");
    file = fopen("sf1splits.txt","w");
    initFile(file);
    
    Message("  Pointer Tables...");
    splitPTs(file);
    Message(" DONE.\n  Single Chunks...");    
    splitSingleChunks(file);    
    
    Message(" DONE.\n  Map Tilesets...");    
    splitMapTilesets(file);
    
    Message(" DONE.\n  Maps ...");
    splitMaps(file);    
    
    Message(" DONE.\n  TextBanks...");    
    splitTextbanks(file);
    Message(" DONE.\n");    
    
    writestr(file,"\nsplit    0x0,0x0,\\0x0 - .bin\n");
    fclose(file);
    Message("END OF SPLITS.\n");    
    
}



static initFile(file){
writestr(file,"/***********************Directories***************************/\n");
writestr(file,"#dir    data/\n");
writestr(file,"#dir    data/battles/\n");
writestr(file,"#dir    data/battles/battleexits\n");
writestr(file,"#dir    data/battles/global\n");
writestr(file,"#dir    data/battles/entries\n");
writestr(file,"#dir    data/graphics/\n");
writestr(file,"#dir    data/graphics/battles/\n");
writestr(file,"#dir    data/graphics/battles/backgrounds\n");
writestr(file,"#dir    data/graphics/battles/battlesprites/\n");
writestr(file,"#dir    data/graphics/battles/battlesprites/allies/\n");
writestr(file,"#dir    data/graphics/battles/battlesprites/allies/animations\n");
writestr(file,"#dir    data/graphics/battles/battlesprites/enemies/\n");
writestr(file,"#dir    data/graphics/battles/battlesprites/enemies/animations\n");
writestr(file,"#dir    data/graphics/battles/platforms\n");
writestr(file,"#dir    data/graphics/battles/spells\n");
writestr(file,"#dir    data/graphics/battles/spells/layouts\n");
writestr(file,"#dir    data/graphics/battles/spells/palettes\n");
writestr(file,"#dir    data/graphics/battles/weapons\n");
writestr(file,"#dir    data/graphics/battles/weapons/palettes\n");
writestr(file,"#dir    data/graphics/maps/\n");
writestr(file,"#dir    data/graphics/maps/maptilesets\n");
writestr(file,"#dir    data/graphics/maps/tileanimations\n");
writestr(file,"#dir    data/graphics/mapsprites\n");
writestr(file,"#dir    data/graphics/portraits\n");
writestr(file,"#dir    data/graphics/specialsprites\n");
writestr(file,"#dir    data/graphics/specialscreens/\n");
writestr(file,"#dir    data/graphics/specialscreens/chapterscreen\n");
writestr(file,"#dir    data/graphics/specialscreens/ending\n");
writestr(file,"#dir    data/graphics/specialscreens/intro\n");
writestr(file,"#dir    data/graphics/specialscreens/readerscreen\n");
writestr(file,"#dir    data/graphics/specialscreens/soundtest\n");
writestr(file,"#dir    data/graphics/specialscreens/titlescreen\n");
writestr(file,"#dir    data/graphics/icons\n");
writestr(file,"#dir    data/graphics/tech/\n");
writestr(file,"#dir    data/graphics/tech/menus\n");
writestr(file,"#dir    data/graphics/tech/fonts\n");
writestr(file,"#dir    data/graphics/tech/palettes\n");
writestr(file,"#dir    data/graphics/tech/windowlayouts\n");
writestr(file,"#dir    data/graphics/tech/windowlayouts/miscmessages\n");
writestr(file,"#dir    data/graphics/introtiles\n");
writestr(file,"#dir    data/maps/\n");
writestr(file,"#dir    data/maps/global\n");
writestr(file,"#dir    data/maps/entries\n");
writestr(file,"#dir    data/maps/spritesets\n");
writestr(file,"#dir    data/scripting/\n");
writestr(file,"#dir    data/scripting/cutscenes\n");
writestr(file,"#dir    data/scripting/mapspritescripts\n");
writestr(file,"#dir    data/scripting/text\n");
writestr(file,"#dir    data/sound/\n");
writestr(file,"#dir    data/stats/\n");
writestr(file,"#dir    data/stats/allies\n");
writestr(file,"#dir    data/stats/classes\n");
writestr(file,"#dir    data/stats/effects\n");
writestr(file,"#dir    data/stats/enemies\n");
writestr(file,"#dir    data/stats/items\n");
writestr(file,"#dir    data/stats/items/shops\n");
writestr(file,"#dir    data/stats/spells\n");
writestr(file,"#dir    data/stats/ranges\n");
writestr(file,"\n");
writestr(file,"/***********************Data***************************/\n");
writestr(file,"\n");
}



/*
 *    Split simple pointer tables
 */
static splitPTs(file){

    /*    Template
     *    splitPT(start, end, lastEntryDataEnd, chunkEnd, "ptName", "entryName", "binDir", "binName", indexLength, align, file);
     */
    
    //splitPT(0xC362, 0xC3A2, 0xB6F4, 0xB6F4, "pt_SpellLevelBarLayouts", "layout_SpellLevelBar", "data/graphics/", "spelllevelbarlayout", 2, 0, file);
    //splitPT(0xD39A, 0xD3BE, 0xD75A, 0xD75A, "pt_MiscMessageWindowLayouts", "layout_MiscMessageWindow", "data/graphics/tech/windowlayouts/miscmessages/", "miscmessagewindowlayout", 1, 0, file);
    
    //splitPT(0x1D3B2, 0x1D3D2, 0x1D68E, 0x1D68E, "pt_BattleExits", "table_BattleExit", "data/battles/battleexits/", "battleexit", 1, 0, file);
    splitPT(0x1DF28, 0x1DF68, 0x1E37A, 0x1E37A, "pt_IntroTiles", "tiles_Intro", "data/graphics/introtiles/", "introtile", 2, 0, file);
    
    splitPT(0x2D13E, 0x2D20E, 0x37B38, 0x38000, "pt_Portraits", "Portrait", "data/graphics/portraits/", "portrait", 2, 15, file);
    //splitPT(0x39928, 0x39BA8, 0x57F5E, 0x58000, "pt_Mapsprites", "Mapsprite", "data/graphics/mapsprites/", "mapsprite", 3, 15, file);
    
    splitPT(0x80010, 0x800E8, 0x80EE0, 0x80EE0, "pt_MapSpritesets", "table_MapSpriteset", "data/maps/spritesets/", "spriteset", 2, 0, file);
    splitPT(0x80EFE, 0x811AE, 0x820CC, 0x820CC, "pt_MapspriteScripts", "MapspriteScript", "data/scripting/mapspritescripts/", "mapspritescript", 2, 0, file);
    
    splitPT(0xB97F4, 0xB980C, 0xBA3EC, 0xBC000, "pt_MapTileAnimations", "table_MapTileAnimation", "data/maps/tileanimations/", "tileanimation", 1, 14, file);
    
    splitPT(0xC0068, 0xC0088, 0xCB8C6, 0xCC000, "pt_ChapterScreenTiles", "tiles_ChapterScreen", "data/graphics/specialscreens/chapterscreen/", "chapterscreentiles", 1, 14, file);
    splitPT(0xD398E, 0xD3AC6, 0xFFD3C, 0x100000, "pt_Backgrounds", "tiles_Background", "data/graphics/battles/backgrounds/", "background", 2, 15, file);
    
    splitPT(0x100008, 0x1000D0, 0x122252, 0x122252, "pt_EnemyBattlesprites", "EnemyBattlesprite", "data/graphics/battles/battlesprites/enemies/", "enemybattlesprite", 2, 0, file);
    splitPT(0x122252, 0x12236E, 0x122758, 0x124000, "pt_EnemyAnimations", "EnemyAnimation", "data/graphics/battles/battlesprites/enemies/animations/", "enemyanimation", 3, 14, file);
    
    splitPT(0x144014, 0x1440A0, 0x1602E2, 0x1602E2, "pt_AllyBattlesprites", "AllyBattlesprite", "data/graphics/battles/battlesprites/allies/", "allybattlesprite", 2, 0, file);
    splitPT(0x1602E2, 0x16035E, 0x16186E, 0x16186E, "pt_Weaponsprites", "Weaponsprite", "data/graphics/battles/weapons/", "weaponsprite", 2, 0, file);
    splitPT(0x161A66, 0x161B52, 0x16226A, 0x16226A, "pt_AllyAnimations", "AllyAnimation", "data/graphics/battles/battlesprites/allies/animations/", "allyanimation", 3, 0, file);
    splitPT(0x16226A, 0x162296, 0x163FFA, 0x164000, "pt_Platforms", "Platform", "data/graphics/battles/platforms/", "platform", 2, 14, file);
    
}

static splitSingleChunks(file) {
    auto i,j,x,s,index,path;
    auto start,base,addr,end,dref,section,action;
    
    // Template : splitSingleChunk(0x,0x,"","",file);
    
    //Section 01 : 0x0-0x8000
    
    //splitSingleChunk(0xB4C,0xB9C,"table_FadingData","data/graphics/tech/fadingdata.bin",file);
    splitSingleChunk(0x394C,0x39CC,"palettes_ReaderScreen","data/graphics/specialscreens/readerscreen/readerscreenpalettes.bin",file);
    //splitSingleChunk(0x39CC,0x3A44,"layout_ShiningForceLogo","data/graphics/specialscreens/readerscreen/shiningforcelogolayout.bin",file);
    //splitSingleChunk(0x49EE,0x4BEE,"layout_ChapterScreen","data/graphics/specialscreens/chapterscreen/chapterscreenlayout.bin",file);
    //splitSingleChunk(0x4BEE,0x4C0E,"layout_ChapterEnd","data/graphics/specialscreens/chapterscreen/chapterendlayout.bin",file);
    //splitSingleChunk(0x50E2,0x51D2,"table_BattleTestTargets","data/battles/global/battletesttargets.bin",file);
    //splitSingleChunk(0x530E,0x53B8,"layout_BattleTestWindow","data/graphics/tech/windowlayouts/battletest.bin",file);
    //splitSingleChunk(0x53B8,0x5462,"layout_ChapterTestWindow","data/graphics/tech/windowlayouts/chaptertest.bin",file);
    //splitSingleChunk(0x5462,0x550C,"layout_MessageTestWindow","data/graphics/tech/windowlayouts/messagetest.bin",file);
    //splitSingleChunk(0x55CC,0x560C,"layout_GoldWindow","data/graphics/tech/windowlayouts/gold.bin",file);
    splitSingleChunk(0x57EA,0x5A18,"tiles_YesNoPrompt","data/graphics/tech/menus/yesnoprompttiles.bin",file);
    //splitSingleChunk(0x69D4,0x6A2E,"byte_69D4","data/",file);
    //splitSingleChunk(0x73EE,0x740E,"word_73EE","data/",file);
    //splitSingleChunk(0x740E,0x758E,"unk_740E","data/",file);
    //splitSingleChunk(0x758E,0x7594,"unk_758E","data/",file);
    //splitSingleChunk(0x75A0,0x75E8,"layout_75A0","data/graphics/tech/windowlayouts/75a0.bin",file);
    //splitSingleChunk(0x75E8,0x76C0,"layout_EquipMenuStatsWindow","data/graphics/tech/windowlayouts/equipmenustats.bin",file);
    //splitSingleChunk(0x76C0,0x772C,"layout_EquipMenuNenberNameWindow","data/graphics/tech/windowlayouts/equipmenumembername.bin",file);
    //splitSingleChunk(0x772C,0x77A4,"layout_EquipMenuItemNameWindow","data/graphics/tech/windowlayouts/equipmenuitemname.bin",file);
    //splitSingleChunk(0x7B58,0x7C46,"layout_OptionsSpeedWindow","data/graphics/tech/windowlayouts/optionsspeed.bin",file);
    //splitSingleChunk(0x7C46,0x7D34,"layout_OptionsMessageWindow","data/graphics/tech/windowlayouts/optionsmessage.bin",file);
    //splitSingleChunk(0x7D34,0x7E22,"layout_BattlefieldQuitWindow","data/graphics/tech/windowlayouts/battlefieldquit.bin",file);
    MakeAlign(0x7E22, 0x8000-0x7E22,15);
    
    
    //Section 02 : 0x8000-0x10000
    
    //splitSingleChunk(0x87A2,0x87AA,"byte_87A2","data/",file);
    //splitSingleChunk(0x8854,0x8914,"CursorData","data/",file);
    //splitSingleChunk(0x9754,0x,"word_9754","data/graphics/tech/palettes/",file);
    splitSingleChunk(0x9A0E,0x9A4E,"palettes_Mapsprite","data/graphics/tech/palettes/mapspritepalettes.bin",file);
    //splitSingleChunk(0x9A4E,0x9A8A,"defined_byte_9A4E","data/",file);
    //splitSingleChunk(0xB982,0xBDFA,"layout_StatusMain","data/graphics/tech/windowlayouts/statusmain.bin",file);
    //splitSingleChunk(0xBDFA,0xBE3A,"layout_StatusGold","data/graphics/tech/windowlayouts/statusgold.bin",file);
    //splitSingleChunk(0xC900,0xCC90,"layout_C900","data/graphics/tech/windowlayouts/c900.bin",file);
    //splitSingleChunk(0xCC90,0xCCD8,"unk_CC90","data/",file);
    splitSingleChunk(0xCCD8,0xCED8,"tiles_IconHighlight","data/graphics/tech/iconhighlighttiles.bin",file);
    //splitSingleChunk(0xD230,0xD24E,"layout_D230","data/graphics/tech/windowlayouts/d230.bin",file);
    //splitSingleChunk(0xD24E,0xD258,"layout_D24E","data/graphics/tech/windowlayouts/d24e.bin",file);
    //splitSingleChunk(0xD258,0xD28A,"layout_D258","data/graphics/tech/windowlayouts/d258.bin",file);
    //splitSingleChunk(0xD28A,0xD32C,"word_D28A","data/",file);
    //splitSingleChunk(0xDD1C,0xDDF4,"layout_BattleEquipStats","data/graphics/tech/windowlayouts/battleequipstats.bin",file);
    //splitSingleChunk(0xDDF4,0xDEC0,"layout_BattleEquipItemName","data/graphics/tech/windowlayouts/battleequipitemname.bin",file);
    //splitSingleChunk(0xDF8C,0xDFEC,"layout_LandEffectWindow","data/graphics/tech/windowlayouts/landeffect.bin",file);
    //splitSingleChunk(0xE322,0xE3C2,"layout_PortraitWindow1","data/graphics/tech/windowlayouts/portrait1.bin",file);
    //splitSingleChunk(0xE3C2,0xE462,"layout_PortraitWindow2","data/graphics/tech/windowlayouts/portrait2.bin",file);
    //splitSingleChunk(0xE462,0xE49E,"layout_SpeakerNameWindow","data/graphics/tech/windowlayouts/speakername.bin",file);
    //splitSingleChunk(0xEBC0,0xEBE0,"unk_EBC0","data/",file);
    //splitSingleChunk(0xEE72,0xEE9A,"unk_EE72","data/",file);
    //splitSingleChunk(0xF06A,0xF0EA,"unk_F06A","data/",file);
    //splitSingleChunk(0xF0EA,0xF1CA,"unk_F0EA","data/",file);
    //splitSingleChunk(0xF1CA,0xF2D8,"layout_ShopInventoryWindow","data/graphics/tech/windowlayouts/shopinventory.bin",file);
    //splitSingleChunk(0xF2D8,0xF30E,"layout_F2D8","data/graphics/tech/windowlayouts/f2d8.bin",file);
    //splitSingleChunk(0xF30E,0xF344,"layout_F30E","data/graphics/tech/windowlayouts/f30e.bin",file);
    splitSingleChunk(0xF344,0xF364,"tiles_ShopIconHighlight","data/graphics/tech/menus/shopiconhighlighttiles.bin",file);
    //splitSingleChunk(0xF364,0xF3C8,"layout_ShopItemNameAndPriceWindow","data/graphics/tech/windowlayouts/shopitemnameandprice.bin",file);
    //splitSingleChunk(0xF3C8,0xF410,"layout_F3C8","data/graphics/tech/windowlayouts/f3c8.bin",file);
    //splitSingleChunk(0xF410,0xF43A,"layout_MembersListWindow1","data/graphics/tech/windowlayouts/memberslist1.bin",file);
    //splitSingleChunk(0xF43A,0xF464,"layout_MembersListWindow2","data/graphics/tech/windowlayouts/memberslist2.bin",file);
    //splitSingleChunk(0xF464,0xF48E,"layout_MembersListWindow3","data/graphics/tech/windowlayouts/memberslist3.bin",file);
    //splitSingleChunk(0xF48E,0xF4DE,"layout_ItemMenuItemNameWindow","data/graphics/tech/windowlayouts/itemmenuitemname.bin",file);
    //splitSingleChunk(0xF4DE,0xF61E,"unk_F4DE","data/",file);
    MakeAlign(0xFD58, 0x10000-0xFD58,15);
    
    
    //Section 03 : 0x10000-0x20000
    
    //splitSingleChunk(0x11B14,0x11B4A,"MapDialogs","data/maps/global/mapdialogs.bin",file);
    //splitSingleChunk(0x11EE0,0x11F00,"byte_11EE0","data/graphics/tech/palettes/",file);
    //splitSingleChunk(0x12D8A,0x131A4,"table_MapTeleports","data/maps/global/mapteleports.bin",file);
    
    /*
    splitSingleChunk(0x16F92,0x16F99,"ShopInventory00","data/stats/items/shops/shopinventory00.bin",file);
    splitSingleChunk(0x16F99,0x16F9E,"ShopInventory01","data/stats/items/shops/shopinventory01.bin",file);
    splitSingleChunk(0x16F9E,0x16FA5,"ShopInventory02","data/stats/items/shops/shopinventory02.bin",file);
    splitSingleChunk(0x16FA5,0x16FAA,"ShopInventory03","data/stats/items/shops/shopinventory03.bin",file);
    splitSingleChunk(0x16FAA,0x16FB2,"ShopInventory04","data/stats/items/shops/shopinventory04.bin",file);
    splitSingleChunk(0x16FB2,0x16FB8,"ShopInventory05","data/stats/items/shops/shopinventory05.bin",file);
    splitSingleChunk(0x16FB8,0x16FBA,"ShopInventory06","data/stats/items/shops/shopinventory06.bin",file);
    splitSingleChunk(0x16FBA,0x16FBC,"ShopInventory07","data/stats/items/shops/shopinventory07.bin",file);
    splitSingleChunk(0x16FBC,0x16FC4,"ShopInventory08","data/stats/items/shops/shopinventory08.bin",file);
    splitSingleChunk(0x16FC4,0x16FCA,"ShopInventory09","data/stats/items/shops/shopinventory09.bin",file);
    splitSingleChunk(0x16FCA,0x16FD2,"ShopInventory10","data/stats/items/shops/shopinventory10.bin",file);
    splitSingleChunk(0x16FD2,0x16FD8,"ShopInventory11","data/stats/items/shops/shopinventory11.bin",file);
    splitSingleChunk(0x16FD8,0x16FE0,"ShopInventory12","data/stats/items/shops/shopinventory12.bin",file);
    splitSingleChunk(0x16FE0,0x16FE6,"ShopInventory13","data/stats/items/shops/shopinventory13.bin",file);
    splitSingleChunk(0x16FE6,0x16FEE,"ShopInventory14","data/stats/items/shops/shopinventory14.bin",file);
    splitSingleChunk(0x16FEE,0x16FF4,"ShopInventory15","data/stats/items/shops/shopinventory15.bin",file);
    splitSingleChunk(0x16FF4,0x16FFB,"ShopInventory16","data/stats/items/shops/shopinventory16.bin",file);
    splitSingleChunk(0x16FFB,0x17001,"ShopInventory17","data/stats/items/shops/shopinventory17.bin",file);
    splitSingleChunk(0x17001,0x17008,"ShopInventory18","data/stats/items/shops/shopinventory18.bin",file);
    splitSingleChunk(0x17008,0x1700E,"ShopInventory19","data/stats/items/shops/shopinventory19.bin",file);
    splitSingleChunk(0x1700E,0x17015,"ShopInventory20","data/stats/items/shops/shopinventory20.bin",file);
    splitSingleChunk(0x17015,0x1701B,"ShopInventory21","data/stats/items/shops/shopinventory21.bin",file);
    splitSingleChunk(0x1701B,0x17022,"ShopInventory22","data/stats/items/shops/shopinventory22.bin",file);
    splitSingleChunk(0x17022,0x17028,"ShopInventory23","data/stats/items/shops/shopinventory23.bin",file);
    */
    
    //splitSingleChunk(0x17BBC,0x17C5E,"table_MapspriteSpeechSfx","data/scripting/mapspritespeechsfx.bin",file);
    //splitSingleChunk(0x17D62,0x17E34,"DialogHeader","data/scripting/dialogheader.bin",file);
    //splitSingleChunk(0x1D68E,0x1DA8E,"table_BattleChests","data/battles/global/battlechests.bin",file);
    //splitSingleChunk(0x1E37A,0x1E67A,"byte_1E37A","data/",file);
    //splitSingleChunk(0x1E67A,0x1E712,"byte_1E67A","data/",file);
    //splitSingleChunk(0x1E712,0x1E892,"byte_1E712","data/",file);
    splitSingleChunk(0x1E892,0x1EA3A,"TextBankTreesPointers","data/scripting/text/huffmantreeoffsets.bin",file);
    splitSingleChunk(0x1EA3A,0x1EFE0,"TextBankTreeData","data/scripting/text/huffmantrees.bin",file);
    MakeAlign(0x1F068, 0x20000-0x1F068,15);
    

    //Section 04 : 0x20000-0x2C000
    
    //splitSingleChunk(0x206DC,0x207BC,"byte_206DC","data/",file);
    //splitSingleChunk(0x207CA,0x20802,"table_LaserEyeTargetGrid","data/stats/ranges/lasereyetargetgrid.bin",file);
    
    //splitSingleChunk(0x20A04,0x20BDC,"EffectData","data/stats/effects/effectdata.bin",file);
    splitChunksWithGapInBetween(0x20A04,0x20BDC,6,2,"table_EffectData","data/stats/effects/","effect",2,file);
    
    //splitSingleChunk(0x20E8C,0x20E96,"ExperienceTable","data/stats/allies/experiencetable.bin",file);
    //splitSingleChunk(0x20F7C,0x20F82,"ElemAttackCritPercents","data/stats/effects/elemattackcritpercents.bin",file);
    //splitSingleChunk(0x2100C,0x21034,"table_StatusEffectBattleMessages","data/stats/effects/statuseffectbattlemessages.bin",file);
    //splitSingleChunk(0x211E2,0x211E6,"ResistancePercents","data/stats/spells/resistancepercents.bin",file);
    //splitSingleChunk(0x21266,0x2126A,"EvasionPercents","data/stats/evasionpercents.bin",file);
    //splitSingleChunk(0x212A2,0x212A6,"UnableToEvadeClasses","data/",file);
    //splitSingleChunk(0x2303A,0x23040,"ItemDrops","data/stats/items/itemdrops.bin",file);
    //splitSingleChunk(0x230EC,0x230EF,"unk_230EC","data/",file);
    //splitSingleChunk(0x230EF,0x230F2,"unk_230EF","data/",file);
    //splitSingleChunk(0x2315C,0x23160,"byte_2315C","data/",file);
    
    //splitSingleChunk(0x23178,0x23378,"RangeData","data/stats/ranges/rangedata.bin",file);
    splitChunksWithGapInBetween(0x23178,0x23378,4,4,"table_RangeData","data/stats/ranges/","range",2,file);
    
    //splitSingleChunk(0x2361A,0x2361E,"SpecialAttackPercents","data/stats/effects/specialattackpercents.bin",file);
    //splitSingleChunk(0x23A1E,0x23A3E,"PromotedPortraits","data/stats/allies/promotedportraits.bin",file);
    //splitSingleChunk(0x23ACE,0x23AD6,"OutfitItems","data/stats/items/outfititems.bin",file);
    //splitSingleChunk(0x24002,0x24006,"byte_24002","data/",file);
    //splitSingleChunk(0x24006,0x2401C,"unk_24006","data/",file);
    //splitSingleChunk(0x2409C,0x240BC,"unk_2409C","data/",file);
    //splitSingleChunk(0x240DC,0x240E8,"unk_240DC","data/",file);
    //splitSingleChunk(0x243AA,0x244CA,"AITargetPriority","data/stats/classes/aitargetpriority.bin",file);
    //splitSingleChunk(0x24A38,0x24A44,"word_24A38","data/",file);
    //splitSingleChunk(0x24C98,0x24CA4,"byte_24C98","data/",file);
    //splitSingleChunk(0x24D70,0x24D74,"EndStatusPercents","data/stats/effects/endstatuspercents.bin",file);
    splitSingleChunk(0x25154,0x25604,"table_InitialForceData","data/stats/allies/initialforcedata.bin",file);
    splitSingleChunk(0x25604,0x25640,"table_BattleSpriteData","data/stats/allies/battlespritedata.bin",file);
    splitSingleChunk(0x25640,0x25916,"table_ItemNames","data/stats/items/itemnames.bin",file);
    splitSingleChunk(0x25916,0x25D06,"table_ItemData","data/stats/items/itemdata.bin",file);
    splitSingleChunk(0x25D06,0x25D2C,"table_WeaponSpriteData","data/stats/items/weaponspritedata.bin",file);
    splitSingleChunk(0x25D2C,0x25D6C,"table_ItemTypes","data/stats/items/itemtypes.bin",file);
    splitSingleChunk(0x25D6C,0x260BC,"table_ClassNames","data/stats/classes/classnames.bin",file);
    splitSingleChunk(0x260BC,0x26404,"table_ClassData","data/stats/classes/classdata.bin",file);
    splitSingleChunk(0x26404,0x26466,"table_SpellNames","data/stats/spells/spellnames.bin",file);
    splitSingleChunk(0x26466,0x26566,"table_SpellData","data/stats/spells/spelldata.bin",file);
    splitSingleChunk(0x26566,0x265E6,"table_MoveCostData","data/battles/global/movecostdata.bin",file);
    splitSingleChunk(0x265E6,0x26666,"table_LandEffectData","data/battles/global/landeffectdata.bin",file);
    splitSingleChunk(0x26666,0x2688E,"table_ForceAnimationData","data/stats/allies/forceanimationdata.bin",file);
    splitSingleChunk(0x2688E,0x269FE,"table_EnemyAnimationData","data/stats/enemies/enemyanimationdata.bin",file);
    splitSingleChunk(0x269FE,0x26BF2,"table_TerrainData","data/battles/global/terraindata.bin",file);
    splitSingleChunk(0x26BF6,0x26C1A,"table_GrowthCurves","data/stats/allies/growthcurves.bin",file);
    splitSingleChunk(0x26C1A,0x26CCE,"table_UnpromotedGrowths","data/stats/allies/unpromotedgrowths.bin",file);
    splitSingleChunk(0x26CCE,0x26D70,"table_PromotedGrowths","data/stats/allies/promotedgrowths.bin",file);
    splitSingleChunk(0x26D70,0x26E16,"table_SpellLearningData","data/stats/allies/spelllearningdata.bin",file);
    splitSingleChunk(0x26EE4,0x26F0A,"table_EndingCreditsForceData","data/stats/allies/endingcreditsforcedata.bin",file);
    splitSingleChunk(0x26F0A,0x26F46,"table_EndingAnimationSequence","data/stats/allies/endinganimationsequence.bin",file);
    splitSingleChunk(0x26F0A,0x26F46,"table_EndingAnimationSequence","data/stats/allies/endinganimationsequence.bin",file);
    
    splitSingleChunk(0x2704E,0x2751A,"rpt_MapHeaders","data/maps/global/mapheaders.bin",file);
    splitSingleChunk(0x2751C,0x279AC,"table_EnemyDefs","data/stats/enemies/enemydefs.bin",file);
    splitSingleChunk(0x279AC,0x29EA4,"table_BattleTerrain","data/battles/global/battleterrain.bin",file);
    splitSingleChunk(0x29EA4,0x2BF84,"table_BattleData","data/battles/global/battledata.bin",file);
    
    MakeAlign(0x2BF85, 0x2C000-0x2BF84,14);
    
    
    //Section 05 : 0x2C000-0x38000
    
    splitSingleChunk(0x2C13E,0x2D13E,"font_VariableWidth","data/graphics/tech/fonts/variablewidthfont.bin",file);
    
    
    //Section 06 : 0x380000-0x58000
    
    //splitSingleChunk(0x38040,0x383A0,"byte_38040","data/graphics/",file);
    //splitSingleChunk(0x383A0,0x38700,"byte_383A0","data/graphics/",file);
    //splitSingleChunk(0x38700,0x38800,"byte_38700","data/graphics/",file);
    //splitSingleChunk(0x38800,0x38900,"byte_38800","data/graphics/",file);
    //splitSingleChunk(0x38900,0x38940,"byte_38900","data/graphics/",file);
    //splitSingleChunk(0x38940,0x38980,"byte_38940","data/graphics/",file);
    //splitSingleChunk(0x38980,0x38A60,"byte_38980","data/graphics/",file);
    //splitSingleChunk(0x38A60,0x38B40,"byte_38A60","data/graphics/",file);
    //splitSingleChunk(0x38B40,0x38CA0,"byte_38B40","data/graphics/",file);
    //splitSingleChunk(0x38CA0,0x38E00,"byte_38CA0","data/graphics/",file);
    //splitSingleChunk(0x38E00,0x39260,"byte_38E00","data/graphics/",file);
    //splitSingleChunk(0x39260,0x396C0,"byte_39260","data/graphics/",file);
    splitSingleChunk(0x396C0,0x39928,"SpecialSprite_Jogurt1","data/graphics/specialsprites/specialsprite-jogurt1.bin",file);
    splitSingleChunk(0x3A0A8,0x3A19E,"Mapsprite000","data/graphics/mapsprites/mapsprite000.bin",file);
    splitSingleChunk(0x3A37E,0x3A47E,"Mapsprite001","data/graphics/mapsprites/mapsprite001.bin",file);
    splitSingleChunk(0x3A676,0x3A782,"Mapsprite002","data/graphics/mapsprites/mapsprite002.bin",file);
    splitSingleChunk(0x3A986,0x3AA8E,"Mapsprite003","data/graphics/mapsprites/mapsprite003.bin",file);
    splitSingleChunk(0x3ACA0,0x3ADAE,"Mapsprite004","data/graphics/mapsprites/mapsprite004.bin",file);
    splitSingleChunk(0x3AFCC,0x3B0DA,"Mapsprite005","data/graphics/mapsprites/mapsprite005.bin",file);
    splitSingleChunk(0x3B2D6,0x3B3DC,"Mapsprite006","data/graphics/mapsprites/mapsprite006.bin",file);
    splitSingleChunk(0x3B5C4,0x3B6D4,"Mapsprite007","data/graphics/mapsprites/mapsprite007.bin",file);
    splitSingleChunk(0x3B8AE,0x3B9D8,"Mapsprite008","data/graphics/mapsprites/mapsprite008.bin",file);
    splitSingleChunk(0x3BBE2,0x3BD10,"Mapsprite009","data/graphics/mapsprites/mapsprite009.bin",file);
    splitSingleChunk(0x3BF5A,0x3C05E,"Mapsprite010","data/graphics/mapsprites/mapsprite010.bin",file);
    splitSingleChunk(0x3C22C,0x3C33C,"Mapsprite011","data/graphics/mapsprites/mapsprite011.bin",file);
    splitSingleChunk(0x3C522,0x3C64A,"Mapsprite012","data/graphics/mapsprites/mapsprite012.bin",file);
    splitSingleChunk(0x3C85C,0x3C93A,"Mapsprite013","data/graphics/mapsprites/mapsprite013.bin",file);
    splitSingleChunk(0x3CAD2,0x3CBE8,"Mapsprite014","data/graphics/mapsprites/mapsprite014.bin",file);
    splitSingleChunk(0x3CDB4,0x3CEDE,"Mapsprite015","data/graphics/mapsprites/mapsprite015.bin",file);
    splitSingleChunk(0x3D0D6,0x3D226,"Mapsprite016","data/graphics/mapsprites/mapsprite016.bin",file);
    splitSingleChunk(0x3D48E,0x3D5A4,"Mapsprite017","data/graphics/mapsprites/mapsprite017.bin",file);
    splitSingleChunk(0x3D7A4,0x3D8C2,"Mapsprite018","data/graphics/mapsprites/mapsprite018.bin",file);
    splitSingleChunk(0x3DACC,0x3DBDE,"Mapsprite019","data/graphics/mapsprites/mapsprite019.bin",file);
    splitSingleChunk(0x3DDEA,0x3DF1C,"Mapsprite020","data/graphics/mapsprites/mapsprite020.bin",file);
    splitSingleChunk(0x3E198,0x3E2D6,"Mapsprite021","data/graphics/mapsprites/mapsprite021.bin",file);
    splitSingleChunk(0x3E518,0x3E660,"Mapsprite022","data/graphics/mapsprites/mapsprite022.bin",file);
    splitSingleChunk(0x3E8C4,0x3EA0A,"Mapsprite023","data/graphics/mapsprites/mapsprite023.bin",file);
    splitSingleChunk(0x3EC5E,0x3EDA6,"Mapsprite024","data/graphics/mapsprites/mapsprite024.bin",file);
    splitSingleChunk(0x3EFF4,0x3F13A,"Mapsprite025","data/graphics/mapsprites/mapsprite025.bin",file);
    splitSingleChunk(0x3F336,0x3F486,"Mapsprite026","data/graphics/mapsprites/mapsprite026.bin",file);
    splitSingleChunk(0x3F6A6,0x3F7F8,"Mapsprite027","data/graphics/mapsprites/mapsprite027.bin",file);
    splitSingleChunk(0x3FA1A,0x3FAFC,"Mapsprite028","data/graphics/mapsprites/mapsprite028.bin",file);
    splitSingleChunk(0x3FCEC,0x3FDFC,"Mapsprite029","data/graphics/mapsprites/mapsprite029.bin",file);
    splitSingleChunk(0x3FFD4,0x400F8,"Mapsprite030","data/graphics/mapsprites/mapsprite030.bin",file);
    splitSingleChunk(0x4029E,0x403B2,"Mapsprite031","data/graphics/mapsprites/mapsprite031.bin",file);
    splitSingleChunk(0x405CA,0x406EA,"Mapsprite032","data/graphics/mapsprites/mapsprite032.bin",file);
    splitSingleChunk(0x40904,0x40A1C,"Mapsprite033","data/graphics/mapsprites/mapsprite033.bin",file);
    splitSingleChunk(0x40C3E,0x40D5E,"Mapsprite034","data/graphics/mapsprites/mapsprite034.bin",file);
    splitSingleChunk(0x40F8C,0x410A8,"Mapsprite035","data/graphics/mapsprites/mapsprite035.bin",file);
    splitSingleChunk(0x412CA,0x413EE,"Mapsprite036","data/graphics/mapsprites/mapsprite036.bin",file);
    splitSingleChunk(0x4162E,0x41786,"Mapsprite037","data/graphics/mapsprites/mapsprite037.bin",file);
    splitSingleChunk(0x41A06,0x41B5C,"Mapsprite038","data/graphics/mapsprites/mapsprite038.bin",file);
    splitSingleChunk(0x41DB0,0x41F0E,"Mapsprite039","data/graphics/mapsprites/mapsprite039.bin",file);
    splitSingleChunk(0x42186,0x422B0,"Mapsprite040","data/graphics/mapsprites/mapsprite040.bin",file);
    splitSingleChunk(0x42488,0x425C2,"Mapsprite041","data/graphics/mapsprites/mapsprite041.bin",file);
    splitSingleChunk(0x427DC,0x4291C,"Mapsprite042","data/graphics/mapsprites/mapsprite042.bin",file);
    splitSingleChunk(0x42B0A,0x42B96,"Mapsprite043","data/graphics/mapsprites/mapsprite043.bin",file);
    splitSingleChunk(0x42B96,0x42CAA,"Mapsprite044","data/graphics/mapsprites/mapsprite044.bin",file);
    splitSingleChunk(0x42E98,0x42FCC,"Mapsprite045","data/graphics/mapsprites/mapsprite045.bin",file);
    splitSingleChunk(0x431F6,0x43322,"Mapsprite046","data/graphics/mapsprites/mapsprite046.bin",file);
    splitSingleChunk(0x43514,0x4362C,"Mapsprite047","data/graphics/mapsprites/mapsprite047.bin",file);
    splitSingleChunk(0x437D2,0x43938,"Mapsprite048","data/graphics/mapsprites/mapsprite048.bin",file);
    splitSingleChunk(0x43BB0,0x43D26,"Mapsprite049","data/graphics/mapsprites/mapsprite049.bin",file);
    splitSingleChunk(0x43F9C,0x440BA,"Mapsprite050","data/graphics/mapsprites/mapsprite050.bin",file);
    splitSingleChunk(0x442EC,0x44428,"Mapsprite051","data/graphics/mapsprites/mapsprite051.bin",file);
    splitSingleChunk(0x4466A,0x447B4,"Mapsprite052","data/graphics/mapsprites/mapsprite052.bin",file);
    splitSingleChunk(0x44A18,0x44B92,"Mapsprite053","data/graphics/mapsprites/mapsprite053.bin",file);
    splitSingleChunk(0x44E2C,0x44FA8,"Mapsprite054","data/graphics/mapsprites/mapsprite054.bin",file);
    splitSingleChunk(0x4522E,0x4536A,"Mapsprite055","data/graphics/mapsprites/mapsprite055.bin",file);
    splitSingleChunk(0x4556C,0x456EA,"Mapsprite056","data/graphics/mapsprites/mapsprite056.bin",file);
    splitSingleChunk(0x45902,0x45A34,"Mapsprite057","data/graphics/mapsprites/mapsprite057.bin",file);
    splitSingleChunk(0x45C34,0x45D0C,"Mapsprite058","data/graphics/mapsprites/mapsprite058.bin",file);
    splitSingleChunk(0x45E7C,0x45F7E,"Mapsprite059","data/graphics/mapsprites/mapsprite059.bin",file);
    splitSingleChunk(0x46152,0x462E6,"Mapsprite060","data/graphics/mapsprites/mapsprite060.bin",file);
    splitSingleChunk(0x46546,0x4666E,"Mapsprite061","data/graphics/mapsprites/mapsprite061.bin",file);
    splitSingleChunk(0x468E4,0x469D0,"Mapsprite062","data/graphics/mapsprites/mapsprite062.bin",file);
    splitSingleChunk(0x46BE2,0x46CCE,"Mapsprite063","data/graphics/mapsprites/mapsprite063.bin",file);
    splitSingleChunk(0x46ED8,0x4707E,"Mapsprite064","data/graphics/mapsprites/mapsprite064.bin",file);
    splitSingleChunk(0x4733E,0x47490,"Mapsprite065","data/graphics/mapsprites/mapsprite065.bin",file);
    splitSingleChunk(0x476BC,0x477D8,"Mapsprite066","data/graphics/mapsprites/mapsprite066.bin",file);
    splitSingleChunk(0x47A56,0x47C08,"Mapsprite067","data/graphics/mapsprites/mapsprite067.bin",file);
    splitSingleChunk(0x47F0C,0x480B8,"Mapsprite068","data/graphics/mapsprites/mapsprite068.bin",file);
    splitSingleChunk(0x483B6,0x48506,"Mapsprite069","data/graphics/mapsprites/mapsprite069.bin",file);
    splitSingleChunk(0x48748,0x48786,"Mapsprite070","data/graphics/mapsprites/mapsprite070.bin",file);
    splitSingleChunk(0x48786,0x488D8,"Mapsprite071","data/graphics/mapsprites/mapsprite071.bin",file);
    splitSingleChunk(0x48AD4,0x48C28,"Mapsprite072","data/graphics/mapsprites/mapsprite072.bin",file);
    splitSingleChunk(0x48E58,0x48F22,"Mapsprite073","data/graphics/mapsprites/mapsprite073.bin",file);
    splitSingleChunk(0x490C8,0x49192,"Mapsprite074","data/graphics/mapsprites/mapsprite074.bin",file);
    splitSingleChunk(0x4933A,0x494AA,"Mapsprite075","data/graphics/mapsprites/mapsprite075.bin",file);
    splitSingleChunk(0x496F6,0x4986A,"Mapsprite076","data/graphics/mapsprites/mapsprite076.bin",file);
    splitSingleChunk(0x49ACC,0x49C2E,"Mapsprite077","data/graphics/mapsprites/mapsprite077.bin",file);
    splitSingleChunk(0x49E54,0x49F8C,"Mapsprite078","data/graphics/mapsprites/mapsprite078.bin",file);
    splitSingleChunk(0x4A182,0x4A2E0,"Mapsprite079","data/graphics/mapsprites/mapsprite079.bin",file);
    splitSingleChunk(0x4A55C,0x4A6D0,"Mapsprite080","data/graphics/mapsprites/mapsprite080.bin",file);
    splitSingleChunk(0x4A950,0x4AA90,"Mapsprite081","data/graphics/mapsprites/mapsprite081.bin",file);
    splitSingleChunk(0x4AC72,0x4ADBE,"Mapsprite082","data/graphics/mapsprites/mapsprite082.bin",file);
    splitSingleChunk(0x4AFC4,0x4B100,"Mapsprite083","data/graphics/mapsprites/mapsprite083.bin",file);
    splitSingleChunk(0x4B2DE,0x4B40C,"Mapsprite084","data/graphics/mapsprites/mapsprite084.bin",file);
    splitSingleChunk(0x4B636,0x4B75C,"Mapsprite085","data/graphics/mapsprites/mapsprite085.bin",file);
    splitSingleChunk(0x4B95E,0x4BA6C,"Mapsprite086","data/graphics/mapsprites/mapsprite086.bin",file);
    splitSingleChunk(0x4BCB4,0x4BDC0,"Mapsprite087","data/graphics/mapsprites/mapsprite087.bin",file);
    splitSingleChunk(0x4BFF6,0x4C1AE,"Mapsprite088","data/graphics/mapsprites/mapsprite088.bin",file);
    splitSingleChunk(0x4C46A,0x4C580,"Mapsprite089","data/graphics/mapsprites/mapsprite089.bin",file);
    splitSingleChunk(0x4C93A,0x4CA98,"Mapsprite090","data/graphics/mapsprites/mapsprite090.bin",file);
    splitSingleChunk(0x4C580,0x4C6DE,"Mapsprite091","data/graphics/mapsprites/mapsprite091.bin",file);
    splitSingleChunk(0x4CCF4,0x4CE4C,"Mapsprite092","data/graphics/mapsprites/mapsprite092.bin",file);
    splitSingleChunk(0x4D082,0x4D178,"Mapsprite093","data/graphics/mapsprites/mapsprite093.bin",file);
    splitSingleChunk(0x4D178,0x4D2E8,"Mapsprite094","data/graphics/mapsprites/mapsprite094.bin",file);
    splitSingleChunk(0x4D524,0x4D678,"Mapsprite095","data/graphics/mapsprites/mapsprite095.bin",file);
    splitSingleChunk(0x4D8C8,0x4DA82,"Mapsprite096","data/graphics/mapsprites/mapsprite096.bin",file);
    splitSingleChunk(0x4DD3C,0x4DE8E,"Mapsprite097","data/graphics/mapsprites/mapsprite097.bin",file);
    splitSingleChunk(0x4E0E6,0x4E12A,"Mapsprite098","data/graphics/mapsprites/mapsprite098.bin",file);
    splitSingleChunk(0x4E1A2,0x4E31C,"Mapsprite099","data/graphics/mapsprites/mapsprite099.bin",file);
    splitSingleChunk(0x4E600,0x4E75E,"Mapsprite100","data/graphics/mapsprites/mapsprite100.bin",file);
    splitSingleChunk(0x4E99E,0x4EB26,"Mapsprite101","data/graphics/mapsprites/mapsprite101.bin",file);
    splitSingleChunk(0x4EDEE,0x4EF28,"Mapsprite102","data/graphics/mapsprites/mapsprite102.bin",file);
    splitSingleChunk(0x4F180,0x4F2B6,"Mapsprite103","data/graphics/mapsprites/mapsprite103.bin",file);
    splitSingleChunk(0x4F4D8,0x4F5F0,"Mapsprite104","data/graphics/mapsprites/mapsprite104.bin",file);
    splitSingleChunk(0x4F85A,0x4F95C,"Mapsprite105","data/graphics/mapsprites/mapsprite105.bin",file);
    splitSingleChunk(0x4FB20,0x4FC10,"Mapsprite106","data/graphics/mapsprites/mapsprite106.bin",file);
    splitSingleChunk(0x4FDDE,0x4FF06,"Mapsprite107","data/graphics/mapsprites/mapsprite107.bin",file);
    splitSingleChunk(0x50134,0x502AE,"Mapsprite108","data/graphics/mapsprites/mapsprite108.bin",file);
    splitSingleChunk(0x504DC,0x50630,"Mapsprite109","data/graphics/mapsprites/mapsprite109.bin",file);
    splitSingleChunk(0x50630,0x507B4,"Mapsprite110","data/graphics/mapsprites/mapsprite110.bin",file);
    splitSingleChunk(0x50A5E,0x50BCE,"Mapsprite111","data/graphics/mapsprites/mapsprite111.bin",file);
    splitSingleChunk(0x50E02,0x50EF6,"Mapsprite112","data/graphics/mapsprites/mapsprite112.bin",file);
    splitSingleChunk(0x510A6,0x511F2,"Mapsprite113","data/graphics/mapsprites/mapsprite113.bin",file);
    splitSingleChunk(0x513E2,0x51524,"Mapsprite114","data/graphics/mapsprites/mapsprite114.bin",file);
    splitSingleChunk(0x5172C,0x5189E,"Mapsprite115","data/graphics/mapsprites/mapsprite115.bin",file);
    splitSingleChunk(0x51AAA,0x51C28,"Mapsprite116","data/graphics/mapsprites/mapsprite116.bin",file);
    splitSingleChunk(0x51F0C,0x51F56,"Mapsprite117","data/graphics/mapsprites/mapsprite117.bin",file);
    splitSingleChunk(0x51F56,0x5206C,"Mapsprite118","data/graphics/mapsprites/mapsprite118.bin",file);
    splitSingleChunk(0x52290,0x52384,"Mapsprite119","data/graphics/mapsprites/mapsprite119.bin",file);
    splitSingleChunk(0x52384,0x5247A,"Mapsprite120","data/graphics/mapsprites/mapsprite120.bin",file);
    splitSingleChunk(0x525FE,0x5275E,"Mapsprite121","data/graphics/mapsprites/mapsprite121.bin",file);
    splitSingleChunk(0x529C4,0x52AD2,"Mapsprite122","data/graphics/mapsprites/mapsprite122.bin",file);
    splitSingleChunk(0x52CB0,0x52DAA,"Mapsprite123","data/graphics/mapsprites/mapsprite123.bin",file);
    splitSingleChunk(0x52F46,0x53038,"Mapsprite124","data/graphics/mapsprites/mapsprite124.bin",file);
    splitSingleChunk(0x531EE,0x532EC,"Mapsprite125","data/graphics/mapsprites/mapsprite125.bin",file);
    splitSingleChunk(0x534BA,0x5359A,"Mapsprite126","data/graphics/mapsprites/mapsprite126.bin",file);
    splitSingleChunk(0x5372C,0x53832,"Mapsprite127","data/graphics/mapsprites/mapsprite127.bin",file);
    splitSingleChunk(0x53A04,0x53B12,"Mapsprite128","data/graphics/mapsprites/mapsprite128.bin",file);
    splitSingleChunk(0x53CBA,0x53DB6,"Mapsprite129","data/graphics/mapsprites/mapsprite129.bin",file);
    splitSingleChunk(0x53F7C,0x54082,"Mapsprite130","data/graphics/mapsprites/mapsprite130.bin",file);
    splitSingleChunk(0x54242,0x542F4,"Mapsprite131","data/graphics/mapsprites/mapsprite131.bin",file);
    splitSingleChunk(0x5441C,0x544FA,"Mapsprite132","data/graphics/mapsprites/mapsprite132.bin",file);
    splitSingleChunk(0x54680,0x54716,"Mapsprite133","data/graphics/mapsprites/mapsprite133.bin",file);
    splitSingleChunk(0x54876,0x548DA,"Mapsprite134","data/graphics/mapsprites/mapsprite134.bin",file);
    splitSingleChunk(0x549B0,0x54A1E,"Mapsprite135","data/graphics/mapsprites/mapsprite135.bin",file);
    splitSingleChunk(0x54B08,0x54BE6,"Mapsprite136","data/graphics/mapsprites/mapsprite136.bin",file);
    splitSingleChunk(0x54D6E,0x54E94,"Mapsprite137","data/graphics/mapsprites/mapsprite137.bin",file);
    splitSingleChunk(0x55074,0x55154,"Mapsprite138","data/graphics/mapsprites/mapsprite138.bin",file);
    splitSingleChunk(0x552E0,0x5541A,"Mapsprite139","data/graphics/mapsprites/mapsprite139.bin",file);
    splitSingleChunk(0x55636,0x55756,"Mapsprite140","data/graphics/mapsprites/mapsprite140.bin",file);
    splitSingleChunk(0x55904,0x559D2,"Mapsprite141","data/graphics/mapsprites/mapsprite141.bin",file);
    splitSingleChunk(0x55B44,0x55CA4,"Mapsprite142","data/graphics/mapsprites/mapsprite142.bin",file);
    splitSingleChunk(0x55E96,0x55FE2,"Mapsprite143","data/graphics/mapsprites/mapsprite143.bin",file);
    splitSingleChunk(0x56202,0x562FC,"Mapsprite144","data/graphics/mapsprites/mapsprite144.bin",file);
    splitSingleChunk(0x564CA,0x565D6,"Mapsprite145","data/graphics/mapsprites/mapsprite145.bin",file);
    splitSingleChunk(0x5679E,0x5682C,"Mapsprite146","data/graphics/mapsprites/mapsprite146.bin",file);
    splitSingleChunk(0x5695C,0x56AEA,"Mapsprite147","data/graphics/mapsprites/mapsprite147.bin",file);
    splitSingleChunk(0x56D7E,0x56E94,"Mapsprite148","data/graphics/mapsprites/mapsprite148.bin",file);
    splitSingleChunk(0x5706C,0x57110,"Mapsprite149","data/graphics/mapsprites/mapsprite149.bin",file);
    splitSingleChunk(0x5725E,0x573A2,"Mapsprite150","data/graphics/mapsprites/mapsprite150.bin",file);
    splitSingleChunk(0x575F8,0x576E0,"Mapsprite151","data/graphics/mapsprites/mapsprite151.bin",file);
    splitSingleChunk(0x5786C,0x57974,"Mapsprite152","data/graphics/mapsprites/mapsprite152.bin",file);
    splitSingleChunk(0x57B06,0x57B62,"Mapsprite153","data/graphics/mapsprites/mapsprite153.bin",file);
    splitSingleChunk(0x57C46,0x57D20,"Mapsprite154","data/graphics/mapsprites/mapsprite154.bin",file);
    splitSingleChunk(0x57D20,0x57DF4,"Mapsprite155","data/graphics/mapsprites/mapsprite155.bin",file);
    splitSingleChunk(0x3A19E,0x3A29E,"Mapsprite156","data/graphics/mapsprites/mapsprite156.bin",file);
    splitSingleChunk(0x3A47E,0x3A58C,"Mapsprite157","data/graphics/mapsprites/mapsprite157.bin",file);
    splitSingleChunk(0x3A782,0x3A894,"Mapsprite158","data/graphics/mapsprites/mapsprite158.bin",file);
    splitSingleChunk(0x3AA8E,0x3ABA4,"Mapsprite159","data/graphics/mapsprites/mapsprite159.bin",file);
    splitSingleChunk(0x3ADAE,0x3AECC,"Mapsprite160","data/graphics/mapsprites/mapsprite160.bin",file);
    splitSingleChunk(0x3B0DA,0x3B1E8,"Mapsprite161","data/graphics/mapsprites/mapsprite161.bin",file);
    splitSingleChunk(0x3B3DC,0x3B4E0,"Mapsprite162","data/graphics/mapsprites/mapsprite162.bin",file);
    splitSingleChunk(0x3B6D4,0x3B7AC,"Mapsprite163","data/graphics/mapsprites/mapsprite163.bin",file);
    splitSingleChunk(0x3B9D8,0x3BAE0,"Mapsprite164","data/graphics/mapsprites/mapsprite164.bin",file);
    splitSingleChunk(0x3BD10,0x3BE2E,"Mapsprite165","data/graphics/mapsprites/mapsprite165.bin",file);
    splitSingleChunk(0x3C05E,0x3C152,"Mapsprite166","data/graphics/mapsprites/mapsprite166.bin",file);
    splitSingleChunk(0x3C33C,0x3C432,"Mapsprite167","data/graphics/mapsprites/mapsprite167.bin",file);
    splitSingleChunk(0x3C64A,0x3C76A,"Mapsprite168","data/graphics/mapsprites/mapsprite168.bin",file);
    splitSingleChunk(0x3C93A,0x3CA14,"Mapsprite169","data/graphics/mapsprites/mapsprite169.bin",file);
    splitSingleChunk(0x3CBE8,0x3CCC6,"Mapsprite170","data/graphics/mapsprites/mapsprite170.bin",file);
    splitSingleChunk(0x3CEDE,0x3CFE6,"Mapsprite171","data/graphics/mapsprites/mapsprite171.bin",file);
    splitSingleChunk(0x3D226,0x3D36C,"Mapsprite172","data/graphics/mapsprites/mapsprite172.bin",file);
    splitSingleChunk(0x3D5A4,0x3D6A2,"Mapsprite173","data/graphics/mapsprites/mapsprite173.bin",file);
    splitSingleChunk(0x3D8C2,0x3D9CA,"Mapsprite174","data/graphics/mapsprites/mapsprite174.bin",file);
    splitSingleChunk(0x3DBDE,0x3DCE2,"Mapsprite175","data/graphics/mapsprites/mapsprite175.bin",file);
    splitSingleChunk(0x3DF1C,0x3E07E,"Mapsprite176","data/graphics/mapsprites/mapsprite176.bin",file);
    splitSingleChunk(0x3E2D6,0x3E3E8,"Mapsprite177","data/graphics/mapsprites/mapsprite177.bin",file);
    splitSingleChunk(0x3E660,0x3E788,"Mapsprite178","data/graphics/mapsprites/mapsprite178.bin",file);
    splitSingleChunk(0x3EA0A,0x3EB32,"Mapsprite179","data/graphics/mapsprites/mapsprite179.bin",file);
    splitSingleChunk(0x3EDA6,0x3EEC8,"Mapsprite180","data/graphics/mapsprites/mapsprite180.bin",file);
    splitSingleChunk(0x3F13A,0x3F212,"Mapsprite181","data/graphics/mapsprites/mapsprite181.bin",file);
    splitSingleChunk(0x3F486,0x3F572,"Mapsprite182","data/graphics/mapsprites/mapsprite182.bin",file);
    splitSingleChunk(0x3F7F8,0x3F8E0,"Mapsprite183","data/graphics/mapsprites/mapsprite183.bin",file);
    splitSingleChunk(0x3FAFC,0x3FC0A,"Mapsprite184","data/graphics/mapsprites/mapsprite184.bin",file);
    splitSingleChunk(0x3FDFC,0x3FEF2,"Mapsprite185","data/graphics/mapsprites/mapsprite185.bin",file);
    splitSingleChunk(0x400F8,0x401D4,"Mapsprite186","data/graphics/mapsprites/mapsprite186.bin",file);
    splitSingleChunk(0x403B2,0x404D0,"Mapsprite187","data/graphics/mapsprites/mapsprite187.bin",file);
    splitSingleChunk(0x406EA,0x407FC,"Mapsprite188","data/graphics/mapsprites/mapsprite188.bin",file);
    splitSingleChunk(0x40A1C,0x40B3C,"Mapsprite189","data/graphics/mapsprites/mapsprite189.bin",file);
    splitSingleChunk(0x40D5E,0x40E86,"Mapsprite190","data/graphics/mapsprites/mapsprite190.bin",file);
    splitSingleChunk(0x410A8,0x411C8,"Mapsprite191","data/graphics/mapsprites/mapsprite191.bin",file);
    splitSingleChunk(0x413EE,0x4151C,"Mapsprite192","data/graphics/mapsprites/mapsprite192.bin",file);
    splitSingleChunk(0x41786,0x418B0,"Mapsprite193","data/graphics/mapsprites/mapsprite193.bin",file);
    splitSingleChunk(0x41B5C,0x41C6C,"Mapsprite194","data/graphics/mapsprites/mapsprite194.bin",file);
    splitSingleChunk(0x41F0E,0x42028,"Mapsprite195","data/graphics/mapsprites/mapsprite195.bin",file);
    splitSingleChunk(0x422B0,0x4239A,"Mapsprite196","data/graphics/mapsprites/mapsprite196.bin",file);
    splitSingleChunk(0x425C2,0x426B2,"Mapsprite197","data/graphics/mapsprites/mapsprite197.bin",file);
    splitSingleChunk(0x4291C,0x42A08,"Mapsprite198","data/graphics/mapsprites/mapsprite198.bin",file);
    splitSingleChunk(0x42CAA,0x42DA2,"Mapsprite199","data/graphics/mapsprites/mapsprite199.bin",file);
    splitSingleChunk(0x42FCC,0x430D4,"Mapsprite200","data/graphics/mapsprites/mapsprite200.bin",file);
    splitSingleChunk(0x43322,0x4341E,"Mapsprite201","data/graphics/mapsprites/mapsprite201.bin",file);
    splitSingleChunk(0x4362C,0x436EC,"Mapsprite202","data/graphics/mapsprites/mapsprite202.bin",file);
    splitSingleChunk(0x43938,0x43A68,"Mapsprite203","data/graphics/mapsprites/mapsprite203.bin",file);
    splitSingleChunk(0x43D26,0x43E4C,"Mapsprite204","data/graphics/mapsprites/mapsprite204.bin",file);
    splitSingleChunk(0x440BA,0x441EC,"Mapsprite205","data/graphics/mapsprites/mapsprite205.bin",file);
    splitSingleChunk(0x44428,0x44534,"Mapsprite206","data/graphics/mapsprites/mapsprite206.bin",file);
    splitSingleChunk(0x447B4,0x448D0,"Mapsprite207","data/graphics/mapsprites/mapsprite207.bin",file);
    splitSingleChunk(0x44B92,0x44CE0,"Mapsprite208","data/graphics/mapsprites/mapsprite208.bin",file);
    splitSingleChunk(0x44FA8,0x450DE,"Mapsprite209","data/graphics/mapsprites/mapsprite209.bin",file);
    splitSingleChunk(0x4536A,0x4544A,"Mapsprite210","data/graphics/mapsprites/mapsprite210.bin",file);
    splitSingleChunk(0x456EA,0x457E0,"Mapsprite211","data/graphics/mapsprites/mapsprite211.bin",file);
    splitSingleChunk(0x45A34,0x45B46,"Mapsprite212","data/graphics/mapsprites/mapsprite212.bin",file);
    splitSingleChunk(0x45D0C,0x45DC0,"Mapsprite213","data/graphics/mapsprites/mapsprite213.bin",file);
    splitSingleChunk(0x45F7E,0x4606C,"Mapsprite214","data/graphics/mapsprites/mapsprite214.bin",file);
    splitSingleChunk(0x462E6,0x463F2,"Mapsprite215","data/graphics/mapsprites/mapsprite215.bin",file);
    splitSingleChunk(0x4666E,0x467DA,"Mapsprite216","data/graphics/mapsprites/mapsprite216.bin",file);
    splitSingleChunk(0x469D0,0x46ADE,"Mapsprite217","data/graphics/mapsprites/mapsprite217.bin",file);
    splitSingleChunk(0x46CCE,0x46DD6,"Mapsprite218","data/graphics/mapsprites/mapsprite218.bin",file);
    splitSingleChunk(0x4707E,0x471E2,"Mapsprite219","data/graphics/mapsprites/mapsprite219.bin",file);
    splitSingleChunk(0x47490,0x47592,"Mapsprite220","data/graphics/mapsprites/mapsprite220.bin",file);
    splitSingleChunk(0x477D8,0x47942,"Mapsprite221","data/graphics/mapsprites/mapsprite221.bin",file);
    splitSingleChunk(0x47C08,0x47D7C,"Mapsprite222","data/graphics/mapsprites/mapsprite222.bin",file);
    splitSingleChunk(0x480B8,0x4822C,"Mapsprite223","data/graphics/mapsprites/mapsprite223.bin",file);
    splitSingleChunk(0x48506,0x48622,"Mapsprite224","data/graphics/mapsprites/mapsprite224.bin",file);
    splitSingleChunk(0x488D8,0x489D6,"Mapsprite225","data/graphics/mapsprites/mapsprite225.bin",file);
    splitSingleChunk(0x48C28,0x48D3E,"Mapsprite226","data/graphics/mapsprites/mapsprite226.bin",file);
    splitSingleChunk(0x48F22,0x4900E,"Mapsprite227","data/graphics/mapsprites/mapsprite227.bin",file);
    splitSingleChunk(0x49192,0x49280,"Mapsprite228","data/graphics/mapsprites/mapsprite228.bin",file);
    splitSingleChunk(0x494AA,0x495CC,"Mapsprite229","data/graphics/mapsprites/mapsprite229.bin",file);
    splitSingleChunk(0x4986A,0x49996,"Mapsprite230","data/graphics/mapsprites/mapsprite230.bin",file);
    splitSingleChunk(0x49C2E,0x49D04,"Mapsprite231","data/graphics/mapsprites/mapsprite231.bin",file);
    splitSingleChunk(0x49F8C,0x4A050,"Mapsprite232","data/graphics/mapsprites/mapsprite232.bin",file);
    splitSingleChunk(0x4A2E0,0x4A41A,"Mapsprite233","data/graphics/mapsprites/mapsprite233.bin",file);
    splitSingleChunk(0x4A6D0,0x4A80A,"Mapsprite234","data/graphics/mapsprites/mapsprite234.bin",file);
    splitSingleChunk(0x4AA90,0x4AB7E,"Mapsprite235","data/graphics/mapsprites/mapsprite235.bin",file);
    splitSingleChunk(0x4ADBE,0x4AEB4,"Mapsprite236","data/graphics/mapsprites/mapsprite236.bin",file);
    splitSingleChunk(0x4B100,0x4B1EA,"Mapsprite237","data/graphics/mapsprites/mapsprite237.bin",file);
    splitSingleChunk(0x4B40C,0x4B516,"Mapsprite238","data/graphics/mapsprites/mapsprite238.bin",file);
    splitSingleChunk(0x4B75C,0x4B84E,"Mapsprite239","data/graphics/mapsprites/mapsprite239.bin",file);
    splitSingleChunk(0x4BA6C,0x4BB90,"Mapsprite240","data/graphics/mapsprites/mapsprite240.bin",file);
    splitSingleChunk(0x4BDC0,0x4BEE0,"Mapsprite241","data/graphics/mapsprites/mapsprite241.bin",file);
    splitSingleChunk(0x4C1AE,0x4C2EC,"Mapsprite242","data/graphics/mapsprites/mapsprite242.bin",file);
    splitSingleChunk(0x4CA98,0x4CBC6,"Mapsprite243","data/graphics/mapsprites/mapsprite243.bin",file);
    splitSingleChunk(0x4C6DE,0x4C80C,"Mapsprite244","data/graphics/mapsprites/mapsprite244.bin",file);
    splitSingleChunk(0x4CE4C,0x4CF4A,"Mapsprite245","data/graphics/mapsprites/mapsprite245.bin",file);
    splitSingleChunk(0x4D2E8,0x4D3CE,"Mapsprite246","data/graphics/mapsprites/mapsprite246.bin",file);
    splitSingleChunk(0x4D678,0x4D784,"Mapsprite247","data/graphics/mapsprites/mapsprite247.bin",file);
    splitSingleChunk(0x4DA82,0x4DBC4,"Mapsprite248","data/graphics/mapsprites/mapsprite248.bin",file);
    splitSingleChunk(0x4DE8E,0x4DFC6,"Mapsprite249","data/graphics/mapsprites/mapsprite249.bin",file);
    splitSingleChunk(0x4E12A,0x4E166,"Mapsprite250","data/graphics/mapsprites/mapsprite250.bin",file);
    splitSingleChunk(0x4E31C,0x4E4A4,"Mapsprite251","data/graphics/mapsprites/mapsprite251.bin",file);
    splitSingleChunk(0x4E75E,0x4E868,"Mapsprite252","data/graphics/mapsprites/mapsprite252.bin",file);
    splitSingleChunk(0x4EB26,0x4EC94,"Mapsprite253","data/graphics/mapsprites/mapsprite253.bin",file);
    splitSingleChunk(0x4EF28,0x4F046,"Mapsprite254","data/graphics/mapsprites/mapsprite254.bin",file);
    splitSingleChunk(0x4F2B6,0x4F3BA,"Mapsprite255","data/graphics/mapsprites/mapsprite255.bin",file);
    splitSingleChunk(0x4F5F0,0x4F752,"Mapsprite256","data/graphics/mapsprites/mapsprite256.bin",file);
    splitSingleChunk(0x4F95C,0x4FA28,"Mapsprite257","data/graphics/mapsprites/mapsprite257.bin",file);
    splitSingleChunk(0x4FC10,0x4FCF2,"Mapsprite258","data/graphics/mapsprites/mapsprite258.bin",file);
    splitSingleChunk(0x4FF06,0x50016,"Mapsprite259","data/graphics/mapsprites/mapsprite259.bin",file);
    splitSingleChunk(0x502AE,0x503B4,"Mapsprite260","data/graphics/mapsprites/mapsprite260.bin",file);
    splitSingleChunk(0x507B4,0x508E8,"Mapsprite261","data/graphics/mapsprites/mapsprite261.bin",file);
    splitSingleChunk(0x50BCE,0x50CEC,"Mapsprite262","data/graphics/mapsprites/mapsprite262.bin",file);
    splitSingleChunk(0x50EF6,0x50FD0,"Mapsprite263","data/graphics/mapsprites/mapsprite263.bin",file);
    splitSingleChunk(0x511F2,0x512B4,"Mapsprite264","data/graphics/mapsprites/mapsprite264.bin",file);
    splitSingleChunk(0x51524,0x51622,"Mapsprite265","data/graphics/mapsprites/mapsprite265.bin",file);
    splitSingleChunk(0x5189E,0x5199E,"Mapsprite266","data/graphics/mapsprites/mapsprite266.bin",file);
    splitSingleChunk(0x51C28,0x51DBC,"Mapsprite267","data/graphics/mapsprites/mapsprite267.bin",file);
    splitSingleChunk(0x5206C,0x5218C,"Mapsprite268","data/graphics/mapsprites/mapsprite268.bin",file);
    splitSingleChunk(0x5247A,0x5254E,"Mapsprite269","data/graphics/mapsprites/mapsprite269.bin",file);
    splitSingleChunk(0x5275E,0x52894,"Mapsprite270","data/graphics/mapsprites/mapsprite270.bin",file);
    splitSingleChunk(0x52AD2,0x52BBE,"Mapsprite271","data/graphics/mapsprites/mapsprite271.bin",file);
    splitSingleChunk(0x52DAA,0x52E7A,"Mapsprite272","data/graphics/mapsprites/mapsprite272.bin",file);
    splitSingleChunk(0x53038,0x53126,"Mapsprite273","data/graphics/mapsprites/mapsprite273.bin",file);
    splitSingleChunk(0x532EC,0x533D2,"Mapsprite274","data/graphics/mapsprites/mapsprite274.bin",file);
    splitSingleChunk(0x5359A,0x53666,"Mapsprite275","data/graphics/mapsprites/mapsprite275.bin",file);
    splitSingleChunk(0x53832,0x53910,"Mapsprite276","data/graphics/mapsprites/mapsprite276.bin",file);
    splitSingleChunk(0x53B12,0x53BDA,"Mapsprite277","data/graphics/mapsprites/mapsprite277.bin",file);
    splitSingleChunk(0x53DB6,0x53E7C,"Mapsprite278","data/graphics/mapsprites/mapsprite278.bin",file);
    splitSingleChunk(0x54082,0x5413A,"Mapsprite279","data/graphics/mapsprites/mapsprite279.bin",file);
    splitSingleChunk(0x542F4,0x54380,"Mapsprite280","data/graphics/mapsprites/mapsprite280.bin",file);
    splitSingleChunk(0x544FA,0x545CE,"Mapsprite281","data/graphics/mapsprites/mapsprite281.bin",file);
    splitSingleChunk(0x54716,0x547DE,"Mapsprite282","data/graphics/mapsprites/mapsprite282.bin",file);
    splitSingleChunk(0x548DA,0x54956,"Mapsprite283","data/graphics/mapsprites/mapsprite283.bin",file);
    splitSingleChunk(0x54A1E,0x54A9A,"Mapsprite284","data/graphics/mapsprites/mapsprite284.bin",file);
    splitSingleChunk(0x54BE6,0x54CA2,"Mapsprite285","data/graphics/mapsprites/mapsprite285.bin",file);
    splitSingleChunk(0x54E94,0x54F80,"Mapsprite286","data/graphics/mapsprites/mapsprite286.bin",file);
    splitSingleChunk(0x55154,0x55212,"Mapsprite287","data/graphics/mapsprites/mapsprite287.bin",file);
    splitSingleChunk(0x5541A,0x55518,"Mapsprite288","data/graphics/mapsprites/mapsprite288.bin",file);
    splitSingleChunk(0x55756,0x5583A,"Mapsprite289","data/graphics/mapsprites/mapsprite289.bin",file);
    splitSingleChunk(0x559D2,0x55A96,"Mapsprite290","data/graphics/mapsprites/mapsprite290.bin",file);
    splitSingleChunk(0x55CA4,0x55D8A,"Mapsprite291","data/graphics/mapsprites/mapsprite291.bin",file);
    splitSingleChunk(0x55FE2,0x560DE,"Mapsprite292","data/graphics/mapsprites/mapsprite292.bin",file);
    splitSingleChunk(0x562FC,0x563D0,"Mapsprite293","data/graphics/mapsprites/mapsprite293.bin",file);
    splitSingleChunk(0x565D6,0x566BC,"Mapsprite294","data/graphics/mapsprites/mapsprite294.bin",file);
    splitSingleChunk(0x5682C,0x568BE,"Mapsprite295","data/graphics/mapsprites/mapsprite295.bin",file);
    splitSingleChunk(0x56AEA,0x56BFC,"Mapsprite296","data/graphics/mapsprites/mapsprite296.bin",file);
    splitSingleChunk(0x56E94,0x56F88,"Mapsprite297","data/graphics/mapsprites/mapsprite297.bin",file);
    splitSingleChunk(0x57110,0x571BA,"Mapsprite298","data/graphics/mapsprites/mapsprite298.bin",file);
    splitSingleChunk(0x573A2,0x574C6,"Mapsprite299","data/graphics/mapsprites/mapsprite299.bin",file);
    splitSingleChunk(0x576E0,0x577F2,"Mapsprite300","data/graphics/mapsprites/mapsprite300.bin",file);
    splitSingleChunk(0x57974,0x57A36,"Mapsprite301","data/graphics/mapsprites/mapsprite301.bin",file);
    splitSingleChunk(0x57B62,0x57BD0,"Mapsprite302","data/graphics/mapsprites/mapsprite302.bin",file);
    splitSingleChunk(0x57DF4,0x57EAA,"Mapsprite303","data/graphics/mapsprites/mapsprite303.bin",file);
    splitSingleChunk(0x3A29E,0x3A37E,"Mapsprite304","data/graphics/mapsprites/mapsprite304.bin",file);
    splitSingleChunk(0x3A58C,0x3A676,"Mapsprite305","data/graphics/mapsprites/mapsprite305.bin",file);
    splitSingleChunk(0x3A894,0x3A986,"Mapsprite306","data/graphics/mapsprites/mapsprite306.bin",file);
    splitSingleChunk(0x3ABA4,0x3ACA0,"Mapsprite307","data/graphics/mapsprites/mapsprite307.bin",file);
    splitSingleChunk(0x3AECC,0x3AFCC,"Mapsprite308","data/graphics/mapsprites/mapsprite308.bin",file);
    splitSingleChunk(0x3B1E8,0x3B2D6,"Mapsprite309","data/graphics/mapsprites/mapsprite309.bin",file);
    splitSingleChunk(0x3B4E0,0x3B5C4,"Mapsprite310","data/graphics/mapsprites/mapsprite310.bin",file);
    splitSingleChunk(0x3B7AC,0x3B8AE,"Mapsprite311","data/graphics/mapsprites/mapsprite311.bin",file);
    splitSingleChunk(0x3BAE0,0x3BBE2,"Mapsprite312","data/graphics/mapsprites/mapsprite312.bin",file);
    splitSingleChunk(0x3BE2E,0x3BF5A,"Mapsprite313","data/graphics/mapsprites/mapsprite313.bin",file);
    splitSingleChunk(0x3C152,0x3C22C,"Mapsprite314","data/graphics/mapsprites/mapsprite314.bin",file);
    splitSingleChunk(0x3C432,0x3C522,"Mapsprite315","data/graphics/mapsprites/mapsprite315.bin",file);
    splitSingleChunk(0x3C76A,0x3C85C,"Mapsprite316","data/graphics/mapsprites/mapsprite316.bin",file);
    splitSingleChunk(0x3CA14,0x3CAD2,"Mapsprite317","data/graphics/mapsprites/mapsprite317.bin",file);
    splitSingleChunk(0x3CCC6,0x3CDB4,"Mapsprite318","data/graphics/mapsprites/mapsprite318.bin",file);
    splitSingleChunk(0x3CFE6,0x3D0D6,"Mapsprite319","data/graphics/mapsprites/mapsprite319.bin",file);
    splitSingleChunk(0x3D36C,0x3D48E,"Mapsprite320","data/graphics/mapsprites/mapsprite320.bin",file);
    splitSingleChunk(0x3D6A2,0x3D7A4,"Mapsprite321","data/graphics/mapsprites/mapsprite321.bin",file);
    splitSingleChunk(0x3D9CA,0x3DACC,"Mapsprite322","data/graphics/mapsprites/mapsprite322.bin",file);
    splitSingleChunk(0x3DCE2,0x3DDEA,"Mapsprite323","data/graphics/mapsprites/mapsprite323.bin",file);
    splitSingleChunk(0x3E07E,0x3E198,"Mapsprite324","data/graphics/mapsprites/mapsprite324.bin",file);
    splitSingleChunk(0x3E3E8,0x3E518,"Mapsprite325","data/graphics/mapsprites/mapsprite325.bin",file);
    splitSingleChunk(0x3E788,0x3E8C4,"Mapsprite326","data/graphics/mapsprites/mapsprite326.bin",file);
    splitSingleChunk(0x3EB32,0x3EC5E,"Mapsprite327","data/graphics/mapsprites/mapsprite327.bin",file);
    splitSingleChunk(0x3EEC8,0x3EFF4,"Mapsprite328","data/graphics/mapsprites/mapsprite328.bin",file);
    splitSingleChunk(0x3F212,0x3F336,"Mapsprite329","data/graphics/mapsprites/mapsprite329.bin",file);
    splitSingleChunk(0x3F572,0x3F6A6,"Mapsprite330","data/graphics/mapsprites/mapsprite330.bin",file);
    splitSingleChunk(0x3F8E0,0x3FA1A,"Mapsprite331","data/graphics/mapsprites/mapsprite331.bin",file);
    splitSingleChunk(0x3FC0A,0x3FCEC,"Mapsprite332","data/graphics/mapsprites/mapsprite332.bin",file);
    splitSingleChunk(0x3FEF2,0x3FFD4,"Mapsprite333","data/graphics/mapsprites/mapsprite333.bin",file);
    splitSingleChunk(0x401D4,0x4029E,"Mapsprite334","data/graphics/mapsprites/mapsprite334.bin",file);
    splitSingleChunk(0x404D0,0x405CA,"Mapsprite335","data/graphics/mapsprites/mapsprite335.bin",file);
    splitSingleChunk(0x407FC,0x40904,"Mapsprite336","data/graphics/mapsprites/mapsprite336.bin",file);
    splitSingleChunk(0x40B3C,0x40C3E,"Mapsprite337","data/graphics/mapsprites/mapsprite337.bin",file);
    splitSingleChunk(0x40E86,0x40F8C,"Mapsprite338","data/graphics/mapsprites/mapsprite338.bin",file);
    splitSingleChunk(0x411C8,0x412CA,"Mapsprite339","data/graphics/mapsprites/mapsprite339.bin",file);
    splitSingleChunk(0x4151C,0x4162E,"Mapsprite340","data/graphics/mapsprites/mapsprite340.bin",file);
    splitSingleChunk(0x418B0,0x41A06,"Mapsprite341","data/graphics/mapsprites/mapsprite341.bin",file);
    splitSingleChunk(0x41C6C,0x41DB0,"Mapsprite342","data/graphics/mapsprites/mapsprite342.bin",file);
    splitSingleChunk(0x42028,0x42186,"Mapsprite343","data/graphics/mapsprites/mapsprite343.bin",file);
    splitSingleChunk(0x4239A,0x42488,"Mapsprite344","data/graphics/mapsprites/mapsprite344.bin",file);
    splitSingleChunk(0x426B2,0x427DC,"Mapsprite345","data/graphics/mapsprites/mapsprite345.bin",file);
    splitSingleChunk(0x42A08,0x42B0A,"Mapsprite346","data/graphics/mapsprites/mapsprite346.bin",file);
    splitSingleChunk(0x42DA2,0x42E98,"Mapsprite347","data/graphics/mapsprites/mapsprite347.bin",file);
    splitSingleChunk(0x430D4,0x431F6,"Mapsprite348","data/graphics/mapsprites/mapsprite348.bin",file);
    splitSingleChunk(0x4341E,0x43514,"Mapsprite349","data/graphics/mapsprites/mapsprite349.bin",file);
    splitSingleChunk(0x436EC,0x437D2,"Mapsprite350","data/graphics/mapsprites/mapsprite350.bin",file);
    splitSingleChunk(0x43A68,0x43BB0,"Mapsprite351","data/graphics/mapsprites/mapsprite351.bin",file);
    splitSingleChunk(0x43E4C,0x43F9C,"Mapsprite352","data/graphics/mapsprites/mapsprite352.bin",file);
    splitSingleChunk(0x441EC,0x442EC,"Mapsprite353","data/graphics/mapsprites/mapsprite353.bin",file);
    splitSingleChunk(0x44534,0x4466A,"Mapsprite354","data/graphics/mapsprites/mapsprite354.bin",file);
    splitSingleChunk(0x448D0,0x44A18,"Mapsprite355","data/graphics/mapsprites/mapsprite355.bin",file);
    splitSingleChunk(0x44CE0,0x44E2C,"Mapsprite356","data/graphics/mapsprites/mapsprite356.bin",file);
    splitSingleChunk(0x450DE,0x4522E,"Mapsprite357","data/graphics/mapsprites/mapsprite357.bin",file);
    splitSingleChunk(0x4544A,0x4556C,"Mapsprite358","data/graphics/mapsprites/mapsprite358.bin",file);
    splitSingleChunk(0x457E0,0x45902,"Mapsprite359","data/graphics/mapsprites/mapsprite359.bin",file);
    splitSingleChunk(0x45B46,0x45C34,"Mapsprite360","data/graphics/mapsprites/mapsprite360.bin",file);
    splitSingleChunk(0x45DC0,0x45E7C,"Mapsprite361","data/graphics/mapsprites/mapsprite361.bin",file);
    splitSingleChunk(0x4606C,0x46152,"Mapsprite362","data/graphics/mapsprites/mapsprite362.bin",file);
    splitSingleChunk(0x463F2,0x46546,"Mapsprite363","data/graphics/mapsprites/mapsprite363.bin",file);
    splitSingleChunk(0x467DA,0x468E4,"Mapsprite364","data/graphics/mapsprites/mapsprite364.bin",file);
    splitSingleChunk(0x46ADE,0x46BE2,"Mapsprite365","data/graphics/mapsprites/mapsprite365.bin",file);
    splitSingleChunk(0x46DD6,0x46ED8,"Mapsprite366","data/graphics/mapsprites/mapsprite366.bin",file);
    splitSingleChunk(0x471E2,0x4733E,"Mapsprite367","data/graphics/mapsprites/mapsprite367.bin",file);
    splitSingleChunk(0x47592,0x476BC,"Mapsprite368","data/graphics/mapsprites/mapsprite368.bin",file);
    splitSingleChunk(0x47942,0x47A56,"Mapsprite369","data/graphics/mapsprites/mapsprite369.bin",file);
    splitSingleChunk(0x47D7C,0x47F0C,"Mapsprite370","data/graphics/mapsprites/mapsprite370.bin",file);
    splitSingleChunk(0x4822C,0x483B6,"Mapsprite371","data/graphics/mapsprites/mapsprite371.bin",file);
    splitSingleChunk(0x48622,0x48748,"Mapsprite372","data/graphics/mapsprites/mapsprite372.bin",file);
    splitSingleChunk(0x489D6,0x48AD4,"Mapsprite373","data/graphics/mapsprites/mapsprite373.bin",file);
    splitSingleChunk(0x48D3E,0x48E58,"Mapsprite374","data/graphics/mapsprites/mapsprite374.bin",file);
    splitSingleChunk(0x4900E,0x490C8,"Mapsprite375","data/graphics/mapsprites/mapsprite375.bin",file);
    splitSingleChunk(0x49280,0x4933A,"Mapsprite376","data/graphics/mapsprites/mapsprite376.bin",file);
    splitSingleChunk(0x495CC,0x496F6,"Mapsprite377","data/graphics/mapsprites/mapsprite377.bin",file);
    splitSingleChunk(0x49996,0x49ACC,"Mapsprite378","data/graphics/mapsprites/mapsprite378.bin",file);
    splitSingleChunk(0x49D04,0x49E54,"Mapsprite379","data/graphics/mapsprites/mapsprite379.bin",file);
    splitSingleChunk(0x4A050,0x4A182,"Mapsprite380","data/graphics/mapsprites/mapsprite380.bin",file);
    splitSingleChunk(0x4A41A,0x4A55C,"Mapsprite381","data/graphics/mapsprites/mapsprite381.bin",file);
    splitSingleChunk(0x4A80A,0x4A950,"Mapsprite382","data/graphics/mapsprites/mapsprite382.bin",file);
    splitSingleChunk(0x4AB7E,0x4AC72,"Mapsprite383","data/graphics/mapsprites/mapsprite383.bin",file);
    splitSingleChunk(0x4AEB4,0x4AFC4,"Mapsprite384","data/graphics/mapsprites/mapsprite384.bin",file);
    splitSingleChunk(0x4B1EA,0x4B2DE,"Mapsprite385","data/graphics/mapsprites/mapsprite385.bin",file);
    splitSingleChunk(0x4B516,0x4B636,"Mapsprite386","data/graphics/mapsprites/mapsprite386.bin",file);
    splitSingleChunk(0x4B84E,0x4B95E,"Mapsprite387","data/graphics/mapsprites/mapsprite387.bin",file);
    splitSingleChunk(0x4BB90,0x4BCB4,"Mapsprite388","data/graphics/mapsprites/mapsprite388.bin",file);
    splitSingleChunk(0x4BEE0,0x4BFF6,"Mapsprite389","data/graphics/mapsprites/mapsprite389.bin",file);
    splitSingleChunk(0x4C2EC,0x4C46A,"Mapsprite390","data/graphics/mapsprites/mapsprite390.bin",file);
    splitSingleChunk(0x4CBC6,0x4CCF4,"Mapsprite391","data/graphics/mapsprites/mapsprite391.bin",file);
    splitSingleChunk(0x4C80C,0x4C93A,"Mapsprite392","data/graphics/mapsprites/mapsprite392.bin",file);
    splitSingleChunk(0x4CF4A,0x4D082,"Mapsprite393","data/graphics/mapsprites/mapsprite393.bin",file);
    splitSingleChunk(0x4D3CE,0x4D524,"Mapsprite394","data/graphics/mapsprites/mapsprite394.bin",file);
    splitSingleChunk(0x4D784,0x4D8C8,"Mapsprite395","data/graphics/mapsprites/mapsprite395.bin",file);
    splitSingleChunk(0x4DBC4,0x4DD3C,"Mapsprite396","data/graphics/mapsprites/mapsprite396.bin",file);
    splitSingleChunk(0x4DFC6,0x4E0E6,"Mapsprite397","data/graphics/mapsprites/mapsprite397.bin",file);
    splitSingleChunk(0x4E166,0x4E1A2,"Mapsprite398","data/graphics/mapsprites/mapsprite398.bin",file);
    splitSingleChunk(0x4E4A4,0x4E600,"Mapsprite399","data/graphics/mapsprites/mapsprite399.bin",file);
    splitSingleChunk(0x4E868,0x4E99E,"Mapsprite400","data/graphics/mapsprites/mapsprite400.bin",file);
    splitSingleChunk(0x4EC94,0x4EDEE,"Mapsprite401","data/graphics/mapsprites/mapsprite401.bin",file);
    splitSingleChunk(0x4F046,0x4F180,"Mapsprite402","data/graphics/mapsprites/mapsprite402.bin",file);
    splitSingleChunk(0x4F3BA,0x4F4D8,"Mapsprite403","data/graphics/mapsprites/mapsprite403.bin",file);
    splitSingleChunk(0x4F752,0x4F85A,"Mapsprite404","data/graphics/mapsprites/mapsprite404.bin",file);
    splitSingleChunk(0x4FA28,0x4FB20,"Mapsprite405","data/graphics/mapsprites/mapsprite405.bin",file);
    splitSingleChunk(0x4FCF2,0x4FDDE,"Mapsprite406","data/graphics/mapsprites/mapsprite406.bin",file);
    splitSingleChunk(0x50016,0x50134,"Mapsprite407","data/graphics/mapsprites/mapsprite407.bin",file);
    splitSingleChunk(0x503B4,0x504DC,"Mapsprite408","data/graphics/mapsprites/mapsprite408.bin",file);
    splitSingleChunk(0x508E8,0x50A5E,"Mapsprite409","data/graphics/mapsprites/mapsprite409.bin",file);
    splitSingleChunk(0x50CEC,0x50E02,"Mapsprite410","data/graphics/mapsprites/mapsprite410.bin",file);
    splitSingleChunk(0x50FD0,0x510A6,"Mapsprite411","data/graphics/mapsprites/mapsprite411.bin",file);
    splitSingleChunk(0x512B4,0x513E2,"Mapsprite412","data/graphics/mapsprites/mapsprite412.bin",file);
    splitSingleChunk(0x51622,0x5172C,"Mapsprite413","data/graphics/mapsprites/mapsprite413.bin",file);
    splitSingleChunk(0x5199E,0x51AAA,"Mapsprite414","data/graphics/mapsprites/mapsprite414.bin",file);
    splitSingleChunk(0x51DBC,0x51F0C,"Mapsprite415","data/graphics/mapsprites/mapsprite415.bin",file);
    splitSingleChunk(0x5218C,0x52290,"Mapsprite416","data/graphics/mapsprites/mapsprite416.bin",file);
    splitSingleChunk(0x5254E,0x525FE,"Mapsprite417","data/graphics/mapsprites/mapsprite417.bin",file);
    splitSingleChunk(0x52894,0x529C4,"Mapsprite418","data/graphics/mapsprites/mapsprite418.bin",file);
    splitSingleChunk(0x52BBE,0x52CB0,"Mapsprite419","data/graphics/mapsprites/mapsprite419.bin",file);
    splitSingleChunk(0x52E7A,0x52F46,"Mapsprite420","data/graphics/mapsprites/mapsprite420.bin",file);
    splitSingleChunk(0x53126,0x531EE,"Mapsprite421","data/graphics/mapsprites/mapsprite421.bin",file);
    splitSingleChunk(0x533D2,0x534BA,"Mapsprite422","data/graphics/mapsprites/mapsprite422.bin",file);
    splitSingleChunk(0x53666,0x5372C,"Mapsprite423","data/graphics/mapsprites/mapsprite423.bin",file);
    splitSingleChunk(0x53910,0x53A04,"Mapsprite424","data/graphics/mapsprites/mapsprite424.bin",file);
    splitSingleChunk(0x53BDA,0x53CBA,"Mapsprite425","data/graphics/mapsprites/mapsprite425.bin",file);
    splitSingleChunk(0x53E7C,0x53F7C,"Mapsprite426","data/graphics/mapsprites/mapsprite426.bin",file);
    splitSingleChunk(0x5413A,0x54242,"Mapsprite427","data/graphics/mapsprites/mapsprite427.bin",file);
    splitSingleChunk(0x54380,0x5441C,"Mapsprite428","data/graphics/mapsprites/mapsprite428.bin",file);
    splitSingleChunk(0x545CE,0x54680,"Mapsprite429","data/graphics/mapsprites/mapsprite429.bin",file);
    splitSingleChunk(0x547DE,0x54876,"Mapsprite430","data/graphics/mapsprites/mapsprite430.bin",file);
    splitSingleChunk(0x54956,0x549B0,"Mapsprite431","data/graphics/mapsprites/mapsprite431.bin",file);
    splitSingleChunk(0x54A9A,0x54B08,"Mapsprite432","data/graphics/mapsprites/mapsprite432.bin",file);
    splitSingleChunk(0x54CA2,0x54D6E,"Mapsprite433","data/graphics/mapsprites/mapsprite433.bin",file);
    splitSingleChunk(0x54F80,0x55074,"Mapsprite434","data/graphics/mapsprites/mapsprite434.bin",file);
    splitSingleChunk(0x55212,0x552E0,"Mapsprite435","data/graphics/mapsprites/mapsprite435.bin",file);
    splitSingleChunk(0x55518,0x55636,"Mapsprite436","data/graphics/mapsprites/mapsprite436.bin",file);
    splitSingleChunk(0x5583A,0x55904,"Mapsprite437","data/graphics/mapsprites/mapsprite437.bin",file);
    splitSingleChunk(0x55A96,0x55B44,"Mapsprite438","data/graphics/mapsprites/mapsprite438.bin",file);
    splitSingleChunk(0x55D8A,0x55E96,"Mapsprite439","data/graphics/mapsprites/mapsprite439.bin",file);
    splitSingleChunk(0x560DE,0x56202,"Mapsprite440","data/graphics/mapsprites/mapsprite440.bin",file);
    splitSingleChunk(0x563D0,0x564CA,"Mapsprite441","data/graphics/mapsprites/mapsprite441.bin",file);
    splitSingleChunk(0x566BC,0x5679E,"Mapsprite442","data/graphics/mapsprites/mapsprite442.bin",file);
    splitSingleChunk(0x568BE,0x5695C,"Mapsprite443","data/graphics/mapsprites/mapsprite443.bin",file);
    splitSingleChunk(0x56BFC,0x56D7E,"Mapsprite444","data/graphics/mapsprites/mapsprite444.bin",file);
    splitSingleChunk(0x56F88,0x5706C,"Mapsprite445","data/graphics/mapsprites/mapsprite445.bin",file);
    splitSingleChunk(0x571BA,0x5725E,"Mapsprite446","data/graphics/mapsprites/mapsprite446.bin",file);
    splitSingleChunk(0x574C6,0x575F8,"Mapsprite447","data/graphics/mapsprites/mapsprite447.bin",file);
    splitSingleChunk(0x577F2,0x5786C,"Mapsprite448","data/graphics/mapsprites/mapsprite448.bin",file);
    splitSingleChunk(0x57A36,0x57B06,"Mapsprite449","data/graphics/mapsprites/mapsprite449.bin",file);
    splitSingleChunk(0x57BD0,0x57C46,"Mapsprite450","data/graphics/mapsprites/mapsprite450.bin",file);
    splitSingleChunk(0x57EAA,0x57F5E,"Mapsprite451","data/graphics/mapsprites/mapsprite451.bin",file);
    MakeAlign(0x57F5E, 0x58000-0x57F5E,15);
    
    
    //Section 07 : 0x58000-0x80000
    
    splitSingleChunk(0x7F344,0x7F548,"SpecialSprite_BurningShip","data/graphics/specialsprites/specialsprite-burningship.bin",file);
    splitSingleChunk(0x7F548,0x7F6FF,"SpecialSprite_Jogurt2","data/graphics/specialsprites/specialsprite-jogurt2.bin",file);
    MakeAlign(0x7F6FF, 0x80000-0x7F6FF,15);
    
    
    //Section 08 : 0x80000-0xBC000
    
    
    //Section 09 : 0xBC000-0xC0000
    
    splitSingleChunk(0xBC2CE,0xBC34E,"palettes_SoundTest","data/graphics/tech/palettes/soundtestpalettes.bin",file);
    splitSingleChunk(0xBC34E,0xBCC40,"tiles_SoundTest1","data/graphics/specialscreens/soundtest/soundtesttiles1.bin",file);
    splitSingleChunk(0xBCC40,0xBD5D8,"tiles_SoundTest2","data/graphics/specialscreens/soundtest/soundtesttiles2.bin",file);
    splitSingleChunk(0xBD5D8,0xBDC38,"tiles_SoundTest3","data/graphics/specialscreens/soundtest/soundtesttiles3.bin",file);
    //splitSingleChunk(0xBDC38,0xBE338,"byte_BDC38","data/",file);
    //splitSingleChunk(0xBE338,0xBE360,"byte_BE338","data/",file);
    //splitSingleChunk(0xBE360,0xBE388,"byte_BE360","data/",file);
    //splitSingleChunk(0xBE388,0xBE3AA,"byte_BE388","data/",file);
    //splitSingleChunk(0xBE3AA,0xBE3CC,"byte_BE3AA","data/",file);
    //splitSingleChunk(0xBE3CC,0xBE3E8,"byte_BE3CC","data/",file);
    //splitSingleChunk(0xBE3E8,0xBE404,"byte_BE3E8","data/",file);
    //splitSingleChunk(0xBE404,0xBE414,"byte_BE404","data/",file);
    //splitSingleChunk(0xBE414,0xBE424,"byte_BE414","data/",file);
    //splitSingleChunk(0xBE424,0xBE43A,"byte_BE424","data/",file);
    //splitSingleChunk(0xBE43A,0xBE450,"byte_BE43A","data/",file);
    //splitSingleChunk(0xBE450,0xBE460,"byte_BE450","data/",file);
    //splitSingleChunk(0xBE460,0xBE470,"byte_BE460","data/",file);
    //splitSingleChunk(0xBE470,0xBE510,"layout_SoundTestWindow","data/graphics/tech/windowlayouts/soundtest.bin",file);
    splitSingleChunk(0xBE510,0xBE7D8,"tiles_ShiningForceLogo","data/graphics/specialscreens/readerscreen/shiningforcelogotiles.bin",file);
    //splitSingleChunk(0xBE7D8,0xBE8DE,"byte_BE7D8","data/graphics/",file);
    //splitSingleChunk(0xBE8DE,0xBE932,"byte_BE8DE","data/",file);
    //splitSingleChunk(0xBE932,0xBEA56,"byte_BE932","data/",file);
    //splitSingleChunk(0xBEA56,0xBED2A,"byte_BEA56","data/",file);
    //splitSingleChunk(0xBED2A,0xBEDAC,"byte_BED2A","data/",file);
    MakeAlign(0xBEDAA, 0xC0000-0xBEDAA,15);
    
    
    //Section 10 : 0xC0000-0xCC000
    
    splitSingleChunk(0xC0088,0xC03CE,"tiles_EndingMax1","data/graphics/specialscreens/ending/endingtiles-max1.bin",file);
    splitSingleChunk(0xC03CE,0xC075E,"tiles_EndingMax2","data/graphics/specialscreens/ending/endingtiles-max2.bin",file);
    splitSingleChunk(0xC075E,0xC0B70,"tiles_EndingMax3","data/graphics/specialscreens/ending/endingtiles-max3.bin",file);
    splitSingleChunk(0xC0B70,0xC0F0E,"tiles_EndingMax4","data/graphics/specialscreens/ending/endingtiles-max4.bin",file);
    splitSingleChunk(0xC0F0E,0xC11D0,"tiles_EndingAdam","data/graphics/specialscreens/ending/endingtiles-adam.bin",file);
    splitSingleChunk(0xC11D0,0xC15BE,"tiles_EndingTheEnd","data/graphics/specialscreens/ending/endingtiles-theend.bin",file);
    splitSingleChunk(0xC15BE,0xC163E,"palette_Ending","data/graphics/specialscreens/ending/endingpalette.bin",file);
    splitSingleChunk(0xC163E,0xC18AE,"tiles_EndingFarmer","data/graphics/specialscreens/ending/endingtiles-farmer.bin",file);
    splitSingleChunk(0xC18AE,0xC192E,"palette_IntroScene1_1","data/graphics/specialscreens/intro/intropalette-scene1-1.bin",file);
    splitSingleChunk(0xC192E,0xC19AE,"palette_IntroScene1_2","data/graphics/specialscreens/intro/intropalette-scene1-2.bin",file);
    splitSingleChunk(0xC19AE,0xC24A8,"tiles_IntroScene1_1","data/graphics/specialscreens/intro/introtiles-scene1-1.bin",file);
    splitSingleChunk(0xC24A8,0xC2E50,"tiles_IntroScene1_2","data/graphics/specialscreens/intro/introtiles-scene1-2.bin",file);
    splitSingleChunk(0xC2E50,0xC2ED0,"palette_IntroScene2","data/graphics/specialscreens/intro/intropalette-scene2.bin",file);
    splitSingleChunk(0xC2ED0,0xC331A,"tiles_IntroScene2","data/graphics/specialscreens/intro/introtiles-scene2.bin",file);
    splitSingleChunk(0xC331A,0xC339A,"palette_IntroScene3","data/graphics/specialscreens/intro/intropalette-scene3.bin",file);
    splitSingleChunk(0xC339A,0xC390E,"tiles_IntroScene3_1","data/graphics/specialscreens/intro/introtiles-scene3-1.bin",file);
    splitSingleChunk(0xC390E,0xC3F2E,"tiles_IntroScene3_2","data/graphics/specialscreens/intro/introtiles-scene3-2.bin",file);
    splitSingleChunk(0xC3F2E,0xC3FAE,"palette_IntroScene4","data/graphics/specialscreens/intro/intropalette-scene4.bin",file);
    splitSingleChunk(0xC3FAE,0xC4534,"tiles_IntroScene4_1","data/graphics/specialscreens/intro/introtiles-scene4-1.bin",file);
    splitSingleChunk(0xC4534,0xC4AE4,"tiles_IntroScene4_2","data/graphics/specialscreens/intro/introtiles-scene4-2.bin",file);
    splitSingleChunk(0xC4AE4,0xC5158,"tiles_IntroScene4_BG1","data/graphics/specialscreens/intro/introtiles-scene4-bg1.bin",file);
    splitSingleChunk(0xC5158,0xC57C4,"tiles_IntroScene4_BG2","data/graphics/specialscreens/intro/introtiles-scene4-bg2.bin",file);
    splitSingleChunk(0xC57C4,0xC5844,"palette_TitleScreen","data/graphics/specialscreens/titlescreen/titlescreenpalette.bin",file);
    splitSingleChunk(0xC5844,0xC6984,"tiles_TitleScreen","data/graphics/specialscreens/titlescreen/titlescreentiles.bin",file);
    //splitSingleChunk(0xC6984,0xC7084,"layout_TitleScreen","data/graphics/specialscreens/titlescreen/titlescreenlayout.bin",file);
    splitSingleChunk(0xC7084,0xC7104,"palette_ChapterScreen","data/graphics/specialscreens/chapterscreen/chapterscreenpalette.bin",file);
    
    
    //Section 11 : 0xCC000-0x100000
    
    splitSingleChunk(0xCC05E,0xCCB1A,"tiles_Base","data/graphics/tech/basetiles.bin",file);
    splitSingleChunk(0xCCB1A,0xCCFEE,"tiles_OptionsMenu","data/graphics/tech/menus/menutiles-battleoptions.bin",file);
    splitSingleChunk(0xCCFEE,0xCDD6E,"tiles_MainMenu","data/graphics/tech/menus/menutiles-main.bin",file);
    splitSingleChunk(0xCDD6E,0xCE2FE,"tiles_ItemMenu","data/graphics/tech/menus/menutiles-item.bin",file);
    splitSingleChunk(0xCE2FE,0xCE75E,"tiles_ShopMenu","data/graphics/tech/menus/menutiles-shop.bin",file);
    splitSingleChunk(0xCE75E,0xCEC34,"tiles_HqMenu","data/graphics/tech/menus/menutiles-hq.bin",file);
    splitSingleChunk(0xCEC34,0xCF0EA,"tiles_ChurchMenu","data/graphics/tech/menus/menutiles-church.bin",file);
    splitSingleChunk(0xCF0EA,0xCFCEA,"icons_Spell","data/graphics/icons/spellicons.bin",file);
    splitSingleChunk(0xCFCEA,0xD2DAA,"icons_Item","data/graphics/icons/itemicons.bin",file);
    splitSingleChunk(0xD2DAA,0xD2E84,"tiles_Cursor","data/graphics/tech/cursortiles.bin",file);
    splitSingleChunk(0xD2E84,0xD2EA4,"palette_Base","data/graphics/tech/basepalette.bin",file);
    //splitSingleChunk(0xD301A,0xD32DA,"layout_TextInputWindow","data/graphics/tech/windowlayouts/textinput.bin",file);
    //splitSingleChunk(0xD32DA,0xD3308,"byte_D32DA","data/",file);
    splitSingleChunk(0xD3308,0xD398E,"font_EndingCredits","data/graphics/tech/fonts/endingcreditsfont.bin",file);
    
    
    //Section 12 : 0x100000-0x124000
    
    
    //Section 13 : 0x124000-0x130000
    
    //splitSingleChunk(0x12570A,0x125A0A,"byte_12570A","data/",file);
    splitSingleChunk(0x125A0A,0x125B48,"tiles_BackgroundTransition1","data/graphics/battles/backgroundtransitiontiles1.bin",file);
    splitSingleChunk(0x125B48,0x125C3E,"tiles_BackgroundTransition2","data/graphics/battles/backgroundtransitiontiles2.bin",file);
    //splitSingleChunk(0x125C3E,0x125D54,"byte_125C3E","data/graphics/",file);
    splitSingleChunk(0x125D54,0x125F36,"tiles_BattlesceneStatusEffects","data/graphics/battles/battlescenestatuseffectstiles.bin",file);
    splitSingleChunk(0x1269C6,0x1269EE,"SpellPalette_Bolt","data/graphics/battles/spells/palettes/spellpalette-bolt.bin",file);
    splitSingleChunk(0x126A6C,0x126A76,"SpellPalette_Blaze","data/graphics/battles/spells/palettes/spellpalette-blaze.bin",file);
    splitSingleChunk(0x126B9E,0x126BA8,"SpellPalette_Freeze","data/graphics/battles/spells/palettes/spellpalette-freeze.bin",file);
    splitSingleChunk(0x126C26,0x126C30,"SpellPalette_DemonBlaze","data/graphics/battles/spells/palettes/spellpalette-demonblaze.bin",file);
    splitSingleChunk(0x126C8E,0x126C98,"SpellPalette_Desoul","data/graphics/battles/spells/palettes/spellpalette-desoul.bin",file);
    //splitSingleChunk(0x126D1E,0x126D3C,"byte_126D1E","data/",file);
    splitSingleChunk(0x126DEA,0x126DFE,"SpellPalette_Healing","data/graphics/battles/spells/palettes/spellpalette-healing.bin",file);
    splitSingleChunk(0x126E78,0x126E82,"SpellPalette_MachineGun","data/graphics/battles/spells/palettes/spellpalette-machinegun.bin",file);
    splitSingleChunk(0x126E90,0x126E9A,"SpellPalette_Crossbow","data/graphics/battles/spells/palettes/spellpalette-crossbow.bin",file);
    splitSingleChunk(0x126EF0,0x126EFA,"SpellPalette_BlueFlyingDragons","data/graphics/battles/spells/palettes/spellpalette-blueflyingdragons.bin",file);
    splitSingleChunk(0x126F4A,0x126F54,"SpellPalette_YellowFlyingDragons","data/graphics/battles/spells/palettes/spellpalette-yellowflyingdragons.bin",file);
    splitSingleChunk(0x126F6E,0x126F78,"SpellPalette_YellowLightningBreath","data/graphics/battles/spells/palettes/spellpalette-yellowlightningbreath.bin",file);
    splitSingleChunk(0x126FD0,0x126FDA,"SpellPalette_BlueLightningBreath","data/graphics/battles/spells/palettes/spellpalette-bluelightningbreath.bin",file);
    splitSingleChunk(0x126FFE,0x127008,"SpellPalette_GreenLaser","data/graphics/battles/spells/palettes/spellpalette-greenlaser.bin",file);
    splitSingleChunk(0x127060,0x12706A,"SpellPalette_BlueLaser","data/graphics/battles/spells/palettes/spellpalette-bluelaser.bin",file);
    splitSingleChunk(0x127092,0x12709C,"SpellPalette_BusterShot","data/graphics/battles/spells/palettes/spellpalette-bustershot.bin",file);
    splitSingleChunk(0x1270F4,0x1270FE,"SpellPalette_EnergyBlast","data/graphics/battles/spells/palettes/spellpalette-energyblast.bin",file);
    splitSingleChunk(0x127182,0x12718C,"SpellPalette_FireBreath","data/graphics/battles/spells/palettes/spellpalette-firebreath.bin",file);
    splitSingleChunk(0x12744A,0x127576,"SpellEntityLayout_Bolt1","data/graphics/battles/spells/layouts/spellentitylayout-bolt1.bin",file);
    splitSingleChunk(0x127576,0x127666,"SpellEntityLayout_Bolt2","data/graphics/battles/spells/layouts/spellentitylayout-bolt2.bin",file);
    splitSingleChunk(0x127864,0x1278C8,"SpellEntityLayout_BlazeFireball","data/graphics/battles/spells/layouts/spellentitylayout-blazefireball.bin",file);
    splitSingleChunk(0x1278C8,0x127904,"SpellEntityLayout_BlazeMain","data/graphics/battles/spells/layouts/spellentitylayout-blazemain.bin",file);
    splitSingleChunk(0x127A3C,0x127A6E,"SpellEntityLayout_AssaultShell","data/graphics/battles/spells/layouts/spellentitylayout-assaultshell.bin",file);
    splitSingleChunk(0x127B4C,0x127B56,"SpellEntityLayout_DemonBlaze1","data/graphics/battles/spells/layouts/spellentitylayout-demonblaze1.bin",file);
    splitSingleChunk(0x127B56,0x127B5C,"SpellEntityLayout_DemonBlaze2","data/graphics/battles/spells/layouts/spellentitylayout-demonblaze2.bin",file);
    splitSingleChunk(0x127C9C,0x127CA6,"SpellEntityLayout_FlyingDragons","data/graphics/battles/spells/layouts/spellentitylayout-flyingdragons.bin",file);
    splitSingleChunk(0x12815C,0x1281FC,"SpellEntityLayout_Freeze","data/graphics/battles/spells/layouts/spellentitylayout-freeze.bin",file);
    splitSingleChunk(0x1282CC,0x1282D6,"SpellEntityLayout_Desoul1","data/graphics/battles/spells/layouts/spellentitylayout-desoul1.bin",file);
    splitSingleChunk(0x1282D6,0x1282E0,"SpellEntityLayout_Desoul2","data/graphics/battles/spells/layouts/spellentitylayout-desoul2.bin",file);
    splitSingleChunk(0x1283C4,0x1283E2,"SpellEntityLayout_Debuff","data/graphics/battles/spells/layouts/spellentitylayout-debuff.bin",file);
    splitSingleChunk(0x12865E,0x1286FE,"SpellEntityLayout_Healing1","data/graphics/battles/spells/layouts/spellentitylayout-healing1.bin",file);
    splitSingleChunk(0x1286FE,0x128730,"SpellEntityLayout_Healing2","data/graphics/battles/spells/layouts/spellentitylayout-healing2.bin",file);
    splitSingleChunk(0x1288A0,0x1288B4,"SpellEntityLayout_MachineGun","data/graphics/battles/spells/layouts/spellentitylayout-machinegun.bin",file);
    splitSingleChunk(0x128910,0x128988,"SpellEntityLayout_LightningBreath","data/graphics/battles/spells/layouts/spellentitylayout-lightningbreath.bin",file);
    splitSingleChunk(0x128B42,0x128BE7,"SpellEntityLayout_Laser","data/graphics/battles/spells/layouts/spellentitylayout-laser.bin",file);
    splitSingleChunk(0x128BE7,0x128C23,"SpellEntityLayout_LaserEye","data/graphics/battles/spells/layouts/spellentitylayout-lasereye.bin",file);
    splitSingleChunk(0x128C23,0x128D04,"SpellEntityLayout_Laser_Mirrored","data/graphics/battles/spells/layouts/spellentitylayout-laser-mirrored.bin",file);
    splitSingleChunk(0x128D9E,0x128E16,"SpellEntityLayout_BusterShot","data/graphics/battles/spells/layouts/spellentitylayout-bustershot.bin",file);
    splitSingleChunk(0x128EAA,0x128F04,"SpellEntityLayout_EnergyBlast","data/graphics/battles/spells/layouts/spellentitylayout-energyblast.bin",file);
    splitSingleChunk(0x12C7B0,0x12CBD0,"SpellTiles_Freeze","data/graphics/battles/spells/spelltiles-freeze.bin",file);
    splitSingleChunk(0x12CBD0,0x12D47E,"SpellTiles_Bolt","data/graphics/battles/spells/spelltiles-bolt.bin",file);
    splitSingleChunk(0x12D47E,0x12DDA2,"SpellTiles_Blaze","data/graphics/battles/spells/spelltiles-blaze.bin",file);
    splitSingleChunk(0x12DDA2,0x12DFEC,"SpellTiles_Debuff","data/graphics/battles/spells/spelltiles-debuff.bin",file);
    splitSingleChunk(0x12DFEC,0x12E2FC,"SpellTiles_Desoul","data/graphics/battles/spells/spelltiles-desoul.bin",file);
    splitSingleChunk(0x12E2FC,0x12E5E4,"SpellTiles_Healing","data/graphics/battles/spells/spelltiles-healing.bin",file);
    splitSingleChunk(0x12E5E4,0x12E610,"SpellTiles_MachineGun","data/graphics/battles/spells/spelltiles-machinegun.bin",file);
    splitSingleChunk(0x12E610,0x12E692,"SpellTiles_FlyingDragons","data/graphics/battles/spells/spelltiles-flyingdragons.bin",file);
    splitSingleChunk(0x12E692,0x12E8C0,"SpellTiles_EnergyBlast","data/graphics/battles/spells/spelltiles-energyblast.bin",file);
    splitSingleChunk(0x12E8C0,0x12E99E,"SpellTiles_Laser","data/graphics/battles/spells/spelltiles-laser.bin",file);
    splitSingleChunk(0x12E99E,0x12EDC2,"SpellTiles_LightningBreath","data/graphics/battles/spells/spelltiles-lightningbreath.bin",file);
    splitSingleChunk(0x12EDC2,0x12EEBE,"SpellTiles_BusterShot","data/graphics/battles/spells/spelltiles-bustershot.bin",file);
    splitSingleChunk(0x12EEBE,0x12F0FE,"SpellTiles_FireBreath","data/graphics/battles/spells/spelltiles-firebreath.bin",file);
    splitSingleChunk(0x12F0FE,0x12F2E2,"SpellTiles_DemonBlaze","data/graphics/battles/spells/spelltiles-demonblaze.bin",file);
    //splitSingleChunk(0x12F2E2,0x12F502,"byte_12F2E2","data/graphics/",file);
    //splitSingleChunk(0x12F502,0x12F70E,"byte_12F502","data/graphics/",file);
    //splitSingleChunk(0x12F70E,0x12F8E2,"byte_12F70E","data/graphics/",file);
    splitSingleChunk(0x12F8E2,0x12F938,"tiles_ChapterEnd","data/graphics/specialscreens/chapterscreen/chapterendtiles.bin",file);
    splitSingleChunk(0x12F938,0x12FE16,"tiles_IntroSpeckOfLight","data/graphics/specialscreens/intro/introspeckoflighttiles.bin",file);
    MakeAlign(0x12FE16, 0x130000-0x12FE16,15);
    
    
    //Section 14 : 0x130000-0x144000
    
    //splitSingleChunk(0x130464,0x13048E,"layout_PressStartButton","data/graphics/specialscreens/titlescreen/pressstartbuttonlayout.bin",file);
    //splitSingleChunk(0x130740,0x130762,"byte_13100A","data/",file);
    //splitSingleChunk(0x130762,0x130784,"byte_130762","data/",file);
    //splitSingleChunk(0x130784,0x1307A6,"byte_130784","data/",file);
    //splitSingleChunk(0x1307A6,0x1307C8,"byte_1307A6","data/",file);
    //splitSingleChunk(0x1307C8,0x1307EA,"byte_1307C8","data/",file);
    //splitSingleChunk(0x1307EA,0x13080C,"byte_1307EA","data/",file);
    //splitSingleChunk(0x13080C,0x13082E,"byte_13080C","data/",file);
    //splitSingleChunk(0x13082E,0x130850,"byte_13082E","data/",file);
    //splitSingleChunk(0x130850,0x13089A,"byte_130850","data/",file);
    //splitSingleChunk(0x13089A,0x13091C,"byte_13089A","data/",file);
    //splitSingleChunk(0x13091C,0x130A3E,"byte_13091C","data/",file);
    //splitSingleChunk(0x130A3E,0x130C40,"byte_130A3E","data/",file);
    //splitSingleChunk(0x130C40,0x13100A,"byte_130C40","data/",file);
    //splitSingleChunk(0x13100A,0x131110,"byte_13100A","data/",file);
    //splitSingleChunk(0x131110,0x131216,"byte_131110","data/",file);
    //splitSingleChunk(0x131216,0x13131C,"byte_131216","data/",file);
    //splitSingleChunk(0x13131C,0x131422,"byte_13131C","data/",file);
    //splitSingleChunk(0x131422,0x131528,"byte_131422","data/",file);
    //splitSingleChunk(0x131528,0x13162E,"byte_131528","data/",file);
    //splitSingleChunk(0x13171C,0x131A1C,"byte_13171C","data/",file);
    MakeAlign(0x13E92A, 0x144000-0x13E92A,15);
    
    
    //Section 15 : 0x144000-0x164000
    
    splitSingleChunk(0x16186E,0x161A66,"WeaponPalettes","data/graphics/battles/weapons/palettes/weaponpalettes.bin",file);
    
    
    //Section 16 : 0x164000-0x168000
    
    //splitSingleChunk(0x1640C0,0x1640C8,"unk_1640C0","data/",file);
    //splitSingleChunk(0x1640C8,0x1640D0,"unk_1640C8","data/",file);
    //splitSingleChunk(0x1640D0,0x1640D8,"unk_1640D0","data/",file);
    //splitSingleChunk(0x1640D8,0x164100,"unk_1640D8","data/",file);
    //splitSingleChunk(0x1644EA,0x1644F6,"byte_1644EA","data/",file);
    //splitSingleChunk(0x164990,0x1649CC,"layout_164990","data/graphics/tech/windowlayouts/164990.bin",file);
    splitSingleChunk(0x1649CC,0x164A0A,"tiles_TextHighlight","data/graphics/tech/texthighlighttiles.bin",file);
    //splitSingleChunk(0x164A0A,0x164A12,"byte_164A0A","data/",file);
    //splitSingleChunk(0x164A32,0x164A37,"unk_164A32","data/",file);
    //splitSingleChunk(0x164A37,0x164A3D,"unk_164A37","data/",file);
    //splitSingleChunk(0x164A3D,0x164A42,"unk_164A3D","data/",file);
    //splitSingleChunk(0x164A42,0x164A48,"unk_164A42","data/",file);
    //splitSingleChunk(0x164A48,0x164A4B,"unk_164A48","data/",file);
    //splitSingleChunk(0x164A4B,0x164A4E,"unk_164A4B","data/",file);
    //splitSingleChunk(0x164A4E,0x164A51,"unk_164A4E","data/",file);
    //splitSingleChunk(0x164A51,0x164A54,"unk_164A51","data/",file);
    //splitSingleChunk(0x164A54,0x164A58,"unk_164A54","data/",file);
    //splitSingleChunk(0x164A58,0x164AD4,"byte_164A58","data/",file);
    //splitSingleChunk(0x164AD4,0x164C74,"byte_164AD4","data/",file);
    //splitSingleChunk(0x164C74,0x164D92,"byte_164C74","data/graphics/",file);
    //splitSingleChunk(0x164D92,0x165152,"unk_164D92","data/",file);
    splitSingleChunk(0x165152,0x1662BA,"tiles_Simone1","data/graphics/specialscreens/readerscreen/simonetiles1.bin",file);
    splitSingleChunk(0x1662BA,0x166400,"tiles_Simone2","data/graphics/specialscreens/readerscreen/simonetiles2.bin",file);
    //splitSingleChunk(0x166400,0x166980,"byte_166400","data/",file);
    splitSingleChunk(0x166980,0x1672B4,"tiles_Simone3","data/graphics/specialscreens/readerscreen/simonetiles3.bin",file);
    //splitSingleChunk(0x1672B4,0x1673CC,"byte_1672B4","data/",file);
    //splitSingleChunk(0x1673CC,0x1674E4,"byte_1673CC","data/",file);
    splitSingleChunk(0x16761C,0x16763C,"palette_SegaLogo","data/graphics/tech/segalogopalette.bin",file);
    splitSingleChunk(0x16763C,0x167B12,"tiles_SegaLogo","data/graphics/tech/segalogotiles.bin",file);
    //splitSingleChunk(0x167B12,0x167B1A,"word_167B12","data/",file);
    //splitSingleChunk(0x167B1A,0x167E87,"byte_167B1A","data/",file);
    //splitSingleChunk(0x167E87,0x167E94,"byte_167E87","data/",file);
    splitSingleChunk(0x167F02,0x167F9C,"SegaLogoColors","data/graphics/tech/segalogocolors.bin",file);
    MakeAlign(0x167FEA, 0x168000-0x167FEA,15);
    
    
    //Section 17 : 0x168000-0x180000
    
    splitSingleChunk(0x168000, 0x170000, "","data/sound/pcmbank0.bin",file);
    splitSingleChunk(0x170000, 0x176000, "","data/sound/musicbank0.bin",file);
    splitSingleChunk(0x176000, 0x178000, "","data/sound/sounddriver.bin",file);
    splitSingleChunk(0x178000, 0x178AE0, "","data/sound/instruments.bin",file);
    splitSingleChunk(0x178AE0, 0x180000, "","data/sound/musicbank1.bin",file);
    
}

static splitSingleChunk(start, end, nameString, binPath, splitFile){
    auto j;
    //Message("Cleaning from %a to %a ...\n",start,end);
    for(j=start+1;j<end;j++){undefineByte(j);}
    MakeData(start,FF_BYTE,end-start,1);
    if(nameString!=""){
        MakeNameEx(start,nameString,0);
    }
    SetManualInsn   (start, form("incbin \"%s\"",binPath));
    writestr(splitFile,form("#split\t0x%s,0x%s,%s\n",ltoa(start,16),ltoa(end,16),binPath));
    //Jump(start);
}

static splitSingleChunkWithCommentedSplitEntry(start, end, nameString, binPath, splitFile){
    auto j;
    //Message("Cleaning from %a to %a ...\n",start,end);
    for(j=start+1;j<end;j++){undefineByte(j);}
    MakeData(start,FF_BYTE,end-start,1);
    MakeNameEx(start,nameString,0);
    SetManualInsn   (start, form("incbin \"%s\"",binPath));
    writestr(splitFile,form("/*#split\t0x%s,0x%s,%s*/\n",ltoa(start,16),ltoa(end,16),binPath));
    //Jump(start);
}

static splitChunksWithGapInBetween(start, end, chunkSize, gapSize, nameString, binDir, binName, indexLength, file) {
    auto i,j,index;
    auto addr,action;
    i = 0;
    addr = start;
    action=1;
    if(nameString!=""){
        MakeNameEx(start,nameString,0);
    }
    while(addr!=end&&action==1){
        //Message("Cleaning from %a to %a ...\n",addr,addr+chunkSize);
        for(j=addr+1;j<addr+chunkSize;j++){undefineByte(j);}
        MakeData(addr,FF_BYTE,chunkSize,1);
        index = ltoa(i,10);
        while(strlen(index)<indexLength){
            index=form("0%s",index);
        }
        SetManualInsn   (addr, form("incbin \"%s%s%s.bin\"",binDir,binName,index));
        writestr(file,form("#split\t0x%s,0x%s,%s%s%s.bin\n",ltoa(addr,16),ltoa(addr+chunkSize,16),binDir,binName,index));
        i++;
        addr=addr+chunkSize+gapSize;
        //action = AskYN(1,"Ok ?");
    }
}


/*
 *    Split one simple pointer table
 */
static splitPT(start, end, lastEntryDataEnd, chunkEnd, ptName, entryName, binDir, binName, indexLength, align, file) {
    auto i,j,x,s,index,path;
    auto addr,dataEnd,from,dref,section,action;
    i = 0;
    addr = start;
    action=1;
    Message("\n    Pointer table %s ...",ptName);    
    //Jump(start);
    // Cleaning whole chunk
    //Message("Cleaning from %a to %a ...\n",start,chunkEnd);
    for(j=start;j<chunkEnd;j++){undefineByte(j);}
    // Naming pointer table
    MakeNameEx(addr,ptName,0);
    // Prepare whole chunk with new names and Data XRefs
    while(addr<end&&action==1){
        MakeDword(addr);
        dref = Dword(addr);
        add_dref(addr,dref,dr_O);
        dref = Dfirst(addr);        
        //Jump(dref);
        index = ltoa(i,10);
        while(strlen(index)<indexLength){
            index=form("0%s",index);
        }
        if(strstr(GetTrueName(dref),entryName)==-1){
            if(isUnknown(dref)){ 
            }
            else{
                //Jump(dref);
                //action = AskYN(1,"Ok ?");
                MakeByte(dref);
            }
            MakeNameExC(dref,form("%s%s",entryName,index),0); 
            //Message("\nNamed %a : %s%s",dref,entryName,index);
            i++;
        }
        addr=addr+4;
    }
    /*
     *    Each entry is delimited by its address and the next DATA XRef coming from current chunk
     *    It can then be made into data and replaced by an incbin manual instruction.
     */
    i = 0;
    addr = start;
    while(addr!=end&&action==1){
        dref = Dfirst(addr);        
        //Jump(dref); 
        dataEnd = 0;
        j = dref+1;
        // Finding entry's data end
        while(dataEnd==0){
            from = DfirstB(j);
            while(from!=BADADDR){
                if(from>=start&&from<chunkEnd){
                    dataEnd = j;
                }
          from=DnextB(addr,from);      
            }
            j++;
            if(j==lastEntryDataEnd) dataEnd = lastEntryDataEnd;
        }
        index = ltoa(i,10);
        while(strlen(index)<indexLength){
            index=form("0%s",index);
        }
        //Message(form("Processing entry %s%s from %s, to %s\n",entryName,index,ltoa(dref,16),ltoa(dataEnd,16)));
        MakeData(dref,FF_BYTE,dataEnd-dref,1);
        if(strstr(GetDisasm(dref),"incbin")==-1){        
            SetManualInsn   (dref, form("incbin \"%s%s%s.bin\"",binDir,binName,index));
            writestr(file,form("#split\t0x%s,0x%s,%s%s%s.bin\n",ltoa(dref,16),ltoa(dataEnd,16),binDir,binName,index));
            i++;
        }
        addr=addr+4;
        //action = AskYN(1,"Ok ?");
    }
    // Put align instruction for padding until chunkEnd
    if(align!=0)MakeAlign(lastEntryDataEnd,chunkEnd-lastEntryDataEnd,align);
}


static splitMaps(file) {
    auto i,j,x,s,index,path;
    auto start,end,lastEntryDataEnd,chunkEnd,addr,dataEnd,from,dref,section,action;
    i = 0;
    start = 0x820CC;
    end = 0x8264C;
    addr = start;
    lastEntryDataEnd = 0xB97F4;
    chunkEnd = 0xB97F4;
    action=1;
    Message("Cleaning from %a to %a ...\n",start,chunkEnd);    
    for(j=start;j<chunkEnd;j++){undefineByte(j);}
    MakeNameEx(addr,"pt_Maps",0);
    while(addr<end&&action==1){
        MakeDword(addr);
        MakeDword(addr+4);
        MakeDword(addr+8);
        MakeDword(addr+12);
        MakeDword(addr+16);
        MakeDword(addr+20);
        MakeData(addr+24, FF_BYTE, 0x1, 0);
        MakeData(addr+25, FF_BYTE, 0x1, 0);
        MakeData(addr+26, FF_BYTE, 0x1, 0);
        MakeData(addr+27, FF_BYTE, 0x1, 0);
        MakeData(addr+28, FF_BYTE, 0x1, 0);    
        MakeData(addr+29, FF_BYTE, 0x1, 0);    
        MakeData(addr+30, FF_BYTE, 0x1, 0);    
        MakeData(addr+31, FF_BYTE, 0x1, 0);    
        MakeData(addr+32, FF_BYTE, 0x1, 0);        
        
        index = ltoa(i,10);
        if(strlen(index)==1)index=form("0%s",index);
        
        writestr(file,form("#dir\tdata/maps/entries/map%s\n",index));
        
        for(s=0;s!=6;s++){
            from = addr+4*s;
            MakeDword(from);
            section = Dword(from);
            add_dref(from,section,dr_O);
            MakeNameExC(section,form("Map%sSection%d",index,s),0);
        }        
        addr=addr+32;
        i++;
    }
    
    i = 0;
    addr = start;
    while(addr!=end&&action==1){    
        for(s=0;s!=6;s++){
            section = Dfirst(addr+4*s);
            if(section!=BADADDR){
                dataEnd = 0;
                j = section+1;
                while(dataEnd==0){
                    from = DfirstB(j);
                    while(from!=BADADDR){
                        if(from>=start&&from<chunkEnd){
                            dataEnd = j;
                        }
                  from=DnextB(addr,from);      
                    }
                    j++;
                    if(j==lastEntryDataEnd) dataEnd = lastEntryDataEnd;
                }
                index = ltoa(i,10);
                if(strlen(index)==1)index=form("0%s",index);
                //Message(form("Processing Map%s section%d at %s, dataEnd %s\n",index,s,ltoa(section,16),ltoa(dataEnd,16)));
                MakeData(section,FF_BYTE,dataEnd-section,1);
                if(strstr(GetDisasm(section),"incbin")==-1){                        
                    SetManualInsn   (section, form("incbin \"data/maps/entries/map%s/section%d.bin\"",index,s));
                    writestr(file,form("#split\t0x%s,0x%s,data/maps/entries/map%s/section%d.bin\n",ltoa(section,16),ltoa(dataEnd,16),index,s));
                }
            }
        }
        addr=addr+32;
        i++;
        //action = AskYN(1,"Ok ?");
    }
    
}


static splitMapTilesets(file) {

    auto i,j,x,s,index,path;
    auto start,end,lastEntryDataEnd,chunkEnd,addr,dataEnd,from,dref,section,action;
    i = 0;
    start = 0x5801C;
    end = 0x580B8;
    addr = start;
    lastEntryDataEnd = 0x7F344;
    chunkEnd = 0x7F344;
    action=1;
    //Message("Cleaning from %a to %a ...\n",start,chunkEnd);        
    for(j=start;j<chunkEnd;j++){undefineByte(j);}
    MakeNameEx(addr,"pt_MapTilesets",0);
    while(addr<end&&action==1){
        MakeDword(addr);
        dref = Dword(addr);
        add_dref(addr,dref,dr_O);
        dref = Dfirst(addr);        
        //Jump(dref);
        index = ltoa(i,10);
        if(strlen(index)==1)index=form("0%s",index);
        if((dref>=end)&&(strstr(GetTrueName(dref),"MapTileset")==-1)){        
            MakeNameEx(dref,form("MapTileset%s",index),0);
        }
        addr=addr+4;
        i++;
    }
    i = 0;
    addr = start;
    while(addr!=end&&action==1){
        dref = Dfirst(addr);        
        //Jump(dref); 
        dataEnd = 0;
        j = dref+1;
        while(dataEnd==0){
            from = DfirstB(j);
            while(from!=BADADDR){
                if(from>=start&&from<chunkEnd){
                    dataEnd = j;
                }
          from=DnextB(addr,from);      
            }
            j++;
            if(j==lastEntryDataEnd) dataEnd = lastEntryDataEnd;
        }
        index = ltoa(i,10);
        if(strlen(index)==1)index=form("0%s",index);
        //Message(form("dref %s, dataEnd %s\n",ltoa(dref,16),ltoa(dataEnd,16)));
        if((dref>=end)&&(strstr(GetDisasm(dref),"incbin")==-1)){
            MakeData(dref,FF_BYTE,dataEnd-dref,1);
            SetManualInsn   (dref, form("incbin \"data/graphics/maps/maptilesets/maptileset%s.bin\"",index));
            writestr(file,form("#split\t0x%s,0x%s,data/graphics/maps/maptilesets/maptileset%s.bin\n",ltoa(dref,16),ltoa(dataEnd,16),index));
        }
        addr=addr+4;
        i++;
        //action = AskYN(1,"Ok ?");
    }
    
    MakeAlign(lastEntryDataEnd, chunkEnd-lastEntryDataEnd,15);

}



static splitTextbanks(file) {
    auto i,j,x,s,index,path;
    auto start,end,lastEntryDataEnd,chunkEnd,addr,dataEnd,from,dref,section,action;
    i = 0;
    start = 0x13E906;
    end = 0x13E92A;
    addr = start;
    lastEntryDataEnd = 0x13E906;
    chunkEnd = 0x13E92A;
    action=1;
    //Message("Cleaning from %a to %a ...\n",start,chunkEnd);        
    for(j=0x131A1C;j<chunkEnd;j++){undefineByte(j);}
    MakeNameEx(addr,"pt_TextBanks",0);
    while(addr<end&&action==1){
        MakeDword(addr);
        dref = Dword(addr);
        add_dref(addr,dref,dr_O);
        dref = Dfirst(addr);        
        //Jump(dref);
        index = ltoa(i,10);
        if(strlen(index)==1)index=form("0%s",index);
        MakeNameEx(dref,form("TextBank%s",index),0);
        addr=addr+4;
        i++;
    }
    i = 0;
    addr = start;
    while(addr!=end&&action==1){
        dref = Dfirst(addr);        
        //Jump(dref); 
        dataEnd = 0;
        j = dref+1;
        while(dataEnd==0){
            from = DfirstB(j);
            while(from!=BADADDR){
                if(from>=start&&from<chunkEnd){
                    dataEnd = j;
                }
          from=DnextB(addr,from);      
            }
            j++;
            if(j==lastEntryDataEnd) dataEnd = lastEntryDataEnd;
        }
        index = ltoa(i,10);
        if(strlen(index)==1)index=form("0%s",index);
        //Message(form("dref %s, dataEnd %s\n",ltoa(dref,16),ltoa(dataEnd,16)));
        MakeData(dref,FF_BYTE,dataEnd-dref,1);
        SetManualInsn   (dref, form("incbin \"data/scripting/text/textbank%s.bin\"",index));
        writestr(file,form("#split\t0x%s,0x%s,data/scripting/text/textbank%s.bin\n",ltoa(dref,16),ltoa(dataEnd,16),index));
        addr=addr+4;
        i++;
        //action = AskYN(1,"Ok ?");
    }
}



static MakeNameExC(addr,name,flags){

    auto current;
    current = GetTrueName(addr);
    if(current=="" || strstr(current,"unk_")!=-1 || strstr(current,"byte_")!=-1 || strstr(current,"word_")!=-1 || strstr(current,"dword_")!=-1 || strstr(current,"off_")!=-1){
        MakeNameEx(addr,name,flags);
    }

}




/* 
 *    Makes sure byte at addr is
 *    clean for new formatting
 */
static undefineByte(addr){
        auto from;
        from = DfirstB(addr);
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
        MakeUnkn(addr,DOUNK_DELNAMES);
        MakeNameEx(addr,"",0);
        SetManualInsn(addr,"");
}




