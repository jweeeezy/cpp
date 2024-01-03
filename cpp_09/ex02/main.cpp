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
#include "utils.hpp"     // needed for log_container
#include <algorithm>     // needed for std::advance
#include <cstdlib>       // needed for MACROS
#include <iostream>      // needed for std::cerr, std::cout

#define RED   "\033[1;31m"
#define RESET "\033[0m"

#define EXPECTED_ARGC 2

static int log_exit(t_str_c & message)
{
    std::cerr << RED << "error: " << message << RESET << "\n";
    return (EXIT_FAILURE);
}

static t_str_c vec_str_to_str(t_vec_str_c & vec)
{
    std::stringstream ss;
    for (t_vec_str_cit it = vec.begin(); it != vec.end(); ++it)
    {
        ss << *it << " ";
    }
    return ss.str();
}

int main(int argc, char ** argv)
{
    if (argc < EXPECTED_ARGC)
    {
        return log_exit("not enough arguments!");
    }
    try
    {
        StopWatch timer_list;
        StopWatch timer_deque;

        PmergeMe pmm(argc - 1, argv);

        timer_list.start();
        pmm.sort_with_list();
        timer_list.stop();

        log_is_sorted(pmm.get_sorted_args(), "std::list:");

        timer_deque.start();
        pmm.sort_with_deque();
        timer_deque.stop();

        log_is_sorted(pmm.get_sorted_args(), "std::deq:");

        std::cout << "Before: " << vec_str_to_str(pmm.get_unsorted_args())
                  << "\n"
                  << "After:  " << vec_str_to_str(pmm.get_sorted_args()) << "\n"
                  << "Time to process a range of " << argc
                  << " elements with std::list: "
                  << timer_list.get_measured_time() << " ms\n"
                  << "Time to process a range of " << argc
                  << " elements with std::deque: "
                  << timer_deque.get_measured_time() << " ms" << std::endl;
    }
    catch (std::exception const & e)
    {
        return log_exit(e.what());
    }
    return (EXIT_SUCCESS);
}

// -------------------------------------------------------------------------- //
