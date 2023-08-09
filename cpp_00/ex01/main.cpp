
#include "class.phonebook.hpp"	// needed for Phonebook
#include "phonebook.hpp"		// needed for MACROS
#include <iostream>				// needed for cin, cout, cerr
#include <cstdlib>				// needed for atoi()


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


static bool	isnumber(std::string str_to_check)
{
	debug_log("isnumber() called");
	for (std::string::iterator itr = str_to_check.begin();
			itr != str_to_check.end();
			++itr)
	{
		if (isdigit(*itr) == 0)
		{
			debug_log("isnumber() returned false");
			return(false);
		}
	}
	debug_log("isnumber() returned true");
	return (true);
}

int	main_loop(void)
{
	while (std::cin.eof() == false)
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
			//@note new loop?
			char	index[128];

			debug_log("SEARCH called");
			pb.display_all();
			std::cout << MESSAGE_SEARCH << std::endl;
			std::cin >> index;

			if (isnumber(index) == true)
			{
				int tmp;

				tmp = atoi(index);
				std::clog << tmp << std::endl;
				if (tmp < 0 || tmp >= 9)
				{
					std::cout << MESSAGE_SEARCH_BAD << std::endl;
				}
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