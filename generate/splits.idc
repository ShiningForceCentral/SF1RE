

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
writestr(file,"#dir	data/graphics/battles/weapons\n");
writestr(file,"#dir	data/graphics/maps/\n");
writestr(file,"#dir	data/graphics/maps/maptilesets\n");
writestr(file,"#dir	data/graphics/mapsprites\n");
writestr(file,"#dir	data/graphics/portraits\n");
writestr(file,"#dir	data/graphics/specialsprites\n");
writestr(file,"#dir	data/graphics/specialscreens/\n");
writestr(file,"#dir	data/graphics/specialscreens/intro\n");
writestr(file,"#dir	data/graphics/specialscreens/titlescreen\n");
writestr(file,"#dir	data/graphics/specialscreens/readerscreen\n");
writestr(file,"#dir	data/graphics/specialscreens/chapterscreen\n");
writestr(file,"#dir	data/graphics/specialscreens/ending\n");
writestr(file,"#dir	data/graphics/icons\n");
writestr(file,"#dir	data/graphics/tech/\n");
writestr(file,"#dir	data/graphics/tech/menus\n");
writestr(file,"#dir	data/graphics/tech/fonts\n");
writestr(file,"#dir	data/graphics/tech/palettes\n");
writestr(file,"#dir	data/graphics/tech/windowlayouts\n");
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
	
	splitPT(0x1D3B2, 0x1D3D2, 0x1D68E, 0x1D68E, "pt_BattleExits", "BattleExit", "data/battles/battleexits/", "battleexit", 1, 0, file);
	splitPT(0x1DF28, 0x1DF68, 0x1E37A, 0x1E37A, "pt_IntroTiles", "IntroTile", "data/graphics/introtiles/", "introtile", 2, 0, file);
    
	splitPT(0x2D13E, 0x2D20E, 0x37B38, 0x38000, "pt_Portraits", "Portrait", "data/graphics/portraits/", "portrait", 2, 15, file);
	splitPT(0x39928, 0x3A0A8, 0x57F5F, 0x58000, "pt_MapSprites", "MapSprite", "data/graphics/mapsprites/", "mapsprite", 3, 15, file);
    
	splitPT(0x80010, 0x800E8, 0x80EE0, 0x80EE0, "pt_SpriteSets", "SpriteSet", "data/maps/spritesets/", "mapspriteset", 2, 0, file);
	splitPT(0x80EFE, 0x811AE, 0x820CC, 0x820CC, "pt_MapSpriteScripts", "MapSpriteScript", "data/scripting/mapspritescripts/", "mapspritescript", 2, 0, file);
    
	splitPT(0xD398E, 0xD3AC6, 0xFFD3D, 0x100000, "pt_Backgrounds", "Background", "data/graphics/battles/backgrounds/", "background", 2, 15, file);
	splitPT(0x100008, 0x1000D0, 0x122252, 0x122252, "pt_EnemyBattleSprites", "EnemyBattleSprite", "data/graphics/battles/battlesprites/enemies/", "enemybattlesprite", 2, 0, file);
	splitPT(0x122252, 0x12236E, 0x122758, 0x124000, "pt_EnemiesAnimations", "EnemyBattleSpriteAnimation", "data/graphics/battles/battlesprites/enemies/animations/", "enemybattlespriteanimation", 3, 14, file);
	
	splitPT(0x144014, 0x1440A0, 0x1602E2, 0x1602E2, "pt_AllyBattleSprites", "AllyBattleSprite", "data/graphics/battles/battlesprites/allies/", "allybattlesprite", 2, 0, file);
	splitPT(0x1602E2, 0x16035E, 0x16186E, 0x16186E, "pt_WeaponSprites", "WeaponSprite", "data/graphics/battles/weapons/", "weaponsprite", 2, 0, file);
	splitPT(0x161A66, 0x161B52, 0x16226A, 0x16226A, "pt_AlliesAnimations", "AllyBattleSpriteAnimation", "data/graphics/battles/battlesprites/allies/animations/", "allybattleanimation", 3, 0, file);
	splitPT(0x16226A, 0x162296, 0x163FFA, 0x164000, "pt_Platforms", "Platform", "data/graphics/battles/platforms/", "platform", 2, 14, file);
	
	
	
	
	
}

