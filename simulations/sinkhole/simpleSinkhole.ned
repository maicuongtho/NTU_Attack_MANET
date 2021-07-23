package ntuattack.simulations.sinkhole;
import inet.common.scenario.ScenarioManager;
import inet.networklayer.configurator.ipv4.Ipv4NetworkConfigurator;
import inet.networklayer.ipv4.RoutingTableRecorder;
import inet.node.aodv.AodvRouter;
import inet.physicallayer.unitdisk.UnitDiskRadioMedium;
import inet.visualizer.contract.IIntegratedVisualizer;
import ntuattack.nodes.NTU_AodvRouter;
import ntuattack.nodes.NTU_Attacker_Sinkhole;
//
// TODO auto-generated type
//
network SimpleSinkhole
{
    parameters:
        @figure[title](type=label; pos=0,0; anchor=sw; color=darkblue);
        @figure[sentPkText](type=indicatorText; pos=380,20; anchor=w; font=,12; textFormat="Sender: packets sent: %g"; initialValue=0);
        @statistic[packetSent](source=sender.app[0].packetSent; record=figure(count); targetFigure=sentPkText);

        @figure[rcvdPkText](type=indicatorText; pos=380,40; anchor=w; font=,12; textFormat="Receiver: packets received: %g"; initialValue=0);
        @statistic[packetReceived](source=receiver.app[0].packetReceived; record=figure(count); targetFigure=rcvdPkText);

    submodules:
        visualizer: <default("IntegratedCanvasVisualizer")> like IIntegratedVisualizer if hasVisualizer() {
            @display("p=580,125");
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
        sender: AodvRouter {
            parameters:
                @display("i=device/pocketpc_s;r=,,#707070;p=184,100");
        }
        receiver: AodvRouter {
            parameters:
                @display("i=device/pocketpc_s;r=,,#707070;p=534,163");
        }

        host1: AodvRouter {
            @display("p=307,92");
        }
        host2: AodvRouter {
            @display("p=204,229");
        }
        host3: AodvRouter {
            @display("p=274,331");
        }
        host4: AodvRouter {
            @display("p=426,108");
        }
        attacker: NTU_Attacker_Sinkhole {
            @display("p=284,169;i=old/laptop3");
        }
        attacker1: NTU_Attacker_Sinkhole {
            @display("p=205,386;i=old/laptop3");
        }
        host5: AodvRouter {
            @display("p=397,361");
        }
    connections allowunconnected:
}
