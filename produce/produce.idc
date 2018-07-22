
/*
 *	Attempt at producing ASM file from IDC script 
 *	instead of IDA's function, for more flexibility.
 */

#include <idc.idc>

static main(void) {

	Message("PRODUCING ASM...\n");

	produceMacros();
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
	writestr(file,"align:	macro\n");
	writestr(file,"	if (narg=1)\n");
	writestr(file,"	dcb.b \\1-(*%\\1),$FF\n");
	writestr(file,"	else\n");
	writestr(file,"	dcb.b \\1-(*%\\1),\\2\n");
	writestr(file,"	endc\n");
	writestr(file,"	endm\n");
	writestr(file,"\n");
	fclose(file);	
	Message("DONE.");	
}

static produceEnums(){
	auto i,j,enumQty,id,enumName,enumSize,constant,constId,output,file;
	file = fopen("disasm\\sf1enums.asm","w");
	Message("\nWriting Enums to sf1enums.asm ...");
	enumQty = GetEnumQty();
	for(i=0;i<enumQty;i++){
		id = GetnEnum(i);
		enumName = GetEnumName(id);
		//Message("\n\n; ---------------------------------------------------------------------------\n");
		writestr(file,"\n\n; ---------------------------------------------------------------------------\n");
		//Message(form("\n; enum %s",enumName));
		writestr(file,form("\n; enum %s",enumName));
		enumSize = GetEnumSize(id);
		constant = GetFirstConst(id,-1);
		while(constant!=-1){
			j=0;
			constId = GetConstEx(id,constant,j,-1);
			while(constId != -1){
				output = form("\n%s: equ $%s",GetConstName(constId),ltoa(constant,16));
				//Message(output);
				writestr(file,output);
				j++;
				constId = GetConstEx(id,constant,j,-1);
			}
			constant = GetNextConst(id,constant,-1);
		}
	}
	fclose(file);
	Message("DONE.");
}


