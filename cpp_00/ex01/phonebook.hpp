
#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include <string>		// needed for std::string

/*	---		debug macro	---	*/
# ifndef DEBUG
#  define DEBUG 0
# endif // DEBUG

/*	---		macros	---	*/
# define TEST_MODE true
# define NORMAL_MODE false
# define MESSAGE_WELCOME "\nWelcome to the *phonebook* application!\n"
# define MESSAGE_EXIT "\n< You decided to exit the *phonebook* " \
						"application. Goodbye!\n"
# define MESSAGE_SHELL "$: "
# define MESSAGE_MAIN "\n< You are in the main menu >\n"
# define MESSAGE_MAIN_HINT "\nHint: Please enter one of the following " \
						"commands: ADD, SEARCH, EXIT...\n"
# define MESSAGE_MAIN_BAD "\nWarning: You didn't enter a viable command!\n"
# define MESSAGE_ADD "\n< You are in the ADD section >\n"
# define MESSAGE_ADD_BAD_NAME "\nWarning: Names must be alphabet only!\n"
# define MESSAGE_ADD_BAD_NUMBER "\nWarning: Only digits allowed!\n"

# define MESSAGE_SEARCH "\n< You are in the SEARCH section >\n"
# define MESSAGE_SEARCH_BAD "\nWarning: The index must be between 1 - 8!\n"
# define MESSAGE_SEARCH_EMPTY "\nWarning: Phonebook is currently empty." \
						" Please use ADD to add new contacts to the list!\n"
# define MESSAGE_SEARCH_HINT "\nHint: Please enter the index of the entry " \
						"you want to be displayed...\n"
# define WAIT_DURATION 1

/*	---		utils	---	*/
void		debug_log(std::string message);
void		debug_log(std::string message, int exit_status);
bool		isalpha_string(std::string str_to_check);
bool		isnumber_string(std::string str_to_check);
void		print_short(std::string str);
void		sleep_for(long long duration);

#endif // PHONEBOOK_H

/* ************************************************************************** */