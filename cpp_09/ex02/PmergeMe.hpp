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

/* typedefs */
typedef std::string t_str;
typedef t_str const t_str_c;

typedef std::vector<t_str>        t_vec_str;
typedef t_vec_str const           t_vec_str_c;
typedef t_vec_str::const_iterator t_vec_str_cit;

/*@note typedefs deque */

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
    void log_deque(std::deque<std::string> & deq, t_str_c & name) const;

    void parse_arguments();

    int       _argc;
    char **   _argv;
    t_vec_str _args;
};

#endif // PMERGEME

// -------------------------------------------------------------------------- //
