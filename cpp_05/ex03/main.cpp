// ========================================================================== //
//                               42 | Heilbronn                               //
// ========================================================================== //
//                                                                            //
// name:  jakob willert (jwillert)                                            //
// mail:  jwillert@student.42heilbronn.de                                     //
// file:  main.cpp                                                            //
//                                                                            //
// -------------------------------------------------------------------------- //

#include <cstdlib>    // needed for MACROS
#include "Intern.hpp" // needed for Intern class;

int	main(void)
{
	Intern i;

	i.makeForm("random form", "home");
	delete i.makeForm("shrubbery creation", "home");

	return (EXIT_SUCCESS);
}

// -------------------------------------------------------------------------- //
