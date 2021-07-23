/*
 * NTU_FloodingAttack.cc
 *
 *  Created on: Mar 21, 2021
 *      Author: thomc
 */
#include "NTU_FloodingAttack.h"


Define_Module (NTU_FloodingAttack);

cMessage *NTU_FloodingAttack::generateAttackMessage(const char *name) {

    LOG << "NTU_Flooding Attack: generateAttackMessage\n";

    // Specific message for the specifics hacked modules.
    NTU_FloodingM *msg = new NTU_FloodingM(name);
    msg->setIsDataFlooding(par("isDataFlooding").boolValue());
    msg->setIsHelloFlooding(par("isHelloFlooding").boolValue());
    msg->setIsRreqFlooding(par("isRreqFlooding").boolValue());

    msg->setInterval_DataFlooing(par("Interval_DataFlooing").doubleValue());
    msg->setInterval_HelloFlooing(par("Interval_DataFlooing").doubleValue());
    msg->setInterval_RreqFlooing(par("Interval_DataFlooing").doubleValue());
//    msg->setDroppingAttackProbability(par("droppingAttackProbability").doubleValue());
//    msg->setDroppingPINGdata(par("droppingPINGdata").boolValue());
//    msg->setDroppingTCPdata(par("droppingTCPdata").boolValue());
//    msg->setDroppingUDPdata(par("droppingUDPdata").boolValue());
    return msg;
}



