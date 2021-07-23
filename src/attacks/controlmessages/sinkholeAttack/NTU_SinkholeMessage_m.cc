//
// Generated file, do not edit! Created by nedtool 5.6 from attacks/controlmessages/sinkholeAttack/NTU_SinkholeMessage.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#if defined(__clang__)
#  pragma clang diagnostic ignored "-Wshadow"
#  pragma clang diagnostic ignored "-Wconversion"
#  pragma clang diagnostic ignored "-Wunused-parameter"
#  pragma clang diagnostic ignored "-Wc++98-compat"
#  pragma clang diagnostic ignored "-Wunreachable-code-break"
#  pragma clang diagnostic ignored "-Wold-style-cast"
#elif defined(__GNUC__)
#  pragma GCC diagnostic ignored "-Wshadow"
#  pragma GCC diagnostic ignored "-Wconversion"
#  pragma GCC diagnostic ignored "-Wunused-parameter"
#  pragma GCC diagnostic ignored "-Wold-style-cast"
#  pragma GCC diagnostic ignored "-Wsuggest-attribute=noreturn"
#  pragma GCC diagnostic ignored "-Wfloat-conversion"
#endif

#include <iostream>
#include <sstream>
#include "NTU_SinkholeMessage_m.h"

namespace omnetpp {

// Template pack/unpack rules. They are declared *after* a1l type-specific pack functions for multiple reasons.
// They are in the omnetpp namespace, to allow them to be found by argument-dependent lookup via the cCommBuffer argument

// Packing/unpacking an std::vector
template<typename T, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::vector<T,A>& v)
{
    int n = v.size();
    doParsimPacking(buffer, n);
    for (int i = 0; i < n; i++)
        doParsimPacking(buffer, v[i]);
}

template<typename T, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::vector<T,A>& v)
{
    int n;
    doParsimUnpacking(buffer, n);
    v.resize(n);
    for (int i = 0; i < n; i++)
        doParsimUnpacking(buffer, v[i]);
}

// Packing/unpacking an std::list
template<typename T, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::list<T,A>& l)
{
    doParsimPacking(buffer, (int)l.size());
    for (typename std::list<T,A>::const_iterator it = l.begin(); it != l.end(); ++it)
        doParsimPacking(buffer, (T&)*it);
}

template<typename T, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::list<T,A>& l)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i=0; i<n; i++) {
        l.push_back(T());
        doParsimUnpacking(buffer, l.back());
    }
}

// Packing/unpacking an std::set
template<typename T, typename Tr, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::set<T,Tr,A>& s)
{
    doParsimPacking(buffer, (int)s.size());
    for (typename std::set<T,Tr,A>::const_iterator it = s.begin(); it != s.end(); ++it)
        doParsimPacking(buffer, *it);
}

template<typename T, typename Tr, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::set<T,Tr,A>& s)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i=0; i<n; i++) {
        T x;
        doParsimUnpacking(buffer, x);
        s.insert(x);
    }
}

// Packing/unpacking an std::map
template<typename K, typename V, typename Tr, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::map<K,V,Tr,A>& m)
{
    doParsimPacking(buffer, (int)m.size());
    for (typename std::map<K,V,Tr,A>::const_iterator it = m.begin(); it != m.end(); ++it) {
        doParsimPacking(buffer, it->first);
        doParsimPacking(buffer, it->second);
    }
}

template<typename K, typename V, typename Tr, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::map<K,V,Tr,A>& m)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i=0; i<n; i++) {
        K k; V v;
        doParsimUnpacking(buffer, k);
        doParsimUnpacking(buffer, v);
        m[k] = v;
    }
}

// Default pack/unpack function for arrays
template<typename T>
void doParsimArrayPacking(omnetpp::cCommBuffer *b, const T *t, int n)
{
    for (int i = 0; i < n; i++)
        doParsimPacking(b, t[i]);
}

template<typename T>
void doParsimArrayUnpacking(omnetpp::cCommBuffer *b, T *t, int n)
{
    for (int i = 0; i < n; i++)
        doParsimUnpacking(b, t[i]);
}

