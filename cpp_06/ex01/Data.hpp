// ========================================================================== //
//                               42 | Heilbronn                               //
// ========================================================================== //
//                                                                            //
// name:  jakob willert (jwillert)                                            //
// mail:  jwillert@student.42heilbronn.de                                     //
// file:  Data.hpp                                                            //
//                                                                            //
// -------------------------------------------------------------------------- //

#ifndef DATA_HPP
#define DATA_HPP

#include <string> // needed for std::string

struct Data
{
    std::string  address;
    unsigned int no_floors;
    unsigned int no_bedrooms;
    unsigned int no_bathrooms;
    unsigned int no_kitchen;
};

#endif // DATA_HPP

// -------------------------------------------------------------------------- //
