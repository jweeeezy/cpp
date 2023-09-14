// ========================================================================== //
//                               42 | Heilbronn                               //
// ========================================================================== //
//                                                                            //
// name:  jakob willert (jwillert)                                            //
// mail:  jwillert@student.42heilbronn.de                                     //
// file:  Cure.cpp                                                            //
//                                                                            //
// -------------------------------------------------------------------------- //

#include "Cure.hpp"       // needed for Cure class
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
		std::cout << YELLOW << "Cure: " << message << RESET << std::endl;
	}
}
/* <~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~> constructors */

Cure::Cure() : AMateria("cure")
{
	debug_log("default constructor called");
}

Cure::Cure(const Cure& src) : AMateria(src.type)
{
	debug_log("copy constructor called");
}

Cure::~Cure()
{
	debug_log("destructor called");
}

/* <~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~> operator overloads */

Cure& Cure::operator=(const Cure& rhs)
{
	debug_log("assignment operator called");
	if (this != & rhs)
	{

	}
	return *this;
}

/* <~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~> member functions */

AMateria* Cure::clone() const
{
	return (new Cure(*this));
}
void Cure::use(ICharacter& target)
{
	std::cout << "* heals "
              << target.getName()
			  << "'s wounds *" << std::endl;
}

// -------------------------------------------------------------------------- //
