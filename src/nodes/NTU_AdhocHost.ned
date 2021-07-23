package ntuattack.nodes;

import inet.node.inet.AdhocHost;
import ntuattack.attacks.controllers.NTU_Attack;
import ntuattack.attacks.controllers.droppingAttack.NTU_DroppingAttack;
//
// Attacker wireless ad hoc host. Modificated from WirelessHost module. 
// Redefined from INET framework and used as attacker host.
//
// To implement an attack you must include the corresponding attack controller module in the attacker host.
//
// This attack could be include N attacks controllers to implement several simultaneous attacks.
// The current attack controllers included are:
// - NTU_DroppingAttack (dropping attack controller)
// - NA_SinkholeAttack (dropping attack controller)
module NTU_AdhocHost extends NTU_WirelessHost
{
    parameters:
        @display("i=device/cellphone");
        wlan[*].mgmt.typename = default("Ieee80211MgmtAdhoc");
        wlan[*].agent.typename = default("");
        forwarding = default(true);   
}
