// ========================================================================== //
//                               42 | Heilbronn                               //
// ========================================================================== //
//                                                                            //
// name:  jakob willert (jwillert)                                            //
// mail:  jwillert@student.42heilbronn.de                                     //
// file:  whatever.hpp                                                        //
//                                                                            //
// -------------------------------------------------------------------------- //

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

template <typename T> void swap(T & a, T & b)
{
    T tmp = a;
    a = b;
    b = tmp;
};

template <typename T> T const & min(T const & a, T const & b)
{
    if (a <= b)
    {
        return a;
    }
    return b;
};

template <typename T> T const & max(T const & a, T const & b)
{
    if (a >= b)
    {
        return a;
    }
    return b;
}

#endif // WHATEVER_HPP

// -------------------------------------------------------------------------- //
