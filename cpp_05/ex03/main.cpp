// ========================================================================== //
//                               42 | Heilbronn                               //
// ========================================================================== //
//                                                                            //
// name:  jakob willert (jwillert)                                            //
// mail:  jwillert@student.42heilbronn.de                                     //
// file:  main.cpp                                                            //
//                                                                            //
// -------------------------------------------------------------------------- //

#include "Intern.hpp" // needed for Intern class, AForm class,
#include <cstdlib>    // needed for MACROS
#include <iostream>   // needed for std::cout, std::endl
                      // Bureaucrat class

#define GREEN "\033[32m"
#define RESET "\033[0m"

/* log function */

static inline void test_log(std::string const & message)
{
    std::cout << GREEN << "\n< " << message << " >" << RESET << std::endl;
}

/* test cases */

void test_unknown_form(Intern & i, Bureaucrat & b)
{
    test_log("Testing making and executing an unknown form");
    try
    {
        AForm * f = i.makeForm("random form", "home");
        b.executeForm(*f);
        delete f;
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }
}

void test_known_form(Intern & i, Bureaucrat & b)
{
    test_log("Testing making and executing a known form");
    try
    {
        AForm * f = i.makeForm("robotomy request", "The Eval Duck");
        b.signForm(*f);
        b.executeForm(*f);
        delete f;
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }
}

void test_no_try_catch_block(Intern & i, Bureaucrat & b)
{
    test_log("Testing throwing exception without try/catch block");
    {
        AForm * ptr = i.makeForm("not existing", "self");
        /* throwing exception replaces NULL check */
        b.signForm(*ptr);
    }
}

int main(void)
{
    test_log("Testing creating Intern (make Forms)and Bureaucrat (exec Forms)");
    Intern i;
    Bureaucrat b("Randy", 1);

    test_unknown_form(i, b);
    test_known_form(i, b);
    test_no_try_catch_block(i, b);
    return (EXIT_SUCCESS);
}

// -------------------------------------------------------------------------- //
