Forgotten_Cave_Special_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Forgotten_Cave_Special_MapScripts_MAP_SCRIPT_ON_TRANSITION
	.byte 0

Forgotten_Cave_Special_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	setvar VAR_FORGOTTEN_CAVE_SPECIAL_WILD_SET, 0
	call_if_unset FLAG_DEFEATED_MEWTWO, ShowMewtwo
	call_if_unset FLAG_DEFEATED_CELEBI, ShowCelebi
	call_if_unset FLAG_DEFEATED_JIRACHI, ShowJirachi
	end


ShowMewtwo::
	clearflag FLAG_HIDE_MEWTWO
	return


ShowCelebi::
	clearflag FLAG_HIDE_CELEBI
	return


ShowJirachi::
	clearflag FLAG_HIDE_JIRACHI
	return


FightMewtwo::
	lock
	waitse
	playmoncry SPECIES_MEWTWO, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setwildbattle SPECIES_MEWTWO, 70, ITEM_MASTER_BALL
	special BattleSetup_StartLegendaryBattle
	waitstate
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq FightMewtwo_1
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_eq FightMewtwo_1
	goto Common_EventScript_LegendaryArtifactFades
	end

FightMewtwo_1:
	setflag FLAG_DEFEATED_MEWTWO
	goto Common_EventScript_LegendaryArtifactVanishes
	end


FightCelebi::
	lock
	waitse
	playmoncry SPECIES_CELEBI, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setwildbattle SPECIES_CELEBI, 5, ITEM_GANLON_BERRY
	special BattleSetup_StartLegendaryBattle
	waitstate
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq FightCelebi_1
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_eq FightCelebi_1
	goto Common_EventScript_LegendaryArtifactFades
	end

FightCelebi_1:
	setflag FLAG_DEFEATED_CELEBI
	goto Common_EventScript_LegendaryArtifactVanishes
	end


FightJirachi::
	lock
	waitse
	playmoncry SPECIES_JIRACHI, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setwildbattle SPECIES_JIRACHI, 5, ITEM_SALAC_BERRY
	special BattleSetup_StartLegendaryBattle
	waitstate
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq FightJirachi_1
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_eq FightJirachi_1
	goto Common_EventScript_LegendaryArtifactFades
	end

FightJirachi_1:
	setflag FLAG_DEFEATED_JIRACHI
	goto Common_EventScript_LegendaryArtifactVanishes
	end


TriggerWildPkmnMewtwo::
	setvar VAR_FORGOTTEN_CAVE_SPECIAL_WILD_SET, 0
	releaseall
	end


TriggerWildPkmnJirachi::
	setvar VAR_FORGOTTEN_CAVE_SPECIAL_WILD_SET, 1
	releaseall
	end


TriggerWildPkmnCelebi::
	setvar VAR_FORGOTTEN_CAVE_SPECIAL_WILD_SET, 2
	releaseall
	end

