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
	for (int i = 0; i < 100; ++i)
	{
		ideas[i] = src.ideas[i];
	}
}

Brain::~Brain()
{
	print_log("Brain: destructor called");
}

/* <~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~> operator overloads */

Brain& Brain::operator=(const Brain& rhs)
{
	print_log("Brain: assignment operator called");
	if (this != &rhs)
	{
		for (int i = 0; i < 100; ++i)
		{
			ideas[i] = rhs.ideas[i];
		}
	}
	return *this;
}

/* <~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~> member functions */

std::string Brain::getIdea(int pos)
{
	if (pos < 0 || pos > BRAIN_SIZE)
	{
		return ("Brainfreeze");
	}
	else
	{
		return ideas[pos];
	}
}

void Brain::setIdea(std::string idea, int pos)
{
	if (pos < 0 || pos > BRAIN_SIZE)
	{
		print_log("Brain: setIdea is out of bounds");
	}
	else
	{
		ideas[pos] = idea;
	}
}

// -------------------------------------------------------------------------- //
