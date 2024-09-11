static main()
{
    // Trap0_SoundCommand
    SetFunctionCmt(0x5fa, 
        "if parameter = -1, then get command from d0.w", 1);

    // VInt
    SetFunctionCmt(0x6d8, 
        "Vertical Interrupt", 1);

    // HInt
    SetFunctionCmt(0xb9c, 
        "Horizontal Interrupt", 1);

    // WaitDmaEnd
    SetFunctionCmt(0xb9e, 
        "waits for 0xc00004 (VDP DMA register) to be cleared", 1);

    // GetVdpRegStatus
    SetFunctionCmt(0xbb2, 
        "VDP Reg Status -> D0", 1);

    // ApplyVIntCramDma
    SetFunctionCmt(0xc8a, 
        "VDP CRAM", 1);

    // WaitForVInt
    SetFunctionCmt(0xe66, 
        "Wait until VInt function is called, i.e., next frame", 1);

    // Sleep
    SetFunctionCmt(0xe80, 
        "Wait for D0 frames", 1);

    // ApplyVIntVramDma
    SetFunctionCmt(0x10d2, 
        "A0=Source, A1=Destination, D0=Length, D1=Auto-increment", 1);

    // UpdateVdpVScrollData
    SetFunctionCmt(0x11f8, 
        "VDP Vertical Scroll Data", 1);

    // ApplyImmediateVramDmaOnCompressedTiles
    SetFunctionCmt(0x125c, 
        "A0=Source, A1=Destination, D0=Length, D1=Auto-increment", 1);

    // sub_1294
    SetFunctionCmt(0x1294, 
        "DMA code", 1);

    // sub_12BA
    SetFunctionCmt(0x12ba, 
        "DMA code", 1);

    // ApplyVramDmaFill
    SetFunctionCmt(0x12e6, 
        "D0=Destination, D1=Length, D2=Filler value", 1);

    // GenerateRandomNumber
    SetFunctionCmt(0x14ee, 
        "In: D6 = Value range, Out: D7 = Random value", 1);

    // PlayMusicAfterCurrentOne
    SetFunctionCmt(0x150e, 
        "d0 : music index, or previous music if value $FB", 1);

    // CopyBytes
    SetFunctionCmt(0x1526, 
        "A0=Source, A1=Destination, D7=Length", 1);

    // InitSprites
    SetFunctionCmt(0x1550, 
        "D0 = Number of sprites to initialize", 1);

    // sub_1856
    SetFunctionCmt(0x1856, 
        "something with clearing/resetting sprite info when transitioning to battle scene?", 1);

    // LoadText
    SetFunctionCmt(0x2046, 
        "d0 : string index", 1);

    // GetEventFlag
    SetFunctionCmt(0x3082, 
        "Get event flag D0", 1);

    // sub_3284
    SetFunctionCmt(0x3284, 
        "Suspend game", 1);

    // sub_32EC
    SetFunctionCmt(0x32ec, 
        "Simone's ending speech", 1);

    // EndChapter
    SetFunctionCmt(0x3d80, 
        "End chapter", 1);

    // GetAdviceMessageOffset
    SetFunctionCmt(0x6078, 
        "Get offset to advice message index for current battle -> D0", 1);

    // LoadHeadquartersMapsprite
    SetFunctionCmt(0x689c, 
        "Load headquarters map sprite", 1);

    // LoadEndingCutsceneCombatantData
    SetFunctionCmt(0x6a7e, 
        "Load combatant data during ending cutscene.", 1);

    // FindCombatantSlot
    SetFunctionCmt(0x73d4, 
        "Find force member D2 combatant slot number -> D0 if exists, else D0 = $FFFFFFFF", 1);

    // optionMenuAction_Quit
    SetFunctionCmt(0x7aa6, 
        "Battle menu action : Quit", 1);

    // LoadCursorSpriteData
    SetFunctionCmt(0x87d2, 
        "In: d1.w, d2.w = cursor X, Y speed", 1);

    // sub_9602
    SetFunctionCmt(0x9602, 
        "Wrapper for 9626 - Set tile D3,D4 to D0", 1);

    // sub_96FC
    SetFunctionCmt(0x96fc, 
        "Change chest tile to open at D1,D2", 1);

    // sub_9718
    SetFunctionCmt(0x9718, 
        "Change chest tile to closed at D1,D2", 1);

    // CheckBattleEnd
    SetFunctionCmt(0xace4, 
        "Check if boss dead", 1);

    // sub_ADA6
    SetFunctionCmt(0xada6, 
        "Wrapper for ADEO, loads position and calls ADB8", 1);

    // sub_ADB8
    SetFunctionCmt(0xadb8, 
        "Get coordinates of tile sprite is facing D1,D2", 1);

    // MoveWindow
    SetFunctionCmt(0xae3a, 
        "In: D0 = size WWHH\n\
    D1 = origin/destination XXYYXXYY\n\
    D2 = animation frames length", 1);

    // CreateWindow
    SetFunctionCmt(0xaea8, 
        "In: A0 = layout, D0 = size WWHH, D1 = position XXYY", 1);

    // sub_B030
    SetFunctionCmt(0xb030, 
        "Clear window properties?", 1);

    // WriteTilesFromNumber
    SetFunctionCmt(0xb042, 
        "Write tiles from number D0 into A1 : D7 letters, window width D1", 1);

    // WriteTilesFromAscii
    SetFunctionCmt(0xb054, 
        "Write tiles from ASCII at A0 to A1 : D7 letters, window width D1", 1);

    // GetIconTilesAddress
    SetFunctionCmt(0xc6c6, 
        "In: A2 = icons tiles pointer\n\
    A3 = entity items/spells address\n\
    D1 = item/spell slot\n\
\n\
Out: A0 = icon tiles address", 1);

    // CapMiniStatusBarLength
    SetFunctionCmt(0xd21e, 
        "In: D2 = current HP or MP value\n\
    D3 = max HP or MP value", 1);

    // sub_D32C
    SetFunctionCmt(0xd32c, 
        "Show battle menu action refusal text", 1);

    // LoadPortrait
    SetFunctionCmt(0xe156, 
        "Load portrait tiles.", 1);

    // ExecuteShopScreen
    SetFunctionCmt(0xe49e, 
        "Out: D0 = selected item index if it exists, else D0 = $FFFFFFFF", 1);

    // sub_11126
    SetFunctionCmt(0x11126, 
        "Set sprite direction", 1);

    // sub_11D84
    SetFunctionCmt(0x11d84, 
        "Load map sprite", 1);

    // sub_12C62
    SetFunctionCmt(0x12c62, 
        "Teleport map sprite (on same map?)", 1);

    // DisplayPortraitInMenu
    SetFunctionCmt(0x168d8, 
        "Display portrait in menu", 1);

    // ExecuteShopMenu
    SetFunctionCmt(0x168fe, 
        "In: D0 = current shop index\n\
    D1 = \n\
    D2 = ", 1);

    // CheckGold
    SetFunctionCmt(0x16dae, 
        "Check if enough gold to pay price D0 -> D2 = 1 if true", 1);

    // ExecuteChurchMenu
    SetFunctionCmt(0x17028, 
        "In: D1 =\n\
    D2 = ", 1);

    // sub_17E34
    SetFunctionCmt(0x17e34, 
        "Dialog Scripts", 1);

    // GiveItemToHero
    SetFunctionCmt(0x17ed6, 
        "Used in dialogue scripts", 1);

    // CutsceneFunction_SetSpeechSfx
    SetFunctionCmt(0x17f64, 
        "Cutscene Function : SetSpeechSfx", 1);

    // CutsceneFunction_JoinForce
    SetFunctionCmt(0x17fe0, 
        "Cutscene Function : JoinForce", 1);

    // sub_18046
    SetFunctionCmt(0x18046, 
        "Display yes/no prompt", 1);

    // sub_18056
    SetFunctionCmt(0x18056, 
        "Check yes/no", 1);

    // DialogueScript29
    SetFunctionCmt(0x1cbf4, 
        "Metapha (get Chaos Breaker)", 1);

    // InitDecoder
    SetFunctionCmt(0x1efe0, 
        "Initialize Huffman decoder\n\
- clear Huffman (script) data\n\
- set starting tree", 1);

    // MakeEffectiveMoveCosts
    SetFunctionCmt(0x20404, 
        "In: A0 = move cost entry address", 1);

    // PopulateTotalMoveCosts
    SetFunctionCmt(0x2040c, 
        "Setup registers to calculate and load total move costs to table at $FFA8C0\n\
\n\
In: D1 = moving combatant's Y\n\
    D2 = moving combatant's X\n\
    D3 = moving combatant's modified move * 2 (i.e., move points)", 1);

    // CalculateTotalMoveCosts
    SetFunctionCmt(0x20432, 
        "Calculate total move costs to reachable spaces, load to table at $FFA8C0\n\
\n\
In: A0 = passability flags entry address\n\
    D3 = moving combatant's modified move * 2 (i.e., move points)", 1);

    // LoadMoveCosts
    SetFunctionCmt(0x20506, 
        "Load move costs table given entry at A0, mapped to current terrain data", 1);

    // BlockSpacesOccupiedByOpponents
    SetFunctionCmt(0x2053e, 
        "Block spaces occupied by opponents (bits 0 and 1 of D4 determine if enemies or force members should be blocked, respectively)", 1);

    // SetupEffectiveMoveCosts
    SetFunctionCmt(0x20584, 
        "Setup registers to make effective move costs table for combatant D0", 1);

    // SetupTargetingMoveCosts
    SetFunctionCmt(0x2059e, 
        "Setup registers to make targeting move costs table", 1);

    // InitPassabilityFlags
    SetFunctionCmt(0x205b2, 
        "Initialize all spaces within move range as \"allowed to pass through\" and \"allowed to stay at\"", 1);

    // ClearAllowedToStayAtFlags
    SetFunctionCmt(0x205de, 
        "Clear \"allowed to stay at\" in passability flags table for all occupied spaces", 1);

    // MakeTargetingGrid
    SetFunctionCmt(0x2061c, 
        "Mark spaces within distances D2 to D1 as passable", 1);

    // sub_20692
    SetFunctionCmt(0x20692, 
        "In: A1 = current position into passability flags table", 1);

    // LoadLaserEyeTargetGrid
    SetFunctionCmt(0x207bc, 
        "Get Laser Eye's predefined target grid address, load to passability flags table", 1);

    // MakeTorchEyeTargetGrid
    SetFunctionCmt(0x20802, 
        "Make Torch Eye's special target grid, clear space occupied by combatant D0", 1);

    // MakeSpecialTargetGrid
    SetFunctionCmt(0x20822, 
        "Clear passability flags, mark all spaces within 2 of combatant D0 as targetable", 1);

    // sub_20868
    SetFunctionCmt(0x20868, 
        "Calculate distance up to 3 of tiles around D2,D1", 1);

    // CreateTotalMoveCosts
    SetFunctionCmt(0x208de, 
        "Make total move costs table for enemy combatant D0\n\
\n\
In: D3 = ", 1);

    // BlockAllOccupiedSpaces
    SetFunctionCmt(0x2091a, 
        "In: D3 = ", 1);

    // CalculateDistance
    SetFunctionCmt(0x2097a, 
        "Calculate distance measured in spaces between positions D2,D1 and D6,D5 -> D7", 1);

    // CalculateDistanceToTarget
    SetFunctionCmt(0x20994, 
        "Calculate distance between combatant D0 and position D2,D1 -> D7", 1);

    // CalculateDistanceBetweenCombatants
    SetFunctionCmt(0x209b0, 
        "Calculate distance between combatants D0 and D1 -> D7", 1);

    // IsSpaceOccupied
    SetFunctionCmt(0x209ca, 
        "Check if space at position D2,D1 is occupied by a combatant\n\
\n\
CCR: carry-bit set if true", 1);

    // DetermineLaserEyeAction
    SetFunctionCmt(0x20bdc, 
        "Effect Handler (calls 20C1C) -- Laser Eye range routine", 1);

    // StartBattleaction
    SetFunctionCmt(0x20c1c, 
        "In: d5.b = battleaction index", 1);

    // InitializeBattlesceneAftermath
    SetFunctionCmt(0x20c40, 
        "Clear experience, coins, and dropped items values.", 1);

    // EffectRoutine_Heal
    SetFunctionCmt(0x20c50, 
        "In: A0 = effect data address\n\
    D0 = caster index\n\
    D1 = target index", 1);

    // IsHealerClass
    SetFunctionCmt(0x20ce2, 
        "Check if caster D0 is a healer class -> CCR zero-bit set if true", 1);

    // HandleTargetDefeat
    SetFunctionCmt(0x20df4, 
        "In: D3 = calculated damage", 1);

    // LoadDeathMessage
    SetFunctionCmt(0x20e4a, 
        "Load death message depending on if target is force or enemy", 1);

    // CalculateKillExperience
    SetFunctionCmt(0x20e6a, 
        "Get experience for killing enemy based on level difference -> D2", 1);

    // LoadCoinsToGain
    SetFunctionCmt(0x20e96, 
        "Load coins for killing enemy", 1);

    // LoadItemToDrop
    SetFunctionCmt(0x20eba, 
        "Give Jogurt Ring if Jogurt kills an enemy and it hasn't been given yet", 1);

    // LoadEffectSuccessMessage
    SetFunctionCmt(0x20fd4, 
        "In: D1 = target index\n\
    D2 = status effect index", 1);

    // CalculateDamage
    SetFunctionCmt(0x210f0, 
        "Calculate physical attack damage -> D3", 1);

    // ApplyCriticalDamage
    SetFunctionCmt(0x21128, 
        "Determine critical hit, apply damage multiplier -> D3", 1);

    // ApplyDamageSpread
    SetFunctionCmt(0x21180, 
        "Apply damage spread to D3", 1);

    // ApplyLandEffect
    SetFunctionCmt(0x211a8, 
        "Apply land effect to damage D3", 1);

    // ApplyResistance
    SetFunctionCmt(0x211c6, 
        "Apply resistance to element D2 unto damage D3", 1);

    // GetTargetCombatantResistance
    SetFunctionCmt(0x211e6, 
        "Get combatant D1 resistance to element D2 -> D2", 1);

    // IsSpellNullified
    SetFunctionCmt(0x211fc, 
        "Check if spell is nullified by magic curtain", 1);

    // DetermineEvade
    SetFunctionCmt(0x21224, 
        "Determine whether targeted combatant D1 evades the attack\n\
\n\
      In: D0 = attacker index\n\
          D1 = target index\n\
\n\
      Out: CCR carry-bit set when successful", 1);

    // IsAbleToEvade
    SetFunctionCmt(0x2126a, 
        "Check if combatant D1 is able to evade attacks -> CCR carry-bit set if true", 1);

    // GenerateRandomNumber0To99
    SetFunctionCmt(0x212a6, 
        "Generate random number 0 to 99, returned in d7.w", 1);

    // DetermineEffectFailure
    SetFunctionCmt(0x212b6, 
        "In: D1 = target index\n\
    D2 = resistance index\n\
\n\
Out: CCR: carry-bit clear if successful", 1);

    // CalculateLevelDifference
    SetFunctionCmt(0x212de, 
        "Get level difference between attacker D0 and target D1 -> D1", 1);

    // IsVulnerableToInstantDeath
    SetFunctionCmt(0x212fa, 
        "Check if combatant D1 is vulnerable to instant death attacks", 1);

    // DetermineDarkDragonFinisher
    SetFunctionCmt(0x214a8, 
        "Perform a special animation if Max kills the last Dark Dragon head with the Chaos Breaker.", 1);

    // LoadBattlesceneActors
    SetFunctionCmt(0x21520, 
        "In: D0 = caster index\n\
    D1 = target index", 1);

    // sub_2154C
    SetFunctionCmt(0x2154c, 
        "Add battlescene member", 1);

    // sub_2157A
    SetFunctionCmt(0x2157a, 
        "Add battlescene target", 1);

    // sub_215A0
    SetFunctionCmt(0x215a0, 
        "Setup battlescene data", 1);

    // WriteBattlesceneCommand
    SetFunctionCmt(0x215c8, 
        "Setup battlescene data", 1);

    // sub_215F2
    SetFunctionCmt(0x215f2, 
        "Wrapper for 215C8", 1);

    // CopyBattlesceneData
    SetFunctionCmt(0x215fc, 
        "Copy battlescene data\n\
\n\
In: A0 = source\n\
    A2 = destination", 1);

    // sub_2160E
    SetFunctionCmt(0x2160e, 
        "Copy battlescene data 2", 1);

    // sub_21620
    SetFunctionCmt(0x21620, 
        "Setup Battle Messages", 1);

    // EndBattleaction
    SetFunctionCmt(0x21640, 
        "End of battle action (award money, break items, give exp, drop item)", 1);

    // NullBattleaction
    SetFunctionCmt(0x21744, 
        "Add empty battle action", 1);

    // ExecuteBattleaction
    SetFunctionCmt(0x21754, 
        "Battle action effect handler\n\
\n\
In: D0 = actor index\n\
    A0 = effect entry address\n\
    A1 = pointer to effect routine", 1);

    // sub_218D4
    SetFunctionCmt(0x218d4, 
        "Initialize amount of damage to inflict and status effects change", 1);

    // sub_218EE
    SetFunctionCmt(0x218ee, 
        "Initialize battle action data", 1);

    // IsTargetOpponent
    SetFunctionCmt(0x21934, 
        "Check if target is an opponent, get its combatant index -> d1.w if true, else -1\n\
\n\
In: a3 = target table entry address\n\
    d0.w = caster index", 1);

    // sub_219C0
    SetFunctionCmt(0x219c0, 
        "Attack cleanup - clear item dropped, set to single attack if first will kill enemy", 1);

    // CheckFatalDamage
    SetFunctionCmt(0x219e6, 
        "Check if damage will defeat target", 1);

    // CheckDispel
    SetFunctionCmt(0x219fc, 
        "Check if caster is under dispel status\n\
\n\
Out: CCR = Carry-bit set if true", 1);

    // DetermineCurseParalysis
    SetFunctionCmt(0x21a4e, 
        "Carry-bit set if paralysis occurs", 1);

    // GetEnemyPositionsPointer
    SetFunctionCmt(0x21bcc, 
        "Get enemy positions pointer -> A1", 1);

    // PopulateCombatantSlot
    SetFunctionCmt(0x21c9c, 
        "Populate combatant slot D0 with force member D1, and place them at coordinates A1", 1);

    // FindEmptyCombatantSlot
    SetFunctionCmt(0x21cce, 
        "Find first empty combatant slot -> D0\n\
\n\
CCR: carry-bit set if not found", 1);

    // LoadCombatantData
    SetFunctionCmt(0x21cf2, 
        "Load combatant D0 data", 1);

    // GetEnemyEntryAddress
    SetFunctionCmt(0x21ff0, 
        "Get enemy D0 (from enemies list) entry address -> A1 if they exists, carry-bit set if not", 1);

    // IsInForce
    SetFunctionCmt(0x220b8, 
        "Check if force member D0 has joined -> CCR zero-bit cleared if true", 1);

    // IsInForceAndBattleParty
    SetFunctionCmt(0x220c8, 
        "Check if force member D0 has joined and is in battle party\n\
\n\
    Out: D1 = 0 if not in battle party, 1 otherwise\n\
         CCR zero-bit set if member has not joined, cleared otherwise", 1);

    // IsInBattleParty
    SetFunctionCmt(0x220d0, 
        "Check if force member D0 is in battle party -> D1 = 0 if false, 1 if true", 1);

    // JoinBattleParty
    SetFunctionCmt(0x2210e, 
        "Add force member D0 to battle party", 1);

    // LeaveBattleParty
    SetFunctionCmt(0x22132, 
        "Remove force member D0 from battle party", 1);

    // GetEmptyBattlePartySlot
    SetFunctionCmt(0x22158, 
        "Get first empty slot in battle party -> D2", 1);

    // JoinForce
    SetFunctionCmt(0x221ae, 
        "Add character D0 to force (if not already)     ", 1);

    // dup_IsInForce
    SetFunctionCmt(0x221d4, 
        "Check if force member D0 has joined (duplicate)", 1);

    // GetEntity
    SetFunctionCmt(0x22298, 
        "Get combatant d0.w entity index -> d1.w if they exist, else -1", 1);

    // GetCombatantX
    SetFunctionCmt(0x222b0, 
        "Get combatant d0.w X -> d1.w if they exist, else -1", 1);

    // GetCombatantY
    SetFunctionCmt(0x222ca, 
        "Get combatant d0.w Y -> d1.w if they exist, else -1", 1);

    // GetModifiedAttack
    SetFunctionCmt(0x222e4, 
        "Get combatant d0.w modified attack -> d1.w if they exist, else -1", 1);

    // GetModifiedDefense
    SetFunctionCmt(0x222fe, 
        "Get combatant d0.w modified defense -> d1.w if they exist, else -1", 1);

    // GetModifiedAgility
    SetFunctionCmt(0x22318, 
        "Get combatant d0.w modified agility -> d1.w if they exist, else -1", 1);

    // GetModifiedMove
    SetFunctionCmt(0x22332, 
        "Get combatant d0.w modified move -> d1.w if they exist, else -1", 1);

    // GetModifiedCritical
    SetFunctionCmt(0x2234c, 
        "Get combatant d0.w modified critical -> d1.w if they exist, else -1", 1);

    // GetModifiedDoubleAttackMode
    SetFunctionCmt(0x22366, 
        "Get combatant d0.w modified double attack mode -> d1.w if they exist, else -1", 1);

    // GetCombatantPosition
    SetFunctionCmt(0x22380, 
        "Get combatant d0.w position X,Y -> d2,d1.w", 1);

    // GetStatusEffectCounter
    SetFunctionCmt(0x22390, 
        "Get force member's status effect bitfield d1.w for combatant d0.w -> d2.w", 1);

    // GetClass
    SetFunctionCmt(0x223a0, 
        "Get force member D0 class index -> D1", 1);

    // GetLevel
    SetFunctionCmt(0x223b4, 
        "Get force member D0 level -> D1", 1);

    // GetBaseAttack
    SetFunctionCmt(0x223c8, 
        "Get force member D0 base attack -> D1", 1);

    // GetBaseDefense
    SetFunctionCmt(0x223dc, 
        "Get force member D0 base defense -> D1", 1);

    // GetBaseAgility
    SetFunctionCmt(0x223f0, 
        "Get force member D0 base agility -> D1", 1);

    // GetBaseMove
    SetFunctionCmt(0x22404, 
        "Get force member D0 base move -> D1", 1);

    // GetBaseCritical
    SetFunctionCmt(0x22418, 
        "Get force member D0 base critical -> D1", 1);

    // GetExperience
    SetFunctionCmt(0x2242c, 
        "Get force member D0 experience -> D1", 1);

    // GetMaxHp
    SetFunctionCmt(0x22440, 
        "Get force member D0 max HP -> D1", 1);

    // GetCurrentHp
    SetFunctionCmt(0x22452, 
        "Get force member D0 current HP -> D1", 1);

    // GetMaxMP
    SetFunctionCmt(0x22464, 
        "Get force member D0 max MP -> D1", 1);

    // GetCurrentMP
    SetFunctionCmt(0x22478, 
        "Get force member D0 current MP -> D1", 1);

    // GetStatusEffects
    SetFunctionCmt(0x2248c, 
        "Get force member D0 status effects -> D1", 1);

    // GetClassForCombatant
    SetFunctionCmt(0x2249e, 
        "Get force member's class index for combatant D0 -> D1", 1);

    // GetLevelForCombatant
    SetFunctionCmt(0x224ac, 
        "Get force member's level for combatant D0 -> D1", 1);

    // GetBaseAttackForCombatant
    SetFunctionCmt(0x224ba, 
        "Get force member's base attack for combatant D0 -> D1", 1);

    // GetBaseDefenseForCombatant
    SetFunctionCmt(0x224c8, 
        "Get force member's base defense for combatant D0 -> D1", 1);

    // GetBaseAgilityForCombatant
    SetFunctionCmt(0x224d6, 
        "Get force member's base agility for combatant D0 -> D1", 1);

    // GetBaseMoveForCombatant
    SetFunctionCmt(0x224e4, 
        "Get force member's base move for combatant D0 -> D1", 1);

    // GetBaseCriticalForCombatant
    SetFunctionCmt(0x224f2, 
        "Get force member's base critical for combatant D0 -> D1", 1);

    // GetExperienceForCombatant
    SetFunctionCmt(0x22500, 
        "Get force member's experience for combatant D0 -> D1", 1);

    // GetStatusEffectsForCombatant
    SetFunctionCmt(0x2250e, 
        "Get force member's status effects for combatant D0 -> D1", 1);

    // GetMaxHpForCombatant
    SetFunctionCmt(0x2251c, 
        "Get entity's max HP for combatant D0 -> D1", 1);

    // GetCurrentHpForCombatant
    SetFunctionCmt(0x2252a, 
        "Get entity's current HP for combatant D0 -> D1", 1);

    // GetMaxMpForCombatant
    SetFunctionCmt(0x22538, 
        "Get entity's max MP from combatant D0 -> D1", 1);

    // GetCurrentMpForCombatant
    SetFunctionCmt(0x22546, 
        "Get entity's current MP for combatant D0 -> D1", 1);

    // GetEntityStatsAddress
    SetFunctionCmt(0x22554, 
        "Get entity D0 stats address -> A0", 1);

    // GetEntityItemsAddress
    SetFunctionCmt(0x22562, 
        "Get entity D0 items address -> A0", 1);

    // GetCharacterSpellsAddress
    SetFunctionCmt(0x22574, 
        "Get entity D0 spells address -> A0", 1);

    // GetEntityStatsAddressForCombatant
    SetFunctionCmt(0x22586, 
        "Get entity stats address for combatant D0 -> A0", 1);

    // GetEntityItemsAddressForCombatant
    SetFunctionCmt(0x22594, 
        "Get entity's items address for combatant D0 -> A0", 1);

    // GetEntitySpellsAddressForCombatant
    SetFunctionCmt(0x225a2, 
        "Get entity spells address for combatant D0 -> A0", 1);

    // alt_GetEntity
    SetFunctionCmt(0x225b0, 
        "Get combatant D0 entity index -> D0 (alternate implementation)", 1);

    // FindCombatantEntry
    SetFunctionCmt(0x225c4, 
        "Find force member D0 combatant entry address -> A0", 1);

    // GetCombatantEntryAddress
    SetFunctionCmt(0x225e0, 
        "Get combatant D0 entry address -> A0 (CCR zero-bit set if slot is empty)", 1);

    // GetEntityEntryAddress
    SetFunctionCmt(0x225f2, 
        "Get entity (force member or enemy) D0 data entry address -> A0", 1);

    // IsEnemy
    SetFunctionCmt(0x22610, 
        "Check if combatant D0 is an enemy -> CCR negative-bit set if true", 1);

    // GetDisplayedNameAddress
    SetFunctionCmt(0x22620, 
        "Get combatant D0 displayed name address (load class name if enemy)\n\
\n\
Out: A0 = name address for combatant\n\
     D1 = name length for combatant", 1);

    // SetEntityIndex
    SetFunctionCmt(0x22654, 
        "Set D1 -> combatant D0 entity index", 1);

    // SetCombatantX
    SetFunctionCmt(0x22664, 
        "Set D1 -> combatant D0 X", 1);

    // SetCombatantY
    SetFunctionCmt(0x22676, 
        "Set D1 -> combatant D0 Y", 1);

    // SetModifiedAttack
    SetFunctionCmt(0x22688, 
        "Set D1 -> combatant D0 modified attack", 1);

    // SetModifiedDefense
    SetFunctionCmt(0x2269a, 
        "Set D1 -> combatant D0 modified defense", 1);

    // SetModifiedAgility
    SetFunctionCmt(0x226ac, 
        "Set D1 -> combatant D0 modified agility", 1);

    // SetModifiedMove
    SetFunctionCmt(0x226be, 
        "Set D1 -> combatant D0 modified move", 1);

    // SetModifiedCritical
    SetFunctionCmt(0x226d0, 
        "Set D1 -> combatant D0 modified critical", 1);

    // SetModifiedDoubleAttackMode
    SetFunctionCmt(0x226e2, 
        "Set D1 -> combatant D0 modified double attack mode", 1);

    // SetCombatantPosition
    SetFunctionCmt(0x226f4, 
        "Set Y = D1, X = D2 -> combatant D0 position", 1);

    // SetStatusEffectCounter
    SetFunctionCmt(0x22708, 
        "Set D2 -> force member's status effect counter D1 for combatant D0", 1);

    // SetClass
    SetFunctionCmt(0x2272c, 
        "Set D1 -> force member D0 class index", 1);

    // SetLevel
    SetFunctionCmt(0x2273e, 
        "Set D1 -> force member D0 level", 1);

    // SetBaseAttack
    SetFunctionCmt(0x22750, 
        "Set D1 -> force member D0 base attack", 1);

    // SetBaseDefense
    SetFunctionCmt(0x22762, 
        "Set D1 -> force member D0 base defense", 1);

    // SetBaseAgility
    SetFunctionCmt(0x22774, 
        "Set D1 -> force member D0 base agility", 1);

    // SetBaseMove
    SetFunctionCmt(0x22786, 
        "Set D1 -> force member D0 base move", 1);

    // SetBaseCritical
    SetFunctionCmt(0x22798, 
        "Set D1 -> force member D0 base critical", 1);

    // SetExperience
    SetFunctionCmt(0x227aa, 
        "Set D1 -> force member D0 experience", 1);

    // SetMaxHp
    SetFunctionCmt(0x227bc, 
        "Set D1 -> force member D0 max HP", 1);

    // SetCurrentHp
    SetFunctionCmt(0x227ce, 
        "Set D1 -> force member D0 current HP", 1);

    // SetMaxMp
    SetFunctionCmt(0x227e0, 
        "Set D1 -> force member D0 max MP", 1);

    // SetCurrentMp
    SetFunctionCmt(0x227f2, 
        "Set D1 -> force member D0 current MP", 1);

    // SetStatusEffects
    SetFunctionCmt(0x22804, 
        "Set D1 -> force member D0 status effects", 1);

    // SetClassForCombatant
    SetFunctionCmt(0x22816, 
        "Set D1 -> force member's class index for combatant D0", 1);

    // SetLevelForCombatant
    SetFunctionCmt(0x22824, 
        "Set D1 -> force member's level for combatant D0", 1);

    // SetBaseAttackForCombatant
    SetFunctionCmt(0x22832, 
        "Set D1 -> force member's base attack for combatant D0", 1);

    // SetBaseDefenseForCombatant
    SetFunctionCmt(0x22840, 
        "Set D1 -> force member's base defense for combatant D0", 1);

    // SetBaseAgilityForCombatant
    SetFunctionCmt(0x2284e, 
        "Set D1 -> force member's base agility for combatant D0", 1);

    // SetBaseMoveForCombatant
    SetFunctionCmt(0x2285c, 
        "Set D1 -> force member's base move for combatant D0", 1);

    // SetBaseCriticalForCombatant
    SetFunctionCmt(0x2286a, 
        "Set D1 -> force member's base critical for combatant D0", 1);

    // SetExperienceForCombatant
    SetFunctionCmt(0x22878, 
        "Set D1 -> force member's experience for combatant D0", 1);

    // SetMaxHpForCombatant
    SetFunctionCmt(0x22886, 
        "Set D1 -> force member's max HP for combatant D0", 1);

    // SetCurrentHpForCombatant
    SetFunctionCmt(0x22894, 
        "Set D1 -> force member's current HP for combatant D0", 1);

    // SetMaxMpForCombatant
    SetFunctionCmt(0x228a2, 
        "Set D1 -> force member's max MP for combatant D0", 1);

    // SetCurrentMpForCombatant
    SetFunctionCmt(0x228b0, 
        "Set D1 -> force member's current MP for combatant D0", 1);

    // SetStatusEffectsForCombatant
    SetFunctionCmt(0x228be, 
        "Set D1 -> force member's status effects for combatant D0", 1);

    // LoadForceMemberName
    SetFunctionCmt(0x228cc, 
        "Load force member name from A0 into stats table", 1);

    // IncreaseModifiedAttack
    SetFunctionCmt(0x228e6, 
        "Add d1.w to combatant d0.w modified attack, capping at 99", 1);

    // IncreaseModifiedDefense
    SetFunctionCmt(0x22910, 
        "Add d1.w to combatant d0.w modified defense, capping at 99", 1);

    // IncreaseModifiedAgility
    SetFunctionCmt(0x2293a, 
        "Add d1.w to combatant d0.w modified agility, capping at 99", 1);

    // IncreaseModifiedMove
    SetFunctionCmt(0x22964, 
        "Add d1.w to combatant d0.w modified move, capping at 9", 1);

    // IncreaseModifiedCritical
    SetFunctionCmt(0x2298e, 
        "Add d1.w to combatant d0.w modified critical, capping at 99", 1);

    // IncreaseLevel
    SetFunctionCmt(0x229b8, 
        "Add d1.w to force member d0.w level, capping at 99", 1);

    // IncreaseBaseAttack
    SetFunctionCmt(0x229e2, 
        "Add d1.w to force member d0.w base attack, capping at 99", 1);

    // IncreaseBaseDefense
    SetFunctionCmt(0x22a0c, 
        "Add d1.w to force member d0.w base defense, capping at 99", 1);

    // IncreaseBaseAgility
    SetFunctionCmt(0x22a36, 
        "Add d1.w to force member d0.w base agility, capping at 99", 1);

    // IncreaseBaseMove
    SetFunctionCmt(0x22a60, 
        "Add d1.w to force member d0.w base move, capping at 9", 1);

    // IncreaseBaseCritical
    SetFunctionCmt(0x22a8a, 
        "Add d1.w to force member d0.w base critical, capping at 99", 1);

    // IncreaseMaxHp
    SetFunctionCmt(0x22ab4, 
        "Add d1.w to force member d0.w max HP, capping at 99", 1);

    // IncreaseCurrentHp
    SetFunctionCmt(0x22adc, 
        "Add d1.w to force member d0.w current HP, capping at max HP", 1);

    // IncreaseMaxMp
    SetFunctionCmt(0x22b06, 
        "Add d1.w to force member d0.w max MP, capping at 99", 1);

    // IncreaseLevelForCombatant
    SetFunctionCmt(0x22b30, 
        "Add D1 to force member's level for combatant D0", 1);

    // IncreaseBaseAttackForCombatant
    SetFunctionCmt(0x22b3e, 
        "Add D1 to force member's base attack for combatant D0", 1);

    // IncreaseBaseDefenseForCombatant
    SetFunctionCmt(0x22b4c, 
        "Add D1 to force member's base defense for combatant D0", 1);

    // IncreaseBaseAgilityForCombatant
    SetFunctionCmt(0x22b5a, 
        "Add D1 to force member's base agility for combatant D0", 1);

    // IncreaseBaseMoveForCombatant
    SetFunctionCmt(0x22b68, 
        "Add D1 to force member's base move for combatant D0", 1);

    // IncreaseBaseCriticalForCombatant
    SetFunctionCmt(0x22b76, 
        "Add D1 to force member's base critical for combatant D0", 1);

    // IncreaseExperienceForCombatant
    SetFunctionCmt(0x22b84, 
        "Add D1 to force member's experience for combatant D0", 1);

    // IncreaseMaxHpForCombatant
    SetFunctionCmt(0x22b92, 
        "Add D1 to force member's max HP for combatant D0", 1);

    // IncreaseCurrentHpForCombatant
    SetFunctionCmt(0x22ba0, 
        "Add D1 to force member's current HP for combatant D0", 1);

    // IncreaseMaxMpForCombatant
    SetFunctionCmt(0x22bae, 
        "Add D1 to force member's max MP for combatant D0", 1);

    // IncreaseCurrentMpForCombatant
    SetFunctionCmt(0x22bbc, 
        "Add D1 to force member's current MP for combatant D0", 1);

    // IncreaseCurrentMp
    SetFunctionCmt(0x22bca, 
        "Add d1.w to force member d0.w current MP, capping at max MP", 1);

    // IncreaseExperience
    SetFunctionCmt(0x22c00, 
        "Add D1 to force member D0 experience, capping at 99 if at level cap", 1);

    // IsAtLevelCap
    SetFunctionCmt(0x22c2e, 
        "Check if force member D0 has reached the level cap -> CCR carry-bit set if true", 1);

    // DecreaseModifiedAttack
    SetFunctionCmt(0x22c5e, 
        "Subtract D1 from combatant D0 modified attack", 1);

    // DecreaseModifiedDefense
    SetFunctionCmt(0x22c66, 
        "Subtract D1 from combatant D0 modified defense", 1);

    // DecreaseModifiedAgility
    SetFunctionCmt(0x22c6e, 
        "Subtract D1 from combatant D0 modified agility", 1);

    // DecreaseModifiedMove
    SetFunctionCmt(0x22c76, 
        "Subtract D1 from combatant D0 modified move", 1);

    // DecreaseMaxHp
    SetFunctionCmt(0x22c7e, 
        "Subtract D1 from force member D0 max HP", 1);

    // DecreaseMaxMp
    SetFunctionCmt(0x22c86, 
        "Subtract D1 from force member D0 max MP", 1);

    // DecreaseBaseAttack
    SetFunctionCmt(0x22c8e, 
        "Subtract D1 from force member D0 base attack", 1);

    // DecreaseBaseDefense
    SetFunctionCmt(0x22c96, 
        "Subtract D1 from force member D0 base defense", 1);

    // DecreaseBaseAgility
    SetFunctionCmt(0x22c9e, 
        "Subtract D1 from force member D0 base agility", 1);

    // DecreaseBaseMove
    SetFunctionCmt(0x22ca6, 
        "Subtract D1 from force member D0 base move", 1);

    // DecreaseCurrentHp
    SetFunctionCmt(0x22cae, 
        "Subtract D1 from force member D0 current HP", 1);

    // DecreaseCurrentMp
    SetFunctionCmt(0x22cb6, 
        "Subtract D1 from force member D0 current MP", 1);

    // DecreaseMaxHpForCombatant
    SetFunctionCmt(0x22cbe, 
        "Subtract D1 from force member's max HP for combatant D0", 1);

    // DecreaseMaxMpForCombatant
    SetFunctionCmt(0x22ccc, 
        "Subtract D1 from force member's max MP for combatant D0", 1);

    // DecreaseBaseAttackForCombatant
    SetFunctionCmt(0x22cda, 
        "Subtract D1 from force member's base attack for combatant D0", 1);

    // DecreaseBaseDefenseForCombatant
    SetFunctionCmt(0x22ce8, 
        "Subtract D1 from force member's base defense for combatant D0", 1);

    // DecreaseBaseAgilityForCombatant
    SetFunctionCmt(0x22cf6, 
        "Subtract D1 from force member's base agility for combatant D0", 1);

    // DecreaseBaseMoveForCombatant
    SetFunctionCmt(0x22d04, 
        "Subtract D1 from force member's base move for combatant D0", 1);

    // DecreaseCurrentHpForCombatant
    SetFunctionCmt(0x22d12, 
        "Subtract D1 from force member's current HP for combatant D0", 1);

    // DecreaseCurrentMpForCombatant
    SetFunctionCmt(0x22d20, 
        "Subtract D1 from force member's current MP for combatant D0", 1);

    // GiveItem
    SetFunctionCmt(0x22d2e, 
        "Move item D1 to force member D0 first empty item slot if available\n\
\n\
CCR: carry-bit set if empty item slot not found", 1);

    // GiveItemForCombatant
    SetFunctionCmt(0x22d58, 
        "Move item D1 to force member's first empty item slot for combatant D0 if available\n\
\n\
CCR: carry-bit set if empty item slot not found", 1);

    // RemoveItem
    SetFunctionCmt(0x22d70, 
        "Empty force member D0 item slot D1 and rotate remaining down", 1);

    // RemoveItemForCombatant
    SetFunctionCmt(0x22d9e, 
        "Empty force member's item slot D1 for combatant D0 and rotate remaining down", 1);

    // CountOccupiedItemSlots
    SetFunctionCmt(0x22db6, 
        "Count force member D0 empty item slots -> D1\n\
\n\
      CCR carry-bit set if all slots are occupied", 1);

    // CountOccupiedItemSlotsForCombatant
    SetFunctionCmt(0x22dde, 
        "Count force member's empty item slots for combatant D0 -> D1", 1);

    // BreakItem
    SetFunctionCmt(0x22df2, 
        "Break force member D0 item in slot D1", 1);

    // BreakItemForCombatant
    SetFunctionCmt(0x22e0c, 
        "Break force member's item in slot D1 for combatant D0", 1);

    // GetEquippedItemForCombatant
    SetFunctionCmt(0x22e24, 
        "Get item and slot indexes of a given type currently equipped by combatant\n\
\n\
    In: D0 = force member index\n\
        D1 = item type mask\n\
\n\
    Out: D2 = item index\n\
         D3 = item slot index\n\
         CCR carry-bit set if no equipped item found", 1);

    // EquipItemForCombatant
    SetFunctionCmt(0x22e36, 
        "Equip force member with item in slot D2 for combatant D0", 1);

    // LoadEquippableItemsForCombatant
    SetFunctionCmt(0x22e48, 
        "Load table of equippable items for combatant D0", 1);

    // IsItemEquippableForCombatant
    SetFunctionCmt(0x22e5a, 
        "Check if item D2 type D1 can be equipped for combatant D0", 1);

    // GetItemsCurseSettingsForCombatant
    SetFunctionCmt(0x22e6c, 
        "Check if force member is allowed to unequip for combatant D0", 1);

    // GetItemEntryAddress
    SetFunctionCmt(0x22e7e, 
        "Get address of item D1 entry -> A1", 1);

    // GetItemType
    SetFunctionCmt(0x22e92, 
        "Get item D1 word-sized type flags -> D2", 1);

    // GetItemPrice
    SetFunctionCmt(0x22ea8, 
        "Get price of item D1 -> D2", 1);

    // GetEquippedWeaponIndex
    SetFunctionCmt(0x22eb6, 
        "Out: d2.w, d3.w", 1);

    // GetEquippedItem
    SetFunctionCmt(0x22ec0, 
        "Get item and slot indexes of a given type currently equipped by entity\n\
\n\
    In: D0 = entity index\n\
        D1 = item type mask\n\
\n\
    Out: D2 = item entry\n\
         D3 = item slot index\n\
         CCR carry-bit set if no equipped item found", 1);

    // EquipItem
    SetFunctionCmt(0x22efe, 
        "Equip force member D0 with item type D1 in slot D2, unequip old item", 1);

    // LoadEquippableItems
    SetFunctionCmt(0x22f36, 
        "Load table of items equippable by force member D0", 1);

    // IsItemEquippable
    SetFunctionCmt(0x22f7a, 
        "Check if item D2 type D1 can be equipped by force member D0\n\
\n\
      Out: CCR carry-bit set if false", 1);

    // GetItemsCurseSettings
    SetFunctionCmt(0x22fa6, 
        "Get curse settings for all items equipped by entity D0 -> D1", 1);

    // GetItemCurseSetting
    SetFunctionCmt(0x22fd8, 
        "Get curse setting of item type D1 currently equipped by entity D0 -> D4", 1);

    // FindItemToDrop
    SetFunctionCmt(0x22ff2, 
        "Find enemy combatant d0.w item index to drop -> d1.w if it exists, else -1", 1);

    // GetSpellEntryAddress
    SetFunctionCmt(0x23040, 
        "Get address of spell D1 entry -> A1", 1);

    // GetMPCost
    SetFunctionCmt(0x23056, 
        "Get MP cost of spell D1 -> D2", 1);

    // GetRangeEntryAddress
    SetFunctionCmt(0x23068, 
        "Get address of range D4 entry -> A1", 1);

    // FindTargetableSpaces
    SetFunctionCmt(0x2307a, 
        "Find targetable spaces from range D4", 1);

    // FindTargetsWithinArea
    SetFunctionCmt(0x230f2, 
        "In: D0 = caster index\n\
    D1 = target index\n\
    D4 = range index", 1);

    // GetAdjustedGroupFlags
    SetFunctionCmt(0x23136, 
        "Check if casting combatant D0 is an enemy and adjust group flags D4 accordingly", 1);

    // AdjustGroupFlags
    SetFunctionCmt(0x23148, 
        "Convert group designation for enemy actions.", 1);

    // JumpToRangeOrEquipEffect
    SetFunctionCmt(0x23160, 
        "Jump to range/equip effect routine", 1);

    // IncreaseStatOnItemUse
    SetFunctionCmt(0x2337a, 
        "Stat increasing item routine\n\
\n\
      In: D0 = character index\n\
          D1 = stat index", 1);

    // CurePoison
    SetFunctionCmt(0x233e6, 
        "Cure poison of combatant D0", 1);

    // EquipEffect_IncreaseAttack
    SetFunctionCmt(0x23418, 
        "Add D5 to combatant D0 modified attack", 1);

    // EquipEffect_IncreaseDefense
    SetFunctionCmt(0x23426, 
        "Add D5 to combatant D0 modified defense", 1);

    // EquipEffect_IncreaseAgility
    SetFunctionCmt(0x23434, 
        "Add D5 to combatant D0 modified agility", 1);

    // EquipEffect_IncreaseMove
    SetFunctionCmt(0x23442, 
        "Add D5 to combatant D0 modified move", 1);

    // AfterTurn_RecoverHp
    SetFunctionCmt(0x23450, 
        "Add D5 to force member D0 current HP (not functional)", 1);

    // AfterTurn_RecoverMp
    SetFunctionCmt(0x2345e, 
        "Add D5 to force member D0 current MP (not functional)", 1);

    // AfterTurn_GainHp
    SetFunctionCmt(0x2346c, 
        "Add D5 to force member D0 max HP (not functional)", 1);

    // AfterTurn_GainAttack
    SetFunctionCmt(0x2347a, 
        "Add D5 to force member D0 base attack (not functional)", 1);

    // AfterTurn_GainDefense
    SetFunctionCmt(0x23488, 
        "Add D5 to force member D0 base defense (not functional)", 1);

    // AfterTurn_GainAgility
    SetFunctionCmt(0x23496, 
        "Add D5 to force member D0 base agility (not functional)", 1);

    // AfterTurn_GainMove
    SetFunctionCmt(0x234a4, 
        "Add D5 to force member D0 base move (not functional)", 1);

    // EquipEffect_IncreaseAttackSetCritical
    SetFunctionCmt(0x234b2, 
        "Add D5 to combatant D0 modified attack, set modified critical to 13", 1);

    // EquipEffect_IncreaseAttackAndDefense
    SetFunctionCmt(0x234ca, 
        "Add 4 to combatant D0 modified attack and 8 to modified defense", 1);

    // EquipEffect_SetJogurtStatus
    SetFunctionCmt(0x2350a, 
        "Set Jogurt status effect to combatant D0", 1);

    // KindanNoHako
    SetFunctionCmt(0x2352a, 
        "Level Up Party (Kindan NoHako)", 1);

    // CreateMovementGrid
    SetFunctionCmt(0x23566, 
        "Make movement area grid for combatant D0", 1);

    // IsForceMemberOrEnemy
    SetFunctionCmt(0x23594, 
        "Check if combatant D0 is force member or enemy, return in D4 (1 = enemy, 2 = force)", 1);

    // FindTargetableSpacesForAttack
    SetFunctionCmt(0x235a8, 
        "Find targetable spaces for \"attack\" battle action", 1);

    // Battleaction_Attack
    SetFunctionCmt(0x235ba, 
        "Prepare to attack (get attack range and effect, check for special attack)\n\
\n\
Out: D4 = attack range index\n\
     D5 = attack effect index", 1);

    // UseItem
    SetFunctionCmt(0x2361e, 
        "Use item D1 in battle", 1);

    // GetItemUseRangeAndEffect
    SetFunctionCmt(0x23660, 
        "Get item D1 use range and effect indexes -> D4 = range, D5 = effect", 1);

    // Battleaction_UseItem
    SetFunctionCmt(0x23684, 
        "Prepare to use item slot D1 from combatant D0 (load item index and slot number)\n\
\n\
Out: D4 = range index\n\
     D5 = effect index", 1);

    // FindTargetableSpacesForSpell
    SetFunctionCmt(0x236a6, 
        "Find targetable spaces for the \"cast spell\" battleaction.", 1);

    // Battleaction_CastSpell
    SetFunctionCmt(0x236b8, 
        "Prepare to cast spell D1 (load index, level and MP cost)\n\
\n\
Out: D4 = spell range index\n\
     D5 = spell effect index", 1);

    // SetupBattleaction
    SetFunctionCmt(0x236f0, 
        "Get effect, range and targetable spaces for current battleaction.", 1);

    // sub_23752
    SetFunctionCmt(0x23752, 
        "hardcoded \"GIVE\" item menu action range (?)", 1);

    // MakeMoveEverywhereGrid
    SetFunctionCmt(0x23772, 
        "Make movement area grid for combatant D0 when modified move is greater than 9 (i.e., force leader in battle test mode)", 1);

    // GetItemNameAddress
    SetFunctionCmt(0x238c2, 
        "Get item D1 name address and length\n\
\n\
Out: A0 = item name address\n\
     D1 = item name length", 1);

    // GetVariableLengthEntryAddress
    SetFunctionCmt(0x238cc, 
        "Get D1th entry address from table which is stored with length values\n\
\n\
Out: A0 = entry address\n\
     D1 = entry length", 1);

    // GetSpellNameAddress
    SetFunctionCmt(0x238ea, 
        "Get spell D1 name address and length\n\
\n\
Out: A0 = spell name address\n\
     D1 = spell name length", 1);

    // GetClassNameAddress
    SetFunctionCmt(0x238f6, 
        "Get class D1 name address and length\n\
\n\
Out: A0 = class name address\n\
     D1 = class name length", 1);

    // GetClassEntryAddress
    SetFunctionCmt(0x23914, 
        "Get class D1 entry address -> A0", 1);

    // GetMoveCostEntryAddress
    SetFunctionCmt(0x23928, 
        "Get combatant D0 move cost entry address -> A0", 1);

    // GetLandEffectEntryAddress
    SetFunctionCmt(0x23930, 
        "Get combatant D0 land effect entry address -> A0", 1);

    // GetResistance
    SetFunctionCmt(0x23956, 
        "Get combatant D0 resistance to element D1 -> D2", 1);

    // sub_2397C
    SetFunctionCmt(0x2397c, 
        "Get combatant d0.w special bit 6 from class (unused)\n\
\n\
Out: set: d1.w = 2 / clear: d1.w = 1", 1);

    // GetBaseDoubleAttackMode
    SetFunctionCmt(0x23998, 
        "Get combatant D0 base double attack mode from class -> D1", 1);

    // IsFlyingOrHovering
    SetFunctionCmt(0x239b2, 
        "Check if combatant D0 has flying or hovering move type", 1);

    // GetPortraitForCombatant
    SetFunctionCmt(0x239d2, 
        "Get entity's portrait index for combatant D0 -> D1", 1);

    // GetPortrait
    SetFunctionCmt(0x239de, 
        "Get entity D0 portrait index -> D1 (check if changed into jogurt or promoted)", 1);

    // GetMapSpriteForCombatant
    SetFunctionCmt(0x23a3e, 
        "Get entity's map sprite index for combatant D0 -> D1", 1);

    // GetMapsprite
    SetFunctionCmt(0x23a4a, 
        "Get entity D0 map sprite index -> D1\n\
\n\
    - Check if changed into Jogurt\n\
    - Apply outfits if applicable\n\
    - Add 30 to index if promoted", 1);

    // ApplyOutfitItems
    SetFunctionCmt(0x23a94, 
        "Apply outfit items -> D1 = new map sprite index", 1);

    // LoadBattlespriteAndPaletteIndexes
    SetFunctionCmt(0x23b24, 
        "Load battle sprite and palette indexes in RAM", 1);

    // GetAnimationDataAddress
    SetFunctionCmt(0x23c2e, 
        "Get address of animation data for battle sprite -> A0", 1);

    // IsCombatantChangedIntoJogurt
    SetFunctionCmt(0x23c5c, 
        "Check if combatant D0 is under Jogurt status effect -> CCR zero-bit cleared if true", 1);

    // IsEntityChangedIntoJogurt
    SetFunctionCmt(0x23c6c, 
        "Check if entity D0 is under Jogurt status effect -> CCR zero-bit cleared if true", 1);

    // DetermineAiAction
    SetFunctionCmt(0x23f6e, 
        "Determine AI action -> CCR carry-bit set if regular attack", 1);

    // AiAction_CastSpell
    SetFunctionCmt(0x2401c, 
        "Cast spell AI -> CCR carry-bit set if unable to proceed", 1);

    // LoadAiSpellcastData
    SetFunctionCmt(0x24062, 
        "Caster AI : prepare to cast spell D1", 1);

    // AiAction_UseItem
    SetFunctionCmt(0x240e8, 
        "Use item AI -> CCR carry-bit set if unable to proceed", 1);

    // LoadRangeData
    SetFunctionCmt(0x24170, 
        "Load range D4 data", 1);

    // sub_2425C
    SetFunctionCmt(0x2425c, 
        "Trigger AI regions (or set AI regions to trigger?)", 1);

    // sub_24324
    SetFunctionCmt(0x24324, 
        "In: A3 = priority routine address", 1);

    // ApplyClassToTargetPriority
    SetFunctionCmt(0x24386, 
        "Apply class to target priority -> d6.w\n\
\n\
2 points per class priority value.", 1);

    // ApplyDistanceToTargetPriority
    SetFunctionCmt(0x244ca, 
        "Apply distance to target priority -> d6.w\n\
\n\
Starts at 400 points for adjacent targets, -40 points per distance greater than 1 space.", 1);

    // GetLandEffectForCombatant
    SetFunctionCmt(0x24608, 
        "Get land effect of space occupied by combatant D0 -> D1", 1);

    // GetLandEffectAtPosition
    SetFunctionCmt(0x24616, 
        "Get land effect of space at position D2,D1 -> D1", 1);

    // GetTerrainEntryAddress
    SetFunctionCmt(0x24646, 
        "Get terrain entry address of space at position D2,D1 -> A0", 1);

    // GetTerrainBackgrounds
    SetFunctionCmt(0x2468e, 
        "Get background layers for terrain -> D0, D1", 1);

    // IncreaseStatsOnLevelUpForCombatant
    SetFunctionCmt(0x246f8, 
        "Increase stats on level up by force index", 1);

    // IncreaseStatsOnLevelUp
    SetFunctionCmt(0x24708, 
        "Increase stats for force member D0 on level up", 1);

    // CalculateStatGain
    SetFunctionCmt(0x247f0, 
        "Calculate maximum increase of stat given target D1, current D2 and level D3 -> D2", 1);

    // Promote
    SetFunctionCmt(0x24912, 
        "Promote force member D0 (save level promoted at to $FFA16A table, add 16 to class index)", 1);

    // CalculateTotalStatGrowth
    SetFunctionCmt(0x249d8, 
        "Calculate force member D0 total growth for stat D1 -> D1", 1);

    // CalculateInitialStatValue
    SetFunctionCmt(0x249fc, 
        "Calculate force member D0 initial stat D1 value, factoring in promoted at level -> D1", 1);

    // MapStatToForceEntryOffset
    SetFunctionCmt(0x24a2e, 
        "Map stat D1 to force entry offset -> D3", 1);

    // CalculateGrowthTarget
    SetFunctionCmt(0x24a44, 
        "Calculate growth target value based on level D1 and growth value D2 -> D1", 1);

    // CalculateGrowthPercent
    SetFunctionCmt(0x24a56, 
        "Calculate growth percent based on level D1 and growth curve D2 -> D1", 1);

    // GetGrowthEntryAddress
    SetFunctionCmt(0x24aa2, 
        "Get force member D0 growth entry address based on if promoted -> A0", 1);

    // GetUnpromotedGrowthEntryAddress
    SetFunctionCmt(0x24aae, 
        "Get force member D0 unpromoted growth entry address -> A0", 1);

    // GetInitialForceEntryAddress
    SetFunctionCmt(0x24ac4, 
        "Get force member D0 initial data entry address -> A0", 1);

    // IsPromoted
    SetFunctionCmt(0x24ada, 
        "Check if force member D0 is promoted", 1);

    // GetPromotedAtLevel
    SetFunctionCmt(0x24ae6, 
        "Get force member D0 promoted at level -> D1 (0 if not promoted)", 1);

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
        "Get total level of character D0 (current level + level promoted at) -> D1", 1);

    // CalculateEffectiveLevel
    SetFunctionCmt(0x24bac, 
        "Get level of character D0 (+10 if promoted) -> D1", 1);

    // IsAsleep
    SetFunctionCmt(0x24bd2, 
        "Check if character D0 asleep", 1);

    // sub_24CA6
    SetFunctionCmt(0x24ca6, 
        "related to the battle cursor", 1);

    // ResetForceMemberStats
    SetFunctionCmt(0x24d0e, 
        "Clear statuses of all members and restore HP/MP to max", 1);

    // DecrementStatusEffectCounter
    SetFunctionCmt(0x24d44, 
        "Decrement counter for status effect D1, with chance to end it early", 1);

    // TerminateStatusEffectRandomly
    SetFunctionCmt(0x24d74, 
        "Clear status effect bit D1, 50% of the time", 1);

    // GetGold
    SetFunctionCmt(0x24dbc, 
        "Get current gold -> D1", 1);

    // SetGold
    SetFunctionCmt(0x24dc4, 
        "Set D1 -> current gold", 1);

    // IncreaseGold
    SetFunctionCmt(0x24dcc, 
        "Add D1 to current gold, cap at 999999", 1);

    // DecreaseGold
    SetFunctionCmt(0x24de8, 
        "Sub D1 from current gold, cap at 0", 1);

    // IncrementDealsStock
    SetFunctionCmt(0x24dfe, 
        "Add 1 to deals stock for item D1", 1);

    // DecrementDealsStock
    SetFunctionCmt(0x24e1c, 
        "Sub 1 from deals stock for item D1", 1);

    // GetDealsStock
    SetFunctionCmt(0x24e2a, 
        "Get stock of item D1 currently in deals -> D2", 1);

    // SetDealsStock
    SetFunctionCmt(0x24e44, 
        "Set D2 -> stock of item D1 currently in deals", 1);

    // GetDealsStockEntryAddress
    SetFunctionCmt(0x24e64, 
        "Get item D1 deals stock entry address -> A0", 1);

    // LoadDealsInventory
    SetFunctionCmt(0x24e74, 
        "Load items currently in deals into shop inventory\n\
\n\
In: A0 = shop data address\n\
    D0 = shop type (0: weapon shop, 1: item shop)", 1);

    // IsItemInDealsOrHeldByForce
    SetFunctionCmt(0x24ec4, 
        "Check if item D1 not in deals stock or held by any character", 1);

    // IsItemHeldByCharacter
    SetFunctionCmt(0x24eda, 
        "Check if character has item D1", 1);

    // IsItemHeldByForce
    SetFunctionCmt(0x24efe, 
        "Check if any character has item D1", 1);

    // LoadBaseAttack
    SetFunctionCmt(0x24f1a, 
        "Load force member's base attack to combatant D0 entry", 1);

    // LoadBaseDefense
    SetFunctionCmt(0x24f2c, 
        "Load force member's base defense to combatant D0 entry", 1);

    // LoadBaseAgility
    SetFunctionCmt(0x24f3e, 
        "Load force member's base agility to combatant D0 entry", 1);

    // LoadBaseMove
    SetFunctionCmt(0x24f50, 
        "Load force member's base move to combatant D0 entry", 1);

    // LoadBaseCritical
    SetFunctionCmt(0x24f62, 
        "Load force member's base critical to combatant D0 entry", 1);

    // RefillHp
    SetFunctionCmt(0x24f74, 
        "Refill force member D0 HP", 1);

    // RefillMp
    SetFunctionCmt(0x24f86, 
        "Refill force member D0 MP", 1);

    // RefillHpForCombatant
    SetFunctionCmt(0x24f98, 
        "Refill force member's HP for combatant D0", 1);

    // RefillMpForCombatant
    SetFunctionCmt(0x24fae, 
        "Refill force member's MP for combatant D0", 1);

    // InitializeBattleMap
    SetFunctionCmt(0x24fe6, 
        "Wrapper for 25026 and 24FEC", 1);

    // TrimBattleTerrain
    SetFunctionCmt(0x24fec, 
        "Trim battle terrain table down to map size", 1);

    // sub_25026
    SetFunctionCmt(0x25026, 
        "Load map size and terrain data", 1);

    // LoadPredefinedTargetGrid
    SetFunctionCmt(0x2510a, 
        "Reset target grid (i.e., passability flags table) and load from A0", 1);

    // LoadEndingCreditsForce
    SetFunctionCmt(0x26e16, 
        "Prepare Ending Sequence", 1);

    // WriteEndingCreditsBattlesceneScript
    SetFunctionCmt(0x26e7e, 
        "In: d0.w", 1);

    // sub_27036
    SetFunctionCmt(0x27036, 
        "Flag AI Regions as triggered", 1);

    // GetMapspriteScriptAddress
    SetFunctionCmt(0x80ee0, 
        "Load address into table at $80EFE based on byte 13 of sprite data.", 1);

    // sub_1261F8
    SetFunctionCmt(0x1261f8, 
        "In: D0 = status effects", 1);

    // ExecuteSpellAnimation
    SetFunctionCmt(0x12647e, 
        "In: D0 = spell animation index", 1);

    // PlaySpellCastEffect
    SetFunctionCmt(0x126686, 
        "In: D2 = spell cast effect color index", 1);

    // LoadSpellEntityLayout
    SetFunctionCmt(0x12672a, 
        "In: D0 = \n\
    D1 = sprite layer\n\
    D2 = number of graphics pieces to load\n\
    D3 = X offset\n\
    D4 = Y offset", 1);

    // SetupScreenTint_Dark
    SetFunctionCmt(0x1267ac, 
        "Call copy palettes function, then apply dark screen tint effect", 1);

    // SetupScreenTint_Grey
    SetFunctionCmt(0x126826, 
        "Call copy palettes function, then apply greyscale screen tint effect", 1);

    // SetupScreenTint_Red
    SetFunctionCmt(0x126908, 
        "Call copy palettes function, then apply red screen tint effect", 1);

    // SetupSpellAnimation_Bolt
    SetFunctionCmt(0x126a38, 
        "In: D3 = spell animation version", 1);

    // SetupSpellAnimation_Blaze
    SetFunctionCmt(0x126ab4, 
        "In: D3 = spell animation version", 1);

    // LoadSpellEntity
    SetFunctionCmt(0x126b20, 
        "In: D3 = frame number\n\
    D4 = is slot in use?\n\
    D5 = Y position\n\
    D6 = X position", 1);

    // SetupSpellAnimation_AssaultShell
    SetFunctionCmt(0x126b48, 
        "In: D3 = spell animation version", 1);

    // SetupSpellAnimation_Freeze
    SetFunctionCmt(0x126be6, 
        "In: D3 = spell animation version", 1);

    // SetupSpellAnimation_IceBreath
    SetFunctionCmt(0x126c06, 
        "In: D3 = spell animation version", 1);

    // SetupSpellAnimation_DemonBlaze
    SetFunctionCmt(0x126c30, 
        "In: D3 = spell animation version", 1);

    // SetupSpellAnimation_Desoul
    SetFunctionCmt(0x126c98, 
        "In: D3 = spell animation version", 1);

    // SetupSpellAnimation_Dispel
    SetFunctionCmt(0x126d3c, 
        "In: D3 = spell animation version", 1);

    // SetupSpellAnimation_Muddle
    SetFunctionCmt(0x126d54, 
        "In: D3 = spell animation version", 1);

    // SetupSpellAnimation_Slow
    SetFunctionCmt(0x126d6c, 
        "In: D3 = spell animation version", 1);

    // SetupSpellAnimation_Sleep
    SetFunctionCmt(0x126d84, 
        "In: D3 = spell animation version", 1);

    // SetupSpellAnimation_Healing
    SetFunctionCmt(0x126dfe, 
        "In: D3 = spell animation version", 1);

    // SetupSpellAnimation_MachineGun
    SetFunctionCmt(0x126e82, 
        "In: D3 = spell animation version", 1);

    // SetupSpellAnimation_Crossbow
    SetFunctionCmt(0x126e9a, 
        "In: D3 = spell animation version", 1);

    // SetupSpellAnimation_GreenLaser
    SetFunctionCmt(0x12700a, 
        "In: D3 = spell animation version", 1);

    // SetupSpellAnimation_LaserEye
    SetFunctionCmt(0x12706c, 
        "In: D3 = spell animation version", 1);

    // SetupSpellAnimation_FireBreath
    SetFunctionCmt(0x1271ce, 
        "In: D3 = spell animation version", 1);

    // abcs10
    SetFunctionCmt(0x12aec8, 
        "Pao bridge post-battle cutscene (i.e., the \"Pelle\" scene.)", 1);

    // WasEntityKilledByLastAttack
    SetFunctionCmt(0x12bfd0, 
        "CCR zero-bit set if true", 1);

    // sub_12C342
    SetFunctionCmt(0x12c342, 
        "Get mapsprite (used in cutscenes.)", 1);

    // sub_12C446
    SetFunctionCmt(0x12c446, 
        "Pelle joins the Force.", 1);

    // CheckSkipToTitleScreen
    SetFunctionCmt(0x1304fe, 
        "Wait D0 frames while checking for start button input", 1);

    // sub_1645A4
    SetFunctionCmt(0x1645a4, 
        "navigate naming window", 1);

}
