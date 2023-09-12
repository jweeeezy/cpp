// ========================================================================== //
//                               42 | Heilbronn                               //
// ========================================================================== //
//                                                                            //
// name:  jakob willert (jwillert)                                            //
// mail:  jwillert@student.42heilbronn.de                                     //
// file:  Animal.cpp                                                          //
//                                                                            //
// -------------------------------------------------------------------------- //

#include <iostream>   // needed for std::cout, std::endl
#include "Animal.hpp" // needed for Animal class

#define YELLOW  "\033[33m"
#define RESET   "\033[0m"

/* <~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~> non-class functions */

static inline void print_log(std::string message)
{
	std::cout << YELLOW << message << RESET << std::endl;
}

/* <~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~> constructors */

Animal::Animal(std::string t) : type(t)
{
	print_log("Animal: type constructor called");
}

Animal::Animal() : type("basic animal")
{
	print_log("Animal: default constructor called");
}

Animal::Animal(const Animal& src) : type(src.type)
{
	print_log("Animal: copy constructor called");
}

Animal::~Animal()
{
	print_log("Animal: destructor called");
}

/* <~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~> operator overloads */

Animal& Animal::operator=(const Animal& rhs)
{
	print_log("Animal: assignment operator called");
	if (this != &rhs)
	{
		type = rhs.type;
	}
	return *this;
}

/* <~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~> member functions */

std::string Animal::getType() const
{
	return this->type;
}

void Animal::makeSound() const
{
	std::cout << "Random Animal sounds ... " << std::endl;
}

// -------------------------------------------------------------------------- //
