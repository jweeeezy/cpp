// ========================================================================== //
//                               42 | Heilbronn                               //
// ========================================================================== //
//                                                                            //
// name:  jakob willert (jwillert)                                            //
// mail:  jwillert@student.42heilbronn.de                                     //
// file:  Base.cpp                                                            //
//                                                                            //
// -------------------------------------------------------------------------- //

#include "Base.hpp" // needed for Base class
#include <string>   // needed for std::string
#include <iostream> // needed for std::cout

#define YELLOW "\033[33m"
#define RESET  "\033[0m"

static inline void debug_log(std::string const & message)
{
    (void)message;
    #ifdef DEBUG
    std::cout << YELLOW << "Base: " << message << RESET << "\n";
    #endif // DEBUG
}

Base::~Base() { debug_log("destructor called"); }

// -------------------------------------------------------------------------- //
