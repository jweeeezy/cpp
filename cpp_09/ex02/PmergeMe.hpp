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

#include "typedefs.hpp" // needed for types and typedefs
#include "utils.hpp"    // needed for template util functions

class PmergeMe
{
  private:
#define NO_STRAGGLER -1
#define ODD          1

  public:
    /* location: PmergeMe.cpp */
    PmergeMe(int argc, char ** argv);
    PmergeMe & operator=(PmergeMe const & rhs);
    PmergeMe(PmergeMe const & src);
    ~PmergeMe();

    /* locaton: PmergeMe.cpp */
    t_vec_str_c get_unsorted_args() const;

    /* location: PmergeMe.SortList.cpp */
    t_lst_int_c sort_with_list() const;

    /* location: PmergeMe.SortDeque.cpp */
    t_deq_int_c sort_with_deque() const;

  private:
    /* location: PmergeMe.cpp */
    PmergeMe();

    /* location: PmergeMe.Logs.cpp */
    void log_debug(t_str_c & message) const;
    void log_straggler() const;
    void log_pairs(t_lst_pair_int_c & pairs, t_str_c & name) const;
    void log_pairs(t_deq_pair_int_c & pairs, t_str_c & name) const;

    /* location: PmergeMe.Parsing.cpp */
    void parse_arguments();
    void handle_straggler();

    int       _argc;
    char **   _argv;
    t_vec_str _args;
    int       _straggler;

  private:
    /* template functions for the FJMI */

    /* converts a std::vector<std::string> to given container type */
    template <typename T>
    void convert_args_to_container(t_vec_str_c & args, T & container) const
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
    }

    /* makes int pairs out of the given numbers container */
    template <typename T1, typename T2>
    void make_pairs(T1 & numbers, T2 & pairs) const
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

    /* extracts sorted sequence S and unsorted sequence pend out of an int pairs
     * container */
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
            S.push_back(it->first);
        }
    }

    /* helper function for generate_jacobsthal_numbers */
    template <typename T> int generate_next_number(T & jacobs) const
    {
        int tmp = *(jacobs.rbegin()) + 2 * *(++jacobs.rbegin());
        jacobs.push_back(tmp);
        return (tmp);
    }

    /* generates jacobsthal numbers with the help of sequence pends size as a
     * given container type*/
    template <typename T>
    void generate_jacobsthal_numbers(T & pend, T & jacobsthal) const
    {
        jacobsthal.push_back(0);
        jacobsthal.push_back(1);
        for (int i = 0; i < static_cast<int>(pend.size());)
        {
            i = generate_next_number(jacobsthal);
        }
    }

    /* generates a sequence of indexes with the help of the previously generated
     * jacosbthal numbers in what order the numbers from pend should be inserted
     * into S */
    template <typename T> void insertion_sort_with_jacobsthal(T & lists) const
    {
        t_lst_int sequence;
        while (1)
        {
            int current_jacobs = lists.jacobsthal.back();
            lists.jacobsthal.pop_back();

            int next_jacobs = lists.jacobsthal.back();
            if (next_jacobs == 0)
            {
                int current_value = access_container_by_index(lists.pend, 0);
                insert_with_binary_search(lists.S, current_value);
                sequence.push_back(current_value);
                break;
            }

            /* NEW !! */
            int index;
            if (current_jacobs > static_cast<int>(lists.pend.size()))
            {
                index = static_cast<int>(lists.pend.size() - 1);
            }
            else
            {
                index = current_jacobs - 1;
            }

            while (index != next_jacobs - 1)
            {
                int current_value =
                    access_container_by_index(lists.pend, index);
                insert_with_binary_search(lists.S, current_value);
                sequence.push_back(current_value);
                --index;
            }
        }
        log_container(sequence, "insert sequence");
    }
};

#endif // PMERGEME

// -------------------------------------------------------------------------- //
