
#include "class.phonebook.hpp"
#include "class.contact.hpp"
#include "phonebook.hpp"
#include <iostream>
#include <iomanip>	// needed for setw


void	Phonebook::add_contact(std::string *buffer)
{
	debug_log("phonebook: add_contact() called");
	this->isempty = false;
	this->contacts[7].clear();
	this->contacts[7] = this->contacts[6];
	this->contacts[6] = this->contacts[5];
	this->contacts[5] = this->contacts[4];
	this->contacts[4] = this->contacts[3];
	this->contacts[3] = this->contacts[2];
	this->contacts[2] = this->contacts[1];
	this->contacts[1] = this->contacts[0];
	this->contacts[0] = Contact(buffer[0],
								buffer[1],
								buffer[2],
								buffer[3],
								buffer[4]);
}

void	Phonebook::display_headers_info(void)
{
	std::cout 	<< std::right
				<< std::setw(10) << "index"
				<< "|"
				<< std::setw(10) << "first name"
				<< "|"
				<< std::setw(10) << "last name"
				<< "|"
				<< std::setw(10) << "nickname"
				<< "\n"
				<< std::endl;
	return ;
}

void	Phonebook::display_headers_all(void)
{
	std::cout 	<< std::right
				<< std::setw(10) << "first name"
				<< "|"
				<< std::setw(10) << "last name"
				<< "|"
				<< std::setw(10) << "nickname"
				<< "|"
				<< std::setw(10) << "phone number"
				<< "|"
				<< std::setw(10) << "darkest secret"
				<< "|"
				<< "\n"
				<< std::endl;
	return ;
}


void	Phonebook::display_all(void)
{
	debug_log("Phonebook: display_all() called");
	Phonebook::display_headers_info();
	for (size_t i = 0; i < 8; ++i)
	{
		this->display_contact(i);
	}
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
	this->index_add = 0;
	this->isempty = true;
	return ;
}

Phonebook::~Phonebook()
{
	debug_log("Phonebook: destructor called");
	return ;
}

/* ************************************************************************** */