// ========================================================================== //
//                               42 | Heilbronn                               //
// ========================================================================== //
//                                                                            //
// name:  jakob willert (jwillert)                                            //
// mail:  jwillert@student.42heilbronn.de                                     //
// file:  Form.cpp                                                            //
//                                                                            //
// -------------------------------------------------------------------------- //
#include "Form.hpp" // needed for Form class, Bureaucrat class,
					// std::string, std::ostream
#include <iostream> // needed for std::cout, std::endl

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
		std::cout << YELLOW << "Form: " << message << RESET << std::endl;
	}
}

/* <~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~> constructors */

Form::Form() : name("Default"),
               sign_status(false),
               req_grade_sign(150),
               req_grade_exec(150)
{
	debug_log("default constructor called");
}

Form::Form(const Form& src) : name(src.name),
                              sign_status(src.sign_status),
                              req_grade_sign(src.req_grade_sign),
                              req_grade_exec(src.req_grade_exec)
{
	debug_log("copy constructor called");
}

Form::Form(std::string const  name,
           unsigned short int req_sign,
           unsigned short int req_exec) : name(name), sign_status(false)
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

Form::~Form()
{
	debug_log("destructor called");
}

/* <~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~> operator overloads */

Form& Form::operator=(const Form& rhs)
{
	sign_status = rhs.sign_status;
	req_grade_sign = rhs.req_grade_sign;
	req_grade_exec = rhs.req_grade_exec;
	return *this;
}

std::ostream &operator<<(std::ostream &os, const Form &rhs)
{
	os  << "--Form information--\n"
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
	   << rhs.getReqGradeExec();
	
	return os;
}

/* <~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~> member functions */

bool Form::getSignStatus() const
{
	return sign_status;
}

std::string const& Form::getName() const
{
	return name;
}

unsigned short int  Form::getReqGradeSign() const
{
	return req_grade_sign;
}

unsigned short int  Form::getReqGradeExec() const
{
	return req_grade_exec;
}

void Form::beSigned(Bureaucrat &b)
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
