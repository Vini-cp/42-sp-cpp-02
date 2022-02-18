/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 01:01:46 by coder             #+#    #+#             */
/*   Updated: 2022/02/18 01:53:16 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef FIXED_H
# define FIXED_H

# include <iostream>

class Fixed {

	private:

		int					_numberValue;
		static const int	_fractionalBits = 8;

	public:

		Fixed( void );
		Fixed( const Fixed &fxp );
		~Fixed( void );

		Fixed	&operator=( const Fixed &fxp );
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );

};

#endif
