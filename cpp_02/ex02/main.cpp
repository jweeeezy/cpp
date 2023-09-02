// ========================================================================== //
//                               42 | Heilbronn                               //
// ========================================================================== //
//                                                                            //
// name:  jakob willert (jwillert)                                            //
// mail:  jwillert@student.42heilbronn.de                                     //
// file:  main.cpp                                                            //
//                                                                            //
// -------------------------------------------------------------------------- //

#include "Fixed.hpp" // needed for Fixed
#include <cstdlib>   // needed for MACROS
#include <iostream>  // needed for std::cout, std::endl

int main(void)
{
//	Fixed a;
//	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
//
//	std::cout << a << std::endl;
//	std::cout << ++a << std::endl;
//	std::cout << a << std::endl;
//	std::cout << a++ << std::endl;
//	std::cout << a << std::endl;
//	std::cout << b << std::endl;
//
//	std::cout << Fixed::max( a, b ) << std::endl;

	Fixed a(0.1f);

	std::cout << a.getRawBits() << std::endl;


//	Fixed a(42);
//	Fixed b(21);
//
//	std::cout << a << " " << a.getRawBits() << std::endl;
//	std::cout << b << " " << b.getRawBits() << std::endl;
//
//	std::cout << "min:" << Fixed::min(a, b) << std::endl;
//	std::cout << "max:" << Fixed::max(a, b) << std::endl;
//
//	std::cout << "a + b:" << Fixed(a + b) << std::endl;
//	std::cout << "a - b:" << a - b << std::endl;
//	std::cout << "b - a:" << b - a << std::endl;
//
//	std::cout << "a * b:" << Fixed(a * b) << std::endl;
//	std::cout << "a / b:" << a / b << std::endl;
//
//	std::cout << "-a + b:" << (a * -1) + b << std::endl;
//
	return (EXIT_SUCCESS);
}

// -------------------------------------------------------------------------- //
