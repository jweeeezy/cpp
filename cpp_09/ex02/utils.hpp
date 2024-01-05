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
template <typename T> void log_container(T & container, t_str_c & name)
{
    (void)container;
    (void)name;
#ifdef DEBUG
    std::cerr << LIGHT_BLUE << name << ": " << RESET;
    for (typename T::const_iterator it = container.begin();
         it != container.end();
         ++it)
    {
        std::cerr << *it << " ";
    }
    std::cerr << "\n";
#endif
}

/* converts a given container to a string (expects container holding strings) */
template <typename T> t_str_c container_to_str(T & container)
{
    std::stringstream ss;
    for (typename T::const_iterator it = container.begin();
         it != container.end();
         ++it)
    {
        ss << *it << " ";
    }
    return ss.str();
}

/* checks if given container is sorted (expects ints) */
template <typename T> bool is_sorted(T & container)
{
    for (typename T::const_iterator it = container.begin();
         it != container.end();
         ++it)
    {
        typename T::const_iterator next = it;
        ++next;
        if (next == container.end())
        {
            break;
        }
        if (*it > *next)
        {
            return false;
        }
    }
    return true;
}

/* logs if given container is sorted (expects strings) */
template <typename T> void log_is_sorted(T & container, t_str_c & name)
{
    (void)container;
    (void)name;
#ifdef DEBUG
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
    typename T::iterator it = container.begin();
    std::advance(it, index);
    return *it;
}

#endif // UTILS

// -------------------------------------------------------------------------- //
