// Author: vcordeir <vcordeir@student.42sp.org.br>
// 42 SP

#include "../include/Point.h"
#include <cmath>

static float calculateTriangleArea( const Point& prPointA, const Point& prPointB, const Point& prPointC )
{
    float Area = ( prPointA.getX().toFloat() * ( prPointB.getY().toFloat() - prPointC.getY().toFloat() ) + \
                   prPointB.getX().toFloat() * ( prPointC.getY().toFloat() - prPointA.getY().toFloat() ) + \
                   prPointC.getX().toFloat() * ( prPointA.getY().toFloat() - prPointB.getY().toFloat() ) ) / 2;

    return std::abs( Area );
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
    float triangleArea = calculateTriangleArea( a, b, c );
    float A1 = calculateTriangleArea( point, a, b );
    float A2 = calculateTriangleArea( point, a, c );
    float A3 = calculateTriangleArea( point, b, c );

    if ( A1 == 0 || A2 == 0 || A3 == 0 ) return false;

    return ( A1 + A2 + A3 == triangleArea );
}
