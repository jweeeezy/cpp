// ========================================================================== //
//                               42 | Heilbronn                               //
// ========================================================================== //
//                                                                            //
// name:  jakob willert (jwillert)                                            //
// mail:  jwillert@student.42heilbronn.de                                     //
// file:  Intern.cpp                                                          //
//                                                                            //
// -------------------------------------------------------------------------- //

#include "Intern.hpp"                 // needed for Intern class
#include "PresidentialPardonForm.hpp" // needed for PPF class
#include "RobotomyRequestForm.hpp"    // needed for RRF class
#include "ShrubberyCreationForm.hpp"  // needed for SCF class
#include <iostream>                   // needed for std::cout, std::endl

#define YELLOW "\033[33m"
#define RESET "\033[0m"

/* <~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~> static variables */

Intern::t_func_map Intern::forms[FORM_COUNT] = {
    {"shrubbery creation", &Intern::makeSCF},
    {"robotomy request", &Intern::makeRRF},
    {"presidential pardon", &Intern::makePPF}};

/* <~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~> non-class functions */

static inline void debug_log(std::string message)
{
    (void)message;
    #ifdef DEBUG
    std::cout << YELLOW << "Intern: " << message << RESET << std::endl;
    #endif // DEBUG
}

/* <~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~> constructors */

Intern::Intern() { debug_log("default constructor called"); }

Intern::Intern(const Intern & src)
{
    debug_log("copy constructor called");
    (void)src;
}

Intern::~Intern() { debug_log("destructor called"); }

/* <~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~> operator overloads */

Intern & Intern::operator=(const Intern & rhs)
{
    debug_log("copy assignment operator called");
    (void)rhs;
    return *this;
}

/* <~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~> member functions */

AForm * Intern::makeForm(std::string const & form,
                         std::string const & target) const
{
    for (int i = 0; i < FORM_COUNT; ++i)
    {
        if (form == forms[i].name)
        {
            std::cout << "Intern creates " << forms[i].name << std::endl;
            return (this->*forms[i].create)(target);
        }
    }
    throw UnknownFormException(); /* replaces returning NULL */
}

AForm * Intern::makePPF(std::string const & target) const
{
    return new PresidentialPardonForm(target);
}

AForm * Intern::makeRRF(std::string const & target) const
{
    return new RobotomyRequestForm(target);
}

AForm * Intern::makeSCF(std::string const & target) const
{
    return new ShrubberyCreationForm(target);
}

// -------------------------------------------------------------------------- //
