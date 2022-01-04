PacifidlogTown_House5_EventScript_MirageIslandWatcherWife::
	lock
	faceplayer
	specialvar VAR_RESULT, IsMirageIslandPresentBox
	compare VAR_RESULT, TRUE
	goto_if_eq PacifidlogTown_House5_EventScript_MirageIslandWatcherWife_2
	msgbox NoFittingBoxPokemon_Text, MSGBOX_AUTOCLOSE
PacifidlogTown_House5_EventScript_MirageIslandWatcherWife_1:
	release
	end

PacifidlogTown_House5_EventScript_MirageIslandWatcherWife_2:
	msgbox FittingBoxPokemon_Text, MSGBOX_AUTOCLOSE
	goto PacifidlogTown_House5_EventScript_MirageIslandWatcherWife_1


FittingBoxPokemon_Text::
	.string "Oh! I somehow feel like today\n"
	.string "could be the day!$"

NoFittingBoxPokemon_Text::
	.string "I don't think I will ever see\n"
	.string "MIRAGE ISLAND again…$"
