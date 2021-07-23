/*
 * NTU_SinkholeAttack.cc
 *
 *  Created on: Mar 9, 2020
 *      Author: thomc
 */
#include "NTU_SinkholeAttack.h"
#include "NTU_SinkholeMessage_m.h"

Define_Module (NTU_SinkholeAttack);
cMessage *NTU_SinkholeAttack::generateAttackMessage(const char *name) {
    LOG << "NTU_SinkholeAttack: generate Attack Message\n";
    // Generates the specific message with the specific parameters for hacked module
    NTU_SinkholeMessage *msg = new NTU_SinkholeMessage(name);
    msg->setSinkholeAttackProbability(par("sinkholeAttackProbability").doubleValue());
    msg->setSinkOnlyWhenRouteInTable(par("sinkOnlyWhenRouteInTable").boolValue());
    msg->setSeqnoAdded(par("seqnoAdded").doubleValue());
    msg->setNumHops(par("numHops").intValue());
    return msg;
}


