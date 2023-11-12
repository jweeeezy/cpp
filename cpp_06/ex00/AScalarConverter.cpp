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
#include <iostream>            // needed for std::cout, std::endl, std::cerr

#define YELLOW "\033[33m"
#define RESET  "\033[0m"

/* <~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~> non-class functions */

static inline void log_debug(std::string const & message)
{
    (void)message;
    #ifdef DEBUG
    std::cerr << YELLOW << "ScalarConverter: " << message << RESET << "\n";
    #endif // DEBUG
}

/* <~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~> constructors */

ScalarConverter::ScalarConverter() { log_debug("default constructor called"); }

ScalarConverter::ScalarConverter(ScalarConverter const & src)
{
    (void)src;
    log_debug("copy constructor called");
}

ScalarConverter::~ScalarConverter() { log_debug("destructor called"); }

/* <~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~> operator overloads */

ScalarConverter & ScalarConverter::operator=(ScalarConverter const & rhs)
{
    (void)rhs;
    return *this;
}

// -------------------------------------------------------------------------- //
