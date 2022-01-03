Forgotten_Cave_Sea_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, Forgotten_Cave_Sea_MapScripts_MAP_SCRIPT_ON_LOAD
	.byte 0

Forgotten_Cave_Sea_MapScripts_MAP_SCRIPT_ON_LOAD:
	compare VAR_MYSTERY_MAN_STATE, 5
	goto_if_ge Forgotten_Cave_Sea_MapScripts_MAP_SCRIPT_ON_LOAD_1
	return

Forgotten_Cave_Sea_MapScripts_MAP_SCRIPT_ON_LOAD_1:
	setmetatile 12, 2, 0x20B, TRUE
	setmetatile 12, 3, 0x213, TRUE
	setmetatile 13, 2, 0x20C, TRUE
	setmetatile 13, 3, 0x214, FALSE
	setmetatile 14, 2, 0x20D, TRUE
	setmetatile 14, 3, 0x215, TRUE
	end


MysteryManForgottenCave::
	lockall
	faceplayer
	goto_if_set FLAG_CAUGHT_HO_OH, MysteryManForgottenCave_3
	goto_if_set FLAG_DEFEATED_HO_OH, MysteryManForgottenCave_3
MysteryManForgottenCave_2:
	goto MysteryManForgottenCave_ComeBackAfterHoohLugia
	return

MysteryManForgottenCave_1:
	goto MysteryManForgottenCave_DefeatedHoohLugia
	return

MysteryManForgottenCave_3:
	goto_if_set FLAG_CAUGHT_LUGIA, MysteryManForgottenCave_1
	goto_if_set FLAG_DEFEATED_LUGIA, MysteryManForgottenCave_1
	goto MysteryManForgottenCave_2


MysteryManForgottenCave_DefeatedHoohLugia::
	msgbox MysteryManForgottenCave_DefeatedHoohLugia_Text, MSGBOX_AUTOCLOSE
	setvar VAR_MYSTERY_MAN_STATE, 6
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject VAR_LAST_TALKED
	fadescreenswapbuffers FADE_FROM_BLACK
	setflag FLAG_HIDE_MYSTERY_MAN_FORGOTTEN_CAVE
	clearflag FLAG_HIDE_MYSTERY_MAN_LAST
	setvar VAR_MYSTERY_MAN_STATE, 6
	releaseall
	end


MysteryManForgottenCave_ComeBackAfterHoohLugia::
	msgbox MysteryManForgottenCave_ComeBackAfterHoohLugia_Text, MSGBOX_AUTOCLOSE
	releaseall
	end


MysteryManForgottenCave_DefeatedHoohLugia_Text::
	.string "Oh, so you did it, right?\n"
	.string "Good. In this cave lies your\l"
	.string "last challenge.\l"
	.string "Go ahead if you are ready.\p"
	.string "After this, if we ever\n"
	.string "meet again...\p"
	.string "Well, I guess if it's you,\n"
	.string "you'll find out.\p"
	.string "If you want to find me again,\n"
	.string "there is this strange cave that\l"
	.string "opened up recently on ROUTE 103...\p"
	.string "Farewell!$"

MysteryManForgottenCave_ComeBackAfterHoohLugia_Text::
	.string "...\n"
	.string "Not yet, huh?\p"
	.string "You have not forgotten the last\n"
	.string "ticket have you?$"
