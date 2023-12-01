// ========================================================================== //
//                               42 | Heilbronn                               //
// ========================================================================== //
//                                                                            //
// name:  jakob willert (jwillert)                                            //
// mail:  jwillert@student.42heilbronn.de                                     //
// file:  main.cpp                                                            //
//                                                                            //
// -------------------------------------------------------------------------- //

#include "BitcoinExchange.hpp" // needed for BitcoinExchange class
#include <cstdlib>             // needed for MACROS
#include <iostream>            // needed for std::cerr

#define EXPECTED_ARGC 2

int main(int argc, char ** argv)
{
    if (argc != EXPECTED_ARGC)
    {
        std::cerr << "error: bad arguments!\nusage: ./btc [filename]\n";
        return (EXIT_FAILURE);
    }
    try
    {
        BitcoinExchange btc("data.csv");
        BitcoinExchange cpy;
        
        cpy = btc;
        cpy.print_database();

        btc.convert(argv[1]);
    }
    catch (std::exception & e)
    {
        std::cerr << e.what();
    }
    return (EXIT_SUCCESS);
}

// -------------------------------------------------------------------------- //
