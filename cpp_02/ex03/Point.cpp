// ========================================================================== //
//                               42 | Heilbronn                               //
// ========================================================================== //
//                                                                            //
// name:  jakob willert (jwillert)                                            //
// mail:  jwillert@student.42heilbronn.de                                     //
// file:  Point.cpp                                                           //
//                                                                            //
// -------------------------------------------------------------------------- //

#include "Point.hpp"

std::ostream& operator<<(std::ostream& os, const Point& obj)
{
	os	<< "[" << obj.get_x()
	   	<< " | " << obj.get_y()
		<< "]";
	return os;
}

float Point::get_x( void ) const
{
	return (this->x.toFloat());
}

float Point::get_y( void ) const
{
	return (this->y.toFloat());
}

Point::Point( float const a, float const b ) : x(a), y(b)
{
	return ;
}

Point::Point() : x(0), y(0)
{
	return ;
}

Point::Point(const Point& src)
{
	(void) src;
}

Point::~Point()
{
	return ;
}

Point& Point::operator=(const Point& rhs)
{
	//if (this != &rhs)
	//{
	//	this->x = rhs.x;
	//	this->y = rhs.y;
	//}
	(void) rhs;
	return (*this);
}

// -------------------------------------------------------------------------- //
