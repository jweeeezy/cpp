// ========================================================================== //
//                               42 | Heilbronn                               //
// ========================================================================== //
//                                                                            //
// name:  jakob willert (jwillert)                                            //
// mail:  jwillert@student.42heilbronn.de                                     //
// file:  Array.hpp                                                           //
//                                                                            //
// -------------------------------------------------------------------------- //

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <cstdlib> // needed for size_t

template <typename T> class Array
{
  public:
    /* constructors */
    Array();
    Array(unsigned int n);
    Array(const Array & src);
    ~Array();
    Array & operator=(const Array & rhs);

    /* member functions */
    size_t size() const;

  private:
    /* member variables */
    T *    element;
    size_t no_elements;
};

#endif

// -------------------------------------------------------------------------- //
