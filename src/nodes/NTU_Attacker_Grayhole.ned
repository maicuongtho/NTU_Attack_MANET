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

import ntuattack.attacks.controllers.droppingAttack.NTU_DroppingAttack;
import ntuattack.attacks.controllers.grayholeAttack.NTU_GrayholeAttack;
import ntuattack.nodes.NTU_AdhocHost;
import ntuattack.hackedmodules.routing.aodv.NTU_Aodv;
import inet.routing.aodv.Aodv;
//
// TODO auto-generated type
//
module NTU_Attacker_Grayhole extends NTU_AdhocHost
{
    submodules:
        aodv: NTU_Aodv {
            @display("p=875.69995,225.22499");
        }
        grayholer: NTU_GrayholeAttack {
            @display("p=911.925,72.45");
            active = true;
            startTime = 0s;
//            endTime = 100s;
            grayholeAttackProbability = 0.5;
            // graykOnlyWhenRouteInTable = false;
            seqnoAdded = 999;
            numHops = 1;
        }
        dropper: NTU_DroppingAttack {
            @display("p=779.625,74.024994");
            active = true;
            startTime = 0s;
//            endTime = 100s;
            // Option 1-----------------==
            droppingAttackProbability = 0.5;
            // Option 2--------------------
            droppingUDPdata = true;
            droppingTCPdata = false;
            droppingPINGdata = true;
        }

    connections:
        aodv.socketOut --> at.in++;
        aodv.socketIn <-- at.out++;
}
