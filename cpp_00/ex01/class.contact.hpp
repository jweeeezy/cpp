
#ifndef CLASS_CONTACT_H
# define CLASS_CONTACT_H

#include <string>

class Contact
{
	public:

		std::string	first_name;
		std::string	last_name;
		std::string	nick_name;
		std::string	phone_number;
		std::string	darkest_secret;

		void	display(void);
		//void	display_short(void);
		void	clear(void);

		Contact(std::string fn,
				std::string ln,
				std::string nn,
				std::string pn,
				std::string ds);

		Contact(void);
		~Contact(void);
};

#endif // CLASS_CONTACT_H

/* ************************************************************************** */