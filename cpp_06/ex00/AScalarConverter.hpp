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

    enum Type
    {
        CHAR,
        INTEGER,
        DOUBLE,
        FLOAT,
        INFNEG,
        INFPOS,
        NANF,
        STRING,
        NON_TYPE,
        NON_PRINTABLE,
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
    class NoTypeIdentifiedException : public std::exception
    {
        public:
            char const * what() const throw()
            {
                return "ScalarConverter: No type identifiable!";
            }
    };

};

std::ostream & operator<<(std::ostream & os,
                          ScalarConverter::Type const & type);

#endif // ASCALARCONVERTER_HPP

// -------------------------------------------------------------------------- //
