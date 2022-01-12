MauvilleCity_BikeShop_EventScript_GetNewAcroBike::
	message MauvilleCity_BikeShop_Text_ExplainBike
	waitmessage
	msgbox MauvilleCity_BikeShop_Text_ReceivedBike, MSGBOX_DEFAULT
	giveitem ITEM_ACRO_BIKE
	msgbox MauvilleCity_BikeShop_Text_HowToSwapModes, MSGBOX_AUTOCLOSE
	release
	end


MauvilleCity_BikeShop_EventScript_HowToSwapModesReturn::
	msgbox MauvilleCity_BikeShop_Text_HowToSwapModesReturn, MSGBOX_AUTOCLOSE
	release
	end


MauvilleCity_BikeShop_Text_ExplainBike::
	.string "RYDEL: Hm, hm… … … … …\p"
	.string "You're saying that you came all this\n"
	.string "way from LITTLEROOT?\p"
	.string "My goodness!\n"
	.string "That's ridiculously far!\p"
	.string "If you had one of my BIKES, you could\n"
	.string "go anywhere easily while feeling the\l"
	.string "gentle caress of the wind!\p"
	.string "I'll tell you what!\n"
	.string "I'll give you a BIKE!\p"
	.string "To be honest I just got a new\n"
	.string "model of the ACRO BIKE.\p"
	.string "This new model combines the\n"
	.string "features of the former ACRO BIKE\l"
	.string "and MACH BIKE.\p"
	.string "The MACH BIKE was for cyclists who\n"
	.string "want to feel the wind with their\l"
	.string "bodies!\p"
	.string "And the old ACRO BIKE was for those\n"
	.string "who prefer technical rides!\p"
	.string "Well, here you go!$"

MauvilleCity_BikeShop_Text_ReceivedBike::
	.string "{PLAYER} RECEIVED a BIKE.$"

MauvilleCity_BikeShop_Text_HowToSwapModes::
	.string "RYDEL: To switch between ACRO mode\n"
	.string "and MACH mode press both the\l"
	.string "L- and R-BUTTON at the same time.\p"
	.string "I hope you will like your new bike\n"
	.string "and use it a lot!$"

MauvilleCity_BikeShop_Text_HowToSwapModesReturn::
	.string "RYDEL: Oh, you are back!\n"
	.string "Do you like the BIKE?\p"
	.string "Just to make sure you remember it:\n"
	.string "To switch between ACRO and MACH mode\l"
	.string "press the L- and R-BUTTON at the\l"
	.string "same time.\p"
	.string "Well, good luck on the rest of\n"
	.string "your journey and I hope you use\l"
	.string "my BIKE a lot!$"
