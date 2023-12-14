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
#include <string> // needed for std::string
#include <vector> // needed for std::vector

/*@note typedefs deque */
/* typedefs */
typedef std::string t_str;
typedef t_str const t_str_c;

typedef std::vector<t_str>        t_vec_str;
typedef t_vec_str const           t_vec_str_c;
typedef t_vec_str::const_iterator t_vec_str_cit;

typedef std::vector<int>          t_vec_int;
typedef t_vec_int const           t_vec_int_c;
typedef t_vec_int::const_iterator t_vec_int_cit;

typedef std::deque<int>           t_deq_int;
typedef t_deq_int const           t_deq_int_c;
typedef t_deq_int::const_iterator t_deq_int_cit;

class PmergeMe
{

  public:
    PmergeMe(int argc, char ** argv);
    PmergeMe();
    PmergeMe(PmergeMe const & src);
    ~PmergeMe();
    PmergeMe & operator=(PmergeMe const & rhs);

    /* @note this is where time measuring should start */
    void sort_with_vector() const;
    void sort_with_deque() const;

  private:
    void log_debug(t_str_c & message) const;
    void log_vector(t_vec_str_c & vec, t_str_c & name) const;
    void log_vector(t_vec_int_c & vec, t_str_c & name) const;
    void log_deque(t_deq_int_c & deq, t_str_c & name) const;

    void parse_arguments();

    int       _argc;
    char **   _argv;
    t_vec_int _args;
};

#endif // PMERGEME

// -------------------------------------------------------------------------- //
