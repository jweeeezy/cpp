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
#include <string>  // needed for std::string

#define YELLOW "\033[33m"
#define RESET "\033[0m"

static inline void log_debug(std::string const & message)
{
    (void)message;
    #ifdef DEBUG
    std::cout << YELLOW << "Array: " << message << RESET << "\n";
    #endif // DEBUG
}

template <typename T> class Array
{
  public:
    /* constructors */
    Array() : no_elements(0) { log_debug("default constructor called"); };

    Array(unsigned int n) : no_elements(0)
    {
        log_debug("size constructor called");
    };

    Array(const Array & src) { log_debug("copy constructor called"); };

    ~Array() { log_debug("destructor called"); };

    Array & operator=(const Array & rhs)
    {
        log_debug("operator = called");
        if (this != rhs)
        {
            /*@note deep copy */
        }
        return *this;
    };

    /* member functions */
    size_t size() const { return no_elements; };

  private:
    /* member variables */
    T *    element;
    size_t no_elements;
};

#endif

// -------------------------------------------------------------------------- //
