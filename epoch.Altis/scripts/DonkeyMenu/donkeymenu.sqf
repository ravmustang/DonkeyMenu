/*
	Donkey Menu GUI v0.2 
	June 1,2015
	by =RAV=MusTanG
	DonkeyPunch.INFO
*/
donkeymenuKeyPressEnabled = true;
// HOTKEY CONFIGURATION FOR: TOGGLE EARPLUG IN/OUT VIA KEYPRESS FUNCTION
// List of Available Hotkey Options
//	To use	INSERT					as your hotkey, please choose:		1		in the variable below
//	To use	NumPadMultiply		as your hotkey, please choose:		2		in the variable below
//	To use	NumPadDivide			as your hotkey, please choose:		3		in the variable below
//	To use	F4							as your hotkey, please choose:		4		in the variable below
//	To use	F5							as your hotkey, please choose:		5		in the variable below
dpMenu_myHotkeyChoice = 4;
////////////////////////////////////////////////
//This is where you will uncomment the next two lines and add your UID's

admin_list = ["0","0"];// your admins go here
dpvip_list = ["0","0","0"];// your VIP/registered players here
////////////////////////////////////////////////
dpOpen_Crafting = {
	createdialog "Crafting_Menu_dialog";
};
dpOpen_Donator = {
	createdialog "Donator_Menu_dialog";
};
dpOpen_TempGroups = {
	[] execVM "scripts\group\dialog\groupMenu.sqf";
};

dp_Menu_Handler = 
{
	if ((getPlayerUID player) in admin_list) then
	{
		createdialog "Admin_Menu_GUI";
	}
	else
	{
		if ((getPlayerUID player) in dpvip_list) then
		{
			createdialog "Donator_Menu_GUI";
		}
		else
		{
			createdialog "Donkey_Menu_GUI";
		};
	};
};

dp_Possum_Play = {
		[player] execVM "scripts\donkeymenu\playpossum.sqf";
};

dp_Possum_Stop = {
		hint "Okay, I will stop faking!";
		player playAction "AgonyStop";	
		sleep 1;
		player enableSimulation true;
};

dp_suicide = {
	[]execVM "scripts\donkeymenu\suicide.sqf";
};

dp_Surrender = {
	[] execVM "scripts\donkeymenu\surrender.sqf";
};	 
dp_Surrender_Stop = {
	//player playMoveNow "AmovPercMstpSsurWnonDnon_AmovPercMstpSnonWnonDnon";//Animation out
	//player enableSimulation true;
		hint "Okay, I will stop Surrendering!";
		player playAction "AgonyStop";	
		sleep 1;
		player enableSimulation true;
};

dp_SurvivorHunt = {
	[] execVM "scripts\donkeymenu\survivorhunt\survivorhunt_client.sqf";
};

dp_AdminHunt = {
	[] execVM "scripts\donkeymenu\admin\adminhunt_client.sqf";
};
dp_StartArsenal = {
	[]execVM "ASORGS\open.sqf";
};

dp_pushUPS = {
		hint "Kicking Ass!";
		player playAction "AmovPercMstpSnonWnonDnon_exercisePushup";  //PUshUPs
};

dp_Squats = {
		hint "Get Some!";
		player playAction "AmovPercMstpSnonWnonDnon_exercisekneeBendB";  //Squats
};

dp_Karate = {
		hint "Everybody was Kung FOO Fighting!!!!!!";
		player playAction "AmovPercMstpSnonWnonDnon_exerciseKata";  //Karate
};

dp_Splits = {
		hint "OH MAN, Thats gotta hurt!";
		player playAction "Acts_EpicSplit";
};

dp_Frienly_ComeHere = {
		hint "Hope they get the drift";
		player playAction "Acts_NavigatingChopper_Loop";
};

dp_unrestrain = {
		hint "You are free to Go";
		player playAction "Acts_AidlPsitMstpSsurWnonDnon_out"; //sitting restrained to unrestrain and stand updateDrawIcon
};

dp_repairVehicle = {
		hint "You have fixed your vehicle";
		player playAction "Acts_carFixingWheel";
};

dp_SquadGesture_GetDown = {
		hint "Get the Fuck Down";
		player playAction "Acts_CrouchGetLowGesture";
};


dpMenu_hotkeyDIKCodeNumberINSERT 						= 210;
dpMenu_hotkeyDIKCodeNumberNUMPADMULTIPLY 	= 55;
dpMenu_hotkeyDIKCodeNumberNUMPADDIVIDE 			= 181;
dpMenu_hotkeyDIKCodeNumberF4									= 62;
dpMenu_hotkeyDIKCodeNumberF5									= 63;

switch dpMenu_myHotkeyChoice do {
	case 1:		{ dpMenu_hotkeyDIKCodeNumber = dpMenu_hotkeyDIKCodeNumberINSERT};
	case 2:		{ dpMenu_hotkeyDIKCodeNumber = dpMenu_hotkeyDIKCodeNumberNUMPADMULTIPLY};
	case 3:		{ dpMenu_hotkeyDIKCodeNumber = dpMenu_hotkeyDIKCodeNumberNUMPADDIVIDE};
	case 4:		{ dpMenu_hotkeyDIKCodeNumber = dpMenu_hotkeyDIKCodeNumberF4};
	case 5:		{ dpMenu_hotkeyDIKCodeNumber = dpMenu_hotkeyDIKCodeNumberF5};
	case 0;
	default		{ dpMenu_hotkeyDIKCodeNumber = dpMenu_hotkeyDIKCodeNumberINSERT};
};
publicVariable	"dpMenu_hotkeyDIKCodeNumber";