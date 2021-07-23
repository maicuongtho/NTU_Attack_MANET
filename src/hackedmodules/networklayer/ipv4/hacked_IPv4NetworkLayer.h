/*
 * hacked_IPv4NetworkLayer.h
 *
 *  Created on: Mar 15, 2021
 *      Author: thomc
 */

#ifndef HACKEDMODULES_NETWORKLAYER_IPV4_HACKED_IPV4NETWORKLAYER_H_
#define HACKEDMODULES_NETWORKLAYER_IPV4_HACKED_IPV4NETWORKLAYER_H_
#include "inet/common/INETDefs.h"
#include "NTU_HackedModule.h"
class INET_API hacked_IPv4NetworkLayer : public cModule, public NTU_HackedModule
{
    public:
            /**
            * Overridden function
            */
       void handleMessageFromAttackController(cMessage *msg);
  protected:
    virtual void refreshDisplay() const override;
    virtual void updateDisplayString() const;
};





#endif /* HACKEDMODULES_NETWORKLAYER_IPV4_HACKED_IPV4NETWORKLAYER_H_ */
