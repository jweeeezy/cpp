
#include <iostream>	// needed for cin, cout, cerr
#include "phonebook.hpp"	// needed for MACROS

int	main_loop(void)
{
	std::string	user_input;

	while (1)
	{
		std::cout << MESSAGE_WELCOME << std::endl;
		std::cin >> user_input;

		if (DEBUG)
			std::clog << "log: user inputted: [" << \
			user_input << "]" << std::endl;

		if (user_input.compare("ADD") == 0)
		{
			if (DEBUG)
				std::clog << "log: ADD called" << std::endl;
		}
		else if(user_input.compare("SEARCH") == 0)
		{
			if (DEBUG)
				std::clog << "log: SEARCH called" << std::endl;
		}
		else if(user_input.compare("EXIT") == 0)
		{
			if (DEBUG)
				std::clog << "log: EXIT called" << std::endl;
			break ;
		}
	}
	return (EXIT_SUCCESS);
}

int	main(void)
{
	int	exit_status;

	exit_status = EXIT_SUCCESS;
	if (DEBUG == true)
		std::clog << "log: program started..." << std::endl;
	exit_status = main_loop();
	if (DEBUG == true)
		std::clog << "log: program exited with exit_status = " \
		<< exit_status << std::endl;
	return (exit_status);
}

/* ************************************************************************** */