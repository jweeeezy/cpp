// ========================================================================== //
//                               42 | Heilbronn                               //
// ========================================================================== //
//                                                                            //
// name:  jakob willert (jwillert)                                            //
// mail:  jwillert@student.42heilbronn.de                                     //
// file:  main.cpp                                                            //
//                                                                            //
// -------------------------------------------------------------------------- //

#include <cstdlib>             // needed for MACROS
#include <iostream>            // needed for std::cout, std::endl
#include "ScalarConverter.hpp" // needed for ScalarConverter class, std::string

#define EXPECTED_ARGC 2

static inline void print_error(std::string message)
{
	std::cout << message << std::endl;
	exit(1);
}

int	main(int argc, char **argv)
{
	if (argc != EXPECTED_ARGC)
	{
		print_error("Wrong arguments!");
	}

	std::string const& input(argv[1]);

	try
	{
		ScalarConverter::convert(input);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	return (EXIT_SUCCESS);
}

// -------------------------------------------------------------------------- //
