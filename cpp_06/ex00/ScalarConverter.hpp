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
# define SCALARCONVERTER_HPP

#include <string> // needed for std::string

class ScalarConverter
{


	private:

		static bool is_printable(std::string const& input);
		static bool has_dot(std::string const& input);
		static bool has_trailing_f(std::string const& input);

	public:

		class NonPrintableException : public std::exception
		{
			public:
				const char *what() const throw()
				{
					return "ScalarConverter: Non displayable characters " \
					 "are invalid input!";
				}
		};

		static void convert(std::string const& input);
		
		ScalarConverter();
		ScalarConverter(const ScalarConverter& src);
		~ScalarConverter();
		ScalarConverter& operator=(const ScalarConverter& rhs);

};

#endif // SCALARCONVERTER_HPP

// -------------------------------------------------------------------------- //
