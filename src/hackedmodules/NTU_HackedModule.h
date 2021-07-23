/*
 * NTU_HackedModule.h
 *
 *  Created on: Mar 6, 2020
 *      Author: thomc
 */

#ifndef HACKEDMODULES_NTU_HACKEDMODULE_H_
#define HACKEDMODULES_NTU_HACKEDMODULE_H_
#include "NA_NesgLog.h"
class NTU_HackedModule {
    private:
        /**
         * Log reference
         */
    NA_NesgLog log;
    public:
        /**
         * This method is in charge of to receive the control message from the attack controller.
         * Depending of the message information, this method sets the specific hacked module properties
         * to allow the attack behavior or not.
         *
         * This method must be overridden for all hacked modules.
         *
         * @param msg cMessage the received message from attack controller
         */
        virtual void handleMessageFromAttackController(cMessage *msg);

};



#endif /* HACKEDMODULES_NTU_HACKEDMODULE_H_ */
