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

package ntuattack.simulations.whormhole;
import inet.node.aodv.AodvRouter;
import inet.node.ethernet.Eth100G;
import inet.node.ethernet.Eth1G;
import inet.common.scenario.ScenarioManager;
import inet.networklayer.configurator.ipv4.Ipv4NetworkConfigurator;
import inet.networklayer.ipv4.RoutingTableRecorder;
import inet.node.aodv.AodvRouter;
import inet.node.ethernet.EtherLink;
import inet.physicallayer.unitdisk.UnitDiskRadioMedium;
import inet.visualizer.contract.IIntegratedVisualizer;
import ntuattack.nodes.NTU_AodvRouter;
import ntuattack.nodes.NTU_Attacker_Blackhole;
import ntuattack.nodes.NTU_Attacker_Wormhole;


//
// TODO auto-generated type
//
network Vd
{
    @display("bgb=685,432;bgg=50");
    @figure[title](type=label; pos=0,0; anchor=sw; color=darkblue);
    submodules:
        visualizer: <default("IntegratedCanvasVisualizer")> like IIntegratedVisualizer if hasVisualizer() {
            @display("p=566,411");
        }
        radioMedium: UnitDiskRadioMedium {
            parameters:
                @display("p=263,407;is=s");
        }
        configurator: Ipv4NetworkConfigurator {
            parameters:
                config = xml("<config> \
                				<interface hosts='Wormholer_A' names='eth0' address='145.237.1.100' netmask='255.255.0.0' /> \
                                <interface hosts='Wormholer_B' names='eth0' address='145.237.1.200' netmask='255.255.0.0' /> \
                                <interface hosts='Wormholer_A' names='' address='145.236.1.10' netmask='255.255.0.0' /> \
                                <interface hosts='Wormholer_B' names='' address='145.236.1.20' netmask='255.255.0.0' /> \
                				<interface hosts='r*' names='' address='145.236.2.x' netmask='255.255.0.0'/>\
                				<interface hosts='s*' names='' address='145.236.2.x' netmask='255.255.0.0'/>\
                				</config>"
                		 );

                @display("p=443,385;is=s");
        }
        routingTableRecorder: RoutingTableRecorder {
            parameters:
                @display("p=365,413;is=s");
        }
        scenarioManager: ScenarioManager {
            parameters:
                script = default(xml("<scenario/>"));
                @display("p=100,400;is=s");
        }
        Wormholer_A: NTU_Attacker_Wormhole {
            @display("p=108,177;i=,#EF2929,90");

        }
        Wormholer_B: NTU_Attacker_Wormhole {
            @display("p=426,299;i=,#EF2929,90");
        }
        sender: AodvRouter {
            @display("p=69,70;i=device/pocketpc");
        }
        receiver: AodvRouter {
            @display("p=540,294;i=device/palm2");
        }
    connections:
        Wormholer_A.ethg[0] <--> Eth100G <--> Wormholer_B.ethg[0];
}
