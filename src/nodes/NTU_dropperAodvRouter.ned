package ntuattack.nodes;
import ntuattack.nodes.NTU_AodvRouter;
import ntuattack.attacks.controllers.droppingAttack.NTU_DroppingAttack;
module NTU_dropperAodvRouter extends NTU_AodvRouter
{
    submodules:
        droppingAttack: NTU_DroppingAttack   // Droping Attack Controller
        {
            @display("p=911.925,74.024994");
            active = true;
            startTime = 10s;
            endTime = 60s;
            droppingAttackProbability = 1;
            droppingUDPdata = true;
            droppingTCPdata = true;
            droppingPINGdata = true;
        }
}

