/*
 * NTU_BlackholeAttack.h
 *
 *  Created on: Mar 14, 2020
 *      Author: thomc
 */

#ifndef ATTACKS_CONTROLLERS_BLACKHOLEATTACK_NTU_BLACKHOLEATTACK_H_
#define ATTACKS_CONTROLLERS_BLACKHOLEATTACK_NTU_BLACKHOLEATTACK_H_

#include "NTU_Attack.h"
#include "NTU_BlackholeMessage_m.h"
class NTU_BlackholeAttack: public NTU_Attack {
protected:
       virtual cMessage *generateAttackMessage(const char* name);
};
#endif /* ATTACKS_CONTROLLERS_BLACKHOLEATTACK_NTU_BLACKHOLEATTACK_H_ */
