
#ifndef CLASS_PHONEBOOK_H
# define CLASS_PHONEBOOK_H

#include "class.contact.hpp"

class Phonebook
{
	public:

		/*	---		member	---	*/
		Contact	contacts[8];

		/*	---		functions		---	*/
		void	display_all(void);
		void	display_contact(int index);
		//void	add();
		//void	shift();????

		/*	---		construction	---	*/
		Phonebook( void );
		~Phonebook( void );
};

#endif // CLASS_PHONEBOOK_H

/* ************************************************************************** */