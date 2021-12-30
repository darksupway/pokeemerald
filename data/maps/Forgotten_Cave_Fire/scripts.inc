Forgotten_Cave_Fire_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Forgotten_Cave_Fire_MapScripts_MAP_SCRIPT_ON_TRANSITION
	.byte 0

Forgotten_Cave_Fire_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	call_if_unset FLAG_DEFEATED_MOLTRES, ShowMoltres
	call_if_unset FLAG_DEFEATED_ENTEI, ShowEntei
	end


ShowMoltres::
	clearflag FLAG_HIDE_MOLTRES
	return


ShowEntei::
	clearflag FLAG_HIDE_ENTEI
	return


FightMoltres::
	lock
	waitse
	playmoncry SPECIES_MOLTRES, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setwildbattle SPECIES_MOLTRES, 50, ITEM_BRIGHT_POWDER
	special BattleSetup_StartLegendaryBattle
	waitstate
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq FightMoltres_1
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_eq FightMoltres_1
	goto Common_EventScript_LegendaryArtifactFades
	end

FightMoltres_1:
	setflag FLAG_DEFEATED_MOLTRES
	goto Common_EventScript_LegendaryArtifactVanishes
	end


FightEntei::
	lock
	waitse
	playmoncry SPECIES_ENTEI, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setwildbattle SPECIES_ENTEI, 50, ITEM_NONE
	special BattleSetup_StartLegendaryBattle
	waitstate
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq FightEntei_1
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_eq FightEntei_1
	goto Common_EventScript_LegendaryArtifactFades
	end

FightEntei_1:
	setflag FLAG_DEFEATED_ENTEI
	goto Common_EventScript_LegendaryArtifactVanishes
	end

