/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 01:01:46 by coder             #+#    #+#             */
/*   Updated: 2022/02/20 15:57:31 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef FIXED_H
# define FIXED_H

# include <iostream>
# include <cmath>

class Fixed {

	private:

		int					_rawBits;
		static const int	_fractionalBits = 8;

	public:

		Fixed( void );
		Fixed( int const intNumber );
		Fixed( float const floatNumber );
		Fixed( const Fixed &fxp );
		~Fixed( void );

		Fixed	&operator=( const Fixed &fxp );
		Fixed	operator+( const Fixed &fxp );
		Fixed	operator-( const Fixed &fxp );
		Fixed	operator*( const Fixed &fxp );
		Fixed	operator/( const Fixed &fxp );

		bool	operator==( const Fixed &fxp );
		bool	operator<=( const Fixed &fxp );
		bool	operator>=( const Fixed &fxp );
		bool	operator<( const Fixed &fxp );
		bool	operator>( const Fixed &fxp );
		bool	operator!=( const Fixed &fxp );

		Fixed&	operator++( void );
		Fixed	operator++( int );
		Fixed&	operator--( void );
		Fixed	operator--( int );

		static Fixed& 		max( Fixed &f1, Fixed &f2 );
		static const Fixed&	max( const Fixed &f1, const Fixed &f2 );
		static Fixed&		min( Fixed &f1, Fixed &f2 );
		static const Fixed&	min( const Fixed &f1, const Fixed &f2 );

		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
		float	toFloat( void ) const;
		int		toInt( void ) const;

};

std::ostream	&operator<<(std::ostream &os, const Fixed &fxp);

#endif
