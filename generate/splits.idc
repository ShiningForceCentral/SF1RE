

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
writestr(file,"#dir	data/graphics/\n");
writestr(file,"#dir	data/graphics/maps\n");
writestr(file,"#dir	data/graphics/maps/maptilesets\n");
writestr(file,"#dir	data/graphics/mapsprites\n");
writestr(file,"#dir	data/graphics/portraits\n");
writestr(file,"#dir	data/graphics/specialsprites\n");
writestr(file,"#dir	data/graphics/battles\n");
writestr(file,"#dir	data/graphics/battles/battlesprites\n");
writestr(file,"#dir	data/graphics/battles/battlesprites/allies\n");
writestr(file,"#dir	data/graphics/battles/battlesprites/allies/animations/\n");
writestr(file,"#dir	data/graphics/battles/battlesprites/enemies\n");
writestr(file,"#dir	data/graphics/battles/battlesprites/enemies/animations/\n");
writestr(file,"#dir	data/graphics/battles/weapons\n");
writestr(file,"#dir	data/graphics/battles/spells\n");
writestr(file,"#dir	data/graphics/battles/backgrounds\n");
writestr(file,"#dir	data/graphics/battles/grounds\n");
writestr(file,"#dir	data/graphics/specialscreens\n");
writestr(file,"#dir	data/graphics/specialscreens/titlescreen\n");
writestr(file,"#dir	data/graphics/specialscreens/readerscreen\n");
writestr(file,"#dir	data/graphics/icons\n");
writestr(file,"#dir	data/graphics/tech/\n");
writestr(file,"#dir	data/graphics/tech/menus\n");
writestr(file,"#dir	data/graphics/tech/fonts\n");
writestr(file,"#dir	data/graphics/tech/palettes\n");
writestr(file,"#dir	data/maps/\n");
writestr(file,"#dir	data/maps/global/\n");
writestr(file,"#dir	data/maps/entries/\n");
writestr(file,"#dir	data/maps/spritesets/\n");
writestr(file,"#dir	data/battles\n");
writestr(file,"#dir	data/battles/global\n");
writestr(file,"#dir	data/battles/entries\n");
writestr(file,"#dir	data/stats/\n");
writestr(file,"#dir	data/stats/allies\n");
writestr(file,"#dir	data/stats/allies/classes\n");
writestr(file,"#dir	data/stats/enemies\n");
writestr(file,"#dir	data/stats/items\n");
writestr(file,"#dir	data/stats/spells\n");
writestr(file,"#dir	data/scripting/\n");
writestr(file,"#dir	data/scripting/text\n");
writestr(file,"#dir	data/scripting/mapspritescripts\n");
writestr(file,"#dir	data/scripting/cutscenes\n");
writestr(file,"#dir	data/sound/\n");
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
	
	splitPT(0x80010, 0x800E8, 0x80EE0, 0x80EE0, "pt_SpriteSets", "SpriteSet", "data/maps/spritesets/", "mapspriteset", 2, 0, file);	
	splitPT(0x80EFE, 0x811AE, 0x820CC, 0x820CC, "pt_MapSpriteScripts", "MapSpriteScript", "data/scripting/mapspritescripts/", "mapspritescript", 2, 0, file);	
	
	splitPT(0x2D13E, 0x2D20E, 0x37B38, 0x38000, "pt_Portraits", "Portrait", "data/graphics/portraits/", "portrait", 2, 15, file);	
	splitPT(0x39928, 0x3A0A8, 0x57F5F, 0x58000, "pt_MapSprites", "MapSprite", "data/graphics/mapsprites/", "mapsprite", 3, 15, file);			
	splitPT(0xD398E, 0xD3AC6, 0xFFD3D, 0x100000, "pt_Backgrounds", "Background", "data/graphics/battles/backgrounds/", "background", 2, 15, file);	
	splitPT(0x100008, 0x1000D0, 0x122252, 0x122252, "pt_EnemyBattleSprites", "EnemyBattleSprite", "data/graphics/battles/battlesprites/enemies/", "enemybattlesprite", 2, 0, file);	
	splitPT(0x122252, 0x12236E, 0x122758, 0x124000, "pt_EnemiesAnimations", "EnemyBattleSpriteAnimation", "data/graphics/battles/battlesprites/enemies/animations/", "enemybattlespriteanimation", 3, 14, file);
	
	splitPT(0x144014, 0x1440A0, 0x1602E2, 0x1602E2, "pt_AllyBattleSprites", "AllyBattleSprite", "data/graphics/battles/battlesprites/allies/", "allybattlesprite", 2, 0, file);
	splitPT(0x1602E2, 0x16035E, 0x16186E, 0x16186E, "pt_WeaponSprites", "WeaponSprite", "data/graphics/battles/weapons/", "weaponsprite", 2, 0, file);		
	splitPT(0x161A66, 0x161B52, 0x16226A, 0x16226A, "pt_AlliesAnimations", "AllyBattleSpriteAnimation", "data/graphics/battles/battlesprites/enemies/animations/", "allybattleanimation", 3, 0, file);
	splitPT(0x16226A, 0x162296, 0x163FFA, 0x164000, "pt_Grounds", "Ground", "data/graphics/battles/grounds/", "ground", 2, 14, file);
	
	
	
	
	
}

