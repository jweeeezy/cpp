// ========================================================================== //
//                               42 | Heilbronn                               //
// ========================================================================== //
//                                                                            //
// name:  jakob willert (jwillert)                                            //
// mail:  jwillert@student.42heilbronn.de                                     //
// file:  main.cpp                                                            //
//                                                                            //
// -------------------------------------------------------------------------- //

#include <iostream>   // needed for std::cout, std::endl
#include <cstdlib>    // needed for MACROS
#include "Intern.hpp" // needed for Intern class;

int	main(void)
{
	Intern i;
	
	try
	{
		AForm*f1 = i.makeForm("random form", "home");
		AForm*f2 = i.makeForm("shrubbery creation", "home");

		delete f1;
		delete f2;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	return (EXIT_SUCCESS);
}

// -------------------------------------------------------------------------- //
