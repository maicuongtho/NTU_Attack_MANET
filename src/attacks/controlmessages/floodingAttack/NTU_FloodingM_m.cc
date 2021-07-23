//
// Generated file, do not edit! Created by nedtool 5.6 from attacks/controlmessages/floodingAttack/NTU_FloodingM.msg.
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
#include "NTU_FloodingM_m.h"

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

Register_Class(NTU_FloodingM)

NTU_FloodingM::NTU_FloodingM(const char *name, short kind) : ::omnetpp::cMessage(name,kind)
{
    this->isHelloFlooding = false;
    this->isRreqFlooding = false;
    this->isDataFlooding = false;
    this->Interval_HelloFlooing = 0;
    this->Interval_RreqFlooing = 0;
    this->Interval_DataFlooing = 0;
}

NTU_FloodingM::NTU_FloodingM(const NTU_FloodingM& other) : ::omnetpp::cMessage(other)
{
    copy(other);
}

NTU_FloodingM::~NTU_FloodingM()
{
}

NTU_FloodingM& NTU_FloodingM::operator=(const NTU_FloodingM& other)
{
    if (this==&other) return *this;
    ::omnetpp::cMessage::operator=(other);
    copy(other);
    return *this;
}

void NTU_FloodingM::copy(const NTU_FloodingM& other)
{
    this->isHelloFlooding = other.isHelloFlooding;
    this->isRreqFlooding = other.isRreqFlooding;
    this->isDataFlooding = other.isDataFlooding;
    this->Interval_HelloFlooing = other.Interval_HelloFlooing;
    this->Interval_RreqFlooing = other.Interval_RreqFlooing;
    this->Interval_DataFlooing = other.Interval_DataFlooing;
}

void NTU_FloodingM::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cMessage::parsimPack(b);
    doParsimPacking(b,this->isHelloFlooding);
    doParsimPacking(b,this->isRreqFlooding);
    doParsimPacking(b,this->isDataFlooding);
    doParsimPacking(b,this->Interval_HelloFlooing);
    doParsimPacking(b,this->Interval_RreqFlooing);
    doParsimPacking(b,this->Interval_DataFlooing);
}

void NTU_FloodingM::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cMessage::parsimUnpack(b);
    doParsimUnpacking(b,this->isHelloFlooding);
    doParsimUnpacking(b,this->isRreqFlooding);
    doParsimUnpacking(b,this->isDataFlooding);
    doParsimUnpacking(b,this->Interval_HelloFlooing);
    doParsimUnpacking(b,this->Interval_RreqFlooing);
    doParsimUnpacking(b,this->Interval_DataFlooing);
}

bool NTU_FloodingM::getIsHelloFlooding() const
{
    return this->isHelloFlooding;
}

void NTU_FloodingM::setIsHelloFlooding(bool isHelloFlooding)
{
    this->isHelloFlooding = isHelloFlooding;
}

bool NTU_FloodingM::getIsRreqFlooding() const
{
    return this->isRreqFlooding;
}

void NTU_FloodingM::setIsRreqFlooding(bool isRreqFlooding)
{
    this->isRreqFlooding = isRreqFlooding;
}

bool NTU_FloodingM::getIsDataFlooding() const
{
    return this->isDataFlooding;
}

void NTU_FloodingM::setIsDataFlooding(bool isDataFlooding)
{
    this->isDataFlooding = isDataFlooding;
}

double NTU_FloodingM::getInterval_HelloFlooing() const
{
    return this->Interval_HelloFlooing;
}

void NTU_FloodingM::setInterval_HelloFlooing(double Interval_HelloFlooing)
{
    this->Interval_HelloFlooing = Interval_HelloFlooing;
}

double NTU_FloodingM::getInterval_RreqFlooing() const
{
    return this->Interval_RreqFlooing;
}

void NTU_FloodingM::setInterval_RreqFlooing(double Interval_RreqFlooing)
{
    this->Interval_RreqFlooing = Interval_RreqFlooing;
}

double NTU_FloodingM::getInterval_DataFlooing() const
{
    return this->Interval_DataFlooing;
}

