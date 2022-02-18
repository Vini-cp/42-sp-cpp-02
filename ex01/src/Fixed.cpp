/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 01:25:12 by coder             #+#    #+#             */
/*   Updated: 2022/02/18 16:49:50 by coder            ###   ########.fr       */
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
