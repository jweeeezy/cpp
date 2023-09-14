// ========================================================================== //
//                               42 | Heilbronn                               //
// ========================================================================== //
//                                                                            //
// name:  jakob willert (jwillert)                                            //
// mail:  jwillert@student.42heilbronn.de                                     //
// file:  Ice.cpp                                                             //
//                                                                            //
// -------------------------------------------------------------------------- //

#include "Ice.hpp"        // needed for Ice class, AMateria class
#include <iostream>       // needed for std::cout, std::endl
#include "ICharacter.hpp" // needed for ICharacter interface

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
		std::cout << YELLOW << "Ice: " << message << RESET << std::endl;
	}
}

/* <~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~> constructors */

Ice::Ice() : AMateria("ice")
{
	debug_log("default constructor called");
}

Ice::Ice(const Ice& src) : AMateria(src.type)
{
	debug_log("copy constructor called");
}

Ice::~Ice()
{
	debug_log("destructor called");
}

/* <~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~> operator overloads */

Ice& Ice::operator=(const Ice& rhs)
{
	debug_log("assignment operator called");
	if (this != &rhs)
	{
		// implementation
	}
	return *this;
}

/* <~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~> member functions */

AMateria* Ice::clone() const
{
	return (new Ice(*this));
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at "
              << target.getName()
			  << " *" << std::endl;
}

// -------------------------------------------------------------------------- //
