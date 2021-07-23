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
import inet.common.scenario.ScenarioManager;
import inet.networklayer.configurator.ipv4.Ipv4NetworkConfigurator;
import inet.networklayer.ipv4.RoutingTableRecorder;
import inet.node.aodv.AodvRouter;
import inet.physicallayer.unitdisk.UnitDiskRadioMedium;
import inet.visualizer.contract.IIntegratedVisualizer;
import ntuattack.nodes.NTU_Attacker_Blackhole;
import ntuattack.nodes.TnTaodvRouter;


//
// TODO auto-generated type
//
network SimpleBlackhole
{
    parameters:
        @figure[title](type=label; pos=0,-1; anchor=sw; color=darkblue);

        @figure[sentPkText](type=indicatorText; pos=380,20; anchor=w; font=,12; textFormat="Sender: packets sent: %g"; initialValue=0);
        @statistic[packetSent](source=sender.app[0].packetSent; record=figure(count); targetFigure=sentPkText);

        @figure[rcvdPkText](type=indicatorText; pos=380,40; anchor=w; font=,12; textFormat="Receiver: packets received: %g"; initialValue=0);
        @statistic[packetReceived](source=receiver.app[0].packetReceived; record=figure(count); targetFigure=rcvdPkText);

        @display("bgb=680,461");
    submodules:
        visualizer: <default("IntegratedCanvasVisualizer")> like IIntegratedVisualizer if hasVisualizer() {
            @display("p=28,30");
        }
        radioMedium: UnitDiskRadioMedium {
            parameters:
                @display("p=100,200;is=s");
        }
        configurator: Ipv4NetworkConfigurator {
            parameters:
                //   addDefaultRoutes = false;
                //   addStaticRoutes = false;
                //   addSubnetRoutes = false;
                config = xml("<config><interface hosts='*' address='145.236.x.x' netmask='255.255.0.0'/></config>");
                @display("p=100,100;is=s");
        }
        routingTableRecorder: RoutingTableRecorder {
            parameters:
                @display("p=100,300;is=s");
        }
        scenarioManager: ScenarioManager {
            parameters:
                script = default(xml("<scenario/>"));
                @display("p=100,400;is=s");
        }
        sender: TnTaodvRouter {
            parameters:
                @display("i=device/pocketpc_s;r=,,#707070;p=301,143");
        }
        receiver: TnTaodvRouter {
            parameters:
                @display("i=device/pocketpc_s;r=,,#707070;p=629,77");
        }

        host1: TnTaodvRouter {
            @display("p=512,108");
        }
        host2: TnTaodvRouter {
            @display("p=442,190");
        }
        bh: NTU_Attacker_Blackhole {
            @display("p=566,218;i=,#EF2929,66");
        }
        host3: TnTaodvRouter {
            @display("p=471,319");
        }
        host4: TnTaodvRouter {
            @display("p=321,257");
        }
        bh1: NTU_Attacker_Blackhole {
            @display("p=245,348;i=,#EF2929,66");
        }
    connections allowunconnected:
}
