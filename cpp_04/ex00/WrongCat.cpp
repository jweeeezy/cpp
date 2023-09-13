// ========================================================================== //
//                               42 | Heilbronn                               //
// ========================================================================== //
//                                                                            //
// name:  jakob willert (jwillert)                                            //
// mail:  jwillert@student.42heilbronn.de                                     //
// file:  WrongCat.cpp                                                        //
//                                                                            //
// -------------------------------------------------------------------------- //

#include "WrongCat.hpp" // needed for WrongCat class, WrongAnimal class
#include <iostream>     // needed for std::cout, std::endl

#define YELLOW  "\033[33m"
#define RESET   "\033[0m"

/* <~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~> non-class functions */

static inline void print_log(std::string message)
{
	std::cout << YELLOW << message << RESET << std::endl;
}

/* <~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~> constructors */

WrongCat::WrongCat() : WrongAnimal()
{
	this->type = "WrongCat";
	print_log("WrongCat: default constructor called");
}

WrongCat::WrongCat(const WrongCat& src) : WrongAnimal(src)
{
	print_log("WrongCat: copy constructor called");
}

WrongCat::~WrongCat()
{
	print_log("WrongCat: destructor called");
}

/* <~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~> operator overloads */

WrongCat& WrongCat::operator=(const WrongCat& rhs)
{
	print_log("WrongCat: assignment operator called");
	if (this != &rhs)
	{
		this->type = rhs.type;
	}
	return *this;
}

/* <~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~> member functions */

void WrongCat::makeSound() const
{
	std::cout << "I am a Cat you fool!" << std::endl;
}

// -------------------------------------------------------------------------- //
