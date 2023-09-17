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
#include "Bureaucrat.hpp" // needed for Bureaucrat class

int	main(void)
{
	Bureaucrat a;
	Bureaucrat b("Bob", 100);
	
	std::cout << a.getName() << " " << a.getGrade() << std::endl;
	std::cout << b.getName() << " " << b.getGrade() << std::endl;

	std::cout << a << std::endl;
	std::cout << b << std::endl;

	try
	{
		Bureaucrat c("Albert", 155);
	}
	catch (Bureaucrat::GradeTooLowException & e)
	{
		std::cout << "1st" << std::endl;
	}
	catch (Bureaucrat::GradeTooHighException & e)
	{
		std::cout << "2nd" << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << "3rd" << std::endl;
	}

	


	return (EXIT_SUCCESS);
}

// -------------------------------------------------------------------------- //
