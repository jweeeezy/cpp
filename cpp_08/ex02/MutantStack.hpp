// ========================================================================== //
//                               42 | Heilbronn                               //
// ========================================================================== //
//                                                                            //
// name:  jakob willert (jwillert)                                            //
// mail:  jwillert@student.42heilbronn.de                                     //
// file:  MutantStack.hpp                                                     //
//                                                                            //
// -------------------------------------------------------------------------- //

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream> // needed for std::cout
#include <stack>    // needed for std::stack

#define YELLOW "\033[33m"
#define RESET  "\033[0m"

/* <~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~> non-class functions */

static inline void debug_log(std::string const & message)
{
    (void)message;
#ifdef DEBUG
    std::cout << YELLOW << "MutantStack: " << message << RESET << std::endl;
#endif // DEBUG
}

/* <~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~> class */

template <typename T> class MutantStack : public std::stack<T>
{
    
    /* @note inheriting from std:: containers is not advised 
     * (non virtual destructors) */

  public:
    /* constructors */
    MutantStack()
    {
        debug_log("default constructor called\n");
    }
    MutantStack(MutantStack const & src) : std::stack<T>(src)
    {
        debug_log("copy constructor called\n");
    }
    ~MutantStack() 
    {
        debug_log("destructor called\n");
    }
    MutantStack & operator=(MutantStack const & rhs)
    {
        debug_log("assignment operator called\n");
        if (this != &rhs)
        {
            this->c = rhs.c;
        }
        return *this;
    };
    
    /* iterators */
    typedef typename std::stack<T>::container_type   t_stack_ct;;
    typedef typename t_stack_ct::iterator            iterator;
    typedef typename t_stack_ct::const_iterator      const_iterator;
    
    iterator       begin()       { return this->c.begin(); }
    iterator       end()         { return this->c.end(); }
    const_iterator begin() const { return this->c.begin(); }
    const_iterator end()   const { return this->c.end(); }

};

#endif // MUTANTSTACK_HPP

// -------------------------------------------------------------------------- //
