// ========================================================================== //
//                               42 | Heilbronn                               //
// ========================================================================== //
//                                                                            //
// name:  jakob willert (jwillert)                                            //
// mail:  jwillert@student.42heilbronn.de                                     //
// file:  main.cpp                                                            //
//                                                                            //
// -------------------------------------------------------------------------- //

#include "RPN.hpp"  // needed for RPN class
#include <cstdlib>  // needed for MACROS
#include <iostream> // needed for std::cout, std::cerr

#define EXPECTED_ARGC 2

#define DIGITS    std::string("0123456789")
#define OPERATORS std::string("+-/*")

#define RED   "\033[1;31m"
#define RESET "\033[0m"

static int log_exit(std::string const & message)
{
    std::cerr << RED << "error: " << message << RESET << "\n";
    return (EXIT_FAILURE);
}

int main(int argc, char ** argv)
{
    if (argc != EXPECTED_ARGC)
    {
        return log_exit("missing argument!");
    }
    try
    {
        int result = RPN::calculate(argv[1]);
        std::cout << result;
    }
    catch (std::exception & e)
    {
        return log_exit(e.what());
    }
    return (EXIT_SUCCESS);
}

// -------------------------------------------------------------------------- //
