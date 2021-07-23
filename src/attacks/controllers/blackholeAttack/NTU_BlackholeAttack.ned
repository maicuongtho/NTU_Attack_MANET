package ntuattack.attacks.controllers.blackholeAttack;
import ntuattack.attacks.controllers.NTU_Attack;

module NTU_BlackholeAttack extends NTU_Attack
{
    parameters:
        @class(NTU_BlackholeAttack);
        @display("i=misc/cloud3,red,100;is=l");
        attackType = "blackhole";  //Should correspond with the tag located in the hackedModules.ned. e.g. @sinkhole for this attack.       
        double blackholeAttackProbability = default(0); //Probability of answering a RREQ message with a fake route. Range [0,1].
        bool blackOnlyWhenRouteInTable = default(false); //TRUE: Send fake answers to RREQ messages only when requested routes are really in routing table of sinkhole node.
		volatile double seqnoAdded = default(4294967295); 	// Fake sequence number generated.
        volatile int numHops = default(1);						// Fake number of hops.
}
