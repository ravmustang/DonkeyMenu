/*
	Donkey Menu GUI v1
	by =RAV=MusTanG
	DonkeyPunch.INFO
*/
cutText [format["Your attempting to make a Temporary Crate"], "PLAIN DOWN"];

 
   if ("ItemCorrugatedLg" in magazines player AND "ItemCorrugatedLg" in magazines player AND "ItemCorrugatedLg" in magazines player AND player hasWeapon "MeleeSledge")    then{

player removeItem "ItemCorrugatedLg";
player removeItem "ItemCorrugatedLg";
player removeItem "ItemCorrugatedLg";


player playActionNow "Medic";

sleep 4;

_spawn = "CargoNet_01_box_F";

_posplr = [((getPos player) select 0) + 2, ((getPos player) select 1) + 2, 0];


_spwnveh = _spawn createVehicle (_posplr);
clearWeaponCargoGlobal _spwnveh;
clearMagazineCargoGlobal _spwnveh;
clearItemCargoGlobal _spwnveh;
clearBackpackCargoGlobal _spwnveh;
//_spwnveh additemcargoGlobal ["U_O_GhillieSuit", 1];


sleep 3;

 

cutText [format["You've used your Materials to build a Temporary Crate!."], "PLAIN DOWN"];

} else {

SystemChat "You need 3 Large Metals and a Sledge IN Hand to build the crate"; 

};