// ========================================================================== //
//                               42 | Heilbronn                               //
// ========================================================================== //
//                                                                            //
// name:  jakob willert (jwillert)                                            //
// mail:  jwillert@student.42heilbronn.de                                     //
// file:  main.cpp                                                            //
//                                                                            //
// -------------------------------------------------------------------------- //

#include "Span.hpp"  // needed for Span class
#include <cstdlib>   // needed for MACROS, std::srand, std::rand
#include <ctime>     // needed for std::time
#include <exception> // needed for std::exception
#include <iostream>  // needed for std::cout, std::cerr

#define GREEN "\033[32m"
#define RESET "\033[0m"

/* log function */

static inline void test_log(std::string const & message)
{
    std::cout << GREEN << "\n< " << message << " >" << RESET << std::endl;
}

#define TEST_SIZE 10

int main(void)
{
    {
        test_log("Testing max_N constructor");
        Span sp(TEST_SIZE);

        test_log("Testing copy constructor");
        Span cpy(sp);

        test_log("Testing addNumber() and its exception");
        try
        {
            for (size_t i = 0; i != TEST_SIZE + 1; ++i)
            {
                sp.addNumber(0);
            }
        }
        catch (std::exception & e)
        {
            std::cerr << "caught exception " << e.what() << "\n";
        }

        test_log("Testing getNumbers()");
        {
            std::cout << sp.getNumbers() << "\n";
        }

        test_log("Testing assignment operator and getNumbers() on deep copy");
        Span a;
        a = sp;
        std::cout << a.getNumbers() << "\n";

        test_log("Testing addNumber() on deep copy");
        try
        {
            a.addNumber(0);
        }
        catch (std::exception & e)
        {
            std::cerr << "caught exception: " << e.what() << "\n";
        }
    }

    {
        test_log("Testing addNumbersByVector()");
        Span             tmp(11);
        std::vector<int> vec_zero;
        for (size_t i = 0; i != 5; ++i)
        {
            vec_zero.push_back(0);
        }
        std::vector<int> vec_one;
        for (size_t i = 0; i != 5; ++i)
        {
            vec_zero.push_back(1);
        }
        tmp.addNumbersByVector(vec_zero.begin(), vec_zero.end());
        tmp.addNumbersByVector(vec_one.begin(), vec_one.end());
        std::cout << tmp.getNumbers() << "\n";

        test_log("Testing addNumbersByVector() exception");
        try
        {
            tmp.addNumbersByVector(vec_zero.begin(), vec_zero.end());
        }
        catch (std::exception & e)
        {
            std::cerr << "caught exception: " << e.what() << "\n";
        }
        std::cout << tmp.getNumbers() << "\n";
    }

    {
        test_log("Testing shortestSpan() and longestSpan() exceptions");
        Span tmp;
        try
        {
            std::cout << tmp.shortestSpan() << "\n";
        }
        catch (std::exception & e)
        {
            std::cerr << "caught exception: " << e.what() << "\n";
        }
        try
        {
            std::cout << tmp.longestSpan() << "\n";
        }
        catch (std::exception & e)
        {
            std::cerr << "caught exception: " << e.what() << "\n";
        }
    }
    {
        test_log(
            "Testing shortestSpan() and longestSpan() with random numbers");
        std::srand(static_cast<unsigned int>(std::time(0)));
        Span sp(TEST_SIZE * 2);
        for (size_t i = 0; i != TEST_SIZE; ++i)
        {
            sp.addNumber(std::rand());
        }
        std::cout << sp.getNumbers() << "\n";
        std::cout << "Shortest span: " << sp.shortestSpan() << "\n";
        std::cout << "Longest span: " << sp.longestSpan() << "\n";
    }
    return (EXIT_SUCCESS);
}

// -------------------------------------------------------------------------- //
