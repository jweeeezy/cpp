// ========================================================================== //
//                               42 | Heilbronn                               //
// ========================================================================== //
//                                                                            //
// name:  jakob willert (jwillert)                                            //
// mail:  jwillert@student.42heilbronn.de                                     //
// file:  Cat.cpp                                                             //
//                                                                            //
// -------------------------------------------------------------------------- //

#include "Cat.hpp"  // needed for Cat class, Animal class
#include <iostream> // needed for std::cout, std::endl

#define YELLOW  "\033[33m"
#define RESET   "\033[0m"

/* <~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~> non-class functions */

static inline void print_log(std::string message)
{
	std::cout << YELLOW << message << RESET << std::endl;
}

/* <~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~> constructors */

Cat::Cat() : Animal("Cat")
{
	print_log("Cat: default constructor called");
	brain = new Brain();
}

Cat::Cat(const Cat& src) : Animal(src)
{
	print_log("Cat: copy constructor called");
	type = src.type;
	brain = src.brain;
}

Cat::~Cat()
{
	delete brain;
	print_log("Cat: destructor called");
}

/* <~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~> operator overloads */

Cat& Cat::operator=(const Cat& rhs)
{
	print_log("Cat: assignment operator called");
	if (this != &rhs)
	{
		type = rhs.type;
		brain = rhs.brain;
	}
	return *this;
}

/* <~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~> member functions */

std::string Cat::getIdea(int pos)
{
	return brain->getIdea(pos);
}

void        Cat::setIdea(std::string idea, int pos)
{
	brain->setIdea(idea, pos);
}

void Cat::makeSound() const
{
	std::cout << "Oh long johnson ..." << std::endl;
}

// -------------------------------------------------------------------------- //
