#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <iomanip>
#include <cmath>

class Fixed
{
private:
	int m_FixedPoint;
	static const int m_FractionalBits;
public:
	Fixed();
	Fixed(const int point);
	Fixed(const float point);
	Fixed(const Fixed& copy);
	Fixed& operator=(const Fixed& other);
	~Fixed();
	int getRawBits( void ) const;
	void setRawBits( int const raw );
	float toFloat( void ) const;
	int toInt( void ) const;
};

std::ostream& operator<<(std::ostream& out, const Fixed& fixed);

#endif