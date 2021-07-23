/*
 * NTU_BlackholeAttack.cc
 *
 *  Created on: Mar 14, 2020
 *      Author: thomc
 */
#include "NTU_BlackholeAttack.h"
#include "NTU_BlackholeMessage_m.h"

Define_Module (NTU_BlackholeAttack);
cMessage *NTU_BlackholeAttack::generateAttackMessage(const char *name) {
    LOG << "NTU_BlackholeAttack: generate Attack Message\n";
    // Generates the specific message with the specific parameters for hacked module
    NTU_BlackholeMessage *msg = new NTU_BlackholeMessage(name);
    msg->setBlackholeAttackProbability(par("blackholeAttackProbability").doubleValue());
    msg->setBlackOnlyWhenRouteInTable(par("blackOnlyWhenRouteInTable").boolValue());
    msg->setSeqnoAdded(par("seqnoAdded").doubleValue());
    msg->setNumHops(par("numHops").intValue());
    return msg;
}



