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
    log_vector(_args, "arguments");
}

void PmergeMe::sort_with_deque() const
{
    std::deque<int> deq;
    log_deque(deq, "deque");
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

static int get_parsed_int(t_lst_int_c & lst, t_vec_str_cit it)
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
        int first  = get_parsed_int(lst, it);
        int second = get_parsed_int(lst, it + 1);
        sort_in_pair(lst, first, second);
        if (it + 3 == _args.end())
        {
            int last = get_parsed_int(lst, it + 2);
            lst.push_back(last);
            break;
        }
        it += 2;
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

void lst_insert_into_sequence_and_erase(t_lst_int &  lst,
                                        t_lst_int_it it,
                                        t_lst_int_it end)
{
#ifdef DEBUG
    std::cerr << "sorts " << *it << " into the sequence\n";
#endif // DEBUG
    t_lst_int_it itr = ++lst_get_iter_by_value(lst, *end);
    lst_insert_into_sequence(lst, itr, *it);
    lst.erase(it);
}

void PmergeMe::sort_with_list() const
{
    bool even_or_odd = is_even(_args.size());

    /* step 1 algorithm */
    t_lst_int lst = vector_to_lst();
    log_list(lst, "step 1 (comparison)");

    /* step 2 algorithm */
    int end = *(--lst.end());
    {
        t_lst_int_it it    = lst.begin();
        int          index = 0;
        int          stop  = 1;
        while (it != lst.end() && *it != end)
        {
            if (index == stop)
            {
                lst_insert_into_sequence_and_erase(lst,
                                                   it,
                                                   lst_get_iter_by_value(lst,
                                                                         end));
                stop += 1;
                index = 0;
                it    = lst.begin();
            }
            ++index;
            ++it;
        }
        if (even_or_odd == EVEN)
        {
            lst_insert_into_sequence_and_erase(lst,
                                               it,
                                               lst_get_iter_by_value(lst, end));
        }
    }
    log_list(lst, "step 2 (larger elements)");

    /* step 3 algorithm */
    {
        int tmp = *lst.begin();
        lst_insert_into_sequence_and_erase(lst,
                                           lst_get_iter_by_value(lst, tmp),
                                           lst_get_iter_by_value(lst, end));
    }
    log_list(lst, "step 3 (insertion sort)");

    /* algorithm step 1 */
    /* group elements into n / 2 pairs,
     * leave one element unpaired if necessary */
    /* perform n/2 comparisons, one per pair,
     * to determine the larger of the two elements in each pair */

    /* algorithm step 2 */
    /* recursively sort the n/2 larger elements from each pair,
     * creating a sorted sequence S in ascending order */

    /* algorithm step 3 */

    /* insert at the start of S the element that was paired with
     * the first and smallest element of S */
    /* insert the remaining n / 2 - 1 elements of X \ S into S,
     * one at a time, with a specially chosen insertion.
     * use binary search in subsequences of S to determine the position
     * at which each element should be inserted */
}

// -------------------------------------------------------------------------- //
