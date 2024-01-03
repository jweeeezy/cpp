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
    PmergeMe();
    ~PmergeMe();

    /* location: PmergeMe.SortList.cpp */
    void sort_with_list() const;

    /* location: PmergeMe.SortDeque.cpp */
    void sort_with_deque() const;

  private:
    /* location: PmergeMe.Logs.cpp */
    void log_debug(t_str_c & message) const;
    void log_straggler() const;
    void log_list(t_lst_pair_int_c & lst, t_str_c & name) const;
    void log_deq(t_deq_pair_int_c & deq, t_str_c & name) const;

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
};

#endif // PMERGEME

// -------------------------------------------------------------------------- //
