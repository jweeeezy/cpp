
#ifndef CLASS_CONTACT_H
# define CLASS_CONTACT_H

#include <string>

class Contact
{
	public:

		std::string	first_name;
		std::string	last_name;
		std::string	nickname;
		std::string	phone_number;
		std::string	darkest_secret;

		void	display(void);

		Contact(void);
		~Contact(void);
};

#endif // CLASS_CONTACT_H

/* ************************************************************************** */