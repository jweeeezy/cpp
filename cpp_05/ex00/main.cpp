// ========================================================================== //
//                               42 | Heilbronn                               //
// ========================================================================== //
//                                                                            //
// name:  jakob willert (jwillert)                                            //
// mail:  jwillert@student.42heilbronn.de                                     //
// file:  main.cpp                                                            //
//                                                                            //
// -------------------------------------------------------------------------- //

#include "Bureaucrat.hpp" // needed for Bureaucrat class, std::exception
#include <cstdlib>        // needed for MACROS
#include <exception>
#include <iostream>       // needed for std::cout, std::endl

#define GREEN "\033[32m"
#define RESET "\033[0m"

/* log function */

static inline void test_log(std::string const &message)
{
    std::cout << GREEN << "\n< " << message << " >" << RESET << std::endl;
}

/* test cases */

void test_invalid_construction()
{
    test_log("Testing both exceptions in constructor");
    {
        try
        {
            Bureaucrat toohigh("dummy", 0);
        }
        catch (std::exception &e)
        {
            std::cerr << e.what() << std::endl;
        }
        try
        {
            Bureaucrat toolow("dummy", 151);
        }
        catch (std::exception &e)
        {
            std::cerr << e.what() << std::endl;
        }
    }
}

void test_valid_construction(std::string const &name,
                               unsigned short int grade)
{
    test_log("Testing constructor with valid name and grade");
    Bureaucrat obj(name, grade);
    
    test_log("Testing getter functions");
    std::cout << obj.getName() << " " << obj.getGrade() << std::endl;

    test_log("Testing incrementing the grade");
    obj.increment();
    std::cout << obj.getGrade() << std::endl;
    
    test_log("Testing decrementing the grade");
    obj.decrement();
    std::cout << obj.getGrade() << std::endl;
}

void test_copy_construction_and_operator_overloads()
{
    test_log("Testing assignment / copy constructor");
    
    Bureaucrat obj;
    std::cout << obj << std::endl;
    
    Bureaucrat cpy = obj;
    std::cout << cpy << std::endl;

    Bureaucrat mirr = obj;
    std::cout << mirr << std::endl;
}

void test_exception_on_increment_or_decrement()
{
    test_log("Testing exceptions on inc-/ & decrementing");
    Bureaucrat obj("Dude", 50);
    try
    {   
        while(1)
            obj.decrement();
    }
    catch (std::exception & e)
    {
        std::cerr << e.what() << std::endl;
        std::cout << obj << std::endl;
    }
    try
    {   
        while(1)
            obj.increment();
    }
    catch (std::exception & e)
    {
        std::cerr << e.what() << std::endl;
        std::cout << obj << std::endl;
    }
}

int main(void)
{
    test_invalid_construction();
    test_valid_construction("Paul", 20);
    test_copy_construction_and_operator_overloads();
    test_exception_on_increment_or_decrement();
    return (EXIT_SUCCESS);
}

// -------------------------------------------------------------------------- //
