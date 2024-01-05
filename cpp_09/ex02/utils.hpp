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

#include "typedefs.hpp" // needed for typedefs
#include <algorithm>    // needed for std::advance
#include <sstream>      // needed for std::stringstream

/* converts a container type to a std::vector<std::string> */
template <typename T> t_vec_str container_to_vec_str(T & container)
{
    t_vec_str vec;
    for (typename T::const_iterator it = container.begin();
         it != container.end(); ++it)
    {
        std::ostringstream os;
        os << *it;
        vec.push_back(os.str());
    }
    return vec;
}

/* outputs the content of a container (expects int) */
template <typename T> void log_container(T & container, t_str_c & name)
{
    (void)container;
    (void)name;
#ifdef DEBUG
    std::cerr << LIGHT_BLUE << name << ": " << RESET;
    for (typename T::const_iterator it = container.begin();
         it != container.end(); ++it)
    {
        std::cerr << *it << " ";
    }
    std::cerr << "\n";
#endif
}

/* checks if given container is sorted (expects strings) */
template <typename T> bool is_sorted(T & container)
{
    for (typename T::const_iterator it = container.begin();
         it != container.end(); ++it)
    {
        typename T::const_iterator next = it;
        ++next;
        if (next == container.end())
        {
            break;
        }
        if (std::atoi(it->c_str()) > std::atoi(next->c_str()))
        {
            return false;
        }
    }
    return true;
}

/* logs if given container is sorted (expects strings) */
template <typename T>
void log_is_sorted(T & container, std::string const & name)
{
    (void)container;
    (void)name;
#ifdef DEBUG
    log_container(container, "container to be checked");

    if (is_sorted(container) == false)
    {
        std::cerr << name << RED << "is not sorted!\n" << RESET;
    }
    else
    {
        std::cerr << name << GREEN << " is sorted!\n" << RESET;
    }
#endif
}

/* helper function for generate_jacobsthal_numbers */
template <typename T> static int generate_next_number(T & jacobs)
{
    int tmp = *(jacobs.rbegin()) + 2 * *(++jacobs.rbegin());
    jacobs.push_back(tmp);
    return (tmp);
}

/* generates jacobsthal numbers with the help of sequence pends size as a given
 * container type*/
template <typename T> void generate_jacobsthal_numbers(T & pend, T & jacobsthal)
{
    jacobsthal.push_back(0);
    jacobsthal.push_back(1);
    for (int i = 0; i < static_cast<int>(pend.size());)
    {
        i = generate_next_number(jacobsthal);
    }
}

/* inserts an int value into given container with binary search */
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

/* extracts sorted sequence S and unsorted sequence pend out of an int pairs
 * container */
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
        S.push_back(it->first);
    }
}

/* makes int pairs out of the given numbers container */
template <typename T1, typename T2> void make_pairs(T1 & numbers, T2 & pairs)
{
    typename T1::const_iterator it = numbers.begin();
    while (it != numbers.end())
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

/* converts a std::vector<std::string> to given container type */
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

/* removes front value and returns it from given container */
template <typename T> int get_and_pop_front(T & container)
{
    int tmp = container.front();
    container.pop_front();
    return tmp;
}

/* access any container with an index and return the value */
template <typename T> int access_container_by_index(T & container, int index)
{
    t_lst_int_it it = container.begin();
    std::advance(it, index);
    return *it;
}

#endif // UTILS

// -------------------------------------------------------------------------- //
