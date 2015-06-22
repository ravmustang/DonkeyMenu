/*
	Donkey Menu GUI 
	by =RAV=MusTanG
	v0.7 Released since EpochPro are thieves 
*/
//=====================================================================================================================
// Donkey Menu Init 
//=====================================================================================================================
if (!isDedicated and hasInterface) then 
{
	waitUntil {alive vehicle player};	
	waitUntil {typeOF player != "VirtualMan_EPOCH"};
		[true] call compile preprocessFileLineNumbers "scripts\donkeymenu\donkeymenu.sqf";
};
//////////////////////
earplugsout = true;
/////////////////////
if (donkeymenuKeyPressEnabled) then {
	[] spawn {dmKeyPress = (findDisplay 46) displayAddEventHandler ["KeyDown","if ((_this select 1) == dpMenu_hotkeyDIKCodeNumber) then {[] call dp_Menu_Handler;};"];};
};