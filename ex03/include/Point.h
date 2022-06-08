// Author: vcordeir <vcordeir@student.42sp.org.br>
// 42 SP

#ifndef POINT_H
# define POINT_H

# include "Fixed.h"

class Point
{
public:

    Point( void ); 
    Point( const float x, const float y );
    Point( const Point& prPoint );
    ~Point( void );

    Point& operator=( const Point& prPoint );

    void setX( Fixed x );
    void setY( Fixed y );

    Fixed getX( void ) const;
    Fixed getY( void ) const;

private:

    Fixed X;
    Fixed Y;

};

std::ostream& operator<<( std::ostream& os, const Point& prPoint );

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif
