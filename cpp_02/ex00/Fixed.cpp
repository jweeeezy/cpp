// -------------------------------------------------------------------------- //
//                               42 | Heilbronn                               //
// ========================================================================== //
//                                                                            //
// name:  jakob willert (jwillert)                                            //
// mail:  jwillert@student.42heilbronn.de                                     //
// file:  Fixed.cpp                                                           //
//                                                                            //
// -------------------------------------------------------------------------- //

#include "Fixed.hpp"
#include <iostream>

void	print_log(std::string message)
{
	std::cout << message << std::endl;
	return ;
}

const int Fixed::_fractional_bits = 8;

Fixed::Fixed() : _fixed_point_number(0)
{
	print_log("Default constructor called");
	return ;
}

Fixed::Fixed(const Fixed& src) : _fixed_point_number(src._fixed_point_number)
{
	print_log("Copy constructor called");
	return ;
}

Fixed::~Fixed()
{
	print_log("Destructor called");
	return ;
}

Fixed& Fixed::operator=(const Fixed& rhs)
{
	print_log("Copy assignment operator called");
	if (this != &rhs)
	{
		this->_fixed_point_number = rhs._fixed_point_number;
	}
	return (*this);
}

int 	Fixed::getRawBits( void )
{
	print_log("getRawBits member function called");
	return (_fixed_point_number);
}

void	Fixed::setRawBits( int const raw )
{
	print_log("setRawBits member function called");
	_fixed_point_number = raw;
	return ;
}

// -------------------------------------------------------------------------- //
