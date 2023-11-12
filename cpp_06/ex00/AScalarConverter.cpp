// ========================================================================== //
//                               42 | Heilbronn                               //
// ========================================================================== //
//                                                                            //
// name:  jakob willert (jwillert)                                            //
// mail:  jwillert@student.42heilbronn.de                                     //
// file:  AScalarConverter.cpp                                                //
//                                                                            //
// -------------------------------------------------------------------------- //

#include "AScalarConverter.hpp" // needed for ScalarConverter class
#include <iostream>             // needed for std::cout, std::endl, std::cerr

/* <~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~> constructors */

AScalarConverter::AScalarConverter() {}
AScalarConverter::AScalarConverter(AScalarConverter const & src) { (void)src; }
AScalarConverter::~AScalarConverter() {}
AScalarConverter & AScalarConverter::operator=(AScalarConverter const & rhs)
{
    (void)rhs;
    return *this;
}

// -------------------------------------------------------------------------- //
