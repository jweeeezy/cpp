// ========================================================================== //
//                               42 | Heilbronn                               //
// ========================================================================== //
//                                                                            //
// name:  jakob willert (jwillert)                                            //
// mail:  jwillert@student.42heilbronn.de                                     //
// file:  PmergeMe.SortDeque.cpp                                              //
//                                                                            //
// -------------------------------------------------------------------------- //

#include "PmergeMe.hpp" // needed for PmergeMe class, typedefs
#include "utils.hpp"    // needed for container utils

struct s_deques
{
    t_deq_int      numbers;
    t_deq_pair_int pairs;
    t_deq_int      S;
    t_deq_int      pend;
    t_deq_int      jacobsthal;
};

t_vec_str_c & PmergeMe::sort_with_deque()
{
    struct s_deques deques;
    return _sorted;
}

// -------------------------------------------------------------------------- //
