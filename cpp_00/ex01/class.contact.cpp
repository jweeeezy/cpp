
#include "class.contact.hpp"
#include "phonebook.hpp"
#include <iostream>

void	Contact::display(void)
{
	debug_log("Contact: display() called");
	std::cout << this->first_name << std::endl;
	std::cout << this->last_name << std::endl;
	std::cout << this->nickname << std::endl;
	std::cout << this->phone_number<< std::endl;
	std::cout << this->darkest_secret << std::endl;
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