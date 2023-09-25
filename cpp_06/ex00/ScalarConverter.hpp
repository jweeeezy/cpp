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

#include <string>

class ScalarConverter
{

	public:

		static void convert(std::string input);
		
		ScalarConverter();
		ScalarConverter(const ScalarConverter& src);
		~ScalarConverter();
		ScalarConverter& operator=(const ScalarConverter& rhs);

};

#endif // SCALARCONVERTER_HPP

// -------------------------------------------------------------------------- //
