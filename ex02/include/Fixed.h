// Author: vcordeir <vcordeir@student.42sp.org.br>
// 42 SP

#ifndef FIXED_H
# define FIXED_H

#include <iostream>

class Fixed
{
public:

    Fixed( void );
    Fixed( int const pNumber );
    Fixed( float const pNumber );
    Fixed( const Fixed& prFixedPoint );
    ~Fixed( void );

    Fixed& operator=( const Fixed& prFixedPoint );

    Fixed operator+( const Fixed& prFixedPoint );
    Fixed operator-( const Fixed& prFixedPoint );
    Fixed operator*( const Fixed& prFixedPoint );
    Fixed operator/( const Fixed& prFixedPoint );

    bool operator==( const Fixed& prFixedPoint );
    bool operator!=( const Fixed& prFixedPoint );
    bool operator<( const Fixed& prFixedPoint );
    bool operator<=( const Fixed& prFixedPoint );
    bool operator>( const Fixed& prFixedPoint );
    bool operator>=( const Fixed& prFixedPoint );

    Fixed& operator++( void );
    Fixed operator++( int );
    Fixed& operator--( void );
    Fixed operator--( int );

    static Fixed& max( Fixed& prFixedPoint1, Fixed& prFixedPoint2 );
    static const Fixed& max( const Fixed& prFixedPoint1, const Fixed& prFixedPoint2 );
    static Fixed& min( Fixed& prFixedPoint1, Fixed& prFixedPoint2 );
    static const Fixed& min( const Fixed& prFixedPoint1, const Fixed& prFixedPoint2 );

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
