/*
 * NTU_DroppingAttack.h
 *
 *  Created on: Mar 6, 2020
 *      Author: thomc
 */

#ifndef ATTACKS_CONTROLLERS_DROPPINGATTACK_NTU_DROPPINGATTACK_H_
#define ATTACKS_CONTROLLERS_DROPPINGATTACK_NTU_DROPPINGATTACK_H_
#include "NTU_Attack.h"
#include "NTU_DroppingMessage_m.h"

class NTU_DroppingAttack: public NTU_Attack {

protected:
    /**
     * Overridden function
     */
    virtual cMessage *generateAttackMessage(const char* name);
};

#endif /* ATTACKS_CONTROLLERS_DROPPINGATTACK_NTU_DROPPINGATTACK_H_ */


