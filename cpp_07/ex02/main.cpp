// ========================================================================== //
//                               42 | Heilbronn                               //
// ========================================================================== //
//                                                                            //
// name:  jakob willert (jwillert)                                            //
// mail:  jwillert@student.42heilbronn.de                                     //
// file:  main.cpp                                                            //
//                                                                            //
// -------------------------------------------------------------------------- //

#include "whatever.hpp" // needed for swap(), min(), max()
#include <cstdlib>      // needed for MACROS
#include <iostream>     // needed for std::cout
#include <string>       // needed for std::string

int main(void)
{
    int a = 2;
    int b = 3;

    ::swap(a, b);
    std::cout << "a = " << a << ", b = " << b << "\n";
    std::cout << "min( a, b ) = " << ::min(a, b) << "\n";
    std::cout << "max( a, b ) = " << ::max(a, b) << "\n";

    std::string c = "chaine1";
    std::string d = "chaine2";

    ::swap(c, d);
    std::cout << "c = " << c << ", d = " << d << "\n";
    std::cout << "min( c, d ) = " << ::min(c, d) << "\n";
    std::cout << "max( c, d ) = " << ::max(c, d) << "\n";

    return (EXIT_SUCCESS);
}

// -------------------------------------------------------------------------- //
