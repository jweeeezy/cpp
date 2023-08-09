
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

inline static void	loop_mode_search(Phonebook *phonebook, bool is_looped)
{
	char	index[128];

	//@todo clean up this code!
	debug_log("SEARCH called");

	if (is_looped == false)
	{
		phonebook->display_all();
		std::cout << MESSAGE_SEARCH << std::endl;
		std::cin >> index;
	}
	else
	{
		std::cout << MESSAGE_SEARCH_BAD << std::endl;
		std::cin >> index;
	}
	if (isnumber(index) == true && std::cin.eof() == false)
	{
		int tmp;

		tmp = atoi(index);
		if (tmp >= 0 && tmp <= 8)
		{
			std::cout << "You entered index = " << index << std::endl;
			return ;
		}
	}
	if (std::cin.eof() == false)
		loop_mode_search(phonebook, true);
}

inline static int	loop_mode_add(void)
{
	debug_log("ADD called");
	return (EXIT_SUCCESS);
}

int	main_loop(void)
{
	while (std::cin.eof() == false)
	{
		Phonebook	phonebook;
		std::string	user_input;

		std::cout << MESSAGE_WELCOME << std::endl;
		std::cin >> user_input;
		if (user_input.compare("ADD") == 0)
		{
			loop_mode_add();
		}
		else if(user_input.compare("SEARCH") == 0)
		{
			loop_mode_search(&phonebook, false);
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