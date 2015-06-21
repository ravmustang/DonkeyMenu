/*
	ArmA 3 Epoch Donkey Punch
	by =RAV=MusTanG
	Menu GUI v0.1
*/
// Control types
#define CT_MAP_MAIN 101
#define CT_TREE 12
#define CT_STRUCTURED_TEXT 13
// Static styles
#define ST_PICTURE 0x30
#define ST_MULTI 16
// Listbox styles
#define ST_LEFT 0x00
#define LB_TEXTURES 0x10

// Base Classes

class DDM_IGUIBack
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
	colorbackground[] = {.1,.1,.1,.6};
};

class DDM_RscFrame1
{
	type = 0;
	idc = -1;
	style = 64;
	shadow = 2;
	colorBackground[] = {0.969,0,0,1};
	colorText[] = {0.969,0,0,1};
	font = "PuristaLight";
	sizeEx = 1;
	text = "";
};

class DDM_RscFrame2
{
	type = 0;
	idc = -1;
	style = 64;
	shadow = 2;
	colorBackground[] = {0,.5,1,.8};
	colorText[] = {0,.5,1,.8};
	font = "PuristaLight";
	sizeEx = 0.02;
	text = "";
};


class DDM_RscButton
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
	shadow = 1;
	font = "PuristaMedium";
	sizeEx = "(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1)";
	offsetX = 0.003;
	offsetY = 0.003;
	offsetPressedX = 0.002;
	offsetPressedY = 0.002;
	borderSize = 0;
};

class DDM_RscText
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
};

class DDM_RscStructuredText
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
class DDM_RscPicture
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


class donator_menu_dialog {
	idd = 8080;
	movingEnable = true;
	enableSimulation = false;
	controlsBackground[] = {};
	objects[] = {};
	class controls 
	{
		class IGUIBack_2200: DDM_IGUIBack
		{
			idc = 2200;
			x = 0.432969 * safezoneW + safezoneX;
			y = -0.127 * safezoneH + safezoneY;
			w = 0 * safezoneW;
			h = 0 * safezoneH;
		};
		
