// ========================================================================== //
//                               42 | Heilbronn                               //
// ========================================================================== //
//                                                                            //
// name:  jakob willert (jwillert)                                            //
// mail:  jwillert@student.42heilbronn.de                                     //
// file:  bsp.cpp                                                             //
//                                                                            //
// -------------------------------------------------------------------------- //

#include "Point.hpp" // needed for Point class, Fixed class

// This function calculates the orientation of the triplet (p, q, r).
// If the result is positive, then the orientation is counterclockwise
// If the result is negative, then the orientation is clockwise
// If the result is 0, then the points are collinear (no triangle can be formed)
static Fixed orientation(Point const &p, Point const &q, Point const &r) 
{
    // determinant
	return (q.get_x() - p.get_x()) * (r.get_y() - p.get_y()) - 
           (q.get_y() - p.get_y()) * (r.get_x() - p.get_x());
}

// Idea: If a point lies on the same side of all edges of the triangle it
// is inside. If all cross products have the same sign, thats the case.
bool bsp(Point const a, Point const b, Point const c, Point const point) 
{
    Fixed o_ab = orientation(a, b, point);
    Fixed o_bc = orientation(b, c, point);
    Fixed o_ca = orientation(c, a, point);

    // all orientations are either counterclockwise or clockwise
    return (o_ab >= 0 && o_bc >= 0 && o_ca >= 0)
		   || (o_ab <= 0 && o_bc <= 0 && o_ca <= 0);
}

// -------------------------------------------------------------------------- //
