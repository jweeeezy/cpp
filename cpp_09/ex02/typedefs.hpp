// ========================================================================== //
//                               42 | Heilbronn                               //
// ========================================================================== //
//                                                                            //
// name:  jakob willert (jwillert)                                            //
// mail:  jwillert@student.42heilbronn.de                                     //
// file:  typedefs.hpp                                                        //
//                                                                            //
// -------------------------------------------------------------------------- //

#ifndef TYPEDEFS_HPP
#define TYPEDEFS_HPP

#define RED   "\033[1;31m"
#define RESET "\033[0m"

/* only needed for debugging */
#ifdef DEBUG
#define GREEN      "\033[032m"
#define LIGHT_BLUE "\033[094m"
#define YELLOW     "\033[033m"
#include <iostream> // needed for std::cerr
#endif

#include <deque>  // needed for std::deque
#include <list>   // needed for std::list
#include <string> // needed for std::string
#include <vector> // needed for std::vector

typedef std::string                    t_str;
typedef t_str const                    t_str_c;

typedef std::pair<int, int>            t_pair;
typedef t_pair const                   t_pair_c;

typedef std::vector<t_str>             t_vec_str;
typedef t_vec_str const                t_vec_str_c;
typedef t_vec_str::const_iterator      t_vec_str_cit;

typedef std::list<int>                 t_lst_int;
typedef t_lst_int const                t_lst_int_c;

typedef std::list<t_pair>              t_lst_pair_int;
typedef t_lst_pair_int const           t_lst_pair_int_c;

typedef std::deque<int>                t_deq_int;
typedef t_deq_int const                t_deq_int_c;

typedef std::deque<t_pair>             t_deq_pair_int;
typedef t_deq_pair_int const           t_deq_pair_int_c;

#endif // TYPEDEFS_HPP

// -------------------------------------------------------------------------- //
