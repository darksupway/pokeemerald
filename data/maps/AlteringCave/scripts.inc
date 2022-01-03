AlteringCave_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, AlteringCave_MapScripts_MAP_SCRIPT_ON_TRANSITION
	.byte 0

AlteringCave_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	setflag FLAG_LANDMARK_ALTERING_CAVE
	return


MysteryManAlteringCave::
	lock
	goto_if_set FLAG_DEFEATED_METEOR_FALLS_STEVEN, MysteryManAlteringCave_1
	msgbox MysteryManAlteringCave_ComeAfterSteven_Text, MSGBOX_AUTOCLOSE
	release
	end

MysteryManAlteringCave_1:
	msgbox MysteryManAlteringCave_Fight_Text, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq MysteryManAlteringCave_4
	msgbox MysteryManAlteringCave_Text_0, MSGBOX_AUTOCLOSE
	release
	end

MysteryManAlteringCave_4:
	goto FightMysteryMan
	return


FightMysteryMan::
	trainerbattle_no_intro TRAINER_MYSTERYMAN, MysteryManAlteringCave_Defeated_Text
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject VAR_LAST_TALKED
	fadescreenswapbuffers FADE_FROM_BLACK
	setflag FLAG_HIDE_MYSTERY_MAN_LAST
	setvar VAR_MYSTERY_MAN_STATE, 7
	release
	end


MysteryManAlteringCave_Text_0:
	.string "Come back if you're ready.$"

MysteryManAlteringCave_Fight_Text::
	.string "...\n"
	.string "Alright, let's do this...\l"
	.string "Are you ready, {PLAYER}?$"

MysteryManAlteringCave_Defeated_Text::
	.string "...\n"
	.string "Good job, Farewell…$"

MysteryManAlteringCave_ComeAfterSteven_Text::
	.string "...\n"
	.string "Oh, you're here.\p"
	.string "Hmm, not yet...\n"
	.string "Come again after fighting stronger\l"
	.string "opponents.$"
