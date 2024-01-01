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
#include <list>         // needed for std::list
#include <stdexcept>    // needed for std::invalid_argument
#include <vector>       // needed for std::vector

#ifdef DEBUG
#include <iostream> // needed for std::cout, std::cerr
#endif

#define EVEN 0
#define ODD  1

struct s_data
{
    t_lst_int      lst;
    t_lst_pair_int pairs;
    t_lst_int      S;
    t_lst_int      pend;
    t_lst_int      jacobs_no;
};

void PmergeMe::sort_with_list() const
{
    struct s_data d;

    convert_args_to_container(d.lst);
    log_container(d.lst, "after moving");

    make_pairs(d.lst, d.pairs);
    log_list(d.pairs, "lst with pairs");
    log_container(d.lst, "after pairing");

    extract_S_and_pend(d.pairs, d.S, d.pend);
    log_container(d.S, "S");
    log_container(d.pend, "pend");

    generate_jacobs_numbers(d.pend, d.jacobs_no);
    log_container(d.jacobs_no, "jacobsthal");

    /* @note next step algorithm */

    if (_straggler != -1)
    {
        insert_with_binary_search(d.S, _straggler);
        log_container(d.S, "S after straggler");
    }
}

void PmergeMe::sort_with_deque() const
{
    std::deque<int> deq;
    log_container(deq, "deque");
}

int PmergeMe::get_parsed_int(t_vec_str_cit it) const
{
    int tmp = std::atoi(it->c_str());
    if (tmp < 1)
    {
        throw std::invalid_argument("only positive integers allowed!");
    }
    return tmp;
}

void PmergeMe::handle_straggler()
{
    _straggler = -1;
    if (_args.size() % 2 == ODD)
    {
        _straggler = get_parsed_int(--_args.end());
        _args.pop_back();
    }
}

PmergeMe::PmergeMe(int argc, char ** argv) : _argc(argc), _argv(argv)
{
    log_debug("parsing constructor called");

    parse_arguments();
    log_container(_args, "arguments");

    handle_straggler();
    log_straggler();
}

PmergeMe & PmergeMe::operator=(PmergeMe const & rhs)
{
    log_debug("assignment operator called");
    if (this != &rhs)
    {
        _argc = rhs._argc;
        _argv = rhs._argv;
        _args = rhs._args;
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
