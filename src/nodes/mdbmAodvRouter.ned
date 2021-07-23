package ntuattack.nodes;

import ntuattack.hackedmodules.routing.MDBM_Aodv.MDBM_Aodv;
import ntuattack.hackedmodules.routing.HHS_Aodv.hhsAodv;
import inet.node.inet.AdhocHost;

//
// TODO auto-generated type
//
module MdbmAodvRouter extends AdhocHost
{
    submodules:
        aodv: MDBM_Aodv {
            @display("p=825,226");
        }
    connections:
        aodv.socketOut --> at.in++;
        aodv.socketIn <-- at.out++;
}