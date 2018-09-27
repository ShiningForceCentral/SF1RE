static main()
{
    // Trap0_SoundCommand
    SetFunctionCmt(0x5fa, 
        "if xxxx = $FFFF, then get d0.w", 1);

    // sub_768
    SetFunctionCmt(0x768, 
        "executes if VINT_PARAMS bit 0 set", 1);

    // sub_7EC
    SetFunctionCmt(0x7ec, 
        "related to VINT_PARAMS bit 4", 1);

    // sub_82C
    SetFunctionCmt(0x82c, 
        "executes if VINT_PARAMS bit 3 set or bit 1 clear", 1);

    // WaitForDMAFree
    SetFunctionCmt(0xb9e, 
        "waits for 0xc00004 (VDP DMA register) to be cleared", 1);

    // GetVDPRegStatus
    SetFunctionCmt(0xbb2, 
        "d0 : vdp reg number", 1);

    // DuplicatePalettes
    SetFunctionCmt(0xc6c, 
        "Palette transfer ?", 1);

    // WaitForVInt
    SetFunctionCmt(0xe66, 
        "Wait until VInt func is called, i.e. next frame", 1);

    // Sleep
    SetFunctionCmt(0xe80, 
        "wait for D0 Vints/frames", 1);

    // SetVIntParam0
    SetFunctionCmt(0xe96, 
        "used to execute sub_768", 1);

    // sub_10D2
    SetFunctionCmt(0x10d2, 
        "DMA stuff. d0 = DMA destination ?", 1);

    // sub_1284
    SetFunctionCmt(0x1284, 
        "DMA preparation stuff", 1);

    // sub_1294
    SetFunctionCmt(0x1294, 
        "DMA stuff", 1);

    // sub_12BA
    SetFunctionCmt(0x12ba, 
        "DMA stuff", 1);

    // DMAVramFill
    SetFunctionCmt(0x12e6, 
        "d0:DMA destination - d1:DMA length - d2:sent to VDP Data", 1);

    // WriteAsciiNumber
    SetFunctionCmt(0x137e, 
        "write D0 into RAM:E80 to D7 places", 1);

    // UpdateRandomSeed
    SetFunctionCmt(0x14ee, 
        "Get random number from 0 to D6, returned in D7", 1);

    // PlayMusicAfterCurrentOne
    SetFunctionCmt(0x150e, 
        "d0 : music index, or previous music if value $FB", 1);

    // CopyBytes
    SetFunctionCmt(0x1526, 
        "    Copy D7 bytes from A0 to A1.\n\
    In: A0 = src address\n\
        A1 = dest address\n\
        D7 = number of bytes to copy", 1);

    // InitSprites
    SetFunctionCmt(0x1550, 
        "In: D0 = number of sprites\n\
\n\
set default values in sprite table", 1);

    // sub_1856
    SetFunctionCmt(0x1856, 
        "something with clearing/resetting sprite info when transitioning to battle scene?", 1);

    // LoadText
    SetFunctionCmt(0x2046, 
        "d0 : string index", 1);

    // GetEventFlag
    SetFunctionCmt(0x3082, 
        "Get event flag D0", 1);

    // FindBattleMember
    SetFunctionCmt(0x73d4, 
        "Find battle member with index D2", 1);

    // sub_8DE2
    SetFunctionCmt(0x8de2, 
        "Update screen after tile changes", 1);

    // sub_9602
    SetFunctionCmt(0x9602, 
        "Wrapper for 9626 - Set tile D3,D4 to D0", 1);

    // sub_96FC
    SetFunctionCmt(0x96fc, 
        "Change chest tile to open at D1,D2", 1);

    // sub_9718
    SetFunctionCmt(0x9718, 
        "Change chest tile to closed at D1,D2", 1);

    // sub_ACE4
    SetFunctionCmt(0xace4, 
        "Check if boss dead", 1);

    // sub_ADA6
    SetFunctionCmt(0xada6, 
        "Wrapper for ADEO, loads position and calls ADB8", 1);

    // sub_ADB8
    SetFunctionCmt(0xadb8, 
        "Get coordinates of tile sprite is facing D1,D2", 1);

    // sub_AE36
    SetFunctionCmt(0xae36, 
        "Display window? D0 = XXXXWWHH D1=? D2=?", 1);

    // sub_12C62
    SetFunctionCmt(0x12c62, 
        "Teleport map sprite (on same map?)", 1);

    // sub_17E34
    SetFunctionCmt(0x17e34, 
        "Dialog Scripts", 1);

    // InitDecoder
    SetFunctionCmt(0x1efe0, 
        "Initialize Huffman decoder\n\
- clear Huffman (script) data\n\
- set starting tree", 1);

    // sub_20404
    SetFunctionCmt(0x20404, 
        "Compute distance to reachable squares given D1=Y,D2=X, calls 20432", 1);

    // sub_20432
    SetFunctionCmt(0x20432, 
        "Compute distance to reachable squares given A0 offset", 1);

    // sub_20506
    SetFunctionCmt(0x20506, 
        "Load Terrain Data to RAM (xACC0)", 1);

    // sub_2053E
    SetFunctionCmt(0x2053e, 
        "Clear occupied squares from valid targets (bits 0 and 1 of D4 determine if enemy and force should be cleared respectively)", 1);

    // sub_20584
    SetFunctionCmt(0x20584, 
        "Prepare to compute move cost of character D0, loads class and terrain data", 1);

    // sub_2059E
    SetFunctionCmt(0x2059e, 
        "Similar to 20584 but from land effect data instead of class", 1);

    // sub_205AC
    SetFunctionCmt(0x205ac, 
        "Wrapper for 205B2 and 205DE", 1);

    // sub_205B2
    SetFunctionCmt(0x205b2, 
        "Mark all squares that within move range as passable and stoppable", 1);

    // sub_205DE
    SetFunctionCmt(0x205de, 
        "Clear stoppable flag of all occupied squares", 1);

    // sub_2061C
    SetFunctionCmt(0x2061c, 
        "Set only squares with distance A to B as passable (A and B on stack)", 1);

    // sub_207BC
    SetFunctionCmt(0x207bc, 
        "Reset Tile Flags and load from 207CA", 1);

    // sub_20802
    SetFunctionCmt(0x20802, 
        "Clear tile flags of tile under member D0", 1);

    // sub_20822
    SetFunctionCmt(0x20822, 
        "Clear tile flags and then mark all tiles within 2 of member D0 as passable?", 1);

    // sub_20868
    SetFunctionCmt(0x20868, 
        "Compute distance up to 3 of tiles around D1,D2", 1);

    // sub_208DE
    SetFunctionCmt(0x208de, 
        "Compute movement cost to all tiles for member D0", 1);

    // sub_2091A
    SetFunctionCmt(0x2091a, 
        "Mark all occupied squares as unreachable", 1);

    // CalculateDistance
    SetFunctionCmt(0x2097a, 
        "Computes distance (DX+DY) of two points stored in D1,D2 and D5,D6 and returns as D7", 1);

    // GetDistanceToTarget
    SetFunctionCmt(0x20994, 
        "Computes distance between D1,D2 and member D0 and returns as D7", 1);

    // GetDistanceBetweenTargets
    SetFunctionCmt(0x209b0, 
        "Get distance between members D0 and D1 -> D7", 1);

    // FindTargetAtPosition
    SetFunctionCmt(0x209ca, 
        "Find member at D1,D2 and store in D0", 1);

    // sub_20BDC
    SetFunctionCmt(0x20bdc, 
        "Effect Handler (calls 20C1C)", 1);

    // sub_20C1C
    SetFunctionCmt(0x20c1c, 
        "Effect Code Routine", 1);

    // sub_20C40
    SetFunctionCmt(0x20c40, 
        "Reset Effect Values", 1);

    // ActionEffect_Heal
    SetFunctionCmt(0x20c50, 
        "Heal Effect Routine", 1);

    // IsHealer
    SetFunctionCmt(0x20ce2, 
        "Check if healer class", 1);

    // CapEXPToGain
    SetFunctionCmt(0x20d08, 
        "Cap EXP at 48", 1);

    // ActionEffect_Antidote
    SetFunctionCmt(0x20d18, 
        "Antidote/Detox effect routine", 1);

    // ActionEffect_PhysicalAttack
    SetFunctionCmt(0x20d7c, 
        "Physical attack routine", 1);

    // sub_20DF4
    SetFunctionCmt(0x20df4, 
        "Death Routine", 1);

    // sub_20E4A
    SetFunctionCmt(0x20e4a, 
        "Get death message depending on if force or enemy", 1);

    // sub_20E6A
    SetFunctionCmt(0x20e6a, 
        "Get experience for killing enemy based on level difference", 1);

    // LoadCoinsToGain
    SetFunctionCmt(0x20e96, 
        "Load coins for killing enemy", 1);

    // LoadItemToDrop
    SetFunctionCmt(0x20eba, 
        "Give Jogurt ring if Jogurt kills enemy and hasn't been given", 1);

    // sub_20EF6
    SetFunctionCmt(0x20ef6, 
        "Doom Blade Effect Routine", 1);

    // sub_20FBA
    SetFunctionCmt(0x20fba, 
        "Spell Failure Message", 1);

    // sub_20FD4
    SetFunctionCmt(0x20fd4, 
        "Status Effect Message", 1);

    // ActionEffect_Desoul
    SetFunctionCmt(0x21034, 
        "Desoul Routine", 1);

    // CalculateDamage
    SetFunctionCmt(0x210f0, 
        "Calculate physical damage D3", 1);

    // CheckCriticalHit
    SetFunctionCmt(0x21128, 
        "Check for critical", 1);

    // sub_21152
    SetFunctionCmt(0x21152, 
        "Prepare critical message", 1);

    // ApplyDamageSpread
    SetFunctionCmt(0x21180, 
        "Apply damage spread to D3", 1);

    // ApplyLandEffect
    SetFunctionCmt(0x211a8, 
        "Apply land effect to damage D3", 1);

    // ApplyElemResist
    SetFunctionCmt(0x211c6, 
        "Apply elemental resistance D2 to damage D3", 1);

    // GetTargetResistance
    SetFunctionCmt(0x211e6, 
        "Get battle member D1 resistance flags D2 -> D2", 1);

    // IsSpellNullified
    SetFunctionCmt(0x211fc, 
        "Check if spell nullified by barrier", 1);

    // CheckEvasion
    SetFunctionCmt(0x21224, 
        "Evasion check", 1);

    // IsAbleToEvade
    SetFunctionCmt(0x2126a, 
        "Check if asleep and laser eye or dark dragon", 1);

    // UpdateRandomSeed0To100
    SetFunctionCmt(0x212a6, 
        "Get random number 0 to 100, returned in D7", 1);

    // CheckStatusFailure
    SetFunctionCmt(0x212b6, 
        "Check for status effect failure", 1);

    // CalculateLevelDifference
    SetFunctionCmt(0x212de, 
        "Get difference between target level", 1);

    // sub_212FA
    SetFunctionCmt(0x212fa, 
        "Get Sleep/Death resistance", 1);

    // sub_2130E
    SetFunctionCmt(0x2130e, 
        "Special Attack Routine", 1);

    // sub_21340
    SetFunctionCmt(0x21340, 
        "Doom Blade Special Attack Routine (6% death, or go back to normal attack)", 1);

    // sub_2138C
    SetFunctionCmt(0x2138c, 
        "Enemy Physical Attack", 1);

    // sub_21424
    SetFunctionCmt(0x21424, 
        "HP Steal Special Attack", 1);

    // sub_21460
    SetFunctionCmt(0x21460, 
        "Poison Causing Special Attack", 1);

    // sub_21484
    SetFunctionCmt(0x21484, 
        "Sleep Causing Special Attack", 1);

    // sub_214A8
    SetFunctionCmt(0x214a8, 
        "Special animation if Max kills last Dark Dragon head with Chaos Breaker", 1);

    // sub_21520
    SetFunctionCmt(0x21520, 
        "Setup attack animation members", 1);

    // sub_2154C
    SetFunctionCmt(0x2154c, 
        "Add battle animation member", 1);

    // sub_2157A
    SetFunctionCmt(0x2157a, 
        "Add battle animation target", 1);

    // sub_215A0
    SetFunctionCmt(0x215a0, 
        "Setup battle animation data", 1);

    // sub_215C8
    SetFunctionCmt(0x215c8, 
        "Setup battle animation data", 1);

    // sub_215F2
    SetFunctionCmt(0x215f2, 
        "Wrapper for 215C8", 1);

    // sub_215FC
    SetFunctionCmt(0x215fc, 
        "Copy battle animation data", 1);

    // sub_2160E
    SetFunctionCmt(0x2160e, 
        "Copy battle animation data 2", 1);

    // sub_21620
    SetFunctionCmt(0x21620, 
        "Setup Battle Messages", 1);

    // sub_21640
    SetFunctionCmt(0x21640, 
        "End of battle action (award money, break items, give exp, drop item)", 1);

    // sub_21744
    SetFunctionCmt(0x21744, 
        "Add empty battle action", 1);

    // sub_21934
    SetFunctionCmt(0x21934, 
        "Check if battle member (D0) and battle member (A3) are on different team, if so load to D1", 1);

    // sub_2195E
    SetFunctionCmt(0x2195e, 
        "Check for double attack", 1);

    // sub_219C0
    SetFunctionCmt(0x219c0, 
        "Attack cleanup - clear item dropped, set to single attack if first will kill enemy", 1);

    // sub_219E6
    SetFunctionCmt(0x219e6, 
        "Check if damage will kill target", 1);

    // sub_219FC
    SetFunctionCmt(0x219fc, 
        "Check for dispel status", 1);

    // sub_21A4E
    SetFunctionCmt(0x21a4e, 
        "Apply chance of curse", 1);

    // InitGameSettings
    SetFunctionCmt(0x21aee, 
        "Game init routine", 1);

    // sub_21BDC
    SetFunctionCmt(0x21bdc, 
        "Clear battle member table", 1);

    // sub_21C9C
    SetFunctionCmt(0x21c9c, 
        "Add character/enemy D1 to battle member table slot D0, copy stats", 1);

    // sub_21CCE
    SetFunctionCmt(0x21cce, 
        "Find empty slot in battle data table", 1);

    // LoadBattleStats
    SetFunctionCmt(0x21cf2, 
        "Load member into battle data table", 1);

    // GetEnemyEntryAddress
    SetFunctionCmt(0x21ff0, 
        "Gets address of enemy's data (D1) into monster data table if enemy exists", 1);

    // IsInForce
    SetFunctionCmt(0x220b8, 
        "Checks if member D0 is in force", 1);

    // JoinBattleParty
    SetFunctionCmt(0x2210e, 
        "Add D0 to current force", 1);

    // LeaveBattleParty
    SetFunctionCmt(0x22132, 
        "Remove D0 from current force", 1);

    // GetEmptyActiveForceSlot
    SetFunctionCmt(0x22158, 
        "Get empty slot in current force to D2", 1);

    // JoinForce
    SetFunctionCmt(0x221ae, 
        "Add character D0 to force (if not already)     ", 1);

    // IsInForce_0
    SetFunctionCmt(0x221d4, 
        "Checks if member D0 is in force", 1);

    // sub_22232
    SetFunctionCmt(0x22232, 
        "Set Max's stats in battle test mode", 1);

    // GetTargetID
    SetFunctionCmt(0x22298, 
        "Get battle member (D0) ID to D1 if member exists, else D1=FFFF", 1);

    // GetTargetX
    SetFunctionCmt(0x222b0, 
        "Get battle member (D0) X to D1 if member exists, else D1=FFFF", 1);

    // GetTargetY
    SetFunctionCmt(0x222ca, 
        "Get battle member (D0) Y to D1 if member exists, else D1=FFFF", 1);

    // GetTargetATT
    SetFunctionCmt(0x222e4, 
        "Get battle member (D0) attack to D1 if member exists, else D1=FFFF", 1);

    // GetTargetDEF
    SetFunctionCmt(0x222fe, 
        "Get battle member (D0) defense to D1 if member exists, else D1=FFFF", 1);

    // GetTargetAGI
    SetFunctionCmt(0x22318, 
        "Get battle member (D0) agility to D1 if member exists, else D1=FFFF", 1);

    // GetTargetMOVE
    SetFunctionCmt(0x22332, 
        "Get battle member (D0) move to D1 if member exists, else D1=FFFF", 1);

    // GetTargetCRIT
    SetFunctionCmt(0x2234c, 
        "Get battle member (D0) crit to D1 if member exists, else D1=FFFF", 1);

    // GetTargetDoubleAttack
    SetFunctionCmt(0x22366, 
        "Get battle member (D0) double attack setting to D1 if member exists, else D1=FFFF", 1);

    // GetTargetPosition
    SetFunctionCmt(0x22380, 
        "Get position of member D0 -> X to D2, Y to D1", 1);

    // GetStatusCounter
    SetFunctionCmt(0x22390, 
        "Get section D1 of force member status (calls 2250E)", 1);

    // GetForceMemberClass
    SetFunctionCmt(0x223a0, 
        "Get force member (D0) Class to D1", 1);

    // GetForceMemberLevel
    SetFunctionCmt(0x223b4, 
        "Get force member (D0) level to D1", 1);

    // GetForceMemberATT
    SetFunctionCmt(0x223c8, 
        "Get force member (D0) attack to D1", 1);

    // GetForceMemberDEF
    SetFunctionCmt(0x223dc, 
        "Get force member (D0) defense to D1", 1);

    // GetForceMemberAGI
    SetFunctionCmt(0x223f0, 
        "Get force member (D0) agility to D1", 1);

    // GetForceMemberMOVE
    SetFunctionCmt(0x22404, 
        "Get force member (D0) move to D1", 1);

    // GetForceMemberCRIT
    SetFunctionCmt(0x22418, 
        "Get force member (D0) crit to D1", 1);

    // GetForceMemberEXP
    SetFunctionCmt(0x2242c, 
        "Get force member (D0) EXP to D1", 1);

    // GetForceMemberMaxHP
    SetFunctionCmt(0x22440, 
        "Get force member (D0) Max HP to D1", 1);

    // GetForceMemberHP
    SetFunctionCmt(0x22452, 
        "Get force member (D0) HP to D1", 1);

    // GetForceMemberMaxMP
    SetFunctionCmt(0x22464, 
        "Get force member (D0) Max MP to D1", 1);

    // GetForceMemberMP
    SetFunctionCmt(0x22478, 
        "Get force member (D0) MP to D1", 1);

    // GetForceMemberStatus
    SetFunctionCmt(0x2248c, 
        "Get force member (D0) status to D1", 1);

    // GetClassFromForceID
    SetFunctionCmt(0x2249e, 
        "Get class by force index D0 -> D1", 1);

    // GetLevelFromForceID
    SetFunctionCmt(0x224ac, 
        "Get level by force index", 1);

    // GetATTFromForceID
    SetFunctionCmt(0x224ba, 
        "Get ATT by force index", 1);

    // GetDEFFromForceID
    SetFunctionCmt(0x224c8, 
        "Get DEF by force index", 1);

    // GetAGIFromForceID
    SetFunctionCmt(0x224d6, 
        "Get AGI by force index", 1);

    // GetMOVEFromForceID
    SetFunctionCmt(0x224e4, 
        "Get MOVE by force index", 1);

    // GetCRITFromForceID
    SetFunctionCmt(0x224f2, 
        "Get CRIT by force index", 1);

    // GetEXPFromForceID
    SetFunctionCmt(0x22500, 
        "Get EXP by force index", 1);

    // GetStatusFromForceID
    SetFunctionCmt(0x2250e, 
        "Get status by force index", 1);

    // GetMaxHPFromForceID
    SetFunctionCmt(0x2251c, 
        "Get max HP by force index", 1);

    // GetHPFromForceID
    SetFunctionCmt(0x2252a, 
        "Get HP by force index", 1);

    // GetMaxMPFromForceID
    SetFunctionCmt(0x22538, 
        "Get max MP by force index", 1);

    // GetMPFromForceID
    SetFunctionCmt(0x22546, 
        "Get MP by force index", 1);

    // GetForceStatsAddress
    SetFunctionCmt(0x22554, 
        "Get Address from 225F2 + 0 (Stats) of force member", 1);

    // GetForceItemsAddress
    SetFunctionCmt(0x22562, 
        "Get Address from 225F2 + x1A (Items) of force member", 1);

    // GetForceSpellsAddress
    SetFunctionCmt(0x22574, 
        "Get Address from 225F2 + x1E (Spells) of force member", 1);

    // GetForceStatsFromForceID
    SetFunctionCmt(0x22586, 
        "Get Address from 225F2 + 0 (Stats) by force index", 1);

    // GetForceItemsFromForceID
    SetFunctionCmt(0x22594, 
        "Get Address from 225F2 + x1A (Items) by force index", 1);

    // GetForceSpellsFromForceID
    SetFunctionCmt(0x225a2, 
        "Get Address from 225F2 + x1E (Spells) by force index", 1);

    // GetForceMemberID
    SetFunctionCmt(0x225b0, 
        "Get ID of force member", 1);

    // FindTarget
    SetFunctionCmt(0x225c4, 
        "Get ram address ot stats matching ID D1", 1);

    // GetTargetEntryAddress
    SetFunctionCmt(0x225e0, 
        "Get ram address of target's stats", 1);

    // GetForceEntryAddress
    SetFunctionCmt(0x225f2, 
        "Get ram address of force member's stats", 1);

    // IsEnemy
    SetFunctionCmt(0x22610, 
        "Test battle member ID to see if force or enemy", 1);

    // LoadClassName
    SetFunctionCmt(0x22620, 
        "Load class name of battle member to A1", 1);

    // SetTargetID
    SetFunctionCmt(0x22654, 
        "Set battle member (D0) ID to D1", 1);

    // SetTargetX
    SetFunctionCmt(0x22664, 
        "Set battle member (D0) X to D1", 1);

    // SetTargetY
    SetFunctionCmt(0x22676, 
        "Set battle member (D0) Y to D1", 1);

    // SetTargetATT
    SetFunctionCmt(0x22688, 
        "Set battle member (D0) attack to D1", 1);

    // SetTargetDEF
    SetFunctionCmt(0x2269a, 
        "Set battle member (D0) defense to D1", 1);

    // SetTargetAGI
    SetFunctionCmt(0x226ac, 
        "Set battle member (D0) agility to D1", 1);

    // SetTargetMOVE
    SetFunctionCmt(0x226be, 
        "Set battle member (D0) move to D1", 1);

    // SetTargetCRIT
    SetFunctionCmt(0x226d0, 
        "Set battle member (D0) crit to D1", 1);

    // SetTargetDoubleAttack
    SetFunctionCmt(0x226e2, 
        "Set battle member (D0) double attack setting to D1", 1);

    // SetTargetPosition
    SetFunctionCmt(0x226f4, 
        "Set battle member (D0) X to D2, Y to D1", 1);

    // SetTargetStatus
    SetFunctionCmt(0x22708, 
        "Set battle member (D0) Status section D1 to D2", 1);

    // SetForceMemberClass
    SetFunctionCmt(0x2272c, 
        "Set force member (D0) class to D1", 1);

    // SetForceMemberLevel
    SetFunctionCmt(0x2273e, 
        "Set force member (D0) level to D1", 1);

    // SetForceMemberATT
    SetFunctionCmt(0x22750, 
        "Set force member (D0) attack to D1", 1);

    // SetForceMemberDEF
    SetFunctionCmt(0x22762, 
        "Set force member (D0) defense to D1", 1);

    // SetForceMemberAGI
    SetFunctionCmt(0x22774, 
        "Set force member (D0) agility to D1", 1);

    // SetForceMemberMOVE
    SetFunctionCmt(0x22786, 
        "Set force member (D0) move to D1", 1);

    // SetForceMemberCRIT
    SetFunctionCmt(0x22798, 
        "Set force member (D0) crit to D1", 1);

    // SetForceMemberEXP
    SetFunctionCmt(0x227aa, 
        "Set force member (D0) EXP to D1", 1);

    // SetForceMemberMaxHP
    SetFunctionCmt(0x227bc, 
        "Set force member (D0) Max HP to D1", 1);

    // SetForceMemberHP
    SetFunctionCmt(0x227ce, 
        "Set force member (D0) HP to D1", 1);

    // SetForceMemberMaxMP
    SetFunctionCmt(0x227e0, 
        "Set force member (D0) Max MP to D1", 1);

    // SetForceMemberMP
    SetFunctionCmt(0x227f2, 
        "Set force member (D0) MP to D1", 1);

    // SetForceMemberStatus
    SetFunctionCmt(0x22804, 
        "Set force member (D0) Status to D1", 1);

    // SetClassFromForceID
    SetFunctionCmt(0x22816, 
        "Set class by force index", 1);

    // SetLevelFromForceID
    SetFunctionCmt(0x22824, 
        "Set level by force index", 1);

    // SetATTFromForceID
    SetFunctionCmt(0x22832, 
        "Set ATT by force index", 1);

    // SetDEFFromForceID
    SetFunctionCmt(0x22840, 
        "Set DEF by force index", 1);

    // SetAGIFromForceID
    SetFunctionCmt(0x2284e, 
        "Set AGI by force index", 1);

    // SetMOVEFromForceID
    SetFunctionCmt(0x2285c, 
        "Set MOVE by force index", 1);

    // SetCRITFromForceID
    SetFunctionCmt(0x2286a, 
        "Set CRIT by force index", 1);

    // SetEXPFromForceID
    SetFunctionCmt(0x22878, 
        "Set EXP by force index", 1);

    // SetMaxHPFromForceID
    SetFunctionCmt(0x22886, 
        "Set max HP by force index", 1);

    // SetHPFromForceID
    SetFunctionCmt(0x22894, 
        "Set HP by force index", 1);

    // SetMaxMPFromForceID
    SetFunctionCmt(0x228a2, 
        "Set max MP by force index", 1);

    // SetMPFromForceID
    SetFunctionCmt(0x228b0, 
        "Set MP by force index", 1);

    // SetStatusFromForceID
    SetFunctionCmt(0x228be, 
        "Set status by force index", 1);

    // LoadForceMemberName
    SetFunctionCmt(0x228cc, 
        "Load member name from A0 into stats table", 1);

    // IncreaseTargetATT
    SetFunctionCmt(0x228e6, 
        "Add D1 to battle member (D0) attack, capping at 99", 1);

    // IncreaseTargetDEF
    SetFunctionCmt(0x22910, 
        "Add D1 to battle member (D0) defense, capping at 99", 1);

    // IncreaseTargetAGI
    SetFunctionCmt(0x2293a, 
        "Add D1 to battle member (D0) agility, capping at 99", 1);

    // IncreaseTargetMOVE
    SetFunctionCmt(0x22964, 
        "Add D1 to battle member (D0) move, capping at 9", 1);

    // IncreaseTargetCRIT
    SetFunctionCmt(0x2298e, 
        "Add D1 to battle member (D0) crit, capping at 99", 1);

    // IncreaseForceMemberLevel
    SetFunctionCmt(0x229b8, 
        "Add D1 to force member (D0) level, capping at 99", 1);

    // IncreaseForceMemberATT
    SetFunctionCmt(0x229e2, 
        "Add D1 to force member (D0) attack, capping at 99", 1);

    // IncreaseForceMemberDEF
    SetFunctionCmt(0x22a0c, 
        "Add D1 to force member (D0) defense, capping at 99", 1);

    // IncreaseForceMemberAGI
    SetFunctionCmt(0x22a36, 
        "Add D1 to force member (D0) agility, capping at 99", 1);

    // IncreaseForceMemberMOVE
    SetFunctionCmt(0x22a60, 
        "Add D1 to force member (D0) move, capping at 9", 1);

    // IncreaseForceMemberCRIT
    SetFunctionCmt(0x22a8a, 
        "Add D1 to force member (D0) crit, capping at 99", 1);

    // IncreaseForceMemberMaxHP
    SetFunctionCmt(0x22ab4, 
        "Add D1 to force member (D0) Max HP, capping at 99", 1);

    // IncreaseForceMemberHP
    SetFunctionCmt(0x22adc, 
        "Add D1 to force member (D0) HP, capping at Max HP", 1);

    // IncreaseForceMemberMaxMP
    SetFunctionCmt(0x22b06, 
        "Add D1 to force member (D0) Max MP, capping at 99", 1);

    // IncreaseLevelFromForceID
    SetFunctionCmt(0x22b30, 
        "Add D1 to level by force index", 1);

    // IncreaseATTFromForceID
    SetFunctionCmt(0x22b3e, 
        "Add D1 to attack by force index", 1);

    // IncreaseDEFFromForceID
    SetFunctionCmt(0x22b4c, 
        "Add D1 to defense by force index", 1);

    // IncreaseAGIFromForceID
    SetFunctionCmt(0x22b5a, 
        "Add D1 to agility by force index", 1);

    // IncreaseMOVEFromForceID
    SetFunctionCmt(0x22b68, 
        "Add D1 to move by force index", 1);

    // IncreaseCRITFromForceID
    SetFunctionCmt(0x22b76, 
        "Add D1 to crit by force index", 1);

    // IncreaseEXPFromForceID
    SetFunctionCmt(0x22b84, 
        "Add D1 to experience by force index", 1);

    // IncreaseMaxHPFromForceID
    SetFunctionCmt(0x22b92, 
        "Add D1 to max HP by force index", 1);

    // IncreaseHPFromForceID
    SetFunctionCmt(0x22ba0, 
        "Add D1 to current HP by force index", 1);

    // IncreaseMaxMPFromForceID
    SetFunctionCmt(0x22bae, 
        "Add D1 to max MP by force index", 1);

    // IncreaseMPFromForceID
    SetFunctionCmt(0x22bbc, 
        "Add D1 to current MP by force index", 1);

    // IncreaseForceMemberMP
    SetFunctionCmt(0x22bca, 
        "Add D1 to force member (D0) MP, capping at Max MP", 1);

    // IncreaseForceMemberEXP
    SetFunctionCmt(0x22c00, 
        "Add D1 to force member (D0) EXP, capping at 99 if at max level", 1);

    // DecreaseTargetATT
    SetFunctionCmt(0x22c5e, 
        "Sub D1 from battle member (D0) attack", 1);

    // DecreaseTargetDEF
    SetFunctionCmt(0x22c66, 
        "Sub D1 from battle member (D0) defense", 1);

    // DecreaseTargetAGI
    SetFunctionCmt(0x22c6e, 
        "Sub D1 from battle member (D0) agility", 1);

    // DecreaseTargetMOVE
    SetFunctionCmt(0x22c76, 
        "Sub D1 from battle member (D0) move", 1);

    // DecreaseForceMemberMaxHP
    SetFunctionCmt(0x22c7e, 
        "Sub D1 from force member (D0) Max HP", 1);

    // DecreaseForceMemberMaxMP
    SetFunctionCmt(0x22c86, 
        "Sub D1 from force member (D0) Max MP", 1);

    // DecreaseForceMemberATT
    SetFunctionCmt(0x22c8e, 
        "Sub D1 from force member (D0) attack", 1);

    // DecreaseForceMemberDEF
    SetFunctionCmt(0x22c96, 
        "Sub D1 from force member (D0) defense", 1);

    // DecreaseForceMemberAGI
    SetFunctionCmt(0x22c9e, 
        "Sub D1 from force member (D0) agility", 1);

    // DecreaseForceMemberMOVE
    SetFunctionCmt(0x22ca6, 
        "Sub D1 from force member (D0) move", 1);

    // DecreaseForceMemberHP
    SetFunctionCmt(0x22cae, 
        "Sub D1 from force member (D0) HP", 1);

    // DecreaseForceMemberMP
    SetFunctionCmt(0x22cb6, 
        "Sub D1 from force member (D0) MP", 1);

    // DecreaseMaxHPFromForceID
    SetFunctionCmt(0x22cbe, 
        "Sub D1 from max HP by force index", 1);

    // DecreaseMaxMPFromForceID
    SetFunctionCmt(0x22ccc, 
        "Sub D1 from max MP by force index", 1);

    // DecreaseATTFromForceID
    SetFunctionCmt(0x22cda, 
        "Sub D1 from attack by force index", 1);

    // DecreaseDEFFromForceID
    SetFunctionCmt(0x22ce8, 
        "Sub D1 from defense by force index", 1);

    // DecreaseAGIFromForceID
    SetFunctionCmt(0x22cf6, 
        "Sub D1 from agility by force index", 1);

    // DecreaseMOVEFromForceID
    SetFunctionCmt(0x22d04, 
        "Sub D1 from move by force index", 1);

    // DecreaseHPFromForceID
    SetFunctionCmt(0x22d12, 
        "Sub D1 from current HP by force index", 1);

    // DecreaseMPFromForceID
    SetFunctionCmt(0x22d20, 
        "Sub D1 from current MP by force index", 1);

    // FindEmptyItemSlot
    SetFunctionCmt(0x22d2e, 
        "Find first empty item slot of member (D0), and give D1 if available", 1);

    // FindEmptyItemSlotFromTargetID
    SetFunctionCmt(0x22d58, 
        "Find first empty item slot to D1 by force index", 1);

    // RemoveItem
    SetFunctionCmt(0x22d70, 
        "Remove Item D1 from member D0 and rotate remaining down", 1);

    // RemoveItemFromTargetID
    SetFunctionCmt(0x22d9e, 
        "Remove Item D1 by force index", 1);

    // CountEmptyItemSlots
    SetFunctionCmt(0x22db6, 
        "Count empty item slots of member (D0) to D1", 1);

    // CountEmptyItemSlotsFromTargetID
    SetFunctionCmt(0x22dde, 
        "Count empty item slots to D1 by force index", 1);

    // BreakItem
    SetFunctionCmt(0x22df2, 
        "Break Item D1 of member D0", 1);

    // BreakItemFromTargetID
    SetFunctionCmt(0x22e0c, 
        "Break Item D1 by force index", 1);

    // GetEquippedItemFromForceID
    SetFunctionCmt(0x22e24, 
        "Get equipped item matching flags D1 by force index D0 -> D2", 1);

    // EquipItemFromForceID
    SetFunctionCmt(0x22e36, 
        "Equip item D2 by force index", 1);

    // LoadEquippableItemsFromForceID
    SetFunctionCmt(0x22e48, 
        "Load list of equippable items by force index", 1);

    // IsItemEquippableFromForceID
    SetFunctionCmt(0x22e5a, 
        "Check if item D2 can be equipped by force index", 1);

    // IsItemUnequippableFromForceID
    SetFunctionCmt(0x22e6c, 
        "Check if can't unequip by force index", 1);

    // GetItemEntryAddress
    SetFunctionCmt(0x22e7e, 
        "Get address of item D1 entry -> A1", 1);

    // GetItemType
    SetFunctionCmt(0x22e92, 
        "Get word-sized type flags of item D1 -> D2", 1);

    // GetItemPrice
    SetFunctionCmt(0x22ea8, 
        "Get price of item D1 -> D2", 1);

    // sub_22EB6
    SetFunctionCmt(0x22eb6, 
        "Prepare RAM Offsets for attack effect", 1);

    // GetEquippedItem
    SetFunctionCmt(0x22ec0, 
        "Get equipped item matching flags D1 of force member D0 -> D2", 1);

    // EquipItem
    SetFunctionCmt(0x22efe, 
        "Equip item D2 on character D0, unequip old item", 1);

    // LoadEquippableItems
    SetFunctionCmt(0x22f36, 
        "Load list of equippable items on character D0", 1);

    // IsItemEquippable
    SetFunctionCmt(0x22f7a, 
        "Check if item D2 can be equipped by character D0", 1);

    // IsItemUnequippable
    SetFunctionCmt(0x22fa6, 
        "Check if character D0 can't unequip", 1);

    // sub_22FD8
    SetFunctionCmt(0x22fd8, 
        "Item D2 can't be unequipped", 1);

    // IsEnemyAndHasItemToDrop
    SetFunctionCmt(0x22ff2, 
        "Check if battle member is an enemy and has items to drop", 1);

    // GetSpellEntryAddress
    SetFunctionCmt(0x23040, 
        "Get address of spell D1 entry -> A1", 1);

    // GetMPCost
    SetFunctionCmt(0x23056, 
        "Get MP cost of spell D1 -> D2", 1);

    // GetRangeEntryAddress
    SetFunctionCmt(0x23068, 
        "Get address of range D4 entry -> A1", 1);

    // sub_2307A
    SetFunctionCmt(0x2307a, 
        "Find targetable squares from range D4", 1);

    // sub_230F2
    SetFunctionCmt(0x230f2, 
        "Like 2307A?", 1);

    // GetAdjustedGroupFlags
    SetFunctionCmt(0x23136, 
        "Check if caster D0 is enemy and adjust group flags D4 accordingly", 1);

    // sub_23160
    SetFunctionCmt(0x23160, 
        "Jump to range/equip effect routine", 1);

    // sub_2337A
    SetFunctionCmt(0x2337a, 
        "Stat increasing item routine", 1);

    // sub_233E6
    SetFunctionCmt(0x233e6, 
        "Cure poison of character D0", 1);

    // EquipEffect_IncreaseATT
    SetFunctionCmt(0x23418, 
        "Add D5 to battle member (D0) attack", 1);

    // EquipEffect_IncreaseDEF
    SetFunctionCmt(0x23426, 
        "Add D5 to battle member (D0) defense", 1);

    // EquipEffect_IncreaseAGI
    SetFunctionCmt(0x23434, 
        "Add D5 to battle member (D0) agility", 1);

    // EquipEffect_IncreaseMOVE
    SetFunctionCmt(0x23442, 
        "Add D5 to battle member (D0) move", 1);

    // sub_23450
    SetFunctionCmt(0x23450, 
        "Add D5 to force member (D0) HP", 1);

    // sub_2345E
    SetFunctionCmt(0x2345e, 
        "Add D5 to force member (D0) MP", 1);

    // sub_2346C
    SetFunctionCmt(0x2346c, 
        "Add D5 to force member (D0) Max HP", 1);

    // sub_2347A
    SetFunctionCmt(0x2347a, 
        "Add D5 to force member (D0) attack", 1);

    // sub_23488
    SetFunctionCmt(0x23488, 
        "Add D5 to force member (D0) defense", 1);

    // sub_23496
    SetFunctionCmt(0x23496, 
        "Add D5 to force member (D0) agility", 1);

    // sub_234A4
    SetFunctionCmt(0x234a4, 
        "Add D5 to force member (D0) move", 1);

    // EquipEffect_IncreaseATTAndSetCRIT
    SetFunctionCmt(0x234b2, 
        "Add D5 to battle member (D0) attack, set crit to 13", 1);

    // EquipEffect_IncreaseATTAndDEF
    SetFunctionCmt(0x234ca, 
        "Add D5 to battle member (D0) attack, set double attack setting to High", 1);

    // EquipEffect_SetJogurtStatus
    SetFunctionCmt(0x2350a, 
        "Set Jogurt status to battle member (D0)", 1);

    // sub_2352A
    SetFunctionCmt(0x2352a, 
        "Level Up Party (Kindan NoHako)", 1);

    // sub_23566
    SetFunctionCmt(0x23566, 
        "Compute movable area, everywhere if above 9 MOVE", 1);

    // IsForceOrEnemy
    SetFunctionCmt(0x23594, 
        "Check if battle member D0 is force or enemy and return in D4", 1);

    // sub_235A8
    SetFunctionCmt(0x235a8, 
        "Get effect, range and targetable squares for attack", 1);

    // sub_235BA
    SetFunctionCmt(0x235ba, 
        "Prepare effect,range etc for attack", 1);

    // UseItem
    SetFunctionCmt(0x2361e, 
        "Use item D1", 1);

    // GetItemUseRangeAndEffect
    SetFunctionCmt(0x23660, 
        "Get use range and effect of item D1", 1);

    // sub_23684
    SetFunctionCmt(0x23684, 
        "Select item D1 of character D0", 1);

    // sub_236A6
    SetFunctionCmt(0x236a6, 
        "Get effect, range and targetable squares for current spell", 1);

    // sub_236B8
    SetFunctionCmt(0x236b8, 
        "Prepare effect,range of spell", 1);

    // sub_236F0
    SetFunctionCmt(0x236f0, 
        "Get effect, range and targetable squares for current action", 1);

    // sub_23772
    SetFunctionCmt(0x23772, 
        "Compute movable area based on class and terrain", 1);

    // sub_238CC
    SetFunctionCmt(0x238cc, 
        "Get D1th entry from table which is stored with length values, return in D1", 1);

    // GetSpellName
    SetFunctionCmt(0x238ea, 
        "Get name of spell D1", 1);

    // GetClassName
    SetFunctionCmt(0x238f6, 
        "Get name of class D1", 1);

    // sub_238FE
    SetFunctionCmt(0x238fe, 
        "Load data from 238CC into A1", 1);

    // GetClassEntryAddress
    SetFunctionCmt(0x23914, 
        "Get address of class D1 entry -> A0", 1);

    // GetMoveCostEntryAddress
    SetFunctionCmt(0x23928, 
        "Get offset into Move Cost Table based on class of member D0", 1);

    // GetLandEffectEntryAddress
    SetFunctionCmt(0x23930, 
        "Get offset into Land Effect Table based on class of member D0", 1);

    // GetResistance
    SetFunctionCmt(0x23956, 
        "Get resistance D2", 1);

    // sub_2397C
    SetFunctionCmt(0x2397c, 
        "Get class special bit 5", 1);

    // GetClassDoubleAttack
    SetFunctionCmt(0x23998, 
        "Get class special bits 3+4", 1);

    // sub_239B2
    SetFunctionCmt(0x239b2, 
        "Check if flying", 1);

    // sub_239D2
    SetFunctionCmt(0x239d2, 
        "Get portrait by force index", 1);

    // sub_239DE
    SetFunctionCmt(0x239de, 
        "Get portrait (checks for jogurt and promoted)", 1);

    // GetMapSpriteFromForceID
    SetFunctionCmt(0x23a3e, 
        "Get map sprite by force index", 1);

    // GetMapSprite
    SetFunctionCmt(0x23a4a, 
        "Get map sprite of battle member (D0), Checks Jogurt change, adds 30 if promoted", 1);

    // ApplyOutfitToMapSprite
    SetFunctionCmt(0x23a94, 
        "Apply outfits to map sprite", 1);

    // sub_23B24
    SetFunctionCmt(0x23b24, 
        "Load battle sprite and palette IDs in RAM", 1);

    // IsChangedIntoJogurt
    SetFunctionCmt(0x23c6c, 
        "Check if character D0 is under Jogurt status effect", 1);

    // sub_23F6E
    SetFunctionCmt(0x23f6e, 
        "Check action type", 1);

    // sub_2401C
    SetFunctionCmt(0x2401c, 
        "Cast spell AI", 1);

    // sub_24062
    SetFunctionCmt(0x24062, 
        "Caster AI : prepare to cast spell D1", 1);

    // sub_240BC
    SetFunctionCmt(0x240bc, 
        "Dark Dragon AI", 1);

    // sub_240E8
    SetFunctionCmt(0x240e8, 
        "Use item AI", 1);

    // sub_24170
    SetFunctionCmt(0x24170, 
        "Load range data", 1);

    // sub_2425C
    SetFunctionCmt(0x2425c, 
        "Trigger AI regions (or set AI regions to trigger?)", 1);

    // GetLandEffectAtTargetPosition
    SetFunctionCmt(0x24608, 
        "Get land effect % of tile under battle member D0 -> D1", 1);

    // GetLandEffectAtCoord
    SetFunctionCmt(0x24616, 
        "Get land effect % of tile (X D2, Y D1) -> D1", 1);

    // GetTerrainAtCoordAddress
    SetFunctionCmt(0x24646, 
        "Get address of terrain under tile (X D2, Y D1) -> A0", 1);

    // IncreaseStatsFromForceID
    SetFunctionCmt(0x246f8, 
        "Increase stats on level up by force index", 1);

    // IncreaseStatsOnLevelUp
    SetFunctionCmt(0x24708, 
        "Increase stats for force member D0 on level up", 1);

    // CalculateStatGain
    SetFunctionCmt(0x247f0, 
        "Calculate maximum increase of stat given target D1, current D2 and level D3", 1);

    // ShowLevelUpMessages
    SetFunctionCmt(0x24852, 
        "Show level up messages", 1);

    // Promote
    SetFunctionCmt(0x24912, 
        "Promote Character (Save Level Promoted to A16A table, add 16 to class)", 1);

    // CalculateTotalStatGrowth
    SetFunctionCmt(0x249d8, 
        "Compute total stat growth D1 for character D0", 1);

    // CalculatePromotedBaseStats
    SetFunctionCmt(0x249fc, 
        "Calculate contribution of prepromoted levels to stat growth D1 for character D0", 1);

    // MapGrowthToStatOffset
    SetFunctionCmt(0x24a2e, 
        "Maps stat growth D1 to stat offset D3", 1);

    // CalculateGrowthTarget
    SetFunctionCmt(0x24a44, 
        "Compute growth target value based on level D1 and growth value D2", 1);

    // CalculateGrowthPercent
    SetFunctionCmt(0x24a56, 
        "Compute growth percent based on level D1 and growth value D2", 1);

    // GetStatGrowthAddress
    SetFunctionCmt(0x24aa2, 
        "Get stat growth address based on if promoted", 1);

    // GetCharacterEntryAddress
    SetFunctionCmt(0x24ac4, 
        "Get address of character's initial data", 1);

    // IsPromoted
    SetFunctionCmt(0x24ada, 
        "Check if force member is promoted", 1);

    // GetPromotedAtLevel
    SetFunctionCmt(0x24ae6, 
        "Gets level character promoted at (0 if not promoted)", 1);

    // LearnSpell
    SetFunctionCmt(0x24afe, 
        "Learn new spell on level up", 1);

    // AddSpell
    SetFunctionCmt(0x24b30, 
        "Add spell D1 to character D0", 1);

    // GetSpellLearningEntryAddress
    SetFunctionCmt(0x24b62, 
        "Get address of character D0 spells learning data to A0", 1);

    // CalculateTotalLevel
    SetFunctionCmt(0x24b8c, 
        "Get total level of character D0 (Level + Promoted at Level)", 1);

    // CalculateEffectiveLevel
    SetFunctionCmt(0x24bac, 
        "Get level of character D0 (+10 if promoted)", 1);

    // IsAsleep
    SetFunctionCmt(0x24bd2, 
        "Check if character D0 asleep", 1);

    // sub_24BF2
    SetFunctionCmt(0x24bf2, 
        "Buff/Boost Type Statuses Routine", 1);

    // sub_24CA6
    SetFunctionCmt(0x24ca6, 
        "Status Helper, sets RAM Bits for messages?", 1);

    // sub_24CBA
    SetFunctionCmt(0x24cba, 
        "Poison Routine", 1);

    // sub_24CEE
    SetFunctionCmt(0x24cee, 
        "Sleep Routine", 1);

    // ResetForceMemberStats
    SetFunctionCmt(0x24d0e, 
        "Clear statuses of all members and restore HP/MP to max", 1);

    // DecrementStatusCounter
    SetFunctionCmt(0x24d44, 
        "Decrement Status D1 counter, check for end", 1);

    // ClearStatusBitRandomly
    SetFunctionCmt(0x24d74, 
        "Clear Status bit D1, 50% of the time", 1);

    // sub_24D9E
    SetFunctionCmt(0x24d9e, 
        "Status Message Handler", 1);

    // GetGold
    SetFunctionCmt(0x24dbc, 
        "Get money to D1", 1);

    // SetGold
    SetFunctionCmt(0x24dc4, 
        "Set money to D1", 1);

    // IncreaseGold
    SetFunctionCmt(0x24dcc, 
        "Add D1 to money, cap at 999999", 1);

    // DecreaseGold
    SetFunctionCmt(0x24de8, 
        "Sub D1 from money, cap at 0", 1);

    // IncreaseDealsItemStock
    SetFunctionCmt(0x24dfe, 
        "Add 1 to deals stock of item (D1)", 1);

    // DecreaseDealsItemStock
    SetFunctionCmt(0x24e1c, 
        "Sub 1 from deals stock of item (D1)", 1);

    // GetDealsItemStock
    SetFunctionCmt(0x24e2a, 
        "Get deals stock of item (D1) to D2", 1);

    // SetDealsItemStock
    SetFunctionCmt(0x24e44, 
        "Set deals stock of item (D1) to D2", 1);

    // GetDealsItemEntryAddress
    SetFunctionCmt(0x24e64, 
        "Get address into deals table from item id (D1)", 1);

    // GetDealsStockList
    SetFunctionCmt(0x24e74, 
        "Get list of all items in deal stock", 1);

    // IsItemInDealsOrHeldByForce
    SetFunctionCmt(0x24ec4, 
        "Check if item D1 not in deal stock and held by any character", 1);

    // IsItemHeldByCharacter
    SetFunctionCmt(0x24eda, 
        "Check if character has item D1", 1);

    // IsItemHeldByForce
    SetFunctionCmt(0x24efe, 
        "Check if any character has item D1", 1);

    // LoadATTFromForceID
    SetFunctionCmt(0x24f1a, 
        "Load force member attack to battle stats table", 1);

    // LoadDEFFromForceID
    SetFunctionCmt(0x24f2c, 
        "Load force member defense to battle stats table", 1);

    // LoadAGIFromForceID
    SetFunctionCmt(0x24f3e, 
        "Load force member agility to battle stats table", 1);

    // LoadMOVEFromForceID
    SetFunctionCmt(0x24f50, 
        "Load force member move to battle stats table", 1);

    // LoadCRITFromForceID
    SetFunctionCmt(0x24f62, 
        "Load force member crit to battle stats table", 1);

    // RefillHPFromTargetID
    SetFunctionCmt(0x24f98, 
        "Set HP to max by force index", 1);

    // RefillMPFromTargetID
    SetFunctionCmt(0x24fae, 
        "Set MP to max by force index", 1);

    // sub_24FC4
    SetFunctionCmt(0x24fc4, 
        "Clear RAM Table A4C0", 1);

    // sub_24FE6
    SetFunctionCmt(0x24fe6, 
        "Wrapper for 25026 and 24FEC", 1);

    // sub_24FEC
    SetFunctionCmt(0x24fec, 
        "Clear terrain values (ACC0) at map borders", 1);

    // sub_25026
    SetFunctionCmt(0x25026, 
        "Load map size and terrain data", 1);

    // sub_250DA
    SetFunctionCmt(0x250da, 
        "Clear terrain values at occupied squares", 1);

    // sub_2510A
    SetFunctionCmt(0x2510a, 
        "Reset walkable areas (A4C0) and initialize from A0", 1);

    // sub_26E16
    SetFunctionCmt(0x26e16, 
        "Prepare Ending Sequence", 1);

    // sub_26E7E
    SetFunctionCmt(0x26e7e, 
        "Load Animation D1 of Ending Sequence", 1);

    // sub_27036
    SetFunctionCmt(0x27036, 
        "Flag AI Regions as triggered", 1);

    // sub_80EE0
    SetFunctionCmt(0x80ee0, 
        "Load address into table at 80EFE based on byte D of sprite data", 1);

}
