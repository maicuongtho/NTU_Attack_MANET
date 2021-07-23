package ntuattack.nodes;

import ntuattack.hackedmodules.routing.TnTaodv.TnTaodv;
import inet.node.inet.AdhocHost;

module TnTaodvRouter extends AdhocHost
{
    submodules:
        aodv: TnTaodv {
            @display("p=825,226");
        }
    connections:
        aodv.socketOut --> at.in++;
        aodv.socketIn <-- at.out++;
}
