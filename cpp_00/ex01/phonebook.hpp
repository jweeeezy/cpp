
#ifndef PHONEBOOK_H
# define PHONEBOOK_H

#include <string>

#ifndef DEBUG
# define DEBUG 0
#endif // DEBUG

# define MESSAGE_WELCOME "Hint: Please enter one of the following commands:" \
						 " ADD, SEARCH, EXIT"
# define MESSAGE_SEARCH "Hint: Please enter the index of the entry you want" \
						" to be displayed"
# define MESSAGE_SEARCH_BAD "Hint: The index must be between 0 - 8"
void	debug_log(std::string message);
void	debug_log(std::string message, int exit_status);

#endif // PHONEBOOK_H

/* ************************************************************************** */