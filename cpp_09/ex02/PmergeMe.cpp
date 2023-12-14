// ========================================================================== //
//                               42 | Heilbronn                               //
// ========================================================================== //
//                                                                            //
// name:  jakob willert (jwillert)                                            //
// mail:  jwillert@student.42heilbronn.de                                     //
// file:  PmergeMe.cpp                                                        //
//                                                                            //
// -------------------------------------------------------------------------- //

#include "PmergeMe.hpp" // needed for PmergeMe class, typedefs, std::vector

PmergeMe::PmergeMe() { log_debug("default constructor called"); }
PmergeMe::~PmergeMe() { log_debug("destructor called"); }
PmergeMe::PmergeMe(PmergeMe const & src)
{
    log_debug("copy constructor called");
    *this = src;
}

PmergeMe & PmergeMe::operator=(PmergeMe const & rhs)
{
    log_debug("assignment operator called");
    if (this != &rhs)
    {
        _argc = rhs._argc;
        _argv = rhs._argv;
        _args = rhs._args;
    }
    return *this;
}

PmergeMe::PmergeMe(int argc, char ** argv) : _argc(argc), _argv(argv)
{
    log_debug("parsing constructor called");
    parse_arguments();
    log_vector(_args, "arguments");
}

void PmergeMe::sort_with_vector() const { log_vector(_args, "vector"); }

void PmergeMe::sort_with_deque() const
{
    std::deque<int> deq;
    log_deque(deq, "deque");
}

void PmergeMe::sort_with_list() const
{

    /* group elements into n / 2 pairs,
     * leave one element unpaired if necessary */

    /* perform n/2 comparisons, one per pair,
     * to determine the larger of the two elements in each pair */

    /* recursively sort the n/2 larger elements from each pair,
     * creating a sorted sequence S in ascending order */

    /* insert at the start of S the element that was paired with
     * the first and smallest element of S */

    /* insert the remaining n / 2 - 1 elements of X \ S into S,
     * one at a time, with a specially chosen insertion.
     * use binary search in subsequences of S to determine the position
     * at which each element should be inserted */
}

// -------------------------------------------------------------------------- //
