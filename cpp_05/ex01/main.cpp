// ========================================================================== //
//                               42 | Heilbronn                               //
// ========================================================================== //
//                                                                            //
// name:  jakob willert (jwillert)                                            //
// mail:  jwillert@student.42heilbronn.de                                     //
// file:  main.cpp                                                            //
//                                                                            //
// -------------------------------------------------------------------------- //

#include "Form.hpp" // needed for Form class, Bureaucrat class
#include <cstdlib>  // needed for MACROS
#include <iostream> // needed for std::cout, std::cerr, std::endl

#define GREEN "\033[32m"
#define RESET "\033[0m"

/* log function */

static inline std::string const getBoolAsString(bool is)
{
    if (is == true)
        return ("<is signed>");
    return ("<is not signed>");
}

static inline void test_log(std::string const & message)
{
    std::cout << GREEN << "\n< " << message << " >" << RESET << std::endl;
}

/* test cases */

void test_invalid_construction()
{
    test_log("Testing both exceptions in constructor");
    try
    {
        Form toohigh("Too High", 151, 20);
    }
    catch (std::exception & e)
    {
        std::cerr << e.what() << std::endl;
    }
    try
    {
        Form toolow("too Low", 20, 0);
    }
    catch (std::exception & e)
    {
        std::cerr << e.what() << std::endl;
    }
}

void test_valid_construction(std::string const & name, unsigned int grade_sign,
                             unsigned int grade_exec)
{
    test_log(
        "Testing constructor with valid name and grades for exec and sign");
    Form obj(name, grade_sign, grade_exec);
    std::cout << obj.getName() << " " << getBoolAsString(obj.getSignStatus())
              << " " << obj.getReqGradeSign() << " " << obj.getReqGradeExec()
              << std::endl;
}

void test_copy_construction_and_operator_overloads()
{
    test_log("Testing assignment / copy constructor");
    Form obj;
    std::cout << obj << std::endl;

    Form cpy(obj);
    std::cout << cpy << std::endl;

    Form mirr = obj;
    std::cout << mirr << std::endl;
}

void test_valid_and_unvalid_signing()
{
    test_log("Testing each a valid/unvalid form signing with a Bureaucrat");
    Form fa("A1", 130, 130);
    std::cout << fa << std::endl;

    Form fb("B2", 50, 50);
    std::cout << fb << std::endl;

    Bureaucrat bur("Tom", 70);
    std::cout << bur << std::endl;

    bur.signForm(fa);
    bur.signForm(fb);

}

int main(void)
{
    test_invalid_construction();
    test_valid_construction("Letter", 150, 150);
    test_copy_construction_and_operator_overloads();
    test_valid_and_unvalid_signing();
    return (EXIT_SUCCESS);
}

// -------------------------------------------------------------------------- //
