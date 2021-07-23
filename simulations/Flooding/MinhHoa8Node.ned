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

package ntuattack.simulations.Flooding;

import inet.node.aodv.AodvRouter;
import inet.networklayer.configurator.ipv4.Ipv4NetworkConfigurator;
import inet.networklayer.ipv4.RoutingTableRecorder;
import inet.node.aodv.AodvRouter;
import inet.physicallayer.unitdisk.UnitDiskRadioMedium;
import inet.visualizer.contract.IIntegratedVisualizer;
import inet.visualizer.networklayer.RoutingTableVisualizer;
import ntuattack.nodes.NTU_Attacker_Flooding;


network MinhHoa8Node
{
    @display("bgb=1000,600;bgg=100,1,grey95");
    @figure[title](type=label; pos=0,-1; anchor=sw; color=darkblue);

//    @figure[sentPkText](type=indicatorText; pos=500,20; anchor=w; font=,10; textFormat="Sender: UDP packets sent: %g"; initialValue=0);
//    @statistic[packetSent](source=sender.app[0].packetSent; record=figure(count); targetFigure=sentPkText);
//
//    @figure[rcvdPkText](type=indicatorText; pos=500,40; anchor=w; font=,10; textFormat="Receiver: UDP packets received: %g"; initialValue=0);
//    @statistic[packetReceived](source=receiver.app[0].packetReceived; record=figure(count); targetFigure=rcvdPkText);

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

        sender: AodvRouter {
            @display("p=312.495,72.79");
        }
        N1: AodvRouter {
            @display("p=294.06998,210.84");
        }
        N2: AodvRouter {
            @display("p=527.1,271.08");
        }
        N3: AodvRouter {
            @display("p=430.465,185.73999");
        }
        N4: AodvRouter {
            @display("p=537.13995,154.36499");
        }
        receiver: AodvRouter {
            @display("p=682,204");
        }
        ntu_Flooder1: NTU_Attacker_Flooding {
            @display("p=419.16998,348.88998;i=,#A40000,100");
        }
        ntu_Flooder2: NTU_Attacker_Flooding {
            @display("p=485.685,72.79;i=,#A40000,100");
        }
}
