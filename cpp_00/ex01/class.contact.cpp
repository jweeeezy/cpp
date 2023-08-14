
#include "class.contact.hpp"
#include "phonebook.hpp"
#include <iostream>
#include <iomanip>

void	Contact::display_full(void)
{
	debug_log("Contact: display() called");
	std::cout	<< std::right
				<< this->first_name
				<< this->last_name
				<< this->nick_name
				<< this->phone_number
				<< this->darkest_secret
				<< std::endl;

	return ;
}

void	Contact::display_short(int index)
{
	debug_log("Contact: display_short() called");
	std::cout << std::setw(10) << std::right << index;
	std::cout << " | ";
	print_10(this->first_name);
	std::cout << " | ";
	print_10(this->last_name);
	std::cout << " | ";
	print_10(this->nick_name);
	std::cout << " | " << std::endl;
	return ;
}

Contact::Contact(	std::string fn,
					std::string ln,
					std::string nn,
					std::string pn,
					std::string ds)
				:	first_name(fn),
					last_name(ln),
					nick_name(nn),
					phone_number(pn),
					darkest_secret(ds)
{
	return ;
}
void	Contact::clear(void)
{
	this->first_name.clear();
	this->last_name.clear();
	this->nick_name.clear();
	this->phone_number.clear();
	this->darkest_secret.clear();
}


Contact::Contact(void)
{
	debug_log("Contact: constructor called");
	return ;
}

Contact::~Contact(void)
{
	debug_log("Contact: destructor called");
	return ;
}

/* ************************************************************************** */