// ========================================================================== //
//                               42 | Heilbronn                               //
// ========================================================================== //
//                                                                            //
// name:  jakob willert (jwillert)                                            //
// mail:  jwillert@student.42heilbronn.de                                     //
// file:  ShrubberyCreationForm.cpp                                           //
//                                                                            //
// -------------------------------------------------------------------------- //

#include "ShrubberyCreationForm.hpp" // needed for ShrubberyCreationForm class
#include <exception>
#include <iostream>                  // needed for std::cout, std::endl
#include <fstream>                   // needed for std::ofstream
#include <stdexcept>                 // needed for std::runtime_error

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
		std::cout << YELLOW << "SCF: " << message << RESET << std::endl;
	}
}

/* <~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~> constructors */

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("SCF", 145, 137)
{
	debug_log("default constructor called");
	setTarget("target");
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& src)
	: AForm(src)
{
	debug_log("copy constructor called");
	setTarget(src.getTarget());
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const& target)
	: AForm("SCF", 145, 137)
{
	debug_log("target constructor called");
	setTarget(target);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	debug_log("destructor called");
}

/* <~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~> operator overloads */

ShrubberyCreationForm& ShrubberyCreationForm::operator=
                                            (const ShrubberyCreationForm& rhs)
{
	debug_log("assignment operator called");
	AForm::operator=(rhs);
	setTarget(rhs.getTarget());
	return *this;
}

/* <~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~> member functions */

void ShrubberyCreationForm::execute(Bureaucrat const& executor) const
{
	AForm::execute(executor);

	std::ofstream file((this->getTarget() + "_shrubbery").c_str());
	if (file.is_open() == false)
	{
		debug_log("execute: failed to open file");
		throw std::runtime_error("failed to open file");
	}

	file << "   +   " << "\n"
         << "  / \\  " << "\n"
	     << " +   +  " << "\n"
	     << "/ \\ / \\" << std::endl;

	file << "   +   " << "\n"
         << "  / \\  " << "\n"
	     << " +   +  " << "\n"
	     << "/ \\ / \\" << std::endl;
	
	file << "   +   " << "\n"
         << "  / \\  " << "\n"
	     << " +   +  " << "\n"
	     << "/ \\ / \\" << std::endl;

	file.close();
}

// -------------------------------------------------------------------------- //
