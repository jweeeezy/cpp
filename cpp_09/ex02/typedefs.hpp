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

#ifdef DEBUG
#define YELLOW     "\033[033m"
#define LIGHT_BLUE "\033[094m"
#define GREEN      "\033[032m"
#define RESET      "\033[0m"
#include <iostream> // needed for std::cerr
#endif

#include <deque>  // needed for std::deque
#include <list>   // needed for std::list
#include <string> // needed for std::string
#include <vector> // needed for std::vector

typedef std::string t_str;
typedef t_str const t_str_c;

typedef std::vector<t_str>        t_vec_str;
typedef t_vec_str const           t_vec_str_c;
typedef t_vec_str::iterator       t_vec_str_it;
typedef t_vec_str::const_iterator t_vec_str_cit;

typedef std::list<int>            t_lst_int;
typedef t_lst_int const           t_lst_int_c;
typedef t_lst_int::iterator       t_lst_int_it;
typedef t_lst_int::const_iterator t_lst_int_cit;

typedef std::list<std::pair<int, int> > t_lst_pair_int;
typedef t_lst_pair_int const            t_lst_pair_int_c;
typedef t_lst_pair_int::iterator        t_lst_pair_int_it;
typedef t_lst_pair_int::const_iterator  t_lst_pair_int_cit;

typedef std::deque<int>           t_deq_int;
typedef t_deq_int const           t_deq_int_c;
typedef t_deq_int::iterator       t_deq_int_it;
typedef t_deq_int::const_iterator t_deq_int_cit;

typedef std::deque<std::pair<int, int> > t_deq_pair_int;
typedef t_deq_pair_int const             t_deq_pair_int_c;
typedef t_deq_pair_int::iterator         t_deq_pair_int_it;
typedef t_deq_pair_int::const_iterator   t_deq_pair_int_cit;

#endif // TYPEDEFS_HPP

// -------------------------------------------------------------------------- //
