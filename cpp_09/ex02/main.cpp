// ========================================================================== //
//                               42 | Heilbronn                               //
// ========================================================================== //
//                                                                            //
// name:  jakob willert (jwillert)                                            //
// mail:  jwillert@student.42heilbronn.de                                     //
// file:  main.cpp                                                            //
//                                                                            //
// -------------------------------------------------------------------------- //

#include <cstdlib>  // needed for MACROS
#include <iostream> // needed for std::cerr

#define RED   "\033[1;31m"
#define RESET "\033[0m"

#define EXPECTED_ARGC 3

static int log_exit(std::string const & message)
{
    std::cerr << RED << "error: " << message << RESET << "\n";
    return (EXIT_FAILURE);
}

int main(int argc, char ** argv)
{

    /* @note remove at some point */
    (void)argc;
    (void)argv;

    if (argc < EXPECTED_ARGC)
    {
        return log_exit("not enough arguments!");
    }

    /* @note create PmergeMe class */
    /* mb instantiate with the container to be used ? */
    /* @note parse integers (positive only!) -> data structure */

    try
    {
    }
    catch (std::exception const & e)
    {
        return log_exit(e.what());
    }

    return (EXIT_SUCCESS);
}

// -------------------------------------------------------------------------- //
