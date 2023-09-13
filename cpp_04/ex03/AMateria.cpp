// ========================================================================== //
//                               42 | Heilbronn                               //
// ========================================================================== //
//                                                                            //
// name:  jakob willert (jwillert)                                            //
// mail:  jwillert@student.42heilbronn.de                                     //
// file:  AMateria.cpp                                                        //
//                                                                            //
// -------------------------------------------------------------------------- //

#include "AMateria.hpp" // needed for AMateria class
#include <iostream>     // needed for std::cout, std::endl

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
		std::cout << YELLOW << "AMateria: " << message << RESET << std::endl;
	}
}

/* <~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~> constructors */

AMateria::AMateria() : type("generic")
{
	debug_log("default constructor called");
}

AMateria::AMateria(const AMateria& src) : type(src.type)
{
	debug_log("copy constructor called");
}

AMateria::AMateria(std::string const & type) : type(type)
{
	debug_log("type constructor called");
}

AMateria::~AMateria()
{
	debug_log("destructor called");
}

/* <~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~> operator overloads */

AMateria& AMateria::operator=(const AMateria& rhs)
{
	debug_log("assignment operator called");
	if (this != &rhs)
	{
		// needs implementation
		debug_log("operator = dummmy overload");
	}
	return *this;
}

/* <~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~> member functions */

std::string const &AMateria::getType() const
{
	return type;
}

void AMateria::use(ICharacter& target)
{
	// needs implementation
	(void) target;
	debug_log("use dummy function");
}

// -------------------------------------------------------------------------- //
