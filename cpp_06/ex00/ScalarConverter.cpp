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
#include <cstdlib>
#include <iostream>            // needed for std::cout, std::endl, std::cerr
#include <cstdlib>             // needed for atoi(), atof()

#define YELLOW  "\033[33m"
#define RESET   "\033[0m"

#ifndef DEBUG
# define DEBUG 0
#endif // DEBUG

/* <~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~> non-class functions */

static inline void print_log(std::string message)
{
	if (DEBUG)
	{
		std::cerr << YELLOW
                  << "ScalarConverter: " << message << RESET << std::endl;
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

std::ostream& operator<<(std::ostream& os, const ScalarConverter::Type& type)
{
    switch(type) 
	{
        case ScalarConverter::NON_PRINTABLE:
            os << "NON_PRINTABLE!";
            break;
        case ScalarConverter::FLOAT:
            os << "FLOAT!";
            break;
        case ScalarConverter::DOUBLE:
            os << "DOUBLE!";
            break;
        case ScalarConverter::INTEGER:
            os << "INTEGER!";
            break;
        case ScalarConverter::NON_TYPE:
            os << "NON_TYPE!";
            break;
		case ScalarConverter::STRING:
            os << "STRING!";
            break;
        case ScalarConverter::CHAR:
            os << "CHAR!";
            break;
        default:
            os << "UNKNOWN_TYPE";
            break;
    }
    return os;
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
	if (input.find_first_not_of("0123456789-+.f") != std::string::npos)
	{
		return false;
	}
	if (input.length() <= 1
		&& (has_trailing_f(input) == true || input.compare(".") == 0))
	{
		return false;
	}
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

ScalarConverter::Type ScalarConverter::identify_type(std::string const& input)
{
	print_log("identify_type() called!");

	if (is_printable(input) == false)
	{
		return (ScalarConverter::NON_PRINTABLE);
	}
	else if (is_number(input) == true)
	{
		if (has_trailing_f(input) == true)
		{
			return (ScalarConverter::FLOAT);
		}
		else if (has_dot(input) == true)
		{
			return (ScalarConverter::DOUBLE);
		}
		else
		{
			if (  input.find("f") != std::string::npos
			   || input.find(".") != std::string::npos)
			{
				return (ScalarConverter::NON_TYPE);
			}
				return (ScalarConverter::INTEGER);
		}
	}
	else
	{
		if (input.length() >= 2)
		{
			return (ScalarConverter::STRING);
		}
		return (ScalarConverter::CHAR);
	}
}

void ScalarConverter::convert(std::string const& input)
{
	print_log("convert() called!");
	
	char c;
	int i;
	double d;
	float f;
	Type type = identify_type(input);

	switch(type)
	{
		case CHAR:
			c = static_cast<char>(input[0]);
			i = static_cast<int>(c);
			d = static_cast<double>(c);
			f = static_cast<float>(c);
			break;
		case INTEGER:
			i = atoi(input.c_str());
			c = static_cast<char>(i);
			d = static_cast<double>(i);
			f = static_cast<float>(i);
			break;
		case DOUBLE:
			d = atof(input.c_str());
			c = static_cast<char>(d);
			i = static_cast<int>(d);
			f = static_cast<float>(d);
			break;
		case FLOAT:
			f = static_cast<float>(atof(input.c_str()));
			c = static_cast<char>(f);
			i = static_cast<int>(f);
			d = static_cast<double>(f);
			break;
		case STRING:
			return;
		case NON_TYPE:
			return;
		case NON_PRINTABLE:
			return;
	}

	print_conversion(c, i, d, f);
}

void ScalarConverter::print_conversion(char c, int i, double d, float f)
{
	(void) c;
	(void) i;
	(void) d;
	(void) f;

	std::cout << "No implementation yet" << std::endl;
}

// -------------------------------------------------------------------------- //
