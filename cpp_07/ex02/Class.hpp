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
    Class(const Class & src);
    ~Class();
    Class & operator=(const Class & rhs);

    /* member variables */
    std::string content;
};

#endif // CLASS_HPP

// -------------------------------------------------------------------------- //
