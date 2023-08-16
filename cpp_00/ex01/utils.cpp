
#include "phonebook.hpp"	// needed for DEBUG, debug_log()
#include <iostream>			// needed for std::cout, std::endl
#include <iomanip>			// needed for std::setw(), std::right
#include <unistd.h>			// needed for sleep()

void	debug_log(std::string message)
{
	if (DEBUG == true)
	{
		std::clog << "log: " << message << std::endl;
	}
	return ;
}

void	debug_log(std::string message, int exit_status)
{
	if (DEBUG == true)
	{
		std::clog << "log: " << message << exit_status << std::endl;
	}
	return ;
}

bool	isnumber_string(std::string str_to_check)
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

bool isalpha_string(std::string str_to_check)
{
	debug_log("isalpha_string() called");
	for (std::string::iterator itr = str_to_check.begin() ;
			itr != str_to_check.end();
			++itr)
	{
		if (isalpha(*itr) == false)
		{
			return (false);
		}
	}
	return (true);
}

void	print_message_app(std::string message, bool delay)
{
	std::cout << COLOR_APP << message << RESET << std::endl;
	if (delay == true)
	{
		sleep_for(WAIT_DURATION);
	}
}

void	print_message_warning(std::string warning, bool delay)
{
	std::cout << COLOR_WARNING << warning << RESET << std::endl;
	if (delay == true)
	{
		sleep_for(WAIT_DURATION);
	}
}

void	print_message_hint(std::string hint, bool delay)
{
	std::cout << COLOR_HINT << hint << RESET << std::endl;
	if (delay == true)
	{
		sleep_for(WAIT_DURATION);
	}
}

void	print_short(std::string str)
{
	if (str.length() >= 9)
	{
		std::cout.write(str.c_str(), 9);
		std::cout << ".";
	}
	else
	{
		std::cout << std::right << std::setw(10) << str;
	}
}

void	sleep_for(long long duration)
{
	debug_log("sleep_for() called");
	sleep(duration);
}

std::string	take_input(std::string cmd_line)
{
	std::string buffer;

	debug_log("take_input() called");
	std::cout << COLOR_SHELL << cmd_line;
	std::cin >> buffer;
	std::cout << RESET << std::endl;
	return (buffer);
}

/* ************************************************************************** */