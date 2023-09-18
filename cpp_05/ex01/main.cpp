// ========================================================================== //
//                               42 | Heilbronn                               //
// ========================================================================== //
//                                                                            //
// name:  jakob willert (jwillert)                                            //
// mail:  jwillert@student.42heilbronn.de                                     //
// file:  main.cpp                                                            //
//                                                                            //
// -------------------------------------------------------------------------- //

#include <cstdlib>  // needed for MACROS
#include <exception>
#include <iostream> // needed for std::cout, std::endl
#include "Form.hpp" // needed for Form class, Bureaucrat class

#define GREEN "\033[32m"
#define RESET "\033[0m"

static inline void print_story(std::string story)
{
	std::cout << GREEN << "\n< " << story << " >\n" << RESET << std::endl;
}

int	main(void)
{
	print_story("Wrong Form");
	{
		try
		{
			Form f("Wrong", 151, 151);
			std::cout << f << std::endl;
		}
		catch (std::exception& e)
		{
			std::cout << "Exception caught: " << e.what() << std::endl;
		}
	}

	print_story("Default Bureaucrat");
	Bureaucrat b;
	std::cout << b << std::endl;

	print_story("Explicit Bureaucrat");
	Bureaucrat b2("Hans", 2);
	std::cout << b2 << std::endl;

	print_story("Explicit Form");
	Form f("Thesis", 20, 20);
	std::cout << f << std::endl;
	
	print_story("Signing Test");
	b.signForm(f);
	b2.signForm(f);
	b2.signForm(f);

	print_story("Assignment operator test");
	{
		Form f2;
		f2 = f;
		b2.signForm(f2);
	}

	print_story("Copy constructor test");
	{
		Form f2(f);
		b2.signForm(f2);
	}

	return (EXIT_SUCCESS);
}

// -------------------------------------------------------------------------- //
