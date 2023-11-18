// ========================================================================== //
//                               42 | Heilbronn                               //
// ========================================================================== //
//                                                                            //
// name:  jakob willert (jwillert)                                            //
// mail:  jwillert@student.42heilbronn.de                                     //
// file:  main.cpp                                                            //
//                                                                            //
// -------------------------------------------------------------------------- //

#include "Span.hpp" // needed for Span class
#include <cstdlib>  // needed for MACROS
#include <iostream> // needed for std::cout

int main(void)
{
    Span sp(5);

    sp.addNumber(50);
    sp.addNumber(-20);
    sp.addNumber(20);
    sp.addNumber(100);
    sp.addNumber(-1000);

    std::cout << sp.longestSpan() << "\n";

    return (EXIT_SUCCESS);
}

// -------------------------------------------------------------------------- //
