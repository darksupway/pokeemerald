MysteryManEonTicket::
	lockall
	faceplayer
	goto_if_unset FLAG_MYSTERY_MAN_BAG_FULL, MysteryManEonTicket_2
	msgbox gText_MysteryMan_Return, MSGBOX_DEFAULT
MysteryManEonTicket_1:
	checkitem ITEM_EON_TICKET
	compare VAR_RESULT, TRUE
	goto_if_eq MysteryManEonTicket_6
	checkitemspace ITEM_EON_TICKET
	compare VAR_RESULT, FALSE
	goto_if_eq MysteryManEonTicket_14
MysteryManEonTicket_13:
	giveitem ITEM_EON_TICKET
	setflag FLAG_ENABLE_SHIP_SOUTHERN_ISLAND
	setvar VAR_DISTRIBUTE_EON_TICKET, 0
	msgbox MysteryManEonTicket_Obtained_Text, MSGBOX_AUTOCLOSE
MysteryManEonTicket_5:
	clearflag FLAG_MYSTERY_MAN_BAG_FULL
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject VAR_LAST_TALKED
	fadescreenswapbuffers FADE_FROM_BLACK
	setflag FLAG_HIDE_MYSTERY_MAN_LOUNGE6
	clearflag FLAG_HIDE_MYSTERY_MAN_ABOVE_BATTLE_DOME
	setvar VAR_MYSTERY_MAN_STATE, 4
	releaseall
	end

MysteryManEonTicket_2:
	compare VAR_ROAMER_POKEMON, 0
	goto_if_eq MysteryManEonTicket_10
	bufferstring STR_VAR_1, MysteryManEonTicket_Text_1
MysteryManEonTicket_9:
	msgbox MysteryManEonTicket_Text, MSGBOX_DEFAULT
	goto MysteryManEonTicket_1

MysteryManEonTicket_6:
	msgbox MysteryManEonTicket_HasTicketAlready, MSGBOX_AUTOCLOSE
	goto MysteryManEonTicket_5

MysteryManEonTicket_10:
	bufferstring STR_VAR_1, MysteryManEonTicket_Text_0
	goto MysteryManEonTicket_9

MysteryManEonTicket_14:
	goto Common_EventScript_MysteryMan_NoBagSpace
	goto MysteryManEonTicket_13


MysteryManEonTicket_Text_0:
	.string "{COLOR RED}{SHADOW LIGHT_RED}RED{COLOR DARK_GRAY}{SHADOW LIGHT_GRAY}$"

MysteryManEonTicket_Text_1:
	.string "{COLOR BLUE}{SHADOW LIGHT_BLUE}BLUE{COLOR DARK_GRAY}{SHADOW LIGHT_GRAY}$"

MysteryManEonTicket_Text::
	.string "Ah, you're here!\n"
	.string "Did you enjoy some wilderness on\l"
	.string "the FARAWAY ISLAND?\p"
	.string "Oh right, do you remember that\n"
	.string "news report some time ago?\p"
	.string "You know, the one about that\n"
	.string "{STR_VAR_1} Pokemon?\p"
	.string "Ok, enough about that. Here!$"

MysteryManEonTicket_Obtained_Text::
	.string "Now there is only one ticket left.\p"
	.string "This time, only come back to me\n"
	.string "once you used all the tickets and\l"
	.string "meet the Pokemon in those places.\p"
	.string "Until then!$"

MysteryManEonTicket_HasTicketAlready::
	.string "Oh... It seems you already have\n"
	.string "an EON TICKET.\p"
	.string "In that case, I'll just go to the\n"
	.string "next location. Bye!$"
