SF1RE
=====

Collaborative work on reverse-engineering Shining Force.

The main purposes of SF1RE are :
- to reverse-engineer Shining Force with IDA Pro,
- to share disassembly content with IDC scripts allowing to re-create the IDB from scratch,
- and ultimately, to produce as a result SF1DISASM's content : a split disassembly which can build back into the original game, while offering as much flexibility as possible for new games, hacks and mods based on Shining Force. 


Usage workflow :
1. IDB Initialization
    1. Open "Shining Force (USA)" ROM in IDA Pro to create a new IDB.
    2. Execute initialization scripts from ./01-IDB_INIT/ folder : 
        1. sf1.idc
        2. ImportGeneratedFunctionComments.idc
    3. Execute parsing scripts from ./02-IDB_PARSING/ folder :
        1. 00.ram-migration.idc
        2. 01.splits.idc
        3. 02.traps.idc : copy flags.txt and text.txt files in IDB folder first
        4. 03.othermacros.idc
        5. 04.fixes.idc
        At this point, the IDB represents the current state of disassembly, with the ability to further format and document content.
2. Export the disassembly :
    1. In IDB folder, copy and execute ./03-ASM_EXPORT/dirs.bat, which will create ./disasm/ folder
    2. Execute ./03-ASM_EXPORT/produce.idc
    3. Copy disasm folder into SF1DISASM project folder, in which you can build the ROM and check that a vanilla build still is bit-perfect.
3. Export IDB updates :
    1. File > Produce file > Dump database to IDC file ... and overwrite ./01-IDB_INIT/sf1.idc
    2. Optional : if function header comments have been updated, execute ./00-TOOLS/ExportFunctionComments.idc, which produces ImportGeneratedFunctionComments.idc in IDB folder, and then copy it into 01-IDB_INIT folder.


Naming conventions :
- Functions : DoSomethingLikeThis
- Rom Data Locations : DataChunkLikeThat
Disambiguation is made by the way they are accessed : functions are
branched or jumped into while data is pointed to, moved, etc.
- Enums : ENUM_VALUE_LIKE_THIS
- RAM locations : RAM_LOCATION_LIKE_THAT
Once again, disambiguation is natural, as enums are used as immediate
values while RAM locations are pointed to, moved, etc.


Disasm folder organization :
The main goal is to clarify the game's data organization and creation
process by reflecting them in the folder structure.
- Most data is considered as assets and gathered by type for a
bottom-up approach : graphics, sound, scripting, etc., need to be
created first in order to use them in maps, battles, cutscenes.
- In an opposite top-down approach, battles and maps are organized in an
"entry-oriented" way, to make each entry contain all that is specific to
the entry.
Editors can then edit assets individually, and point to them while
editing battle or map entries.
