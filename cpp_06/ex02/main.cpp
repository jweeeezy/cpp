// ========================================================================== //
//                               42 | Heilbronn                               //
// ========================================================================== //
//                                                                            //
// name:  jakob willert (jwillert)                                            //
// mail:  jwillert@student.42heilbronn.de                                     //
// file:  main.cpp                                                            //
//                                                                            //
// -------------------------------------------------------------------------- //

#include "A.hpp"    // needed for A class
#include "B.hpp"    // needed for B class
#include "Base.hpp" // needed for Base class
#include "C.hpp"    // needed for C class

#include <cstdlib>   // needed for MACROS, std::srand, std::rand
#include <ctime>     // needed for std::time
#include <exception> // needed for std::exception
#include <iostream>  // needed for std::cerr
#include <stdexcept> // needed for std::runtime_error
#include <unistd.h>  // needed for sleep

#define YELLOW "\033[33m"
#define GREEN "\033[32m"
#define RESET "\033[0m"

/* <~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~> log function */

static inline void log_debug(std::string const & message)
{
    (void)message;
    #ifdef DEBUG
    std::cout << YELLOW << message << RESET << "\n";
    #endif // DEBUG
}

static inline void log_test(std::string const & message)
{
    std::cout << GREEN << "\n< " << message << " >" << RESET << std::endl;
}

/* <~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~> helper functions */

void generate_seed()
{
    std::srand(static_cast<unsigned>(std::time(NULL)));
}

/* <~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~> subject functions */

Base * generate(void)
{
    int choice = std::rand() % 3;
    switch (choice)
    {
    case 0:
        log_debug("generate: Case A");
        return new A;
    case 1:
        log_debug("generate: Case B");
        return new B;
    case 2:
        log_debug("generate: Case C");
        return new C;
    default:
        throw std::runtime_error("Randomisation failed\n");
    }
}

void identify(Base * ptr)
{
    if (dynamic_cast<A *>(ptr) != NULL)
    {
        std::cout << "A\n";
    }
    else if (dynamic_cast<B *>(ptr) != NULL)
    {
        std::cout << "B\n";
    }
    else if (dynamic_cast<C *>(ptr) != NULL)
    {
        std::cout << "C\n";
    }
}

void identify(Base & ref)
{
    try
    {
        (void)dynamic_cast<A &>(ref);
        std::cout << "A\n";
    }
    catch (std::exception & e) { ; }
    try
    {
        (void)dynamic_cast<B &>(ref);
        std::cout << "B\n";
    }
    catch (std::exception & e) { ; }
    try
    {
        (void)dynamic_cast<C &>(ref);
        std::cout << "C\n";
    }
    catch (std::exception & e) { ; }
}

int main()
{
    /* set seed for randomisation to current time */
    generate_seed();
    
    {
        log_test("Generating a ptr");
        Base * ptr = generate();
        Base & ref = *ptr;

        identify(ptr);
        identify(ref);

        delete ptr;
    }

    /* reseed with sleep for new result */
    sleep(1);
    generate_seed();

    {
        log_test("Generating a ref to a ptr");
        Base & ref = *generate();
        Base * ptr = &ref;

        identify(ref);
        identify(ptr);

        delete ptr;
    }
    return (EXIT_SUCCESS);
}

// -------------------------------------------------------------------------- //
