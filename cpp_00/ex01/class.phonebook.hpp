
#ifndef CLASS_PHONEBOOK_H
# define CLASS_PHONEBOOK_H

#include "class.Contact.hpp" // needed for Contact

class Phonebook
{
	public:

		/*	---		member			---	*/
		Contact	contacts[8];
		size_t	index_add;
		bool	is_empty;

		/*	---		functions		---	*/
		void	add_contact(std::string *buffer);
		void	display(void) const;
		void	populate(void);

		/*	---		construction	---	*/
		Phonebook( void );
		~Phonebook( void );
};

#endif // CLASS_PHONEBOOK_H

/* ************************************************************************** */