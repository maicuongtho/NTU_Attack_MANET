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
import ntuattack.attacks.controllers.wormholeAttack.NTU_WormholeAttack;
import ntuattack.nodes.NTU_AdhocHost;
import ntuattack.hackedmodules.routing.aodv.NTU_Aodv;

module NTU_Attacker_Wormhole extends NTU_AdhocHost
{
    submodules:
        aodv: NTU_Aodv {
            @display("p=875.69995,225.22499");
        }
        wormholer: NTU_WormholeAttack {
            @display("p=729.225,56.699997");
            active = true;
            startTime = 0s;
//            endTime = 100s;
            wormholeAttackProbability = 1;
        }
    connections:
        aodv.socketOut --> at.in++;
        aodv.socketIn <-- at.out++;
}
