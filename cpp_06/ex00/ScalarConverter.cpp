// ========================================================================== //
//                               42 | Heilbronn                               //
// ========================================================================== //
//                                                                            //
// name:  jakob willert (jwillert)                                            //
// mail:  jwillert@student.42heilbronn.de                                     //
// file:  ScalarConverter.cpp                                                 //
//                                                                            //
// -------------------------------------------------------------------------- //

#include "ScalarConverter.hpp" // needed for ScalarConverter class

#include <iostream> // needed for std::cout, std::endl, std::cerr

#ifndef DEBUG
# define DEBUG 0
#endif // DEBUG

static inline void print_log(std::string message)
{
	if (DEBUG)
	{
		std::cerr << "ScalarConverter: " << message << std::endl;
	}
}

void ScalarConverter::convert(std::string input)
{
	print_log("convert() called!");
	(void) input;
	return ;
}

ScalarConverter::ScalarConverter(){;}
ScalarConverter::ScalarConverter(const ScalarConverter& src){(void) src;}
ScalarConverter::~ScalarConverter(){;}
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& rhs){(void) rhs; return *this;}

// -------------------------------------------------------------------------- //
