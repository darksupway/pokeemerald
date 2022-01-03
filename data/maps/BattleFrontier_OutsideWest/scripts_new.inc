MysteryManMysticTicket::
	lockall
	goto_if_set FLAG_BATTLED_DEOXYS, MysteryManMysticTicket_3
	goto_if_set FLAG_DEFEATED_DEOXYS, MysteryManMysticTicket_3
MysteryManMysticTicket_2:
	goto MysteryManMysticTicket_ComeBackAfterTickets
	return

MysteryManMysticTicket_1:
	goto MysteryManMysticTicket_DefeatedOtherLegendaries
	return

MysteryManMysticTicket_3:
	goto_if_set FLAG_CAUGHT_MEW, MysteryManMysticTicket_7
	goto_if_set FLAG_DEFEATED_MEW, MysteryManMysticTicket_7
	goto MysteryManMysticTicket_2

MysteryManMysticTicket_7:
	goto_if_set FLAG_CAUGHT_LATIAS_OR_LATIOS, MysteryManMysticTicket_1
	goto_if_set FLAG_DEFEATED_LATIAS_OR_LATIOS, MysteryManMysticTicket_1
	goto MysteryManMysticTicket_2


MysteryManMysticTicket_DefeatedOtherLegendaries::
	faceplayer
	goto_if_unset FLAG_MYSTERY_MAN_BAG_FULL, MysteryManMysticTicket_DefeatedOtherLegendaries_2
	msgbox gText_MysteryMan_Return, MSGBOX_DEFAULT
MysteryManMysticTicket_DefeatedOtherLegendaries_1:
	checkitem ITEM_MYSTIC_TICKET
	compare VAR_RESULT, TRUE
	goto_if_eq MysteryManMysticTicket_DefeatedOtherLegendaries_6
	checkitemspace ITEM_MYSTIC_TICKET
	compare VAR_RESULT, FALSE
	goto_if_eq MysteryManMysticTicket_DefeatedOtherLegendaries_10
MysteryManMysticTicket_DefeatedOtherLegendaries_9:
	giveitem ITEM_MYSTIC_TICKET
	setflag FLAG_ENABLE_SHIP_NAVEL_ROCK
	setflag FLAG_RECEIVED_MYSTIC_TICKET
	msgbox MysteryManMysticTicket_Obtained_Text, MSGBOX_AUTOCLOSE
MysteryManMysticTicket_DefeatedOtherLegendaries_5:
	clearflag FLAG_MYSTERY_MAN_BAG_FULL
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject VAR_LAST_TALKED
	fadescreenswapbuffers FADE_FROM_BLACK
	setflag FLAG_HIDE_MYSTERY_MAN_ABOVE_BATTLE_DOME
	clearflag FLAG_HIDE_MYSTERY_MAN_FORGOTTEN_CAVE
	setvar VAR_MYSTERY_MAN_STATE, 5
	releaseall
	end

MysteryManMysticTicket_DefeatedOtherLegendaries_2:
	msgbox MysteryManMysticTicket_Text, MSGBOX_DEFAULT
	goto MysteryManMysticTicket_DefeatedOtherLegendaries_1

MysteryManMysticTicket_DefeatedOtherLegendaries_6:
	msgbox MysteryManMysticTicket_HasTicketAlready, MSGBOX_AUTOCLOSE
	goto MysteryManMysticTicket_DefeatedOtherLegendaries_5

MysteryManMysticTicket_DefeatedOtherLegendaries_10:
	goto Common_EventScript_MysteryMan_NoBagSpace
	goto MysteryManMysticTicket_DefeatedOtherLegendaries_9


MysteryManMysticTicket_ComeBackAfterTickets::
	msgbox MysteryManMysticTicket_ComeBackAfterTickets_Text, MSGBOX_AUTOCLOSE
	releaseall
	end


MysteryManMysticTicket_Text::
	.string "Ah, you are here.\n"
	.string "...\p"
	.string "So what do you think after\n"
	.string "becoming a Champion and meeting\l"
	.string "all sorts of Pokemon?\p"
	.string "Are you satisfied? Or are you\n"
	.string "searching for more challenges?\p"
	.string "Here, the last ticket I have for\n"
	.string "you.$"

MysteryManMysticTicket_ComeBackAfterTickets_Text::
	.string "Hmm...\p"
	.string "It seems you have neither caught\n"
	.string "nor defeated the Pokemon on\l"
	.string "the islands.\p"
	.string "Come back after doing that.$"

MysteryManMysticTicket_Obtained_Text::
	.string "After you are done with this\n"
	.string "one, please come meet me in the\l"
	.string "FORGOTTEN CAVE located on the\l"
	.string "east side of the Frontier\p"
	.string "If you have not found it yet...\n"
	.string "Well, I don't think you will have\l"
	.string "a problem finding it.$"

MysteryManMysticTicket_HasTicketAlready::
	.string "Oh... It seems you already have\n"
	.string "a MYSTIC TICKET.\p"
	.string "In that case, I'll just go to the\n"
	.string "next location. Bye!$"
