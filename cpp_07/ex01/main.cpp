// ========================================================================== //
//                               42 | Heilbronn                               //
// ========================================================================== //
//                                                                            //
// name:  jakob willert (jwillert)                                            //
// mail:  jwillert@student.42heilbronn.de                                     //
// file:  main.cpp                                                            //
//                                                                            //
// -------------------------------------------------------------------------- //

#include "iter.hpp" // needed for iter()
#include <cstdlib>  // needed for MACROS
#include <iostream> // needed for std::cout
#include <string>   // needed for std::string

#define GREEN "\033[32m"
#define RESET "\033[0m"

static inline void test_log(std::string const & message)
{
    std::cout << GREEN << "\n< " << message << " >" << RESET << "\n";
}

int main(void)
{
    int c_arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    test_log("Printing with ::iter function");
    ::iter(c_arr, 10, ::print<int>);
    std::cout << "\n";

    test_log("Multiplicating by 2 with ::iter function");
    ::iter(c_arr, 10, ::multiplicate_by_2<int>);

    test_log("Printing with ::iter function");
    ::iter(c_arr, 10, ::print<int>);
    std::cout << "\n\n";

    return (EXIT_SUCCESS);
}

// -------------------------------------------------------------------------- //
