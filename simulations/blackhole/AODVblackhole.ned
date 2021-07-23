package ntuattack.simulations.blackhole;
import inet.common.scenario.ScenarioManager;
import inet.networklayer.configurator.ipv4.Ipv4NetworkConfigurator;
import inet.networklayer.ipv4.RoutingTableRecorder;
import inet.node.aodv.AodvRouter;
import inet.physicallayer.unitdisk.UnitDiskRadioMedium;
import inet.physicallayer.ieee80211.packetlevel.Ieee80211ScalarRadioMedium;
import inet.visualizer.contract.IIntegratedVisualizer;
import ntuattack.nodes.HhsAodvRouter;
import ntuattack.nodes.NTU_Attacker_Blackhole;
import ntuattack.nodes.niraAodvRouter;


network WSN_AODV_BH
{
    parameters:
        int numHosts;
        int numBHs;
        @display("bgb=1030,730;bgg=100,1,grey95");
        @figure[title](type=label; pos=0,-20; anchor=sw; color=darkblue);
//        @figure[sentPkText](type=indicatorText; pos=500,20; anchor=w; font=,10; textFormat="Sender: UDP packets sent: %g"; initialValue=0);
//        @statistic[packetSent](source=host[0].app[0].packetSent; record=figure(count); targetFigure=sentPkText);
//
//        @figure[rcvdPkText](type=indicatorText; pos=500,40; anchor=w; font=,10; textFormat="Receiver: UDP packets received: %g"; initialValue=0);
//        @statistic[packetReceived](source=host[10].app[0].packetReceived; record=figure(count); targetFigure=rcvdPkText);

//        @figure[x](type=indicatorText; pos=500,60; anchor=w; font=,10; textFormat="Data packet drop: UDP+TCP+ICMP"; initialValue=0);
//        @figure[y](type=indicatorText; pos=500,80; anchor=w; font=,10; textFormat="Fake RREP Probability: 1.0"; initialValue=0);
//        @figure[z](type=indicatorText; pos=500,100; anchor=w; font=,10; textFormat="Dropping Probability: 1.0"; initialValue=0);

    submodules:
        visualizer: <default("IntegratedCanvasVisualizer")> like IIntegratedVisualizer if hasVisualizer() {
            @display("p=-100,510");
        }
        radioMedium: UnitDiskRadioMedium {
            parameters:
                @display("p=-100,199;is=s");
        }
        configurator: Ipv4NetworkConfigurator {
            parameters:
                config = xml("<config><interface hosts='*' address='145.236.x.x' netmask='255.255.0.0'/></config>");
                @display("p=-100,103;is=s");
        }
        routingTableRecorder: RoutingTableRecorder {
            parameters:
                @display("p=-110,710;is=s");
        }
        scenarioManager: ScenarioManager {
            parameters:
                script = default(xml("<scenario/>"));
                @display("p=1000,428;is=s");
        }

        Bs: AodvRouter {
            parameters:
                @display("i=device/wifilaptop,#73D216,68;p=818.04803,347.776");
        }
        S0: AodvRouter {

            @display("tt=Sender;p=116.864006,91.520004");
        }
        S1: AodvRouter {

            @display("tt=Sender;p=22.528,426.62402");
        }
        H[numHosts]: AodvRouter {
            parameters:
                @display("i=device/pocketpc_s;r=,,#707070");
        }
        S2: AodvRouter {

            @display("tt=Sender;p=360.448,509.696");
        }

        S3: AodvRouter {

            @display("tt=Sender;p=568.83203,309.76");
        }
        S4: AodvRouter {

            @display("tt=Sender;p=784.25604,646.27203");
        }

        BH[numBHs]: NTU_Attacker_Blackhole {
            @display("i=device/laptop,#EF2929,62");
        }
    connections allowunconnected:
}
