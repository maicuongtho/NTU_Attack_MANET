/*
 * NTU_GrayholeAttack.cc
 *
 *  Created on: Mar 12, 2020
 *      Author: thomc
 */
#include "NTU_GrayholeAttack.h"
#include "NTU_GrayholeMessage_m.h"

Define_Module (NTU_GrayholeAttack);
cMessage *NTU_GrayholeAttack::generateAttackMessage(const char *name) {
    LOG << "NTU_GrayholeAttack: generateAttackMessage\n";
    NTU_GrayholeMessage *msg = new NTU_GrayholeMessage(name);
    msg->setGrayholeAttackProbability(par("grayholeAttackProbability").doubleValue());
    msg->setGrayOnlyWhenRouteInTable(par("grayOnlyWhenRouteInTable").boolValue());
    msg->setSeqnoAdded(par("seqnoAdded").doubleValue());
    msg->setNumHops(par("numHops").intValue());
    return msg;
}