static splitSingleChunks(file) {
	auto i,j,x,s,index,path;
	auto start,base,addr,end,dref,section,action;
	
	// Template : splitSingleChunk(0x,0x,"","",file);
	
    splitSingleChunk(0xB4C,0xB9C,"FadingData","data/graphics/tech/fadingdata.bin",file);
	
	MakeAlign(0x7E22, 0x8000-0x7E22,15);	
	
	splitSingleChunk(0x1E892,0x1EA3A,"TextBankTreesPointers","data/scripting/text/huffmantreeoffsets.bin",file);
	splitSingleChunk(0x1EA3A,0x1EFE0,"TextBankTreeData","data/scripting/text/huffmantrees.bin",file);
	
	MakeAlign(0x1F068, 0x20000-0x1F068,15);	
	


	splitSingleChunk(0x25154,0x25604,"CharacterData","data/stats/allies/chardata.bin",file);	
	splitSingleChunk(0x25640,0x25916,"ItemNames","data/stats/items/itemnames.bin",file);
	splitSingleChunk(0x25916,0x25D06,"ItemData","data/stats/items/itemdata.bin",file);
	splitSingleChunk(0x25D6C,0x260BC,"ClassNames","data/stats/allies/classes/classnames.bin",file);	
	splitSingleChunk(0x260BC,0x26404,"ClassData","data/stats/allies/classes/classdata.bin",file);	
	splitSingleChunk(0x26404,0x26466,"SpellNames","data/stats/spells/spellnames.bin",file);
	splitSingleChunk(0x26466,0x26566,"SpellData","data/stats/spells/spelldata.bin",file);	
	splitSingleChunk(0x265E6,0x26666,"LandEffectData","data/battles/global/landeffectdata.bin",file);		
	splitSingleChunk(0x26C1A,0x26CCE,"StatGrowthCurves","data/stats/allies/growthcurves.bin",file);
	splitSingleChunk(0x26CCE,0x26D70,"StatGrowthCurvesPromoted","data/stats/allies/growthcurvespromoted.bin",file);		
	splitSingleChunk(0x26D70,0x26E16,"SpellsLearningData","data/stats/allies/spellslearningdata.bin",file);			
	splitSingleChunk(0x2704E,0x2751A,"MapHeaders","data/maps/global/mapheaders.bin",file);	
	splitSingleChunk(0x2751C,0x2BF85,"EnemyData","data/stats/enemies/enemydata.bin",file);		
	MakeAlign(0x2BF85, 0x2C000-0x2BF85,14);
	splitSingleChunk(0x2C13E,0x2D13E,"VariableWidthFont","data/graphics/tech/fonts/variablewidthfont.bin",file);
	
	
	
	MakeAlign(0xBEDAC, 0xC0000-0xBEDAC,15);	
	splitSingleChunk(0xCCB1A,0xCCFEE,"MenuGraphics","data/graphics/tech/menus/menugraphics.bin",file);	
	splitSingleChunk(0xCF0EA,0xCFCEA,"Icons","data/graphics/icons/icons.bin",file);	
	
	
	splitSingleChunk(0x16186E,0x161A66,"plt_WeaponPalettes","data/graphics/battles/weapons/weaponpalettes.bin",file);

	splitSingleChunk(0x168000, 0x170000, "","data/sound/pcmbank0.bin",file);
	splitSingleChunk(0x170000, 0x176000, "","data/sound/musicbank0.bin",file);
	splitSingleChunk(0x176000, 0x178000, "","data/sound/driver.bin",file);
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




