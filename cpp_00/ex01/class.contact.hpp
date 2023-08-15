
#ifndef CLASS_CONTACT_H
# define CLASS_CONTACT_H

#include <string>	// needed for std::string

class Contact
{
	private:

		std::string	phone_number;
		std::string	darkest_secret;

	public:

		/*	---		member			---	*/
		std::string	first_name;
		std::string	last_name;
		std::string	nick_name;

		/*	---		functions		---	*/
		void	clear(void);
		void	display_full(int index);
		void	display_short(int index);

		/*	---		construction	---	*/
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