// ========================================================================== //
//                               42 | Heilbronn                               //
// ========================================================================== //
//                                                                            //
// name:  jakob willert (jwillert)                                            //
// mail:  jwillert@student.42heilbronn.de                                     //
// file:  PmergeMe.Logs.cpp                                                   //
//                                                                            //
// -------------------------------------------------------------------------- //

#include "PmergeMe.hpp" // needed for PmergeMe class, typedefs, std::vector

#ifdef DEBUG
#include <iostream> // needed for std::cerr
#endif

/* @note make Yellow light blue or something visible other than white */

#define YELLOW "\033[033m"
#define RESET  "\033[0m"

void PmergeMe::log_debug(t_str_c & message) const
{
    (void)message;
#ifdef DEBUG
    std::cerr << YELLOW << "PmergeMe: " << message << RESET << "\n";
#endif // DEBUG
}

void PmergeMe::log_straggler() const
{

#ifdef DEBUG
    std::cerr << YELLOW << "Straggler: " << RESET << _straggler << "\n";
#endif
}

void PmergeMe::log_list(t_lst_pair_int_c & pairs, t_str_c & name) const
{
    (void)pairs;
    (void)name;
#ifdef DEBUG
    std::cerr << YELLOW << name << ": " << RESET;
    for (std::list<std::pair<int, int> >::const_iterator it = pairs.begin();
         it != pairs.end(); ++it)
    {
        std::cout << "[" << it->first << "|" << it->second << "] ";
    }
    std::cerr << "\n" << RESET;
#endif
}

// -------------------------------------------------------------------------- //
