/*
	Donkey Menu GUI v1
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

class DCM_IGUIBack
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

class DCM_RscFrame1
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

class DCM_RscFrame2
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

class DCM_RscButton
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

class DCM_RscText
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

class DCM_RscStructuredText
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
class DCM_RscPicture
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


class Crafting_Menu_dialog {
	idd = 8081;
	movingEnable = true;
	enableSimulation = false;
	controlsBackground[] = {};
	objects[] = {};
	class controls 
	{
		class IGUIBack_2210: DCM_IGUIBack
		{
			idc = 2210;
			x = 0.432969 * safezoneW + safezoneX;
			y = -0.127 * safezoneH + safezoneY;
			w = 0 * safezoneW;
			h = 0 * safezoneH;
		};
		
		class RscFrame_1810: DCM_RscFrame1
		{
			idc = 1810;
			x = 0.314375 * safezoneW + safezoneX;
			y = 0.346 * safezoneH + safezoneY;
			w = 0.360937 * safezoneW;
			h = 0.352 * safezoneH;
			colorText[] = {1,1,0,1};
			colorBackground[] = {1,1,0,1};
		};
		class RscFrame_1811: DCM_RscFrame2
		{
			idc = 1811;
			x = 0.324687 * safezoneW + safezoneX;
			y = 0.269 * safezoneH + safezoneY;
			w = 0.345469 * safezoneW;
			h = 0.044 * safezoneH;
			colorText[] = {0,0.5,1,0.8};
			colorBackground[] = {0,0.5,1,0.8};
		};
		 class RscPicture: DCM_RscPicture
        {
			idc = -1;
			text = "donkeymenu\donkeypunch.paa";
			x = 0.04625 * safezoneW + safezoneX;
			y = 0.412 * safezoneH + safezoneY;
			w = 0.195937 * safezoneW;
			h = 0.209 * safezoneH;
        };
		class RscText_1010: DCM_RscText
		{
			idc = 1010;
			text = "DonkeyPunch.INFO Crafting Menu";
			x = 0.324687 * safezoneW + safezoneX;
			y = 0.269 * safezoneH + safezoneY;
			w = 0.345469 * safezoneW;
			h = 0.044 * safezoneH;
			colorText[] = {1,1,0,1};
			colorBackground[] = {0.8,0.8,0.8,0.35};
			sizeEx = 0.06;
		};
		class RscText_1011: DCM_RscText
		{
			idc = 1011;
			text = "RavA3Epoch.TS3.NfoServers.COM";
			x = 0.422656 * safezoneW + safezoneX;
			y = 0.709 * safezoneH + safezoneY;
			w = 0.144375 * safezoneW;
			h = 0.022 * safezoneH;
			colorText[] = {1,1,0,1};
			colorBackground[] = {0.8,0.8,0.8,0.35};
			sizeEx = 0.03;
		};
		class RscText_1012: DCM_RscText
		{
			idc = 1012;
			text = "#(argb,8,8,3)color(1,1,1,1)";
			x = 0.432969 * safezoneW + safezoneX;
			y = -0.127 * safezoneH + safezoneY;
			w = 0 * safezoneW;
			h = 0 * safezoneH;
			colorText[] = {1,1,0,1};
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
		class RscButton_1620: DCM_RscButton
		{
			idc = 1620;
			text = "Mosquito";
			x = 0.329844 * safezoneW + safezoneX;
			y = 0.368 * safezoneH + safezoneY;
			w = 0.0773437 * safezoneW;
			h = 0.044 * safezoneH;
			colorText[] = {1,1,0,1};
			colorBackground[] = {0.7,0.7,0.7,0.6};
			colorActive[] = {0.3,0.3,0.3,0.6};
			tooltip = "Mosquito's Only Lasts for 1 Restart cost: 300 Crypto";
			action = "closeDialog 0;[] execVM 'donkeymenu\crafting\Mosquito.sqf'";
		};
		class RscButton_1621: DCM_RscButton
		{
			idc = 1621;
			text = "QuadBike";
			x = 0.329844 * safezoneW + safezoneX;
			y = 0.434 * safezoneH + safezoneY;
			w = 0.0773437 * safezoneW;
			h = 0.044 * safezoneH;
			colorText[] = {1,1,0,1};
			colorBackground[] = {0.7,0.7,0.7,0.6};
			colorActive[] = {0.3,0.3,0.3,0.6};
			tooltip = "QuadBike's Only Last for 1 Restart cost: 200 Crypto";
			action = "closeDialog 0;[] execVM 'donkeymenu\crafting\quadbike.sqf'";
		};
		class RscButton_1622: DCM_RscButton
		{
			idc = 1622;
			text = "BluKing";
			x = 0.329844 * safezoneW + safezoneX;
			y = 0.5 * safezoneH + safezoneY;
			w = 0.0773437 * safezoneW;
			h = 0.044 * safezoneH;
			colorText[] = {1,1,0,1};
			colorBackground[] = {0.7,0.7,0.7,0.6};
			colorActive[] = {0.3,0.3,0.3,0.6};
			tooltip = "Go-Karts Only Last for 1 Restart cost: 500 Crypto";
			action = "closeDialog 0;[] execVM 'donkeymenu\crafting\kartbluking.sqf'";
		};
		class RscButton_1623: DCM_RscButton
		{
			idc = 1623;
			text = "H-Barrier Block";
			x = 0.329844 * safezoneW + safezoneX;
			y = 0.566 * safezoneH + safezoneY;
			w = 0.0773437 * safezoneW;
			h = 0.044 * safezoneH;
			colorText[] = {1,1,0,1};
			colorBackground[] = {0.7,0.7,0.7,0.6};
			colorActive[] = {0.3,0.3,0.3,0.6};
			tooltip = "H-Barrier Blocks Only Last for 1 Restart cost: 1500 Energy";
			action = "closeDialog 0;[] execVM 'donkeymenu\crafting\Land_HBarrier_Big_F.sqf'";
		};
		class RscButton_1624: DCM_RscButton
		{
			idc = 1624;
			text = "Military Wall";
			x = 0.329844 * safezoneW + safezoneX;
			y = 0.632 * safezoneH + safezoneY;
			w = 0.0773437 * safezoneW;
			h = 0.044 * safezoneH;
			colorText[] = {1,1,0,1};
			colorBackground[] = {0.7,0.7,0.7,0.6};
			colorActive[] = {0.3,0.3,0.3,0.6};
			tooltip = "Military Walls Only Last for 1 Restart cost: 1000 Energy";
			action = "closeDialog 0;[] execVM 'donkeymenu\crafting\Land_Mil_WallBig_4m_F.sqf'";
		};
		class RscButton_1625: DCM_RscButton
		{
			idc = 1625;
			text = "Zombie Target";
			x = 0.453594 * safezoneW + safezoneX;
			y = 0.368 * safezoneH + safezoneY;
			w = 0.0773437 * safezoneW;
			h = 0.044 * safezoneH;
			colorText[] = {1,1,0,1};
			colorBackground[] = {0.7,0.7,0.7,0.6};
			colorActive[] = {0.3,0.3,0.3,0.6};
			tooltip = "Targets Only Last for 1 Restart cost: 250 Energy";
			action = "closeDialog 0;[] execVM 'donkeymenu\donator\TargetP_Zom_F.sqf'";
		};
		class RscButton_1626: DCM_RscButton
		{
			idc = 1626;
			text = "Civilian Target";
			x = 0.453594 * safezoneW + safezoneX;
			y = 0.434 * safezoneH + safezoneY;
			w = 0.0773437 * safezoneW;
			h = 0.044 * safezoneH;
			colorText[] = {1,1,0,1};
			colorBackground[] = {0.7,0.7,0.7,0.6};
			colorActive[] = {0.3,0.3,0.3,0.6};
			tooltip = "Targets Only Last for 1 Restart cost: 250 Energy";
			action = "closeDialog 0;[] execVM 'donkeymenu\donator\TargetP_Civ_F.sqf'";
		};
		class RscButton_1627: DCM_RscButton
		{
			idc = 1627;
			text = "Bandit Target";
			x = 0.453594 * safezoneW + safezoneX;
			y = 0.5 * safezoneH + safezoneY;
			w = 0.0773437 * safezoneW;
			h = 0.044 * safezoneH;
			colorText[] = {1,1,0,1};
			colorBackground[] = {0.7,0.7,0.7,0.6};
			colorActive[] = {0.3,0.3,0.3,1};
			tooltip = "Targets Only Last for 1 Restart cost: 250 Energy";
			action = "closeDialog 0;[] execVM 'donkeymenu\donator\TargetP_Inf3_F.sqf'";
		};
		class RscButton_1628: DCM_RscButton
		{
			idc = 1628;
			text = "Ghilliesuit";
			x = 0.453594 * safezoneW + safezoneX;
			y = 0.566 * safezoneH + safezoneY;
			w = 0.0773437 * safezoneW;
			h = 0.044 * safezoneH;
			colorText[] = {1,1,0,1};
			colorBackground[] = {0.7,0.7,0.7,0.6};
			colorActive[] = {0.3,0.3,0.3,0.6};
			tooltip = "Supply Crates Only Last for 1 Restart - Craftable";
			action = "closeDialog 0;[] execVM 'donkeymenu\crafting\ghilliesuit.sqf'";
		};
		class RscButton_1629: DCM_RscButton
		{
			idc = 1629;
			text = "Supply Crate";
			x = 0.453594 * safezoneW + safezoneX;
			y = 0.632 * safezoneH + safezoneY;
			w = 0.0773437 * safezoneW;
			h = 0.044 * safezoneH;
			colorText[] = {1,1,0,1};
			colorBackground[] = {0.7,0.7,0.7,0.6};
			colorActive[] = {0.3,0.3,0.3,0.2};
			tooltip = "Supply Crates Only Last for 1 Restart - Craftable";
			action = "closeDialog 0;[] execVM 'donkeymenu\crafting\crate.sqf'";
		};
		class RscButton_1630: DCM_RscButton
		{
			idc = 1630;
			text = "Fire Barrel";
			x = 0.577344 * safezoneW + safezoneX;
			y = 0.368 * safezoneH + safezoneY;
			w = 0.0773437 * safezoneW;
			h = 0.044 * safezoneH;
			colorText[] = {1,1,0,1};
			colorBackground[] = {0.7,0.7,0.7,0.6};
			colorActive[] = {0.3,0.3,0.3,0.6};
			tooltip = "Fire Barrels Only Last for 1 Restart cost: 750 Energy";
			action = "closeDialog 0;[] execVM 'donkeymenu\crafting\MetalBarrel_burning_F.sqf'";
		};
		class RscButton_1631: DCM_RscButton
		{
			idc = 1631;
			text = "Water Barrel";
			x = 0.577344 * safezoneW + safezoneX;
			y = 0.434 * safezoneH + safezoneY;
			w = 0.0773437 * safezoneW;
			h = 0.044 * safezoneH;
			colorText[] = {1,1,0,1};
			colorBackground[] = {0.7,0.7,0.7,0.6};
			colorActive[] = {0.3,0.3,0.3,0.6};
			tooltip = "Water Barrels Only Last for 1 Restart";
			action = "closeDialog 0;[] execVM 'donkeymenu\donator\Land_BarrelWater_F.sqf'";
		};
		class RscButton_1632: DCM_RscButton
		{
			idc = 1632;
			text = "Camo Net";
			x = 0.577344 * safezoneW + safezoneX;
			y = 0.5 * safezoneH + safezoneY;
			w = 0.0773437 * safezoneW;
			h = 0.044 * safezoneH;
			colorText[] = {1,1,0,1};
			colorBackground[] = {0.7,0.7,0.7,0.6};
			colorActive[] = {0.3,0.3,0.3,0.6};
			tooltip = "Camo Nets Only Last for 1 Restart cost: 1250 Energy";
			action = "closeDialog 0;[] execVM 'donkeymenu\crafting\CamoNet_INDP_big_F.sqf'";
		};
		class RscButton_1633: DCM_RscButton
		{
			idc = 1633;
			text = "Razor Wire";
			x = 0.577344 * safezoneW + safezoneX;
			y = 0.566 * safezoneH + safezoneY;
			w = 0.0773437 * safezoneW;
			h = 0.044 * safezoneH;
			colorText[] = {1,1,0,1};
			colorBackground[] = {0.7,0.7,0.7,0.6};
			colorActive[] = {0.3,0.3,0.3,0.6};
			tooltip = "Razor Wire Only Last for 1 Restart cost: 400 Energy";
			action = "closeDialog 0;[] execVM 'donkeymenu\donator\Land_Razorwire_F.sqf'";
		};
		class RscButton_1634: DCM_RscButton
		{
			idc = 1634;
			text = "Lights";
			x = 0.577344 * safezoneW + safezoneX;
			y = 0.632 * safezoneH + safezoneY;
			w = 0.0773437 * safezoneW;
			h = 0.044 * safezoneH;
			colorText[] = {1,1,0,1};
			colorBackground[] = {0.7,0.7,0.7,0.6};
			colorActive[] = {0.3,0.3,0.3,0.6};
			tooltip = "Street Lights Only Last for 1 Restart cost: 500 Energy";
			action = "closeDialog 0;[] execVM 'donkeymenu\donator\tempbaselighting.sqf'";
		};
	};
};