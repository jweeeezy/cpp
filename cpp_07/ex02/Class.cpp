// ========================================================================== //
//                               42 | Heilbronn                               //
// ========================================================================== //
//                                                                            //
// name:  jakob willert (jwillert)                                            //
// mail:  jwillert@student.42heilbronn.de                                     //
// file:  Class.cpp                                                           //
//                                                                            //
// -------------------------------------------------------------------------- //

#include "Class.hpp" // needed for Class class
#include <iostream>  // needed for std::cout
#include <string>    // needed for std::string

#define YELLOW "\033[33m"
#define RESET  "\033[0m"

static inline void log_debug(std::string const & message)
{
    (void)message;
    #ifdef DEBUG
    std::cout << YELLOW << "Class: " << message << RESET << "\n";
    #endif // DEBUG
}

Class::Class() : content("123") { log_debug("Default constructor called"); }

Class::Class(Class const & src)
{
    (void)src;
    log_debug("copy constructor called");
}

Class::~Class() { log_debug("destructor called"); }

Class & Class::operator=(Class const & src)
{
    log_debug("assignment operator called");
    (void)src;
    return *this;
}

// -------------------------------------------------------------------------- //
