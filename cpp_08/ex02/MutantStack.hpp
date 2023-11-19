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

#include <stack> // needed for std::stack

template <typename T> class MutantStack : public std::stack<T>
{
  public:
    MutantStack(){};
    MutantStack(MutantStack const & src) { (void)src; };
    ~MutantStack(){};
    MutantStack & operator=(MutantStack const & rhs)
    {
        (void)rhs;
        return *this;
    };

  private:
};

#endif // MUTANTSTACK_HPP

// -------------------------------------------------------------------------- //
