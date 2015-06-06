/*
	Donkey Menu GUI v1
	by =RAV=MusTanG
	DonkeyPunch.INFO
*/
cutText [format["Your attempting to make a Range Finder"], "PLAIN DOWN"];

 
   if ("Binocular" in items player AND "ItemGPS" in items player AND player hasWeapon "MultiGun")    then{

player removeItem "Binocular";
player removeItem "ItemGPS";



player playActionNow "Medic";

sleep 4;

_spawn = "Box_NATO_Wps_F";

_posplr = [((getPos player) select 0) + 2, ((getPos player) select 1) + 2, 0];


_spwnveh = _spawn createVehicle (_posplr);
clearWeaponCargoGlobal _spwnveh;
clearMagazineCargoGlobal _spwnveh;
clearItemCargoGlobal _spwnveh;
clearBackpackCargoGlobal _spwnveh;
_spwnveh additemcargoGlobal ["Rangefinder", 1];


sleep 3;

 

cutText [format["You've used your Materials to build a Range Finder."], "PLAIN DOWN"];
sleep 120; 
deleteVehicle _spwnveh;
} else {

SystemChat "You need a Multi Gun, A Binocular and A GPS to make Range Finder"; 

};


