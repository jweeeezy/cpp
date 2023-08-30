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
#include "Fixed.hpp"

Point::Point( float const a, float const b )
{
}

Point::Point()
{
	return ;
}

Point::Point(const Point& src)
{
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
	return (*this);
}

// -------------------------------------------------------------------------- //
