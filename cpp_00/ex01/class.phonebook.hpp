
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

		void	display_headers_short(void);
		void	display_contacts_short(void);

		void	display_contacts_full(void);
		void	display_headers_full(void);

		void	add_contact(std::string *buffer);
		void	populate(void);

		/*	---		construction	---	*/
		Phonebook( void );
		~Phonebook( void );
};

#endif // CLASS_PHONEBOOK_H

/* ************************************************************************** */