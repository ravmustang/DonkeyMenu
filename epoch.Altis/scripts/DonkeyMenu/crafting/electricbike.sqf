/*
	Donkey Menu GUI v1
	by =RAV=MusTanG
	DonkeyPunch.INFO
*/
if (EPOCH_playerCrypto >= 200) then {
	
	_cnt = 3;
	_locationPlayer = (getPosATL player);
	for "_p" from 1 to 3 do
	{
		systemChat(format ["WARNING! Buying Electric Bike in %1s - Move to cancel",_cnt]);
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
	ebike = [player, _spawnPos, _spawnDir];
	EPOCH_playerCrypto = EPOCH_playerCrypto - 200 ;
	uisleep 3;
	publicVariableServer "ebike";
	uisleep 1;
	['This Vehicle does not save on restart !',0,0.7,2,0] spawn bis_fnc_dynamictext;
	player removeAction ebike;
} else{
	['You need 200 Crypto. Get Lootin, poor Bitch! DONKEYPUNCH.INFO',0,0.7,2,0] spawn bis_fnc_dynamictext;
};