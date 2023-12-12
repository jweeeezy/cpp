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

class PmergeMe
{
  public:
    PmergeMe(int argc, char ** argv);
    PmergeMe();
    PmergeMe(PmergeMe const & src);
    ~PmergeMe();
    PmergeMe & operator=(PmergeMe const & rhs);

    void log_debug(std::string const & message) const;

    void parse_arguments(char ** argv);

    int _argc;
    /* @note prob a template Container ? */
        /* or just an overloaded constructor */
};

#endif // PMERGEME

// -------------------------------------------------------------------------- //
