package ntuattack.simulations.blackhole;
import inet.common.scenario.ScenarioManager;
import inet.networklayer.configurator.ipv4.Ipv4NetworkConfigurator;
import inet.networklayer.ipv4.RoutingTableRecorder;
import inet.physicallayer.unitdisk.UnitDiskRadioMedium;
import inet.physicallayer.ieee80211.packetlevel.Ieee80211ScalarRadioMedium;
import inet.visualizer.contract.IIntegratedVisualizer;
import ntuattack.nodes.TnTaodvRouter;
network AODV20_TnT
{
    parameters:
        @display("bgb=1030,730;bgg=100,1,grey95");
        @figure[title](type=label; pos=0,-20; anchor=sw; color=darkblue);
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
                @display("p=-110,428;is=s");
        }

        Bs1: TnTaodvRouter {
            parameters:
                @display("i=device/wifilaptop,#73D216,68;p=348.4,180.7");
        }
        S5: TnTaodvRouter {

            @display("tt=Sender;p=116.864006,91.520004");
        }
        S1: TnTaodvRouter {

            @display("tt=Sender;p=22.528,426.62402");
        }

        S2: TnTaodvRouter {

            @display("tt=Sender;p=360.448,509.696");
        }

        S3: TnTaodvRouter {

            @display("tt=Sender;p=547.3,507");
        }
        S4: TnTaodvRouter {

            @display("tt=Sender;p=784.25604,646.27203");
        }

        H1: TnTaodvRouter {
            parameters:
                @display("i=device/pocketpc_s;r=,,#707070;p=96,220");
        }


        H2: TnTaodvRouter {
            parameters:
                @display("i=device/pocketpc_s;r=,,#707070;p=247,144.3");
        }


        H3: TnTaodvRouter {
            parameters:
                @display("i=device/pocketpc_s;r=,,#707070;p=219.7,309.4");
        }


        H4: TnTaodvRouter {
            parameters:
                @display("i=device/pocketpc_s;r=,,#707070;p=769.6,144.3");
        }


        H5: TnTaodvRouter {
            parameters:
                @display("i=device/pocketpc_s;r=,,#707070;p=521.3,72.799995");
        }


        H6: TnTaodvRouter {
            parameters:
                @display("i=device/pocketpc_s;r=,,#707070;p=509.6,416");
        }


        H7: TnTaodvRouter {
            parameters:
                @display("i=device/pocketpc_s;r=,,#707070;p=219.7,627.89996");
        }


        H8: TnTaodvRouter {
            parameters:
                @display("i=device/pocketpc_s;r=,,#707070;p=211.9,466.69998");
        }


        H9: TnTaodvRouter {
            parameters:
                @display("i=device/pocketpc_s;r=,,#707070;p=897,578.5");
        }


        H10: TnTaodvRouter {
            parameters:
                @display("i=device/pocketpc_s;r=,,#707070;p=620.1,626.6");
        }


        H11: TnTaodvRouter {
            parameters:
                @display("i=device/pocketpc_s;r=,,#707070;p=924.3,319.8");
        }


        H12: TnTaodvRouter {
            parameters:
                @display("i=device/pocketpc_s;r=,,#707070;p=722.8,426.4");
        }


        H13: TnTaodvRouter {
            parameters:
                @display("i=device/pocketpc_s;r=,,#707070;p=451.1,219.7");
        }


        H14: TnTaodvRouter {
            parameters:
                @display("i=device/pocketpc_s;r=,,#707070;p=750.1,538.2");
        }


        H15: TnTaodvRouter {
            parameters:
                @display("i=device/pocketpc_s;r=,,#707070;p=705.89996,289.9");
        }


        H16: TnTaodvRouter {
            parameters:
                @display("i=device/pocketpc_s;r=,,#707070;p=360.1,416");
        }


        H17: TnTaodvRouter {
            parameters:
                @display("i=device/pocketpc_s;r=,,#707070;p=322.4,249.59999");
        }


        H18: TnTaodvRouter {
            parameters:
                @display("i=device/pocketpc_s;r=,,#707070;p=184.59999,50.7");
        }


        H19: TnTaodvRouter {
            parameters:
                @display("i=device/pocketpc_s;r=,,#707070;p=295.1,646.1");
        }


        H20: TnTaodvRouter {
            parameters:
                @display("i=device/pocketpc_s;r=,,#707070;p=938.6,41.6");
        }


        Bs2: TnTaodvRouter {
            parameters:
                @display("i=device/wifilaptop,#73D216,68;p=858,399.1");
        }
    connections allowunconnected:

}
