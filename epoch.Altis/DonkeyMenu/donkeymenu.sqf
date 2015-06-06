/*
	Donkey Menu GUI 
	June 1,2015
	by =RAV=MusTanG
	DonkeyPunch.INFO
*/
donkeymenuKeyPressEnabled = true;
// HOTKEY TOGGLE Donkey Menu
// Hotkey Options
//	To use	INSERT					as your hotkey, please choose:		1		in the variable below
//	To use	NumPadMultiply		as your hotkey, please choose:		2		in the variable below
//	To use	NumPadDivide			as your hotkey, please choose:		3		in the variable below
//	To use	F4							as your hotkey, please choose:		4		in the variable below
//	To use	F5							as your hotkey, please choose:		5		in the variable below
dpMenu_myHotkeyChoice = 4;

//dpMenu_Admin =[];
//dpMenu_Donator = [];

dpOpen_Crafting = {
	createdialog "Crafting_Menu_dialog";
};

dp_Menu_Handler = 
{
				createdialog "Donkey_Menu_GUI";
		
};
//Thanks ComputerMancer
dp_Possum_Play = {
		[player] execVM "donkeymenu\playpossum.sqf";
};

dp_Possum_Stop = {
		hint "Okay, I will stop faking!";
		player playAction "AgonyStop";	
		sleep 1;
		player enableSimulation true;
};

dp_suicide = {
	[]execVM "donkeymenu\suicide.sqf";
};

dp_Surrender = {
	[] execVM "donkeymenu\surrender.sqf";
};	 
dp_Surrender_Stop = {
	//player playMoveNow "AmovPercMstpSsurWnonDnon_AmovPercMstpSnonWnonDnon";//Animation out
	//player enableSimulation true;
		hint "Okay, I will stop Surrendering!";
		player playAction "AgonyStop";	
		sleep 1;
		player enableSimulation true;
};
//Thanks ComputerMancer!
dp_Earplugs = {
		if (earplugsout) then {
		systemchat "Earplugs have been inserted...";
		5 fadeSound 0.25;
		earplugsout=false;
	} else {
		systemchat "Earplugs have been removed.";
		10 fadeSound 1;	
		earplugsout=true;
	};	
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