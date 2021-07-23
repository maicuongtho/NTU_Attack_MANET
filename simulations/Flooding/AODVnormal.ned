package ntuattack.simulations.Flooding;
import inet.common.scenario.ScenarioManager;
import inet.networklayer.configurator.ipv4.Ipv4NetworkConfigurator;
import inet.networklayer.ipv4.RoutingTableRecorder;
import inet.node.aodv.AodvRouter;
import inet.physicallayer.unitdisk.UnitDiskRadioMedium;
import inet.visualizer.contract.IIntegratedVisualizer;
import ntuattack.nodes.NTU_Attacker_Flooding;


network AODVnormal
{
    parameters:
        int numHosts;
        int numReceives;
        int numSends;
        @display("bgb=1000,800;bgg=100,1,grey95");
        @figure[title](type=label; pos=0,-1; anchor=sw; color=darkblue);
  //      @figure[sentPkText](type=indicatorText; pos=500,20; anchor=w; font=,10; textFormat="Sender: UDP packets sent: %g"; initialValue=0);
  //      @statistic[packetSent](source=sender.app[0].packetSent; record=figure(count); targetFigure=sentPkText);

  //      @figure[rcvdPkText](type=indicatorText; pos=500,40; anchor=w; font=,10; textFormat="Receiver: UDP packets received: %g"; initialValue=0);
  //      @statistic[packetReceived](source=receiver.app[0].packetReceived; record=figure(count); targetFigure=rcvdPkText);

//        @figure[x](type=indicatorText; pos=10,460; anchor=w; font=,10; textFormat="Data packet drop: UDP+TCP+ICMP"; initialValue=0);
//        @figure[y](type=indicatorText; pos=600,480; anchor=w; font=,10; textFormat="Fake RREP Probability: 1.0"; initialValue=0);
//        @figure[z](type=indicatorText; pos=600,500; anchor=w; font=,10; textFormat="Dropping Probability: 0.5"; initialValue=0);

    submodules:
        visualizer: <default("IntegratedCanvasVisualizer")> like IIntegratedVisualizer if hasVisualizer() {
            @display("p=-160,510");
        }
        radioMedium: UnitDiskRadioMedium {
            parameters:
                @display("p=-180,199;is=s");
        }
        configurator: Ipv4NetworkConfigurator {
            parameters:
                config = xml("<config><interface hosts='*' address='145.236.x.x' netmask='255.255.0.0'/></config>");
                @display("p=-180,103;is=s");
        }
        routingTableRecorder: RoutingTableRecorder {
            parameters:
                @display("p=-180,310;is=s");
        }
        scenarioManager: ScenarioManager {
            parameters:
                script = default(xml("<scenario/>"));
                @display("p=11.2560005,775.056;is=s");
        }
        N[numHosts]: AodvRouter {
            parameters:
                @display("i=device/pocketpc_s;r=,,#707070;");
        }
        S[numSends]: AodvRouter {
            parameters:
                @display("i=misc/smartphone,#CE5C00,100");
        }
        R[numReceives]: AodvRouter {
            parameters:
                @display("i=misc/smartphone,,100");
        }
//            F1: NTU_Attacker_Flooding {
//                @display("p=226.90399,222.888;i=,#A40000,70;is=n;tt=RReq Flooder");
//            }
//            F2: NTU_Attacker_Flooding {
//                @display("p=664.648,530.112;i=,#CC0000,60;tt=RReq Flooder");
//            }
    connections allowunconnected:
}
