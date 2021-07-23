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

import ntuattack.attacks.controllers.floodingAttack.NTU_FloodingAttack;
import ntuattack.hackedmodules.routing.floodingAodv.floodNTU_Aodv;


//
// TODO auto-generated type
//
module NTU_Attacker_Flooding extends NTU_AdhocHost
{
    submodules:
        aodv: floodNTU_Aodv {
            @display("p=872.3,211.9");
        }
        ntu_FloodingAttack: NTU_FloodingAttack {
            @display("p=898.3,74.1");
            active = true;
            startTime = 0s;
            isHelloFlooding = false;
            isRreqFlooding = true;
            isDataFlooding = false;
            Interval_RreqFlooing = 0.6;
        }
    connections:
        aodv.socketOut --> at.in++;
        aodv.socketIn <-- at.out++;
}
