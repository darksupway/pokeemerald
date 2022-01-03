EventScript_RepelWoreOff::
	lockall

	bufferitemname 1, VAR_REPEL_LAST_USED
	checkitem VAR_REPEL_LAST_USED
	compare VAR_RESULT, FALSE
	goto_if_eq EventScript_RepelWoreOff_NoMoreRepels

	msgbox Text_RepelWoreOff_UseAnother, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq EventScript_RepelWoreOff_ChooseNo

	special RenewRepelSteps

	removeitem VAR_REPEL_LAST_USED, 1
	playse SE_REPEL
	msgbox Text_PlayerUsesRepelAgain, MSGBOX_SIGN
	goto EventScript_RepelWoreOff_End
EventScript_RepelWoreOff_ChooseNo:
	closemessage
	goto EventScript_RepelWoreOff_End
EventScript_RepelWoreOff_NoMoreRepels:
	msgbox Text_RepelWoreOff, MSGBOX_SIGN
EventScript_RepelWoreOff_End:
	releaseall
	end

Text_PlayerUsesRepelAgain:
	.string "{PLAYER} used the\n"
	.string "{STR_VAR_2}.$"

Text_RepelWoreOff:
	.string "REPEL's effect wore off…\n"
	.string "{STR_VAR_2}S ran out.$"

Text_RepelWoreOff_UseAnother:
	.string "REPEL's effect wore off…\n"
	.string "Use another?$"
