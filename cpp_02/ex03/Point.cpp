// ========================================================================== //
//                               42 | Heilbronn                               //
// ========================================================================== //
//                                                                            //
// name:  jakob willert (jwillert)                                            //
// mail:  jwillert@student.42heilbronn.de                                     //
// file:  Point.cpp                                                           //
//                                                                            //
// -------------------------------------------------------------------------- //

#include "Point.hpp" // needed for Point class, Fixed class, std::ostream

std::ostream& operator << (std::ostream& os, const Point& obj)
{
	os	<< "["   << obj.get_x().toFloat()
	   	<< " | " << obj.get_y().toFloat()
		<< "]";
	return os;
}

Fixed Point::get_x(void) const
{
	return this->x;
}

Fixed Point::get_y(void) const
{
	return this->y;
}

Point::Point(Fixed x, Fixed y) : x(x), y(y)
{
	return ;
}

Point::Point() : x(0), y(0)
{
	return ;
}

Point::Point(const Point& src) : x(src.x), y(src.y)
{
	return ;
}

Point::~Point()
{
	return ;
}

Point& Point::operator = (Point& rhs)
{
	// not possible because of const qualifier of x and y
	(void) rhs;
	return (*this);
}

// -------------------------------------------------------------------------- //
