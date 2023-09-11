// ========================================================================== //
//                               42 | Heilbronn                               //
// ========================================================================== //
//                                                                            //
// name:  jakob willert (jwillert)                                            //
// mail:  jwillert@student.42heilbronn.de                                     //
// file:  WrongAnimal.cpp                                                     //
//                                                                            //
// -------------------------------------------------------------------------- //

#include <iostream>        // needed for std::cout, std::endl
#include "WrongAnimal.hpp" // needed for WrongAnimal class

#define YELLOW  "\033[33m"
#define RESET   "\033[0m"

/* <~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~> non-class functions */

static inline void print_log(std::string message)
{
	std::cout << YELLOW << message << RESET << std::endl;
}

/* <~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~> constructors */

WrongAnimal::WrongAnimal() : type("basic animal")
{
	print_log("WrongAnimal: default constructor called");
}

WrongAnimal::WrongAnimal(const WrongAnimal& src) : type(src.type)
{
	print_log("WrongAnimal: copy constructor called");
}

WrongAnimal::~WrongAnimal()
{
	print_log("WrongAnimal: destructor called");
}

/* <~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~> operator overloads */

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& rhs)
{
	print_log("WrongAnimal: assignment operator called");
	if (this != &rhs)
	{
		type = rhs.type;
	}
	return *this;
}

/* <~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~> member functions */

std::string WrongAnimal::getType() const
{
	return this->type;
}

void WrongAnimal::makeSound() const
{
	std::cout << "Random Animal sounds ..." << std::endl;
}

// -------------------------------------------------------------------------- //
