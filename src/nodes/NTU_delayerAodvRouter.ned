package ntuattack.nodes;
import ntuattack.attacks.controllers.delayAttack.NTU_DelayingAttack;
import ntuattack.nodes.NTU_AodvRouter;
import ntuattack.attacks.controllers.droppingAttack.NTU_DroppingAttack;
module NTU_delayerAodvRouter extends NTU_AodvRouter
{
    submodules:
        ntu_DelayingAttack: NTU_DelayingAttack { // Delaying Attack Controller
            @display("p=878.85,67.725");
            active = true;
            startTime = 0s;
            endTime = 150s;
            delayAttackProbability = 1;
        }
}

