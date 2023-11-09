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

static inline int log_exit_failure(const std::string & message)
{
	std::cerr << message << std::endl;
	return (EXIT_FAILURE);
}

int	main(int argc, char **argv)
{
	if (argc != EXPECTED_ARGC)
	{
		log_exit_failure("Wrong arguments given!");
	}

	try
	{
		ScalarConverter::convert(argv[1]);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	return (EXIT_SUCCESS);
}

// -------------------------------------------------------------------------- //
