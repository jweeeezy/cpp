

#ifndef CLASS_PHONEBOOK_H
# define CLASS_PHONEBOOK_H

#include <array>
#include "class.contact.hpp"

class Phonebook
{
	public:

		std::array<Contact, 8> contact_list;

		void	display_all(void);
		void	display_contact(int index);
		//void	add();
		//void	remove();???
		//void	shift();????

		Phonebook( void );
		~Phonebook( void );
};

#endif // CLASS_PHONEBOOK_H

/* ************************************************************************** */