void NTU_FloodingM::setInterval_DataFlooing(double Interval_DataFlooing)
{
    this->Interval_DataFlooing = Interval_DataFlooing;
}

class NTU_FloodingMDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    NTU_FloodingMDescriptor();
    virtual ~NTU_FloodingMDescriptor();

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

Register_ClassDescriptor(NTU_FloodingMDescriptor)

NTU_FloodingMDescriptor::NTU_FloodingMDescriptor() : omnetpp::cClassDescriptor("NTU_FloodingM", "omnetpp::cMessage")
{
    propertynames = nullptr;
}

NTU_FloodingMDescriptor::~NTU_FloodingMDescriptor()
{
    delete[] propertynames;
}

bool NTU_FloodingMDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<NTU_FloodingM *>(obj)!=nullptr;
}

const char **NTU_FloodingMDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *NTU_FloodingMDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int NTU_FloodingMDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 6+basedesc->getFieldCount() : 6;
}

unsigned int NTU_FloodingMDescriptor::getFieldTypeFlags(int field) const
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
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<6) ? fieldTypeFlags[field] : 0;
}

const char *NTU_FloodingMDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "isHelloFlooding",
        "isRreqFlooding",
        "isDataFlooding",
        "Interval_HelloFlooing",
        "Interval_RreqFlooing",
        "Interval_DataFlooing",
    };
    return (field>=0 && field<6) ? fieldNames[field] : nullptr;
}

int NTU_FloodingMDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='i' && strcmp(fieldName, "isHelloFlooding")==0) return base+0;
    if (fieldName[0]=='i' && strcmp(fieldName, "isRreqFlooding")==0) return base+1;
    if (fieldName[0]=='i' && strcmp(fieldName, "isDataFlooding")==0) return base+2;
    if (fieldName[0]=='I' && strcmp(fieldName, "Interval_HelloFlooing")==0) return base+3;
    if (fieldName[0]=='I' && strcmp(fieldName, "Interval_RreqFlooing")==0) return base+4;
    if (fieldName[0]=='I' && strcmp(fieldName, "Interval_DataFlooing")==0) return base+5;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *NTU_FloodingMDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "bool",
        "bool",
        "bool",
        "double",
        "double",
        "double",
    };
    return (field>=0 && field<6) ? fieldTypeStrings[field] : nullptr;
}

const char **NTU_FloodingMDescriptor::getFieldPropertyNames(int field) const
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

const char *NTU_FloodingMDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int NTU_FloodingMDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    NTU_FloodingM *pp = (NTU_FloodingM *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *NTU_FloodingMDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    NTU_FloodingM *pp = (NTU_FloodingM *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string NTU_FloodingMDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    NTU_FloodingM *pp = (NTU_FloodingM *)object; (void)pp;
    switch (field) {
        case 0: return bool2string(pp->getIsHelloFlooding());
        case 1: return bool2string(pp->getIsRreqFlooding());
        case 2: return bool2string(pp->getIsDataFlooding());
        case 3: return double2string(pp->getInterval_HelloFlooing());
        case 4: return double2string(pp->getInterval_RreqFlooing());
        case 5: return double2string(pp->getInterval_DataFlooing());
        default: return "";
    }
}

bool NTU_FloodingMDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    NTU_FloodingM *pp = (NTU_FloodingM *)object; (void)pp;
    switch (field) {
        case 0: pp->setIsHelloFlooding(string2bool(value)); return true;
        case 1: pp->setIsRreqFlooding(string2bool(value)); return true;
        case 2: pp->setIsDataFlooding(string2bool(value)); return true;
        case 3: pp->setInterval_HelloFlooing(string2double(value)); return true;
        case 4: pp->setInterval_RreqFlooing(string2double(value)); return true;
        case 5: pp->setInterval_DataFlooing(string2double(value)); return true;
        default: return false;
    }
}

const char *NTU_FloodingMDescriptor::getFieldStructName(int field) const
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

void *NTU_FloodingMDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    NTU_FloodingM *pp = (NTU_FloodingM *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}


