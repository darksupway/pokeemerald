BattleFrontier_OutsideEast_OnLoad::
	compare VAR_BATTLE_FRONTIER_EAST_STATE, 1
	goto_if_ge BattleFrontier_OutsideEast_OnLoad_2
	end

BattleFrontier_OutsideEast_OnLoad_2:
	setmetatile 28, 9, 1, 0
	setmetatile 29, 9, 1, 0
	setmetatile 30, 9, 1, 0
	setmetatile 31, 9, 1, 0
	end


MysteryManOldSeaMap::
	lockall
	faceplayer
	goto_if_unset FLAG_MYSTERY_MAN_BAG_FULL, MysteryManOldSeaMap_2
	msgbox gText_MysteryMan_Return, MSGBOX_DEFAULT
MysteryManOldSeaMap_1:
	checkitem ITEM_OLD_SEA_MAP
	compare VAR_RESULT, TRUE
	goto_if_eq MysteryManOldSeaMap_6
	checkitemspace ITEM_OLD_SEA_MAP
	compare VAR_RESULT, FALSE
	goto_if_eq MysteryManOldSeaMap_10
MysteryManOldSeaMap_9:
	giveitem ITEM_OLD_SEA_MAP
	setflag FLAG_ENABLE_SHIP_FARAWAY_ISLAND
	setflag FLAG_RECEIVED_OLD_SEA_MAP
	msgbox MysteryManOldSeaMap_Obtained_Text, MSGBOX_AUTOCLOSE
MysteryManOldSeaMap_5:
	clearflag FLAG_MYSTERY_MAN_BAG_FULL
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject VAR_LAST_TALKED
	fadescreenswapbuffers FADE_FROM_BLACK
	setflag FLAG_HIDE_MYSTERY_MAN_FRONT_OF_LOUNGE5
	clearflag FLAG_HIDE_MYSTERY_MAN_LOUNGE6
	setvar VAR_MYSTERY_MAN_STATE, 3
	releaseall
	end

MysteryManOldSeaMap_2:
	msgbox MysteryManOldSeaMap_Text, MSGBOX_DEFAULT
	goto MysteryManOldSeaMap_1

MysteryManOldSeaMap_6:
	msgbox MysteryManOldSeaMap_HasTicketAlready, MSGBOX_AUTOCLOSE
	goto MysteryManOldSeaMap_5

MysteryManOldSeaMap_10:
	goto Common_EventScript_MysteryMan_NoBagSpace
	goto MysteryManOldSeaMap_9


MysteryManOldSeaMap_Text::
	.string "Oh, you're here {PLAYER}!\n"
	.string "Have you already used the\l"
	.string "first ticket?\p"
	.string "Well, not that it matters right\n"
	.string "now. Rather, aren't these\l"
	.string "flowers beautiful?\p"
	.string "That reminds me.\n"
	.string "Here the second ticket!$"

MysteryManOldSeaMap_Obtained_Text::
	.string "This ticket will allow you to sail\n"
	.string "to a place far away from Hoenn.\p"
	.string "If you like untouched nature\n"
	.string "you will like it there!\p"
	.string "Now, until next time!$"

MysteryManOldSeaMap_HasTicketAlready::
	.string "Oh... It seems you already have\n"
	.string "an OLD SEA MAP.\p"
	.string "In that case, I'll just go to the\n"
	.string "next location. Bye!$"
