
#include <cstdlib>	// needed for MACROS
#include <string>	// needed for std::string
#include <iostream>	// needed for std::cout, std::endl

#define YELLOW "\033[33m"
#define RESET "\033[0m"

int	main(void)
{
	std::string		string = "HI THIS IS BRAIN";
	std::string*	stringPTR = &string;
	std::string&	stringREF = string;
	// necessary because of inbuilt const qualifier

	std::cout << std::endl;

	std::cout 	<< YELLOW << "memory address of string:      "
				<< RESET << &string << std::endl;
	std::cout 	<< YELLOW << "memory address of stringPTR:   "
				<< RESET <<stringPTR << std::endl;
	std::cout 	<< YELLOW << "memory address of stringREF:   "
				<< RESET <<&stringREF << std::endl;

	std::cout << std::endl;

	std::cout 	<< YELLOW << "value pointed to by string:    "
				<< RESET << string << std::endl;
	std::cout 	<< YELLOW << "value pointed to by stringPTR: "
				<< RESET << *stringPTR << std::endl;
	std::cout 	<< YELLOW << "value pointed to by stringREF: "
				<< RESET << stringREF << std::endl;

	std::cout << std::endl;

	return (EXIT_SUCCESS);
}

/* ************************************************************************** */