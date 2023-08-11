
#include "class.contact.hpp"
#include "phonebook.hpp"
#include <iostream>

void	Contact::display(void)
{
	debug_log("Contact: display() called");
	std::cout << this->first_name << std::endl;
	std::cout << this->last_name << std::endl;
	std::cout << this->nick_name << std::endl;
	std::cout << this->phone_number<< std::endl;
	std::cout << this->darkest_secret << std::endl;
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