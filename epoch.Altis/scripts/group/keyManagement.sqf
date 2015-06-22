/*
	ArmA 3 Epoch Donkey Punch
	by =RAV=MusTanG
	HotKey Manager v1.0
*/

if (!isnil "dpPress_Hotkey") then 
{
	(findDisplay 46) displayRemoveEventHandler ["KeyDown", dpPress_Hotkey];
};

DonkeyPunch_HotKeys =
{
	private ["_key", "_return"];
	_key = _this select 1;
	_return = false;
    
	switch (_key) do 
	{
		case 210:  //Insert key
		{
            [] execVM "scripts\group\dialog\groupMenu.sqf";
		};
		/*case 62:  //F4 63 is F5
		{
           [] call dp_Menu_Handler;
		};*/
	};
    _return
};

waituntil {!isnull (finddisplay 46)};
dpPress_Hotkey = (findDisplay 46) displayAddEventHandler ["KeyDown", "_this call DonkeyPunch_HotKeys; false;"];