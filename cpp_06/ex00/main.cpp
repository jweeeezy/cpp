// ========================================================================== //
//                               42 | Heilbronn                               //
// ========================================================================== //
//                                                                            //
// name:  jakob willert (jwillert)                                            //
// mail:  jwillert@student.42heilbronn.de                                     //
// file:  main.cpp                                                            //
//                                                                            //
// -------------------------------------------------------------------------- //

#include "AScalarConverter.hpp" // needed for ScalarConverter class, std::string
#include <cstdlib>              // needed for MACROS
#include <iostream>             // needed for std::cout

#define RED   "\033[91m"
#define RESET "\033[0m"

#define EXPECTED_ARGC 2

static inline int log_exit_failure(std::string const & message)
{
    std::cerr << RED << "Error: " << message << RESET << "\n";
    exit(EXIT_FAILURE);
}

int main(int argc, char ** argv)
{
    if (argc != EXPECTED_ARGC)
    {
        log_exit_failure("Wrong no. of arguments given!");
    }
    try
    {
        ScalarConverter::convert(argv[1]);
    }
    catch (std::exception const & e)
    {
        log_exit_failure(e.what());
    }
    return (EXIT_SUCCESS);
}

// -------------------------------------------------------------------------- //
