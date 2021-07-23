package ntuattack.nodes;
import ntuattack.attacks.controllers.droppingAttack.NTU_DroppingAttack;
import ntuattack.attacks.controllers.blackholeAttack.NTU_BlackholeAttack;
import ntuattack.nodes.NTU_AdhocHost;
import ntuattack.hackedmodules.routing.aodv.NTU_Aodv;
import inet.routing.aodv.Aodv;

module NTU_Attacker_Blackhole  extends NTU_AdhocHost
{
    submodules:
        aodv: NTU_Aodv {
            @display("p=875.69995,225.22499");
        }
        blackholer: NTU_BlackholeAttack {
            @display("p=1004.85,211.04999");
            active = true;
            startTime = 0s;
           // endTime = 20s;
            blackholeAttackProbability = 1;
            blackOnlyWhenRouteInTable = false;
//            seqnoAdded = 9999;
//            numHops = 1;
        }
        dropper: NTU_DroppingAttack {
            @display("p=779.625,74.024994");
            active = true;
            startTime = 0s;
          //  endTime = 20s;
            droppingAttackProbability = 1;
            droppingUDPdata = true;
            droppingTCPdata = true;
            droppingPINGdata = true;
        }

    connections:
        aodv.socketOut --> at.in++;
        aodv.socketIn <-- at.out++;
}
