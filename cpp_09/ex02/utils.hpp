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

/* outputs the content of a container (expects int) */
template <typename T> void log_container(T const & container, t_str_c & name)
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

/* outputs the content of a container (std::pair<int, int>) */
template <typename T> void log_pairs(T const & pairs, t_str_c & name)
{
    (void)pairs;
    (void)name;
#ifdef DEBUG
    std::cerr << LIGHT_BLUE << name << ": " << RESET;
    for (typename T::const_iterator it = pairs.begin(); it != pairs.end(); ++it)
    {
        std::cerr << "[" << it->first << "|" << it->second << "] ";
    }
    std::cerr << "\n" << RESET;
#endif
}

/* converts a given container to a string (expects container holding strings) */
template <typename T> t_str_c container_to_str(T const & container)
{
    std::stringstream ss;
    for (typename T::const_iterator it = container.begin();
         it != container.end(); ++it)
    {
        ss << *it << " ";
    }
    return ss.str();
}

/* logs if given container is sorted (expects strings) */
template <typename T> void log_is_sorted(T const & container, t_str_c & name)
{
    (void)container;
    (void)name;
#ifdef DEBUG
    if (std::is_sorted(container.begin(), container.end()) == false)
    {
        std::cerr << name << RED << "is not sorted!\n" << RESET;
    }
    else
    {
        std::cerr << name << GREEN << " is sorted!\n" << RESET;
    }
#endif
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

/* removes back value and returns it from given container */
template <typename T> int get_and_pop_back(T & container)
{
    int tmp = container.back();
    container.pop_back();
    return tmp;
}

/* removes front value and returns it from given container */
template <typename T> int get_and_pop_front(T & container)
{
    int tmp = container.front();
    container.pop_front();
    return tmp;
}

/* access any container with an index and return the value */
template <typename T>
int access_container_by_index(T const & container, int index)
{
    typename T::const_iterator it = container.begin();
    std::advance(it, index);
    return *it;
}

/* insert a value (get by index) from a container and track it into sequence */
template <typename T_c, typename T_base>
void insert_and_track_by_index(T_c & c, T_base & sequence, int index)
{
    int current_value = access_container_by_index(c.pend, index);
    insert_with_binary_search(c.S, current_value);
    sequence.push_back(current_value);
}

/* if the given jacobsthal number is bigger than container(pend).size() advance
 * the index accordingly */
template <typename T>
int advance_index_if_out_of_bounds(T const & pend, int current_jacobs)
{
    int index;
    if (current_jacobs > static_cast<int>(pend.size()))
    {
        index = static_cast<int>(pend.size() - 1);
    }
    else
    {
        index = current_jacobs - 1;
    }
    return index;
}

/* creates a container with the given value (expects int) */
template <typename T> T create_with_value(int value)
{
    T obj;
    obj.push_back(value);
    return obj;
}

#endif // UTILS

// -------------------------------------------------------------------------- //
