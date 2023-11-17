// ========================================================================== //
//                               42 | Heilbronn                               //
// ========================================================================== //
//                                                                            //
// name:  jakob willert (jwillert)                                            //
// mail:  jwillert@student.42heilbronn.de                                     //
// file:  iter.hpp                                                            //
//                                                                            //
// -------------------------------------------------------------------------- //

#ifndef ITER_HPP
#define ITER_HPP

#include <cstdlib>  // needed for size_t
#include <iostream> // needed for std::cout

template <typename T, typename Func> void iter(T & arr, size_t length, Func f)
{
    for (size_t i = 0; i < length; ++i)
    {
        f(arr[i]);
    }
};

template <typename T> void print(T const & elem) { std::cout << elem << " "; }

template <typename T> void multiplicate_by_2(T & elem) { elem *= 2; }

#endif // ITER_HPP

// -------------------------------------------------------------------------- //
