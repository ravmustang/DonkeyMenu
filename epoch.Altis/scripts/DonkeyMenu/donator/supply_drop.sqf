
	openMap [true,true];
	clicked = 0;
	hintc "Left click on the map where you want the supplies dropped";

	["supplymapclick", "onMapSingleClick", {
		_supplyLocArray = [+1000,-1375,-1500,-1125,+1250,-1000,+1375,-1250,+1500,+1125];
//:::::::::::|USE THE ONE BELOW FOR TESTING, IT SPAWNS THE HELI MUCH CLOSER|:::::::::::
//		_supplyLocArray = [+500,-500];
		_supplyRandomLocX = _supplyLocArray select floor random count _supplyLocArray;
		_supplyRandomLocY = _supplyLocArray select floor random count _supplyLocArray;
		_supply = [[(_pos select 0)+_supplyRandomLocX,
					(_pos select 1)+_supplyRandomLocY, 
					(_pos select 2)+50], 180, "I_Heli_Transport_02_F", WEST] call bis_fnc_spawnvehicle;
		_supplyHeli = _supply select 0;
		_supplyHeliPos = getPos _supplyHeli;
		_supplyMrkrHeli = createMarker ["supplyMrkrHeli", _supplyHeliPos];
		_supplyCrew = _supply select 1;
		_supplyGrp = _supply select 2;
		_supplyGrp setSpeedMode "FULL";
		_supplyGrp setBehaviour "CARELESS";
		_supplyWP1 =_supplyGrp addWaypoint [(_pos),1];
		_supplyWP1 setWaypointType "MOVE";
		_supplyWP2 = _supplyGrp addWaypoint [[(_pos select 0)+_supplyRandomLocX, 
											(_pos select 1)+_supplyRandomLocY, 
											_pos select 2], 2];
		_supplyMrkrLZ = createMarker ["supplyMrkrLZ", _pos];
		"supplyMrkrLZ" setMarkerType "Empty";
		"supplyMrkrHeli" setMarkerType "Empty";
		_supplyHeli flyInHeight 150;
		clicked = 1;
		openmap [false,false];
		onMapSingleClick '';}] call BIS_fnc_addStackedEventHandler; 

	waitUntil {(clicked == 1)};
		hint "The supplies are on the way";
		_supplyMrkrHeliPos = getMarkerPos "supplyMrkrHeli";
		_supplyMrkrHeliPos2 = [_supplyMrkrHeliPos select 0, 
								_supplyMrkrHeliPos select 1, 
								(_supplyMrkrHeliPos select 2)+50];
		_supplyHeli = _supplyMrkrHeliPos2 nearestObject "I_Heli_Transport_02_F";
		_supplyMrkrLZPos = getMarkerPos "supplyMrkrLZ"; 
		_supplyLZ = createVehicle ["Land_Laptop_device_F", getMarkerPos "supplyMrkrLZ", [], 0, "NONE"];
		deleteMarker "supplyMrkrHeli";
		deleteMarker "supplyMrkrLZ";
		_supplyLZ hideObject true;
		
	waitUntil {( _supplyLZ distance _supplyHeli)<400};
		_supplyHeli animateDoor ["CargoRamp_Open",1];
	waitUntil {( _supplyLZ distance _supplyHeli)<200};
		sleep 2;
		_supplyHeli allowDammage false;
		_supplyBoxFnc = "B_CargoNet_01_ammo_F";
		_supplyBox = createVehicle [_supplyBoxFnc, position _supplyHeli, [], 0, "CAN_COLLIDE"];
						clearBackpackCargoGlobal _supplyBox;
						clearWeaponCargoGlobal _supplyBox;
						clearMagazineCargoGlobal _supplyBox;
						clearItemCargoGlobal _supplyBox;
						_supplyBox addWeaponCargoGlobal ["LMG_Mk200_MRCO_F", 2];
						_supplyBox addWeaponCargoGlobal ["arifle_MXM_RCO_pointer_snds_F", 2];
						_supplyBox addMagazineCargoGlobal ["30Rnd_65x39_caseless_mag_Tracer", 4];
						_supplyBox addMagazineCargoGlobal ["200Rnd_65x39_cased_Box_Tracer", 4];
						_supplyBox additemcargoGlobal ["NVG_EPOCH", 2];
						_supplyBox additemcargoGlobal ["Rangefinder", 2];
						_supplyBox additemcargoGlobal ["FAK", 3];
						_supplyBox additemcargoGlobal ["optic_Arco", 1];
						_supplyBox additemcargoGlobal ["ItemKiloHemp", 3];
						_supplyBox additemcargoGlobal ["ItemRuby", 1];
						_supplyBox additemcargoGlobal ["Pelt_EPOCH", 4];
						_supplyBox additemcargoGlobal ["meatballs_epoch", 2];
						_supplyBox additemcargoGlobal ["HeatPack", 3];
						_supplyBox additemcargoGlobal ["ItemSodaOrangeSherbet", 2];
						_supplyBox additemcargoGlobal ["optic_ACO_grn", 1];
						_supplyBox additemcargoGlobal ["U_O_GhillieSuit", 1];
						_supplyBox addbackpackcargoGlobal ["B_Carryall_cbr", 1];				
		_supplyBox disableCollisionWith _supplyHeli;
		_supplyHeli disableCollisionWith _supplyBox;
		_supplyBox allowDammage false;
		_supplyBox attachTo [_supplyHeli, [0, 0, 0], "CargoRamp"]; 
		_supplyBox setDir ([_supplyBox, _supplyHeli] call BIS_fnc_dirTo);
		detach _supplyBox;
		
		//:::::::::::|Marker|:::::::::::
		_marker = createMarker ["SupplyMarker1", position _supplyLZ];
		_marker setMarkerType "mil_objective";
		"SupplyMarker1" setMarkerText "Supply Drop";
		"SupplyMarker1" setMarkerColor "ColorCIV";
		//:::::::::::::::::::::::::::::::
		
		deleteVehicle _supplyLZ; 
		
		
	_supplyChute = createVehicle ["B_parachute_02_F", position _supplyBox, [], 0, "FLY"];
	_supplyBox attachTo [_supplyChute,[0,1,0]];	
	//_supplyChute hideObject true;
	_supplyChute setPos getPos _supplyBox;
																			
//:::::::::::|LIGHT|:::::::::::
	_supplyLight = "Chemlight_green" createVehicle (position _supplyBox);
	_supplyLight attachTo [_supplyBox, [0,0,0]];
//:::::::::::::::::::::::::::::		
	sleep 1;
	hint "The supplies have been dropped and can be found in the marked zone within a 200m radius.";
	_supplyChute hideObject false;
	_supplyChute allowDammage false;
	_supplyHeli allowDammage true;
	_supplyBox allowDammage true;
	_supplyHeli animateDoor ["CargoRamp_Open",0];
	
//:::::::::::|SMOKE|:::::::::::
	_supplySmoke = "SmokeShell" createVehicle (position _supplyBox);
	_supplySmoke attachTo [_supplyBox, [0,0,0]];
//:::::::::::::::::::::::::::::
	
	waitUntil {(getPos _supplyBox select 2)<2};
	//detach _supplyBox;
		//_supplyChute setPos [ (getPos _supplyChute select 0)+0.75, getPos _supplyChute select 1, getPos _supplyChute select 2];
		hint "";
		sleep 5;
		{deleteVehicle _x;}forEach crew _supplyHeli;deleteVehicle _supplyHeli;deleteVehicle _supplyGrp;
		//hint "end";

// Cleanup
sleep 300;
deleteMarker "SupplyMarker1"; 



