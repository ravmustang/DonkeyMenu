diag_log "#NibbleGaming: AdminHunt initialized";

"reinforceme" addPublicVariableEventHandler {
	[_this select 1] execVM "scripts\donkeymenu\admin\reinforcements.sqf";
};