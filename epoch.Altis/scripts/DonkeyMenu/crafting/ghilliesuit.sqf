/*
	Donkey Menu GUI v1
	by =RAV=MusTanG
	DonkeyPunch.INFO
*/
cutText [format["Your attempting to make a ghillie suit"], "PLAIN DOWN"];

 
   if ("PaintCanGrn" in magazines player AND "PaintCanBrn" in magazines player AND "Pelt_EPOCH" in magazines player AND player hasWeapon "Hatchet")    then{

player removeItem "Pelt_EPOCH";
player removeItem "PaintCanBrn";
player removeItem "PaintCanGrn";


player playActionNow "Medic";

sleep 4;

_spawn = "Box_NATO_Wps_F";

_posplr = [((getPos player) select 0) + 2, ((getPos player) select 1) + 2, 0];


_spwnveh = _spawn createVehicle (_posplr);
clearWeaponCargoGlobal _spwnveh;
clearMagazineCargoGlobal _spwnveh;
clearItemCargoGlobal _spwnveh;
clearBackpackCargoGlobal _spwnveh;
_spwnveh additemcargoGlobal ["U_O_FullGhillie_ard", 3];


sleep 3;

 

cutText [format["You've used your Materials to build a Ghillie Suit."], "PLAIN DOWN"];
sleep 120; 
deleteVehicle _spwnveh;
} else {

SystemChat "You need a Hatchet, 1 pelt, 1 can each of brown and green paint"; 

};