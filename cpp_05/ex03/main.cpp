// ========================================================================== //
//                               42 | Heilbronn                               //
// ========================================================================== //
//                                                                            //
// name:  jakob willert (jwillert)                                            //
// mail:  jwillert@student.42heilbronn.de                                     //
// file:  main.cpp                                                            //
//                                                                            //
// -------------------------------------------------------------------------- //

#include <iostream>       // needed for std::cout, std::endl
#include <cstdlib>        // needed for MACROS
#include "Intern.hpp"     // needed for Intern class, AForm class,
						  // Bureaucrat class

#define GREEN "\033[32m"
#define RESET "\033[0m"

static inline void print_story(std::string story)
{
	std::cout << GREEN << "\n< " << story << " >\n" << RESET << std::endl;
}

int	main(void)
{
	Intern i;
	Bureaucrat b("Randy", 2);
	
	print_story("unknown form test");
	try
	{
		AForm* f = i.makeForm("random form", "home");
		b.executeForm(*f);
		delete f;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	print_story("known form test");
	try
	{
		AForm* f = i.makeForm("robotomy request", "fridge");
		b.signForm(*f);
		b.executeForm(*f);
		delete f;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	print_story("NULL test / no try/catch block");
	{
		AForm* ptr = i.makeForm("not existing", "self");
		// possible segfault if no exception thrown!
		
		if (ptr != NULL)
		{
			b.signForm(*ptr);
		}
		else
		{
			std::cout << "ptr is NULL!" << std::endl;
		}
	}

	return (EXIT_SUCCESS);
}

// -------------------------------------------------------------------------- //
