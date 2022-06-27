// Author: vcordeir <vcordeir@student.42sp.org.br>
// 42 SP

#include "../include/Fixed.h"
#include <cmath>

//------------------------------------------------------------------------------

Fixed::Fixed( void ) : mRawBits( 0 )
{
    std::cout << "Default constructor called" << std::endl;
}

//------------------------------------------------------------------------------

Fixed::Fixed( int const pNumber )
{
    std::cout << "Int constructor called" << std::endl;
    mRawBits = pNumber << msFractionalBits;
}

//------------------------------------------------------------------------------

Fixed::Fixed( float const pNumber )
{
    std::cout << "Float constructor called" << std::endl;
    mRawBits = roundf( pNumber * ( 1 << msFractionalBits ) );
}

//------------------------------------------------------------------------------

Fixed::Fixed( const Fixed& prFixedPoint )
{
    std::cout << "Copy constructor called" << std::endl;
    *this = prFixedPoint;
}

//------------------------------------------------------------------------------

Fixed::~Fixed( void )
{
    std::cout << "Destructor called" << std::endl;
}

//------------------------------------------------------------------------------

Fixed& Fixed::operator=( const Fixed& prFixedPoint )
{
    std::cout << "Copy assignment operator called" << std::endl;

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
    std::cout << "getRawBits member function called" << std::endl;
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
