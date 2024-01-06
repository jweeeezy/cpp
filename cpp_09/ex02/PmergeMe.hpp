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
    PmergeMe();

    t_vec_str_c get_unsorted_args() const;

    t_lst_int_c sort_with_list() const;
    t_deq_int_c sort_with_deque() const;

  private:
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

    /* compares pairs (left/first value) and merges them in ascending order into
     * the old container */
    template <typename T>
    void merge_sort(typename T::iterator first, typename T::iterator mid,
                    typename T::iterator last) const
    {
        T                    merged;
        typename T::iterator left  = first;
        typename T::iterator right = mid;

        while (left != mid && right != last)
        {
            if (left->first <= right->first)
            {
                merged.push_back(*left);
                ++left;
            }
            else
            {
                merged.push_back(*right);
                ++right;
            }
        }

        merged.insert(merged.end(), left, mid);
        merged.insert(merged.end(), right, last);

        std::copy(merged.begin(), merged.end(), first);
    }

    /* recursive function that splits the container recursively splits the
     * container in half and uses merge_sort to sort the pairs */
    template <typename T>
    void sort_pairs_by_larger_value(typename T::iterator first,
                                    typename T::iterator last) const
    {
        if (std::distance(first, last) > 1)
        {
            typename T::iterator mid = first;
            std::advance(mid, std::distance(first, last) / 2);

            sort_pairs_by_larger_value<T>(first, mid);
            sort_pairs_by_larger_value<T>(mid, last);

            merge_sort<T>(first, mid, last);
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

        /* build and insert with sequence */
        while (1)
        {
            /* @note get and pop back ? */
            int current_jacobs = lists.jacobsthal.back();
            lists.jacobsthal.pop_back();

            int next_jacobs = lists.jacobsthal.back();
            if (next_jacobs == 0)
            {
                /* @note same as below */
                int current_value = access_container_by_index(lists.pend, 0);
                insert_with_binary_search(lists.S, current_value);
                sequence.push_back(current_value);
                break;
            }

            /* @note mb abstract this one away */
            int index;
            if (current_jacobs > static_cast<int>(lists.pend.size()))
            {
                index = static_cast<int>(lists.pend.size() - 1);
            }
            else
            {
                index = current_jacobs - 1;
            }

            /* insert until next jacobs is reached */
            /* @note mb use for instead ? */
            while (index != next_jacobs - 1)
            {

                /* @note same as above */
                int current_value =
                    access_container_by_index(lists.pend, index);
                insert_with_binary_search(lists.S, current_value);
                sequence.push_back(current_value);
                --index;
            }
        }
        log_container(sequence, "insert sequence");
    }

    /* template generic struct to hold the data for the merge_insertion_sort */
    template <typename T_base, typename T_pairs> struct s_sort_data
    {
        T_base  numbers;
        T_pairs pairs;
        T_base  S;
        T_base  pend;
        T_base  jacobsthal;
    };

    /* template function for the merge insertion sort. expects a data struct
     * containing a containers type int (numbers, S, pend, jacobsthal) aswell as
     * a container pairs containing std::pair<int, int> */
    template <typename T_containers, typename T_base, typename T_pairs>
    T_base merge_insertion_sort() const
    {
        T_containers c;

        /* Step 0: Convert from std::vector to requested container */
        convert_args_to_container(_args, c.numbers);
        log_container(c.numbers, "d.numbers");

        /* Step 1: Make Pairs */
        make_pairs(c.numbers, c.pairs);
        log_pairs(c.pairs, "d.pairs");

        /* Step 2: Recursively sort pairs by larger (or left) values */
        sort_pairs_by_larger_value<T_pairs>(c.pairs.begin(), c.pairs.end());
        log_pairs(c.pairs, "d.pairs (sorted)");

        /* Step 3: Extract S (sorted bigger values) and pend (smaller values) */
        extract_S_and_pend(c.pairs, c.S, c.pend);
        log_container(c.S, "d.S");
        log_container(c.pend, "d.pend");

        /* Step 4: Insert first element of pend */
        c.S.insert(c.S.begin(), get_and_pop_front(c.pend));
        log_container(c.pend, "--> removed first");

        /* Step 5: Generate jacobsthal sequence with the help of pend.size() */
        generate_jacobsthal_numbers(c.pend, c.jacobsthal);
        log_container(c.jacobsthal, "d.jacobsthal");

        /* Step 6: Use jacosbthal sequence to index the insertion order */
        insertion_sort_with_jacobsthal(c);
        log_container(c.S, "d.S");

        /* Step 7: If there is a straggler, insert it with binary search */
        if (_straggler != NO_STRAGGLER)
        {
            insert_with_binary_search(c.S, _straggler);
            log_container(c.S, "--> with _straggler");
        }
        return c.S;
    }
};

#endif // PMERGEME

// -------------------------------------------------------------------------- //
