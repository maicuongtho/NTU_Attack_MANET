
#include "NTU_DroppingAttack.h"
#include "NTU_DroppingMessage_m.h"

Define_Module (NTU_DroppingAttack);

cMessage *NTU_DroppingAttack::generateAttackMessage(const char *name) {

    LOG << "NTU_DroppingAttack: generateAttackMessage\n";

    NTU_DroppingMessage *msg = new NTU_DroppingMessage(name);
    msg->setDroppingAttackProbability(par("droppingAttackProbability").doubleValue());
    msg->setDroppingPINGdata(par("droppingPINGdata").boolValue());
    msg->setDroppingTCPdata(par("droppingTCPdata").boolValue());
    msg->setDroppingUDPdata(par("droppingUDPdata").boolValue());
    return msg;
}



