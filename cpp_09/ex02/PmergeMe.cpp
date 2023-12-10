// ========================================================================== //
//                               42 | Heilbronn                               //
// ========================================================================== //
//                                                                            //
// name:  jakob willert (jwillert)                                            //
// mail:  jwillert@student.42heilbronn.de                                     //
// file:  PmergeMe.cpp                                                        //
//                                                                            //
// -------------------------------------------------------------------------- //
#include "PmergeMe.hpp" // needed for PmergeMe class
#include <iostream>     // needed for std::cerr

#define YELLOW "\033[033m"
#define RESET  "\033[0m"

void PmergeMe::log_debug(std::string const & message) const
{
    (void) message;
#ifdef DEBUG
    std::cerr << YELLOW << "PmergeMe: " << message << RESET << "\n";
#endif // DEBUG
}

PmergeMe::PmergeMe()
{
    log_debug("default constructor called");
}

PmergeMe::PmergeMe(PmergeMe const & src)
{
    log_debug("copy constructor called");
    *this = src;
}

PmergeMe::PmergeMe(int argc, char ** argv) : _argc(argc)
{
    log_debug("parsing constructor called");
    parse_arguments(argv);
}

PmergeMe::~PmergeMe()
{
    log_debug("destructor called");
}

PmergeMe & PmergeMe::operator=(PmergeMe const & rhs)
{
    log_debug("assignment operator called");
    if (this != &rhs)
    {
    }
    return *this;
}

void PmergeMe::parse_arguments(char ** argv)
{
    for (int i = 1; i <= _argc ; ++i)
    {
        int tmp = std::atoi(argv[i]);
        std::cout << tmp << " ";
    }
    std::cout << "\n";
}

// -------------------------------------------------------------------------- //
