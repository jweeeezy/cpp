// ========================================================================== //
//                               42 | Heilbronn                               //
// ========================================================================== //
//                                                                            //
// name:  jakob willert (jwillert)                                            //
// mail:  jwillert@student.42heilbronn.de                                     //
// file:  Character.cpp                                                       //
//                                                                            //
// -------------------------------------------------------------------------- //

#include "Character.hpp" // needed for Character class
#include <iostream>      // needed for std::cout, std::endl

#define YELLOW  "\033[33m"
#define RESET   "\033[0m"

#ifndef DEBUG
# define DEBUG 0
# endif // DEBUG

#define EMPTY NULL // used for clarity - not sure if good practice

/* <~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~> non-class functions */

static inline void debug_log(std::string message)
{
	if (DEBUG)
	{
		std::cout << YELLOW << "Character: " << message << RESET << std::endl;
	}
}

/* <~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~> constructors */

Character::Character(std::string const name) : name(name)
{
	debug_log("name constructor called");
}

Character::Character() : name("Dummy")
{
	debug_log("default constructor called");
}

Character::Character(const Character& src) : name(src.name)
{
	debug_log("copy constructor called");
	for (int i = 0; i < 4; ++i)
	{
		inventory[i] = src.inventory[i]->clone();
	}
}

Character::~Character()
{
	debug_log("destructor called");
	
	// @note delete?
	for (int i = 0; i < 4; ++i)
	{
		if (inventory[i] != EMPTY)
		{
			//delete inventory[i];
		}
	}
}

/* <~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~> operator overloads */

Character& Character::operator=(const Character& rhs)
{
	debug_log("assignment operator called");
	if (this != &rhs)
	{
		for (int i = 0; i < 4; ++i)
		{
			inventory[i] = rhs.inventory[i]; // <-- no clone?
		}
	}
	return *this;
}

/* <~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~> member functions */

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
	inventory[idx]->use(target);
}

// -------------------------------------------------------------------------- //
