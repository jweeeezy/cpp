// ========================================================================== //
//                               42 | Heilbronn                               //
// ========================================================================== //
//                                                                            //
// name:  jakob willert (jwillert)                                            //
// mail:  jwillert@student.42heilbronn.de                                     //
// file:  RobotomyRequestForm.cpp                                             //
//                                                                            //
// -------------------------------------------------------------------------- //

#include "RobotomyRequestForm.hpp" // needed for RRF class, AForm class,
#include <cstdlib>                 // needed for time(), srand(), rand()
#include <iostream>                // needed for std::cout, std::endl
                                   // std::string

#define YELLOW "\033[33m"
#define RESET "\033[0m"

/* <~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~> non-class functions */

static inline void debug_log(std::string message)
{
    (void)message;
    #ifdef DEBUG
    std::cout << YELLOW << "RRF: " << message << RESET << std::endl;
    #endif // DEBUG
}

/* <~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~> constructors */

RobotomyRequestForm::RobotomyRequestForm(std::string const & target)
    : AForm("RRF", 72, 15)
{
    debug_log("target constructor called");
    setTarget(target);
}

RobotomyRequestForm::RobotomyRequestForm() : AForm("RRF", 72, 15)
{
    debug_log("default constructor called");
    setTarget("target");
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm & src)
    : AForm(src)
{
    debug_log("copy constructor called");
    setTarget(src.getTarget());
}

RobotomyRequestForm::~RobotomyRequestForm() { debug_log("destructor called"); }

/* <~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~> operator overloads */

RobotomyRequestForm &
RobotomyRequestForm::operator=(const RobotomyRequestForm & rhs)
{
    debug_log("assignment operator called");
    AForm::operator=(rhs);
    setTarget(rhs.getTarget());
    return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    AForm::execute(executor);

    std::cout << "*** drilling noises ***" << std::endl;

    srand(static_cast<unsigned int>(time(0)));
    if (rand() % 2)
    {
        std::cout << this->getTarget() << " has been robotomized successfully!"
                  << std::endl;
    }
    else
    {
        std::cout << "Robotomy has failed!" << std::endl;
    }
}

// -------------------------------------------------------------------------- //
