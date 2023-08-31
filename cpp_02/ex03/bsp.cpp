#include "Point.hpp"

#define EPSILON 0.001f
#define EPSILON_SQUARE 0.001f * 0.001f

Fixed side(Fixed x1, Fixed y1, Fixed x2, Fixed y2, Fixed x, Fixed y)
{
	// @note small workaround (no - sign instead * -1)
	return (y2 - y1) * (x - x1) + ((x2 * -1) + x1) * (y - y1);
}

bool naivePointInTriangle(	Fixed x1, Fixed y1,
							Fixed x2, Fixed y2,
							Fixed x3, Fixed y3,
							Fixed x,  Fixed y)
{
	bool checkSide1 = side(x1, y1, x2, y2, x, y).toInt() >= 0;
	bool checkSide2 = side(x2, y2, x3, y3, x, y).toInt() >= 0;
	bool checkSide3 = side(x3, y3, x1, y1, x, y).toInt() >= 0;
	
	return checkSide1 && checkSide2 && checkSide3;
}

bool pointInTriangleBoundingBox(	Fixed x1, Fixed y1,
									Fixed x2, Fixed y2,
									Fixed x3, Fixed y3,
									Fixed x,  Fixed y)
{
	Fixed epsilon(EPSILON);

	Fixed xMin = Fixed::min(x1, Fixed::min(x2, x3)) - epsilon;
	Fixed xMax = Fixed::max(x1, Fixed::max(x2, x3)) + epsilon;
	Fixed yMin = Fixed::min(y1, Fixed::min(y2, y3)) - epsilon;
	Fixed yMax = Fixed::max(y1, Fixed::max(y2, y3)) + epsilon;

	if (x < xMin || xMax < x || y < yMin || yMax < y)
	{
		return false;
	}
	else
	{
		return true;
	}
}

Fixed distanceSquarePointToSegment(	Fixed x1, Fixed y1,
									Fixed x2, Fixed y2,
									Fixed x,  Fixed y)
{
	Fixed p1_p2_squareLength = (x2 - x1) * (x2 -x1) + (y2 - y1) * (y2 -y1);
	Fixed dotProduct = ((x - x1) * (x2 - x1) + (y - y1) * (y2 -y1)) / p1_p2_squareLength;
	
	if (dotProduct < 0)
	{
		return (x - x1) * (x - x1) + (y - y1) * (y - y1);
	}
	else if (dotProduct <= 1)
	{
		Fixed p_p1_squareLength = (x1 - x) * (x1 - x) + (y1 -y) * (y1 - y);
		return p_p1_squareLength - dotProduct * dotProduct * p1_p2_squareLength;
	}
	else
	{
		return (x - x2) * (x - x2) + (y -y2) * (y - y2);
	}
}

bool bsp( Point const a, Point const b, Point const c, Point const point )
{
	
	if (!pointInTriangleBoundingBox(	a.get_x(), a.get_y(),
										b.get_x(),b.get_y(),
										c.get_x(), c.get_y(),
										point.get_x(), point.get_y()))
	{
		return false;
	}
	
	if (naivePointInTriangle(	a.get_x(), a.get_y(),
								b.get_x(),b.get_y(),
								c.get_x(), c.get_y(),
								point.get_x(), point.get_y()))
	{
		return false;
	}

	Fixed epsilon_sq(EPSILON_SQUARE);

	if (distanceSquarePointToSegment( 	a.get_x(), a.get_y(),
										b.get_x(), b.get_y(),
										point.get_x(), point.get_y())
										<= epsilon_sq)
	{
		return true;
	}

	if (distanceSquarePointToSegment(	b.get_x(), b.get_y(),
										c.get_x(), c.get_x(),
										point.get_x(), point.get_y())
										<= epsilon_sq)
	{
		return true;
	}

	if (distanceSquarePointToSegment(	c.get_x(), c.get_x(),
										a.get_x(), a.get_y(),
										point.get_x(), point.get_y())
										<= epsilon_sq)
	{
		return true;
	}

	return false;
}
