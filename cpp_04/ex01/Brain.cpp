// ========================================================================== //
//                               42 | Heilbronn                               //
// ========================================================================== //
//                                                                            //
// name:  jakob willert (jwillert)                                            //
// mail:  jwillert@student.42heilbronn.de                                     //
// file:  Brain.cpp                                                           //
//                                                                            //
// -------------------------------------------------------------------------- //

#include "Brain.hpp" // needed for Brain class
#include <iostream>  // needed for std::cout, std::endl

#define YELLOW  "\033[33m"
#define RESET   "\033[0m"

/* <~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~> non-class functions */

static inline void print_log(std::string message)
{
	std::cout << YELLOW << message << RESET << std::endl;
}

/* <~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~> constructors */

Brain::Brain()
{
	print_log("Brain: default constructor called");
}

Brain::Brain(const Brain& src)
{
	print_log("Brain: copy constructor called");
}

Brain::~Brain()
{
	print_log("Brain: destructor called");
}

Brain& Brain::operator=(const Brain& rhs)
{
	print_log("Brain: assignment operator called");
	if (this != &rhs)
	{
		//ideas = rhs.ideas;
	}
	return *this;
}

// -------------------------------------------------------------------------- //