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

class DMreg_IGUIBack
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
	colorbackground[] = {-1,-1,-1,-1};
};

class DMreg_RscFrame
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


class DMreg_RscButton
{
	access = 0;
	type = 1;
	text = "";
	colorText[] = {0.969,0,0,1};
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
	x = 0;
	y = 0;
	w = 0.095589;
	h = 0.039216;
		class Attributes
		{
		font = "PuristaMedium";
		color = "#ffffff";
		align = "center";
		shadow = 1;
		};
	shadow = 1;
	font = "PuristaMedium";
	sizeEx = "(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)";
	offsetX = 0.003;
	offsetY = 0.003;
	offsetPressedX = 0.002;
	offsetPressedY = 0.002;
	borderSize = 0;
};

class DMreg_RscText
{
	 access = 0;
	 type = CT_STATIC;
	 idc = -1;
	 style = 2;
	 w = 0.1; h = 0.05;
	 //x and y are not part of a global class since each rsctext will be positioned 'somewhere'
	 font = "PuristaMedium";
	 text = "";
	 sizeEx = 0.04;
	 fixedWidth = 0;
	 shadow = 0;
};

class DMreg_RscPicture
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


 class donkey_menu_gui
{
	idd = 8081;
	movingEnable = true;
	enableSimulation = false;
	controlsBackground[] = {};
	objects[] = {};

	class controls
	{
		class IGUIBack_2200: DMreg_IGUIBack
		{
			idc = 2200;
			x = 0.298438 * safezoneW + safezoneX;
			y = 0.216889 * safezoneH + safezoneY;
			w = 0.402187 * safezoneW;
			h = 0.253 * safezoneH;
		};
		class RscFrame_1800: DMreg_RscFrame
		{
			idc = 1800;
			x = 0.304062 * safezoneW + safezoneX;
			y = 0.291 * safezoneH + safezoneY;
			w = 0.391875 * safezoneW;
			h = 0.165 * safezoneH;
			colorText[] = {0,0,1,1};
		};
		class RscButton_1601: DMreg_RscButton
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
		class RscButton_1603: DMreg_RscButton
		{
			idc = 1603;
			text = "Crafting"; //--- ToDo: Localize;
			x = 0.4175 * safezoneW + safezoneX;
			y = 0.302 * safezoneH + safezoneY;
			w = 0.0670312 * safezoneW;
			h = 0.055 * safezoneH;
			colorText[] = {1,1,0,1};
			tooltip = "Crafting Menu";
			action = "closeDialog 0;[] call dpOpen_Crafting";
		};
		class RscButton_1604: DMreg_RscButton
		{
			idc = 1604;
			text = "Temp Groups"; //--- ToDo: Localize;
			x = 0.4175 * safezoneW + safezoneX;
			y = 0.39 * safezoneH + safezoneY;
			w = 0.0670312 * safezoneW;
			h = 0.055 * safezoneH;
			colorText[] = {0.1,1,0.1,1};
			tooltip = "Temporary Groups have NO effect on EPOCH GROUPS!";
			action = "closeDialog 0;[] call dpOpen_TempGroups";
		};
		class RscButton_1605: DMreg_RscButton
		{
			idc = 1605;
			text = "Earplugs"; //--- ToDo: Localize;
			x = 0.515469 * safezoneW + safezoneX;
			y = 0.302 * safezoneH + safezoneY;
			w = 0.0670312 * safezoneW;
			h = 0.055 * safezoneH;
			colorText[] = {0,0.3,1,1.5};
			tooltip = "Silence all the NOISE";
			action = "closeDialog 0;[] call cm_Earplugs_FUNc";
		};
		class RscButton_1606: DMreg_RscButton
		{
			idc = 1606;
			text = "Suicide"; //--- ToDo: Localize;
			x = 0.613437 * safezoneW + safezoneX;
			y = 0.302 * safezoneH + safezoneY;
			w = 0.0670312 * safezoneW;
			h = 0.055 * safezoneH;
			colorText[] = {1,0,0,1.5};
			tooltip = "Kill Yourself";
			action = "closeDialog 0;[] call dp_suicide";
		};
		class RscButton_1607: DMreg_RscButton
		{
			idc = 1607;
			text = "Surrender"; //--- ToDo: Localize;
			x = 0.515469 * safezoneW + safezoneX;
			y = 0.39 * safezoneH + safezoneY;
			w = 0.0670312 * safezoneW;
			h = 0.055 * safezoneH;
			colorText[] = {1,0,1,1.5};
			tooltip = "Drop all your weapons and Give UP";
			action = "closeDialog 0;[player] execVM 'scripts\donkeymenu\surrender.sqf'";
		};
		class RscText_1000: DMreg_RscText
		{
			idc = 1000;
			text = "DONKEY MENU v.2 by =RAV=MusTanG"; //--- ToDo: Localize;
			x = 0.329844 * safezoneW + safezoneX;
			y = 0.236 * safezoneH + safezoneY;
			w = 0.335156 * safezoneW;
			h = 0.044 * safezoneH;
			colorText[] = {0,0,1,1};
			colorBackground[] = {.1,.1,.1,.3};
		};
		class DMreg_RscButton_1609: DMreg_RscButton
		{
			idc = -1;
			text = "Status Bar"; //--- ToDo: Localize;
			x = 0.613437 * safezoneW + safezoneX;
			y = 0.39 * safezoneH + safezoneY;
			w = 0.0670312 * safezoneW;
			h = 0.055 * safezoneH;
			colorText[] = {1,1,0,1};
		};
		class RscButton_1610: DMreg_RscButton
		{
			idc = 1610;
			text = "WIP"; //--- ToDo: Localize;
			x = 0.319531 * safezoneW + safezoneX;
			y = 0.39 * safezoneH + safezoneY;
			w = 0.0670312 * safezoneW;
			h = 0.055 * safezoneH;
			colorText[] = {1,0,0,1};
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