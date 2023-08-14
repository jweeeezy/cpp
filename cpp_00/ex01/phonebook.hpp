
#ifndef PHONEBOOK_H
# define PHONEBOOK_H

#include <string>

#ifndef DEBUG
# define DEBUG 0
#endif // DEBUG

# define MESSAGE_WELCOME "Welcome to the *phonebook* application!"
# define MESSAGE_MAIN "< You are in the main menu >"
# define MESSAGE_MAIN_HINT "Hint: Please enter one of the following commands:" \
						 " ADD, SEARCH, EXIT..."
# define MESSAGE_SEARCH_HINT "Hint: Please enter the index of the entry you want" \
						" to be displayed..."
# define MESSAGE_SEARCH_BAD "Warning: The index must be between 0 - 8!"
# define MESSAGE_ADD_BAD_NAME "Warning: Names must be alphabet only!"
# define MESSAGE_ADD_BAD_NUMBER "Warning: Only digits allowed!"
# define MESSAGE_EMPTY_PHONEBOOK "Warning: Phonebook is currently empty. Please" \
						" use ADD to add new contacts to the list!"
# define MESSAGE_EXIT "< You decided to exit the *phonebook* application. Goodbye!"

# define MESSAGE_ADD "< You are in the ADD section >"
# define MESSAGE_SEARCH "< You are in the SEARCH section >"

# define WAIT_DURATION 1

void	debug_log(std::string message);
void	debug_log(std::string message, int exit_status);

#endif // PHONEBOOK_H

/* ************************************************************************** */
