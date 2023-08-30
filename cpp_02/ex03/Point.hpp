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

		Point( float const a, float const b );
		Point();
		Point(const Point& src);
		~Point();
		Point& operator=(const Point& rhs);
	
	private:

		Fixed const x;
		Fixed const y;
};

#endif
