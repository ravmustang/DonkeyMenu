/*
	Donkey Menu GUI v.2
	by =RAV=MusTanG
	DonkeyPunch.INFO
*/
// Control types
#define CT_MAP_MAIN 101
#define CT_STRUCTURED_TEXT 13
// Static styles
#define ST_PICTURE 0x30
#define ST_MULTI 16
// Listbox styles
#define ST_LEFT 0x00
#define LB_TEXTURES 0x10

// Base Classes
class DMadm_IGUIBack
{
	type = 0;
	idc = -1;
	style = 128;
	text = "";
	colorText[] = {.1,.1,.1,.6};
	font = "PuristaMedium";
	sizeEx = 0;
	shadow = 0;
	x = 0.1;
	y = 0.1;
	w = 0.1;
	h = 0.1;
	colorbackground[] = {0,0,0,0};
};

class DMadm_RscFrame
{
	type = 0;
	idc = -1;
	style = 64;
	shadow = 2;
	colorBackground[] = {0.969,0,0,1};
	colorText[] = {0.969,0,0,1};
	font = "PuristaLight";
	sizeEx = 1.3;
	text = "";
};


class DMadm_RscButton
{
	access = 0;
	type = 1;
	text = "";
	colorDisabled[] = {0.4,0.4,0.4,1};
	colorBackground[] = {.7,.7,.7,.6};
	colorBackgroundDisabled[] = {.95,.95,.95,1};
	colorBackgroundActive[] = {.3,.3,.3,.6};
	colorFocused[] = {.7,.7,.7,.8};
	colorShadow[] = {.1,.1,.1,1};
	colorBorder[] = {.7,.7,.7,.5};
	soundEnter[] = {"\A3\ui_f\data\sound\RscButton\soundEnter",0.09,1};
	soundPush[] = {"\A3\ui_f\data\sound\RscButton\soundPush",0.09,1};
	soundClick[] = {"\A3\ui_f\data\sound\RscButton\soundClick",0.09,1};
	soundEscape[] = {"\A3\ui_f\data\sound\RscButton\soundEscape",0.09,1};
	style = 2;
	shadow = 1;
	font = "PuristaMedium";
	sizeEx = "(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)";
	offsetX = 0.003;
	offsetY = 0.003;
	offsetPressedX = 0.002;
	offsetPressedY = 0.002;
	borderSize = 0;
};

class DMadm_RscText
{
	 access = 0;
	 type = CT_STATIC;
	 idc = -1;
	 style = 2;
	 w = 0.1; h = 0.05;
	 //x and y are not part of a global class since each rsctext will be positioned 'somewhere'
	 font = "PuristaMedium";
	 text = "";
	 fixedWidth = 0;
	 shadow = 0;
	 sizeEx = 0.05;
	 colorText[] = {0,0,1,1.5};
	 colorBackground[] = {0,0,0,0};
};

class DMadm_RscStructuredText
{
	access = 0;
	type = CT_STRUCTURED_TEXT;
	idc = -1;
	style = ST_LEFT;
	colorText[] = {0,0,1,1};
	colorBackground[] = {.1,.1,.1,.6};
	class Attributes
	{
		font = "PuristaMedium";
		color = "#ffffff";
		align = "center";
		shadow = 1;
	};
	x = 0;
	y = 0;
	h = 0.035;
	w = 0.1;
	text = "";
	size = "(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)";
	shadow = 1;
};
class DMadm_RscPicture
{
    access = 0;
    idc = -1;
    type = CT_STATIC;
    style = ST_PICTURE;
    colorBackground[] = {0.502,0.502,0.502,0.01};
    colorText[] = {1,1,1,1};
    font = "PuristaMedium";
    sizeEx = 0;
    lineSpacing = 0;
    text = "";
    fixedWidth = 0;
    shadow = 0;
    x = 0;
    y = 0;
    w = 0.2;
    h = 0.15;
};

class admin_menu_gui {
	
	idd = 8083;
	movingEnable = true;
	enableSimulation = false;
	controlsBackground[] = {};
	objects[] = {};

	class controls
	{

