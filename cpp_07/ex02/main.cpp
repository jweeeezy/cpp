// ========================================================================== //
//                               42 | Heilbronn                               //
// ========================================================================== //
//                                                                            //
// name:  jakob willert (jwillert)                                            //
// mail:  jwillert@student.42heilbronn.de                                     //
// file:  main.cpp                                                            //
//                                                                            //
// -------------------------------------------------------------------------- //

#include <cstdlib>   // needed for MACROS
#include <iostream>  // needed for std::cout
#include "Array.hpp" // needed for Array class

int main(void)
{
    int * a = new int();
    std::cout << *a << "\n";


    Array<int> arr;

    return (EXIT_SUCCESS);
}

// -------------------------------------------------------------------------- //
