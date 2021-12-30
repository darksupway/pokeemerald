Forgotten_Cave_Elec_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Forgotten_Cave_Elec_MapScripts_MAP_SCRIPT_ON_TRANSITION
	.byte 0

Forgotten_Cave_Elec_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	call_if_unset FLAG_DEFEATED_ZAPDOS, ShowZapdos
	call_if_unset FLAG_DEFEATED_RAIKOU, ShowRaikou
	end


ShowZapdos::
	clearflag FLAG_HIDE_ZAPDOS
	return


ShowRaikou::
	clearflag FLAG_HIDE_RAIKOU
	return


FightZapdos::
	lock
	waitse
	playmoncry SPECIES_ZAPDOS, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setwildbattle SPECIES_ZAPDOS, 50, ITEM_BRIGHT_POWDER
	special BattleSetup_StartLegendaryBattle
	waitstate
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq FightZapdos_1
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_eq FightZapdos_1
	goto Common_EventScript_LegendaryArtifactFades
	end

FightZapdos_1:
	setflag FLAG_DEFEATED_ZAPDOS
	goto Common_EventScript_LegendaryArtifactVanishes
	end


FightRaikou::
	lock
	waitse
	playmoncry SPECIES_RAIKOU, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setwildbattle SPECIES_RAIKOU, 50, ITEM_NONE
	special BattleSetup_StartLegendaryBattle
	waitstate
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq FightRaikou_1
	compare VAR_RESULT, B_OUTCOME_CAUGHT
	goto_if_eq FightRaikou_1
	goto Common_EventScript_LegendaryArtifactFades
	end

FightRaikou_1:
	setflag FLAG_DEFEATED_RAIKOU
	goto Common_EventScript_LegendaryArtifactVanishes
	end

