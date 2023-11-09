// ========================================================================== //
//                               42 | Heilbronn                               //
// ========================================================================== //
//                                                                            //
// name:  jakob willert (jwillert)                                            //
// mail:  jwillert@student.42heilbronn.de                                     //
// file:  main.cpp                                                            //
//                                                                            //
// -------------------------------------------------------------------------- //

#include "PresidentialPardonForm.hpp" // needed for PPF class
#include "RobotomyRequestForm.hpp"    // needed for RRF class
#include "ShrubberyCreationForm.hpp"  // needed for SCF class, Bureaucrat class
#include <cstdlib>                    // needed for MACROS
#include <iostream>                   // needed for std::cout, std::endl

#define GREEN "\033[32m"
#define RESET "\033[0m"

/* log function */
static inline void test_log(std::string story)
{
    std::cout << GREEN << "\n< " << story << " >\n" << RESET << std::endl;
}

/* test cases */

void test_invalid_signing_and_execution(ShrubberyCreationForm & scf,
                                        RobotomyRequestForm & rrf,
                                        PresidentialPardonForm & ppf)
{
    test_log("Testing invalid signing and execution");
    Bureaucrat b("ImHereWithoutPermission", 150);
    std::cout << b << std::endl;

    b.signForm(scf);
    b.signForm(rrf);
    b.signForm(ppf);

    b.executeForm(scf);
    b.executeForm(rrf);
    b.executeForm(ppf);
}

void test_valid_signing(ShrubberyCreationForm & scf, RobotomyRequestForm & rrf,
                        PresidentialPardonForm & ppf)
{
    test_log("Testing valid signing");
    Bureaucrat b("ImJustHereToSignThings", 1);
    std::cout << b << std::endl;

    b.signForm(scf);
    b.signForm(rrf);
    b.signForm(ppf);
}

void test_invalid_execution_on_signed_forms(ShrubberyCreationForm & scf,
                                            RobotomyRequestForm & rrf,
                                            PresidentialPardonForm & ppf)
{
    test_log("Testing invalid execution on signed forms");
    Bureaucrat b("ImHereWithoutPermission", 150);
    std::cout << b << std::endl;

    b.executeForm(scf);
    b.executeForm(rrf);
    b.executeForm(ppf);
}

void test_valid_execution(ShrubberyCreationForm & scf,
                          RobotomyRequestForm & rrf,
                          PresidentialPardonForm & ppf)
{
    test_log("Testing valid execution");
    Bureaucrat b("Angelo Merte", 1);
    std::cout << b << std::endl;

    b.executeForm(scf);
    b.executeForm(rrf);
    b.executeForm(ppf);
}

int main(void)
{
    test_log("Testing Form creation");
    ShrubberyCreationForm scf("Backend");
    RobotomyRequestForm rrf("The Eval Duck");
    PresidentialPardonForm ppf("Pisciner who misplaced sth in the shower");

    std::cout << scf << "\n" << std::endl;
    std::cout << rrf << "\n" << std::endl;
    std::cout << ppf << std::endl;

    test_invalid_signing_and_execution(scf, rrf, ppf);
    test_valid_signing(scf, rrf, ppf);
    test_invalid_execution_on_signed_forms(scf, rrf, ppf);
    test_valid_execution(scf, rrf, ppf);

    return (EXIT_SUCCESS);
}

// -------------------------------------------------------------------------- //
