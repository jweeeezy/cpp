// ========================================================================== //
//                               42 | Heilbronn                               //
// ========================================================================== //
//                                                                            //
// name:  jakob willert (jwillert)                                            //
// mail:  jwillert@student.42heilbronn.de                                     //
// file:  MateriaSource.cpp                                                   //
//                                                                            //
// -------------------------------------------------------------------------- //

#include <iostream>          // needed for std::cout, std::endl
#include "MateriaSource.hpp" // needed for MateriaSource class

#define YELLOW  "\033[33m"
#define RESET   "\033[0m"

#ifndef DEBUG
# define DEBUG 0
# endif // DEBUG

/* <~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~> non-class functions */

static inline void debug_log(std::string message)
{
	if (DEBUG)
	{
		std::cout << YELLOW << "MateriaSource: " << message 
			      << RESET << std::endl;
	}
}

/* <~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~> constructors */

MateriaSource::MateriaSource()
{
	debug_log("default constructor called");
	for (int i = 0; i < 4; ++i)
	{
		storage[i] = NULL;
	}
}

MateriaSource::MateriaSource(const MateriaSource& src)
{
	debug_log("copy constructor called");
	(void) src;
}

MateriaSource::~MateriaSource()
{
	debug_log("destructor called");
}

/* <~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~> operator overloads */

MateriaSource& MateriaSource::operator=(const MateriaSource& rhs)
{
	debug_log("assignment operator called");
	(void) rhs;
	return *this;
}

/* <~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~> member functions */

void MateriaSource::showStorage()
{
	for (int i = 0; i < 4; ++i)
	{
		if (storage[i] != NULL)
		{
			std::cout << storage[i]->getType() << std::endl;
		}
		else
		{
			std::cout << "empty" << std::endl;
		}
	}
}

void MateriaSource::learnMateria(AMateria *m)
{
	for (int i = 0; i < 4; ++i)
	{
		if (storage[i] == NULL)
		{
			storage[i] = m;
		}
	}
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	(void) type;
	return 0; // null
}

// -------------------------------------------------------------------------- //
