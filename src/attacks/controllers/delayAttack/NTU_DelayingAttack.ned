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

package ntuattack.attacks.controllers.delayAttack;
import ntuattack.attacks.controllers.NTU_Attack;
//
// TODO auto-generated module
//
simple NTU_DelayingAttack  extends NTU_Attack
{
     	@class(NTU_DelayingAttack);
        @display("i=misc/cloud3,red,100;is=l");
        attackType = "delay";  //Should correspond with the tag located in the hackedModules.ned. e.g. @delay for this attack.
        double delayAttackProbability = default(0); //Probability of delaying a packet. Range [0,1].
        volatile double delayAttackValue @unit(s) = default(normal(1s, 0.1s));//Random delay time
}
