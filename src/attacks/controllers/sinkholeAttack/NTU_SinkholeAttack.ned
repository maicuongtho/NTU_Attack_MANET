package ntuattack.attacks.controllers.sinkholeAttack;
import ntuattack.attacks.controllers.NTU_Attack;
//
// Sinkhole attack controller simple module. Three parameter controls the attack behavior:
// the attack probability, if the route requested is knowed by the attacker or not and the
// the sequence number generated.
//
// @see NTU_Attack, NTU_AODV
//
// @author thomc
// @date 10/3/2020
simple NTU_SinkholeAttack extends NTU_Attack
{
    parameters:
        @class(NTU_SinkholeAttack);
        @display("i=misc/cloud3,red,100;is=l");
        attackType = "sinkhole";  //Should correspond with the tag located in the hackedModules.ned. e.g. @sinkhole for this attack.       
        double sinkholeAttackProbability = default(0); //Probability of answering a RREQ message with a fake route. Range [0,1].
        bool sinkOnlyWhenRouteInTable = default(false); //TRUE: Send fake answers to RREQ messages only when requested routes are really in routing table of sinkhole node.
		volatile double seqnoAdded = default(999); 	// Fake sequence number generated.
        volatile int numHops = default(1);						// Fake number of hops.
}
