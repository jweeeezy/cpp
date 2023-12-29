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
#define ODD 1

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

static int get_parsed_int(t_vec_str_cit it)
{
    int tmp = std::atoi(it->c_str());
    if (tmp < 1)
    {
        throw std::invalid_argument("only positive integers allowed!");
    }
    return tmp;
}

static t_lst_pair_int lst_to_pairs(t_lst_int_c & lst)
{
    t_lst_pair_int pairs;
    t_lst_int_cit  it = lst.begin();
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

static t_lst_int extract_smaller_from_pair(t_lst_pair_int_c & pairs)
{
    t_lst_int sequence;
    for (t_lst_pair_int_cit it = pairs.begin(); it != pairs.end(); ++it)
    {
        int number = it->second;
        if (sequence.empty() == true)
        {
            sequence.push_back(number);
            continue;
        }
        insert_number_into_sequence(number, sequence);
    }
    return sequence;
}

static t_lst_int extract_bigger_from_pair(t_lst_pair_int_c & pairs)
{
    t_lst_int sequence;
    for (t_lst_pair_int_cit it = pairs.begin(); it != pairs.end(); ++it)
    {
        int number = it->first;
        if (sequence.empty() == true)
        {
            sequence.push_back(number);
            continue;
        }
        insert_number_into_sequence(number, sequence);
    }
    return sequence;
}

static int generate_next_number(t_lst_int & lst)
{
    int tmp = *(lst.rbegin()) + 2 * *(++lst.rbegin());
    lst.push_back(tmp);
    return tmp;
}

static t_lst_int generate_jacobs_numbers(t_lst_int_c & pend)
{
    t_lst_int lst;
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

void PmergeMe::sort_with_list()
{
    t_lst_int lst = vector_to_lst();
    log_container(lst, "after moving");

    t_lst_pair_int pairs = lst_to_pairs(lst);
    log_list(pairs, "lst with pairs");
    log_container(lst, "after pairing");

    /* @note could make this in one loop */
    t_lst_int S = extract_bigger_from_pair(pairs);
    t_lst_int pend = extract_smaller_from_pair(pairs);
    log_container(S, "S");
    log_container(pend, "pend");

    t_lst_int jacobs_no = generate_jacobs_numbers(pend);
    log_container(jacobs_no, "jacobsthal");

    if (_straggler != -1)
    {
        insert_with_binary_search(S, _straggler);
        log_container(S, "S after straggler");
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

/*@note should prob be a template */
t_lst_int PmergeMe::vector_to_lst() const
{
    t_lst_int     lst;
    t_vec_str_cit it = _args.begin();
    while (it != _args.end())
    {
        int tmp = get_parsed_int(it);
        if (std::find(lst.begin(), lst.end(), tmp) != lst.end())
        {
            throw std::invalid_argument("no duplicates allowed!");
        }
        lst.push_back(tmp);
        ++it;
    }
    return lst;
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
