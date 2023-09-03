// -------------------------------------------------------------------------- //
//                               42 | Heilbronn                               //
// ========================================================================== //
//                                                                            //
// name:  jakob willert (jwillert)                                            //
// mail:  jwillert@student.42heilbronn.de                                     //
// file:  Fixed.cpp                                                           //
//                                                                            //
// -------------------------------------------------------------------------- //

#include "Fixed.hpp" // needed for Fixed Class
#include <iostream>  // needed for std::cout, std::endl

#define YELLOW "\033[33m"
#define RESET "\033[0m"

/* <~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~> static variables */

const int Fixed::_fractional_bits = 8;

/* <~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~> non-class functions */

void print_log(std::string message)
{
    std::cout << YELLOW << message << RESET << std::endl;
    return;
}

/* <~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~> member functions */

int Fixed::getRawBits(void)
{
    print_log("getRawBits member function called");
    return (_fixed_point_number);
}

void Fixed::setRawBits(int const raw)
{
    print_log("setRawBits member function called");
    _fixed_point_number = raw;
    return;
}

/* <~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~> operator overloading */

Fixed &Fixed::operator=(const Fixed &rhs)
{
    print_log("Copy assignment operator called");
    if (this != &rhs)
    {
        this->_fixed_point_number = rhs._fixed_point_number;
    }
    return (*this);
}

/* <~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~> constructor */

Fixed::Fixed() : _fixed_point_number(0)
{
    print_log("Default constructor called");
    return;
}

Fixed::Fixed(const Fixed &src) : _fixed_point_number(src._fixed_point_number)
{
    print_log("Copy constructor called");
    return;
}

Fixed::~Fixed()
{
    print_log("Destructor called");
    return;
}

// -------------------------------------------------------------------------- //
