[] execVM "scripts\group\keyManagement.sqf";
//=====================================================================================================================
//Start of NibbleGaming AdminHunt:
debug_adminhunt = true;

if (isDedicated) then {
    [] execVM "scripts\donkeymenu\admin\adminhunt_server_init.sqf";
};

if (!isDedicated) then {
    marker_refreshtime = 60;

	"NibbleHint" addPublicVariableEventHandler { private "_sound";
        _sound = (_this select 1) select 0;
        switch(_sound)do{
            case 0:{playSound "UAV_05"}; //Mission started
            case 1:{playSound "UAV_01"}; //admin stopped mission
            case 2:{playsound "UAV_03"}; //Admin dead
        };
        hint parseText format["%1", (_this select 1) select 1]
    };
};
// End of NibbleGaming AdminHunt

currentInvites = [];
publicVariable "currentInvites";

if(!isServer) exitWith {};

while {true} do {
	publicVariable "currentInvites";
    sleep 1; 
};