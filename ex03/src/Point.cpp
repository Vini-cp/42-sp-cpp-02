// Author: vcordeir <vcordeir@student.42sp.org.br>
// 42 SP

#include "../include/Point.h"

//------------------------------------------------------------------------------

Point::Point( void ): X( 0 ), Y( 0 )
{
}

//------------------------------------------------------------------------------

Point::Point( const float x, const float y ): X( x ), Y( y )
{
}

//------------------------------------------------------------------------------

Point::Point( const Point& prPoint )
{
    *this = prPoint;
}

//------------------------------------------------------------------------------

Point::~Point( void )
{
}

//------------------------------------------------------------------------------

Point& Point::operator=( const Point& prPoint )
{

    if ( this == &prPoint ) return *this;

    X = prPoint.getX();
    Y = prPoint.getY();
    return *this;
}

//------------------------------------------------------------------------------

void Point::setX( Fixed x )
{
    X = x;
}

//------------------------------------------------------------------------------

void Point::setY( Fixed y )
{
    Y = y;
}

//------------------------------------------------------------------------------

Fixed Point::getX( void ) const
{
    return X;
}

//------------------------------------------------------------------------------

Fixed Point::getY( void ) const
{
    return Y;
}

//------------------------------------------------------------------------------

std::ostream& operator<<( std::ostream& os, const Point& prPoint )
{
    os << "( " << prPoint.getX() << ", " << prPoint.getY() << " )";
    return os;
}

//------------------------------------------------------------------------------