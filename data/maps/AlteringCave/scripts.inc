    .set LOCALID_ENIGMA_BERRY, 2

AlteringCave_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, AlteringCave_MapScripts_MAP_SCRIPT_ON_LOAD
	map_script MAP_SCRIPT_ON_TRANSITION, AlteringCave_MapScripts_MAP_SCRIPT_ON_TRANSITION
	.byte 0

AlteringCave_MapScripts_MAP_SCRIPT_ON_LOAD:
	goto_if_set FLAG_DEFEATED_METEOR_FALLS_STEVEN, AlteringCave_MapScripts_MAP_SCRIPT_ON_LOAD_2
	end

AlteringCave_MapScripts_MAP_SCRIPT_ON_LOAD_2:
	setmetatile 7, 1, 0x235, 0x1
	end

AlteringCave_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	setflag FLAG_LANDMARK_ALTERING_CAVE
	setvar VAR_ALTERING_CAVE_WILD_SET, 0
	end


AlteringCave_WallAncient::
	lock
	msgbox AlteringCave_WallAncient_Text, MSGBOX_SIGN
	release
	end


AlteringCave_WallMysteryMan::
	lock
	msgbox AlteringCave_WallMysteryMan_Text, MSGBOX_SIGN
	release
	end


AlteringCave_ChangeToWildset2::
	lock
	call AlteringCave_ChangeWildset_AskToChange
	setvar VAR_ALTERING_CAVE_WILD_SET, 1
	goto AlteringCave_ChangeWildset
	return


AlteringCave_ChangeToWildset3::
	lock
	call AlteringCave_ChangeWildset_AskToChange
	setvar VAR_ALTERING_CAVE_WILD_SET, 2
	goto AlteringCave_ChangeWildset
	return


AlteringCave_ChangeToWildset4::
	lock
	call AlteringCave_ChangeWildset_AskToChange
	setvar VAR_ALTERING_CAVE_WILD_SET, 3
	goto AlteringCave_ChangeWildset
	return


AlteringCave_ChangeToWildset5::
	lock
	call AlteringCave_ChangeWildset_AskToChange
	setvar VAR_ALTERING_CAVE_WILD_SET, 4
	goto AlteringCave_ChangeWildset
	return


AlteringCave_ChangeToWildset6::
	lock
	call AlteringCave_ChangeWildset_AskToChange
	setvar VAR_ALTERING_CAVE_WILD_SET, 5
	goto AlteringCave_ChangeWildset
	return


AlteringCave_ChangeToWildset7::
	lock
	call AlteringCave_ChangeWildset_AskToChange
	setvar VAR_ALTERING_CAVE_WILD_SET, 6
	goto AlteringCave_ChangeWildset
	return


AlteringCave_ChangeToWildset8::
	lock
	call AlteringCave_ChangeWildset_AskToChange
	setvar VAR_ALTERING_CAVE_WILD_SET, 7
	goto AlteringCave_ChangeWildset
	return


AlteringCave_ChangeToWildset9::
	lock
	call AlteringCave_ChangeWildset_AskToChange
	setvar VAR_ALTERING_CAVE_WILD_SET, 8
	goto AlteringCave_ChangeWildset
	return


AlteringCave_ChangeWildset_AskToChange::
	msgbox AlteringCave_ChangeWildset_AskToChange_Text, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq AlteringCave_ChangeWildset_AskToChange_2
	return

AlteringCave_ChangeWildset_AskToChange_2:
	msgbox AlteringCave_ChangeWildset_NoChange_Text, MSGBOX_SIGN
	release
	end


AlteringCave_ChangeWildset::
	msgbox AlteringCave_ChangeWildset_WantToChange_Text, MSGBOX_AUTOCLOSE
	setvar VAR_0x8004, 1
	setvar VAR_0x8005, 1
	setvar VAR_0x8006, 8
	setvar VAR_0x8007, 5
	special ShakeCamera
	waitstate
	msgbox AlteringCave_ChangeWildset_Text, MSGBOX_AUTOCLOSE
	release
	end


MysteryManAlteringCave::
	lock
	goto_if_set FLAG_DEFEATED_METEOR_FALLS_STEVEN, MysteryManAlteringCave_1
	msgbox MysteryManAlteringCave_ComeAfterSteven_Text, MSGBOX_AUTOCLOSE
	release
	end

MysteryManAlteringCave_1:
	faceplayer
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
	clearflag FLAG_ITEM_ALTERING_CAVE_ENIGMA_BERRY
	addobject LOCALID_ENIGMA_BERRY
	fadescreenswapbuffers FADE_FROM_BLACK
	setflag FLAG_HIDE_MYSTERY_MAN_LAST
	setvar VAR_MYSTERY_MAN_STATE, 7
	release
	end


MysteryManAlteringCave_Text_0:
	.string "Come back if you're ready.$"

MysteryManAlteringCave_Fight_Text::
	.string "...\n"
	.string "Alright, let's do this.\l"
	.string "Are you ready, {PLAYER}?$"

MysteryManAlteringCave_Defeated_Text::
	.string "...\n"
	.string "Good job and Farewell…$"

MysteryManAlteringCave_ComeAfterSteven_Text::
	.string "...\n"
	.string "Oh, you're here.\p"
	.string "Hmm, not yet.\n"
	.string "Come again after fighting stronger\l"
	.string "opponents.$"

AlteringCave_ChangeWildset_AskToChange_Text::
	.string "Do you want to touch the stone\n"
	.string "and close your eyes?$"

AlteringCave_ChangeWildset_WantToChange_Text::
	.string "You touch it and close your eyes.$"

AlteringCave_ChangeWildset_NoChange_Text::
	.string "You step away from the stone.$"

AlteringCave_ChangeWildset_Text::
	.string "Something seems to have changed…$"

AlteringCave_WallAncient_Text::
	.string "On the wall, something written\n"
	.string "in what seems to be an ancient\l"
	.string "script can be seen.\p"
	.string "Who knows what it could mean.$"

AlteringCave_WallMysteryMan_Text::
	.string "The text on this wall seems to\n"
	.string "have been engraved just recently.\p"
	.string "“FOR THE PEOPLE COMING AFTER ME.\p"
	.string "TO REVEAL THE TRUTH OF THIS CAVE\n"
	.string "FIND THE SPECIAL STONES, TOUCH\l"
	.string "THEM AND CLOSE YOUR EYES.\p"
	.string "LEAVING THE CAVE WILL RETURN\n"
	.string "EVERYTHING TO HOW IT WAS.”$"
