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
            if ((getPlayerUID player) in admin_list) then
				{
					createdialog "Admin_Menu_GUI";
					createdialog "Donkey_Menu_GUI";
				};
				if ((getPlayerUID player) in dpvip_list && !admin_list)then
					{
						createdialog "Donator_Menu_dialog";
					}
					else
					{
						createdialog "Donkey_Menu_GUI";
					};
           
		};
        case 14:
        {
            if (variable and alive player) then {
                [] execVM ".sqf";
            };
        };
		case 211:   //delete key
		{
            
		};*/
	};
    _return
};

waituntil {!isnull (finddisplay 46)};
dpPress_Hotkey = (findDisplay 46) displayAddEventHandler ["KeyDown", "_this call DonkeyPunch_HotKeys; false;"];