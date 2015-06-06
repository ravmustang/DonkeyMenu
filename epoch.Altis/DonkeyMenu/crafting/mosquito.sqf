/*
	Donkey Menu GUI v1
	by =RAV=MusTanG
	DonkeyPunch.INFO
*/
_costs = 300;
if (EPOCH_playerCrypto < _costs && isHalvTradeEnabled) exitWith {cutText [format["You need %1 Crypto. Get Lootin, poor Bitch! DONKEYPUNCH.INFO", _costs], "PLAIN DOWN"];};

	
	_cnt = 3;
	_locationPlayer = (getPosATL player);
	for "_p" from 1 to 3 do
	{
		systemChat(format ["WARNING! Buying Mosquito in %1s - Move to cancel",_cnt]);
		if (player distance _locationPlayer > 0.2) then {
			systemChat("Action cancelled");
			breakOut "exit";
		};
		sleep 1;
		_cnt = _cnt - 1;
	};
	
	player playActionNow "Medic";
	_spawnPos = player modelToWorld [0,2,0];
	_spawnDir = (getDir player) -90;
	mosq = [player, _spawnPos, _spawnDir];
	if(_costs > 0 && isHalvTradeEnabled)then{
	HALV_takegive = [player,(_costs*-1),true];
	publicVariableServer "HALV_takegive";
	sleep 3;
	publicVariableServer "mosq";
	sleep 1;
	['This Vehicle does not save on restart !',0,0.7,2,0] spawn bis_fnc_dynamictext;
	player removeAction mosq;
};