
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
	produceSection(file,"02",	 0x8000,			 0x20000,				0x20000-0x1F068,		"");
	produceSection(file,"03",	0x20000,			 0x2C000,				0x2C000-0x2BF85,		"");
	produceSection(file,"04",	0x2C000,			 0x38000,				0x38000-0x37B38,		"");
	produceSection(file,"05",	0x38000,			 0x58000,				0x58000-0x57F5F,		"");
	produceSection(file,"06",	0x58000,			 0x80000,				0x80000-0x7F6FF,		"");
	produceSection(file,"07",	0x80000,			 0xBC000,				0xBC000-0xBA3ED,		"");
	produceSection(file,"08",	0xBC000,			 0xC0000,				0xC0000-0xBEDAC,		"");
	produceSection(file,"09",	0xC0000,			0x100000,			 0x100000-0xFFD3D,		"");
	produceSection(file,"10",0x100000,			0x124000,			0x124000-0x122758,		"");
	produceSection(file,"11",0x124000,			0x144000,			0x144000-0x13E92C,		"");
	produceSection(file,"12",0x144000,			0x164000,			0x164000-0x163FFA,		"");
	produceSection(file,"13",0x164000,			0x168000,			0x168000-0x163FFA,		"");
	produceSection(file,"14",0x168000,			0x180000,											0,		"");

	fclose(file);
	Message("\nDONE.");	
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