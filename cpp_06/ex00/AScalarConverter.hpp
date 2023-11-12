// ========================================================================== //
//                               42 | Heilbronn                               //
// ========================================================================== //
//                                                                            //
// name:  jakob willert (jwillert)                                            //
// mail:  jwillert@student.42heilbronn.de                                     //
// file:  AScalarConverter.hpp                                                //
//                                                                            //
// -------------------------------------------------------------------------- //

#ifndef ASCALARCONVERTER_HPP
#define ASCALARCONVERTER_HPP

#include <string> // needed for std::string

class ScalarConverter
{

  public:
    
    /* static functions */
    static void convert(std::string const & input);

  private:

    /* constructors */
    ScalarConverter();
    ScalarConverter(ScalarConverter const & src);
    ~ScalarConverter();
    ScalarConverter & operator=(ScalarConverter const & rhs);

    /* exceptions */
    class StringException : public std::exception
    {
      public:
        char const * what() const throw()
        {
            return "ScalarConverter: multi-character strings are "
                   "invalid input!";
        }
    };
    class NonPrintableException : public std::exception
    {
      public:
        char const * what() const throw()
        {
            return "ScalarConverter: non-displayable characters "
                   "are invalid input!";
        }
    };
    class NoTypeIdentifiedException : public std::exception
    {
        public:
            char const * what() const throw()
            {
                return "ScalarConverter: no type identifiable!";
            }
    };

};

#endif // ASCALARCONVERTER_HPP

// -------------------------------------------------------------------------- //
