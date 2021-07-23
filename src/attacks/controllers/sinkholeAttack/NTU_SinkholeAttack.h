/*
 * NTU_SinkholeAttack.h
 *
 *  Created on: Mar 9, 2020
 *      Author: thomc
 */

/**
 * @brief Sinkhole attack controller implementation
 *
 * @details This controller generates the specific control message (sinkhole message) containing
 * the relevant information for the hacked modules affected by the attack.
 * In this case NTU_IPv4.
 *
 */
#ifndef ATTACKS_CONTROLLERS_SINKHOLEATTACK_NTU_SINKHOLEATTACK_H_
#define ATTACKS_CONTROLLERS_SINKHOLEATTACK_NTU_SINKHOLEATTACK_H_

#include "NTU_Attack.h"
#include "NTU_SinkholeMessage_m.h"
class NTU_SinkholeAttack: public NTU_Attack {
protected:
    /**
     * Overridden function
     */
    virtual cMessage *generateAttackMessage(const char* name);
};

#endif /* ATTACKS_CONTROLLERS_SINKHOLEATTACK_NTU_SINKHOLEATTACK_H_ */
