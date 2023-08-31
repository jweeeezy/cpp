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
		float get_x ( void ) const;
		float get_y ( void ) const;

		Point( float const a, float const b );
		Point();
		Point(const Point& src);
		~Point();
		Point& operator = (const Point& rhs);

	private:

		Fixed const x;
		Fixed const y;
};

// prints [x | y]
std::ostream& operator << (std::ostream& os, const Point& obj);

#endif

// -------------------------------------------------------------------------- //
