Forgotten_Cave_Ice_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Forgotten_Cave_Ice_MapScripts_MAP_SCRIPT_ON_TRANSITION
	.byte 0

Forgotten_Cave_Ice_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	call_if_unset FLAG_DEFEATED_ARTICUNO, ShowArticuno
	call_if_unset FLAG_DEFEATED_SUICUNE, ShowSuicune
	end


ShowArticuno::
	clearflag FLAG_HIDE_ARTICUNO
	return


ShowSuicune::
	clearflag FLAG_HIDE_SUICUNE
	return


FightArticuno::
	lock
	waitse
	playmoncry SPECIES_ARTICUNO, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setwildbattle SPECIES_ARTICUNO, 50, ITEM_BRIGHT_POWDER
	special BattleSetup_StartLegendaryBattle
	waitstate
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq FightArticuno_1
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_eq FightArticuno_1
	goto Common_EventScript_LegendaryArtifactFades
	end

FightArticuno_1:
	setflag FLAG_DEFEATED_ARTICUNO
	goto Common_EventScript_LegendaryArtifactVanishes
	end


FightSuicune::
	lock
	waitse
	playmoncry SPECIES_SUICUNE, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setwildbattle SPECIES_SUICUNE, 50, ITEM_NONE
	special BattleSetup_StartLegendaryBattle
	waitstate
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq FightSuicune_1
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_eq FightSuicune_1
	goto Common_EventScript_LegendaryArtifactFades
	end

FightSuicune_1:
	setflag FLAG_DEFEATED_SUICUNE
	goto Common_EventScript_LegendaryArtifactVanishes
	end

