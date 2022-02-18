/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 01:25:12 by coder             #+#    #+#             */
/*   Updated: 2022/02/18 01:58:25 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Fixed.hpp"

Fixed::Fixed( void ): _numberValue(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( const Fixed &fxp )
{
	std::cout << "Copy constructor called" << std::endl;
	_numberValue = fxp.getRawBits();
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
	_numberValue = fxp.getRawBits();
	return (*this);
}

int		Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (_numberValue);
}

void	Fixed::setRawBits( int const raw )
{
	_numberValue = raw;
}
