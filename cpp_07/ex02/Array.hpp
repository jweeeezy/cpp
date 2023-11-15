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

#include <cstdlib>   // needed for size_t
#include <iostream>  // needed for std::cout
#include <stdexcept> // needed for std::invalid_argument
#include <string>    // needed for std::string

#define YELLOW "\033[33m"
#define RESET  "\033[0m"

/* <~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~> helper functions  */

static inline void log_debug(std::string const & message)
{
    (void)message;
#ifdef DEBUG
    std::cout << YELLOW << "Array: " << message << RESET << "\n";
#endif // DEBUG
}

/* <~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~> Array class */

template <typename T> class Array
{
  public:
    /* constructors */
    Array() : element(NULL), no_elements(0)
    {
        log_debug("default constructor called");
    };

    Array(unsigned int n) : no_elements(n)
    {
        log_debug("size constructor called");
        element = new T[no_elements];
    };

    Array(Array const & src) : no_elements(src.no_elements)
    {
        log_debug("copy constructor called");
        element     = new T[no_elements];
        no_elements = src.no_elements;
        for (unsigned int i = 0; i != no_elements; ++i)
        {
            element[i] = src.element[i];
        }
    };

    ~Array()
    {
        delete[] element;
        log_debug("destructor called");
    };

    Array & operator=(Array const & src)
    {
        log_debug("assignment operator called");
        if (this != &src)
        {
            if (element != NULL)
            {
                delete[] element;
            }
            no_elements = src.no_elements;
            element     = new T[no_elements];
            for (unsigned int i = 0; i != no_elements; ++i)
            {
                element[i] = src.element[i];
            }
        }
        return *this;
    };

    T & operator[](unsigned int index) const
    {
        if (index >= no_elements)
        {
            throw std::invalid_argument("Index is out of bounds!");
        }
        return element[index];
    };

    /* member functions */
    unsigned int size() const { return no_elements; };

  private:
    /* member variables */
    T *          element;
    unsigned int no_elements;
};

#endif // ARRAY_HPP

// -------------------------------------------------------------------------- //
