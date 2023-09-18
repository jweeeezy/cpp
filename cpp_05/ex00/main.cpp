// ========================================================================== //
//                               42 | Heilbronn                               //
// ========================================================================== //
//                                                                            //
// name:  jakob willert (jwillert)                                            //
// mail:  jwillert@student.42heilbronn.de                                     //
// file:  main.cpp                                                            //
//                                                                            //
// -------------------------------------------------------------------------- //

#include <cstdlib>        // needed for MACROS
#include <iostream>       // needed for std::cout, std::endl
#include "Bureaucrat.hpp" // needed for Bureaucrat class, std::exception

#define GREEN "\033[32m"
#define RESET "\033[0m"

static inline void print_story(std::string story)
{
	std::cout << GREEN << "\n< " << story << " >\n" << RESET << std::endl;
}

int	main(void)
{
	Bureaucrat a;
	Bureaucrat b("Bob", 100);
	
	print_story("getName() and getGrade() testing");
	std::cout << a.getName() << " " << a.getGrade() << std::endl;
	std::cout << b.getName() << " " << b.getGrade() << std::endl;

	std::cout << a << std::endl;
	std::cout << b << std::endl;

	print_story("try and catch block while constructing");
	try
	{
		Bureaucrat c("Albert", 155);
		std::cout << c << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	print_story("increment testing");
	while (1)
	{
		try
		{
			b.increment();
		}
		catch (std::exception & e)
		{
			std::cout << e.what() << std::endl;
			break;
		}
	}

	std::cout << b << std::endl;

	return (EXIT_SUCCESS);
}

// -------------------------------------------------------------------------- //
