
#include "class.Phonebook.hpp"	// needed for Phonebook
#include "phonebook.hpp"		// needed for MACROS, utils
#include <iostream>				// needed for std::cout, std::cin, std::endl
#include <cstdlib>				// needed for atoi(), MACROS
#include <cstring>				// needed for strcmp()
#include <iomanip>				// needed for std::setw(), std::right

static inline void add_next_field(	std::string field,
							std::string *buffer,
							size_t index)
{
		debug_log("add_next_field() called");

		while (std::cin.eof() == false)
		{
			buffer[index] = take_input("\nPlease enter the " + field + ": ");

			if (index != 3 && index != 2
				&& isalpha_string(buffer[index]) == false)
			{
				buffer[index].clear();
				print_message_warning(MESSAGE_ADD_BAD_NAME, DELAY);
			}
			else if (index == 3 && isnumber_string(buffer[index]) == false)
			{
				buffer[index].clear();
				print_message_warning(MESSAGE_ADD_BAD_NUMBER, DELAY);
			}
			else
			{
				break ;
			}
		}
}

static void	loop_mode_add(Phonebook *phonebook)
{
	debug_log("loop_mode_add() called");

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
		add_next_field(fields[i], buffer, i);
		if (std::cin.eof() == true)
		{
			return ;
		}
	}

	phonebook->add_contact(buffer);
	phonebook->contacts[0].display_full(0);
	sleep_for(WAIT_DURATION);
}

static void	loop_mode_search(Phonebook *phonebook)
{
	debug_log("loop_mode_search() called");

	if (phonebook->is_empty == true)
	{
		print_message_app(MESSAGE_SEARCH_EMPTY, DELAY);
		return ;
	}

	phonebook->display();
	print_message_hint(MESSAGE_SEARCH_HINT, DELAY);

	while (std::cin.eof() == false)
	{
		std::string	user_input;

		user_input = take_input(MESSAGE_CMD_LINE);
		if (isnumber_string(user_input) == true)
		{
			int	index;

			index = atoi(user_input.c_str());
			if (index >= 1 && index <= 8)
			{
				phonebook->contacts[index - 1].display_full(index - 1);
				sleep_for(WAIT_DURATION);
				break ;
			}
		}
		else if (user_input.compare("BACK") == 0)
		{
			sleep_for(WAIT_DURATION);
			break ;
		}
		if (std::cin.eof() == false)
		{
			print_message_warning(MESSAGE_SEARCH_BAD, DELAY);
		}
	}
}

int	main_loop(bool test_mode)
{
	Phonebook	phonebook;

	if (test_mode == true)
	{
		phonebook.populate();
	}

	print_message_app(MESSAGE_WELCOME, DELAY);

	while (std::cin.eof() == false)
	{
		std::string	user_input;

		print_message_app(MESSAGE_MAIN, NO_DELAY);
		print_message_hint(MESSAGE_MAIN_HINT, NO_DELAY);

		user_input = take_input(MESSAGE_CMD_LINE);

		if (user_input.compare("ADD") == 0)
		{
			print_message_app(MESSAGE_ADD, NO_DELAY);
			loop_mode_add(&phonebook);
		}
		else if(user_input.compare("SEARCH") == 0)
		{
			print_message_app(MESSAGE_SEARCH, NO_DELAY);
			loop_mode_search(&phonebook);
		}
		else if(user_input.compare("EXIT") == 0)
		{
			debug_log("loop_mode_exit started");
			print_message_app(MESSAGE_EXIT, DELAY);
			break ;
		}
		else
		{
			debug_log("no viable command entered");
			print_message_warning(MESSAGE_MAIN_BAD, DELAY);
		}
	}
	return (EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	int		exit_status;

	exit_status = EXIT_SUCCESS;
	if (argc >= 2
		&& (strcmp(argv[1], "test") == 0
		|| strcmp(argv[1], "TEST") == 0))
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