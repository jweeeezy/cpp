
#ifndef CLASS_PHONEBOOK_H
# define CLASS_PHONEBOOK_H

#include "class.contact.hpp"

class Phonebook
{
	public:

		/*	---		member	---	*/
		Contact	contacts[8];
		size_t	index_add;

		/*	---		functions		---	*/
		void	display_all(void);
		void	display_contact(int index);
		void	display_headers_info(void);
		void	display_headers_all(void);
		void	add_contact(std::string *buffer);

		/*	---		construction	---	*/
		Phonebook( void );
		~Phonebook( void );
};

#endif // CLASS_PHONEBOOK_H

/* ************************************************************************** */