// ========================================================================== //
//                               42 | Heilbronn                               //
// ========================================================================== //
//                                                                            //
// name:  jakob willert (jwillert)                                            //
// mail:  jwillert@student.42heilbronn.de                                     //
// file:  main.cpp                                                            //
//                                                                            //
// -------------------------------------------------------------------------- //

#include "ScalarConverter.hpp" // needed for ScalarConverter class, std::string
#include <cstdlib>             // needed for MACROS
#include <iostream>            // needed for std::cout, std::endl

#define EXPECTED_ARGC 2

static inline int log_exit_failure(std::string const & message)
{
    std::cerr << "Error: " << message << "\n";
    exit(EXIT_FAILURE);
}

int main(int argc, char ** argv)
{
    if (argc != EXPECTED_ARGC)
    {
        log_exit_failure("Wrong arguments given!");
    }
    try
    {
        ScalarConverter::convert(argv[1]);
    }
    catch (std::exception const & e)
    {
        std::cout << e.what() << std::endl;
    }
    return (EXIT_SUCCESS);
}

// -------------------------------------------------------------------------- //
