/*
 * NTU_Attack.cc
 *
 *  Created on: Mar 6, 2020
 *      Author: thomc
 */
#include "NTU_Attack.h"
#include "NA_NesgLog.h"
#include "NTU_HackedModule.h"
//#include "NA_IPv4.h"

Define_Module (NTU_Attack);

void NTU_Attack::initialize() {

    // Get the type of attack to be launched
    attackType = (char*) par(NTU_ATTACK_TYPE).stringValue();
    LOG << "KiemTraKHOITAO: " <<attackType <<endl;

    // Activate the attack only if defined in the active parameter in module (.ned)
    if (par(NTU_ATTACK_ACTIVE).boolValue() == true) {

        getAttackModules();
        scheduleAttack();
    }
}

void NTU_Attack::getAttackModules() {
    cTopology topo; //Used to discover the topology of the node and find modules for activating the attack
    cTopology::Node *node;
    string nodeName;

    // extract all modules with the @attackType property set in the simulation
    topo.extractByProperty(par(NTU_ATTACK_TYPE).stringValue());

    LOG << "------------------------------------\n";
    LOG << "Found " << topo.getNumNodes() << " possible modules for attack\n";
    LOG << "------------------------------------\n";

    // Now, only the modules contained in the parent module of this NA_Attack object are activated.
    string prefix = this->getParentModule()->getFullPath(); // First we get the full path of the parent node
    int numModules = 0;
    for (int i = 0; i < topo.getNumNodes(); i++) {
        node = topo.getNode(i);
        nodeName = node->getModule()->getFullPath();
        if (not nodeName.compare(0, prefix.size(), prefix)) {

            LOG << "--->Inserting module in list: " << nodeName << "\n";
            modList.push_back(node->getModule());
            numModules++;
        }
    }
    LOG << "-----------------------------------\n";
    LOG << "Inserted " << numModules << " modules in list\n";
    LOG << "-----------------------------------\n";
}

void NTU_Attack::scheduleAttack() {
    cMessage *msg = new cMessage(NTU_ATTACK_START_MESSAGE);
    LOG << "Scheduling the attack \n";
    scheduleAt(par(NTU_ATTACK_START_TIME).doubleValue(), msg);
    if (par("endTime").doubleValue()) //When the value differs from 0
    {
        cMessage *msgEnd = new cMessage(NTU_ATTACK_END_MESSAGE);
        scheduleAt(par(NTU_ATTACK_END_TIME).doubleValue(), msgEnd);
    }
}

void NTU_Attack::handleMessage(cMessage *msg) {
    LOG << "Message received: " << msg->getFullName() << "\n";
    if (not strcmp(msg->getFullName(), NTU_ATTACK_START_MESSAGE)) {
        activateModules();
    } else {
        deactivateModules();
    }
    delete (msg);
}

void NTU_Attack::activateModules() {
    char msgCaption[30];

    // Concatenate the <attackType> + Activate
    opp_strcpy(msgCaption, attackType);
    strcat(msgCaption, NTU_ATTACK_ACTIVATE_TAG);

    // Generate the specific attack controller message.
    // This method belongs to the specific attack controller.
    cMessage *msg = check_and_cast<cMessage *>(
            generateAttackMessage(msgCaption));
    EV << "\n\n";
    LOG << "-----------------------------------\n";
    LOG << "ACTIVATING HACKED MODULES\n";
    LOG << "-----------------------------------\n";

    sendMessageToHackedModules(msg);
}

void NTU_Attack::deactivateModules() {

    char msgCaption[30];

    // Concatenate the <attackType> + Activate
    opp_strcpy(msgCaption, attackType);
    strcat(msgCaption, NTU_ATTACK_DEACTIVATE_TAG);

    // Generate the specific attack controller message.
    // This method belongs to the specific attack controller.
    cMessage *msg = check_and_cast<cMessage *>(
            generateAttackMessage(msgCaption));

    EV << "\n\n";
    LOG << "-----------------------------------\n";
    LOG << "DEACTIVATING HACKED MODULES\n";
    LOG << "-----------------------------------\n";

    sendMessageToHackedModules(msg);
}

void NTU_Attack::sendMessageToHackedModules(cMessage *msg) {

    unsigned int i;
    NTU_HackedModule *modHacked;
    LOG << "SoLuongMoDun: " << modList.size() <<endl;
    for (i = 0; i < modList.size(); i++) {
        LOG << "Module: " << modList[i]->getFullPath() << "\n";
        if (modList[i]->isSimple()) { // Activation is only done in simple modules (implemented in C++ classes).

            modHacked = dynamic_cast<NTU_HackedModule *>(modList[i]);

            LOG << "--> Sending message: " << msg->getFullName() << "\n";
            // Send the message to the specific hacked module
            modHacked->handleMessageFromAttackController(msg);
        } else {
            LOG << "--> Message not sent. Not a simple module.\n";
        }
    }
    //LOG << "--> Sending message: " << msg->getFullName() << "\n";
    LOG << "-----------------------------------\n";
}

cMessage *NTU_Attack::generateAttackMessage(const char *name) {

    LOG << "ERROR: EN NTU_ATTACK GENERATE ATTACK MESSAGE\n";
    cMessage *msg = new cMessage(name);
    return msg;
}



