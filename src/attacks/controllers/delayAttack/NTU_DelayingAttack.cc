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

#include "NTU_DelayingAttack.h"

Define_Module(NTU_DelayingAttack);

cMessage *NTU_DelayingAttack::generateAttackMessage(const char *name) {

    LOG << "NTU_DelayAttack: generateAttackMessage\n";
    NTU_DelayMessage *msg = new NTU_DelayMessage(name);
    msg->setDelayAttackProbability(par("delayAttackProbability").doubleValue());
    return msg;
}
