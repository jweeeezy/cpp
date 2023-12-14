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
        /* @note no deep copy i guess ? */
        _argc = rhs._argc;
        _argv = rhs._argv;
    }
    return *this;
}

PmergeMe::PmergeMe(int argc, char ** argv) : _argc(argc), _argv(argv)
{
    log_debug("parsing constructor called");
    parse_arguments();
    log_vector(_args, "arguments");
}

void PmergeMe::sort_with_vector() const
{
    log_vector(_args, "vector");
}

void PmergeMe::sort_with_deque() const
{
    std::deque<int> deq;
    for (t_vec_int_cit it = _args.begin(); it != _args.end(); ++it)
    {
        deq.push_back(*it);
    }
    log_deque(deq, "deque");
}

// -------------------------------------------------------------------------- //
