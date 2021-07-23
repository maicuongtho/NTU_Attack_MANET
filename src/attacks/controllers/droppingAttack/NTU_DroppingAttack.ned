package ntuattack.attacks.controllers.droppingAttack;
import ntuattack.attacks.controllers.NTU_Attack;

simple NTU_DroppingAttack extends NTU_Attack
{
      parameters:
        @class(NTU_DroppingAttack);
        @display("i=misc/cloud3,red,100;is=l");
        attackType = "dropping";  
        double droppingAttackProbability = default(0); //Probability of dropping a packet. 
        bool droppingUDPdata=default(false);  		   //Drop  data transfer by UDP protocol
    	bool droppingTCPdata=default(false);  		    //Drop data transfer by UDP protocol
   	    bool droppingPINGdata=default(false);  			//Drop  data transfer by ICMP protocol
}


