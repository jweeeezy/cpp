// ========================================================================== //
//                               42 | Heilbronn                               //
// ========================================================================== //
//                                                                            //
// name:  jakob willert (jwillert)                                            //
// mail:  jwillert@student.42heilbronn.de                                     //
// file:  main.cpp                                                            //
//                                                                            //
// -------------------------------------------------------------------------- //

#include "ShrubberyCreationForm.hpp"  // needed for SCF class, Bureaucrat class
#include "RobotomyRequestForm.hpp"    // needed for RRF class
#include "PresidentialPardonForm.hpp" // needed for PPF class
#include <cstdlib>                    // needed for MACROS
#include <iostream>                   // needed for std::cout, std::endl

#define GREEN "\033[32m"
#define RESET "\033[0m"

static inline void print_story(std::string story)
{
	std::cout << GREEN << "\n< " << story << " >\n" << RESET << std::endl;
}

int	main(void)
{
	print_story("Form creation");
	ShrubberyCreationForm  scf("forest");
	RobotomyRequestForm    rrf("The freezer");
	PresidentialPardonForm ppf("Pisciner");
 
	std::cout << scf << "\n" << std::endl;
	std::cout << rrf << "\n" << std::endl;
	std::cout << ppf << "\n" << std::endl;

	print_story("Execute unsigned and sign after");
	{
		Bureaucrat b("Angies right hand", 25);
		
		std::cout << b << std::endl;

		b.executeForm(scf);
		b.executeForm(rrf);
		b.executeForm(ppf);

		b.signForm(scf);
		b.signForm(rrf);
		b.signForm(ppf);
	}

	print_story("Execute without permission");
	{
		Bureaucrat b;

		std::cout << b << std::endl;

		b.executeForm(scf);
		b.executeForm(rrf);
		b.executeForm(ppf);
	}

	print_story("Presidental Execution");
	{
		Bureaucrat a("Angelo Merte", 1);

		std::cout << a << std::endl;

		a.executeForm(scf);
		a.executeForm(rrf);
		a.executeForm(ppf);
	}

	return (EXIT_SUCCESS);
}

// -------------------------------------------------------------------------- //
