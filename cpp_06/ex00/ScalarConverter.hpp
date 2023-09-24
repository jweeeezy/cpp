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

		virtual void convert(std::string input) = 0;
		
		ScalarConverter();
		ScalarConverter(const ScalarConverter& src);
		virtual ~ScalarConverter();
		ScalarConverter& operator=(const ScalarConverter& rhs);

};

#endif // SCALARCONVERTER_HPP

// -------------------------------------------------------------------------- //
