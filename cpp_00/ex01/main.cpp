
#include <iostream>				// needed for cin, cout, cerr
#include "phonebook.hpp"		// needed for MACROS
#include "class.phonebook.hpp"	// needed for Phonebook

void	debug_log(std::string message)
{
	if (DEBUG == true)
		std::clog << "log: " << message << std::endl;
	return ;
}

void	debug_log(std::string message, int exit_status)
{
	if (DEBUG == true)
		std::clog << "log: " << message << exit_status << std::endl;
	return ;
}

int	main_loop(void)
{
	while (1)
	{
		Phonebook	pb;
		std::string	user_input;

		std::cout << MESSAGE_WELCOME << std::endl;
		std::cin >> user_input;
		if (user_input.compare("ADD") == 0)
		{
			debug_log("ADD called");
		}
		else if(user_input.compare("SEARCH") == 0)
		{
			std::string	index;

			debug_log("SEARCH called");
			pb.display_all();
			// @todo pb.display();
			std::cout << MESSAGE_SEARCH << std::endl;
			std::cin >> index;

			// @todo uncaught exception!!
			if (std::stoi(index) < 0 || std::stoi(index) >= 9)
			{
				std::cout << MESSAGE_SEARCH_BAD << std::endl;
				// @todo reloop!
			}
		}
		else if(user_input.compare("EXIT") == 0)
		{
			debug_log("EXIT called");
			break ;
		}
	}
	return (EXIT_SUCCESS);
}

int	main(void)
{
	int	exit_status;

	exit_status = EXIT_SUCCESS;
	debug_log("program started");
	exit_status = main_loop();
	debug_log("program exited with exit_status = ", exit_status);
	return (exit_status);
}

/* ************************************************************************** */