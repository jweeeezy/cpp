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
#include <stdexcept>    // needed for std::invalid_argument
#include <utility>      // needed for std::pair
#include <vector>       // needed for std::vector

#ifdef DEBUG
#include <iostream> // needed for std::cout, std::cerr
#endif

#define EVEN 0
#define ODD  1

template <typename T>
static void insert_with_binary_search(T & container, int value)
{
    int low = 0;
    int high = container.size() - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        typename T::iterator it = container.begin();
        std::advance(it, mid);

        if (*it == value)
        {
            container.insert(it, value);
        }
        else if (*it > value)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    container.insert(container.begin(), value);
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

static t_lst_pair_int lst_to_pairs(t_lst_int_c & lst, t_lst_pair_int & pairs)
{
    t_lst_int_cit it = lst.begin();
    while (it != lst.end())
    {
        int first = *it++;
        int second = *it++;

        std::pair<int, int> pair;
        if (first < second)
        {
            pair.first = second;
            pair.second = first;
        }
        else
        {
            pair.first = first;
            pair.second = second;
        }
        pairs.push_back(pair);
    }
    return pairs;
}

static void insert_number_into_sequence(int number, t_lst_int & sequence)
{
    for (t_lst_int_it it = sequence.begin(); it != sequence.end(); ++it)
    {
        if (*it > number)
        {
            sequence.insert(it, number);
            return;
        }
    }
    sequence.push_back(number);
}
static void extract_S_and_pend(t_lst_pair_int_c & pairs, t_lst_int & S,
                               t_lst_int & pend)
{
    for (t_lst_pair_int_cit it = pairs.begin(); it != pairs.end(); ++it)
    {
        pend.push_back(it->second);
        if (S.empty() == true)
        {
            S.push_back(it->first);
            continue;
        }
        insert_number_into_sequence(it->first, S);
    }
}

static int generate_next_number(t_lst_int & lst)
{
    int tmp = *(lst.rbegin()) + 2 * *(++lst.rbegin());
    lst.push_back(tmp);
    return tmp;
}

static t_lst_int generate_jacobs_numbers(t_lst_int_c & pend, t_lst_int & lst)
{
    lst.push_back(0);
    lst.push_back(1);

    for (int i = 0; i < static_cast<int>(pend.size());)
    {
        i = generate_next_number(lst);
    }
    return lst;
}

void PmergeMe::sort_with_deque() const
{
    std::deque<int> deq;
    log_container(deq, "deque");
}

/* @note template */
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

    vector_to_container(d.lst);
    log_container(d.lst, "after moving");

    /* @note make template */
    lst_to_pairs(d.lst, d.pairs);
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

void PmergeMe::handle_straggler()
{
    _straggler = -1;
    if (_args.size() % 2 == ODD)
    {
        _straggler = get_parsed_int(--_args.end());
        _args.pop_back();
    }
}

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
        _straggler = rhs._straggler;
    }
    return *this;
}

PmergeMe::PmergeMe(int argc, char ** argv) : _argc(argc), _argv(argv)
{
    log_debug("parsing constructor called");

    parse_arguments();
    log_container(_args, "arguments");

    handle_straggler();
    log_straggler();
}

// -------------------------------------------------------------------------- //
