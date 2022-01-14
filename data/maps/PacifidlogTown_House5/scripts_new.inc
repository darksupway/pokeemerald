PacifidlogTown_House5_EventScript_MirageIslandWatcherWife::
	lock
	faceplayer
	msgbox PacifidlogTown_House5_Text_NotGivenUp, MSGBOX_DEFAULT
	specialvar VAR_RESULT, IsMirageIslandPresentBox
	compare VAR_RESULT, TRUE
	goto_if_eq PacifidlogTown_House5_EventScript_MirageIslandWatcherWife_1
	msgbox PacifidlogTown_House5_Text_NoFittingBoxPokemon, MSGBOX_AUTOCLOSE
	release
	end

PacifidlogTown_House5_EventScript_MirageIslandWatcherWife_1:
	msgbox PacifidlogTown_House5_Text_FittingBoxPokemon, MSGBOX_AUTOCLOSE
	release
	end


PacifidlogTown_House5_Text_NotGivenUp::
	.string "My Husband still looks outside\n"
	.string "everyday…\p"
	.string "I wonder if we will ever see\n"
	.string "MIRAGE ISLAND again…\p"
	.string "Today it feels like…$"

PacifidlogTown_House5_Text_FittingBoxPokemon::
	.string "Oh! I somehow feel like today\n"
	.string "could be the day!$"

PacifidlogTown_House5_Text_NoFittingBoxPokemon::
	.string "I don't think I will ever see\n"
	.string "MIRAGE ISLAND again…$"
