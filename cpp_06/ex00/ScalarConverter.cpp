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
#include <iostream>            // needed for std::cout, std::endl, std::cerr

#ifndef DEBUG
# define DEBUG 0
#endif // DEBUG

/* <~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~> non-class functions */

static inline void print_log(std::string message)
{
	if (DEBUG)
	{
		std::cerr << "ScalarConverter: " << message << std::endl;
	}
}

/* <~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~> constructors */

ScalarConverter::ScalarConverter(){;}
ScalarConverter::ScalarConverter(const ScalarConverter& src){(void) src;}
ScalarConverter::~ScalarConverter(){;}

/* <~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~> operator overloads */

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& rhs)
{
	(void) rhs;
	return *this;
}

/* <~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~> member functions */

bool ScalarConverter::is_printable(std::string const& input)
{
	for (std::string::const_iterator it = input.begin();
	                                 it != input.end();
									 ++it)
	{
		if (std::isprint(static_cast<unsigned char>(*it)) == false)
		{
			return false;
		}
	}
	return true;
}

void ScalarConverter::convert(std::string const& input)
{
	print_log("convert() called!");
	if (is_printable(input) == false)
	{
		throw NonPrintableException();
	}
	else
	{
		std::cout << input << std::endl;
	}
	return ;
}

// -------------------------------------------------------------------------- //
