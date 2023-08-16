
#include "class.Phonebook.hpp"	// needed for Phonebook
#include "phonebook.hpp"		// needed for debug_log()
#include <iostream>				// needed for std::cout, std::endl
#include <iomanip>				// needed for std::setw(), std::right

void	Phonebook::add_contact(std::string *info)
{
	debug_log("phonebook: add_contact() called");
	this->is_empty = false;
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

void	Phonebook::display(void)
{
	debug_log("Phonebook: display() called");
	std::string	headers[] =
	{
		"index",
		"first_name",
		"last_name",
		"nick_name",
	};
	std::cout << COLOR_PHONEBOOK << std::endl;
	for (size_t i = 0; i < 4; ++i)
	{
		std::cout	<< std::right
					<< std::setw(10)
					<< headers[i]
					<< " | ";
	}
	std::cout << std::endl;
	for (size_t i = 0; i < 8; ++i)
	{
		this->contacts[i].display_short(i);
	}
	std::cout << RESET << std::endl;
}

void	Phonebook::populate() const
{
	debug_log("phonebook: populate() called");
    std::string contact_information[][5] =
	{
        {"Jakob", "Willert", "bubu", "1234567890123",
			"not funny"},
        {"Alice", "Johnson", "ally", "5678912345678",
			"afraid of small heights"},
        {"Bob", "Smith", "bobby", "9012345678901",
			"loves romantic horror movies"},
        {"Charlie", "Brown", "chuckles", "2345678901234",
			"scared of tiny dogs"},
        {"Daisy", "Miller", "day", "3456789012345",
			"has a dead twin"},
        {"Edward", "Norton", "eddie", "4567890123456",
			"hates faces without pickles"},
        {"Fiona", "Shrek", "fifi", "5678901234567",
			"actually an ogre princess"},
        {"Veryyyyyloooooongnaaaame", "Owen", "georgie", "6789012345678",
			"loves to sing when someone is in the shower"},
    };
	for (size_t i = 0; i < 8; ++i)
	{
		this->add_contact(contact_information[i]);
	}
}

Phonebook::Phonebook()
{
	debug_log("Phonebook: constructor called");
	this->index_add = 0;
	this->is_empty = true;
	return ;
}

Phonebook::~Phonebook()
{
	debug_log("Phonebook: destructor called");
	return ;
}

/* ************************************************************************** */