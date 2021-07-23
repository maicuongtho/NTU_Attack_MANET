package ntuattack.simulations.dropping;
import inet.common.scenario.ScenarioManager;
import inet.networklayer.configurator.ipv4.Ipv4NetworkConfigurator;
import inet.networklayer.ipv4.RoutingTableRecorder;
import inet.node.aodv.AodvRouter;
import inet.physicallayer.unitdisk.UnitDiskRadioMedium;
import inet.visualizer.contract.IIntegratedVisualizer;
import ntuattack.nodes.NTU_AodvRouter;
import ntuattack.nodes.NTU_dropperAodvRouter;
network SimpleIPv4Droping
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

        AodvSender: AodvRouter {
            parameters:
                @display("i=device/pocketpc_s;r=,,#707070;p=113,51");
        }
        AodvSender1: AodvRouter {
            parameters:
                @display("i=device/pocketpc_s;r=,,#707070;p=343,39");
        }
        AodvReceiver: AodvRouter {
            parameters:
                @display("i=device/pocketpc_s;r=,,#707070;p=54,372");
        }
        AodvReceiver1: AodvRouter {
            parameters:
                @display("i=device/pocketpc_s;r=,,#707070;p=428,349");
        }

        droper1: NTU_dropperAodvRouter {
            @display("p=77,269;i=,#EF2929,90");
        }
        droper2: NTU_dropperAodvRouter {
            @display("p=418,133;i=,#EF2929,90");
        }

        aodvHost1: AodvRouter {
            @display("p=207,107;b=5,10");
        }
        aodvHost2: AodvRouter {
            @display("p=183,211");
        }
        aodvHost3: AodvRouter {
            @display("p=384,239");
        }
    connections allowunconnected:
}

