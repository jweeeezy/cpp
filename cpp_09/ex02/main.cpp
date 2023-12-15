// ========================================================================== //
//                               42 | Heilbronn                               //
// ========================================================================== //
//                                                                            //
// name:  jakob willert (jwillert)                                            //
// mail:  jwillert@student.42heilbronn.de                                     //
// file:  main.cpp                                                            //
//                                                                            //
// -------------------------------------------------------------------------- //

#include "PmergeMe.hpp"  // needed for PmergeMe class
#include "StopWatch.hpp" // needed for StopWatch class
#include <cstdlib>       // needed for MACROS
#include <iostream>      // needed for std::cerr, std::cout

#define RED   "\033[1;31m"
#define RESET "\033[0m"

#define EXPECTED_ARGC 2

static int log_exit(std::string const & message)
{
    std::cerr << RED << "error: " << message << RESET << "\n";
    return (EXIT_FAILURE);
}

static void log_measured_time(StopWatch & timer, std::string const & message)
{
    std::cout << message << ": " << timer.get_measured_time() << " ms"
              << "\n";
}

int main(int argc, char ** argv)
{
    if (argc < EXPECTED_ARGC)
    {
        return log_exit("not enough arguments!");
    }
    try
    {
        StopWatch timer_obj;
        PmergeMe  obj(argc - 1, argv);

        timer_obj.start();
        obj.sort_with_deque();
        timer_obj.stop();
        log_measured_time(timer_obj, "First try");
    }
    catch (std::exception const & e)
    {
        return log_exit(e.what());
    }
    return (EXIT_SUCCESS);
}

// -------------------------------------------------------------------------- //
