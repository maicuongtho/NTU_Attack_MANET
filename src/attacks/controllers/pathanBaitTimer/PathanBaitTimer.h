/*
 * PathanBaitTimer.h
 *
 *  Created on: Apr 5, 2020
 *      Author: thomc
 */

#ifndef ATTACKS_CONTROLLERS_PATHANBAITTIMER_PATHANBAITTIMER_H_
#define ATTACKS_CONTROLLERS_PATHANBAITTIMER_PATHANBAITTIMER_H_

#include "NTU_Attack.h"
#include "pathanBaitTimerMessage_m.h"
class PathanBaitTimer: public NTU_Attack {
protected:
       virtual cMessage *generateAttackMessage(const char* name);
};

#endif /* ATTACKS_CONTROLLERS_PATHANBAITTIMER_PATHANBAITTIMER_H_ */
