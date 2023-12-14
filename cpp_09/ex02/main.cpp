// ========================================================================== //
//                               42 | Heilbronn                               //
// ========================================================================== //
//                                                                            //
// name:  jakob willert (jwillert)                                            //
// mail:  jwillert@student.42heilbronn.de                                     //
// file:  main.cpp                                                            //
//                                                                            //
// -------------------------------------------------------------------------- //

#include "PmergeMe.hpp" // needed for PmergeMe class
#include <cstdlib>      // needed for MACROS
#include <iostream>     // needed for std::cerr

#define RED   "\033[1;31m"
#define RESET "\033[0m"

#define EXPECTED_ARGC 2

static int log_exit(std::string const & message)
{
    std::cerr << RED << "error: " << message << RESET << "\n";
    return (EXIT_FAILURE);
}

int main(int argc, char ** argv)
{
    if (argc < EXPECTED_ARGC)
    {
        return log_exit("not enough arguments!");
    }
    try
    {
        PmergeMe obj(argc - 1, argv);
        obj.sort_with_deque();
        obj.sort_with_vector();
    }
    catch (std::exception const & e)
    {
        return log_exit(e.what());
    }
    return (EXIT_SUCCESS);
}

// -------------------------------------------------------------------------- //
