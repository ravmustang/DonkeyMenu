/*
	LetThereBeLight
	by second_coming (http://epochmod.com/forum/index.php?/user/16619-second-coming/)
	Edited for custom use by Donkey Punch Servers
	Allow players to place temporary lighting at their base (requires player to be in range of a friendly jammer)
	
	*/	

// ======================================================================================================================================================================================
// User configurable Variables
// ======================================================================================================================================================================================

// Item to place
_ItemsClassName							= "TargetP_Inf3_F";	// Classname of the item to place
_ItemDisplayName						= "Bandit Range Target";				// Item name to display in the player menu

// Materials Required to Create Lights
_EnergyRequired							= 250;						// Amount of energy expended to build (0 for zero energy required)
_MaterialRequired1						= "ItemCorrugatedLg";				// First material required to build (default is 'CircuitParts' or Electronic Component)
_MaterialRequired1Count					= 2;
_MaterialRequired2						= "ItemCorrugated";			// Second material required to build (default is 'ItemCorrugated' or small metal parts)
_MaterialRequired2Count					= 2;
_AllowWithNoMaterial 					= true;						// Skip material check and allow players to place using no materials (still uses energy)
// Usage Restrictions
_MaxItems								= 4;							// Maximum amount of lights allowed within MaxLightsRange metres
_MaxItemsRange							= 100;						// Range to check for other placed lights (in metres)
_FriendlyJammerRangeCheck				= false;						// Require to be in range of friendly jammer
_FriendlyJammerRange					= 225;						// Range in metres allowed from friendly jammer
// ======================================================================================================================================================================================
// End of User configurable Variables
// ======================================================================================================================================================================================



SafeToPlace = false;	



_cnt = 3;
_locationPlayer = (getPosATL player);


// Check placing is okay
_NotValidReason = "";
_hasIt1 = _MaterialRequired1 in (magazines player);
_hasIt1Count = {_x == _MaterialRequired1} count magazines player;
_hasIt2 = _MaterialRequired2 in (magazines player);	
_hasIt2Count = {_x == _MaterialRequired2} count magazines player;
_hasEnough = false;

if((_hasIt1Count >= _MaterialRequired1Count && _hasIt2Count >= _MaterialRequired2Count) or _AllowWithNoMaterial) then
{
	_hasEnough = true;
}
else
{
	_NotValidReason = _NotValidReason + "Not enough materials\n";
};


_hasEnergy = false;
if(EPOCH_playerEnergy - _EnergyRequired >= 0) then
{		
	_hasEnergy = true;
}
else
{
	_NotValidReason = _NotValidReason + "Not enough Energy\n";
};

_CanPlace = false;
_nearItems = nearestObjects [player,[_ItemsClassName],_MaxItemsRange];
if(count _nearItems <= _MaxItems) then
{
	_CanPlace = true;	
}
else
{
	_NotValidReason = _NotValidReason + "Maximum number of lights already placed\n";
};

_FriendlyInRange = false;
{ 
	if ( (_x getVariable ["BUILD_OWNER", "-1"]) in [getPlayerUID player, Epoch_my_GroupUID] ) then 
	{
		_FriendlyInRange = true;
	} 
} forEach nearestObjects [player, ["PlotPole_EPOCH"], _FriendlyJammerRange];

if(!_FriendlyJammerRangeCheck) then
{
	_FriendlyInRange = true;
}
else
{
	_NotValidReason = _NotValidReason + "Not in range of friendly jammer\n";
};

_CanBuild = (position player) nearRoads 10;
_Nearest = _CanBuild select 0;
if(!isNil "_Nearest")then
{
	_CanPlace = false; 
	_NotValidReason = _NotValidReason + "Too near a road\n";
};

if(_hasEnough && _hasEnergy && _CanPlace && _FriendlyInRange) then
{
	for "_p" from 1 to 3 do
	{
		systemChat(format ["WARNING! Spawning %1 in %2 seconds - Move to cancel",_ItemDisplayName,_cnt]);
		if (player distance _locationPlayer > 0.2) then 
		{
			systemChat("Action cancelled");
			breakOut "exit";
		};
		uiSleep 1;
		_cnt = _cnt - 1;
	};

	// Remove the materials required from the player
	if(_AllowWithNoMaterial) then
	{
		if(EPOCH_playerEnergy - _EnergyRequired < 0 )then
		{
			EPOCH_playerEnergy = 0;
		}
		else
		{
			EPOCH_playerEnergy = EPOCH_playerEnergy - _EnergyRequired;
		};
			
	}
	else
	{
		player removemagazines [_MaterialRequired1 select 0, _MaterialRequired1Count select 0];
		player removemagazines [_MaterialRequired2 select 0, _MaterialRequired2Count select 0];		
		uiSleep 0.1;	
		if(EPOCH_playerEnergy - _EnergyRequired < 0 )then
		{
			EPOCH_playerEnergy = 0;
		}
		else 
		{
			EPOCH_playerEnergy = EPOCH_playerEnergy - _EnergyRequired;
		};	
	};

	
	_object = _ItemsClassName createVehicle (position player);
	_object setDir ((getDir player) + 180);
	_object setVariable ["ObjectID", "1", true];
	_object setVariable ["ObjectUID", "1", true];
	_object attachto [player,[0.0,5.0,1]];

	_cnt = 5;
	_locationPlayer = (getPosATL player);
	for "_p" from 1 to 5 do
	{
		systemChat(format ["Placing %1 in %2 seconds - Move to cancel",_ItemDisplayName,_cnt]);
		if (player distance _locationPlayer > 5) then 
		{
			deleteVehicle _object;
			systemChat("Action cancelled");
			breakOut "exit";
		};
		uiSleep 1;
		_cnt = _cnt - 1;
	};		
	
	
	detach _object;
	player reveal _object;
	_object setPos [(getPos _object select 0), (getPos _object select 1), (getPosATL player select 2)];
	r_interrupt = false;
	player switchMove "";
	player playActionNow "stop";
	cutText [format["Spawned %1 DO NOT SAVE after server restart!",_ItemDisplayName], "PLAIN DOWN"];
	_ObjectPlaced = true;
}
else
{
		deleteVehicle _object;
		hint format["Placing %1 failed:\n%2",_ItemDisplayName,_NotValidReason];
		breakOut "exit";	
};
