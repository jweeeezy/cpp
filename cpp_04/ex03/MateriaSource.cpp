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

static inline void null_array(void **arr, int size)
{
	for (int i = 0; i < size; ++i)
	{
		arr[i] = NULL;
	}
}

/* <~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~> constructors */

MateriaSource::MateriaSource()
{
	debug_log("default constructor called");
	null_array((void**) storage, 4);
}

MateriaSource::MateriaSource(const MateriaSource& src)
{
	debug_log("copy constructor called");
	for (int i = 0; i < 4; ++i)
	{
		if (src.storage[i] != NULL)
		{
			storage[i] = src.storage[i]->clone();
		}
		else
		{
			storage[i] = NULL;
		}
	}
}

MateriaSource::~MateriaSource()
{
	debug_log("destructor called");
	for (int i = 0; i < 4; ++i)
	{
		if (storage[i] != NULL)
		{
			delete storage[i];
		}
	}
}

/* <~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~> operator overloads */

MateriaSource& MateriaSource::operator=(const MateriaSource& rhs)
{
	debug_log("assignment operator called");
	if (this != &rhs)
	{
		for (int i = 0; i < 4; ++i)
		{
			if (rhs.storage[i] != NULL)
			{
				storage[i] = rhs.storage[i]->clone();
			}
			else
			{
				storage[i] = NULL;
			}
		}
	}

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
			break ;
		}
	}
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; ++i)
	{
		if (storage[i]->getType() == type)
		{
			return (storage[i]->clone());
		}
	}
	return NULL;
}

// -------------------------------------------------------------------------- //
