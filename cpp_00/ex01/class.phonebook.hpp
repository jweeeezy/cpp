
#ifndef CLASS_PHONEBOOK_H
# define CLASS_PHONEBOOK_H

#include "class.contact.hpp"

class Phonebook
{
	public:

		/*	---		member	---	*/
		Contact	contacts[8];
		size_t	index_add;
		bool	isempty;

		/*	---		functions		---	*/

		void	display(void);
		void	add_contact(std::string *buffer);
		void	populate(void);

		/*	---		construction	---	*/
		Phonebook( void );
		~Phonebook( void );
};

#endif // CLASS_PHONEBOOK_H

/* ************************************************************************** */