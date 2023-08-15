
#include "class.phonebook.hpp"	// needed for Phonebook
#include "phonebook.hpp"		// needed for MACROS, utils
#include <iostream>				// needed for std::cout, std::cin, std::endl
#include <cstdlib>				// needed for atoi(), MACROS
//#include <cctype>
#include <iomanip>				// needed for std::setw(), std::right

static void	loop_mode_search(Phonebook *phonebook, bool is_looped)
{
	char	index[128]; //@note might change this to a std::string

	//@todo clean up this code!
	debug_log("loop_mode_search() started");

	if (phonebook->isempty == true)
	{
		std::cout << MESSAGE_SEARCH_EMPTY << std::endl;
		sleep_for(WAIT_DURATION);
		return ;
	}
	if (is_looped == false)
	{
		phonebook->display();
		std::cout << MESSAGE_SEARCH_HINT << std::endl;
		sleep_for(WAIT_DURATION);
		std::cout << MESSAGE_SHELL;
		std::cin >> index;
		std::cout << std::endl;
	}
	else
	{
		std::cout << MESSAGE_SEARCH_BAD << std::endl;
		sleep_for(WAIT_DURATION);
		std::cout << MESSAGE_SHELL;
		std::cin >> index;
		std::cout << std::endl;
	}
	if (isnumber_string(index) == true && std::cin.eof() == false)
	{
		int tmp;

		tmp = atoi(index);
		if (tmp >= 1 && tmp <= 8)
		{
			phonebook->contacts[tmp - 1].display_full(tmp - 1);
			sleep_for(WAIT_DURATION);
			return ;
		}
	}
	if (std::cin.eof() == false)
		loop_mode_search(phonebook, true);
}

static void add_next_field(	Phonebook *phonebook,
									std::string field,
									std::string *buffer,
									size_t index,
									bool is_looped)
{
		debug_log("add_next_field() started");
		if (is_looped == true && index <= 2)
			std::cout << MESSAGE_ADD_BAD_NAME << std::endl;
		else if (is_looped == true && index == 3)
			std::cout << MESSAGE_ADD_BAD_NUMBER << std::endl;
		std::cout << "Please enter the " << field << ": ";
		std::cin >> buffer[index];
		std::cout << "\n" << std::endl;

		// @todo abstract this code so it only displays when needed
		//phonebook->display_full();
		for (size_t i = 0; i < index; ++i)
		{
			std::cout << std::right << std::setw(10) << buffer[i] << " ";
		}

		// @todo restrict phone number to 15 digits
		if (std::cin.eof() == false)
		{
			if ((isalpha_string(buffer[index]) == false && index != 3)
				|| (isnumber_string(buffer[index]) == false && index == 3))
			{
				buffer[index].clear();
				std::cout << std::endl;
				add_next_field(phonebook, field, buffer, index, true);
			}
			else
			{
				std::cout << std::right << std::setw(10) << buffer[index] << std::endl;
				// display
			}
		}
		//@todo display new result
}

static void	loop_mode_add(Phonebook *phonebook)
{
	debug_log("loop_mode_add() started");
	std::string	buffer[5];
	std::string fields[] =
	{
		"first_name",
		"last_name",
		"nick_name",
		"phone_number",
		"darkest_secret"
	};
	for (size_t i = 0; i < 5; ++i)
	{
		add_next_field(phonebook, fields[i], buffer, i, false);
		if (std::cin.eof() == true)
			return ;
	}
	phonebook->add_contact(buffer);
}

int	main_loop(bool test_mode)
{
	// while (std::cin.eof() == false)	//@todo break ctrl+d in steps
	Phonebook	phonebook;

	std::cout << MESSAGE_WELCOME << std::endl;
	sleep_for(WAIT_DURATION);
	if (test_mode == true)
	{
		phonebook.populate();
	}
	while (std::cin.eof() == false)
	{
		std::string	user_input;

		std::cout << MESSAGE_MAIN << std::endl;
		std::cout << MESSAGE_MAIN_HINT << std::endl;
		std::cout << MESSAGE_SHELL;
		std::cin >> user_input;
		std::cout << std::endl;
		if (user_input.compare("ADD") == 0)
		{
			std::cout << MESSAGE_ADD << std::endl;
			loop_mode_add(&phonebook);
		}
		else if(user_input.compare("SEARCH") == 0)
		{
			std::cout << MESSAGE_SEARCH << std::endl;
			loop_mode_search(&phonebook, false);
		}
		else if(user_input.compare("EXIT") == 0)
		{
			debug_log("loop_mode_exit started");
			std::cout << MESSAGE_EXIT << std::endl;
			sleep_for(WAIT_DURATION);
			break ;
		}
		else
		{
			debug_log("no viable command entered");
			std::cout << MESSAGE_MAIN_BAD << std::endl;
			sleep_for(WAIT_DURATION);
		}
	}
	return (EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	int		exit_status;

	exit_status = EXIT_SUCCESS;
	if (argc >= 2 && (strcmp(argv[1], "test") == 0 || strcmp(argv[1], "TEST") == 0))
	{
		debug_log("program started in TEST_MODE");
		exit_status = main_loop(TEST_MODE);
	}
	else
	{
		debug_log("program started in NORMAL_MODE");
		exit_status = main_loop(NORMAL_MODE);
	}
	debug_log("program exited with exit_status = ", exit_status);
	return (exit_status);
}

/* ************************************************************************** */
