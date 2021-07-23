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

package ntuattack.simulations.grayhole;
import inet.common.scenario.ScenarioManager;
import inet.networklayer.configurator.ipv4.Ipv4NetworkConfigurator;
import inet.networklayer.ipv4.RoutingTableRecorder;
import inet.node.aodv.AodvRouter;
import inet.physicallayer.unitdisk.UnitDiskRadioMedium;
import inet.visualizer.contract.IIntegratedVisualizer;
import ntuattack.nodes.NTU_AodvRouter;
import ntuattack.nodes.NTU_Attacker_Grayhole;
import ntuattack.nodes.NTU_Attacker_Sinkhole;
//
// TODO auto-generated type
//
network SimpleGrayhole
{
    parameters:
        @figure[title](type=label; pos=0,30; anchor=sw; color=darkblue);

//        @figure[sentPkText](type=indicatorText; pos=600,220; anchor=w; font=,12; textFormat="Sender: UDP packets sent: %g"; initialValue=0);
//        @statistic[packetSent](source=sender.app[0].packetSent; record=figure(count); targetFigure=sentPkText);
//
//        @figure[rcvdPkText](type=indicatorText; pos=600,240; anchor=w; font=,12; textFormat="Receiver: UDP packets received: %g"; initialValue=0);
//        @statistic[packetReceived](source=receiver.app[0].packetReceived; record=figure(count); targetFigure=rcvdPkText);
//
//        @figure[sentPkTextTCP](type=indicatorText; pos=600,280; anchor=w; font=,12; textFormat="TelnetClient: TCP packets sent: %g"; initialValue=0);
//        @statistic[packetSent](source=TelnetClient.app[0].packetSent; record=figure(count); targetFigure=sentPkTextTCP);
////
//        @figure[rcvdPkTextTCP](type=indicatorText; pos=600,540; anchor=w; font=,12; textFormat="TelnetServer: TCP packets received: %g"; initialValue=0);
//        @statistic[packetReceived](source=TelnetServer.app[0].packetReceived; record=figure(count); targetFigure=rcvdPkTextTCP);


        @display("bgb=1025.7,642.2");
    submodules:
        visualizer: <default("IntegratedCanvasVisualizer")> like IIntegratedVisualizer if hasVisualizer() {
            @display("p=860,540");
        }
        radioMedium: UnitDiskRadioMedium {
            parameters:
                @display("p=355,478;is=s");
        }
        configurator: Ipv4NetworkConfigurator {
            parameters:
                config = xml("<config>\
                	<interface hosts='*' address='145.236.x.x' netmask='255.255.0.0'/> \
                	</config>");
                @display("p=486,478;is=s");
        }
        routingTableRecorder: RoutingTableRecorder {
            parameters:
                @display("p=194,478;is=s");
        }
        scenarioManager: ScenarioManager {
            parameters:
                script = default(xml("<scenario/>"));
                @display("p=57,478;is=s");
        }
        sender: AodvRouter {
            parameters:
                @display("i=device/pocketpc_s;r=,,#707070;p=104,156");
        }
        receiver: AodvRouter {
            parameters:
                @display("i=device/pocketpc_s;r=,,#707070;p=491,75");
        }

        host1: AodvRouter {
            @display("p=226,56");
        }
        GrayHoler: NTU_Attacker_Grayhole {
            @display("p=241,211;i=misc/smartphone,#EF2929,80");
        }
        host2: AodvRouter {
            @display("p=352,126");
        }
        TelnetClient: AodvRouter {
            parameters:
                @display("i=device/laptop;p=210.59999,340.6");
        }
        TelnetServer: AodvRouter {
            parameters:
                @display("i=device/server2;p=528,211");
        }
        host3: AodvRouter {
            @display("p=371,234");
        }
    connections allowunconnected:
}
