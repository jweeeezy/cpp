
#include "class.phonebook.hpp"
#include "class.contact.hpp"
#include "phonebook.hpp"
#include <iostream>
#include <iomanip>	// needed for setw


void	Phonebook::populate()
{
	debug_log("phonebook: populate() called");

    std::string contact_information[][5] =
	{
        {"Jakob", "Willert", "bubu", "1234567890123", "not funny"},
        {"Alice", "Johnson", "ally", "5678912345678", "afraid of heights"},
        {"Bob", "Smith", "bobby", "9012345678901", "loves romantic movies"},
        {"Charlie", "Brown", "chuckles", "2345678901234", "scared of dogs"},
        {"Daisy", "Miller", "day", "3456789012345", "has a twin"},
        {"Edward", "Norton", "eddie", "4567890123456", "hates pickles"},
        {"Fiona", "Shrek", "fifi", "5678901234567", "actually a princess"},
        {"George", "Owen", "georgie", "6789012345678", "loves to sing in the shower"},
    };
	for (size_t i = 0; i < 8; ++i)
	{
		this->add_contact(contact_information[i]);
	}
}

void	Phonebook::add_contact(std::string *info)
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
	this->contacts[0] = Contact(info[0],
								info[1],
								info[2],
								info[3],
								info[4]);
}

void	Phonebook::display_headers_info(void)
{
	debug_log("phonebook: display_headers_info() called");
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
	debug_log("phonebook: display_headers_all() called");
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