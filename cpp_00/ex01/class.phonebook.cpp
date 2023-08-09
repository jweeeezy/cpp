
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
	// for (size_t i = 0; i < 9; ++i)
	// {
	// 	this->display_contact(i);
	// }
	return ;
}

void	Phonebook::display_contact(int index)
{
	debug_log("Phonebook: display_contact() called");
	this->contacts[index].display();
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