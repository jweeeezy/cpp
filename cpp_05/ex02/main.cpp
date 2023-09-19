// ========================================================================== //
//                               42 | Heilbronn                               //
// ========================================================================== //
//                                                                            //
// name:  jakob willert (jwillert)                                            //
// mail:  jwillert@student.42heilbronn.de                                     //
// file:  main.cpp                                                            //
//                                                                            //
// -------------------------------------------------------------------------- //

#include <cstdlib>                   // needed for MACROS
#include <iostream>                  // needed for std::cout, std::endl
#include "ShrubberyCreationForm.hpp" // needed for SCF class, Bureaucrat class
#include "RobotomyRequestForm.hpp"   // needed for RRF class
#include "PresidentialPardonForm.hpp"

int	main(void)
{
	Bureaucrat b("Hans", 9);
	PresidentialPardonForm  rrf("home");

	std::cout << b << std::endl;
	std::cout << rrf << std::endl;

	b.signForm(rrf);
	b.executeForm(rrf);
	//scf.execute(b);

	return (EXIT_SUCCESS);
}

// -------------------------------------------------------------------------- //