		class RscFrame_1800: DDM_RscFrame1
		{
			idc = 1800;
			x = 0.314375 * safezoneW + safezoneX;
			y = 0.346 * safezoneH + safezoneY;
			w = 0.360937 * safezoneW;
			h = 0.352 * safezoneH;
			colorText[] = {0.969,0,0,1};
			colorBackground[] = {0.969,0,0,1};
		};
		class RscFrame_1801: DDM_RscFrame2
		{
			idc = 1801;
			x = 0.324687 * safezoneW + safezoneX;
			y = 0.269 * safezoneH + safezoneY;
			w = 0.345469 * safezoneW;
			h = 0.044 * safezoneH;
			colorText[] = {0,0.5,1,0.8};
			colorBackground[] = {0,0.5,1,0.8};
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
		class RscText_1000: DDM_RscText
		{
			idc = 1000;
			text = "DonkeyPunch.INFO Exclusive Donator Menu";
			x = 0.324687 * safezoneW + safezoneX;
			y = 0.269 * safezoneH + safezoneY;
			w = 0.345469 * safezoneW;
			h = 0.044 * safezoneH;
			colorText[] = {0,0,1,1};
			colorBackground[] = {0.8,0.8,0.8,0.35};
			sizeEx = 0.05;
		};
		class RscText_1001: DDM_RscText
		{
			idc = 1001;
			text = "RavA3Epoch.TS3.NfoServers.COM";
			x = 0.422656 * safezoneW + safezoneX;
			y = 0.709 * safezoneH + safezoneY;
			w = 0.144375 * safezoneW;
			h = 0.022 * safezoneH;
			colorText[] = {0,0,1,1};
			colorBackground[] = {0.8,0.8,0.8,0.35};
			sizeEx = 0.03;
		};
		class RscText_1002: DDM_RscText
		{
			idc = 1002;
			text = "#(argb,8,8,3)color(1,1,1,1)";
			x = 0.432969 * safezoneW + safezoneX;
			y = -0.127 * safezoneH + safezoneY;
			w = 0 * safezoneW;
			h = 0 * safezoneH;
			colorText[] = {0,0,1,1};
			shadow = 2;
			colorBackground[] = { 0, 0, 0, 0.5 };  // uncomment and increase 4th number to have a background
			font = "PuristaSemibold";
			size = 0.04;
			type = 13;
			class Attributes {
				align="left";
				color = "#ffffff";//#5fe60c
			};

		};
		class RscButton_1600: DDM_RscButton
		{
			idc = 1600;
			text = "Razor Wire";
			x = 0.329844 * safezoneW + safezoneX;
			y = 0.368 * safezoneH + safezoneY;
			w = 0.0773437 * safezoneW;
			h = 0.044 * safezoneH;
			colorText[] = {0.969,0,0,1};
			colorBackground[] = {0.7,0.7,0.7,0.6};
			colorActive[] = {0.3,0.3,0.3,0.6};
			tooltip = "Razor Wire Only Lasts for 1 Restart";
			action = "closeDialog 0;[] execVM 'scripts\donkeymenu\donator\Land_Razorwire_F.sqf'";
		};
		class RscButton_1601: DDM_RscButton
		{
			idc = 1601;
			text = "H-Barrier Corner";
			x = 0.329844 * safezoneW + safezoneX;
			y = 0.434 * safezoneH + safezoneY;
			w = 0.0773437 * safezoneW;
			h = 0.044 * safezoneH;
			colorText[] = {0.969,0,0,1};
			colorBackground[] = {0.7,0.7,0.7,0.6};
			colorActive[] = {0.3,0.3,0.3,0.6};
			tooltip = "H-Barrier Corners Only Last for 1 Restart";
			action = "closeDialog 0;[] execVM 'scripts\donkeymenu\donator\Land_HBarrierWall_corner_F.sqf'";
		};
		class RscButton_1602: DDM_RscButton
		{
			idc = 1602;
			text = "H-Barrier BIG";
			x = 0.329844 * safezoneW + safezoneX;
			y = 0.5 * safezoneH + safezoneY;
			w = 0.0773437 * safezoneW;
			h = 0.044 * safezoneH;
			colorText[] = {0.969,0,0,1};
			colorBackground[] = {0.7,0.7,0.7,0.6};
			colorActive[] = {0.3,0.3,0.3,0.6};
			tooltip = "H-Barrier BIG Only Lasts for 1 Restart";
			action = "closeDialog 0;[] execVM 'scripts\donkeymenu\donator\Land_HBarrier_Big_F.sqf'";
		};
		class RscButton_1603: DDM_RscButton
		{
			idc = 1603;
			text = "H-Barrier Nest";
			x = 0.329844 * safezoneW + safezoneX;
			y = 0.566 * safezoneH + safezoneY;
			w = 0.0773437 * safezoneW;
			h = 0.044 * safezoneH;
			colorText[] = {0.969,0,0,1};
			colorBackground[] = {0.7,0.7,0.7,0.6};
			colorActive[] = {0.3,0.3,0.3,0.6};
			tooltip = "H-Barrier Nest Only Last for 1 Restart";
			action = "closeDialog 0;[] execVM 'scripts\donkeymenu\donator\Land_HBarrierTower_F.sqf'";
		};
		class RscButton_1604: DDM_RscButton
		{
			idc = 1604;
			text = "Military Wall";
			x = 0.329844 * safezoneW + safezoneX;
			y = 0.632 * safezoneH + safezoneY;
			w = 0.0773437 * safezoneW;
			h = 0.044 * safezoneH;
			colorText[] = {0.969,0,0,1};
			colorBackground[] = {0.7,0.7,0.7,0.6};
			colorActive[] = {0.3,0.3,0.3,0.6};
			tooltip = "Military Walls Only Last for 1 Restart";
			action = "closeDialog 0;[] execVM 'scripts\donkeymenu\donator\Land_Mil_WallBig_4m_F.sqf'";
		};
		class RscButton_1605: DDM_RscButton
		{
			idc = 1605;
			text = "Zombie Target";
			x = 0.453594 * safezoneW + safezoneX;
			y = 0.368 * safezoneH + safezoneY;
			w = 0.0773437 * safezoneW;
			h = 0.044 * safezoneH;
			colorText[] = {0.969,0,0,1};
			colorBackground[] = {0.7,0.7,0.7,0.6};
			colorActive[] = {0.3,0.3,0.3,0.6};
			tooltip = "Targets Only Last for 1 Restart";
			action = "closeDialog 0;[] execVM 'scripts\donkeymenu\donator\TargetP_Zom_F.sqf'";
		};
		class RscButton_1606: DDM_RscButton
		{
			idc = 1606;
			text = "Civilian Target";
			x = 0.453594 * safezoneW + safezoneX;
			y = 0.434 * safezoneH + safezoneY;
			w = 0.0773437 * safezoneW;
			h = 0.044 * safezoneH;
			colorText[] = {0.969,0,0,1};
			colorBackground[] = {0.7,0.7,0.7,0.6};
			colorActive[] = {0.3,0.3,0.3,0.6};
			tooltip = "Targets Only Last for 1 Restart";
			action = "closeDialog 0;[] execVM 'scripts\donkeymenu\donator\TargetP_Civ_F.sqf'";
		};
		class RscButton_1607: DDM_RscButton
		{
			idc = 1607;
			text = "Bandit Target";
			x = 0.453594 * safezoneW + safezoneX;
			y = 0.5 * safezoneH + safezoneY;
			w = 0.0773437 * safezoneW;
			h = 0.044 * safezoneH;
			colorText[] = {0.969,0,0,1};
			colorBackground[] = {0.7,0.7,0.7,0.6};
			colorActive[] = {0.3,0.3,0.3,1};
			tooltip = "Targets Only Last for 1 Restart";
			action = "closeDialog 0;[] execVM 'scripts\donkeymenu\donator\TargetP_Inf3_F.sqf'";
		};
		class RscButton_1608: DDM_RscButton
		{
			idc = 1608;
			text = "Patrol Tower";
			x = 0.453594 * safezoneW + safezoneX;
			y = 0.566 * safezoneH + safezoneY;
			w = 0.0773437 * safezoneW;
			h = 0.044 * safezoneH;
			colorText[] = {0.969,0,0,1};
			colorBackground[] = {0.7,0.7,0.7,0.6};
			colorActive[] = {0.3,0.3,0.3,0.6};
			tooltip = "Patrol Towers Only Last for 1 Restart";
			action = "closeDialog 0;[] execVM 'scripts\donkeymenu\donator\Land_Cargo_Patrol_V1_F.sqf'";
		};
		class RscButton_1609: DDM_RscButton
		{
			idc = 1609;
			text = "Generator";
			x = 0.453594 * safezoneW + safezoneX;
			y = 0.632 * safezoneH + safezoneY;
			w = 0.0773437 * safezoneW;
			h = 0.044 * safezoneH;
			colorText[] = {0.969,0,0,1};
			colorBackground[] = {0.7,0.7,0.7,0.6};
			colorActive[] = {0.3,0.3,0.3,0.2};
			action = "closeDialog 0;[] execVM 'scripts\donkeymenu\donator\Land_Portable_generator_F.sqf'";
		};
		class RscButton_1610: DDM_RscButton
		{
			idc = 1610;
			text = "Fire Barrel";
			x = 0.577344 * safezoneW + safezoneX;
			y = 0.368 * safezoneH + safezoneY;
			w = 0.0773437 * safezoneW;
			h = 0.044 * safezoneH;
			colorText[] = {0.969,0,0,1};
			colorBackground[] = {0.7,0.7,0.7,0.6};
			colorActive[] = {0.3,0.3,0.3,0.6};
			tooltip = "Fire Barrels Only Last for 1 Restart";
			action = "closeDialog 0;[] execVM 'scripts\donkeymenu\donator\MetalBarrel_burning_F.sqf'";
		};
		class RscButton_1611: DDM_RscButton
		{
			idc = 1611;
			text = "Water Barrel";
			x = 0.577344 * safezoneW + safezoneX;
			y = 0.434 * safezoneH + safezoneY;
			w = 0.0773437 * safezoneW;
			h = 0.044 * safezoneH;
			colorText[] = {0.969,0,0,1};
			colorBackground[] = {0.7,0.7,0.7,0.6};
			colorActive[] = {0.3,0.3,0.3,0.6};
			tooltip = "Water Barrels Only Last for 1 Restart";
			action = "closeDialog 0;[] execVM 'scripts\donkeymenu\donator\Land_BarrelWater_F.sqf'";
		};
		class RscButton_1612: DDM_RscButton
		{
			idc = 1612;
			text = "Yellow Sphere";
			x = 0.577344 * safezoneW + safezoneX;
			y = 0.5 * safezoneH + safezoneY;
			w = 0.0773437 * safezoneW;
			h = 0.044 * safezoneH;
			colorText[] = {0.969,0,0,1};
			colorBackground[] = {0.7,0.7,0.7,0.6};
			colorActive[] = {0.3,0.3,0.3,0.6};
			tooltip = "Spheres Only Last for 1 Restart";
			action = "closeDialog 0;[] execVM 'scripts\donkeymenu\donator\Sign_Sphere200cm_F.sqf'";
		};
		class RscButton_1613: DDM_RscButton
		{
			idc = 1613;
			text = "Fuel Pump";
			x = 0.577344 * safezoneW + safezoneX;
			y = 0.566 * safezoneH + safezoneY;
			w = 0.0773437 * safezoneW;
			h = 0.044 * safezoneH;
			colorText[] = {0.969,0,0,1};
			colorBackground[] = {0.7,0.7,0.7,0.6};
			colorActive[] = {0.3,0.3,0.3,0.6};
			tooltip = "Fuel Pumps Only Last for 1 Restart";
			action = "closeDialog 0;[] execVM 'scripts\donkeymenu\donator\Land_fs_feed_F.sqf'";
		};
		class RscButton_1614: DDM_RscButton
		{
			idc = 1614;
			text = "Lights LG";
			x = 0.577344 * safezoneW + safezoneX;
			y = 0.632 * safezoneH + safezoneY;
			w = 0.0773437 * safezoneW;
			h = 0.044 * safezoneH;
			colorText[] = {0.969,0,0,1};
			colorBackground[] = {0.7,0.7,0.7,0.6};
			colorActive[] = {0.3,0.3,0.3,0.6};
			tooltip = "Halogen Lights Only Last for 1 Restart";
			action = "closeDialog 0;[] execVM 'scripts\donkeymenu\donator\lettherebelight.sqf'";
		};
	};
};