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
        int x = get_parsed_int(lst, it);
        int y = get_parsed_int(lst, it + 1);
        sort_in_pair(lst, x, y);
        if (it + 3 == _args.end())
        {
            int x = get_parsed_int(lst, it + 2);
            lst.push_back(x);
            break;
        }
        it += 2;
    }
    return lst;
}

void do_step_2(t_lst_int & lst, t_lst_int_it & it, int & end, int & stop,
               int & index)
{
    int tmp = *it;
#ifdef DEBUG
    std::cerr << "pushes back " << tmp << "\n";
#endif // DEBUG

    {
        t_lst_int_it bla = lst.begin();
        while (*bla != end)
        {
            ++bla;
        }
        {
            t_lst_int_it cpy = bla;
            ++cpy;
            while (cpy != lst.end() || tmp > *cpy)
            {
                ++cpy;
            }
            lst.insert(cpy, tmp);
            /* if first value, just push back */
            /* if next value is bigger, insert here */
            /* if next value is smaller, advance */
        }
    }
    it = lst.erase(it);
    stop += 1;
    index = 0;
    it = lst.begin();
}

void PmergeMe::sort_with_list() const
{
    bool even_or_odd = is_even(_args.size());

    /* step 1 algorithm */
    t_lst_int lst = vector_to_lst();
    log_list(lst, "step 1 (comparison)");

    /* step 2 algorithm */
    {
        t_lst_int_it it = lst.begin();
        int          end = *(--lst.end());
        int          index = 0;
        int          stop = 1;

        while (*it != end)
        {
            if (index == stop)
            {
                do_step_2(lst, it, end, stop, index);
            }
            ++index;
            ++it;
        }
        if (even_or_odd == EVEN)
        {
            do_step_2(lst, it, end, stop, index);
        }
    }
    log_list(lst, "step 2 (larger elements)");

    /* group elements into n / 2 pairs,
     * leave one element unpaired if necessary */
    /* perform n/2 comparisons, one per pair,
     * to determine the larger of the two elements in each pair */

    /* recursively sort the n/2 larger elements from each pair,
     * creating a sorted sequence S in ascending order */

    /* insert at the start of S the element that was paired with
     * the first and smallest element of S */
    /* insert the remaining n / 2 - 1 elements of X \ S into S,
     * one at a time, with a specially chosen insertion.
     * use binary search in subsequences of S to determine the position
     * at which each element should be inserted */
}

// -------------------------------------------------------------------------- //
