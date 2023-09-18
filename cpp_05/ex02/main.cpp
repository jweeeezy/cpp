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
#include "ShrubberyCreationForm.hpp" // needed for SCF class

int	main(void)
{
	Bureaucrat b;
	ShrubberyCreationForm scf("home");

	std::cout << b << std::endl;
	std::cout << scf << std::endl;

	b.executeForm(scf);
	b.signForm(scf);
	b.executeForm(scf);
	//scf.execute(b);

	return (EXIT_SUCCESS);
}

// -------------------------------------------------------------------------- //
