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
#include <algorithm>    // needed for std::find
#include <list>         // needed for std::list

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

void PmergeMe::sort_with_deque() const
{
    std::deque<int> deq;
    log_deque(deq, "deque");
}

static bool is_even(size_t n)
{
    if (n % 2 == 0)
    {
        return true;
    }
    return false;
}

static int get_parsed_int(std::list<int> const & lst, t_vec_str_cit it)
{
    int tmp = std::atoi(it->c_str());
    if (tmp < 1)
    {
        throw std::invalid_argument("only positive integers allowed!");
    }
    if (std::find(lst.begin(), lst.end(), tmp) != lst.end())
    {
        throw std::invalid_argument("no duplicates allowed!");
    }
    return tmp;
}

void PmergeMe::sort_with_list() const
{
    std::list<int> lst;
    bool           even = is_even(lst.size());

    t_vec_str_cit it = _args.begin();
    while (it != _args.end())
    {
        int x = get_parsed_int(lst, it);
        int y = get_parsed_int(lst, it + 1);
        lst.push_back(x);
        lst.push_back(y);
        if (it != _args.end())
        {
            it = it + 2;
        }
    }

    /* @Note different loop for odd or implement it in loop? */

    (void)even;
    log_list(lst, "list");

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
