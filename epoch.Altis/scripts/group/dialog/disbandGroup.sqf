{
	[_x] join grpNull;    
}forEach units group player;
    hint parseText format["<t size='1.20' font='PuristaMedium' color='#0CE800'>[GROUP]</t><br/>
        <t size='1' font='PuristaMedium' align='left'>You have disbanded the group.</t><br/>"];