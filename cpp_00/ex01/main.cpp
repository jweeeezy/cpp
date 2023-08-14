
#include "class.phonebook.hpp"	// needed for Phonebook
#include "phonebook.hpp"		// needed for MACROS
#include <iostream>				// needed for cin, cout, cerr
#include <cstdlib>				// needed for atoi(), MACROS
#include <cctype>
#include <iomanip>
#include <chrono>				// needed for seconds()
#include <thread>				// needed for sleep_for()

void	print_10(std::string str)
{
	if (str.length() >= 9)
	{
		//std::cout << std::setw(10) << std::right;
		std::cout.write(str.c_str(), 9);
		std::cout << ".";
	}
	else
	{
		std::cout << std::right << std::setw(10) << str;
	}
}

inline static void	sleep_for(long long duration)
{
	std::this_thread::sleep_for(std::chrono::seconds(duration));
}

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

static bool	isnumber_string(std::string str_to_check)
{
	debug_log("isnumber_string() called");
	for (std::string::iterator itr = str_to_check.begin();
			itr != str_to_check.end();
			++itr)
	{
		if (isdigit(*itr) == 0)
		{
			debug_log("isnumber_string() returned false");
			return(false);
		}
	}
	debug_log("isnumber_string() returned true");
	return (true);
}

static bool isalpha_string(std::string str_to_check)
{
	for (std::string::iterator itr = str_to_check.begin() ;
			itr != str_to_check.end();
			++itr)
	{
		if (isalpha(*itr) == false)
			return (false);
	}
	return (true);
}

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
		phonebook->display_short();
		std::cout << MESSAGE_SEARCH << std::endl;
		std::cin >> index;
	}
	else
	{
		std::cout << MESSAGE_SEARCH_BAD << std::endl;
		std::cin >> index;
	}
	if (isnumber_string(index) == true && std::cin.eof() == false)
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
		phonebook->display_full();
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
		"first name",
		"last name",
		"nickname",
		"phone number",
		"darkest secret"
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

		std::cout << "\n" << MESSAGE_MAIN << std::endl;
		std::cout << "\n" << MESSAGE_MAIN_HINT << "\n" << std::endl;
		std::cout << "$: ";
		std::cin >> user_input;
		if (user_input.compare("ADD") == 0)
		{
			std::cout << "\n" << MESSAGE_ADD << "\n" << std::endl;
			loop_mode_add(&phonebook);
		}
		else if(user_input.compare("SEARCH") == 0)
		{
			std::cout << "\n" << MESSAGE_SEARCH << "\n" << std::endl;
			loop_mode_search(&phonebook, false);
		}
		else if(user_input.compare("EXIT") == 0)
		{
			debug_log("loop_mode_exit started");
			std::cout << "\n" << MESSAGE_EXIT << "\n" << std::endl;
			sleep_for(WAIT_DURATION);
			break ;
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
