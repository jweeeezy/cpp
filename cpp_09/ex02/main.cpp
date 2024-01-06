// ========================================================================== //
//                               42 | Heilbronn                               //
// ========================================================================== //
//                                                                            //
// name:  jakob willert (jwillert)                                            //
// mail:  jwillert@student.42heilbronn.de                                     //
// file:  main.cpp                                                            //
//                                                                            //
// -------------------------------------------------------------------------- //

#include "PmergeMe.hpp"  // needed for PmergeMe class, typedefs
#include "StopWatch.hpp" // needed for StopWatch class
#include "utils.hpp"     // needed for log_container
#include <cstdlib>       // needed for MACROS
#include <iostream>      // needed for std::cerr, std::cout

#define EXPECTED_ARGC 2

static int log_exit(t_str_c & message)
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
        StopWatch timer_list;
        StopWatch timer_deque;

        PmergeMe FJMI(argc - 1, argv);

        timer_list.start();
        t_lst_int_c sorted_list = FJMI.sort_with_list();
        timer_list.stop();

        log_is_sorted(sorted_list, "std::list:");

        timer_deque.start();
        t_deq_int_c sorted_deque = FJMI.sort_with_deque();
        timer_deque.stop();

        log_is_sorted(sorted_deque, "std::deq:");

        std::cout << "Before: " << container_to_str(FJMI.get_unsorted_args())
                  << "\n"
                  << "After:  " << container_to_str(sorted_deque) << "\n"
                  << "Time to process a range of " << sorted_list.size()
                  << " elements with std::list: "
                  << timer_list.get_measured_time() << " ms\n"
                  << "Time to process a range of " << sorted_deque.size()
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
