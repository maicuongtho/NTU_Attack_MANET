//
// Generated file, do not edit! Created by nedtool 5.6 from attacks/controlmessages/sinkholeAttack/NTU_SinkholeMessage.msg.
//

#ifndef __NTU_SINKHOLEMESSAGE_M_H
#define __NTU_SINKHOLEMESSAGE_M_H

#if defined(__clang__)
#  pragma clang diagnostic ignored "-Wreserved-id-macro"
#endif
#include <omnetpp.h>

// nedtool version check
#define MSGC_VERSION 0x0506
#if (MSGC_VERSION!=OMNETPP_VERSION)
#    error Version mismatch! Probably this file was generated by an earlier version of nedtool: 'make clean' should help.
#endif



/**
 * Class generated from <tt>attacks/controlmessages/sinkholeAttack/NTU_SinkholeMessage.msg:9</tt> by nedtool.
 * <pre>
 * //
 * // Message interchanged between sinkhole attack controller and the corresponding hacked
 * // modules. In this case NA_AODV
 * //
 * // \@see NTU_SinkholeAttack, NTU_AODV
 * //
 * // \@author thomc
 * // \@date 10/3/2020
 * message NTU_SinkholeMessage
 * {
 *     bool sinkOnlyWhenRouteInTable; 	// TRUE indicates that only RREQ for routes that are in routing table are answered as the best route across the sink node.
 *     								// A false value indicates that all the sinkhole node will answer to all the RREQ with fake routes. 
 *     double sinkholeAttackProbability;  	//Probability for announcing a fake route when a RREQ is received. Value in [0,1]
 *     double seqnoAdded; 					// Sequence number.
 *     int numHops;
 * }
 * </pre>
 */
class NTU_SinkholeMessage : public ::omnetpp::cMessage
{
  protected:
    bool sinkOnlyWhenRouteInTable;
    double sinkholeAttackProbability;
    double seqnoAdded;
    int numHops;

  private:
    void copy(const NTU_SinkholeMessage& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const NTU_SinkholeMessage&);

  public:
    NTU_SinkholeMessage(const char *name=nullptr, short kind=0);
    NTU_SinkholeMessage(const NTU_SinkholeMessage& other);
    virtual ~NTU_SinkholeMessage();
    NTU_SinkholeMessage& operator=(const NTU_SinkholeMessage& other);
    virtual NTU_SinkholeMessage *dup() const override {return new NTU_SinkholeMessage(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
    virtual bool getSinkOnlyWhenRouteInTable() const;
    virtual void setSinkOnlyWhenRouteInTable(bool sinkOnlyWhenRouteInTable);
    virtual double getSinkholeAttackProbability() const;
    virtual void setSinkholeAttackProbability(double sinkholeAttackProbability);
    virtual double getSeqnoAdded() const;
    virtual void setSeqnoAdded(double seqnoAdded);
    virtual int getNumHops() const;
    virtual void setNumHops(int numHops);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const NTU_SinkholeMessage& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, NTU_SinkholeMessage& obj) {obj.parsimUnpack(b);}


#endif // ifndef __NTU_SINKHOLEMESSAGE_M_H
