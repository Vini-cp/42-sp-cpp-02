// Author: vcordeir <vcordeir@student.42sp.org.br>
// 42 SP

#ifndef FIXED_H
#define FIXED_H

#include <iostream>
#include <cmath>

class Fixed
{
public:

    Fixed( void );
    Fixed( int const pNumber );
    Fixed( float const pNumber );
    Fixed( const Fixed& prFixedPoint );
    ~Fixed( void );

    Fixed& operator=( const Fixed& prFixedPoint );

    int getRawBits( void ) const;
    void setRawBits( int const pRawBits );

    float toFloat( void ) const;
    int toInt( void ) const;

private:

    int mRawBits;
    static const int msFractionalBits = 8;
};

std::ostream& operator<<( std::ostream& os, const Fixed& prFixedPoint );

#endif
