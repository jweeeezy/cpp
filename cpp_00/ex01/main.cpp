
#include "class.phonebook.hpp"	// needed for Phonebook
#include "phonebook.hpp"		// needed for MACROS
#include <iostream>				// needed for cin, cout, cerr
#include <cstdlib>				// needed for atoi(), MACROS
#include <cctype>

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

static bool	is_number_string(std::string str_to_check)
{
	debug_log("is_number_string() called");
	for (std::string::iterator itr = str_to_check.begin();
			itr != str_to_check.end();
			++itr)
	{
		if (isdigit(*itr) == 0)
		{
			debug_log("is_number_string() returned false");
			return(false);
		}
	}
	debug_log("is_number_string() returned true");
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

inline static void	loop_mode_search(Phonebook *phonebook, bool is_looped)
{
	char	index[128];

	//@todo clean up this code!
	debug_log("loop_mode_search() started");

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
	if (is_number_string(index) == true && std::cin.eof() == false)
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

inline static void add_next_field(	std::string field,
									std::string *buffer,
									int index,
									bool is_looped)
{
		debug_log("add_next_field() started");
		std::clog << is_looped << std::endl;

		if (is_looped == true && index <= 2)
			std::cout << MESSAGE_ADD_BAD_NAME << std::endl;
		else if (is_looped == true && index == 3)
			std::cout << MESSAGE_ADD_BAD_NUMBER << std::endl;
		std::cout << "Please enter the " << field << ": ";
		std::cin >> buffer[index];
		//@todo check for ctrl+d
		if ((isalpha_string(buffer[index]) == false && index != 3)
			|| (is_number_string(buffer[index]) == false && index == 3))
			add_next_field(field, buffer, index, true);
		//@todo display new result
}

inline static void	loop_mode_add(Phonebook *phonebook)
{
	debug_log("loop_mode_add() started");
	(void) phonebook;

	std::string	buffer[5];
	std::string fields[] =
	{	"first name", 
		"last name", 
		"nickname",
		"phone number",
		"darkest secret"};
	for (size_t i = 0; i < 5; ++i)
	{
		add_next_field(fields[i], buffer, i, false);
	}
	// @todo save into phonebook
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
			loop_mode_add(&phonebook);
		}
		else if(user_input.compare("SEARCH") == 0)
		{
			loop_mode_search(&phonebook, false);
		}
		else if(user_input.compare("EXIT") == 0)
		{
			debug_log("loop_mode_exit started");
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
