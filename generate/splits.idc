

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
	
	writestr(file,"\nsplit	0x0,0x0,\\0x0 - .bin\n");
	fclose(file);
	Message("END OF SPLITS.\n");	
	
}



static initFile(file){
writestr(file,"/***********************Directories***************************/\n");
writestr(file,"#dir	data/\n");
writestr(file,"#dir	data/battles/\n");
writestr(file,"#dir	data/battles/battleexits\n");
writestr(file,"#dir	data/battles/global\n");
writestr(file,"#dir	data/battles/entries\n");
writestr(file,"#dir	data/graphics/\n");
writestr(file,"#dir	data/graphics/battles/\n");
writestr(file,"#dir	data/graphics/battles/backgrounds\n");
writestr(file,"#dir	data/graphics/battles/battlesprites/\n");
writestr(file,"#dir	data/graphics/battles/battlesprites/allies/\n");
writestr(file,"#dir	data/graphics/battles/battlesprites/allies/animations\n");
writestr(file,"#dir	data/graphics/battles/battlesprites/enemies/\n");
writestr(file,"#dir	data/graphics/battles/battlesprites/enemies/animations\n");
writestr(file,"#dir	data/graphics/battles/platforms\n");
writestr(file,"#dir	data/graphics/battles/spells\n");
writestr(file,"#dir	data/graphics/battles/spells/palettes\n");
writestr(file,"#dir	data/graphics/battles/statuseffects\n");
writestr(file,"#dir	data/graphics/battles/weapons\n");
writestr(file,"#dir	data/graphics/maps/\n");
writestr(file,"#dir	data/graphics/maps/maptilesets\n");
writestr(file,"#dir	data/graphics/maps/tileanimations\n");
writestr(file,"#dir	data/graphics/mapsprites\n");
writestr(file,"#dir	data/graphics/portraits\n");
writestr(file,"#dir	data/graphics/specialsprites\n");
writestr(file,"#dir	data/graphics/specialscreens/\n");
writestr(file,"#dir	data/graphics/specialscreens/chapterscreens\n");
writestr(file,"#dir	data/graphics/specialscreens/ending\n");
writestr(file,"#dir	data/graphics/specialscreens/intro\n");
writestr(file,"#dir	data/graphics/specialscreens/readerscreen\n");
writestr(file,"#dir	data/graphics/specialscreens/soundtest\n");
writestr(file,"#dir	data/graphics/specialscreens/titlescreen\n");
writestr(file,"#dir	data/graphics/icons\n");
writestr(file,"#dir	data/graphics/tech/\n");
writestr(file,"#dir	data/graphics/tech/menus\n");
writestr(file,"#dir	data/graphics/tech/fonts\n");
writestr(file,"#dir	data/graphics/tech/palettes\n");
writestr(file,"#dir	data/graphics/tech/windowlayouts\n");
writestr(file,"#dir	data/graphics/tech/windowlayouts/miscmessages\n");
writestr(file,"#dir	data/graphics/introtiles\n");
writestr(file,"#dir	data/maps/\n");
writestr(file,"#dir	data/maps/global\n");
writestr(file,"#dir	data/maps/entries\n");
writestr(file,"#dir	data/maps/spritesets\n");
writestr(file,"#dir	data/scripting/\n");
writestr(file,"#dir	data/scripting/cutscenes\n");
writestr(file,"#dir	data/scripting/mapspritescripts\n");
writestr(file,"#dir	data/scripting/text\n");
writestr(file,"#dir	data/sound/\n");
writestr(file,"#dir	data/stats/\n");
writestr(file,"#dir	data/stats/allies\n");
writestr(file,"#dir	data/stats/classes\n");
writestr(file,"#dir	data/stats/effects\n");
writestr(file,"#dir	data/stats/enemies\n");
writestr(file,"#dir	data/stats/items\n");
writestr(file,"#dir	data/stats/spells\n");
writestr(file,"#dir	data/stats/ranges\n");
writestr(file,"\n");
writestr(file,"/***********************Data***************************/\n");
writestr(file,"\n");
}



/*
 *	Split simple pointer tables
 */
