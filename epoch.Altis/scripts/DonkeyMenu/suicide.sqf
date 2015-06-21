/*
		Donkey Menu Suicide
		by =RAV=MusTanG
		DonkeyPunch.INFO
*/
_cnt = 3;
	for "_p" from 1 to 3 do
	{
		systemChat(format ["WARNING! You will call Death in %1s - Move to cancel",_cnt]);
		if (player distance _locationPlayer > 0.2) then {
			systemChat("Action cancelled");
			breakOut "exit";
		};
		sleep 1;
		_cnt = _cnt - 1;
	};
player playAction "Surrender";
sleep 1;
hint "....Death is here for you....";
sleep 2;
playSound "Bam";
sleep 3.5;
hint "Death has you now... rest in it's embrace....";
player switchMove  "AcinPercMrunSnonWnonDf_agony";
sleep  4.5;

	if (alive player) then {  
		player SetDamage 1.1; 
		sleep 1;
	};