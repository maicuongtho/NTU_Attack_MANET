/*
 * hacked_IPv4.cc
 *
 *  Created on: Mar 15, 2021
 *      Author: thomc
 */


#include "hacked_IPv4.h"
#include <iostream>
#include <string.h>

using std::cout;


simsignal_t hacked_IPv4::dropSignal = SIMSIGNAL_NULL;
simsignal_t hacked_IPv4::rcvdPktSignal = SIMSIGNAL_NULL;
simsignal_t hacked_IPv4::delaySignal = SIMSIGNAL_NULL;

Define_Module(hacked_IPv4);
void hacked_IPv4::initialize(int stage) {

    // Dropping attack initialization
    numDrops = 0;
    dropSignal = registerSignal("droppings");
    droppingAttackProbability = 0;
    droppingAttackIsActive =  false;
    droppingPINGdata=false;
    droppingTCPdata=false;
    droppingUDPdata=false;


    // Delay attack initialization
    delayAttackIsActive = false;
    delayAttackProbability = 0;
    numDelays = 0;
    delaySignal = registerSignal("delayed");
    totalDelayTime = 0;
   //

    // Number of data packet received
    numRecvPacket = 0;
    rcvdPktSignal = registerSignal("rcvdPkt");
  //  inet:: QueueBase::initialize();
    Ipv4::initialize(stage);
}

void hacked_IPv4::handleMessageFromAttackController(cMessage *msg) {

    // It is necessary to call Enter_Method for doing context switching (4.10 of User Manual)
    Enter_Method("hacked_IPv4: handle message from attack controller");
    LOG << "hacked_IPv4: Received message: " << msg->getFullName() << "\n";

    /*-------------------------- DROPPING ATTACK -------------------------*/
    if ( not strcmp(msg->getFullName(), "droppingActivate")) {
        NTU_DroppingMessage *dmsg;
        dmsg = check_and_cast<NTU_DroppingMessage *>(msg);
        LOG << "--> Activating module hacked_IPv4 for Dropping Attack...\n";
        LOG << "    Dropping Attack Probability received: "
                << dmsg->getDroppingAttackProbability() << "\n";
        LOG << "    Dropping Ping Data received: "<< dmsg->getDroppingPINGdata() << "\n";
        LOG << "    Dropping UDP Data received: " << dmsg->getDroppingUDPdata() << "\n";
        LOG << "    Dropping TCP Data received: " << dmsg->getDroppingTCPdata() << "\n";
        //Now dropping attack is activated in this module
        droppingAttackIsActive = true;
        droppingAttackProbability = dmsg->getDroppingAttackProbability();
        droppingPINGdata=dmsg->getDroppingPINGdata();
        droppingTCPdata=dmsg->getDroppingTCPdata();
        droppingUDPdata=dmsg->getDroppingUDPdata();
//
//        delete (msg);
      } else if ( not strcmp(msg->getFullName(), "droppingDeactivate")) {
        NTU_DroppingMessage *dmsg;
        dmsg = check_and_cast<NTU_DroppingMessage *>(msg);
        LOG << "Deactivating module NTU_IPv4 for Dropping Attack...\n";
        //Now dropping attack is deactivated
        droppingAttackIsActive = false;
//        delete (msg);
    } else if (not strcmp(msg->getFullName(), "delayActivate")) {
        NTU_DelayMessage *dmsg;
        dmsg = check_and_cast<NTU_DelayMessage *>(msg);
        LOG << "--> Activating module NTU_IPv4 for Delay Attack...\n";
        LOG << "    Delay Attack Probability received: "
                            << dmsg->getDelayAttackProbability() << "\n";
        delayAttackIsActive = true;
        delayAttackProbability = dmsg->getDelayAttackProbability();
    } else if (not strcmp(msg->getFullName(), "delayDeactivate")) {
        NTU_DelayMessage *dmsg;
        dmsg = check_and_cast<NTU_DelayMessage *>(msg);
        LOG << "Deactivating module NT_IPv4 for Delay Attack...\n";
        delayAttackIsActive = false;

        }else
    {
        LOG
                << "ERROR: Message unknown in NTU_IPv4::handleMessageFromAttackController. Msg: "
                << msg->getFullName() << "\n";
    }
 //   delete (msg);
}


