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

class DP_Srndr_IGUIBack
{
	type = 0;
	idc = -1;
	style = 80;
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
class DP_Srndr_RscButton
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
class DP_Srndr_RscText
{
	 access = 0;
	 type = CT_STATIC;
	 idc = -1;
	 style = 2;
	 w = 0.1; h = 0.05;
	 //x and y are not part of a global class since each rsctext will be positioned 'somewhere'
	 font = "PuristaMedium";
	 colorBackground[] = {0,0,0,0};
	 colorText[] = {0,0,1,1};
	 text = "";
	 fixedWidth = 0;
	 shadow = 0;
};

class stop_surrendering {
	idd = 8084;
	movingEnable = true;
	enableSimulation = true;
	controlsBackground[] = {};
	objects[] = {};
	class controls 
	{
		class IGUIBack_2204: DP_Srndr_IGUIBack
		{
			idc = 2204;
			x = 0.736362 * safezoneW + safezoneX;
			y = 0.60736 * safezoneH + safezoneY;
			w = 0.185625 * safezoneW;
			h = 0.132 * safezoneH;
		};
		class RscButton_1644: DP_Srndr_RscButton
		{
			idc = 1644;
			text = "STOP";
			x = 0.768125 * safezoneW + safezoneX;
			y = 0.676 * safezoneH + safezoneY;
			w = 0.12375 * safezoneW;
			h = 0.044 * safezoneH;
			colorText[] = {0,1,0,1};
			tooltip = "";
			action = "closeDialog 0;[] call dp_Surrender_Stop";
		};
		class RscText_1022: DP_Srndr_RscText
		{
			idc = 1022;
			text = "Donkey Surrender";
			x = 0.752656 * safezoneW + safezoneX;
			y = 0.621 * safezoneH + safezoneY;
			w = 0.154687 * safezoneW;
			h = 0.044 * safezoneH;
			colorText[] = {1,0,0,1};
			colorBackground[] = {0.502,0.502,0.502,0.502};
			sizeEx = 1.2 * GUI_GRID_H;
		};
	};
};