package ntuattack.nodes;
import ntuattack.attacks.controllers.droppingAttack.NTU_DroppingAttack;
import inet.node.inet.WirelessHost;
//
// Attacker wireless host. Modificated from WirelessHost module. 
// Redefined from INET framework and used as attacker host.
//
// To implement an attack you must include the corresponding attack controller module in the attacker host.
//
// This attack could be include N attacks controllers to implement several simultaneous attacks.
// The current attack controllers included are:
// - NTU_DroppingAttack (dropping attack controller)
//
// @see NTU_StandardHost, NTU_WirelessHost, NTU_DroppingAttack
//
// @author Gabriel Maciá Fernández, gmacia@ugr.es
// @date 01/22/2013
module NTU_AttackerWirelessHost extends NTU_WirelessHost
{
    @display("i=device/wifilaptop;bgb=754,448;i2=status/cross,white");
    submodules:
        //# Include dropping attack controller 
        droppingAttack: NTU_DroppingAttack {
            @display("p=665,54");
            active = false;
            startTime = 0s;
            endTime = 10s;
            droppingAttackProbability = 0;
        }
}
