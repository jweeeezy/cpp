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

#define EVEN true
#define ODD  false

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
    log_container(_args, "arguments");
}

void PmergeMe::sort_with_deque() const
{
    std::deque<int> deq;
    log_container(deq, "deque");
}

std::string bool_to_string(bool is)
{
    if (is == ODD)
        return "<odd>";
    else
        return "<even>";
}

static bool is_even(size_t n)
{
    bool is = n % 2 == 0;
#ifdef DEBUG
    std::cerr << bool_to_string(is) << " no of elements\n";
#endif // DEBUG
    return is;
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

void sort_in_pair(t_lst_int & lst, int x, int y)
{
    /* @note not sure if correct order */
    if (x < y)
    {
        lst.push_back(x);
        lst.push_back(y);
    }
    else
    {
        lst.push_back(y);
        lst.push_back(x);
    }
}

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

t_lst_int_it lst_get_iter_by_value(t_lst_int & lst, int value)
{
    t_lst_int_it it = lst.begin();
    while (it != lst.end() && *it != value)
    {
        ++it;
    }
    return it;
}

void lst_insert_into_sequence(t_lst_int & lst, t_lst_int_it & it, int value)
{
    while (it != lst.end() && *it < value)
    {
        ++it;
    }
    it = lst.insert(it, value);
}

void lst_insert_into_sequence_and_erase(t_lst_int & lst, t_lst_int_it it,
                                        t_lst_int_it end)
{
#ifdef DEBUG
    std::cerr << "sorts " << *it << " into the sequence\n";
#endif // DEBUG
    t_lst_int_it itr = ++lst_get_iter_by_value(lst, *end);
    lst_insert_into_sequence(lst, itr, *it);
    lst.erase(it);
}

t_lst_pair_int lst_to_pairs(t_lst_int_c & lst)
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

void insert_number_into_sequence(int number, t_lst_int & sequence)
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

t_lst_int extract_smaller_from_pair(t_lst_pair_int_c & pairs)
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

t_lst_int extract_bigger_from_pair(t_lst_pair_int_c & pairs)
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

int generate_next_number(t_vec_int & vec)
{
    int tmp = *(vec.rbegin()) + 2 * *(++vec.rbegin());
    vec.push_back(tmp);
    return tmp;
}

t_vec_int generate_jacobs_numbers(t_lst_int_c & pend)
{
    t_vec_int vec;
    vec.push_back(0);
    vec.push_back(1);

    /* @note what happens with 3000 elements? */
    for (int i = 0; i < static_cast<int>(pend.size());)
    {
        i = generate_next_number(vec);
    }
    return vec;
}

void PmergeMe::sort_with_list()
{
    /* @note bool is not needed, could just check for -1 in the end */
    bool even_or_odd = is_even(_args.size());
    int  straggler = -1;
    if (even_or_odd == ODD)
    {
        straggler = get_parsed_int(--_args.end());
        _args.pop_back();
    }
    (void)straggler; /* insert in the end */
    t_lst_int lst = vector_to_lst();
    log_container(lst, "after moving");

    t_lst_pair_int pairs = lst_to_pairs(lst);
    log_list(pairs, "lst with pairs");
    log_container(lst, "after pairing");

    /* @note could make this in one loop */
    t_lst_int seq_bigger = extract_bigger_from_pair(pairs);
    t_lst_int seq_smaller = extract_smaller_from_pair(pairs);
    log_container(seq_bigger, "S");
    log_container(seq_smaller, "pend");

    /* @note should this also be a lst? */
    t_vec_int jacobs_no = generate_jacobs_numbers(seq_smaller);
    log_container(jacobs_no, "jacobsthal");
}

// -------------------------------------------------------------------------- //
