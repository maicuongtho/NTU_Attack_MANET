/*
 * hacked_IPv4NetworkLayer.cc
 *
 *  Created on: Mar 15, 2021
 *      Author: thomc
 */

#include "inet/common/StringFormat.h"
#include "hacked_IPv4NetworkLayer.h"
Define_Module(hacked_IPv4NetworkLayer);

void hacked_IPv4NetworkLayer::refreshDisplay() const
{
    updateDisplayString();
}

void hacked_IPv4NetworkLayer::updateDisplayString() const
{
    auto text = inet::StringFormat::formatString(par("displayStringTextFormat"), [&] (char directive) {
        static std::string result;
        switch (directive) {
            case 'i':
                result = getSubmodule("ip")->getDisplayString().getTagArg("t", 0);
                break;
            default:
                throw cRuntimeError("Unknown directive: %c", directive);
        }
        return result.c_str();
    });
    getDisplayString().setTagArg("t", 0, text);
}

void hacked_IPv4NetworkLayer::handleMessageFromAttackController(cMessage *msg){
    Enter_Method("hacked_IPv4: handle message from attack controller");

}
