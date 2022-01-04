MysteryManAuroraTicket::
	lockall
	faceplayer
	goto_if_unset FLAG_MYSTERY_MAN_BAG_FULL, MysteryManAuroraTicket_2
	msgbox gText_MysteryMan_Return, MSGBOX_DEFAULT
MysteryManAuroraTicket_1:
	checkitem ITEM_AURORA_TICKET
	compare VAR_RESULT, TRUE
	goto_if_eq MysteryManAuroraTicket_6
	checkitemspace ITEM_AURORA_TICKET
	compare VAR_RESULT, FALSE
	goto_if_eq MysteryManAuroraTicket_10
MysteryManAuroraTicket_9:
	giveitem ITEM_AURORA_TICKET
	setflag FLAG_ENABLE_SHIP_BIRTH_ISLAND
	setflag FLAG_RECEIVED_AURORA_TICKET
	msgbox MysteryManAuroraTicket_Obtained_Text, MSGBOX_AUTOCLOSE
MysteryManAuroraTicket_5:
	clearflag FLAG_MYSTERY_MAN_BAG_FULL
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject VAR_LAST_TALKED
	fadescreenswapbuffers FADE_FROM_BLACK
	setflag FLAG_HIDE_MYSTERY_MAN_LOUNGE2
	clearflag FLAG_HIDE_MYSTERY_MAN_FRONT_OF_LOUNGE5
	setvar VAR_MYSTERY_MAN_STATE, 2
	releaseall
	end

MysteryManAuroraTicket_2:
	msgbox MysteryManAuroraTicket_Text, MSGBOX_DEFAULT
	goto MysteryManAuroraTicket_1

MysteryManAuroraTicket_6:
	msgbox MysteryManAuroraTicket_HasTicketAlready, MSGBOX_AUTOCLOSE
	goto MysteryManAuroraTicket_5

MysteryManAuroraTicket_10:
	goto Common_EventScript_MysteryMan_NoBagSpace
	goto MysteryManAuroraTicket_9


MysteryManAuroraTicket_Text::
	.string "Hello again, {PLAYER}!\n"
	.string "Have you had the chance to look\l"
	.string "around the Battle Frontier?\p"
	.string "Ah, I guess you want what I\n"
	.string "promised you, huh?\p"
	.string "Ok, here you go.$"

MysteryManAuroraTicket_Obtained_Text::
	.string "That's the first of four special\n"
	.string "tickets.\p"
	.string "Have you heard of a POKéMON that\n"
	.string "came from outer space?\l"
	.string "Well if not just use this ticket\l"
	.string "at the LILYCOVE CITY port.\p"
	.string "See you later!$"

MysteryManAuroraTicket_HasTicketAlready::
	.string "Oh... It seems you already have\n"
	.string "an AURORA TICKET.\p"
	.string "In that case, I'll just go to the\n"
	.string "next location. Bye!$"