static produceConst(void) {
	auto seg,end,ea,segName,name,file;
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
			name = GetTrueName(ea);
			if(name!=""){
				writestr(file,form("%s: equ $%s\n",name,ltoa(ea,16)));
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
	 
	produceSection(file,"01",			0x0,				0x8000,					0x8000-0x7E22,		"Technical layer, low level game engine, ...");
	produceSection(file,"02",	 0x8000,			 0x10000,				0x10000-0xFD58,		"");
	produceSection(file,"03",	 0x10000,			 0x20000,				0x20000-0x1F068,		"");
	produceSection(file,"04",	0x20000,			 0x2C000,				0x2C000-0x2BF85,		"");
	produceSection(file,"05",	0x2C000,			 0x38000,				0x38000-0x37B38,		"Region check, variable width font, portraits");
	produceSection(file,"06",	0x38000,			 0x58000,				0x58000-0x57F5F,		"Map sprites, misc. uncompressed graphics");
	produceSection(file,"07",	0x58000,			 0x80000,				0x80000-0x7F6FF,		"Map tilesets");
	produceSection(file,"08",	0x80000,			 0xBC000,				0xBC000-0xBA3ED,		"Sprite sets, map sprite scripts, ...");
	produceSection(file,"09",	0xBC000,			 0xC0000,				0xC0000-0xBEDAC,		"");
	produceSection(file,"10",	0xC0000,			0xCC000,			 0xCC000-0xCB8C5,		"Ending, intro, title and chapter screens graphics and palettes");
	produceSection(file,"11",	0xCC000,			0x100000,			 0x100000-0xFFD3D,		"");
	produceSection(file,"12",0x100000,			0x124000,			0x124000-0x122758,		"Enemy battle sprites and animations");
	produceSection(file,"13",0x124000,			0x130000,			0x130000-0x12FE14,		"");
	produceSection(file,"14",0x130000,			0x144000,			0x144000-0x13E92C,		"Text banks, ...");
	produceSection(file,"15",0x144000,			0x164000,			0x164000-0x163FFA,		"Ally battle sprites and animations, weapon sprites and palettes, battle platforms");
	produceSection(file,"16",0x164000,			0x168000,			0x168000-0x167FEA,		"");
	produceSection(file,"17",0x168000,			0x180000,											0,		"Sound driver");

	fclose(file);
	Message("\nDONE.");	
}

static produceLayoutFile(){

	auto file;
	file = fopen("disasm\\layout\\sf1-00-romlayout.asm","w");
	
	writestr(file,"\n; ROM LAYOUT FILE\n;\n");

	produceSpecificSectionOne(file,		"01",	0x0,		0x8000,		478,	"0x000000..0x008000 : Technical layer, low level game engine, ...");
	produceSpecificSectionTwo(file,		"02",	0x8000,		0x10000,	680,	"0x008000..0x010000 : ");
	produceSpecificSectionThree(file,	"03",	0x10000,	0x20000,	3992,	"0x010000..0x020000 : ");
	produceSpecificSectionFour(file,	"04",	0x20000,	0x2C000,	123,	"0x020000..0x02C000 : ");
	produceSpecificSectionFive(file,	"05",	0x2C000,	0x38000,	1224,	"0x02C000..0x038000 : Region check, variable width font, portraits");
	produceSpecificSectionSix(file,		"06",	0x38000,	0x58000,	161,	"0x038000..0x058000 : Map sprites, misc. uncompressed graphics");
	produceSpecificSectionSeven(file,	"07",	0x58000,	0x80000,	2305,	"0x058000..0x080000 : Map tilesets");
	produceSpecificSectionEight(file,	"08",	0x80000,	0xBC000,	7187,	"0x080000..0x0BC000 : Sprite sets, map sprite scripts, ...");
	produceSpecificSectionNine(file,	"09",	0xBC000,	0xC0000,	1254,	"0x0BC000..0x0C0000 : ");
	produceSpecificSectionTen(file,		"10",	0xC0000,	0xCC000,	1851,	"0x0C0000..0x0CC000 : Ending, intro, title and chapter screens graphics and palettes");
	produceSpecificSectionEleven(file,	"11",	0xCC000,	0x100000,	707,	"0x0CC000..0x100000 : ");
	produceSpecificSectionTwelve(file,	"12",	0x100000,	0x124000,	6312,	"0x100000..0x124000 : Enemy battle sprites and animations");
	produceSpecificSectionThirteen(file,	"13",	0x124000,	0x130000,	492,	"0x124000..0x130000 : ");
	produceSpecificSectionFourteen(file,	"14",	0x130000,	0x144000,	22228,	"0x130000..0x144000 : Text banks, ...");
	produceSpecificSectionFifteen(file,	"15",	0x144000,	0x164000,	6,	"0x144000..0x164000 : Ally battle sprites and animations, weapon sprites and palettes, battle platforms");
	produceSpecificSectionSixteen(file,	"16",	0x164000,	0x168000,	22,	"0x164000..0x168000 : ");
	produceSpecificSectionSeventeen(file,	"17",	0x168000,	0x180000,	0,	"0x168000..0x180000 : Sound driver");

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
	
	//produceAsmSection(file,0x0,0x8000);
    
	produceAsmScript(file,"code\\romheader",0x0,0x200,"ROM Header");
	produceAsmScript(file,"code\\gameflow\\start\\systeminit",0x200,0x47A,"System init functions");
	produceAsmScript(file,"code\\gameflow\\start\\gamestart",0x47A,0x5FA,"Start function");
	produceAsmScript(file,"code\\common\\tech\\interrupts\\trap0_soundcommand",0x5FA,0x62E,"Trap 0 - Sound Command");
	produceAsmScript(file,"code\\common\\tech\\interrupts\\errors",0x62E,0x698,"Error interrupts");
	produceAsmScript(file,"code\\common\\tech\\interrupts\\trap5_",0x698,0x6A8,"Trap 5 - ");
	produceAsmScript(file,"code\\common\\tech\\interrupts\\trap6_",0x6A8,0x6B8,"Trap 6 - ");
	produceAsmScript(file,"code\\common\\tech\\interrupts\\trap7_",0x6B8,0x6C8,"Trap 7 - ");
	produceAsmScript(file,"code\\common\\tech\\interrupts\\trap8_",0x6C8,0x6D8,"Trap 8 - ");
	produceAsmScript(file,"code\\common\\tech\\interrupts\\vintengine",0x6D8,0x137E,"Vertical Interrupt Engine - Main Technical Engine - Triggered at each frame display");
	produceAsmScript(file,"code\\common\\scripting\\text\\asciinumber",0x137E,0x1410,"ASCII number function");
	produceAsmScript(file,"code\\common\\tech\\input",0x1410,0x14EE,"Input functions");
	produceAsmScript(file,"code\\common\\tech\\randomnumbergenerator",0x14EE,0x150E,"RNG function");
	produceAsmScript(file,"code\\common\\tech\\sound\\music",0x150E,0x1526,"Sound function");
	produceAsmScript(file,"code\\common\\tech\\bytecopy",0x1526,0x1550,"Byte-copy function");
	produceAsmScript(file,"code\\common\\tech\\graphics\\graphics",0x1550,0x2046,"Graphics functions");
	produceAsmScript(file,"code\\common\\scripting\\text\\textfunctions",0x2046,0x21C8,"Text functions");

	produceAsmScript(file,"code\\common\\tech\\graphics\\graphicsdecompressor",0x25D0,0x29F8,"Graphics decompression function");

	produceAsmScript(file,"code\\common\\tech\\interrupts\\trap1_",0x2F72,0x2F94,"Trap 1 - ");
	produceAsmScript(file,"code\\common\\tech\\interrupts\\trap2_",0x2F94,0x2FB6,"Trap 2 - ");
	produceAsmScript(file,"code\\common\\tech\\interrupts\\trap3_",0x2FB6,0x2FD8,"Trap 3 - ");
	produceAsmScript(file,"code\\common\\tech\\interrupts\\trap4_",0x2FD8,0x2FFA,"Trap 4 - ");
	//produceAsmScript(file,"code\\common\\scripting\\eventflags",0x2FFA,0x,"Event flags functions");

	produceAsmScript(file,"code\\common\\tech\\sram\\sramfunctions",0x3660,0x3852,"SRAM functions");

	produceAsmScript(file,"code\\common\\scripting\\battleexits",0x3F0E,0x49EE,"Battle exit scripts functions");

	fclose(file);
	Message("DONE.\n");	
}	


static produceSpecificSectionTwo(mainFile,sectionName,start,end,fs,sectionComment){
	auto ea,itemSize,action,currentLine,previousLine,fileName,file;
	auto output, name, indent, comment, commentEx, commentIndent;
	fileName = form("layout\\sf2-%s-0x00%s-0x0%s.asm",sectionName,ltoa(start,16),ltoa(end,16));
	Message(form("Writing assembly section %s to %s (%s) ... ",sectionName,fileName,sectionComment));	
	action = 1;
	writestr(mainFile,form("\t\tinclude \"%s\"\t\t; %s\n",fileName,sectionComment));
	file = fopen(form("disasm\\%s",fileName),"w");
	writestr(file,form("\n; GAME SECTION %s :\n; %s\n",sectionName,sectionComment));
	writestr(file,form("; FREE SPACE : %d bytes.\n\n\n",fs));
    
	produceAsmSection(file,0x8000,0x10000);
    
	fclose(file);
	Message("DONE.\n");	
}	


static produceSpecificSectionThree(mainFile,sectionName,start,end,fs,sectionComment){
	auto ea,itemSize,action,currentLine,previousLine,fileName,file;
	auto output, name, indent, comment, commentEx, commentIndent;
	fileName = form("layout\\sf2-%s-0x0%s-0x0%s.asm",sectionName,ltoa(start,16),ltoa(end,16));
	Message(form("Writing assembly section %s to %s (%s) ... ",sectionName,fileName,sectionComment));	
	action = 1;
	writestr(mainFile,form("\t\tinclude \"%s\"\t\t; %s\n",fileName,sectionComment));
	file = fopen(form("disasm\\%s",fileName),"w");
	writestr(file,form("\n; GAME SECTION %s :\n; %s\n",sectionName,sectionComment));
	writestr(file,form("; FREE SPACE : %d bytes.\n\n\n",fs));	
    
	//produceAsmSection(file,0x10000,0x20000);
    
	produceAsmSection(file,0x1E892,0x1EFE0);
	produceAsmScript(file,"code\\common\\scripting\\text\\huffmandecoder",0x1EFE0,0x1F068,"Text decoding functions");	
	produceAsmSection(file,0x1F068,0x20000);

	fclose(file);
	Message("DONE.\n");	
}	


static produceSpecificSectionFour(mainFile,sectionName,start,end,fs,sectionComment){
	auto ea,itemSize,action,currentLine,previousLine,fileName,file;
	auto output, name, indent, comment, commentEx, commentIndent;
	fileName = form("layout\\sf2-%s-0x0%s-0x0%s.asm",sectionName,ltoa(start,16),ltoa(end,16));
	Message(form("Writing assembly section %s to %s (%s) ... ",sectionName,fileName,sectionComment));	
	action = 1;
	writestr(mainFile,form("\t\tinclude \"%s\"\t\t; %s\n",fileName,sectionComment));
	file = fopen(form("disasm\\%s",fileName),"w");
	writestr(file,form("\n; GAME SECTION %s :\n; %s\n",sectionName,sectionComment));
	writestr(file,form("; FREE SPACE : %d bytes.\n\n\n",fs));	
    
	//produceAsmSection(file,0x20000,0x2C000);
    
	produceAsmScript(file,"code\\common\\stats\\statsengine",0x20000,0x25154,"Character stats engine");
    
    //produceAsmScript(file,"code\\common\\stats\\levelup",0x246EC,0x24BAC,"Level up functions");
    
    produceAsmSection(file,0x25154,0x26E16);    //Stats engine data
    
    //produceAsmScript(file,"code\\gameflow\\battle\\battlefieldengine",0x26E16,0x2704E,"Battlefield engine");
    
	produceAsmSection(file,0x2704E,0x2C000);

	fclose(file);
	Message("DONE.\n");
}


static produceSpecificSectionFive(mainFile,sectionName,start,end,fs,sectionComment){
	auto ea,itemSize,action,currentLine,previousLine,fileName,file;
	auto output, name, indent, comment, commentEx, commentIndent;
	fileName = form("layout\\sf2-%s-0x0%s-0x0%s.asm",sectionName,ltoa(start,16),ltoa(end,16));
	Message(form("Writing assembly section %s to %s (%s) ... ",sectionName,fileName,sectionComment));
	action = 1;
	writestr(mainFile,form("\t\tinclude \"%s\"\t\t; %s\n",fileName,sectionComment));
	file = fopen(form("disasm\\%s",fileName),"w");
	writestr(file,form("\n; GAME SECTION %s :\n; %s\n",sectionName,sectionComment));
	writestr(file,form("; FREE SPACE : %d bytes.\n\n\n",fs));
    
	produceAsmSection(file,0x2C000,0x2C008);
	produceAsmScript(file,"code\\gameflow\\start\\regioncheck",0x2C008,0x2C13E,"Region check function");
	produceAsmSection(file,0x2C13E,0x2D13E);
	produceAsmScript(file,"data\\graphics\\portraits\\entries",0x2D13E,0x37B38,"Portraits");
    produceAsmSection(file,0x37B38,0x38000);
    
	fclose(file);
	Message("DONE.\n");
}


static produceSpecificSectionSix(mainFile,sectionName,start,end,fs,sectionComment){
	auto ea,itemSize,action,currentLine,previousLine,fileName,file;
	auto output, name, indent, comment, commentEx, commentIndent;
	fileName = form("layout\\sf2-%s-0x0%s-0x0%s.asm",sectionName,ltoa(start,16),ltoa(end,16));
	Message(form("Writing assembly section %s to %s (%s) ... ",sectionName,fileName,sectionComment));	
	action = 1;
	writestr(mainFile,form("\t\tinclude \"%s\"\t\t; %s\n",fileName,sectionComment));
	file = fopen(form("disasm\\%s",fileName),"w");
	writestr(file,form("\n; GAME SECTION %s :\n; %s\n",sectionName,sectionComment));
	writestr(file,form("; FREE SPACE : %d bytes.\n\n\n",fs));	
			
	//produceAsmSection(file,0x38000,0x58000);
    
	produceAsmSection(file,0x38000,0x39928);
	produceAsmScript(file,"data\\graphics\\mapsprites\\entries",0x39928,0x57F5F,"Map sprites");
    produceAsmSection(file,0x57F5F,0x58000);

	fclose(file);
	Message("DONE.\n");	
}


static produceSpecificSectionSeven(mainFile,sectionName,start,end,fs,sectionComment){
	auto ea,itemSize,action,currentLine,previousLine,fileName,file;
	auto output, name, indent, comment, commentEx, commentIndent;
	auto battleCutscenesFile, mapSetupsFile;
	fileName = form("layout\\sf2-%s-0x0%s-0x0%s.asm",sectionName,ltoa(start,16),ltoa(end,16));
	Message(form("Writing assembly section %s to %s (%s) ... ",sectionName,fileName,sectionComment));	
	action = 1;
	writestr(mainFile,form("\t\tinclude \"%s\"\t\t; %s\n",fileName,sectionComment));
	file = fopen(form("disasm\\%s",fileName),"w");
	writestr(file,form("\n; GAME SECTION %s :\n; %s\n",sectionName,sectionComment));
	writestr(file,form("; FREE SPACE : %d bytes.\n\n\n",fs));	
    
	produceAsmSection(file,0x58000,0x58014);
	produceAsmScript(file,"data\\graphics\\maps\\maptilesets\\entries",0x58014,0x7F6FF,"Map tilesets");
	produceAsmSection(file,0x7F6FF,0x80000);
    
	fclose(file);
	Message("DONE.\n");
}


static produceSpecificSectionEight(mainFile,sectionName,start,end,fs,sectionComment){
	auto ea,itemSize,action,currentLine,previousLine,fileName,file;
	auto output, name, indent, comment, commentEx, commentIndent;
	fileName = form("layout\\sf2-%s-0x0%s-0x0%s.asm",sectionName,ltoa(start,16),ltoa(end,16));
	Message(form("Writing assembly section %s to %s (%s) ... ",sectionName,fileName,sectionComment));	
	action = 1;
	writestr(mainFile,form("\t\tinclude \"%s\"\t\t; %s\n",fileName,sectionComment));
	file = fopen(form("disasm\\%s",fileName),"w");
	writestr(file,form("\n; GAME SECTION %s :\n; %s\n",sectionName,sectionComment));
	writestr(file,form("; FREE SPACE : %d bytes.\n\n\n",fs));	
    
	//produceAsmSection(file,0x80000,0xBC000);
    
	produceAsmSection(file,0x80000,0x80010);
	produceAsmScript(file,"data\\maps\\spritesets\\entries",0x80010,0x80EE0,"Sprite sets");
	produceAsmSection(file,0x80EE0,0x80EFE);
	produceAsmScript(file,"data\\scripting\\mapspritescripts\\entries",0x80EFE,0x820CC,"Map sprite scripts");

	fclose(file);
	Message("DONE.\n");	
}


static produceSpecificSectionNine(mainFile,sectionName,start,end,fs,sectionComment){
	auto ea,itemSize,action,currentLine,previousLine,fileName,file;
	auto output, name, indent, comment, commentEx, commentIndent;
	fileName = form("layout\\sf2-%s-0x0%s-0x%s.asm",sectionName,ltoa(start,16),ltoa(end,16));
	Message(form("Writing assembly section %s to %s (%s) ... ",sectionName,fileName,sectionComment));	
	action = 1;
	writestr(mainFile,form("\t\tinclude \"%s\"\t\t; %s\n",fileName,sectionComment));
	file = fopen(form("disasm\\%s",fileName),"w");
	writestr(file,form("\n; GAME SECTION %s :\n; %s\n",sectionName,sectionComment));
	writestr(file,form("; FREE SPACE : %d bytes.\n\n\n",fs));	

	produceAsmSection(file,0xBC000,0xC0000);

	fclose(file);
	Message("DONE.\n");	
}


static produceSpecificSectionTen(mainFile,sectionName,start,end,fs,sectionComment){
	auto ea,itemSize,action,currentLine,previousLine,fileName,file;
	auto output, name, indent, comment, commentEx, commentIndent;
	fileName = form("layout\\sf2-%s-0x%s-0x%s.asm",sectionName,ltoa(start,16),ltoa(end,16));
	Message(form("Writing assembly section %s to %s (%s) ... ",sectionName,fileName,sectionComment));	
	action = 1;
	writestr(mainFile,form("\t\tinclude \"%s\"\t\t; %s\n",fileName,sectionComment));
	file = fopen(form("disasm\\%s",fileName),"w");
	writestr(file,form("\n; GAME SECTION %s :\n; %s\n",sectionName,sectionComment));
	writestr(file,form("; FREE SPACE : %d bytes.\n\n\n",fs));	

	produceAsmSection(file,0xC0000,0xCC000);

	fclose(file);
	Message("DONE.\n");	
}


static produceSpecificSectionEleven(mainFile,sectionName,start,end,fs,sectionComment){
	auto ea,itemSize,action,currentLine,previousLine,fileName,file;
	auto output, name, indent, comment, commentEx, commentIndent;
	fileName = form("layout\\sf2-%s-0x%s-0x%s.asm",sectionName,ltoa(start,16),ltoa(end,16));
	Message(form("Writing assembly section %s to %s (%s) ... ",sectionName,fileName,sectionComment));	
	action = 1;
	writestr(mainFile,form("\t\tinclude \"%s\"\t\t; %s\n",fileName,sectionComment));
	file = fopen(form("disasm\\%s",fileName),"w");
	writestr(file,form("\n; GAME SECTION %s :\n; %s\n",sectionName,sectionComment));
	writestr(file,form("; FREE SPACE : %d bytes.\n\n\n",fs));	

	//produceAsmSection(file,0xCC000,0x100000);
    
	produceAsmScript(file,"data\\graphics\\battles\\backgrounds\\entries",0xD398E,0xFFD3D,"Backgrounds");
	produceAsmSection(file,0xFFD3D,0x100000);

	fclose(file);
	Message("DONE.\n");	
}


static produceSpecificSectionTwelve(mainFile,sectionName,start,end,fs,sectionComment){
	auto ea,itemSize,action,currentLine,previousLine,fileName,file;
	auto output, name, indent, comment, commentEx, commentIndent;
	fileName = form("layout\\sf2-%s-0x%s-0x%s.asm",sectionName,ltoa(start,16),ltoa(end,16));
	Message(form("Writing assembly section %s to %s (%s) ... ",sectionName,fileName,sectionComment));	
	action = 1;
	writestr(mainFile,form("\t\tinclude \"%s\"\t\t; %s\n",fileName,sectionComment));
	file = fopen(form("disasm\\%s",fileName),"w");
	writestr(file,form("\n; GAME SECTION %s :\n; %s\n",sectionName,sectionComment));
	writestr(file,form("; FREE SPACE : %d bytes.\n\n\n",fs));	
    
	produceAsmSection(file,0x100000,0x100008);
	produceAsmScript(file,"data\\graphics\\battles\\battlesprites\\enemies\\entries",0x100008,0x122252,"Enemy battle sprites");
	produceAsmScript(file,"data\\graphics\\battles\\battlesprites\\enemies\\animations\\entries",0x122252,0x122758,"Enemy battle animations");
	produceAsmSection(file,0x122758,0x124000);
    
	fclose(file);
	Message("DONE.\n");
}


static produceSpecificSectionThirteen(mainFile,sectionName,start,end,fs,sectionComment){
	auto ea,itemSize,action,currentLine,previousLine,fileName,file;
	auto output, name, indent, comment, commentEx, commentIndent;
	fileName = form("layout\\sf2-%s-0x%s-0x%s.asm",sectionName,ltoa(start,16),ltoa(end,16));
	Message(form("Writing assembly section %s to %s (%s) ... ",sectionName,fileName,sectionComment));	
	action = 1;
	writestr(mainFile,form("\t\tinclude \"%s\"\t\t; %s\n",fileName,sectionComment));
	file = fopen(form("disasm\\%s",fileName),"w");
	writestr(file,form("\n; GAME SECTION %s :\n; %s\n",sectionName,sectionComment));
	writestr(file,form("; FREE SPACE : %d bytes.\n\n\n",fs));	

	produceAsmSection(file,0x124000,0x130000);

	fclose(file);
	Message("DONE.\n");	
}


static produceSpecificSectionFourteen(mainFile,sectionName,start,end,fs,sectionComment){
	auto ea,itemSize,action,currentLine,previousLine,fileName,file;
	auto output, name, indent, comment, commentEx, commentIndent;
	fileName = form("layout\\sf2-%s-0x%s-0x%s.asm",sectionName,ltoa(start,16),ltoa(end,16));
	Message(form("Writing assembly section %s to %s (%s) ... ",sectionName,fileName,sectionComment));	
	action = 1;
	writestr(mainFile,form("\t\tinclude \"%s\"\t\t; %s\n",fileName,sectionComment));
	file = fopen(form("disasm\\%s",fileName),"w");
	writestr(file,form("\n; GAME SECTION %s :\n; %s\n",sectionName,sectionComment));
	writestr(file,form("; FREE SPACE : %d bytes.\n\n\n",fs));	

	//produceAsmSection(file,0x130000,0x144000);
    
	produceAsmScript(file,"data\\scripting\\text\\textbanks\\entries",0x131A1C,0x13E92A,"Text banks");

	fclose(file);
	Message("DONE.\n");
}


static produceSpecificSectionFifteen(mainFile,sectionName,start,end,fs,sectionComment){
	auto ea,itemSize,action,currentLine,previousLine,fileName,file;
	auto output, name, indent, comment, commentEx, commentIndent;
	fileName = form("layout\\sf2-%s-0x%s-0x%s.asm",sectionName,ltoa(start,16),ltoa(end,16));
	Message(form("Writing assembly section %s to %s (%s) ... ",sectionName,fileName,sectionComment));	
	action = 1;
	writestr(mainFile,form("\t\tinclude \"%s\"\t\t; %s\n",fileName,sectionComment));
	file = fopen(form("disasm\\%s",fileName),"w");
	writestr(file,form("\n; GAME SECTION %s :\n; %s\n",sectionName,sectionComment));
	writestr(file,form("; FREE SPACE : %d bytes.\n\n\n",fs));	
    
    produceAsmSection(file,0x144000,0x144014);
    produceAsmScript(file,"data\\graphics\\battles\\battlesprites\\allies\\entries",0x144014,0x1602E2,"Ally battle sprites");
    produceAsmScript(file,"data\\graphics\\battles\\weapons\\entries",0x1602E2,0x16186E,"Weapon sprites");
    produceAsmSection(file,0x16186E,0x161A66);
    produceAsmScript(file,"data\\graphics\\battles\\battlesprites\\allies\\animations\\entries",0x161A66,0x16226A,"Ally battle sprite animations");
    produceAsmScript(file,"data\\graphics\\battles\\grounds\\entries",0x16226A,0x163FFA,"Battle platforms");
    produceAsmSection(file,0x163FFA,0x164000);
    
	fclose(file);
	Message("DONE.\n");
}


static produceSpecificSectionSixteen(mainFile,sectionName,start,end,fs,sectionComment){
	auto ea,itemSize,action,currentLine,previousLine,fileName,file;
	auto output, name, indent, comment, commentEx, commentIndent;
	fileName = form("layout\\sf2-%s-0x%s-0x%s.asm",sectionName,ltoa(start,16),ltoa(end,16));
	Message(form("Writing assembly section %s to %s (%s) ... ",sectionName,fileName,sectionComment));	
	action = 1;
	writestr(mainFile,form("\t\tinclude \"%s\"\t\t; %s\n",fileName,sectionComment));
	file = fopen(form("disasm\\%s",fileName),"w");
	writestr(file,form("\n; GAME SECTION %s :\n; %s\n",sectionName,sectionComment));
	writestr(file,form("; FREE SPACE : %d bytes.\n\n\n",fs));	

	produceAsmSection(file,0x164000,0x168000);

	fclose(file);
	Message("DONE.\n");	
}


static produceSpecificSectionSeventeen(mainFile,sectionName,start,end,fs,sectionComment){
	auto ea,itemSize,action,currentLine,previousLine,fileName,file;
	auto output, name, indent, comment, commentEx, commentIndent;
	fileName = form("layout\\sf2-%s-0x%s-0x%s.asm",sectionName,ltoa(start,16),ltoa(end,16));
	Message(form("Writing assembly section %s to %s (%s) ... ",sectionName,fileName,sectionComment));	
	action = 1;
	writestr(mainFile,form("\t\tinclude \"%s\"\t\t; %s\n",fileName,sectionComment));
	file = fopen(form("disasm\\%s",fileName),"w");
	writestr(file,form("\n; GAME SECTION %s :\n; %s\n",sectionName,sectionComment));
	writestr(file,form("; FREE SPACE : %d bytes.\n\n\n",fs));	

	produceAsmSection(file,0x168000,0x180000);

	fclose(file);
	Message("DONE.\n");	
}


static produceSection(mainFile,sectionName,start,end,fs,sectionComment){
	produceSectionWithPrettyPrintParam(mainFile,sectionName,start,end,fs,sectionComment,1);
}


static produceSectionWithPrettyPrintParam(mainFile,sectionName,start,end,fs,sectionComment,prettyPrint){
	auto ea,itemSize,action,currentLine,previousLine,fileName,file;
	auto output, name, indent, comment, commentEx, commentIndent;
	fileName = form("sf1-%s.asm",sectionName);
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
	auto output, name, indent, comment, commentEx, commentIndent;
	fileName = form("%s.asm",sectionName);
	Message(form("Writing assembly script section %s to %s (%s) ... ",sectionName,fileName,sectionComment));	
	action = 1;
	writestr(mainFile,form("\t\tinclude \"%s\"\t\t; %s\n",fileName,sectionComment));
	file = fopen(form("disasm\\%s",fileName),"w");
	writestr(file,form("\n; ASM FILE %s :\n; %s\n",sectionName,sectionComment));	
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
	writestr(file,"   include \"sf1enums.asm\"\n");
	writestr(file,"   include \"sf1const.asm\"\n");
	writestr(file,"\n");
}

static writeFooter(file){
	writestr(file,"		END");
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
		writestr(file,form("\n	; End of function %s\n\n",funcName));
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
	name = GetTrueName(ea);
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