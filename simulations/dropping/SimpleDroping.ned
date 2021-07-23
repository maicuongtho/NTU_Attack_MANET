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

package ntuattack.simulations.dropping;

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

package ntuattack.simulations.delay;
import inet.common.scenario.ScenarioManager;
import inet.networklayer.configurator.ipv4.Ipv4NetworkConfigurator;
import inet.networklayer.ipv4.RoutingTableRecorder;
import inet.node.aodv.AodvRouter;
import inet.physicallayer.unitdisk.UnitDiskRadioMedium;
import inet.visualizer.contract.IIntegratedVisualizer;
import ntuattack.nodes.NTU_AodvRouter;
import ntuattack.nodes.NTU_delayerAodvRouter;
import ntuattack.nodes.NTU_dropperAodvRouter;
//
// TODO auto-generated type
//
network SimpleDropongAttack
{
    parameters:
        @figure[title](type=label; pos=0,0; anchor=sw; color=darkblue);
        @display("bgb=534,485");
    submodules:
        visualizer: <default("IntegratedCanvasVisualizer")> like IIntegratedVisualizer if hasVisualizer() {
            @display("p=36,449");
        }
        radioMedium: UnitDiskRadioMedium {
            parameters:
                @display("p=455,442");
        }
        configurator: Ipv4NetworkConfigurator {
            parameters:
                @display("p=363,500;is=s");
                config = xml("<config><interface hosts='*' address='145.236.x.x' netmask='255.255.0.0'/></config>");
        }
        routingTableRecorder: RoutingTableRecorder {
            parameters:
                @display("p=318,446");
        }
        scenarioManager: ScenarioManager {
            parameters:
                script = default(xml("<scenario/>"));
                @display("p=156,445");
        }

        sender: AodvRouter {
            parameters:
                @display("i=device/pocketpc_s;r=,,#707070;p=84,152");
        }

        receiver: AodvRouter {
            parameters:
                @display("i=device/pocketpc_s;r=,,#707070;p=416,151");
        }
		// Nút trung gian thực hiện hành vi delay gói, ở cùng vị trí nút cũ
        droper: NTU_dropperAodvRouter {
            @display("p=243,96;i=,#EF2929,90");
        } 
    connections allowunconnected:
}


//
//          delayer: NTU_delayerAodvRouter {
//            @display("p=243,96;i=,#EF2929"); }

