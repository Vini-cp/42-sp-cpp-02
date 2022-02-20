/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 01:25:12 by coder             #+#    #+#             */
/*   Updated: 2022/02/20 16:04:56 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Fixed.hpp"

Fixed::Fixed( void ): _rawBits(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( int const intNumber )
{
	std::cout << "Int constructor called" << std::endl;
	_rawBits = intNumber << _fractionalBits;
}

Fixed::Fixed( float const floatNumber )
{
	std::cout << "Float constructor called" << std::endl;
	_rawBits = roundf(floatNumber * (1 << _fractionalBits));
}
	
Fixed::Fixed( const Fixed &fxp )
{
	std::cout << "Copy constructor called" << std::endl;
	_rawBits = fxp.getRawBits();
}

Fixed::~Fixed( void )
{
	std::cout << "Destructor called" << std::endl;
}

Fixed	&Fixed::operator=( const Fixed &fxp )
{
	std::cout << "Copy assignment operator called " << std::endl;
	if(this == &fxp)
		return (*this);
	_rawBits = fxp.getRawBits();
	return (*this);
}

Fixed	Fixed::operator+( const Fixed &fxp )
{
	Fixed newFixed;
	newFixed.setRawBits(this->getRawBits() + fxp.getRawBits());
	return (newFixed);
}

Fixed	Fixed::operator-( const Fixed &fxp )
{
	Fixed newFixed;
	newFixed.setRawBits(this->getRawBits() - fxp.getRawBits());
	return (newFixed);
}

Fixed	Fixed::operator*( const Fixed &fxp )
{
	Fixed newFixed;
	newFixed.setRawBits((this->getRawBits() * fxp.getRawBits()) >> _fractionalBits);
	return (newFixed);
}

Fixed	Fixed::operator/( const Fixed &fxp )
{
	Fixed newFixed;
	newFixed.setRawBits((this->getRawBits() / fxp.getRawBits()) << _fractionalBits);
	return (newFixed);
}

bool	Fixed::operator==( const Fixed &fxp )
{
	return (this->getRawBits() == fxp.getRawBits());
}

bool	Fixed::operator<=( const Fixed &fxp )
{
	return (this->getRawBits() <= fxp.getRawBits());
}

bool	Fixed::operator>=( const Fixed &fxp )
{
	return (this->getRawBits() >= fxp.getRawBits());
}

bool	Fixed::operator<( const Fixed &fxp )
{
	return (this->getRawBits() < fxp.getRawBits());
}

bool	Fixed::operator>( const Fixed &fxp )
{
	return (this->getRawBits() > fxp.getRawBits());
}

bool	Fixed::operator!=( const Fixed &fxp )
{
	return (this->getRawBits() != fxp.getRawBits());
}

Fixed&	Fixed::operator++( void )
{
	this->setRawBits(this->getRawBits() + 1);
	return (*this);
}

Fixed	Fixed::operator++( int )
{
	Fixed newFixed(*this);
	this->setRawBits(this->getRawBits() + 1);
	return (newFixed);
}

Fixed&	Fixed::operator--( void )
{
	this->setRawBits(this->getRawBits() - 1);
	return (*this);
}

Fixed	Fixed::operator--( int )
{
	Fixed newFixed(*this);
	this->setRawBits(this->getRawBits() - 1);
	return (newFixed);
}

Fixed&	Fixed::max( Fixed &f1, Fixed &f2 )
{
	if (f1 >= f2)
		return (f1);
	return (f2);
}

const Fixed&	Fixed::max( const Fixed &f1, const Fixed &f2 )
{
	if (f1.getRawBits() >= f2.getRawBits())
		return (f1);
	return (f2);
}

Fixed&	Fixed::min( Fixed &f1, Fixed &f2 )
{
	if (f1 <= f2)
		return (f1);
	return (f2);
}

const Fixed&	Fixed::min( const Fixed &f1, const Fixed &f2 )
{
	if (f1.getRawBits() <= f2.getRawBits())
		return (f1);
	return (f2);
}

std::ostream	&operator<<( std::ostream &os, const Fixed &fxp )
{
	os << fxp.toFloat();
	return (os);
}

int		Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (_rawBits);
}

void	Fixed::setRawBits( int const raw )
{
	_rawBits = raw;
}

float	Fixed::toFloat( void ) const
{
	return ((float) _rawBits / (1 << _fractionalBits));
}

int		Fixed::toInt( void ) const
{
	return (_rawBits >> _fractionalBits);
}