static splitPTs(file){

	/*	Template
	 *	splitPT(start, end, lastEntryDataEnd, chunkEnd, "ptName", "entryName", "binDir", "binName", indexLength, align, file);
	 */
	
    //splitPT(0xC362, 0xC3A2, 0xB6F4, 0xB6F4, "pt_SpellLevelBarLayouts", "SpellLevelBarLayout", "data/graphics/", "spelllevelbarlayout", 2, 0, file);
    splitPT(0xD39A, 0xD3BE, 0xD75A, 0xD75A, "pt_MiscMessageWindowLayouts", "MiscMessageWindowLayout", "data/graphics/tech/windowlayouts/miscmessages/", "miscmessagewindowlayout", 1, 0, file);
    
	splitPT(0x1D3B2, 0x1D3D2, 0x1D68E, 0x1D68E, "pt_BattleExits", "BattleExit", "data/battles/battleexits/", "battleexit", 1, 0, file);
	splitPT(0x1DF28, 0x1DF68, 0x1E37A, 0x1E37A, "pt_IntroTiles", "IntroTile", "data/graphics/introtiles/", "introtile", 2, 0, file);
    
	splitPT(0x2D13E, 0x2D20E, 0x37B38, 0x38000, "pt_Portraits", "Portrait", "data/graphics/portraits/", "portrait", 2, 15, file);
    splitPT(0x39928, 0x3A0A8, 0x57F5F, 0x58000, "pt_MapSprites", "MapSprite", "data/graphics/mapsprites/", "mapsprite", 3, 15, file);
    
	splitPT(0x80010, 0x800E8, 0x80EE0, 0x80EE0, "pt_SpriteSets", "SpriteSet", "data/maps/spritesets/", "mapspriteset", 2, 0, file);
	splitPT(0x80EFE, 0x811AE, 0x820CC, 0x820CC, "pt_MapSpriteScripts", "MapSpriteScript", "data/scripting/mapspritescripts/", "mapspritescript", 2, 0, file);
    
    splitPT(0xB97F4, 0xB980C, 0xBA3ED, 0xBC000, "pt_TileAnimations", "TileAnimation", "data/graphics/maps/tileanimations/", "tileanimation", 1, 14, file);
    
    splitPT(0xC0068, 0xC0088, 0xCB8C7, 0xCC000, "pt_ChapterScreens", "ChapterScreen", "data/graphics/specialscreens/chapterscreens/", "chapterscreen", 1, 14, file);
	splitPT(0xD398E, 0xD3AC6, 0xFFD3D, 0x100000, "pt_Backgrounds", "Background", "data/graphics/battles/backgrounds/", "background", 2, 15, file);
    
	splitPT(0x100008, 0x1000D0, 0x122252, 0x122252, "pt_EnemyBattleSprites", "EnemyBattleSprite", "data/graphics/battles/battlesprites/enemies/", "enemybattlesprite", 2, 0, file);
	splitPT(0x122252, 0x12236E, 0x122758, 0x124000, "pt_EnemyAnimations", "EnemyAnimation", "data/graphics/battles/battlesprites/enemies/animations/", "enemyanimation", 3, 14, file);
	
	splitPT(0x144014, 0x1440A0, 0x1602E2, 0x1602E2, "pt_AllyBattleSprites", "AllyBattleSprite", "data/graphics/battles/battlesprites/allies/", "allybattlesprite", 2, 0, file);
	splitPT(0x1602E2, 0x16035E, 0x16186E, 0x16186E, "pt_WeaponSprites", "WeaponSprite", "data/graphics/battles/weapons/", "weaponsprite", 2, 0, file);
	splitPT(0x161A66, 0x161B52, 0x16226A, 0x16226A, "pt_AllyAnimations", "AllyAnimation", "data/graphics/battles/battlesprites/allies/animations/", "allyanimation", 3, 0, file);
	splitPT(0x16226A, 0x162296, 0x163FFA, 0x164000, "pt_Platforms", "Platform", "data/graphics/battles/platforms/", "platform", 2, 14, file);
    
}