/**
     * Overridden function to implement the dropping behavior.
     * First check if the dropping behavior is active. Then check if the received packet is
     * a valid packet to drop (PING, UDP and/or TCP). Finally discard it or not randomly.
     */
 void hacked_IPv4::handleIncomingDatagram(Packet *packet) //
{
    ASSERT(packet);
    /* -------------------------------------------------------------------------------*/
    if ((droppingUDPdata==true)&& (droppingTCPdata==true) && (droppingPINGdata==true)) {
        // Count the number of total data packet received, for statistics.
        if (!strncmp(packet->getName(), PING_DATA, 4) || !strncmp(packet->getName(), UDP_DATA, 3)|| !strncmp(packet->getName(), TCP_DATA, 3)) {
            numRecvPacket++; // The number of packets is updated
            emit(rcvdPktSignal, numRecvPacket); // Sending of the signal indicating that we have received a new data packet.
        }
          //Packet is a ping/UDP/TCP (data packet)
        if (droppingAttackIsActive) {
               LOG << "Received packet after activating dropping attack ... " << "\n";
               if (!strncmp(packet->getName(), PING_DATA, 4) || !strncmp(packet->getName(), UDP_DATA, 3)|| !strncmp(packet->getName(), TCP_DATA, 3))
                   {
                   LOG << "Is a valid packet for dropping ..." << "\n";
                   double ngaunhien =uniform(0,1);
                   if (ngaunhien < droppingAttackProbability) {
                       numDrops++;                  // The number of droppings is updated
                       emit(dropSignal, numDrops); // Sending of the signal indicating a drop
                       LOG << "NTUattack Discarding packet: " << packet->getName() << ": " << numDrops << " dropping times." << endl;
                       cout << simTime() << "NTUattack: Discarding packet: " << packet->getName() << endl;
                       delete packet; //Deletes the packet thus calling its destructor

                   }else {   //uniform else
                       LOG << "NTUattack NOT Discarding packet" << endl;
                        Ipv4::handleIncomingDatagram(packet);
                   }  // uniform
               } else { //Packet is not a data packet --> normal behavior
                   Ipv4::handleIncomingDatagram(packet);
               } // end of if check if it is data packet
            }
         else { // --> Normal behavior., it means droppingAttack Is NOT Active: droppingAttackIsActive==false
          Ipv4::handleIncomingDatagram(packet);
         }
   //---------Dropng UDP and TCP---------------------------------------------------------------------------------/
   }else if ((droppingUDPdata==true)&& (droppingTCPdata==true) && (droppingPINGdata==false)) {
       // Count the number of total data packet received, for statistics.
             if (!strncmp(packet->getName(), UDP_DATA, 3)|| !strncmp(packet->getName(), TCP_DATA, 3)) {
                 numRecvPacket++; // The number of packets is updated
                 emit(rcvdPktSignal, numRecvPacket); // Sending of the signal indicating that we have received a new data packet.
             }
               //Packet is a ping/UDP/TCP (data packet)
             if (droppingAttackIsActive) {
                    LOG << "Received packet after activating dropping attack ... " << "\n";
                    if (!strncmp(packet->getName(), UDP_DATA, 3)|| !strncmp(packet->getName(), TCP_DATA, 3))
                        {
                        LOG << "Is a valid packet for dropping ..." << "\n";
                        if (uniform(0, 1) < droppingAttackProbability) {
                            numDrops++; // The number of droppings is updated
                            emit(dropSignal, numDrops); // Sending of the signal indicating a drop
                            LOG << "Discarding packet: " << packet->getName() << ": " << numDrops << " dropping times." << endl;
                            cout << simTime() << ": Discarding packet: " << packet->getName() << endl;
                            delete packet; //Deletes the packet thus calling its destructor

                        }else {   //uniform else
                            Ipv4::handleIncomingDatagram(packet);
                        }  // uniform
                    } else { //Packet is not a data packet --> normal behavior
                        Ipv4::handleIncomingDatagram(packet);
                    } // end of if check if it is data packet
                 }
              else { // --> Normal behavior., it means droppingAttack Is NOT Active: droppingAttackIsActive==false
               Ipv4::handleIncomingDatagram(packet);
              }
    //-------
   }else  if ((droppingUDPdata==true)&& (droppingTCPdata==false) && (droppingPINGdata==true)) {
       // Count the number of total data packet received, for statistics.
             if (!strncmp(packet->getName(), PING_DATA, 4) || !strncmp(packet->getName(), UDP_DATA, 3)) {
                 numRecvPacket++; // The number of packets is updated
                 emit(rcvdPktSignal, numRecvPacket); // Sending of the signal indicating that we have received a new data packet.
             }
               //Packet is a ping/UDP/TCP (data packet)
             if (droppingAttackIsActive) {
                    LOG << "Received packet after activating dropping attack ... " << "\n";
                    if (!strncmp(packet->getName(), PING_DATA, 4) || !strncmp(packet->getName(), UDP_DATA, 3))
                        {
                        LOG << "Is a valid packet for dropping ..." << "\n";
                        if (uniform(0, 1) < droppingAttackProbability) {
                            numDrops++; // The number of droppings is updated
                            emit(dropSignal, numDrops); // Sending of the signal indicating a drop
                            LOG << "Discarding packet: " << packet->getName() << ": " << numDrops << " dropping times." << endl;
                            cout << simTime() << ": Discarding packet: " << packet->getName() << endl;
                            delete packet; //Deletes the packet thus calling its destructor

                        }else {   //uniform else
                            Ipv4::handleIncomingDatagram(packet);
                        }  // uniform
                    } else { //Packet is not a data packet --> normal behavior
                        Ipv4::handleIncomingDatagram(packet);
                    } // end of if check if it is data packet
                 }
              else { // --> Normal behavior., it means droppingAttack Is NOT Active: droppingAttackIsActive==false
               Ipv4::handleIncomingDatagram(packet);
              }
   //------------------------------------
   }else  if ((droppingUDPdata==true)&& (droppingTCPdata==false) && (droppingPINGdata==false)) {
       // Count the number of total data packet received, for statistics.
             if (!strncmp(packet->getName(), UDP_DATA, 3)) {
                 numRecvPacket++; // The number of packets is updated
                 emit(rcvdPktSignal, numRecvPacket); // Sending of the signal indicating that we have received a new data packet.
             }
               //Packet is a ping/UDP/TCP (data packet)
             if (droppingAttackIsActive) {
                    LOG << "Received packet after activating dropping attack ... " << "\n";
                    if (!strncmp(packet->getName(), UDP_DATA, 3))
                        {
                        LOG << "Is a valid packet for dropping ..." << "\n";
                        if (uniform(0, 1) < droppingAttackProbability) {
                            numDrops++; // The number of droppings is updated
                            emit(dropSignal, numDrops); // Sending of the signal indicating a drop
                            LOG << "Discarding packet: " << packet->getName() << ": " << numDrops << " dropping times." << endl;
                            cout << simTime() << ": Discarding packet: " << packet->getName() << endl;
                            delete packet; //Deletes the packet thus calling its destructor

                        }else {   //uniform else
                            Ipv4::handleIncomingDatagram(packet);
                        }  // uniform
                    } else { //Packet is not a data packet --> normal behavior
                        Ipv4::handleIncomingDatagram(packet);
                    } // end of if check if it is data packet
                 }
              else { // --> Normal behavior., it means droppingAttack Is NOT Active: droppingAttackIsActive==false
               Ipv4::handleIncomingDatagram(packet);}
   }else  if ((droppingUDPdata==false)&& (droppingTCPdata==true) && (droppingPINGdata==true)) {
       // Count the number of total data packet received, for statistics.
             if (!strncmp(packet->getName(), PING_DATA, 4) || !strncmp(packet->getName(), TCP_DATA, 3)) {
                 numRecvPacket++; // The number of packets is updated
                 emit(rcvdPktSignal, numRecvPacket); // Sending of the signal indicating that we have received a new data packet.
             }
               //Packet is a ping/UDP/TCP (data packet)
             if (droppingAttackIsActive) {
                    LOG << "Received packet after activating dropping attack ... " << "\n";
                    if (!strncmp(packet->getName(), PING_DATA, 4) ||!strncmp(packet->getName(), TCP_DATA, 3))
                        {
                        LOG << "Is a valid packet for dropping ..." << "\n";
                        if (uniform(0, 1) < droppingAttackProbability) {
                            numDrops++; // The number of droppings is updated
                            emit(dropSignal, numDrops); // Sending of the signal indicating a drop
                            LOG << "Discarding packet: " << packet->getName() << ": " << numDrops << " dropping times." << endl;
                            cout << simTime() << ": Discarding packet: " << packet->getName() << endl;
                            delete packet; //Deletes the packet thus calling its destructor

                        }else {   //uniform else
                            Ipv4::handleIncomingDatagram(packet);
                        }  // uniform
                    } else { //Packet is not a data packet --> normal behavior
                        Ipv4::handleIncomingDatagram(packet);
                    } // end of if check if it is data packet
                 }
              else { // --> Normal behavior., it means droppingAttack Is NOT Active: droppingAttackIsActive==false
               Ipv4::handleIncomingDatagram(packet);}
   }else  if ((droppingUDPdata==false)&& (droppingTCPdata==true) && (droppingPINGdata==false)) {
       // Count the number of total data packet received, for statistics.
             if (!strncmp(packet->getName(), TCP_DATA, 3)) {
                 numRecvPacket++; // The number of packets is updated
                 emit(rcvdPktSignal, numRecvPacket); // Sending of the signal indicating that we have received a new data packet.
             }
               //Packet is a ping/UDP/TCP (data packet)
             if (droppingAttackIsActive) {
                    LOG << "Received packet after activating dropping attack ... " << "\n";
                    if (!strncmp(packet->getName(), TCP_DATA, 3))
                        {
                        LOG << "Is a valid packet for dropping ..." << "\n";
                        if (uniform(0, 1) < droppingAttackProbability) {
                            numDrops++; // The number of droppings is updated
                            emit(dropSignal, numDrops); // Sending of the signal indicating a drop
                            LOG << "Discarding packet: " << packet->getName() << ": " << numDrops << " dropping times." << endl;
                            cout << simTime() << ": Discarding packet: " << packet->getName() << endl;
                            delete packet; //Deletes the packet thus calling its destructor

                        }else {   //uniform else
                            Ipv4::handleIncomingDatagram(packet);
                        }  // uniform
                    } else { //Packet is not a data packet --> normal behavior
                        Ipv4::handleIncomingDatagram(packet);
                    } // end of if check if it is data packet
                 }
              else { // --> Normal behavior., it means droppingAttack Is NOT Active: droppingAttackIsActive==false
               Ipv4::handleIncomingDatagram(packet);}
   } else  if ((droppingUDPdata==false)&& (droppingTCPdata==false) && (droppingPINGdata==true)) {
       // Count the number of total data packet received, for statistics.
             if (!strncmp(packet->getName(), PING_DATA, 4)) {
                 numRecvPacket++; // The number of packets is updated
                 emit(rcvdPktSignal, numRecvPacket); // Sending of the signal indicating that we have received a new data packet.
             }
               //Packet is a ping/UDP/TCP (data packet)
             if (droppingAttackIsActive) {
                    LOG << "Received packet after activating dropping attack ... " << "\n";
                    if (!strncmp(packet->getName(), PING_DATA, 4))
                        {
                        LOG << "Is a valid packet for dropping ..." << "\n";
                        if (uniform(0, 1) < droppingAttackProbability) {
                            numDrops++; // The number of droppings is updated
                            emit(dropSignal, numDrops); // Sending of the signal indicating a drop
                            LOG << "Discarding packet: " << packet->getName() << ": " << numDrops << " dropping times." << endl;
                            cout << simTime() << ": Discarding packet: " << packet->getName() << endl;
                            delete packet; //Deletes the packet thus calling its destructor

                        }else {   //uniform else
                            Ipv4::handleIncomingDatagram(packet);
                        }  // uniform
                    } else { //Packet is not a data packet --> normal behavior
                        Ipv4::handleIncomingDatagram(packet);
                    } // end of if check if it is data packet
                 }
              else { // --> Normal behavior., it means droppingAttack Is NOT Active: droppingAttackIsActive==false
               Ipv4::handleIncomingDatagram(packet);}
   }else

       Ipv4::handleIncomingDatagram(packet);

  //000x,001,010,011,100,101,110,111
}



 void hacked_IPv4::sendPacketToNIC(Packet *packet)
 {
     if(delayAttackIsActive){
         if (!strncmp(packet->getName(), PING_DATA, 4) || !strncmp(packet->getName(), UDP_DATA, 3))
         {
             if (uniform(0, 1) < delayAttackProbability) {
                 packet->addTagIfAbsent<PacketProtocolTag>()->setProtocol(&Protocol::ipv4);
                 packet->addTagIfAbsent<DispatchProtocolInd>()->setProtocol(&Protocol::ipv4);
                 delete packet->removeTagIfPresent<DispatchProtocolReq>();
                 ASSERT(packet->findTag<InterfaceReq>() != nullptr);
                 sendDelayed(packet,0.1, "queueOut");
                 EV_INFO << "DELAY_END:"<<  simTime() <<endl;
                 return;
             }
          }
      }
     Ipv4::sendPacketToNIC(packet);
 }
