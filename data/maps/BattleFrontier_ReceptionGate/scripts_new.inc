MysteryManIntroduction::
	lockall
	faceplayer
	msgbox MysteryManIntroduction_Text, MSGBOX_AUTOCLOSE
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject VAR_LAST_TALKED
	fadescreenswapbuffers FADE_FROM_BLACK
	setflag FLAG_HIDE_MYSTERY_MAN_RECEPTION
	clearflag FLAG_HIDE_MYSTERY_MAN_LOUNGE2
	setvar VAR_MYSTERY_MAN_STATE, 1
	releaseall
	end


MysteryManIntroduction_Text::
	.string "Oh, Hello there.\n"
	.string "Aren't you Hoenns new\l"
	.string "Champion, {PLAYER}?\p"
	.string "You know what? I have some\n"
	.string "special gifts for you.\p"
	.string "Find me again in other places\n"
	.string "around here and you can have them.$"
