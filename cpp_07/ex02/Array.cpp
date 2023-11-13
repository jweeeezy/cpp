// ========================================================================== //
//                               42 | Heilbronn                               //
// ========================================================================== //
//                                                                            //
// name:  jakob willert (jwillert)                                            //
// mail:  jwillert@student.42heilbronn.de                                     //
// file:  Array.cpp                                                           //
//                                                                            //
// -------------------------------------------------------------------------- //

#include "Array.hpp" // needed for Array class
#include <string>    // needed for std::string

#define YELLOW "\033[33m"
#define RESET  "\033[0m"

/* <~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~> non-class functions */

static inline void log_debug(std::string const & message)
{
    (void)message;
#ifdef DEBUG
    std::cout << YELLOW << "Array: " << message << RESET << "\n";
#endif // DEBUG
}

template <typename T> Array<T>::Array() : no_elements(0)
{
    log_debug("default constructor called");
}

template <typename T> Array<T>::Array(unsigned int n) : no_elements(n)
{

    log_debug("size constructor called");

    no_elements = n;
}

template <typename T> Array<T>::Array(const Array & src) {


    log_debug("copy constructor called");
    /*@note deep copy */




}
template <typename T> Array<T>::~Array() {}
template <typename T> Array<T> & Array<T>::operator=(const Array & rhs)
{
    log_debug("operator = called");
    if (this != rhs)
    {
        /*@note deep copy */
    }
    return *this;
}
template <typename T> size_t Array<T>::size() const { 


    log_debug("destructor called");

    return 0; }

// -------------------------------------------------------------------------- //
