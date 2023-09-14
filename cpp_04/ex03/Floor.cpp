// ========================================================================== //
//                               42 | Heilbronn                               //
// ========================================================================== //
//                                                                            //
// name:  jakob willert (jwillert)                                            //
// mail:  jwillert@student.42heilbronn.de                                     //
// file:  Floor.cpp                                                           //
//                                                                            //
// -------------------------------------------------------------------------- //

#include "Floor.hpp" // needed for Floor class, AMateria class
#include <iostream>  // needed for std::cout, std::endl

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
		std::cout << YELLOW << "Floor: " << message << RESET << std::endl;
	}
}

/* <~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~> constructors */

Floor::Floor()
{
	debug_log("default constructor called");
	for (int i = 0; i < FLOOR_SIZE; ++i)
	{
		arr[i] = NULL;	
	}
}

Floor::Floor(const Floor& src)
{
	debug_log("copy constructor called");
	for (int i = 0; i < FLOOR_SIZE; ++i)
	{
		if (src.arr[i] != EMPTY)
		{
			arr[i] = src.arr[i]->clone();
		}
		else
		{
			arr[i] = EMPTY;
		}
	}
}

Floor::~Floor()
{
	debug_log("destructor called");
	for (int i = 0; i < FLOOR_SIZE; ++i)
	{
		if (arr[i] != EMPTY)
		{
			delete arr[i];
			arr[i] = EMPTY;
		}
	}
}

/* <~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~> operator overloads */

Floor& Floor::operator=(const Floor& rhs)
{
	debug_log("assignment operator called");
	if (this != &rhs)
	{
		for (int i = 0; i < FLOOR_SIZE; ++i)
		{
			if (rhs.arr[i] != EMPTY)
			{
				arr[i] = rhs.arr[i]->clone();
			}
			else
			{
				arr[i] = EMPTY;
			}
		}
	}
	return *this;
}

/* <~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~> member functions */

void Floor::add(AMateria *drop)
{
	for (int i = 0; i < FLOOR_SIZE; ++i)
	{
		if (arr[i] == EMPTY)
		{
			arr[i] = drop;
			return ;
		}
	}
	this->clean();
	arr[0] = drop;
}

void Floor::clean()
{
	for (int i = 0; i < FLOOR_SIZE; ++i)
	{
		if (arr[i] != EMPTY)
		{
			delete arr[i];
			arr[i] = EMPTY;
		}
	}
}

void Floor::print() const
{
	std::cout << "Floor: ";
	for (int i = 0; i < FLOOR_SIZE; ++i)
	{
		if (arr[i] != NULL)
		{
			std::cout << arr[i]->getType() << " ";
		}
		else
		{
			std::cout << "- ";
		}
	}
	std::cout << std::endl;
	return ;
}

// -------------------------------------------------------------------------- //
