#include "macro.sqf"
private ["_nv", "_items"];
_nv = call ASORGS_fnc_GetNightvision;
_items = (ASORGS_CurrentInventory select GSVI_Items) - [_nv];
ASORGS_CurrentInventory set [GSVI_Items, _items];
ASORGS_WeightChanged = true;