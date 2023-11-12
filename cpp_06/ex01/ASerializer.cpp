// ========================================================================== //
//                               42 | Heilbronn                               //
// ========================================================================== //
//                                                                            //
// name:  jakob willert (jwillert)                                            //
// mail:  jwillert@student.42heilbronn.de                                     //
// file:  ASerializer.cpp                                                     //
//                                                                            //
// -------------------------------------------------------------------------- //

#include "ASerializer.hpp" // needed for ASerializer class

/* <~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~> static member functions  */

uintptr_t ASerializer::serialize(Data * ptr)
{
    return reinterpret_cast<uintptr_t>(ptr);
}

Data * ASerializer::deserialize(uintptr_t raw)
{
    return reinterpret_cast<Data *>(raw);
}

/* <~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~> constructors */

ASerializer::ASerializer() {}
ASerializer::ASerializer(const ASerializer & src) { (void)src; }
ASerializer::~ASerializer() {}
ASerializer & ASerializer::operator=(const ASerializer & rhs)
{
    (void)rhs;
    return (*this);
}

// -------------------------------------------------------------------------- //
