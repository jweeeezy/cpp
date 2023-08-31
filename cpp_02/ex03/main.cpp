// ========================================================================== //
//                               42 | Heilbronn                               //
// ========================================================================== //
//                                                                            //
// name:  jakob willert (jwillert)                                            //
// mail:  jwillert@student.42heilbronn.de                                     //
// file:  main.cpp                                                            //
//                                                                            //
// -------------------------------------------------------------------------- //

#include <cstdlib>   // needed for MACROS
#include <iostream>  // needed for std::cout, std::endl
#include "Point.hpp" // needed for Point

#include "./MLX42/include/MLX42/MLX42.h"   // graphics library

int	main( void )
{
	Point a(1.1,2.2);

	std::cout << a << std::endl;
	return (EXIT_SUCCESS);
}

// -------------------------------------------------------------------------- //
