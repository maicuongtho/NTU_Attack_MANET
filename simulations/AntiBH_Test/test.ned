package ntuattack.simulations.AntiBH_Test;
import inet.node.aodv.AodvRouter;
import inet.networklayer.configurator.ipv4.Ipv4NetworkConfigurator;
import inet.networklayer.ipv4.RoutingTableRecorder;
import inet.node.aodv.AodvRouter;
import inet.physicallayer.unitdisk.UnitDiskRadioMedium;
import inet.visualizer.contract.IIntegratedVisualizer;
import ntuattack.nodes.BHdebaratiAodvRouter;
import ntuattack.nodes.BHdokurerAodvRouter;
import ntuattack.nodes.HhsAodvRouter;
import ntuattack.nodes.NTU_Attacker_Blackhole;
import ntuattack.nodes.TnTaodvRouter;
import ntuattack.nodes.TnTaodv_BH_attaker;
import ntuattack.nodes.dokurerAodvRouter;
import inet.common.scenario.ScenarioManager;
import ntuattack.nodes.niraAodvRouter;
import ntuattack.nodes.TnTaodvRouter;

network TEST
{
    @display("bgb=800,500;bgg=100,1,grey95");
    @figure[title](type=label; pos=0,-1; anchor=sw; color=darkblue);

//    @figure[sentPkText](type=indicatorText; pos=500,20; anchor=w; font=,10; textFormat="Sender: UDP packets sent: %g"; initialValue=0);
//    @statistic[packetSent](source=sender.app[0].packetSent; record=figure(count); targetFigure=sentPkText);
//
//    @figure[rcvdPkText](type=indicatorText; pos=500,40; anchor=w; font=,10; textFormat="Receiver: UDP packets received: %g"; initialValue=0);
//    @statistic[packetReceived](source=receiver.app[0].packetReceived; record=figure(count); targetFigure=rcvdPkText);

    submodules:
        visualizer: <default("IntegratedCanvasVisualizer")> like IIntegratedVisualizer if hasVisualizer() {
            @display("p=107.736,500.088");
        }
        radioMedium: UnitDiskRadioMedium {
            parameters:
                @display("p=242.808,552.952;is=s");
        }
        configurator: Ipv4NetworkConfigurator {
            parameters:
                config = xml("<config><interface hosts='*' address='145.236.x.x' netmask='255.255.0.0'/></config>");
                @display("p=186.528,552.952;is=s");
        }
        routingTableRecorder: RoutingTableRecorder {
            parameters:
                @display("p=36.984,552.952;is=s");
        }
        scenarioManager: ScenarioManager {
            parameters:
                script = default(xml("<scenario/>"));
                @display("p=60,558;is=s");
        }

//        sender: AodvRouter {
//            @display("p=86.832,125.424;i=misc/solarpanel");
//        }
//        N2: AodvRouter {
//            @display("p=212.256,125.424");
//        }
//        N3: AodvRouter {
//            @display("p=337.68,123.816");
//        }
//        N4: AodvRouter {
//            @display("p=459.888,128.64");
//        }
//        N5: AodvRouter {
//            @display("p=642,147");
//        }
//        N6: AodvRouter {
//            @display("p=80.4,247.632");
//        }
//        N7: AodvRouter {
//            @display("p=204.216,286.224");
//        }
//        N9: AodvRouter {
//            @display("p=316.776,340.896");
//        }
//        N10: AodvRouter {
//            @display("p=459.888,350.544");
//        }
//        N11: AodvRouter {
//            @display("p=622.296,334.464");
//        }
//        receiver: AodvRouter {
//            @display("p=713.952,237.984;i=device/wifilaptop");
//        }
//        sender1: AodvRouter {
//            @display("p=241.2,403.608;i=misc/solarpanel");
//        }
//        sender2: AodvRouter {
//            @display("p=632,32;i=misc/solarpanel");
//        }
//        sender3: AodvRouter {
//            @display("p=424.512,226.728;i=misc/solarpanel");
//        }

        //         BH1: BHdokurerAodvRouter {
        //            @display("p=486.93997,483.175;i=,#EF2929,98");
        //        }
        //        BH2: BHdokurerAodvRouter {
        //            @display("p=535.885,252.25499;i=,#EF2929,98");
        //        }
        //        BH3: BHdokurerAodvRouter {
        //            @display("p=486.93997,77.81;i=,#EF2929,98");
        //        }
        N1: TnTaodvRouter {
            @display("p=364,201");
        }
        N2: TnTaodvRouter {
            @display("p=491,210");
        }
        sender0: TnTaodvRouter {
            @display("p=146,101;i=misc/solarpanel");
        }
        receiver: TnTaodvRouter {
            @display("p=617,257;i=device/wifilaptop");
        }

        ntu_Attacker_Blackhole: TnTaodv_BH_attaker {
            @display("p=562,101");
        }
        ntu_Attacker_Blackhole1: TnTaodv_BH_attaker {
            @display("p=73,191;is=vl");
        }
        N3: TnTaodvRouter {
            @display("p=354,307");
        }
        N4: TnTaodvRouter {
            @display("p=262,82");
        }
        N5: TnTaodvRouter {
            @display("p=222,221");
        }
        
}
