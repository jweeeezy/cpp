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
#define YELLOW "\033[033m"
#define LIGHT_BLUE "\033[094m"
#define RESET  "\033[0m"
#include <iostream> // needed for std::cerr
#endif

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
    std::cerr << LIGHT_BLUE << "_straggler: " << RESET << _straggler << "\n";
#endif
}

void PmergeMe::log_pairs(t_lst_pair_int_c & pairs, t_str_c & name) const
{
    (void)pairs;
    (void)name;
#ifdef DEBUG
    std::cerr << LIGHT_BLUE << name << ": " << RESET;
    for (t_lst_pair_int_cit it = pairs.begin();
         it != pairs.end(); ++it)
    {
        std::cerr << "[" << it->first << "|" << it->second << "] ";
    }
    std::cerr << "\n" << RESET;
#endif
}

void PmergeMe::log_pairs(t_deq_pair_int_c & pairs, t_str_c & name) const
{
    (void)pairs;
    (void)name;
#ifdef DEBUG
    std::cerr << LIGHT_BLUE << name << ": " << RESET;
    for (t_deq_pair_int_cit it = pairs.begin();
         it != pairs.end(); ++it)
    {
        std::cerr << "[" << it->first << "|" << it->second << "] ";
    }
    std::cerr << "\n" << RESET;
#endif
}

// -------------------------------------------------------------------------- //
