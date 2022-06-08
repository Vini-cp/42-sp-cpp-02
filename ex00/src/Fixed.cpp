// Author: vcordeir <vcordeir@student.42sp.org.br>
// 42 SP

#include "../include/Fixed.h"

//------------------------------------------------------------------------------

Fixed::Fixed( void ): mRawBits( 0 )
{
    std::cout << "Default constructor called" << std::endl;
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

int	Fixed::getRawBits( void ) const
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
