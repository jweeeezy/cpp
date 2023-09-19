// ========================================================================== //
//                               42 | Heilbronn                               //
// ========================================================================== //
//                                                                            //
// name:  jakob willert (jwillert)                                            //
// mail:  jwillert@student.42heilbronn.de                                     //
// file:  PresidentialPardonForm.cpp                                          //
//                                                                            //
// -------------------------------------------------------------------------- //
#include "PresidentialPardonForm.hpp" // needed for PPF class, AForm class,
                                      // std::string
#include <iostream>                   // needed for std::cout, std::endl

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
		std::cout << YELLOW << "PPF: " << message << RESET << std::endl;
	}
}

/* <~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~> constructors */

PresidentialPardonForm::PresidentialPardonForm(std::string const& target)
	: AForm("PPF", 25, 5)
{
	debug_log("target constructor called");
	setTarget(target);
}

PresidentialPardonForm::PresidentialPardonForm() : AForm ("PPF", 25, 5)
{
	debug_log("default constructor called");
	setTarget("target");
}

PresidentialPardonForm::PresidentialPardonForm
                                            (const PresidentialPardonForm& src)
	: AForm(src)
{
	debug_log("copy constructor called");
	setTarget(src.getTarget());
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	debug_log("destructor called");
}

PresidentialPardonForm& PresidentialPardonForm::operator=
                                            (const PresidentialPardonForm& rhs)
{
	debug_log("assignment operator called");
	AForm::operator=(rhs);
	setTarget(rhs.getTarget());
	return *this;
}

void PresidentialPardonForm::execute(Bureaucrat const& executor) const
{
	AForm::execute(executor);
	std::cout << this->getTarget()
		      << " has been pardoned by Zaphod Beeblebrox"
			  << std::endl;
}

// -------------------------------------------------------------------------- //
