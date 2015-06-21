
private ["_start","_stop","_exit","_hint","_nameadmin","_reinforcements","_reinforce","_markercolor","_markertext","_markername","_markeradmin"];

_nameadmin = name player;
player setCaptive false;
starthunt = false;  //needs to be a global variable for addaction to work
stophunt = false;	//needs to be a global variable for addaction to work
exitmenu = false;	//needs to be a global variable for addaction to work
reinforce = false;	//needs to be a global variable for addaction to work
_reinforcements = false;
player removeAction nibblemenu;	
		/* ---   give admin the mission menu ---- */
_start = player addaction ["<t color='#00FF00'>Start Survivor hunt</t><t color='#30FF00'> - remember to gear up with valid loot - </t>",{starthunt = true;},"",-93,false,false,"",""]; 
_exit = player addaction ["<t color='#FFFFFF'>Exit menu</t>",{exitmenu = true;},"",-95,false,false,"",""];
	
		/* ---   wait for admins to activate mission ---- */
waitUntil {starthunt or exitmenu};
if (exitmenu) then {
	player removeAction _start; 
	player removeAction _exit;
	player removeAction nibblemenu;
};
if (starthunt) then {
	player removeAction _start;
	player removeAction _exit; 
	_stop = player addaction ["<t color='#FFFF00'>Terminate Survivor Hunt</t>",{stophunt = true;},"",-94,false,false,"",""];
	//_reinforce = player addaction ["<t color='#55FF00'>Get reinforcements</t>",{reinforce = true;},"",-93,false,false,"",""];
	if (debug_adminhunt) then {diag_log "#NibbleGaming AdminHunt: starting mission";};
			
	/* ---   give players the hint ---- */
	_hint	 = format ["<t align='center' size='2.0' color='#f29420'>Mission<br/>SURVIVOR HUNT</t><br/>
<t size='1.25' color='#ffff00'>______________<br/><br/>
%1 Has Activated SURVIVOR HUNT!<br/>
Check your map to see where he is, kill him!!!</t>",_nameadmin];
	NibbleHint = [0,_hint]; publicVariable "NibbleHint";

	/* ---   give admin the hint as well, for good measures ---- */
	hint parseText format["%1", _hint];

	/* ---   Create the marker  ---- */
	_markercolor = ["ColorYellow","Color4_FD_F","Color1_FD_F","ColorOrange","ColorWhite","ColorPink"] call BIS_fnc_selectRandom;;
	_markertext  = format ["Survivor: %1",_nameadmin];
	_markername  = format ["marker: %1",_nameadmin];
	_markeradmin = createMarker [_markername, getPos player];
	_markeradmin setMarkerShape "ICON";
	_markeradmin setMarkerType "mil_triangle";
	_markeradmin setMarkerColor _markercolor;
	_markeradmin setMarkerText _markertext;

	/* ---   the actual mission ---- */
if (isNil "marker_refreshtime") then {
    marker_refreshtime = 60;
};
[_markeradmin] spawn {
	while {alive player} do {
		_markeradmin = _this select 0;
		_markeradmin setMarkerPos getPos player;
		sleep marker_refreshtime;
			if (!alive player) exitWith {
				deletemarker _markeradmin;
			};
		if (stophunt) exitWith {};
		};
	};
	while {alive player} do {
		if (reinforce) then {
			/* ---   addeventhandler if something goes wrong when player dies, too make sure AI fire at him after respawn ---*/
			player addEventHandler ["killed", {
			player setCaptive false; ///probably not needed
			}];
					
			/* ---   spawn AI's ---*/
			reinforce = false;	
			player setCaptive true;
			_reinforcements = true;
			player removeaction _reinforce;
			movingadmin = [Getpos player,_nameadmin];
			PublicVariableServer "movingadmin";			
			reinforceme = [getpos player,_nameadmin];			
			PublicVariableServer "reinforceme";
			_hint = format ["<t align='center' size='2.0' color='#f29420'>Mission<br/>Survivor Hunt Reinforcements!</t><br/>
<t align='left' size='1.25' color='#ffff00'>______________<br/><br/>
%1 feels threatened and got reinforcements<br/>
Kill him and his bodyguards to finish the mission</t>",_nameadmin];
			NibbleHint = [0,_hint]; publicVariable "NibbleHint";
			hint parseText format["%1", _hint];
					[] spawn {
						while {alive player} do {
							player setCaptive true;
							sleep 0.5;
							if (stophunt) exitWith {};
							_plyrdist = getpos player;
							sleep 5;
								if ((player distance _plyrdist) > 5) then {
									movingadmin = [Getpos player,name player];
									PublicVariableServer "movingadmin";
								};
							sleep 2;
						};
					};
			};
					
			if (stophunt) exitWith {
/*---   Mission stopped ---- */
			
				_hint = 	format ["<t align='center' size='2.0' color='#6bab3a'>Mission aborted</t><br/>
<t align='left' size='1.25' color='#ffff00'>______________<br/><br/>
The Survivor chickened out and stopped the mission. %1 is a fucking pussy!</t>",_nameadmin];
								
				NibbleHint = [1,_hint]; 
				publicVariable "NibbleHint";
				hint parseText format["%1", _hint];
				deletemarker _markeradmin;
				player removeAction _stop; 	
				//player removeaction _reinforce;
				if (_reinforcements) 	then {
				 	stopreinforceme = _nameadmin;
				 	PublicvariableServer "stopreinforceme";
				};
				player setCaptive false;
				_reinforcements = false;
				//nibblemenu = player addaction [("" + ("Admin menu") +""),"scripts\AdminHunt\adminhunt_client.sqf","",-97,false,false,"",""];
			};
			
			if (!alive player) exitwith {
/*---   Mission success ---- */					
				player setCaptive false;
				deletemarker _markeradmin;
				player removeAction _stop; 	
				player removeaction _reinforce;
				if (_reinforcements) then {
					_hint = 	format ["<t align='center' size='2.0' color='#6bab3a'>Survivor Hunt Success</t><br/>
<t align='left' size='1.25' color='#ffff00'>______________<br/><br/>
Survivor %1 is dead<br/>
but be careful, his bodyguards might still be in the area..</t>",_nameadmin];
					deletemarker _markeradmin;						
					NibbleHint = [2,_hint]; publicVariable "NibbleHint";
					hint parseText format["%1", _hint];
					iamdead = _nameadmin;
					PublicVariableServer "iamdead";	
				} else {
					
					_hint = format ["<t align='center' size='2.0' color='#6bab3a'>Survivor Hunt Success</t><br/>
<t align='left' size='1.25' color='#ffff00'>______________<br/><br/>
Survivor %1 is dead</t>",_nameadmin];
					deletemarker _markeradmin;						
					NibbleHint = [2,_hint]; publicVariable "NibbleHint";
					hint parseText format["%1", _hint];
				};
			
			};
		sleep 1;
		};
						
	if (debug_adminhunt) then {diag_log "#NibbleGaming Adminhunt: ending mission";};
	player setCaptive false;
};

			
		