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
#include "utils.hpp"    // needed for container utils
#include <algorithm>    // needed for std::advance
#include <list>         // needed for std::list
#include <sstream>      // needed for std::stringstream
#include <stdexcept>    // needed for std::invalid_argument
#include <vector>       // needed for std::vector

t_vec_str_c & PmergeMe::get_unsorted_args() const { return _args; }

t_vec_str_c & PmergeMe::get_sorted_args() const
{
    if (_sorted.empty() == true)
    {
        throw std::runtime_error("PmergeMe: not sorted yet!\n");
    }
    return _sorted;
}

PmergeMe::PmergeMe(int argc, char ** argv) : _argc(argc), _argv(argv)
{
    log_debug("parsing constructor called");

    parse_arguments();
    log_container(_args, "_args");

    handle_straggler();
    log_straggler();
}

PmergeMe & PmergeMe::operator=(PmergeMe const & rhs)
{
    log_debug("assignment operator called");
    if (this != &rhs)
    {
        _argc      = rhs._argc;
        _argv      = rhs._argv;
        _args      = rhs._args;
        _straggler = rhs._straggler;
    }
    return *this;
}

PmergeMe::PmergeMe(PmergeMe const & src)
{
    log_debug("copy constructor called");
    *this = src;
}

PmergeMe::PmergeMe() { log_debug("default constructor called"); }
PmergeMe::~PmergeMe() { log_debug("destructor called"); }

// -------------------------------------------------------------------------- //
