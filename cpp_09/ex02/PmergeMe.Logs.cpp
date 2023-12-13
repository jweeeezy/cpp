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
#include <iostream>     // needed for std::cerr

#define YELLOW "\033[033m"
#define RESET  "\033[0m"

void PmergeMe::log_debug(t_str_c & message) const
{
    (void)message;
#ifdef DEBUG
    std::cerr << YELLOW << "PmergeMe: " << message << RESET << "\n";
#endif // DEBUG
}

void PmergeMe::log_vector(t_vec_str_c & vec, t_str_c & name) const
{
    (void)vec;
    (void)name;
#ifdef DEBUG
    std::cerr << YELLOW << "[" << name << "]";
    for (t_vec_str_cit it = vec.begin(); it != vec.end(); ++it)
    {
        std::cerr << *it << " ";
    }
    std::cerr << "\n" << RESET;
#endif // DEBUG
}

// -------------------------------------------------------------------------- //
