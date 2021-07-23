//
// Generated file, do not edit! Created by nedtool 5.6 from attacks/controlmessages/blackholeAttack/NTU_BlackholeMessage.msg.
//

#ifndef __NTU_BLACKHOLEMESSAGE_M_H
#define __NTU_BLACKHOLEMESSAGE_M_H

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
 * Class generated from <tt>attacks/controlmessages/blackholeAttack/NTU_BlackholeMessage.msg:19</tt> by nedtool.
 * <pre>
 * //
 * // TODO generated message class
 * //
 * message NTU_BlackholeMessage
 * {
 *     bool blackOnlyWhenRouteInTable; 	// TRUE indicates that only RREQ for routes that are in routing table are answered as the best route across the sink node.
 *     									// A false value indicates that all the sinkhole node will answer to all the RREQ with fake routes. 
 *     double blackholeAttackProbability;  //Probability for announcing a fake route when a RREQ is received. Value in [0,1]
 *     double seqnoAdded; 					// Sequence number.
 *     int numHops;
 * }
 * </pre>
 */
class NTU_BlackholeMessage : public ::omnetpp::cMessage
{
  protected:
    bool blackOnlyWhenRouteInTable;
    double blackholeAttackProbability;
    double seqnoAdded;
    int numHops;

  private:
    void copy(const NTU_BlackholeMessage& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const NTU_BlackholeMessage&);

  public:
    NTU_BlackholeMessage(const char *name=nullptr, short kind=0);
    NTU_BlackholeMessage(const NTU_BlackholeMessage& other);
    virtual ~NTU_BlackholeMessage();
    NTU_BlackholeMessage& operator=(const NTU_BlackholeMessage& other);
    virtual NTU_BlackholeMessage *dup() const override {return new NTU_BlackholeMessage(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
    virtual bool getBlackOnlyWhenRouteInTable() const;
    virtual void setBlackOnlyWhenRouteInTable(bool blackOnlyWhenRouteInTable);
    virtual double getBlackholeAttackProbability() const;
    virtual void setBlackholeAttackProbability(double blackholeAttackProbability);
    virtual double getSeqnoAdded() const;
    virtual void setSeqnoAdded(double seqnoAdded);
    virtual int getNumHops() const;
    virtual void setNumHops(int numHops);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const NTU_BlackholeMessage& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, NTU_BlackholeMessage& obj) {obj.parsimUnpack(b);}


#endif // ifndef __NTU_BLACKHOLEMESSAGE_M_H
