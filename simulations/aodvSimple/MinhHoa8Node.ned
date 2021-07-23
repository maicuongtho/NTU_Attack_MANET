package ntuattack.simulations.aodvSimple;
import inet.node.aodv.AodvRouter;
import inet.networklayer.configurator.ipv4.Ipv4NetworkConfigurator;
import inet.networklayer.ipv4.RoutingTableRecorder;
import inet.node.aodv.AodvRouter;
import inet.physicallayer.unitdisk.UnitDiskRadioMedium;
import inet.visualizer.contract.IIntegratedVisualizer;
import inet.visualizer.networklayer.RoutingTableVisualizer;
import ntuattack.nodes.BHdokurerAodvRouter;
import ntuattack.nodes.NTU_Attacker_Blackhole;
import ntuattack.nodes.debaratiAodvRouter;
import ntuattack.nodes.debaratiAodvRouter;
import ntuattack.nodes.niraAodvRouter;


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
                    @display("p=136.795,139.305;i=misc/solarpanel");
                }
                N2: AodvRouter {
                    @display("p=262.29498,139.305");
                }
                N3: AodvRouter {
                    @display("p=387.79498,136.795");
                }
                N4: AodvRouter {
                    @display("p=510.78497,143.06999");
                }
                N5: AodvRouter {
                    @display("p=758.01996,143.06999");
                }
                N6: AodvRouter {
                    @display("p=131.775,261.03998");
                }
                N7: AodvRouter {
                    @display("p=254.765,299.94498");
                }
                N9: AodvRouter {
                    @display("p=367.715,355.16498");
                }
                N10:AodvRouter {
                    @display("p=510.78497,363.94998");
                }
                N11: AodvRouter {
                    @display("p=672.68,348.88998");
                }
                receiver: AodvRouter {
                    @display("p=764.295,252.25499;i=device/wifilaptop");
                }
                sender1: AodvRouter {
                    @display("p=292.41498,417.91498;i=misc/solarpanel");
                }
                sender2: AodvRouter {
                    @display("p=683.975,64.005;i=misc/solarpanel");
                }
                sender3: AodvRouter {
          				  @display("p=474.38998,239.70499;i=misc/solarpanel");
       			 }

        //         BH1: BHdokurerAodvRouter {
        //            @display("p=486.93997,483.175;i=,#EF2929,98");
        //        }
        //        BH2: BHdokurerAodvRouter {
        //            @display("p=535.885,252.25499;i=,#EF2929,98");
        //        }
        //        BH3: BHdokurerAodvRouter {
        //            @display("p=486.93997,77.81;i=,#EF2929,98");
        //        }
//        N1: debaratiAodvRouter {
//            @display("p=218.37,46.434998");
//        }
//        N2: debaratiAodvRouter {
//            @display("p=262.29498,139.305");
//        }
//        N3: debaratiAodvRouter {
//            @display("p=387.79498,136.795");
//        }
//        N4: debaratiAodvRouter {
//            @display("p=616.20496,210.84");
//        }
//        N5: debaratiAodvRouter {
//            @display("p=758.01996,143.06999");
//        }
//        N6: debaratiAodvRouter {
//            @display("p=131.775,261.03998");
//        }
//        N7: debaratiAodvRouter {
//            @display("p=254.765,299.94498");
//        }
//        N9: debaratiAodvRouter {
//            @display("p=367.715,355.16498");
//        }
//        N10: debaratiAodvRouter {
//            @display("p=510.78497,363.94998");
//        }
//        N11: debaratiAodvRouter {
//            @display("p=672.68,348.88998");
//        }
//        sender0: debaratiAodvRouter {
//            @display("p=136.795,139.305;i=misc/solarpanel");
//        }
//        sender1: debaratiAodvRouter {
//            @display("p=292.41498,464.34998;i=misc/solarpanel");
//        }
//        sender2: debaratiAodvRouter {
//            @display("p=683.975,64.005;i=misc/solarpanel");
//        }
//        sender3: debaratiAodvRouter {
//            @display("p=474.38998,239.70499;i=misc/solarpanel");
//        }
//        receiver: debaratiAodvRouter {
//            @display("p=764.295,252.25499;i=device/wifilaptop");
//        }

//        BH1: BHdokurerAodvRouter {
//            @display("p=608.675,363.94998;b=,,oval;i=,#EF2929,77");
//        }
//        BH2: BHdokurerAodvRouter {
//            @display("p=449.28998,76.555;b=,,oval;i=,#EF2929,77");
//        }
//        BH3: BHdokurerAodvRouter {
//            @display("p=203.31,348.88998;b=,,oval;i=,#EF2929,77");
//        }

}
