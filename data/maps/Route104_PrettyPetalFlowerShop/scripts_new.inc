Route104_PrettyPetalFlowerShop_EventScript_SellBerries::
	lock
	faceplayer
	goto_if_unset FLAG_FIRST_TIME_BERRY_SELLER, Route104_PrettyPetalFlowerShop_EventScript_SellBerries_2
	message Route104_PrettyPetalFlowerShop_EventScript_SellBerries_Text
Route104_PrettyPetalFlowerShop_EventScript_SellBerries_1:
	waitmessage
	pokemart Pokemart_BerryShop
	msgbox Route104_PrettyPetalFlowerShop_EventScript_SellBerries_End_Text, MSGBOX_DEFAULT
	release
	end

Route104_PrettyPetalFlowerShop_EventScript_SellBerries_2:
	message Route104_PrettyPetalFlowerShop_EventScript_SellBerries_First_Text
	setflag FLAG_FIRST_TIME_BERRY_SELLER
	goto Route104_PrettyPetalFlowerShop_EventScript_SellBerries_1


	.align 2
Pokemart_BerryShop:
	.2byte ITEM_CHERI_BERRY
	.2byte ITEM_CHESTO_BERRY
	.2byte ITEM_PECHA_BERRY
	.2byte ITEM_RAWST_BERRY
	.2byte ITEM_ASPEAR_BERRY
	.2byte ITEM_LEPPA_BERRY
	.2byte ITEM_ORAN_BERRY
	.2byte ITEM_PERSIM_BERRY
	.2byte ITEM_LUM_BERRY
	.2byte ITEM_SITRUS_BERRY
	.2byte ITEM_FIGY_BERRY
	.2byte ITEM_WIKI_BERRY
	.2byte ITEM_MAGO_BERRY
	.2byte ITEM_AGUAV_BERRY
	.2byte ITEM_IAPAPA_BERRY
	.2byte ITEM_RAZZ_BERRY
	.2byte ITEM_BLUK_BERRY
	.2byte ITEM_NANAB_BERRY
	.2byte ITEM_WEPEAR_BERRY
	.2byte ITEM_PINAP_BERRY
	.2byte ITEM_POMEG_BERRY
	.2byte ITEM_KELPSY_BERRY
	.2byte ITEM_QUALOT_BERRY
	.2byte ITEM_HONDEW_BERRY
	.2byte ITEM_GREPA_BERRY
	.2byte ITEM_TAMATO_BERRY
	.2byte ITEM_CORNN_BERRY
	.2byte ITEM_MAGOST_BERRY
	.2byte ITEM_RABUTA_BERRY
	.2byte ITEM_NOMEL_BERRY
	.2byte ITEM_SPELON_BERRY
	.2byte ITEM_PAMTRE_BERRY
	.2byte ITEM_WATMEL_BERRY
	.2byte ITEM_DURIN_BERRY
	.2byte ITEM_BELUE_BERRY
	.2byte ITEM_GANLON_BERRY
	.2byte ITEM_SALAC_BERRY
	.2byte ITEM_PETAYA_BERRY
	.2byte ITEM_APICOT_BERRY
	.2byte ITEM_LANSAT_BERRY
	.2byte ITEM_STARF_BERRY
	.2byte ITEM_NONE
	release
	end

Route104_PrettyPetalFlowerShop_EventScript_SellBerries_First_Text::
	.string "Welcome, this is our first time\n"
	.string "meeting right?\p"
	.string "I just began working here and\n"
	.string "sell all sorts of berries.\p"
	.string "Would you like to have a look?$"

Route104_PrettyPetalFlowerShop_EventScript_SellBerries_Text::
	.string "Welcome to the Berry Shop.\n"
	.string "How can I help you?$"

Route104_PrettyPetalFlowerShop_EventScript_SellBerries_End_Text::
	.string "Please come again!$"
