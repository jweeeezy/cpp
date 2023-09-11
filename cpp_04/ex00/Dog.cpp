// ========================================================================== //
//                               42 | Heilbronn                               //
// ========================================================================== //
//                                                                            //
// name:  jakob willert (jwillert)                                            //
// mail:  jwillert@student.42heilbronn.de                                     //
// file:  Dog.cpp                                                             //
//                                                                            //
// -------------------------------------------------------------------------- //
#include "Dog.hpp"  // needed for Dog class, Animal class
#include <iostream> // needed for std::cout, std::endl

#define YELLOW  "\033[33m"
#define RESET   "\033[0m"

/* <~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~> non-class functions */

static inline void print_log(std::string message)
{
	std::cout << YELLOW << message << RESET << std::endl;
}

/* <~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~> constructors */

Dog::Dog() : Animal("Dog")
{
	print_log("Dog: default constructor called");
}

Dog::Dog(const Dog& src) : Animal(src)
{
	print_log("Cat: copy constructor called");
}

Dog::~Dog()
{
	print_log("Cat: destructor called");
}

/* <~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~> operator overloads */

Dog& Dog::operator=(const Dog& rhs)
{
	print_log("Cat: assignment operator called");
	if (this != &rhs)
	{
		type = rhs.type;
	}
	return *this;
}

/* <~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~> member functions */

void Dog::MakeSound() const
{
	std::cout << "Some badly impersonated Wolf sounds ..." << std::endl;
}

// -------------------------------------------------------------------------- //
