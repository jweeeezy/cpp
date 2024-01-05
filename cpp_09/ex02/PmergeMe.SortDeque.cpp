// ========================================================================== //
//                               42 | Heilbronn                               //
// ========================================================================== //
//                                                                            //
// name:  jakob willert (jwillert)                                            //
// mail:  jwillert@student.42heilbronn.de                                     //
// file:  PmergeMe.SortDeque.cpp                                              //
//                                                                            //
// -------------------------------------------------------------------------- //

#include "PmergeMe.hpp" // needed for PmergeMe class, typedefs
#include "utils.hpp"    // needed for container utils

struct s_deques
{
    t_deq_int      numbers;
    t_deq_pair_int pairs;
    t_deq_int      S;
    t_deq_int      pend;
    t_deq_int      jacobsthal;
};

static bool compare_first_value(t_pair_c & lhs, t_pair_c & rhs)
{
    return lhs.first < rhs.first;
}

static void sort_pairs_by_larger_value(t_deq_pair_int & pairs)
{
    std::sort(pairs.begin(), pairs.end(), compare_first_value);
}

t_deq_int_c PmergeMe::sort_with_deque() const
{
    struct s_deques deques;

    /* Step 0: Convert from std::vector to requested container */
    convert_args_to_container(_args, deques.numbers);
    log_container(deques.numbers, "deques.numbers");

    /* Step 1: Make Pairs! */
    make_pairs(deques.numbers, deques.pairs);
    log_pairs(deques.pairs, "deques.pairs");

    /* Step 2: Sort Pairs by larger Value */
    sort_pairs_by_larger_value(deques.pairs);
    log_pairs(deques.pairs, "deques.pairs (sorted)");

    /* Step 3: Extract S (larger values, sorted) and pend (smaller values) */
    extract_S_and_pend(deques.pairs, deques.S, deques.pend);
    log_container(deques.S, "deques.S");
    log_container(deques.pend, "deques.pend");

    /* Step 4: Insert first element of pend */
    deques.S.insert(deques.S.begin(), get_and_pop_front(deques.pend));
    log_container(deques.pend, "--> removed first");

    /* Step 5: Generate jacobsthal sequence with the help of pend.size() */
    generate_jacobsthal_numbers(deques.pend, deques.jacobsthal);
    log_container(deques.jacobsthal, "deques.jacobsthal");

    /* Step 6: Use jacosbthal sequence to index the insertion order */
    insertion_sort_with_jacobsthal(deques);
    log_container(deques.S, "deques.S");

    /* Step 7: If there is a straggler, insert it with binary search */
    if (_straggler != NO_STRAGGLER)
    {
        insert_with_binary_search(deques.S, _straggler);
        log_container(deques.S, "--> with _straggler");
    }
    return deques.S;
}

// -------------------------------------------------------------------------- //
