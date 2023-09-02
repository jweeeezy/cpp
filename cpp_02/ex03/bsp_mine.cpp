// ========================================================================== //
//                               42 | Heilbronn                               //
// ========================================================================== //
//                                                                            //
// name:  jakob willert (jwillert)                                            //
// mail:  jwillert@student.42heilbronn.de                                     //
// file:  bsp_mine.cpp                                                        //
//                                                                            //
// -------------------------------------------------------------------------- //

#include "Point.hpp"

#define EPSILON 0.001f
#define EPSILON_SQUARE 0.001f * 0.001f

bool pointInTriangleBoundingBox(	Fixed x1, Fixed y1,
									Fixed x2, Fixed y2,
									Fixed x3, Fixed y3,
									Fixed x,  Fixed y)
{
	float epsilon(EPSILON);
	Fixed xMin(Fixed::min(x1, Fixed::min(x2, x3)).toFloat() - epsilon);
	Fixed xMax(Fixed::max(x1, Fixed::max(x2, x3)).toFloat() + epsilon);
	Fixed yMin(Fixed::min(y1, Fixed::min(y2, y3)).toFloat() - epsilon);
	Fixed yMax(Fixed::max(y1, Fixed::max(y2, y3)).toFloat() + epsilon);

	if (x < xMin || xMax < x || y < yMin || yMax < y)
	{
		return false;
	}
	else
	{
		return true;
	}
}

bool side(Fixed x1, Fixed y1, Fixed x2, Fixed y2, Fixed x3, Fixed y3, bool* isclockwise)
{
	Fixed ret_product = (y3 - y2) * (x1 - x2) + (x3 * -1 + x2) * (y1 - y2);

	if (*isclockwise == true)
	{
		return (ret_product >= 0);
	}
	return (ret_product <= 0);
}

bool naivePointInTriangle(	Fixed x1, Fixed y1,
							Fixed x2, Fixed y2,
							Fixed x3, Fixed y3,
							Fixed x,  Fixed y,
							bool* isclockwise)
{
	bool checkSide1 = side(x1, y1, x2, y2, x, y, isclockwise);
	bool checkSide2 = side(x2, y2, x3, y3, x, y, isclockwise);
	bool checkSide3 = side(x3, y3, x1, y1, x, y, isclockwise);
	
	if (checkSide1 == true && checkSide2 == true && checkSide3 == true)
		return true;
	else
		return false;
}

void orderCounterclockwise(Point &a, Point &b, Point &c, bool* isclockwise)
{
   	
	Fixed det = (b.get_x() - a.get_x()) * (c.get_y() - a.get_y())
		- (b.get_y() - a.get_y() * (c.get_x() - a.get_x()));

	if (det < 0)
	{
		//Point temp = b;
		//b = c;
		//c = temp;
		*isclockwise = true;
    }
	else
	{
		*isclockwise = false;
	}
}

bool algorithm( Point const a, Point const b, Point const c, Point const point, bool* isclockwise)
{
	
	if (!pointInTriangleBoundingBox(	a.get_x(),     a.get_y(),
										b.get_x(),     b.get_y(),
										c.get_x(),     c.get_y(),
										point.get_x(), point.get_y()))
	{
		//std::cout << "false returned here" << std::endl;
		//return false;
	}
	
	if (naivePointInTriangle(	a.get_x(),     a.get_y(),
								b.get_x(),     b.get_y(),
								c.get_x(),     c.get_y(),
								point.get_x(), point.get_y(),
								isclockwise))
	{
		return true;
	}
	return false;
}

bool bsp( Point const a, Point const b, Point const c, Point const point )
{
	Point ca = a;
	Point cb = b;
	Point cc = c;
	(void) point;
	bool isclockwise = true;

	orderCounterclockwise(ca, cb, cc, &isclockwise);
	
	return(	algorithm (a, b, c, point, &isclockwise) );
}

// -------------------------------------------------------------------------- //
