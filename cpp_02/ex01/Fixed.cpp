// -------------------------------------------------------------------------- //
//                               42 | Heilbronn                               //
// ========================================================================== //
//                                                                            //
// name:  jakob willert (jwillert)                                            //
// mail:  jwillert@student.42heilbronn.de                                     //
// file:  Fixed.cpp                                                           //
//                                                                            //
// -------------------------------------------------------------------------- //

#include "Fixed.hpp" // needed for Fixed
#include <iostream>  // needed for std::cout, std::endl
#include <cmath>     // needed for roundf()

#define YELLOW  "\033[33m"
#define RESET   "\033[0m"

/* <~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~> static variables */

const int Fixed::_fractional_bits = 8;

/* <~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~> non-class functions */

static void	print_log(std::string message)
{
	std::cout << YELLOW << message << RESET << std::endl;
	return ;
}

std::ostream& operator<<(std::ostream& os, const Fixed& obj)
{
	//print_log("<< operator used");
	os << obj.toFloat();
	return os;
}

/* <~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~> member functions */

int 	Fixed::getRawBits( void ) const
{
	return (_fixed_point_number);
}

void	Fixed::setRawBits( int const raw )
{
	_fixed_point_number = raw;
	return ;
}

float	Fixed::toFloat( void ) const
{
	return (static_cast<float>(_fixed_point_number) / (1 << _fractional_bits));
}

int		Fixed::toInt( void ) const
{
	return (_fixed_point_number >> _fractional_bits);
}

/* <~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~> operator overloading */

Fixed& Fixed::operator=(const Fixed& rhs)
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
	return ;
}

Fixed::Fixed( int const number )
	: _fixed_point_number(number << _fractional_bits)
{
	print_log("Integer constructor called");
	return ;
}

Fixed::Fixed( float const number )
	: _fixed_point_number(static_cast<int>(roundf(number * (1 << _fractional_bits))))
{
	print_log("Float constructor called");
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

// -------------------------------------------------------------------------- //
