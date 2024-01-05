// ========================================================================== //
//                               42 | Heilbronn                               //
// ========================================================================== //
//                                                                            //
// name:  jakob willert (jwillert)                                            //
// mail:  jwillert@student.42heilbronn.de                                     //
// file:  PmergeMe.cpp                                                        //
//                                                                            //
// -------------------------------------------------------------------------- //

#include "PmergeMe.hpp" // needed for PmergeMe class, typedefs, algorithm

PmergeMe::PmergeMe(int argc, char ** argv) : _argc(argc), _argv(argv)
{
    log_debug("parsing constructor called");

    parse_arguments();
    log_container(_args, "_args");

    handle_straggler();
    log_straggler();
}

PmergeMe & PmergeMe::operator=(PmergeMe const & rhs)
{
    log_debug("assignment operator called");
    if (this != &rhs)
    {
        _argc      = rhs._argc;
        _argv      = rhs._argv;
        _args      = rhs._args;
        _straggler = rhs._straggler;
    }
    return *this;
}

PmergeMe::PmergeMe(PmergeMe const & src)
{
    log_debug("copy constructor called");
    *this = src;
}

PmergeMe::~PmergeMe() { log_debug("destructor called"); }
PmergeMe::PmergeMe() { log_debug("default constructor called"); }

t_vec_str_c PmergeMe::get_unsorted_args() const
{
    t_vec_str vec(_args);
    if (_straggler != NO_STRAGGLER)
    {
        std::ostringstream ss;
        ss << _straggler;
        vec.push_back(ss.str());
    }
    return vec;
}

/* uses a struct with std::list<int> and std::list<std::pair<int, int> > to sort
 * the given parameters */
t_lst_int_c PmergeMe::sort_with_list() const
{
    return merge_insertion_sort<s_sort_data<t_lst_int, t_lst_pair_int>,
                                t_lst_int,
                                t_lst_pair_int>();
}

/* uses a struct with std::deque<int> and std::deque<std::pair<int, int> > to
 * sort the given parameters */
t_deq_int_c PmergeMe::sort_with_deque() const
{
    return merge_insertion_sort<s_sort_data<t_deq_int, t_deq_pair_int>,
                                t_deq_int,
                                t_deq_pair_int>();
}

// -------------------------------------------------------------------------- //