static splitSingleChunks(file) {
	auto i,j,x,s,index,path;
	auto start,base,addr,end,dref,section,action;
	
	// Template : splitSingleChunk(0x,0x,"","",file);
	
	//Section 01

    splitSingleChunk(0xB4C,0xB9C,"FadingData","data/graphics/tech/fadingdata.bin",file);
	splitSingleChunk(0x394C,0x39CC,"plt_BasePalettes","data/graphics/tech/plt-basepalettes.bin",file);
    
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
    
    splitSingleChunk(0x75E8,0x76C0,"wl_ItemEquipStats","data/graphics/tech/windowlayouts/wl-itemequipstats.bin",file);
    splitSingleChunk(0x76C0,0x772C,"wl_ItemEquipCharName","data/graphics/tech/windowlayouts/wl-itemequipcharname.bin",file);
    splitSingleChunk(0x772C,0x77A4,"wl_ItemEquipItemName","data/graphics/tech/windowlayouts/wl-itemequipitemname.bin",file);
    splitSingleChunk(0x7B58,0x7E22,"wl_Options","data/graphics/tech/windowlayouts/wl-options.bin",file);
	MakeAlign(0x7E22, 0x8000-0x7E22,15);


	//Section 02 - 0x8000

    //splitSingleChunk(0x8854,0x8914,"CursorData","data/",file);
    
    splitSingleChunk(0x9A0E,0x9A4E,"plt_MapSprites","data/graphics/tech/palettes/plt-mapsprites.bin",file);
    
    //splitSingleChunk(0x9A4E,0x9A8A,"defined_byte_9A4E","data/",file);
    
    splitSingleChunk(0xB982,0xBDFA,"wl_StatusMain","data/graphics/tech/windowlayouts/wl-statusmain.bin",file);
    splitSingleChunk(0xBDFA,0xBE3A,"wl_StatusGold","data/graphics/tech/windowlayouts/wl-statusgold.bin",file);
    splitSingleChunk(0xD3BE,0xD408,"wl_MiscMsgNoTarget","data/graphics/tech/windowlayouts/wl-miscmsgnotarget.bin",file);
    splitSingleChunk(0xD408,0xD44C,"wl_MiscMsgNoMagic","data/graphics/tech/windowlayouts/wl-miscmsgnomagic.bin",file);
    splitSingleChunk(0xD44C,0xD48A,"wl_MiscMsgNoItem","data/graphics/tech/windowlayouts/wl-miscmsgnoitem.bin",file);
    splitSingleChunk(0xD48A,0xD4EC,"wl_MiscMsgNotEnoughMP","data/graphics/tech/windowlayouts/wl-miscmsgnotenoughmp.bin",file);
    splitSingleChunk(0xD4EC,0xD56C,"wl_MiscMsgNoEquippableItem","data/graphics/tech/windowlayouts/wl-miscmsgnoequippableitem.bin",file);
    splitSingleChunk(0xD56C,0xD5EC,"wl_MiscMsgTheItemLovesYou","data/graphics/tech/windowlayouts/wl-miscmsgtheitemlovesyou.bin",file);
    splitSingleChunk(0xD5EC,0xD66C,"wl_MiscMsgTheItemIsCursed","data/graphics/tech/windowlayouts/wl-miscmsgtheitemiscursed.bin",file);
    splitSingleChunk(0xD66C,0xD6E6,"wl_MiscMsgNoKeepTheItem","data/graphics/tech/windowlayouts/wl-miscmsgnokeeptheitem.bin",file);
    splitSingleChunk(0xD6E6,0xD75A,"wl_MiscMsgYouCantUseIt","data/graphics/tech/windowlayouts/wl-miscmsgyoucantuseit.bin",file);
    splitSingleChunk(0xDD1C,0xDDF4,"wl_BattleEquipStats","data/graphics/tech/windowlayouts/wl-battleequipstats.bin",file);
    splitSingleChunk(0xDDF4,0xDEC0,"wl_BattleEquipItemName","data/graphics/tech/windowlayouts/wl-battleequipitemname.bin",file);
    splitSingleChunk(0xDF8C,0xDFEC,"wl_LandEffect","data/graphics/tech/windowlayouts/wl-landeffect.bin",file);
    
    splitSingleChunk(0xE322,0xE3C2,"wl_E322","data/graphics/tech/windowlayouts/wl-e322.bin",file);
    splitSingleChunk(0xE3C2,0xE462,"wl_E3C2","data/graphics/tech/windowlayouts/wl-e3c2.bin",file);
    splitSingleChunk(0xE462,0xE49E,"wl_E462","data/graphics/tech/windowlayouts/wl-e462.bin",file);
    splitSingleChunk(0xF1CA,0xF2D8,"wl_F1CA","data/graphics/tech/windowlayouts/wl-f1ca.bin",file);
    splitSingleChunk(0xF2D8,0xF30E,"wl_F2D8","data/graphics/tech/windowlayouts/wl-f2d8.bin",file);
    splitSingleChunk(0xF30E,0xF344,"wl_F30E","data/graphics/tech/windowlayouts/wl-f30e.bin",file);
    
    //splitSingleChunk(0xF344,0xF364,"unk_F344","data/",file);
    
    splitSingleChunk(0xF364,0xF3C8,"wl_F364","data/graphics/tech/windowlayouts/wl-f364.bin",file);
    
    //splitSingleChunk(0xF3C8,0xF410,"unk_F3C8","data/",file);
    
    splitSingleChunk(0xF410,0xF43A,"wl_F410","data/graphics/tech/windowlayouts/wl-f410.bin",file);
    splitSingleChunk(0xF43A,0xF464,"wl_F43A","data/graphics/tech/windowlayouts/wl-f43a.bin",file);
    splitSingleChunk(0xF464,0xF48E,"wl_F464","data/graphics/tech/windowlayouts/wl-f464.bin",file);
    splitSingleChunk(0xF48E,0xF4DE,"wl_F48E","data/graphics/tech/windowlayouts/wl-f48e.bin",file);
    
    //splitSingleChunk(0xF4DE,0xF61E,"unk_F4DE","data/",file);
    
	MakeAlign(0xFD58, 0x10000-0xFD58,15);


	//Section 03 - 0x10000

    splitSingleChunk(0x11B14,0x11B4A,"MapDialogs","data/maps/global/mapdialogs.bin",file);
    splitSingleChunk(0x12D8A,0x131A4,"MapTeleports","data/maps/global/mapteleports.bin",file);
    splitSingleChunk(0x16F62,0x16F92,"ShopOffsets","data/stats/items/shopoffsets.bin",file);
    splitSingleChunk(0x16F92,0x17028,"ShopData","data/stats/items/shopdata.bin",file);
    splitSingleChunk(0x17BBC,0x17C5E,"SpriteTextSounds","data/scripting/spritetextsounds.bin",file);
    splitSingleChunk(0x17D62,0x17E34,"DialogHeader","data/scripting/dialogheader.bin",file);
    splitSingleChunk(0x1D68E,0x1DA8E,"BattleChests","data/battles/global/battlechests.bin",file);
    
    //splitSingleChunk(0x1E37A,0x1E67A,"unk_1E37A","data/",file);
    //splitSingleChunk(0x1E67A,0x1E712,"unk_1E67A","data/",file);
    //splitSingleChunk(0x1E712,0x1E892,"unk_1E712","data/",file);
    
	splitSingleChunk(0x1E892,0x1EA3A,"TextBankTreesPointers","data/scripting/text/huffmantreeoffsets.bin",file);
	splitSingleChunk(0x1EA3A,0x1EFE0,"TextBankTreeData","data/scripting/text/huffmantrees.bin",file);
	MakeAlign(0x1F068, 0x20000-0x1F068,15);
	

	//Section 04 - 0x20000
    
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
    
	splitSingleChunk(0x23178,0x2337A,"RangeData","data/stats/ranges/rangedata.bin",file);
    
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


	//Section 05 - 0x2C000

	splitSingleChunk(0x2C13E,0x2D13E,"VariableWidthFont","data/graphics/tech/fonts/variablewidthfont.bin",file);
	
	
	//Section 06 - 0x38000
    
	//splitSingleChunk(0x38040,0x383A0,"unk_38040","data/graphics/",file);
	//splitSingleChunk(0x383A0,0x38700,"unk_383A0","data/graphics/",file);
	//splitSingleChunk(0x38700,0x38800,"unk_38700","data/graphics/",file);
	//splitSingleChunk(0x38800,0x38900,"unk_38800","data/graphics/",file);
	//splitSingleChunk(0x38900,0x38940,"unk_38900","data/graphics/",file);
	//splitSingleChunk(0x38940,0x38980,"unk_38940","data/graphics/",file);
	//splitSingleChunk(0x38980,0x38A60,"unk_38980","data/graphics/",file);
	//splitSingleChunk(0x38A60,0x38B40,"unk_38A60","data/graphics/",file);
	//splitSingleChunk(0x38B40,0x38CA0,"unk_38B40","data/graphics/",file);
	//splitSingleChunk(0x38CA0,0x38E00,"unk_38CA0","data/graphics/",file);
	//splitSingleChunk(0x38E00,0x39260,"unk_38E00","data/graphics/",file);
	//splitSingleChunk(0x39260,0x396C0,"unk_39260","data/graphics/",file);
	//splitSingleChunk(0x396C0,0x39928,"unk_396C0","data/graphics/",file);
    
    
	//Section 07 - 0x58000
	//Section 08 - 0x80000
    
	//splitSingleChunk(0xB97F4,0xB980C,"TileAnimationBank","data/",file);
	//splitSingleChunk(0xB980C,0xBA3ED,"unk_B980C","data/",file);
	//MakeAlign(0xBA3ED, 0xBC000-0xBA3ED,14);
    
    
	//Section 09 - 0xBC000
	
    splitSingleChunk(0xBE470,0xBE510,"wl_SoundTest","data/graphics/tech/windowlayouts/wl-soundtest.bin",file);
	MakeAlign(0xBEDAC, 0xC0000-0xBEDAC,15);


	//Section 10 - 0xC0000
    
    splitSingleChunk(0xC0088,0xC03CE,"MaxEndingGraphicsFrame1","data/graphics/specialscreens/ending/maxendinggraphicsframe1.bin",file);
    splitSingleChunk(0xC03CE,0xC075E,"MaxEndingGraphicsFrame2","data/graphics/specialscreens/ending/maxendinggraphicsframe2.bin",file);
    splitSingleChunk(0xC075E,0xC0B70,"MaxEndingGraphicsFrame3","data/graphics/specialscreens/ending/maxendinggraphicsframe3.bin",file);
    splitSingleChunk(0xC0B70,0xC0F0E,"MaxEndingGraphicsFrame4","data/graphics/specialscreens/ending/maxendinggraphicsframe4.bin",file);
    splitSingleChunk(0xC0F0E,0xC11D0,"AdamEndingGraphics","data/graphics/specialscreens/ending/adamendinggraphics.bin",file);
    splitSingleChunk(0xC11D0,0xC15BE,"TheEndGraphics","data/graphics/specialscreens/ending/theendgraphics.bin",file);
    splitSingleChunk(0xC15BE,0xC163E,"plt_Ending","data/graphics/tech/palettes/plt-ending.bin",file);
    splitSingleChunk(0xC163E,0xC18AE,"FarmerEndingGraphics","data/graphics/specialscreens/ending/farmerendinggraphics.bin",file);
    
    splitSingleChunk(0xC18AE,0xC192E,"plt_Intro","data/graphics/tech/palettes/plt-intro.bin",file);
    splitSingleChunk(0xC192E,0xC19AE,"plt_Intro2","data/graphics/tech/palettes/plt-intro2.bin",file);
    splitSingleChunk(0xC19AE,0xC24A8,"IntroGraphics","data/graphics/specialscreens/intro/intrographics.bin",file);
    splitSingleChunk(0xC24A8,0xC2E50,"IntroGraphics2","data/graphics/specialscreens/intro/intrographics2.bin",file);
    splitSingleChunk(0xC2E50,0xC2ED0,"plt_IntroSc2","data/graphics/tech/palettes/plt-introsc2.bin",file);
    splitSingleChunk(0xC2ED0,0xC331A,"IntroSc2Graphics","data/graphics/specialscreens/intro/introsc2graphics.bin",file);
    splitSingleChunk(0xC331A,0xC339A,"plt_IntroSc3","data/graphics/tech/palettes/plt-introsc3.bin",file);
    splitSingleChunk(0xC339A,0xC390E,"IntroSc3Graphics","data/graphics/specialscreens/intro/introsc3graphics.bin",file);
    splitSingleChunk(0xC390E,0xC3F2E,"IntroSc3Pt2Graphics","data/graphics/specialscreens/intro/introsc3pt2graphics.bin",file);
    splitSingleChunk(0xC3F2E,0xC3FAE,"plt_IntroSc4","data/graphics/tech/palettes/plt-introsc4.bin",file);
    splitSingleChunk(0xC3FAE,0xC4534,"IntroSc4Graphics","data/graphics/specialscreens/intro/introsc4graphics.bin",file);
    splitSingleChunk(0xC4534,0xC4AE4,"IntroSc4Pt2Graphics","data/graphics/specialscreens/intro/introsc4pt2graphics.bin",file);
    splitSingleChunk(0xC4AE4,0xC5158,"IntroSc4BGGraphics","data/graphics/specialscreens/intro/introsc4bggraphics.bin",file);
    splitSingleChunk(0xC5158,0xC57C4,"IntroSc4Pt2BGGraphics","data/graphics/specialscreens/intro/introsc4pt2bggraphics.bin",file);
    
    splitSingleChunk(0xC57C4,0xC5844,"plt_TitleScreen","data/graphics/tech/palettes/plt-titlescreen.bin",file);
    splitSingleChunk(0xC5844,0xC6984,"TitleScreenGraphics","data/graphics/specialscreens/titlescreen/titlescreengraphics.bin",file);
    //splitSingleChunk(0xC6984,0xC7084,"unk_C6984","data/",file);
    
    splitSingleChunk(0xC7084,0xC7104,"plt_ChapterScreen","data/graphics/tech/palettes/plt-chapterscreen.bin",file);
    splitSingleChunk(0xC7104,0xC799A,"Chapter1Graphics","data/graphics/specialscreens/chapterscreen/chapter1graphics.bin",file);
    splitSingleChunk(0xC799A,0xC8282,"Chapter2Graphics","data/graphics/specialscreens/chapterscreen/chapter2graphics.bin",file);
    splitSingleChunk(0xC8282,0xC8B94,"Chapter3Graphics","data/graphics/specialscreens/chapterscreen/chapter3graphics.bin",file);
    splitSingleChunk(0xC8B94,0xC94C6,"Chapter4Graphics","data/graphics/specialscreens/chapterscreen/chapter4graphics.bin",file);
    splitSingleChunk(0xC94C6,0xC9DDC,"Chapter5Graphics","data/graphics/specialscreens/chapterscreen/chapter5graphics.bin",file);
    splitSingleChunk(0xC9DDC,0xCA72E,"Chapter6Graphics","data/graphics/specialscreens/chapterscreen/chapter6graphics.bin",file);
    splitSingleChunk(0xCA72E,0xCAFD4,"Chapter7Graphics","data/graphics/specialscreens/chapterscreen/chapter7graphics.bin",file);
    splitSingleChunk(0xCAFD4,0xCB8C7,"Chapter8Graphics","data/graphics/specialscreens/chapterscreen/chapter8graphics.bin",file);
    MakeAlign(0xCB8C7, 0xCC000-0xCB8C7,15);
    
    
	//Section 11 - 0xCC000
    
    //splitSingleChunk(0xCC05E,0xCCB1A,"unk_CC05E","data/",file);
    
	splitSingleChunk(0xCCB1A,0xCCFEE,"MenuGraphics","data/graphics/tech/menus/menugraphics.bin",file);
    
    //splitSingleChunk(0xCCFEE,0xCDD6E,"unk_CCFEE","data/",file);
    //splitSingleChunk(0xCDD6E,0xCE2FE,"unk_CDD6E","data/",file);
    //splitSingleChunk(0xCE2FE,0xCE75E,"unk_CE2FE","data/",file);
    //splitSingleChunk(0xCE75E,0xCEC34,"unk_CE75E","data/",file);
    //splitSingleChunk(0xCEC34,0xCF0EA,"unk_CEC34","data/",file);
    
	splitSingleChunk(0xCF0EA,0xCFCEA,"SpellIcons","data/graphics/icons/spellicons.bin",file);
	splitSingleChunk(0xCFCEA,0xD2DAA,"ItemIcons","data/graphics/icons/itemicons.bin",file);
	splitSingleChunk(0xD2DAA,0xD2E84,"CursorGraphics","data/graphics/cursorgraphics.bin",file);
    
    //splitSingleChunk(0xD2E84,0xD2EA4,"unk_D2E84","data/",file);
    
	splitSingleChunk(0xD301A,0xD32DA,"wl_TextInput","data/graphics/tech/windowlayouts/wl-textinput.bin",file);
    
    //splitSingleChunk(0xD32DA,0xD3308,"unk_D32DA","data/",file);
    //...
    
	
	//Section 12 - 0x100000
	//Section 13 - 0x124000
    
	splitSingleChunk(0x1269C6,0x1269EE,"plt_BoltEffect","data/graphics/tech/palettes/plt-bolteffect.bin",file);
	splitSingleChunk(0x126A6C,0x126A76,"plt_BlazeEffect","data/graphics/tech/palettes/plt-blazeeffect.bin",file);
	splitSingleChunk(0x126B9E,0x126BA8,"plt_FreezeEffect","data/graphics/tech/palettes/plt-freezeeffect.bin",file);
	splitSingleChunk(0x126C26,0x126C30,"plt_DemonBlazeEffect","data/graphics/tech/palettes/plt-demonblazeeffect.bin",file);
	splitSingleChunk(0x126C8E,0x126C98,"plt_DesoulEffect","data/graphics/tech/palettes/plt-desouleffect.bin",file);
	//splitSingleChunk(0x126D1E,0x126D3C,"unk_126D1E","data/graphics/tech/palettes/",file);
	splitSingleChunk(0x126DEA,0x126DFE,"plt_HealEffect","data/graphics/tech/palettes/plt-healeffect.bin",file);
	splitSingleChunk(0x126E78,0x126E82,"plt_LyleAttackEffect","data/graphics/tech/palettes/plt-lyleattackeffect.bin",file);
	//splitSingleChunk(0x126E90,0x126E9A,"unk_126E90","data/graphics/tech/palettes/",file);
	splitSingleChunk(0x126EF0,0x126EFA,"plt_WolfBaronAttackEffect","data/graphics/tech/palettes/plt-wolfbaronattackeffect.bin",file);
	//splitSingleChunk(0x126F4A,0x126F54,"unk_126F4A","data/graphics/tech/palettes/",file);
	splitSingleChunk(0x126FD0,0x126FDA,"plt_BleuAttackEffect","data/graphics/tech/palettes/plt-bleuattackeffect.bin",file);
	splitSingleChunk(0x126FFE,0x127008,"plt_LaserEffect","data/graphics/tech/palettes/plt-lasereffect.bin",file);
	//splitSingleChunk(0x127060,0x12706A,"unk_127060","data/graphics/tech/palettes/",file);
	splitSingleChunk(0x127092,0x12709C,"plt_ShellExplosionEffect","data/graphics/tech/palettes/plt-shellexplosioneffect.bin",file);
	splitSingleChunk(0x1270F4,0x1270FE,"plt_MusashiAttackEffect","data/graphics/tech/palettes/plt-musashiattackeffect.bin",file);
	//splitSingleChunk(0x127152,0x12715C,"","data/graphics/tech/palettes/",file);
	splitSingleChunk(0x127182,0x12718C,"plt_FireBreathEffect","data/graphics/tech/palettes/plt-firebreatheffect.bin",file);

	splitSingleChunk(0x12C7B0,0x12CBD0,"EffectGraphics","data/graphics/effectgraphics.bin",file);
    
	//splitSingleChunk(0x12CBD0,0x12D47E,"unk_12CBD0","data/graphics/",file);
	//splitSingleChunk(0x12D47E,0x12DDA2,"unk_12D47E","data/graphics/",file);
	//splitSingleChunk(0x12DDA2,0x12DFEC,"unk_12DDA2","data/graphics/",file);
	//splitSingleChunk(0x12DFEC,0x12E2FC,"unk_12DFEC","data/graphics/",file);
	//splitSingleChunk(0x12E2FC,0x12E5E4,"unk_12E2FC","data/graphics/",file);
	//splitSingleChunk(0x12E5E4,0x12E610,"unk_12E5E4","data/graphics/",file);
	//splitSingleChunk(0x12E610,0x12E692,"unk_12E610","data/graphics/",file);
    //splitSingleChunk(0x12E692,0x12E8C0,"unk_12E692","data/graphics/",file);
    //splitSingleChunk(0x12E8C0,0x12E99E,"unk_12E8C0","data/graphics/",file);
    //splitSingleChunk(0x12E99E,0x12EDC2,"unk_12E99E","data/graphics/",file);
    //splitSingleChunk(0x12EDC2,0x12EEBE,"unk_12EDC2","data/graphics/",file);
    //splitSingleChunk(0x12EEBE,0x12F0FE,"unk_12EEBE","data/graphics/",file);
    //splitSingleChunk(0x12F0FE,0x12F2E2,"unk_12F0FE","data/graphics/",file);
    //splitSingleChunk(0x12F2E2,0x12F502,"unk_12F2E2","data/graphics/",file);
    //splitSingleChunk(0x12F502,0x12F70E,"unk_12F502","data/graphics/",file);
    //splitSingleChunk(0x12F70E,0x12F8E2,"unk_12F70E","data/graphics/",file);
    //splitSingleChunk(0x12F8E2,0x12F938,"unk_12F8E2","data/graphics/",file);
    //splitSingleChunk(0x12F938,0x12FE16,"unk_12F938","data/graphics/",file);
	MakeAlign(0x12FE16, 0x130000-0x12FE16,15);
    
    
	//Section 14 - 0x130000
    
    MakeAlign(0x13E92A, 0x144000-0x13E92A,15);
    
    
	//Section 15 - 0x144000

	splitSingleChunk(0x16186E,0x161A66,"plt_Weapons","data/graphics/battles/weapons/plt-weapons.bin",file);


	//Section 16 - 0x164000
    
    //splitSingleChunk(0x1640C0,0x1640C8,"unk_1640C0","data/",file);
    //splitSingleChunk(0x1640C8,0x1640D0,"unk_1640C8","data/",file);
    //splitSingleChunk(0x1640D0,0x1640D8,"unk_1640D0","data/",file);
    //splitSingleChunk(0x1640D8,0x164100,"unk_1640D8","data/",file);
    //splitSingleChunk(0x1644EA,0x1644F6,"byte_1644EA","data/",file);
    //splitSingleChunk(0x164990,0x1649CC,"unk_164990","data/",file);
    //splitSingleChunk(0x1649CC,0x164A0A,"unk_1649CC","data/",file);
    //splitSingleChunk(0x164A0A,0x164A12,"unk_164A0A","data/",file);
    
    //splitSingleChunk(0x164A32,0x164A37,"unk_164A32","data/",file);
    //splitSingleChunk(0x164A37,0x164A3D,"unk_164A37","data/",file);
    //...
    
    splitSingleChunk(0x16761C,0x16763C,"plt_SegaLogo","data/graphics/tech/palettes/plt-sega.bin",file);
	splitSingleChunk(0x16763C,0x167B12,"SegaLogo","data/graphics/tech/segalogo.bin",file);
    //splitSingleChunk(0x167B12,0x167B1A,"unk_167B12","data/",file);
	//splitSingleChunk(0x167B1A,0x,"wl_Portrait","data/graphics/tech/windowlayouts/wl-portrait.bin",file);
    //splitSingleChunk(0x167F06,0x167F9C,"unk_167F06","data/",file);
    
    
	//Section 17 - 0x168000

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
	start = 0x58014;
	end = 0x580B8;
	addr = start;
	lastEntryDataEnd = 0x7F6FF;
	chunkEnd = 0x80000;
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




