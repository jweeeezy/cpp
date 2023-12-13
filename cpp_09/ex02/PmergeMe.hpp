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

#include <string> // needed for std::string
#include <vector> // needed for std::vector

/* @note typedefs */
typedef std::string t_str;
typedef t_str const t_str_c;

typedef std::vector<t_str>        t_vec_str;
typedef t_vec_str const           t_vec_str_c;
typedef t_vec_str::const_iterator t_vec_str_cit;

class PmergeMe
{

  public:
    PmergeMe(int argc, char ** argv);
    PmergeMe();
    PmergeMe(PmergeMe const & src);
    ~PmergeMe();
    PmergeMe & operator=(PmergeMe const & rhs);

    void log_debug(t_str_c & message) const;

    t_vec_str_c str_split_by(t_str_c & str, t_str_c & delimiter);
    t_vec_str_c split_quotated_strings(char ** argv);
    t_vec_str_c parse_arguments(char ** argv);

  private:
    int _argc;
    /* @note prob a template Container ? */
    /* or just an overloaded constructor */
};

#endif // PMERGEME

// -------------------------------------------------------------------------- //