		class IGUIBack_2200: DMadm_IGUIBack
		{
			idc = 2200;
			x = 0.298438 * safezoneW + safezoneX;
			y = 0.216889 * safezoneH + safezoneY;
			w = 0.402187 * safezoneW;
			h = 0.33 * safezoneH;
		};
		class RscFrame_1800: DMadm_RscFrame
		{
			idc = 1800;
			x = 0.304062 * safezoneW + safezoneX;
			y = 0.291 * safezoneH + safezoneY;
			w = 0.391875 * safezoneW;
			h = 0.253 * safezoneH;
			colorText[] = {0,0,1,1};
		};
		class RscButton_1600: DMadm_RscButton
		{
			idc = 1600;
			text = "Gear Select"; //--- ToDo: Localize;
			x = 0.319531 * safezoneW + safezoneX;
			y = 0.478 * safezoneH + safezoneY;
			w = 0.0670312 * safezoneW;
			h = 0.055 * safezoneH;
			colorText[] = {1,0,1,1};
			tooltip = "Admin Virtual Arsenal(US ONLY!!!!)";
			action = "closeDialog 0;[] call dp_StartArsenal";
		};
		class RscButton_1601: DMadm_RscButton
		{
			idc = 1601;
			text = "Possum"; //--- ToDo: Localize;
			x = 0.319531 * safezoneW + safezoneX;
			y = 0.302 * safezoneH + safezoneY;
			w = 0.0670312 * safezoneW;
			h = 0.055 * safezoneH;
			colorText[] = {0,1,0,1.5};
			tooltip = "Enjoy the FUN!"; //--- ToDo: Localize;
			action = "closeDialog 0;[] call dp_Possum_Play";
		};
		class RscButton_1602: DMadm_RscButton
		{
			idc = 1602;
			text = "Kits/Events"; //--- ToDo: Localize;
			x = 0.412344 * safezoneW + safezoneX;
			y = 0.478 * safezoneH + safezoneY;
			w = 0.0670312 * safezoneW;
			h = 0.055 * safezoneH;
			colorText[] = {0,1,1,1};
			tooltip = "Spawn in Kits/Events"; //--- ToDo: Localize;
			action = "closeDialog 0";
		};
		class RscButton_1603: DMadm_RscButton
		{
			idc = 1603;
			text = "Crafting"; //--- ToDo: Localize;
			x = 0.412344 * safezoneW + safezoneX;
			y = 0.302 * safezoneH + safezoneY;
			w = 0.0670312 * safezoneW;
			h = 0.055 * safezoneH;
			colorText[] = {1,1,0,1};
			tooltip = "Crafting Menu";
			action = "closeDialog 0;[] call dpOpen_Crafting";
		};
		class RscButton_1604: DMadm_RscButton
		{
			idc = 1604;
			text = "Temp Groups"; //--- ToDo: Localize;
			x = 0.463906 * safezoneW + safezoneX;
			y = 0.39 * safezoneH + safezoneY;
			w = 0.0670312 * safezoneW;
			h = 0.055 * safezoneH;
			colorText[] = {0.1,1,0.1,1};
			tooltip = "Temporary Groups have NO effect on EPOCH GROUPS!";
			action = "closeDialog 0;[] call dpOpen_TempGroups";
		};
		class RscButton_1605: DMadm_RscButton
		{
			idc = 1605;
			text = "Earplugs"; //--- ToDo: Localize;
			x = 0.510312 * safezoneW + safezoneX;
			y = 0.302 * safezoneH + safezoneY;
			w = 0.0670312 * safezoneW;
			h = 0.055 * safezoneH;
			colorText[] = {0,0.3,1,1.5};
			tooltip = "Silence all the NOISE";
			action = "closeDialog 0;[] call cm_Earplugs_FUNc";
		};
		class RscButton_1606: DMadm_RscButton
		{
			idc = 1606;
			text = "Suicide"; //--- ToDo: Localize;
			x = 0.608281 * safezoneW + safezoneX;
			y = 0.302 * safezoneH + safezoneY;
			w = 0.0670312 * safezoneW;
			h = 0.055 * safezoneH;
			colorText[] = {1,0,0,1.5};
			tooltip = "Kill Yourself";
			action = "closeDialog 0;[] call dp_suicide";
		};
		class RscButton_1607: DMadm_RscButton
		{
			idc = 1607;
			text = "Surrender"; //--- ToDo: Localize;
			x = 0.561875 * safezoneW + safezoneX;
			y = 0.39 * safezoneH + safezoneY;
			w = 0.0670312 * safezoneW;
			h = 0.055 * safezoneH;
			colorText[] = {1,0,1,1.5};
			tooltip = "Drop all your weapons and Give UP";
			action = "closeDialog 0;[player] execVM 'scripts\donkeymenu\surrender.sqf'";
		};
		class RscText_1000: DMadm_RscText
		{
			idc = 1000;
			text = "Donkey Menu Admin Panel"; //--- ToDo: Localize;
			x = 0.329844 * safezoneW + safezoneX;
			y = 0.236 * safezoneH + safezoneY;
			w = 0.335156 * safezoneW;
			h = 0.044 * safezoneH;
			colorText[] = {0,0,1,1.5};
			colorBackground[] = {.1,.1,.1,.3};
		};
		class RscButton_1608: DMadm_RscButton
		{
			idc = 1608;
			text = "Banking"; //--- ToDo: Localize;
			x = 0.520625 * safezoneW + safezoneX;
			y = 0.478 * safezoneH + safezoneY;
			w = 0.0670312 * safezoneW;
			h = 0.055 * safezoneH;
			colorText[] = {1,0.5,0.5,1};
			tooltip = "Fast Banking!WIP Testing";
			action = "closeDialog 0;[player] execVM 'scripts\donkeymenu\bankaction.sqf'";
		};
		class RscButton_1609: DMadm_RscButton
		{
			idc = 1609;
			text = "Admin Hunt"; //--- ToDo: Localize;
			x = 0.608281 * safezoneW + safezoneX;
			y = 0.478 * safezoneH + safezoneY;
			w = 0.0670312 * safezoneW;
			h = 0.055 * safezoneH;
			colorText[] = {1,1,0,1};
			tooltip = "Admin Hunt! PvP Player Initiated Mission";
			action = "closeDialog 0;[] call dp_AdminHunt";
		};
		class RscButton_1610: DMadm_RscButton
		{
			idc = 1610;
			text = "Donator"; //--- ToDo: Localize;
			x = 0.365937 * safezoneW + safezoneX;
			y = 0.39 * safezoneH + safezoneY;
			w = 0.0670312 * safezoneW;
			h = 0.055 * safezoneH;
			colorText[] = {1,0,0,1};
			tooltip = "Donator Exclusive Menu";
			action = "closeDialog 0;[] call dpOpen_Donator";
		};
		class RscPicture: DDM_RscPicture
        {
			idc = -1;
			text = "scripts\donkeypunch.paa";
			x = 0.04625 * safezoneW + safezoneX;
			y = 0.412 * safezoneH + safezoneY;
			w = 0.195937 * safezoneW;
			h = 0.209 * safezoneH;
        };
	};
};