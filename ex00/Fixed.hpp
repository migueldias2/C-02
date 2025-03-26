#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
private:
	int m_FixedPoint;
	static const int m_FractionalBits;
public:
	Fixed();
	Fixed(const Fixed& copy);
	Fixed& operator=(const Fixed& other);
	~Fixed();
	int getRawBits( void ) const;
	void setRawBits( int const raw );
};

#endif