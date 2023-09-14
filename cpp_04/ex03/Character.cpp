// ========================================================================== //
//                               42 | Heilbronn                               //
// ========================================================================== //
//                                                                            //
// name:  jakob willert (jwillert)                                            //
// mail:  jwillert@student.42heilbronn.de                                     //
// file:  Character.cpp                                                       //
//                                                                            //
// -------------------------------------------------------------------------- //

#include <iostream>      // needed for std::cout, std::endl
#include "Character.hpp" // needed for Character class

#define YELLOW  "\033[33m"
#define RESET   "\033[0m"

#ifndef DEBUG
# define DEBUG 0
# endif // DEBUG

#define EMPTY NULL       // used for readability

/* <~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~> non-class functions */

static inline void debug_log(std::string message)
{
	if (DEBUG)
	{
		std::cout << YELLOW << "Character: " << message << RESET << std::endl;
	}
}

static inline void null_array(void **arr, int size)
{
	for (int i = 0; i < size; ++i)
	{
		arr[i] = EMPTY;
	}
}

/* <~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~> constructors */

Character::Character(std::string const name) : name(name)
{
	debug_log("name constructor called");
	null_array((void **) inventory, 4);
}

Character::Character() : name("Dummy")
{
	debug_log("default constructor called");
	null_array((void **) inventory, 4);
}

Character::Character(const Character& src) : name(src.name)
{
	debug_log("copy constructor called");
	null_array((void **) inventory, 4);
	clearInventory();
	for (int i = 0; i < 4; ++i)
	{
		if (src.inventory[i] != EMPTY)
		{
			inventory[i] = src.inventory[i]->clone();
		}
		else
		{
			inventory[i] = EMPTY;
		}
	}
}

Character::~Character()
{
	debug_log("destructor called");
	clearInventory();
}

/* <~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~> operator overloads */

Character& Character::operator=(const Character& rhs)
{
	debug_log("assignment operator called");
	if (this != &rhs)
	{
		clearInventory();
		for (int i = 0; i < 4; ++i)
		{
			if (rhs.inventory[i] != EMPTY)
			{
				inventory[i] = rhs.inventory[i]->clone();
			}
		}
	}
	return *this;
}

/* <~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~> member functions */

void Character::clearInventory()
{
	for (int i = 0; i < 4; ++i)
	{
		if (inventory[i] != EMPTY)
		{
			delete inventory[i];
			inventory[i] = EMPTY;
		}
	}
}

void Character::showInventory() const
{
	std::cout << "Character " << name << ":";
	for (int i = 0; i < 4; ++i)
	{
		if (inventory[i] != EMPTY)
		{
			std::cout << "[" << inventory[i]->getType() << "]";
		}
		else
		{
			std::cout << "[empty]";
		}
	}
	std::cout << std::endl;
}

AMateria* Character::getItem(int idx)
{
	return inventory[idx];
}

std::string const & Character::getName() const
{
	return name;
}

void Character::equip(AMateria* m)
{
	for (int i = 0; i < 4; ++i)
	{
		if (inventory[i] == EMPTY)
		{
			inventory[i] = m;
			break ;
		}
	}
}

void Character::unequip(int idx)
{
	inventory[idx] = EMPTY;
}

void Character::use(int idx, ICharacter& target)
{
	if (inventory[idx] != NULL)
	{
		inventory[idx]->use(target);
	}
	else
	{
		debug_log("use: index out of bounds or no item equipped");
	}
}

// -------------------------------------------------------------------------- //
