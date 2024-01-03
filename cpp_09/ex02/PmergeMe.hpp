// ========================================================================== //
//                               42 | Heilbronn                               //
// ========================================================================== //
//                                                                            //
// name:  jakob willert (jwillert)                                            //
// mail:  jwillert@student.42heilbronn.de                                     //
// file:  PmergeMe.hpp                                                        //
//                                                                            //
// -------------------------------------------------------------------------- //

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <deque>  // needed for std::deque
#include <list>   // needed for std::map
#include <string> // needed for std::string
#include <vector> // needed for std::vector

#ifdef DEBUG
#include <iostream>
#endif

#define YELLOW "\033[033m"
#define RESET  "\033[0m"

/* typedefs */
/* @note should prob just add them internally in the source files */
typedef std::string t_str;
typedef t_str const t_str_c;

typedef std::vector<t_str>        t_vec_str;
typedef t_vec_str const           t_vec_str_c;
typedef t_vec_str::iterator       t_vec_str_it;
typedef t_vec_str::const_iterator t_vec_str_cit;

typedef std::vector<int>          t_vec_int;
typedef t_vec_int const           t_vec_int_c;
typedef t_vec_int::iterator       t_vec_int_it;
typedef t_vec_int::const_iterator t_vec_int_cit;

typedef std::list<int>            t_lst_int;
typedef t_lst_int const           t_lst_int_c;
typedef t_lst_int::iterator       t_lst_int_it;
typedef t_lst_int::const_iterator t_lst_int_cit;

typedef std::list<std::pair<int, int> > t_lst_pair_int;
typedef t_lst_pair_int const           t_lst_pair_int_c;
typedef t_lst_pair_int::iterator       t_lst_pair_int_it;
typedef t_lst_pair_int::const_iterator t_lst_pair_int_cit;

typedef std::deque<int>           t_deq_int;
typedef t_deq_int const           t_deq_int_c;
typedef t_deq_int::iterator       t_deq_int_it;
typedef t_deq_int::const_iterator t_deq_int_cit;

class PmergeMe
{

  public:
    PmergeMe(int argc, char ** argv);
    PmergeMe();
    PmergeMe(PmergeMe const & src);
    ~PmergeMe();
    PmergeMe & operator=(PmergeMe const & rhs);

    void sort_with_deque() const;
    void sort_with_list() const;

  private:
    void log_debug(t_str_c & message) const;
    void log_straggler() const;
    void log_list(t_lst_pair_int_c & lst, t_str_c & name) const;

    /* @note could just make separate .hpp file for the template functions so
     * they dont pollute the class */

    template <typename T> void log_container(T container, t_str_c & name) const
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

    template <typename T> T convert_args_to_container(T & container) const
    {
        t_vec_str_cit it = _args.begin();

        while (it != _args.end())
        {
            int tmp = get_parsed_int(it);
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

    template <typename T1, typename T2>
    void make_pairs(T1 & lst, T2 & pairs) const
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
    void insert_number_into_sequence(int number, T & sequence) const
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

    template <typename T1, typename T2>
    void extract_S_and_pend(T1 & pairs, T2 & S, T2 & pend) const
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

    template <typename T> int generate_next_number(T & jacobs) const
    {
        int tmp = *(jacobs.rbegin()) + 2 * *(++jacobs.rbegin());
        jacobs.push_back(tmp);
        return (tmp);
    }

    template <typename T>
    void generate_jacobs_numbers(T & pend, T & jacobs) const
    {
        jacobs.push_back(0);
        jacobs.push_back(1);
        for (int i = 0; i < static_cast<int>(pend.size());)
        {
            i = generate_next_number(jacobs);
        }
    }

    /* @note look at this again */
    template <typename T>
    static void insert_with_binary_search(T & container, int value)
    {
        int low  = 0;
        int high = container.size() - 1;

        while (low <= high)
        {
            int                  mid = low + (high - low) / 2;
            typename T::iterator it  = container.begin();
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
                // Handle the case when the value is equal to *it
                container.insert(it, value);
                return;
            }
        }

        // If the value is not found, insert it at the appropriate position
        typename T::iterator it = container.begin();
        std::advance(it, low);
        container.insert(it, value);
    }

    int  get_parsed_int(t_vec_str_cit it) const;
    void parse_arguments();
    void handle_straggler();

    void insertion_sort_with_jacobs_numbers(struct s_data & d) const;

    int       _argc;
    char **   _argv;
    t_vec_str _args;
    int       _straggler;
};

#endif // PMERGEME

// -------------------------------------------------------------------------- //
