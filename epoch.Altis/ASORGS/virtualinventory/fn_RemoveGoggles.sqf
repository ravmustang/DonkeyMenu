#include "macro.sqf"
_goggles = call ASORGS_fnc_GetGoggles;
_items = (ASORGS_CurrentInventory select GSVI_Items) - [_goggles];
ASORGS_CurrentInventory set [GSVI_Items, _items];
ASORGS_WeightChanged = true;