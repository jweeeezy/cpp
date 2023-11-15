// ========================================================================== //
//                               42 | Heilbronn                               //
// ========================================================================== //
//                                                                            //
// name:  jakob willert (jwillert)                                            //
// mail:  jwillert@student.42heilbronn.de                                     //
// file:  main.cpp                                                            //
//                                                                            //
// -------------------------------------------------------------------------- //

#include "Array.hpp" // needed for Array class
#include "Class.hpp" // needed for Class class
#include <cstdlib>   // needed for MACROS
#include <exception> // needed for std::exception
#include <iostream>  // needed for std::cout

#define GREEN "\033[32m"
#define RESET "\033[0m"

static inline void test_log(std::string const & message)
{
    std::cout << GREEN << "\n< " << message << " >" << RESET << "\n";
}

int main(void)
{
    test_log("Testing default constructor");
    Array<Class> def;

    test_log("Testing size constructor");
    Array<Class> a(3);
    
    test_log("Testing copy constructor");
    Array<Class> b(a);
    
    test_log("Testing assignment operator");
    Array<Class> c = a;

    test_log("Testing sizes of all instances");
    std::cout << "def size: " << def.size() << "\n";
    std::cout << "A size:   " << a.size() << "\n";
    std::cout << "B size:   " << b.size() << "\n";
    std::cout << "C size:   " << c.size() << "\n";

    test_log("Testing content of all instances");
    std::cout << "a[0]: " << a[0].content << "\n";
    std::cout << "b[1]: " << b[1].content << "\n";
    std::cout << "c[2]: " << c[2].content << "\n";
    
    test_log("Testing if editing content changes copies");
    a[1].content = "blub";
    std::cout << "a[1]: " << a[1].content << "\n";
    std::cout << "b[1]: " << b[1].content << "\n";
    std::cout << "c[1]: " << c[1].content << "\n";

    test_log("Testing accessing out of bounds");
    try
    {
        std::cout << c[3].content;
    }
    catch (std::exception & e)
    {
        std::cout << "Caught Exception: " << e.what() << "\n";
    }
    return (EXIT_SUCCESS);
}

// -------------------------------------------------------------------------- //
