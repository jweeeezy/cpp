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
    t_vec_str_c   get_unsorted_args() const;
    t_vec_str_c & get_sorted_args() const;

    /* location: PmergeMe.SortList.cpp */
    void sort_with_list();

    /* location: PmergeMe.SortDeque.cpp */
    void sort_with_deque();

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

    /* location: PmergeMe.SortList.cpp */
    void insertion_sort_with_jacobsthal(struct s_lists & d) const;

    /* location: PmergeMe.SortDeque.cpp */
    void insertion_sort_with_jacobsthal(struct s_deques & d) const;

    int       _argc;
    char **   _argv;
    t_vec_str _args;
    int       _straggler;
    t_vec_str _sorted;
};

#endif // PMERGEME

// -------------------------------------------------------------------------- //
