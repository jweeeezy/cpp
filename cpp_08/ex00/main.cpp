// ========================================================================== //
//                               42 | Heilbronn                               //
// ========================================================================== //
//                                                                            //
// name:  jakob willert (jwillert)                                            //
// mail:  jwillert@student.42heilbronn.de                                     //
// file:  main.cpp                                                            //
//                                                                            //
// -------------------------------------------------------------------------- //

#include "easyfind.hpp" // needed for easyfind()
#include <cstdlib>      // needed for MACROS
#include <deque>        // needed for std::deque
#include <exception>    // needed for std::exception
#include <iostream>     // needed for std::cout
#include <list>         // needed for std::list
#include <map>          // needed for std::map
#include <string>       // needed for std::string
#include <vector>       // needed for std::vector

#define GREEN "\033[32m"
#define RESET "\033[0m"

static inline void test_log(std::string const & message)
{
    std::cout << GREEN << "\n< " << message << " >" << RESET << "\n";
}

template <typename T> void test_with_valid_value(T & container, int test_value)
{
    container.push_back(test_value);
    std::cout << *easyfind(container, test_value) << "\n";
}

template <typename T>
void test_with_invalid_value(T & container, int test_value)
{
    try
    {
        std::cout << *easyfind(container, test_value) << "\n";
    }
    catch (std::exception & e)
    {
        std::cerr << "caught exception: " << e.what() << "\n";
    }
}

int main(void)
{
    {
        test_log("Testing valid value with std::list");
        std::list<int> lst;
        test_with_valid_value(lst, 42);

        test_log("Testing invalid value with std::list");
        test_with_invalid_value(lst, -1);
    }
    {
        test_log("Testing valid value with std::vector");
        std::vector<int> vec;
        test_with_valid_value(vec, -21);

        test_log("Testing invalid value with std::vector");
        test_with_invalid_value(vec, -1);
    }
    {
        test_log("testing valid value with std::deque");
        std::deque<int> deq;
        test_with_valid_value(deq, 1231312395);

        test_log("testing invalid value with std::deque");
        test_with_invalid_value(deq, -1);
    }
    return (EXIT_SUCCESS);
}

// -------------------------------------------------------------------------- //
