// ========================================================================== //
//                               42 | Heilbronn                               //
// ========================================================================== //
//                                                                            //
// name:  jakob willert (jwillert)                                            //
// mail:  jwillert@student.42heilbronn.de                                     //
// file:  Point.hpp                                                           //
//                                                                            //
// -------------------------------------------------------------------------- //

#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

class Point
{
	public:
		Fixed get_x ( void ) const;
		Fixed get_y ( void ) const;

		Point( Fixed x, Fixed y );
		Point();
		Point(const Point& src);
		~Point();
		Point& operator =(Point& rhs);

	private:

		Fixed const x;
		Fixed const y;
};

// prints [x | y]
std::ostream& operator <<(std::ostream& os, const Point& obj);

#endif

// -------------------------------------------------------------------------- //
