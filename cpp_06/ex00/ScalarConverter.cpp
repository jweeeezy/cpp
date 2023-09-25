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
	for (std::string::const_iterator itr = input.begin();
	                                 itr != input.end();
									 ++itr)
	{
		if (std::isprint(static_cast<unsigned char>(*itr)) == false)
		{
			return false;
		}
	}
	return true;
}

bool ScalarConverter::is_number(std::string const& input)
{
	//@needs implementation
	(void) input;
	return true;
}

bool ScalarConverter::has_dot(std::string const& input)
{
	if (input.size() >= 3)
	{
		for (std::string::const_iterator itr = input.begin();
	                                 itr != input.end() - 2;
									 ++itr)
		{
			char current = static_cast<unsigned char>(*itr);
			char next = *(itr + 1);
			char after_next = static_cast<unsigned char>(*(itr + 2));

			if (std::isdigit(current) == true
			    && next == '.'
				&& std::isdigit(after_next) == true)
			{
				return true;
			}
		}
	}
	return false;
}

bool ScalarConverter::has_trailing_f(std::string const& input)
{
	if (*(input.end() - 1) == 'f')
	{
		return true;
	}
	return false;
}

void ScalarConverter::convert(std::string const& input)
{
	print_log("convert() called!");

	// @needs to be abstracted to function
	if (is_printable(input) == false)
	{
		throw NonPrintableException();
	}
	else if (is_number(input) == true)
	{
		if (has_trailing_f(input) == true)
		{
			std::cout << "Float!" << std::endl;
		}
		else if (has_dot(input) == true)
		{
			std::cout << "Double!" << std::endl;
		}
		else
		{
			// @needs check for 'f' and '.'
			// if (has_at_least_once(input, "f.") == true)
			// {
			// 		return ;
			// }
			std::cout << "Int!" << std::endl;
		}
	}
	return ;
}

// -------------------------------------------------------------------------- //
