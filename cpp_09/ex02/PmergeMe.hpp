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
#include <list>   // needed for std::map
#include <string> // needed for std::string
#include <vector> // needed for std::vector

#ifdef DEBUG
#include <iostream>
#endif

#define YELLOW "\033[033m"
#define RESET  "\033[0m"

/* typedefs */
/* @note should prob just add them internally in the source files */
typedef std::string t_str;
typedef t_str const t_str_c;

typedef std::vector<t_str>        t_vec_str;
typedef t_vec_str const           t_vec_str_c;
typedef t_vec_str::iterator       t_vec_str_it;
typedef t_vec_str::const_iterator t_vec_str_cit;

typedef std::vector<int>          t_vec_int;
typedef t_vec_int const           t_vec_int_c;
typedef t_vec_int::iterator       t_vec_int_it;
typedef t_vec_int::const_iterator t_vec_int_cit;

typedef std::list<int>            t_lst_int;
typedef t_lst_int const           t_lst_int_c;
typedef t_lst_int::iterator       t_lst_int_it;
typedef t_lst_int::const_iterator t_lst_int_cit;

typedef std::list<std::pair<int, int> > t_lst_pair_int;
typedef t_lst_pair_int const           t_lst_pair_int_c;
typedef t_lst_pair_int::iterator       t_lst_pair_int_it;
typedef t_lst_pair_int::const_iterator t_lst_pair_int_cit;

typedef std::deque<int>           t_deq_int;
typedef t_deq_int const           t_deq_int_c;
typedef t_deq_int::iterator       t_deq_int_it;
typedef t_deq_int::const_iterator t_deq_int_cit;

class PmergeMe
{

  public:
    PmergeMe(int argc, char ** argv);
    PmergeMe();
    PmergeMe(PmergeMe const & src);
    ~PmergeMe();
    PmergeMe & operator=(PmergeMe const & rhs);

    void sort_with_deque() const;
    void sort_with_list() const;

  private:
    void log_debug(t_str_c & message) const;
    void log_straggler() const;
    void log_list(t_lst_pair_int_c & lst, t_str_c & name) const;

    /* @note could just make separate .hpp file for the template functions so
     * they dont pollute the class */

    template <typename T> void log_container(T container, t_str_c & name) const
    {
        (void)container;
        (void)name;
#ifdef DEBUG
        std::cerr << YELLOW << name << ": " << RESET;
        for (typename T::const_iterator it = container.begin();
             it != container.end(); ++it)
        {
            std::cerr << *it << " ";
        }
        std::cerr << "\n";
#endif
    }

    template <typename T> T vector_to_container(T & container) const
    {
        t_vec_str_cit it = _args.begin();

        while (it != _args.end())
        {
            int tmp = get_parsed_int(it);
            if (std::find(container.begin(), container.end(), tmp) !=
                container.end())
            {
                throw std::invalid_argument("no duplicates allowed!");
            }
            container.push_back(tmp);
            ++it;
        }
        return container;
    }

    int  get_parsed_int(t_vec_str_cit it) const;
    void parse_arguments();
    void handle_straggler();

    int       _argc;
    char **   _argv;
    t_vec_str _args;
    int       _straggler;
};

#endif // PMERGEME

// -------------------------------------------------------------------------- //
