/*
 * PathanBaitTimer.cc
 *
 *  Created on: Apr 5, 2020
 *      Author: thomc
 */
#include "PathanBaitTimer.h"
#include "pathanBaitTimerMessage_m.h"

Define_Module (PathanBaitTimer);
cMessage *PathanBaitTimer::generateAttackMessage(const char *name) {
    LOG << "PathanBaitTimer: generate Message\n";
    // Generates the specific message with the specific parameters for hacked module
    pathanBaitTimerMessage *msg = new pathanBaitTimerMessage(name);
    return msg;
}


