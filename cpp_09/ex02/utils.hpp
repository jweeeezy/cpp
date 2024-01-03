// ========================================================================== //
//                               42 | Heilbronn                               //
// ========================================================================== //
//                                                                            //
// name:  jakob willert (jwillert)                                            //
// mail:  jwillert@student.42heilbronn.de                                     //
// file:  utils.hpp                                                           //
//                                                                            //
// -------------------------------------------------------------------------- //

#ifndef UTILS_HPP
#define UTILS_HPP

#include "typedefs.hpp" // needed for types and typedefs
#include <algorithm>    // needed for std::advance

#ifdef DEBUG
/* @note make Yellow light blue or something visible other than white */
#define YELLOW "\033[033m"
#define RESET  "\033[0m"
#include <iostream> // needed for std::cerr
#endif

template <typename T> void log_container(T container, t_str_c & name)
{
    (void)container;
    (void)name;
#ifdef DEBUG
    std::cerr << YELLOW << name << ": " << RESET;
    for (typename T::const_iterator it = container.begin();
         it != container.end(); ++it)
    {
        std::cerr << *it << " ";
    }
    std::cerr << "\n";
#endif
}

/*@note binary search instead?? */
template <typename T> void insert_number_into_sequence(int number, T & sequence)
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

template <typename T> int generate_next_number(T & jacobs)
{
    int tmp = *(jacobs.rbegin()) + 2 * *(++jacobs.rbegin());
    jacobs.push_back(tmp);
    return (tmp);
}

template <typename T> void generate_jacobsthal_numbers(T & pend, T & jacobsthal)
{
    jacobsthal.push_back(0);
    jacobsthal.push_back(1);
    for (int i = 0; i < static_cast<int>(pend.size());)
    {
        i = generate_next_number(jacobsthal);
    }
}

template <typename T1, typename T2>
void extract_S_and_pend(T1 & pairs, T2 & S, T2 & pend)
{
    for (typename T1::const_iterator it = pairs.begin(); it != pairs.end();
         ++it)
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
template <typename T1, typename T2> void make_pairs(T1 & lst, T2 & pairs)
{
    typename T1::const_iterator it = lst.begin();
    while (it != lst.end())
    {
        int first  = *it++;
        int second = *it++;

        std::pair<int, int> pair;
        if (first < second)
        {
            pair.first  = second;
            pair.second = first;
        }
        else
        {
            pair.first  = first;
            pair.second = second;
        }
        pairs.push_back(pair);
    }
}

template <typename T>
T convert_args_to_container(t_vec_str_c & args, T & container)
{
    t_vec_str_cit it = args.begin();
    while (it != args.end())
    {
        int tmp = std::atoi(it->c_str());
        if (tmp < 1)
        {
            throw std::invalid_argument("only positive integers allowed!");
        }
        if (std::find(container.begin(), container.end(), tmp) !=
            container.end())
        {
            throw std::invalid_argument("no duplicates allowed!");
        }
        container.push_back(tmp);
        ++it;
    }
    return container;
}

template <typename T> int get_and_pop_front(T & container)
{
    int tmp = container.front();
    container.pop_front();
    return tmp;
}

template <typename T> int access_container_by_index(T & container, int index)
{
    t_lst_int_it it = container.begin();
    std::advance(it, index);
    return *it;
}

template <typename T> void insert_with_binary_search(T & container, int value)
{
    int low  = 0;
    int high = container.size() - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        typename T::iterator it = container.begin();
        std::advance(it, mid);

        if (value > *it)
        {
            low = mid + 1;
        }
        else if (value < *it)
        {
            high = mid - 1;
        }
        else
        {
            container.insert(it, value);
            return;
        }
    }
    typename T::iterator it = container.begin();
    std::advance(it, low);
    container.insert(it, value);
}

#endif // UTILS

// -------------------------------------------------------------------------- //
