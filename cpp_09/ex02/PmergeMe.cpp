// ========================================================================== //
//                               42 | Heilbronn                               //
// ========================================================================== //
//                                                                            //
// name:  jakob willert (jwillert)                                            //
// mail:  jwillert@student.42heilbronn.de                                     //
// file:  PmergeMe.cpp                                                        //
//                                                                            //
// -------------------------------------------------------------------------- //

#include <cstdlib>  // needed for std::atoi
#include <iostream> // needed for std::cerr

#include "PmergeMe.hpp" // needed for PmergeMe class

#define YELLOW "\033[033m"
#define RESET  "\033[0m"

void PmergeMe::log_debug(std::string const & message) const
{
    (void)message;
#ifdef DEBUG
    std::cerr << YELLOW << "PmergeMe: " << message << RESET << "\n";
#endif // DEBUG
}

PmergeMe::PmergeMe() { log_debug("default constructor called"); }

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

PmergeMe::~PmergeMe() { log_debug("destructor called"); }

PmergeMe & PmergeMe::operator=(PmergeMe const & rhs)
{
    log_debug("assignment operator called");
    if (this != &rhs)
    {
    }
    return *this;
}

bool is_positive_number(t_str_c & input)
{
    size_t pos = input.find_first_not_of("0123456789+");
    if (pos != t_str::npos || std::atoi(input.c_str()) <= 0)
    {
        return false;
    }
    return true;
}

t_vec_str_c PmergeMe::str_split_by(t_str_c & str, t_str_c & delimiter)
{
    t_vec_str vec;
    t_str     tmp(str);
    while (1)
    {
        size_t pos = tmp.find_first_of(delimiter);
        if (pos == t_str::npos)
        {
            pos = tmp.size();
        }
        vec.push_back(tmp.substr(0, pos));
        if (pos == tmp.size())
        {
            break;
        }
        else
        {
            tmp = tmp.substr(pos + 1, tmp.size());
        }
    }
    return vec;
}

t_vec_str_c PmergeMe::split_quotated_strings(char ** argv)
{
    t_vec_str vec;
    for (int i = 1; i <= _argc; ++i)
    {
        t_vec_str_c tmp = str_split_by(argv[i], " ");
        vec.insert(vec.end(), tmp.begin(), tmp.end());
    }
    return vec;
}

t_vec_str_c PmergeMe::parse_arguments(char ** argv)
{
    t_vec_str_c vec = split_quotated_strings(argv);
    for (t_vec_str_cit it = vec.begin(); it != vec.end(); ++it)
    {
        if (is_positive_number(*it) == false)
        {
            throw std::invalid_argument("only positive integers allowed!");
        }
    }
    return vec;
}

// -------------------------------------------------------------------------- //
