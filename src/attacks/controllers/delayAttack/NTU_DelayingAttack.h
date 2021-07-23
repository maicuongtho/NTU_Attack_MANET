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

#ifndef __NTUATTACK_NTU_DELAYINGATTACK_H_
#define __NTUATTACK_NTU_DELAYINGATTACK_H_
#include "NTU_Attack.h"
#include "NTU_DelayMessage_m.h"
/**
 * TODO - Generated class
 */
class NTU_DelayingAttack : public NTU_Attack {

protected:
    /**
     * Overridden function
     */
    virtual cMessage *generateAttackMessage(const char* name);
};

#endif
