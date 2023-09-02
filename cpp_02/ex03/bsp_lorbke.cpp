
#include "Point.hpp"

bool	isClockwise(Point const a, Point const b, Point const c)
{
	Fixed	cross_product = (b.get_x() - a.get_x()) * (c.get_y() - a.get_y())
							- (b.get_y() - a.get_y())
							* (c.get_x() - a.get_x());

	if (cross_product < 0)
	{
		return (true);
	}
	return (false);
}

void orderCounterclockwise(Point &a, Point &b, Point &c)
{
   	
	Fixed det = (b.get_x() - a.get_x()) * (c.get_y() - a.get_y())
		- (b.get_y() - a.get_y() * (c.get_x() - a.get_x()));

	if (det < 0)
	{
		Point temp = b;
		b = c;
		c = temp;
    }
}

static bool	isInnerSide(const Point a, const Point b, const Point c, bool clockwise)
{
	Fixed	scalar_product = (c.get_y() - b.get_y()) * (a.get_x() - b.get_x())
		+ (c.get_x() * -1 + b.get_x()) * (a.get_y() - b.get_y());

	if (clockwise == true)
	{
		return (scalar_product >= 0);
	}
	return (scalar_product <= 0);
}

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	
	bool clockwise = isClockwise(a, b, c);

	bool	sideAB = isInnerSide(a, b, point, clockwise);
	bool	sideBC = isInnerSide(b, c, point, clockwise);
	bool	sideCA = isInnerSide(c, a, point, clockwise);

	if (sideAB == true && sideBC == true && sideCA == true)
		return (true);
	return (false);
}

