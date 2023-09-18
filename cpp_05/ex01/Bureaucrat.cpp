// ========================================================================== //
//                               42 | Heilbronn                               //
// ========================================================================== //
//                                                                            //
// name:  jakob willert (jwillert)                                            //
// mail:  jwillert@student.42heilbronn.de                                     //
// file:  Bureaucrat.cpp                                                      //
//                                                                            //
// -------------------------------------------------------------------------- //
#include "Bureaucrat.hpp" // needed for Bureaucrat exception class
#include <iostream>       // needed for std::cout, std::endl
#include "Form.hpp"       // needed for Form class

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
		std::cout << YELLOW << "Bureaucrat: " << message << RESET << std::endl;
	}
}

/* <~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~> constructors */

Bureaucrat::Bureaucrat(std::string const name, unsigned short int grade)
	: name(name)
{
	debug_log("grade constructor called");
	if (grade > 150)
	{
		throw GradeTooLowException();
	}
	else if (grade < 1)
	{
		throw GradeTooHighException();
	}
	this->grade = grade;
}

Bureaucrat::Bureaucrat() : name("Bureaucrat"), grade(150)
{
	debug_log("default constructor called");
}

Bureaucrat::Bureaucrat(const Bureaucrat& src) : name(src.name), grade(src.grade)
{
	debug_log("copy constructor called");
}

Bureaucrat::~Bureaucrat()
{
	debug_log("destructor called");
}

/* <~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~> operator overloads */

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& rhs)
{
	if (this != &rhs)
	{
		grade = rhs.grade;
	}
	return *this;
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &rhs)
{
	os  << rhs.getName() << ", bureaucrat grade "
		<< rhs.getGrade() << ".";
	return (os);
}

/* <~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~> member functions */

void Bureaucrat::signForm(Form& f)
{
	if (f.getSignStatus() == true)
	{
		std::cout << this->getName()
                  << " couldn't sign "
                  << f.getName()
                  << " because it is already signed." << std::endl;
		return ;
	}
	try
	{
		f.beSigned(*this);
		std::cout << this->getName()
                  << " signed "
				  << f.getName()
				  << "."
				  << std::endl;
	}
	catch (std::exception &e)
	{	
		std::cout << this->getName()
                  << " couldn't sign "
                  << f.getName()
                  << " because the Grade is too low." << std::endl;
	}
}

void Bureaucrat::increment()
{
	if (grade - 1 < 1)
	{
		throw GradeTooHighException();
	}
	grade -= 1;
}

void Bureaucrat::decrement()
{
	if (grade + 1 > 150)
	{
		throw GradeTooLowException();
	}
	grade += 1;
}

unsigned short int Bureaucrat::getGrade() const
{
	return grade;
}

std::string const & Bureaucrat::getName() const
{
	return name;
}

// -------------------------------------------------------------------------- //