static splitSingleChunks(file) {
	auto i,j,x,s,index,path;
	auto start,base,addr,end,dref,section,action;
	
	// Template : splitSingleChunk(0x,0x,"","",file);
	
	//Section 01 : 0x0-0x8000

    splitSingleChunk(0xB4C,0xB9C,"FadingData","data/graphics/tech/fadingdata.bin",file);
	splitSingleChunk(0x394C,0x39CC,"ReaderScreenPalettes","data/graphics/specialscreens/readerscreen/readerscreenpalettes.bin",file);
    
    //splitSingleChunk(0x39CC,0x3A44,"unk_39CC","data/",file);
    
    splitSingleChunk(0x50E2,0x51D2,"BattleTestTargets","data/battles/global/battletesttargets.bin",file);
    splitSingleChunk(0x530E,0x53B8,"wl_BattleTest","data/graphics/tech/windowlayouts/wl-battletest.bin",file);
    splitSingleChunk(0x53B8,0x5462,"wl_ChapterTest","data/graphics/tech/windowlayouts/wl-chaptertest.bin",file);
    splitSingleChunk(0x5462,0x550C,"wl_MessageTest","data/graphics/tech/windowlayouts/wl-messagetest.bin",file);
	splitSingleChunk(0x57EA,0x5A18,"MenuTiles_YesNo","data/graphics/tech/menus/menutiles-yesno.bin",file);
    
    //splitSingleChunk(0x69D4,0x6A2E,"byte_69D4","data/",file);    // HQ Positions
    //splitSingleChunk(0x73EE,0x740E,"word_73EE","data/",file);
    //splitSingleChunk(0x740E,0x758E,"unk_740E","data/",file);
    //splitSingleChunk(0x758E,0x7594,"unk_758E","data/",file);
    //splitSingleChunk(0x75A0,0x75E8,"asc_75A0","data/",file);
    
    splitSingleChunk(0x75E8,0x76C0,"wl_EquipMenuStats","data/graphics/tech/windowlayouts/wl-equipmenustats.bin",file);
    splitSingleChunk(0x76C0,0x772C,"wl_EquipMenuCharName","data/graphics/tech/windowlayouts/wl-equipmenucharname.bin",file);
    splitSingleChunk(0x772C,0x77A4,"wl_EquipMenuItemName","data/graphics/tech/windowlayouts/wl-equipmenuitemname.bin",file);
    splitSingleChunk(0x7B58,0x7E22,"wl_Options","data/graphics/tech/windowlayouts/wl-options.bin",file);
	MakeAlign(0x7E22, 0x8000-0x7E22,15);


	//Section 02 : 0x8000-0x10000
    
    //splitSingleChunk(0x87A2,0x87AA,"byte_87A2","data/",file);
    //splitSingleChunk(0x8854,0x8914,"CursorData","data/",file);
    
    splitSingleChunk(0x9A0E,0x9A4E,"MapSpritePalettes","data/graphics/tech/palettes/mapspritepalettes.bin",file);
    
    //splitSingleChunk(0x9A4E,0x9A8A,"defined_byte_9A4E","data/",file);
    
    splitSingleChunk(0xB982,0xBDFA,"wl_StatusMain","data/graphics/tech/windowlayouts/wl-statusmain.bin",file);
    splitSingleChunk(0xBDFA,0xBE3A,"wl_StatusGold","data/graphics/tech/windowlayouts/wl-statusgold.bin",file);
    
    //splitSingleChunk(0xCC90,0xCCD8,"unk_CC90","data/",file);
    //splitSingleChunk(0xCCD8,0xCED8,"unk_CCD8","data/",file);
    
    //splitSingleChunk(0xD3BE,0xD408,"wl_MiscMsgNoTarget","data/graphics/tech/windowlayouts/wl-miscmsgnotarget.bin",file);
    //splitSingleChunk(0xD408,0xD44C,"wl_MiscMsgNoMagic","data/graphics/tech/windowlayouts/wl-miscmsgnomagic.bin",file);
    //splitSingleChunk(0xD44C,0xD48A,"wl_MiscMsgNoItem","data/graphics/tech/windowlayouts/wl-miscmsgnoitem.bin",file);
    //splitSingleChunk(0xD48A,0xD4EC,"wl_MiscMsgNotEnoughMP","data/graphics/tech/windowlayouts/wl-miscmsgnotenoughmp.bin",file);
    //splitSingleChunk(0xD4EC,0xD56C,"wl_MiscMsgNoEquippableItem","data/graphics/tech/windowlayouts/wl-miscmsgnoequippableitem.bin",file);
    //splitSingleChunk(0xD56C,0xD5EC,"wl_MiscMsgTheItemLovesYou","data/graphics/tech/windowlayouts/wl-miscmsgtheitemlovesyou.bin",file);
    //splitSingleChunk(0xD5EC,0xD66C,"wl_MiscMsgTheItemIsCursed","data/graphics/tech/windowlayouts/wl-miscmsgtheitemiscursed.bin",file);
    //splitSingleChunk(0xD66C,0xD6E6,"wl_MiscMsgNoKeepTheItem","data/graphics/tech/windowlayouts/wl-miscmsgnokeeptheitem.bin",file);
    //splitSingleChunk(0xD6E6,0xD75A,"wl_MiscMsgYouCantUseIt","data/graphics/tech/windowlayouts/wl-miscmsgyoucantuseit.bin",file);
    
    splitSingleChunk(0xDD1C,0xDDF4,"wl_BattleEquipStats","data/graphics/tech/windowlayouts/wl-battleequipstats.bin",file);
    splitSingleChunk(0xDDF4,0xDEC0,"wl_BattleEquipItemName","data/graphics/tech/windowlayouts/wl-battleequipitemname.bin",file);
    splitSingleChunk(0xDF8C,0xDFEC,"wl_LandEffect","data/graphics/tech/windowlayouts/wl-landeffect.bin",file);
    
    splitSingleChunk(0xE322,0xE3C2,"wl_Portrait1","data/graphics/tech/windowlayouts/wl-portrait1.bin",file);
    splitSingleChunk(0xE3C2,0xE462,"wl_Portrait2","data/graphics/tech/windowlayouts/wl-portrait2.bin",file);
    splitSingleChunk(0xE462,0xE49E,"wl_SpeakerName","data/graphics/tech/windowlayouts/wl-speakername.bin",file);
    
    //splitSingleChunk(0xEBC0,0xEBE0,"unk_EBC0","data/",file);
    //splitSingleChunk(0xEE72,0xEE9A,"unk_EE72","data/",file);
    //splitSingleChunk(0xF06A,0xF0EA,"unk_F06A","data/",file);
    //splitSingleChunk(0xF0EA,0xF1CA,"unk_F0EA","data/",file);
    
    splitSingleChunk(0xF1CA,0xF2D8,"wl_ShopInventory","data/graphics/tech/windowlayouts/wl-shopinventory.bin",file);
    splitSingleChunk(0xF2D8,0xF30E,"wl_F2D8","data/graphics/tech/windowlayouts/wl-f2d8.bin",file);
    splitSingleChunk(0xF30E,0xF344,"wl_F30E","data/graphics/tech/windowlayouts/wl-f30e.bin",file);
    splitSingleChunk(0xF344,0xF364,"ShopIconHighlightTiles","data/graphics/tech/menus/shopiconhighlighttiles.bin",file);
    splitSingleChunk(0xF364,0xF3C8,"wl_ShopItemNameAndPrice","data/graphics/tech/windowlayouts/wl-shopitemnameandprice.bin",file);
    
    //splitSingleChunk(0xF3C8,0xF410,"unk_F3C8","data/",file);
    
    splitSingleChunk(0xF410,0xF43A,"wl_MemberList1","data/graphics/tech/windowlayouts/wl-memberlist1.bin",file);
    splitSingleChunk(0xF43A,0xF464,"wl_MemberList2","data/graphics/tech/windowlayouts/wl-memberlist2.bin",file);
    splitSingleChunk(0xF464,0xF48E,"wl_MemberList3","data/graphics/tech/windowlayouts/wl-memberlist3.bin",file);
    splitSingleChunk(0xF48E,0xF4DE,"wl_ItemMenuItemName","data/graphics/tech/windowlayouts/wl-itemmenuitemname.bin",file);
    
    //splitSingleChunk(0xF4DE,0xF61E,"unk_F4DE","data/",file);
    
	MakeAlign(0xFD58, 0x10000-0xFD58,15);


	//Section 03 : 0x10000-0x20000

    splitSingleChunk(0x11B14,0x11B4A,"MapDialogs","data/maps/global/mapdialogs.bin",file);
    splitSingleChunk(0x12D8A,0x131A4,"MapTeleports","data/maps/global/mapteleports.bin",file);
    splitSingleChunk(0x16F62,0x16F92,"ShopOffsets","data/stats/items/shopoffsets.bin",file);
    splitSingleChunk(0x16F92,0x17028,"ShopData","data/stats/items/shopdata.bin",file);
    splitSingleChunk(0x17BBC,0x17C5E,"SpriteTextSounds","data/scripting/spritetextsounds.bin",file);
    splitSingleChunk(0x17D62,0x17E34,"DialogHeader","data/scripting/dialogheader.bin",file);
    splitSingleChunk(0x1D68E,0x1DA8E,"BattleChests","data/battles/global/battlechests.bin",file);
    
    //splitSingleChunk(0x1E37A,0x1E67A,"byte_1E37A","data/",file);
    //splitSingleChunk(0x1E67A,0x1E712,"byte_1E67A","data/",file);
    //splitSingleChunk(0x1E712,0x1E892,"byte_1E712","data/",file);
    
	splitSingleChunk(0x1E892,0x1EA3A,"TextBankTreesPointers","data/scripting/text/huffmantreeoffsets.bin",file);
	splitSingleChunk(0x1EA3A,0x1EFE0,"TextBankTreeData","data/scripting/text/huffmantrees.bin",file);
	MakeAlign(0x1F068, 0x20000-0x1F068,15);
	

	//Section 04 : 0x20000-0x2C000
    
    //splitSingleChunk(0x206DC,0x207BC,"byte_206DC","data/",file);
    
	splitSingleChunk(0x207CA,0x20802,"TileFlags","data/maps/global/tileflags.bin",file);
	splitSingleChunk(0x20A04,0x20BDC,"EffectData","data/stats/effects/effectdata.bin",file);
    
	//splitSingleChunk(0x20E8C,0x20E96,"ExperienceTable","data/stats/allies/experiencetable.bin",file);
	//splitSingleChunk(0x20F7C,0x20F82,"ElemAttackCritPercents","data/stats/effects/elemattackcritpercents.bin",file);
    
	splitSingleChunk(0x2100C,0x21034,"StatusEffectMsgNumbers","data/stats/effects/statuseffectmsgnumbers.bin",file);
    
	//splitSingleChunk(0x211E2,0x211E6,"ResistancePercents","data/stats/spells/resistancepercents.bin",file);
	//splitSingleChunk(0x21266,0x2126A,"EvasionPercents","data/stats/evasionpercents.bin",file);
    //splitSingleChunk(0x212A2,0x212A6,"UnableToEvadeClasses","data/",file);
	//splitSingleChunk(0x2303A,0x23040,"ItemDrops","data/stats/items/itemdrops.bin",file);
	//splitSingleChunk(0x230EC,0x230EF,"unk_230EC","data/",file);
	//splitSingleChunk(0x230EF,0x230F2,"unk_230EF","data/",file);
    //splitSingleChunk(0x2315C,0x23160,"byte_2315C","data/",file);
    
	splitSingleChunk(0x23178,0x23378,"RangeData","data/stats/ranges/rangedata.bin",file);
    
	//splitSingleChunk(0x2361A,0x2361E,"SpecialAttackPercents","data/stats/effects/specialattackpercents.bin",file);
    
	splitSingleChunk(0x23A1E,0x23A3E,"PromotedPortraits","data/stats/allies/promotedportraits.bin",file);
    
	//splitSingleChunk(0x23ACE,0x23AD6,"OutfitItems","data/stats/items/outfititems.bin",file);
    //splitSingleChunk(0x24002,0x24006,"byte_24002","data/",file);
    //splitSingleChunk(0x24006,0x2401C,"unk_24006","data/",file);
    //splitSingleChunk(0x2409C,0x240BC,"unk_2409C","data/",file);
    //splitSingleChunk(0x240DC,0x240E8,"unk_240DC","data/",file);
    
    splitSingleChunk(0x243AA,0x244CA,"AITargetPriority","data/stats/classes/aitargetpriority.bin",file);
    
	//splitSingleChunk(0x24A38,0x24A44,"word_24A38","data/",file);
	//splitSingleChunk(0x24C98,0x24CA4,"byte_24C98","data/",file);
	//splitSingleChunk(0x24D70,0x24D74,"EndStatusPercents","data/stats/effects/endstatuspercents.bin",file);
    
	splitSingleChunk(0x25154,0x25604,"CharacterData","data/stats/allies/chardata.bin",file);
	splitSingleChunk(0x25604,0x25640,"BattleSpriteData","data/stats/allies/battlespritedata.bin",file);
	splitSingleChunk(0x25640,0x25916,"ItemNames","data/stats/items/itemnames.bin",file);
	splitSingleChunk(0x25916,0x25D06,"ItemData","data/stats/items/itemdata.bin",file);
	splitSingleChunk(0x25D06,0x25D2C,"WeaponSpriteData","data/stats/items/weaponspritedata.bin",file);
	splitSingleChunk(0x25D2C,0x25D6C,"ItemTypes","data/stats/items/itemtypes.bin",file);
	splitSingleChunk(0x25D6C,0x260BC,"ClassNames","data/stats/classes/classnames.bin",file);
	splitSingleChunk(0x260BC,0x26404,"ClassData","data/stats/classes/classdata.bin",file);
	splitSingleChunk(0x26404,0x26466,"SpellNames","data/stats/spells/spellnames.bin",file);
	splitSingleChunk(0x26466,0x26566,"SpellData","data/stats/spells/spelldata.bin",file);
	splitSingleChunk(0x26566,0x265E6,"MoveCostData","data/battles/global/movecostdata.bin",file);
	splitSingleChunk(0x265E6,0x26666,"LandEffectData","data/battles/global/landeffectdata.bin",file);
	splitSingleChunk(0x26666,0x2688E,"ForceAnimationData","data/stats/allies/forceanimationdata.bin",file);
	splitSingleChunk(0x2688E,0x269FE,"EnemyAnimationData","data/stats/enemies/enemyanimationdata.bin",file);
	splitSingleChunk(0x269FE,0x26BF2,"TerrainData","data/battles/global/terraindata.bin",file);
    
	//splitSingleChunk(0x26BF2,0x26BF6,"unk_26BF2","data/",file);
    
	splitSingleChunk(0x26BF6,0x26C1A,"GrowthCurves","data/stats/allies/growthcurves.bin",file);
	splitSingleChunk(0x26C1A,0x26CCE,"StatGrowths","data/stats/allies/statgrowths.bin",file);
	splitSingleChunk(0x26CCE,0x26D70,"PromotedStatGrowths","data/stats/allies/promotedstatgrowths.bin",file);
	splitSingleChunk(0x26D70,0x26E16,"SpellLearningData","data/stats/allies/spelllearningdata.bin",file);
	splitSingleChunk(0x26EE4,0x26F0A,"EndingForceMemberData","data/stats/allies/endingforcememberdata.bin",file);
	splitSingleChunk(0x26F0A,0x26F46,"EndingAnimationSequence","data/stats/allies/endinganimationsequence.bin",file);
	splitSingleChunk(0x2704E,0x2751A,"MapHeaders","data/maps/global/mapheaders.bin",file);
	splitSingleChunk(0x2751C,0x279AC,"EnemyData","data/stats/enemies/enemydata.bin",file);
    
    //splitSingleChunk(0x279AC,0x29EB3,"unk_279AC","data/",file);
    
    splitSingleChunk(0x29EB3,0x2BF85,"BattleData","data/battles/global/battledata.bin",file);
	MakeAlign(0x2BF85, 0x2C000-0x2BF85,14);


	//Section 05 : 0x2C000-0x38000

	splitSingleChunk(0x2C13E,0x2D13E,"VariableWidthFont","data/graphics/tech/fonts/variablewidthfont.bin",file);
	
	
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
    
    
	//Section 07 : 0x58000-0x80000
    
    splitSingleChunk(0x7F344,0x7F548,"SpecialSprite_BurningShip","data/graphics/specialsprites/specialsprite-burningship.bin",file);
    splitSingleChunk(0x7F548,0x7F6FF,"SpecialSprite_Jogurt2","data/graphics/specialsprites/specialsprite-jogurt2.bin",file);
    MakeAlign(0x7F6FF, 0x80000-0x7F6FF,15);
    
    
	//Section 08 : 0x80000-0xBC000
	//Section 09 : 0xBC000-0xC0000
	
    //splitSingleChunk(0xBC2CE,0xBC34E,"byte_BC2CE","data/",file);
    
    splitSingleChunk(0xBC34E,0xBCC40,"SoundTestTiles1","data/graphics/specialscreens/soundtest/soundtesttiles1.bin",file);
    splitSingleChunk(0xBCC40,0xBD5D8,"SoundTestTiles2","data/graphics/specialscreens/soundtest/soundtesttiles2.bin",file);
    splitSingleChunk(0xBD5D8,0xBDC38,"SoundTestTiles3","data/graphics/specialscreens/soundtest/soundtesttiles3.bin",file);
    
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
    
    splitSingleChunk(0xBE470,0xBE510,"wl_SoundTest","data/graphics/tech/windowlayouts/wl-soundtest.bin",file);
    splitSingleChunk(0xBE510,0xBE7D8,"ShiningForceLogo","data/graphics/specialscreens/readerscreen/shiningforcelogo.bin",file);
    
    //splitSingleChunk(0xBE7D8,0xBE8DE,"byte_BE7D8","data/graphics/",file);
    //splitSingleChunk(0xBE8DE,0xBE932,"byte_BE8DE","data/",file);
    //splitSingleChunk(0xBE932,0xBEA56,"byte_BE932","data/",file);
    //splitSingleChunk(0xBEA56,0xBED2A,"byte_BEA56","data/",file);
    //splitSingleChunk(0xBED2A,0xBEDAC,"byte_BED2A","data/",file);
    
	MakeAlign(0xBEDAC, 0xC0000-0xBEDAC,15);


	//Section 10 : 0xC0000-0xCC000
    
    splitSingleChunk(0xC0088,0xC03CE,"EndingTiles_Max1","data/graphics/specialscreens/ending/endingtiles-max1.bin",file);
    splitSingleChunk(0xC03CE,0xC075E,"EndingTiles_Max2","data/graphics/specialscreens/ending/endingtiles-max2.bin",file);
    splitSingleChunk(0xC075E,0xC0B70,"EndingTiles_Max3","data/graphics/specialscreens/ending/endingtiles-max3.bin",file);
    splitSingleChunk(0xC0B70,0xC0F0E,"EndingTiles_Max4","data/graphics/specialscreens/ending/endingtiles-max4.bin",file);
    splitSingleChunk(0xC0F0E,0xC11D0,"EndingTiles_Adam","data/graphics/specialscreens/ending/endingtiles-adam.bin",file);
    splitSingleChunk(0xC11D0,0xC15BE,"EndingTiles_TheEnd","data/graphics/specialscreens/ending/endingtiles-theend.bin",file);
    splitSingleChunk(0xC15BE,0xC163E,"EndingPalette","data/graphics/specialscreens/ending/endingpalette.bin",file);
    splitSingleChunk(0xC163E,0xC18AE,"EndingTiles_Farmer","data/graphics/specialscreens/ending/endingtiles-farmer.bin",file);
    
    splitSingleChunk(0xC18AE,0xC192E,"IntroPalette_Scene1_1","data/graphics/specialscreens/intro/intropalette-scene1-1.bin",file);
    splitSingleChunk(0xC192E,0xC19AE,"IntroPalette_Scene1_2","data/graphics/specialscreens/intro/intropalette-scene1-2.bin",file);
    splitSingleChunk(0xC19AE,0xC24A8,"IntroTiles_Scene1_1","data/graphics/specialscreens/intro/introtiles-scene1-1.bin",file);
    splitSingleChunk(0xC24A8,0xC2E50,"IntroTiles_Scene1_2","data/graphics/specialscreens/intro/introtiles-scene1-2.bin",file);
    splitSingleChunk(0xC2E50,0xC2ED0,"IntroPalette_Scene2","data/graphics/specialscreens/intro/intropalette-scene2.bin",file);
    splitSingleChunk(0xC2ED0,0xC331A,"IntroTiles_Scene2","data/graphics/specialscreens/intro/introtiles-scene2.bin",file);
    splitSingleChunk(0xC331A,0xC339A,"IntroPalette_Scene3","data/graphics/specialscreens/intro/intropalette-scene3.bin",file);
    splitSingleChunk(0xC339A,0xC390E,"IntroTiles_Scene3_1","data/graphics/specialscreens/intro/introtiles-scene3-1.bin",file);
    splitSingleChunk(0xC390E,0xC3F2E,"IntroTiles_Scene3_2","data/graphics/specialscreens/intro/introtiles-scene3-2.bin",file);
    splitSingleChunk(0xC3F2E,0xC3FAE,"IntroPalette_Scene4","data/graphics/specialscreens/intro/intropalette-scene4.bin",file);
    splitSingleChunk(0xC3FAE,0xC4534,"IntroTiles_Scene4_1","data/graphics/specialscreens/intro/introtiles-scene4-1.bin",file);
    splitSingleChunk(0xC4534,0xC4AE4,"IntroTiles_Scene4_2","data/graphics/specialscreens/intro/introtiles-scene4-2.bin",file);
    splitSingleChunk(0xC4AE4,0xC5158,"IntroTiles_Scene4_BG1","data/graphics/specialscreens/intro/introtiles-scene4-bg1.bin",file);
    splitSingleChunk(0xC5158,0xC57C4,"IntroTiles_Scene4_BG2","data/graphics/specialscreens/intro/introtiles-scene4-bg2.bin",file);
    
    splitSingleChunk(0xC57C4,0xC5844,"TitleScreenPalette","data/graphics/specialscreens/titlescreen/titlescreenpalette.bin",file);
    splitSingleChunk(0xC5844,0xC6984,"TitleScreenTiles","data/graphics/specialscreens/titlescreen/titlescreentiles.bin",file);
    splitSingleChunk(0xC6984,0xC7084,"TitleScreenLayout","data/graphics/specialscreens/titlescreen/titlescreenlayout.bin",file);
    
    splitSingleChunk(0xC7084,0xC7104,"ChapterScreensPalette","data/graphics/specialscreens/chapterscreens/chapterscreenspalette.bin",file);
    
    
	//Section 11 : 0xCC000-0x100000
    
    splitSingleChunk(0xCC05E,0xCCB1A,"BaseTiles","data/graphics/tech/basetiles.bin",file);
	splitSingleChunk(0xCCB1A,0xCCFEE,"MenuTiles_Options","data/graphics/tech/menus/menutiles-battleoptions.bin",file);
    splitSingleChunk(0xCCFEE,0xCDD6E,"MenuTiles_Main","data/graphics/tech/menus/menutiles-main.bin",file);
    splitSingleChunk(0xCDD6E,0xCE2FE,"MenuTiles_Item","data/graphics/tech/menus/menutiles-item.bin",file);
    splitSingleChunk(0xCE2FE,0xCE75E,"MenuTiles_Shop","data/graphics/tech/menus/menutiles-shop.bin",file);
    splitSingleChunk(0xCE75E,0xCEC34,"MenuTiles_HQ","data/graphics/tech/menus/menutiles-hq.bin",file);
    splitSingleChunk(0xCEC34,0xCF0EA,"MenuTiles_Church","data/graphics/tech/menus/menutiles-church.bin",file);
	splitSingleChunk(0xCF0EA,0xCFCEA,"SpellIcons","data/graphics/icons/spellicons.bin",file);
	splitSingleChunk(0xCFCEA,0xD2DAA,"ItemIcons","data/graphics/icons/itemicons.bin",file);
	splitSingleChunk(0xD2DAA,0xD2E84,"CursorTiles","data/graphics/tech/cursortiles.bin",file);
    splitSingleChunk(0xD2E84,0xD2EA4,"BasePalette","data/graphics/tech/basepalette.bin",file);
    
	splitSingleChunk(0xD301A,0xD32DA,"wl_TextInput","data/graphics/tech/windowlayouts/wl-textinput.bin",file);
    
    //splitSingleChunk(0xD32DA,0xD3308,"byte_D32DA","data/",file);
    
    splitSingleChunk(0xD3308,0xD398E,"EndingCreditsFont","data/graphics/tech/fonts/endingcreditsfont",file);
    
	
	//Section 12 : 0x100000-0x124000
	//Section 13 : 0x124000-0x130000
    
    //splitSingleChunk(0x12570A,0x125A0A,"unk_12570A","data/",file);
    //splitSingleChunk(0x125A0A,0x125B48,"unk_125A0A","data/",file);
    //splitSingleChunk(0x125B48,0x125C3E,"unk_125B48","data/",file);
    //splitSingleChunk(0x125C3E,0x125D54,"unk_125C3E","data/",file);
    
    splitSingleChunk(0x125D54,0x125F36,"StatusEffectsTiles","data/graphics/battles/statuseffects/statuseffectstiles.bin",file);
    
    //splitSingleChunk(0x125F36,0x125FB4,"unk_125F36","data/",file);
    
	splitSingleChunk(0x1269C6,0x1269EE,"SpellPalette_Bolt","data/graphics/battles/spells/palettes/spellpalette-bolt.bin",file);
	splitSingleChunk(0x126A6C,0x126A76,"SpellPalette_Blaze","data/graphics/battles/spells/palettes/spellpalette-blaze.bin",file);
	splitSingleChunk(0x126B9E,0x126BA8,"SpellPalette_Freeze","data/graphics/battles/spells/palettes/spellpalette-freeze.bin",file);
	splitSingleChunk(0x126C26,0x126C30,"SpellPalette_DemonBlaze","data/graphics/battles/spells/palettes/spellpalette-demonblaze.bin",file);
	splitSingleChunk(0x126C8E,0x126C98,"SpellPalette_Desoul","data/graphics/battles/spells/palettes/spellpalette-desoul.bin",file);
    
	//splitSingleChunk(0x126D1E,0x126D3C,"byte_126D1E","data/",file);
    
	splitSingleChunk(0x126DEA,0x126DFE,"SpellPalette_HealAuraDetox","data/graphics/battles/spells/palettes/spellpalette-healauradetox.bin",file);
	splitSingleChunk(0x126E78,0x126E82,"SpellPalette_MachineGun1","data/graphics/battles/spells/palettes/spellpalette-machinegun1.bin",file);
	splitSingleChunk(0x126E90,0x126E9A,"SpellPalette_MachineGun2","data/graphics/battles/spells/palettes/spellpalette-machinegun2.bin",file);
	splitSingleChunk(0x126EF0,0x126EFA,"SpellPalette_FlyingDragon1","data/graphics/battles/spells/palettes/spellpalette-flyingdragon1.bin",file);
	splitSingleChunk(0x126F4A,0x126F54,"SpellPalette_FlyingDragon2","data/graphics/battles/spells/palettes/spellpalette-flyingdragon2",file);
    splitSingleChunk(0x126F6E,0x126F78,"SpellPalette_ElectricBreath1","data/graphics/battles/spells/palettes/spellpalette-electricbreath1.bin",file);
	splitSingleChunk(0x126FD0,0x126FDA,"SpellPalette_ElectricBreath2","data/graphics/battles/spells/palettes/spellpalette-electricbreath2.bin",file);
	splitSingleChunk(0x126FFE,0x127008,"SpellPalette_Laser1","data/graphics/battles/spells/palettes/spellpalette-laser1.bin",file);
	splitSingleChunk(0x127060,0x12706A,"SpellPalette_Laser2","data/graphics/battles/spells/palettes/spellpalette-laser2.bin",file);
	splitSingleChunk(0x127092,0x12709C,"SpellPalette_BusterShot","data/graphics/battles/spells/palettes/spellpalette-bustershot.bin",file);
	splitSingleChunk(0x1270F4,0x1270FE,"SpellPalette_EnergyWave","data/graphics/battles/spells/palettes/spellpalette-energywave.bin",file);
	splitSingleChunk(0x127182,0x12718C,"SpellPalette_FireBreath","data/graphics/battles/spells/palettes/spellpalette-firebreath.bin",file);
    
	splitSingleChunk(0x12C7B0,0x12CBD0,"SpellTiles_Freeze","data/graphics/battles/spells/spelltiles-freeze.bin",file);
	splitSingleChunk(0x12CBD0,0x12D47E,"SpellTiles_Bolt","data/graphics/battles/spells/spelltiles-bolt.bin",file);
	splitSingleChunk(0x12D47E,0x12DDA2,"SpellTiles_Blaze","data/graphics/battles/spells/spelltiles-blaze.bin",file);
	splitSingleChunk(0x12DDA2,0x12DFEC,"SpellTiles_Status","data/graphics/battles/spells/spelltiles-status.bin",file);
	splitSingleChunk(0x12DFEC,0x12E2FC,"SpellTiles_Desoul","data/graphics/battles/spells/spelltiles-desoul.bin",file);
	splitSingleChunk(0x12E2FC,0x12E5E4,"SpellTiles_HealAuraDetox","data/graphics/battles/spells/spelltiles-healauradetox.bin",file);
	splitSingleChunk(0x12E5E4,0x12E610,"SpellTiles_MachineGun","data/graphics/battles/spells/spelltiles-machinegun.bin",file);
	splitSingleChunk(0x12E610,0x12E692,"SpellTiles_FlyingDragon","data/graphics/battles/spells/spelltiles-flyingdragon.bin",file);
    splitSingleChunk(0x12E692,0x12E8C0,"SpellTiles_EnergyWave","data/graphics/battles/spells/spelltiles-energywave.bin",file);
    splitSingleChunk(0x12E8C0,0x12E99E,"SpellTiles_Laser","data/graphics/battles/spells/spelltiles-laser.bin",file);
    splitSingleChunk(0x12E99E,0x12EDC2,"SpellTiles_ElectricBreath","data/graphics/battles/spells/spelltiles-electricbreath.bin",file);
    splitSingleChunk(0x12EDC2,0x12EEBE,"SpellTiles_BusterShot","data/graphics/battles/spells/spelltiles-bustershot.bin",file);
    splitSingleChunk(0x12EEBE,0x12F0FE,"SpellTiles_FireBreath","data/graphics/battles/spells/spelltiles-firebreath.bin",file);
    splitSingleChunk(0x12F0FE,0x12F2E2,"SpellTiles_DemonBlaze","data/graphics/battles/spells/spelltiles-demonblaze.bin",file);
    
    //splitSingleChunk(0x12F2E2,0x12F502,"byte_12F2E2","data/graphics/",file);
    //splitSingleChunk(0x12F502,0x12F70E,"byte_12F502","data/graphics/",file);
    //splitSingleChunk(0x12F70E,0x12F8E2,"byte_12F70E","data/graphics/",file);
    
    splitSingleChunk(0x12F8E2,0x12F938,"ChapterEndTiles","data/graphics/specialscreens/chapterscreens/chapterendtiles.bin",file);
    
    //splitSingleChunk(0x12F938,0x12FE16,"byte_12F938","data/graphics/specialscreens/intro/",file);
    
	MakeAlign(0x12FE16, 0x130000-0x12FE16,15);
    
    
	//Section 14 : 0x130000-0x144000
    
    splitSingleChunk(0x130464,0x13048E,"wl_PressStartButton","data/graphics/specialscreens/titlescreen/wl-pressstartbutton.bin",file);
    
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

	splitSingleChunk(0x16186E,0x161A66,"WeaponPalettes","data/graphics/battles/weapons/weaponpalettes.bin",file);


	//Section 16 : 0x164000-0x168000
    
    //splitSingleChunk(0x1640C0,0x1640C8,"unk_1640C0","data/",file);
    //splitSingleChunk(0x1640C8,0x1640D0,"unk_1640C8","data/",file);
    //splitSingleChunk(0x1640D0,0x1640D8,"unk_1640D0","data/",file);
    //splitSingleChunk(0x1640D8,0x164100,"unk_1640D8","data/",file);
    
    //splitSingleChunk(0x1644EA,0x1644F6,"byte_1644EA","data/",file);
    
    //splitSingleChunk(0x164990,0x1649CC,"byte_164990","data/",file);
    
    splitSingleChunk(0x1649CC,0x164A0A,"TextHighlightTiles","data/graphics/tech/texthighlighttiles.bin",file);
    
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
    
    splitSingleChunk(0x165152,0x1662BA,"SimoneTiles1","data/graphics/specialscreens/readerscreen/simonetiles1.bin",file);
    splitSingleChunk(0x1662BA,0x166400,"SimoneTiles2","data/graphics/specialscreens/readerscreen/simonetiles2.bin",file);
    
    //splitSingleChunk(0x166400,0x166980,"byte_166400","data/",file);
    
    splitSingleChunk(0x166980,0x1672B4,"SimoneTiles3","data/graphics/specialscreens/readerscreen/simonetiles3.bin",file);
    
    //splitSingleChunk(0x1672B4,0x1673CC,"byte_1672B4","data/",file);
    //splitSingleChunk(0x1673CC,0x1674E4,"byte_1673CC","data/",file);
    
    splitSingleChunk(0x16761C,0x16763C,"SegaLogoPalette","data/graphics/tech/segalogopalette.bin",file);
	splitSingleChunk(0x16763C,0x167B12,"SegaLogoTiles","data/graphics/tech/segalogotiles.bin",file);
    
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


/*
 *	Split one simple pointer table
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
	 *	Each entry is delimited by its address and the next DATA XRef coming from current chunk
	 *	It can then be made into data and replaced by an incbin manual instruction.
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
 *	Makes sure byte at addr is
 *	clean for new formatting
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




