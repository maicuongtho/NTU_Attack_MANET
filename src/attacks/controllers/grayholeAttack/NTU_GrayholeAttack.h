/*
 * NTU_GrayholeAttack.h
 *
 *  Created on: Mar 12, 2020
 *      Author: thomc
 */

#ifndef ATTACKS_CONTROLLERS_GRAYHOLEATTACK_NTU_GRAYHOLEATTACK_H_
#define ATTACKS_CONTROLLERS_GRAYHOLEATTACK_NTU_GRAYHOLEATTACK_H_

#include "NTU_Attack.h"
#include "NTU_GrayholeMessage_m.h"
class NTU_GrayholeAttack: public NTU_Attack {
protected:
    virtual cMessage *generateAttackMessage(const char* name);
};

#endif /* ATTACKS_CONTROLLERS_GRAYHOLEATTACK_NTU_GRAYHOLEATTACK_H_ */
