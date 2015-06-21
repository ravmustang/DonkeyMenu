/*
	ArmA 3 Epoch Donkey Punch
	by =RAV=MusTanG
	Temp Groups Menu GUI v0.1
*/
#define gDialog 55510
#define gInviteButton 55511
#define gDisbandButton 55512
#define gLeaveButton 55513
#define gAcceptButton 55514
#define gDeclineButton 55515
#define gInviteText 55516

class DTG_IGUIBack
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
class DTG_RscText
{
	 access = 0;
	 type = CT_STATIC;
	 idc = -1;
	 style = 2;
	 w = 0.1; h = 0.05;
	 //x and y are not part of a global class since each rsctext will be positioned 'somewhere'
	 font = "PuristaMedium";
	 text = "";
	 colorText[] = {0,1,0,1};
	 fixedWidth = 0;
	 shadow = 0;
	 sizeEx = 0.04;
};
class DTG_RscStructuredText
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
class DTG_RscPicture
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
class DTG_RscFrame
{
	type = 0;
	idc = -1;
	style = 64;
	shadow = 2;
	colorBackground[] = {0,1,0,1};
	colorText[] = {0,1,0,1};
	font = "PuristaLight";
	sizeEx = 1;
	text = "";
};
class DTG_RscButton
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
class GroupManagement 
{

	idd = gDialog;
	movingEnable = true;
	enableSimulation = true;
	
	class controls
	{
		class MainBG: DTG_IGUIBack
		{
			idc = -1;
			x = 0.355625 * safezoneW + safezoneX;
			y = 0.357 * safezoneH + safezoneY;
			w = 0.185625 * safezoneW;
			h = 0.352 * safezoneH;
			colorBackground[] = {0.1,0.1,0.1,0.01};
		};
		class MainTitle: DTG_RscText
		{
			idc = -1;
			text = "DonkeyPunch.INFO Temp Groups";
			x = 0.37625 * safezoneW + safezoneX;
			y = 0.379 * safezoneH + safezoneY;
			w = 0.144375 * safezoneW;
			h = 0.044 * safezoneH;
			colorText[] = {0,1,0,1};
			colorBackground[] = {0.1,0.1,0.1,0.5};
			sizeEx = 0.04;
		};
		class InviteText: DTG_RscStructuredText
		{
			idc = gInviteText;
			x = 0.391719 * safezoneW + safezoneX;
			y = 0.621 * safezoneH + safezoneY;
			w = 0.113437 * safezoneW;
			h = 0.066 * safezoneH;
		};
		class DonkeyFrame: DTG_RscFrame
		{
			idc = -1;
			x = 0.37625 * safezoneW + safezoneX;
			y = 0.445 * safezoneH + safezoneY;
			w = 0.144375 * safezoneW;
			h = 0.264 * safezoneH;
			colorText[] = {0,1,0,1};
		};
		class InviteButton: DTG_RscButton
		{
			idc = gInviteButton;
			text = "Invite"; //--- ToDo: Localize;
			onButtonClick = "[] execVM 'scripts\group\dialog\inviteToGroup.sqf'";
			x = 0.427812 * safezoneW + safezoneX;
			y = 0.445 * safezoneH + safezoneY;
			w = 0.04125 * safezoneW;
			h = 0.022 * safezoneH;
			colorText[] = {0,0.95,0,0.95};
			tooltip = "Invite this player to your Temp Group, this has no impact on your EPOCH GROUP!";
		};
		class LeaveButton: DTG_RscButton
		{
			idc = gLeaveButton;
			text = "Leave Group"; //--- ToDo: Localize;
			onButtonClick = "[] execVM 'scripts\group\dialog\leaveGroup.sqf'";
			x = 0.4175 * safezoneW + safezoneX;
			y = 0.533 * safezoneH + safezoneY;
			w = 0.061875 * safezoneW;
			h = 0.022 * safezoneH;
			colorText[] = {0.95,0,0,0.95};
			tooltip = "Leave your Group to start a new Temp Group, this has no effect on EPOCH GROUPS!";
		};
		class DisbandButton: DTG_RscButton
		{
			idc = gDisbandButton;
			text = "Disband"; //--- ToDo: Localize;
			onButtonClick = "[] execVM 'scripts\group\dialog\disbandGroup.sqf'";
			x = 0.427812 * safezoneW + safezoneX;
			y = 0.5 * safezoneH + safezoneY;
			w = 0.04125 * safezoneW;
			h = 0.022 * safezoneH;
			colorText[] = {0.95,0,0,0.95};
			tooltip = "Leave your Temp Group, then Soft Log to Lobby to automatically reenter your EPOCH GROUP!";
		};
		class AcceptInviteButton: DTG_RscButton
		{
			idc = gAcceptButton;
			text = "Accept"; //--- ToDo: Localize;
			onButtonClick = "[] execVM 'scripts\group\dialog\acceptGroupInvite.sqf'";
			x = 0.402031 * safezoneW + safezoneX;
			y = 0.577 * safezoneH + safezoneY;
			w = 0.04125 * safezoneW;
			h = 0.022 * safezoneH;
			colorText[] = {0,0.95,0,0.95};
			tooltip = "Leave your EPOCH GROUP first, then ACCEPT this to enter Temp Group!";
		};
		class DeclineInviteButton: DTG_RscButton
		{
			idc = gDeclineButton;
			text = "Decline"; //--- ToDo: Localize;
			onButtonClick = "[] execVM 'scripts\group\dialog\declineGroupInvite.sqf'";
			x = 0.453594 * safezoneW + safezoneX;
			y = 0.577 * safezoneH + safezoneY;
			w = 0.04125 * safezoneW;
			h = 0.022 * safezoneH;
			colorText[] = {0.95,0,0,0.95};
			tooltip = "Decline the Temp Group Invitation and stay in your EPOCH GROUP";
		};
		class DTGPicture: DTG_RscPicture
		{
			idc = -1;
			text = "scripts\donkeypunch.paa";
			x = 0.0514062 * safezoneW + safezoneX;
			y = 0.423 * safezoneH + safezoneY;
			w = 0.195937 * safezoneW;
			h = 0.231 * safezoneH;
		};
	};
};	