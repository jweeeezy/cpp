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

// Creates a template way of printing the Fixed obj/class
std::ostream& operator<<(std::ostream& os, const Fixed& obj)
{
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

//	Shifts the FPn by fractional bits to the right and static casts it to a
//	float
float	Fixed::toFloat( void ) const
{
	return (static_cast<float>(_fixed_point_number)
				/ (1 << _fractional_bits));
}

// Shifts the integer part of the FPn by fractional bits to the right so it is
// interpreted / readable as an integer.
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

// Shifts the int number by fractional bits to the integer part of the FPnumber
Fixed::Fixed( int const number )
	: _fixed_point_number(number << _fractional_bits)
{
	print_log("Integer constructor called");
	return ;
}

// Multiplicates the given number by the power of two (1 << fractional bits)
// and rounds it (with roundf() and then casts everything to an integer in order
// to store the FPn value)
Fixed::Fixed( float const number )
	: _fixed_point_number(static_cast<int>(
		roundf(number * (1 << _fractional_bits))))
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
