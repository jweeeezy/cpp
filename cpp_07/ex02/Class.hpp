// ========================================================================== //
//                               42 | Heilbronn                               //
// ========================================================================== //
//                                                                            //
// name:  jakob willert (jwillert)                                            //
// mail:  jwillert@student.42heilbronn.de                                     //
// file:  Class.hpp                                                           //
//                                                                            //
// -------------------------------------------------------------------------- //

#ifndef CLASS_HPP
#define CLASS_HPP

#include <string> // needed for std::string

class Class
{
  public:
    /* constructors */
    Class();
    Class(Class const & src);
    ~Class();
    Class & operator=(Class const & rhs);

    /* member variables */
    std::string content;
};

#endif // CLASS_HPP

// -------------------------------------------------------------------------- //