// Default rule to prevent compiler from choosing base class' doParsimPacking() function
template<typename T>
void doParsimPacking(omnetpp::cCommBuffer *, const T& t)
{
    throw omnetpp::cRuntimeError("Parsim error: No doParsimPacking() function for type %s", omnetpp::opp_typename(typeid(t)));
}

template<typename T>
void doParsimUnpacking(omnetpp::cCommBuffer *, T& t)
{
    throw omnetpp::cRuntimeError("Parsim error: No doParsimUnpacking() function for type %s", omnetpp::opp_typename(typeid(t)));
}

}  // namespace omnetpp


// forward
template<typename T, typename A>
std::ostream& operator<<(std::ostream& out, const std::vector<T,A>& vec);

// Template rule which fires if a struct or class doesn't have operator<<
template<typename T>
inline std::ostream& operator<<(std::ostream& out,const T&) {return out;}

// operator<< for std::vector<T>
template<typename T, typename A>
inline std::ostream& operator<<(std::ostream& out, const std::vector<T,A>& vec)
{
    out.put('{');
    for(typename std::vector<T,A>::const_iterator it = vec.begin(); it != vec.end(); ++it)
    {
        if (it != vec.begin()) {
            out.put(','); out.put(' ');
        }
        out << *it;
    }
    out.put('}');
    
    char buf[32];
    sprintf(buf, " (size=%u)", (unsigned int)vec.size());
    out.write(buf, strlen(buf));
    return out;
}

Register_Class(NTU_SinkholeMessage)

NTU_SinkholeMessage::NTU_SinkholeMessage(const char *name, short kind) : ::omnetpp::cMessage(name,kind)
{
    this->sinkOnlyWhenRouteInTable = false;
    this->sinkholeAttackProbability = 0;
    this->seqnoAdded = 0;
    this->numHops = 0;
}

NTU_SinkholeMessage::NTU_SinkholeMessage(const NTU_SinkholeMessage& other) : ::omnetpp::cMessage(other)
{
    copy(other);
}

NTU_SinkholeMessage::~NTU_SinkholeMessage()
{
}

NTU_SinkholeMessage& NTU_SinkholeMessage::operator=(const NTU_SinkholeMessage& other)
{
    if (this==&other) return *this;
    ::omnetpp::cMessage::operator=(other);
    copy(other);
    return *this;
}

void NTU_SinkholeMessage::copy(const NTU_SinkholeMessage& other)
{
    this->sinkOnlyWhenRouteInTable = other.sinkOnlyWhenRouteInTable;
    this->sinkholeAttackProbability = other.sinkholeAttackProbability;
    this->seqnoAdded = other.seqnoAdded;
    this->numHops = other.numHops;
}

void NTU_SinkholeMessage::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cMessage::parsimPack(b);
    doParsimPacking(b,this->sinkOnlyWhenRouteInTable);
    doParsimPacking(b,this->sinkholeAttackProbability);
    doParsimPacking(b,this->seqnoAdded);
    doParsimPacking(b,this->numHops);
}

void NTU_SinkholeMessage::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cMessage::parsimUnpack(b);
    doParsimUnpacking(b,this->sinkOnlyWhenRouteInTable);
    doParsimUnpacking(b,this->sinkholeAttackProbability);
    doParsimUnpacking(b,this->seqnoAdded);
    doParsimUnpacking(b,this->numHops);
}

bool NTU_SinkholeMessage::getSinkOnlyWhenRouteInTable() const
{
    return this->sinkOnlyWhenRouteInTable;
}

void NTU_SinkholeMessage::setSinkOnlyWhenRouteInTable(bool sinkOnlyWhenRouteInTable)
{
    this->sinkOnlyWhenRouteInTable = sinkOnlyWhenRouteInTable;
}

double NTU_SinkholeMessage::getSinkholeAttackProbability() const
{
    return this->sinkholeAttackProbability;
}

