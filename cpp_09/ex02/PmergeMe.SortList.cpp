// ========================================================================== //
//                               42 | Heilbronn                               //
// ========================================================================== //
//                                                                            //
// name:  jakob willert (jwillert)                                            //
// mail:  jwillert@student.42heilbronn.de                                     //
// file:  PmergeMe.SortList.cpp                                               //
//                                                                            //
// -------------------------------------------------------------------------- //

#include "PmergeMe.hpp" // needed for PmergeMe class, typedefs
#include "utils.hpp"    // needed for container utils

struct s_lists
{
    t_lst_int      numbers;
    t_lst_pair_int pairs;
    t_lst_int      S;
    t_lst_int      pend;
    t_lst_int      jacobsthal;
};

static bool compare_first_value(t_pair_c & lhs, t_pair_c & rhs)
{
    return lhs.first < rhs.first;
}

static void sort_pairs_by_larger_value(t_lst_pair_int & pairs)
{
    pairs.sort(compare_first_value);
}

static void insertion_sort_with_jacobsthal(struct s_lists & lists)
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
        int index = current_jacobs - 1;
        while (index != next_jacobs - 1)
        {
            int current_value = access_container_by_index(lists.pend, index);
            insert_with_binary_search(lists.S, current_value);
            sequence.push_back(current_value);
            --index;
        }
    }
    log_container(sequence, "insert sequence");
}

t_vec_str_c & PmergeMe::sort_with_list()
{
    struct s_lists lists;

    convert_args_to_container(_args, lists.numbers);
    log_container(lists.numbers, "lists.numbers");


    /* Step 1: Make Pairs! */
    make_pairs(lists.numbers, lists.pairs);
    log_pairs(lists.pairs, "lists.pairs");

    /* Step 2: Sort Pairs by larger Value */
    sort_pairs_by_larger_value(lists.pairs);
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
    _sorted = container_to_vec_str(lists.S);
    return _sorted;
}

// -------------------------------------------------------------------------- //
