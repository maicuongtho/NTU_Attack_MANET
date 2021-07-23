/*
 * NTU_FloodingAttack.h
 *
 *  Created on: Mar 21, 2021
 *      Author: thomc
 */

#ifndef ATTACKS_CONTROLLERS_FLOODINGATTACK_NTU_FLOODINGATTACK_H_
#define ATTACKS_CONTROLLERS_FLOODINGATTACK_NTU_FLOODINGATTACK_H_
#include "NTU_Attack.h"
#include "NTU_FloodingM_m.h"

class NTU_FloodingAttack: public NTU_Attack {
protected:
    virtual cMessage *generateAttackMessage(const char* name);
};

#endif /* ATTACKS_CONTROLLERS_FLOODINGATTACK_NTU_FLOODINGATTACK_H_ */
