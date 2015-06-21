


private ["_movposadmin","_combatgrp","_AI_init","_rifleman","_sniper","_machinegunner","_posadmin","_nameadmin"];
_posadmin 	= (_this select 0 select 0);
_nameadmin 	= (_this select 0 select 1);

stopreinforceme = "string";
iamdead = "string";
if (debug_adminhunt) then {diag_log format ["NibbleGaming AdminHunt: Admin %1 called in reinforcements at %2", _nameadmin, _posadmin];};

_combatgrp = createGroup RESISTANCE;
_combatgrp setCombatMode "RED";
_combatgrp setBehaviour "COMBAT";

_AI_init = {
	(_this select 0) enableAI "TARGET";
	(_this select 0) enableAI "AUTOTARGET";
	(_this select 0) enableAI "MOVE";
	(_this select 0) enableAI "ANIM";
	(_this select 0) enableAI "FSM";
	(_this select 0) setskill 1;
	(_this select 0) allowDammage true;
	removeUniform 		(_this select 0);
	removeHeadgear 		(_this select 0);
	removeBackpack 		(_this select 0);
	removeallitems 		(_this select 0);
	removeAllWeapons 	(_this select 0);
	(_this select 0) forceAddUniform "U_NikosAgedBody";
	(_this select 0) addVest "V_Press_F";
	(_this select 0) addHeadgear "H_Hat_grey";
	(_this select 0) addMagazines ["11Rnd_45ACP_Mag", 3];
	(_this select 0) addWeapon "hgun_Pistol_heavy_01_F";
	(_this select 0) addHandgunItem "optic_MRD";
};	
		
_rifleman = _combatgrp createUnit ["I_Soldier_EPOCH", _posadmin, [], 10, "FORM"];
[_rifleman] call _AI_init;
_rifleman addWeapon "arifle_MX_GL_Black_F"; 
_rifleman addMagazines ["30Rnd_65x39_caseless_mag_Tracer",3]; 
_rifleman addPrimaryWeaponItem "acc_pointer_IR"; 
_rifleman selectWeapon "arifle_MX_GL_Black_F";

_sniper = _combatgrp createUnit ["I_Soldier_EPOCH", _posadmin, [], 10, "FORM"];
[_sniper] call _AI_init;
_sniper addWeapon "M14_EPOCH"; 
_sniper addMagazines ["20Rnd_762x51_Mag",3]; 
_sniper addPrimaryWeaponItem "optic_DMS"; 
_sniper selectWeapon "M14_EPOCH";
		
_machinegunner = _combatgrp createUnit ["I_Soldier_EPOCH", _posadmin, [], 10, "FORM"];
[_machinegunner] call _AI_init;
_machinegunner addWeapon "LMG_Zafir_F"; 
_machinegunner addMagazines ["150Rnd_762x51_Box_Tracer",3]; 
_machinegunner addPrimaryWeaponItem "optic_Arco"; 
_machinegunner selectWeapon "LMG_Zafir_F";

_combatgrp selectLeader _rifleman;

while {true} do {
	if ((movingadmin select 1) == (_nameadmin)) then {
		_movposadmin = (movingadmin select 0);
	};
	_combatgrp move _movposadmin;
	
	if ((stopreinforceme) == (_nameadmin)) exitWith {
		diag_log format ["NibbleGaming AdminHunt: Admin %1 stopped the AdminHunt, deleting AI's", _nameadmin];
		deleteVehicle _rifleman;
		deleteVehicle _sniper;
		deleteVehicle _machinegunner;
	};

	if ((iamdead) == (_nameadmin)) exitWith {
		if (debug_adminhunt) then {diag_log format ["NibbleGaming AdminHunt: Admin %1 died, cleaning up AI's in 10 minutes", _nameadmin];};
		sleep 600;
		deleteVehicle _rifleman;
		deleteVehicle _sniper;
		deleteVehicle _machinegunner;
		if (debug_adminhunt) then {diag_log format ["NibbleGaming AdminHunt: Admin %1 died, cleaning up AI's now", _nameadmin];};
	};
	sleep 5;
};