void NTU_SinkholeMessage::setSinkholeAttackProbability(double sinkholeAttackProbability)
{
    this->sinkholeAttackProbability = sinkholeAttackProbability;
}

double NTU_SinkholeMessage::getSeqnoAdded() const
{
    return this->seqnoAdded;
}

void NTU_SinkholeMessage::setSeqnoAdded(double seqnoAdded)
{
    this->seqnoAdded = seqnoAdded;
}

int NTU_SinkholeMessage::getNumHops() const
{
    return this->numHops;
}

void NTU_SinkholeMessage::setNumHops(int numHops)
{
    this->numHops = numHops;
}

class NTU_SinkholeMessageDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    NTU_SinkholeMessageDescriptor();
    virtual ~NTU_SinkholeMessageDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual const char *getFieldDynamicTypeString(void *object, int field, int i) const override;
    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(NTU_SinkholeMessageDescriptor)

NTU_SinkholeMessageDescriptor::NTU_SinkholeMessageDescriptor() : omnetpp::cClassDescriptor("NTU_SinkholeMessage", "omnetpp::cMessage")
{
    propertynames = nullptr;
}

NTU_SinkholeMessageDescriptor::~NTU_SinkholeMessageDescriptor()
{
    delete[] propertynames;
}

bool NTU_SinkholeMessageDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<NTU_SinkholeMessage *>(obj)!=nullptr;
}

const char **NTU_SinkholeMessageDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *NTU_SinkholeMessageDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int NTU_SinkholeMessageDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 4+basedesc->getFieldCount() : 4;
}

unsigned int NTU_SinkholeMessageDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<4) ? fieldTypeFlags[field] : 0;
}

const char *NTU_SinkholeMessageDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "sinkOnlyWhenRouteInTable",
        "sinkholeAttackProbability",
        "seqnoAdded",
        "numHops",
    };
    return (field>=0 && field<4) ? fieldNames[field] : nullptr;
}

int NTU_SinkholeMessageDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='s' && strcmp(fieldName, "sinkOnlyWhenRouteInTable")==0) return base+0;
    if (fieldName[0]=='s' && strcmp(fieldName, "sinkholeAttackProbability")==0) return base+1;
    if (fieldName[0]=='s' && strcmp(fieldName, "seqnoAdded")==0) return base+2;
    if (fieldName[0]=='n' && strcmp(fieldName, "numHops")==0) return base+3;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *NTU_SinkholeMessageDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "bool",
        "double",
        "double",
        "int",
    };
    return (field>=0 && field<4) ? fieldTypeStrings[field] : nullptr;
}

const char **NTU_SinkholeMessageDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *NTU_SinkholeMessageDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int NTU_SinkholeMessageDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    NTU_SinkholeMessage *pp = (NTU_SinkholeMessage *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *NTU_SinkholeMessageDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    NTU_SinkholeMessage *pp = (NTU_SinkholeMessage *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string NTU_SinkholeMessageDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    NTU_SinkholeMessage *pp = (NTU_SinkholeMessage *)object; (void)pp;
    switch (field) {
        case 0: return bool2string(pp->getSinkOnlyWhenRouteInTable());
        case 1: return double2string(pp->getSinkholeAttackProbability());
        case 2: return double2string(pp->getSeqnoAdded());
        case 3: return long2string(pp->getNumHops());
        default: return "";
    }
}

bool NTU_SinkholeMessageDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    NTU_SinkholeMessage *pp = (NTU_SinkholeMessage *)object; (void)pp;
    switch (field) {
        case 0: pp->setSinkOnlyWhenRouteInTable(string2bool(value)); return true;
        case 1: pp->setSinkholeAttackProbability(string2double(value)); return true;
        case 2: pp->setSeqnoAdded(string2double(value)); return true;
        case 3: pp->setNumHops(string2long(value)); return true;
        default: return false;
    }
}

const char *NTU_SinkholeMessageDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

void *NTU_SinkholeMessageDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    NTU_SinkholeMessage *pp = (NTU_SinkholeMessage *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}


