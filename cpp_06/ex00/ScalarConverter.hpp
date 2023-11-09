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

/* static variables & methods */

/* public, private*/

/* variables, constructors, methods */

private:
  static bool is_printable(std::string const &input);
  static bool is_number(std::string const &input);

  static bool has_dot(std::string const &input);
  static bool has_trailing_f(std::string const &input);

  static void print_conversion(char c, int i, double d, float f);

/* should prob be private ? */
public:
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

  class StringException : public std::exception
  {
  public:
    const char *what() const throw()
    {
      return "ScalarConverter: Multi-Character Strings are "
             "invalid input!";
    }
  };

  class NonPrintableException : public std::exception
  {
  public:
    const char *what() const throw()
    {
      return "ScalarConverter: Non displayable characters "
             "are invalid input!";
    }
  };

  static Type identify_type(std::string const &input);
  static void convert(std::string const &input);

  ScalarConverter();
  ScalarConverter(const ScalarConverter &src);
  ~ScalarConverter();
  ScalarConverter &operator=(const ScalarConverter &rhs);
};

std::ostream &operator<<(std::ostream &os, const ScalarConverter::Type &type);

#endif // SCALARCONVERTER_HPP

// -------------------------------------------------------------------------- //
