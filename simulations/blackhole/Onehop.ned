//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 

package ntuattack.simulations.blackhole;

import inet.node.aodv.AodvRouter;
import inet.networklayer.configurator.ipv4.Ipv4NetworkConfigurator;
import inet.networklayer.ipv4.RoutingTableRecorder;
import inet.physicallayer.unitdisk.UnitDiskRadioMedium;
import inet.visualizer.contract.IIntegratedVisualizer;
import inet.visualizer.networklayer.RoutingTableVisualizer;
import ntuattack.nodes.NTU_Attacker_Blackhole;
import ntuattack.nodes.TnTaodvRouter;
import ntuattack.nodes.TnTaodv_BH_attaker;


//
// TODO auto-generated type
//
network Onehop
{
    @display("bgb=716,423;bgg=50");
    submodules:
        visualizer: <default("IntegratedCanvasVisualizer")> like IIntegratedVisualizer if hasVisualizer() {
            @display("p=60,510");
        }
        radioMedium: UnitDiskRadioMedium {
            parameters:
                @display("p=60,199;is=s");
        }
        configurator: Ipv4NetworkConfigurator {
            parameters:
                config = xml("<config><interface hosts='*' address='145.236.x.x' netmask='255.255.0.0'/></config>");
                @display("p=60,103;is=s");
        }
        routingTableRecorder: RoutingTableRecorder {
            parameters:
                @display("p=60,310;is=s");
        }
        S: AodvRouter {
            @display("p=50,249");
        }
//        R: AodvRouter {
//            @display("p=541,60");
//        }
        R: AodvRouter {
            @display("p=310,249");
        }
        aodvRouter: AodvRouter {
            @display("p=300,249");
        }
        aodvRouter1: AodvRouter {
            @display("p=367,74");
        }
}
