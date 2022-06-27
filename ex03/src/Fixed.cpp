// Author: vcordeir <vcordeir@student.42sp.org.br>
// 42 SP

#include "../include/Fixed.h"
#include <cmath>

//------------------------------------------------------------------------------

Fixed::Fixed( void ): mRawBits( 0 )
{
}

//------------------------------------------------------------------------------

Fixed::Fixed( int const pNumber )
{
    mRawBits = pNumber << msFractionalBits;
}

//------------------------------------------------------------------------------

Fixed::Fixed( float const pNumber )
{
    mRawBits = roundf( pNumber * ( 1 << msFractionalBits ) );
}

//------------------------------------------------------------------------------

Fixed::Fixed( const Fixed& prFixedPoint )
{
    *this = prFixedPoint;
}

//------------------------------------------------------------------------------

Fixed::~Fixed( void )
{
}

//------------------------------------------------------------------------------

Fixed& Fixed::operator=( const Fixed& prFixedPoint )
{

    if ( this == &prFixedPoint ) return *this;

    mRawBits = prFixedPoint.getRawBits();

    return *this;
}

//------------------------------------------------------------------------------

Fixed Fixed::operator+( const Fixed& prFixedPoint )
{
    Fixed lNewFixed;
    lNewFixed.setRawBits( mRawBits + prFixedPoint.getRawBits() );
    
    return lNewFixed;
}

//------------------------------------------------------------------------------

Fixed Fixed::operator-( const Fixed& prFixedPoint )
{
    Fixed lNewFixed;
    lNewFixed.setRawBits( mRawBits - prFixedPoint.getRawBits() );

    return lNewFixed;
}

//------------------------------------------------------------------------------

Fixed Fixed::operator*( const Fixed& prFixedPoint )
{
    Fixed lNewFixed;
    lNewFixed.setRawBits( ( mRawBits * prFixedPoint.getRawBits() ) >> msFractionalBits );

    return lNewFixed;
}

//------------------------------------------------------------------------------

Fixed Fixed::operator/( const Fixed& prFixedPoint )
{
    Fixed lNewFixed;
    lNewFixed.setRawBits( ( mRawBits / prFixedPoint.getRawBits() ) << msFractionalBits );
    
    return lNewFixed;
}

//------------------------------------------------------------------------------

bool Fixed::operator==( const Fixed& prFixedPoint )
{
    return ( mRawBits == prFixedPoint.getRawBits() );
}

//------------------------------------------------------------------------------

bool Fixed::operator<=( const Fixed& prFixedPoint )
{
    return ( mRawBits <= prFixedPoint.getRawBits() );
}

//------------------------------------------------------------------------------

bool Fixed::operator>=( const Fixed& prFixedPoint )
{
    return ( mRawBits >= prFixedPoint.getRawBits() );
}

//------------------------------------------------------------------------------

bool Fixed::operator<( const Fixed& prFixedPoint )
{
    return ( mRawBits < prFixedPoint.getRawBits() );
}

//------------------------------------------------------------------------------

bool Fixed::operator>( const Fixed& prFixedPoint )
{
    return ( mRawBits > prFixedPoint.getRawBits() );
}

//------------------------------------------------------------------------------

bool Fixed::operator!=( const Fixed& prFixedPoint )
{
    return ( mRawBits != prFixedPoint.getRawBits() );
}

//------------------------------------------------------------------------------

Fixed& Fixed::operator++( void )
{
    setRawBits( mRawBits + 1 );
    return *this;
}

//------------------------------------------------------------------------------

Fixed Fixed::operator++( int )
{
    Fixed lNewFixed( *this );
    setRawBits( mRawBits + 1 );

    return lNewFixed;
}

//------------------------------------------------------------------------------

Fixed& Fixed::operator--( void )
{
    setRawBits( mRawBits - 1 );
    return *this;
}

//------------------------------------------------------------------------------

Fixed Fixed::operator--( int )
{
    Fixed lNewFixed( *this );
    setRawBits( mRawBits - 1 );

    return lNewFixed;
}

//------------------------------------------------------------------------------

Fixed& Fixed::max( Fixed& prFixedPoint1, Fixed& prFixedPoint2 )
{
    if ( prFixedPoint1 >= prFixedPoint2 ) return prFixedPoint1;

    return prFixedPoint2;
}

//------------------------------------------------------------------------------

const Fixed& Fixed::max( const Fixed& prFixedPoint1, const Fixed& prFixedPoint2 )
{
    if ( prFixedPoint1.getRawBits() >= prFixedPoint2.getRawBits() ) return prFixedPoint1;

    return prFixedPoint2;
}

//------------------------------------------------------------------------------

Fixed& Fixed::min( Fixed& prFixedPoint1, Fixed& prFixedPoint2 )
{
    if ( prFixedPoint1 <= prFixedPoint2 ) return prFixedPoint1;

    return prFixedPoint2;
}

//------------------------------------------------------------------------------

const Fixed& Fixed::min( const Fixed& prFixedPoint1, const Fixed& prFixedPoint2 )
{
    if ( prFixedPoint1.getRawBits() <= prFixedPoint2.getRawBits() ) return prFixedPoint1;

    return prFixedPoint2;
}

//------------------------------------------------------------------------------

int Fixed::getRawBits( void ) const
{
    return mRawBits;
}

//------------------------------------------------------------------------------

void Fixed::setRawBits( int const pRawBits )
{
    mRawBits = pRawBits;
}

//------------------------------------------------------------------------------

float Fixed::toFloat( void ) const
{
    return ( (float) mRawBits / ( 1 << msFractionalBits ) );
}

//------------------------------------------------------------------------------

int Fixed::toInt( void ) const
{
    return ( mRawBits >> msFractionalBits );
}

//------------------------------------------------------------------------------

std::ostream& operator<<( std::ostream& os, const Fixed& prFixedPoint )
{
    os << prFixedPoint.toFloat();
    return os;
}

//------------------------------------------------------------------------------
