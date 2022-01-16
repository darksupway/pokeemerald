Forgotten_Cave_Entrance_MapScripts::
	.byte 0


Forgotten_Cave_Entrance_SomethingHappenedOutside::
	lock
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	setvar VAR_0x8004, 1
	setvar VAR_0x8005, 1
	setvar VAR_0x8006, 8
	setvar VAR_0x8007, 5
	special ShakeCamera
	waitstate
	waitmovement 0
	setvar VAR_BATTLE_FRONTIER_EAST_STATE, 1
	msgbox Forgotten_Cave_Entrance_SomethingHappenedOutside_Text_0, MSGBOX_AUTOCLOSE
	release
	end


AncientText1::
	lock
	msgbox AncientText1_Text_0, MSGBOX_SIGN
	release
	end


AncientText2::
	lock
	msgbox AncientText2_Text_0, MSGBOX_SIGN
	release
	end


AncientText3::
	lock
	msgbox AncientText3_Text_0, MSGBOX_SIGN
	release
	end


Forgotten_Cave_Entrance_SomethingHappenedOutside_Text_0:
	.string "Something seems to have happened\n"
	.string "outside the cave.$"

AncientText1_Text_0:
	.string "In ... land of ...isue the Al...hty Sin...h,\n"
	.string "the Orig...ne, cr...ted bei... of ti..., ...ace\l"
	.string "and distor...$"

AncientText2_Text_0:
	.string "Wit...em, tim... space d...orting artif...s\n"
	.string "cam... be.$"

AncientText3_Text_0:
	.string "Nine ...tifacts rest ... They ... possible\n"
	.string "...teract with beings of m...$"
