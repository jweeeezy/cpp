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

		// type identification
		// check for printable?!
		// if !isnumber()
			// check for printable?!
		// else
			// if has trailing_f <-- is this viable without a dot?
			// if hasdot()

		static bool is_printable(std::string const& input);
		static bool is_number(std::string const& input); // <-- @needs impl.

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

		//static void getType(std::string const& input); <-- @needs impl.

		static void convert(std::string const& input);
		
		ScalarConverter();
		ScalarConverter(const ScalarConverter& src);
		~ScalarConverter();
		ScalarConverter& operator=(const ScalarConverter& rhs);

};

#endif // SCALARCONVERTER_HPP

// -------------------------------------------------------------------------- //
