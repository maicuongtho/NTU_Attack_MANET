package ntuattack.attacks.controllers.floodingAttack;
import ntuattack.attacks.controllers.NTU_Attack;

simple NTU_FloodingAttack extends NTU_Attack
{
    parameters:
    	@class(NTU_FloodingAttack);
        @display("i=misc/cloud3,red,100;is=l");
        attackType = "flooding"; //Should correspond with the tag located in the hackedModules.ned. e.g. @dropping for this attack.
     	bool isHelloFlooding = default(false); 
     	bool isRreqFlooding =default(false); 
     	bool isDataFlooding =default(false); 
	 	double Interval_HelloFlooing= default(2.0); 
	 	double Interval_RreqFlooing= default(2.0);
	 	double Interval_DataFlooing=default(3.0);     
}
