// ========================================================================== //
//                               42 | Heilbronn                               //
// ========================================================================== //
//                                                                            //
// name:  jakob willert (jwillert)                                            //
// mail:  jwillert@student.42heilbronn.de                                     //
// file:  AForm.cpp                                                           //
//                                                                            //
// -------------------------------------------------------------------------- //

#include "AForm.hpp" // needed for AForm class, Bureaucrat class,
					 // std::string, std::ostream
#include <iostream>  // needed for std::cout, std::endl

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
		std::cout << YELLOW << "AForm: " << message << RESET << std::endl;
	}
}

/* <~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~> constructors */

AForm::AForm() : name("Default"),
	             sign_status(false),
			     req_grade_sign(150),
			     req_grade_exec(150)
{
	debug_log("default constructor called");
}

AForm::AForm(const AForm& src) : name(src.name),
	                             sign_status(src.sign_status),
								 req_grade_sign(src.req_grade_sign),
								 req_grade_exec(src.req_grade_exec)
{
	debug_log("copy constructor called");
}

AForm::AForm(std::string const  name,
		     unsigned short int req_sign,
             unsigned short int req_exec) : name(name),
	                                        sign_status(false)
{
	debug_log("name and grade constructor called");
	if (req_sign < 1 || req_exec < 1)
	{
		throw GradeTooHighException();
	}
	else if (req_sign > 150 || req_exec > 150)
	{
		throw GradeTooLowException();
	}
	req_grade_sign = req_sign;
	req_grade_exec = req_exec;
}

AForm::~AForm()
{
	debug_log("destructor called");
}

/* <~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~> operator overloads */

AForm& AForm::operator=(const AForm& rhs)
{
	sign_status = rhs.sign_status;
	req_grade_sign = rhs.req_grade_sign;
	req_grade_exec = rhs.req_grade_exec;
	return *this;
}

std::ostream &operator<<(std::ostream &os, const AForm &rhs)
{
	os  << "--AForm information--\n"
		<< "Name:                      "
		<< rhs.getName()
		<< std::endl;

	os << "Status:                    ";
	if (rhs.getSignStatus() == true)
	{
		os << "signed" << std::endl;
	}
	else
	{
		os << "unsigned" << std::endl;
	}
	
	os << "Required Grade to Sign:    "
	   << rhs.getReqGradeSign()
	   << std::endl;

	os << "Required Grade to Execute: "
	   << rhs.getReqGradeExec()
	   << std::endl;
	
	os << "Target:                    ";

	std::string const& t = rhs.getTarget();
	if (t.empty() == true)
	{
		os << "not set";
	}
	else
	{
		os << t;
	}
	return os;
}

/* <~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~> member functions */
 
std::string const& AForm::getName() const
{
	return name;
}

unsigned short int  AForm::getReqGradeSign() const
{
	return req_grade_sign;
}

unsigned short int  AForm::getReqGradeExec() const
{
	return req_grade_exec;
}

bool AForm::getSignStatus() const
{
	return sign_status;
}

std::string const& AForm::getTarget() const
{
	return target;
}

void AForm::setTarget(std::string const target)
{
	this->target = target;
}

void AForm::beSigned(Bureaucrat &b)
{
	if (b.getGrade() <= this->getReqGradeSign())
	{
		sign_status = true;
	}
	else
	{
		throw GradeTooLowException();
	}
}

// -------------------------------------------------------------------------- //
