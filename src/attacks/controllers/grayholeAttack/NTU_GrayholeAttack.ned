package ntuattack.attacks.controllers.grayholeAttack;
import ntuattack.attacks.controllers.NTU_Attack;
// infected module: NTU_AODV
// this perform the first phrase of Grayhole
// the second phrase, we call Dropping NTU_Dropping
simple NTU_GrayholeAttack extends NTU_Attack
{
     	@class(NTU_GrayholeAttack);
        @display("i=misc/cloud3,red,100;is=l");
        attackType = "grayhole";    
        double grayholeAttackProbability = default(0); 
        //Probability of answering a RREQ message with a fake route. Range [0,1].
        bool grayOnlyWhenRouteInTable = default(false); 
        //TRUE: Send fake answers to RREQ messages only when requested routes are really in routing table of sinkhole node.
	    //FALSE: Send fake answers for any RREQ messages arriving at the sinkhole node.
        volatile double seqnoAdded = default(999); 	// Fake sequence number generated.
        volatile int numHops = default(1);	
}
