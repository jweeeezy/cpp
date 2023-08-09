
#include "class.phonebook.hpp"
#include "class.contact.hpp"
#include "phonebook.hpp"
#include <iostream>
#include <iomanip>	// needed for setw

void	Phonebook::display_all(void)
{
	debug_log("Phonebook: display_all() called");
	std::cout 	<< std::right
				<< std::setw(10) << "index"
				<< "|"
				<< std::setw(10) << "first name"
				<< "|"
				<< std::setw(10) << "last name"
				<< "|"
				<< std::setw(10) << "nickname"
				<< std::endl;
	return ;
}


void	Phonebook::display_contact(int index)
{
	Contact	contact;

	//@todo format!
	contact = this->contact_list[index];
	std::cout << contact.first_name << std::endl;
	std::cout << contact.last_name << std::endl;
	std::cout << contact.nickname << std::endl;
	std::cout << contact.phone_number<< std::endl;
	std::cout << contact.darkest_secret << std::endl;
	return ;
}

Phonebook::Phonebook()
{
	debug_log("Phonebook: constructor called");
	return ;
}

Phonebook::~Phonebook()
{
	debug_log("Phonebook: destructor called");
	return ;
}

/* ************************************************************************** */