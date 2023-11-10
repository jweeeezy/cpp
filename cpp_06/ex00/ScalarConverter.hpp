// ========================================================================== //
//                               42 | Heilbronn                               //
// ========================================================================== //
//                                                                            //
// name:  jakob willert (jwillert)                                            //
// mail:  jwillert@student.42heilbronn.de                                     //
// file:  ScalarConverter.hpp                                                 //
//                                                                            //
// -------------------------------------------------------------------------- //

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string> // needed for std::string

class ScalarConverter
{

  public:
    /* static functions */
    static void convert(std::string const & input);

    enum Type
    {
        NON_TYPE,
        NON_PRINTABLE,
        CHAR,
        STRING,
        INTEGER,
        DOUBLE,
        FLOAT
    };

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
            return "ScalarConverter: Multi-Character Strings are "
                   "invalid input!";
        }
    };
    class NonPrintableException : public std::exception
    {
      public:
        char const * what() const throw()
        {
            return "ScalarConverter: Non displayable characters "
                   "are invalid input!";
        }
    };
};

std::ostream & operator<<(std::ostream & os,
                          ScalarConverter::Type const & type);

#endif // SCALARCONVERTER_HPP

// -------------------------------------------------------------------------- //
