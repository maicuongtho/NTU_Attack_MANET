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

package ntuattack.nodes;

import inet.node.inet.AdhocHost;
import ntuattack.hackedmodules.routing.DebaratiAODV_BH.DebaratiAODV_BH;
import ntuattack.attacks.controllers.droppingAttack.NTU_DroppingAttack;
import ntuattack.attacks.controllers.blackholeAttack.NTU_BlackholeAttack;

//import inet.routing.aodv.Aodv;
module BHdebaratiAodvRouter extends AdhocHost
{
    submodules:
        aodv: DebaratiAODV_BH {
            @display("p=872.55,233.09999");
        }
          blackholer: NTU_BlackholeAttack {
            @display("p=1004.85,211.04999");
            active = true;
            startTime = 0s;
           // endTime = 20s;
            blackholeAttackProbability = 1;
            blackOnlyWhenRouteInTable = false;
//            seqnoAdded = 9999;
//            numHops = 1;
        }
        dropper: NTU_DroppingAttack {
            @display("p=779.625,74.024994");
            active = true;
            startTime = 0s;
          //  endTime = 20s;
            droppingAttackProbability = 1;
            droppingUDPdata = true;
            droppingTCPdata = true;
            droppingPINGdata = true;
        }
    
    connections:
        aodv.socketOut --> at.in++;
        aodv.socketIn <-- at.out++;
}
