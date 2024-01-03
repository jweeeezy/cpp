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
#include <algorithm>    // needed for std::advance
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
    t_lst_int      numbers;
    t_lst_pair_int pairs;
    t_lst_int      S;
    t_lst_int      pend;
    t_lst_int      jacobsthal;
};

void PmergeMe::insertion_sort_with_jacobsthal(struct s_data & lists) const
{
    t_lst_int sequence;
    while (1)
    {
        int current_jacobs = lists.jacobsthal.back();
        lists.jacobsthal.pop_back();
        int next_jacobs = lists.jacobsthal.back();
        if (next_jacobs == 0)
        {
            int current_value = access_container_by_index(lists.pend, 0);
            insert_with_binary_search(lists.S, current_value);
            sequence.push_back(current_value);
            break;
        }
        int index = current_jacobs - 1;
        while (index != next_jacobs - 1)
        {
            int current_value = access_container_by_index(lists.pend, index);
            insert_with_binary_search(lists.S, current_value);
            sequence.push_back(current_value);
            --index;
        }
    }
    log_container(sequence, "insertion sequence");
}

void PmergeMe::sort_with_list() const
{
    struct s_data lists;

    convert_args_to_container(lists.numbers);
    log_container(lists.numbers, "after moving");

    /* @note check if already sorted (if elements < 2) */

    make_pairs(lists.numbers, lists.pairs);
    log_list(lists.pairs, "lst with pairs");
    log_container(lists.numbers, "after pairing");

    extract_S_and_pend(lists.pairs, lists.S, lists.pend);
    log_container(lists.S, "S");
    log_container(lists.pend, "pend");

    lists.S.insert(lists.S.begin(), get_and_pop_front(lists.pend));
    log_container(lists.pend, "pend after removing first");

    generate_jacobsthal_numbers(lists.pend, lists.jacobsthal);
    log_container(lists.jacobsthal, "jacobsthal");

    insertion_sort_with_jacobsthal(lists);
    log_container(lists.S, "S after jacobs insertion");

    if (_straggler != -1)
    {
        insert_with_binary_search(lists.S, _straggler);
        log_container(lists.S, "S after straggler");
    }
    /* @note print S or return S */
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
