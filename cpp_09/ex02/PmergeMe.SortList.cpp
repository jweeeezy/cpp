// ========================================================================== //
//                               42 | Heilbronn                               //
// ========================================================================== //
//                                                                            //
// name:  jakob willert (jwillert)                                            //
// mail:  jwillert@student.42heilbronn.de                                     //
// file:  PmergeMe.SortList.cpp                                               //
//                                                                            //
// -------------------------------------------------------------------------- //

#include "PmergeMe.hpp" // needed for PmergeMe class, typedefs, algorithm

struct s_lists
{
    t_lst_int      numbers;
    t_lst_pair_int pairs;
    t_lst_int      S;
    t_lst_int      pend;
    t_lst_int      jacobsthal;
};

void merge_sort(t_lst_pair_int_it first, t_lst_pair_int_it mid,
                t_lst_pair_int_it last)
{
    t_lst_pair_int    merged;
    t_lst_pair_int_it left  = first;
    t_lst_pair_int_it right = mid;

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

void sort_pairs_by_larger_value(t_lst_pair_int_it first, t_lst_pair_int_it last)
{
    if (std::distance(first, last) > 1)
    {
        t_lst_pair_int_it mid = first;
        std::advance(mid, std::distance(first, last) / 2);

        sort_pairs_by_larger_value(first, mid);
        sort_pairs_by_larger_value(mid, last);

        merge_sort(first, mid, last);
    }
}

t_lst_int_c PmergeMe::sort_with_list() const
{
    struct s_lists lists;

    /* Step 0: Convert from std::vector to requested container */
    convert_args_to_container(_args, lists.numbers);
    log_container(lists.numbers, "lists.numbers");

    /* Step 1: Make Pairs! */
    make_pairs(lists.numbers, lists.pairs);
    log_pairs(lists.pairs, "lists.pairs");

    /* Step 2: Recursively pairs by larger value */
    sort_pairs_by_larger_value(lists.pairs.begin(), lists.pairs.end());
    log_pairs(lists.pairs, "lists.pairs (sorted)");

    /* Step 3: Extract S (larger values, sorted) and pend (smaller values) */
    extract_S_and_pend(lists.pairs, lists.S, lists.pend);
    log_container(lists.S, "lists.S");
    log_container(lists.pend, "lists.pend");

    /* Step 4: Insert first element of pend */
    lists.S.insert(lists.S.begin(), get_and_pop_front(lists.pend));
    log_container(lists.pend, "--> removed first");

    /* Step 5: Generate jacobsthal sequence with the help of pend.size() */
    generate_jacobsthal_numbers(lists.pend, lists.jacobsthal);
    log_container(lists.jacobsthal, "lists.jacobsthal");

    /* Step 6: Use jacosbthal sequence to index the insertion order */
    insertion_sort_with_jacobsthal(lists);
    log_container(lists.S, "lists.S");

    /* Step 7: If there is a straggler, insert it with binary search */
    if (_straggler != NO_STRAGGLER)
    {
        insert_with_binary_search(lists.S, _straggler);
        log_container(lists.S, "--> with _straggler");
    }
    return lists.S;
}

// -------------------------------------------------------------------------- //
