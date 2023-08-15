
#include "class.contact.hpp"	// needed for Contact
#include "phonebook.hpp"		// needed for debug_log(), print_short()
#include <iostream>				// needed for std::cout, std::endl
#include <iomanip>				// needed for std::right, std::setw()

void	Contact::clear(void)
{
	this->first_name.clear();
	this->last_name.clear();
	this->nick_name.clear();
	this->phone_number.clear();
	this->darkest_secret.clear();
}

void	Contact::display_full(int index)
{
	debug_log("Contact: display_full() called");
	std::cout << std::endl;
	std::cout << std::setw(20) <<
		"index | " << index + 1 << std::endl;
	std::cout << std::setw(20) << "first_name | "
		<< this->first_name << std::endl;
	std::cout << std::setw(20) << "last_name | "
		<< this->last_name << std::endl;
	std::cout << std::setw(20) << "nick_name | "
		<< this->nick_name << std::endl;
	std::cout << std::setw(20) << "phone_number | "
		<< this->phone_number << std::endl;
	std::cout << std::setw(20) << "darkest_secret | "
		<< this->darkest_secret << "\n" << std::endl;
	return ;
}

void	Contact::display_short(int index)
{
	debug_log("Contact: display_short() called");
	std::cout << std::setw(10) << std::right << index + 1;
	std::cout << " | ";
	print_short(this->first_name);
	std::cout << " | ";
	print_short(this->last_name);
	std::cout << " | ";
	print_short(this->nick_name);
	std::cout << " | " << std::endl;
	return ;
}

Contact::Contact(	std::string fn,
					std::string ln,
					std::string nn,
					std::string pn,
					std::string ds)
				:	phone_number(pn),
					darkest_secret(ds),
					first_name(fn),
					last_name(ln),
					nick_name(nn)
{
	return ;
}

Contact::Contact(void)
{
	debug_log("Contact: constructor called");
	return ;
}

Contact::~Contact(void)
{
	debug_log("Contact: destructor called");
	this->clear();
	return ;
}

/* ************************************************************************** */