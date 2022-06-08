// Author: vcordeir <vcordeir@student.42sp.org.br>
// 42 SP

#ifndef FIXED_H
# define FIXED_H

# include <iostream>

class Fixed
{
public:

    Fixed( void );
    Fixed( const Fixed& prFixedPoint );
    ~Fixed( void );

    Fixed &operator=( const Fixed& prFixedPoint );

    int getRawBits( void ) const;
    void setRawBits( int const pRawBits );

private:

    int mRawBits;
    static const int msFractionalBits = 8;
};

#endif
