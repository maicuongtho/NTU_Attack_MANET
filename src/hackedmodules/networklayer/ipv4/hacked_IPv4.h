/*
 * hacked_IPv4.h
 *
 *  Created on: Mar 15, 2021
 *      Author: thomc
 */

#ifndef HACKEDMODULES_NETWORKLAYER_IPV4_HACKED_IPV4_H_
#define HACKEDMODULES_NETWORKLAYER_IPV4_HACKED_IPV4_H_

#include <Ipv4.h>
#include <omnetpp.h>
#include "NA_NesgLog.h"
#include "NTU_HackedModule.h"
#include "NTU_DroppingMessage_m.h"
#include "NTU_DelayMessage_m.h"

#define TCP_DATA "TCP"
#define UDP_DATA "UDP"
#define PING_DATA "ping"

/**
 * @brief Dropping attack hacked module
 *
 * @details This hacked module is in charge of implement the dropping behavior on
 * IP layer. When this module receive a dropping control message from the controller
 * this activate or deactivate the dropping behavior. The packets are discarded randomly
 * following a normal distribution with a @verbatim droppingAttackProbability @endverbatim
 * probability.
 *
 * Implemented attacks:
 * - Dropping
 * - Delay
 *
 * @see NTU_HackedModule, NTU_DroppingAttack
  *
 */
using namespace inet;
using namespace omnetpp;
class INET_API hacked_IPv4 : public Ipv4, public NTU_HackedModule {
private:

    /**
     * Log reference
     */
    NA_NesgLog log;
    /*----------------- grayhole  -------------------------*/
    bool UdpButNotTCP;
    bool droppingPINGdata;
    bool droppingTCPdata;
    bool droppingUDPdata;

    /*----------------- DROPPING ATTACK  -------------------------*/
    /**
     * Flag to activate dropping attack
     */
    bool droppingAttackIsActive;

    /**
     * Probability for dropping packets when dropping attack is active
     */
    double droppingAttackProbability;

    /**
     * Count the number of packet discarded. For dropping statistics
     */
    long numDrops;


    /*----------------- DELAY ATTACK  -------------------------*/
    /**
     * Flag to activate delay attack
     */
    bool delayAttackIsActive;

    /**
     * Probability for delaying a packet
     */
    double delayAttackProbability;

    /**
     * Number of packets delayed. For statistics
     */
    long numDelays;

    /**
     * Accumulated delay time for all the packets delayed. For statistics
     */
    long totalDelayTime;

    /**
     * DelayValue for the simulation. Implemented as a pointer to allow functions as values
     */
    double delayAttackValue;

    /*---------------------OTHERs-------------------------------*/
    /**
     * Number of data packet received by the host.
     */
    long numRecvPacket;

public:

    /**
     * Overridden function
     */
    void handleMessageFromAttackController(cMessage *msg);

protected:

    /**
     * Method from cSimpleModule class, to initialize the simple module.
     * Overridden function.
     */
    virtual void initialize(int stage);


    /*----------------- DROPPING ATTACK  -------------------------*/
    /**
     * Drop signal for statistics
     */
    static simsignal_t dropSignal;

    /**
     * Overridden function to implement the dropping behavior.
     * First check if the dropping behavior is active. Then check if the received packet is
     * a valid packet to drop (PING, UDP and/or TCP). Finally discard it or not randomly.
     */
  //  virtual void handlePacketFromNetwork(IPv4Datagram *datagram, InterfaceEntry *fromIE);
  //  virtual void handlePacketFromHL(Packet *packet);  // by thomc
    virtual void handleIncomingDatagram(Packet *packet);
    /*----------------- DELAY ATTACK  -------------------------*/
    /**
     * Overridden function to implement the delay behavior.
     * First check if the delay behavior is active. Then check if the received packet is
     * a valid packet to delay (PING, UDP and/or TCP). Finally add a delay time in a random way.
     */
    virtual void sendPacketToNIC(Packet *packet);
    //virtual void sendDatagramToOutput(Packet *packet);

    /**
     * Delay signal for statistics
     */
    static simsignal_t delaySignal;

    /*------------------OTHERs ---------------------------------*/
    /**
     * Packet received signal for statistics.
     */
    static simsignal_t rcvdPktSignal;



};


#endif /* HACKEDMODULES_NETWORKLAYER_IPV4_HACKED_IPV4_H_ */
