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

	bool operator>(const Fixed& fixed) const;
	bool operator>=(const Fixed& fixed)const;
	bool operator<(const Fixed& fixed)const;
	bool operator<=(const Fixed& fixed)const;
	bool operator==(const Fixed& fixed)const;
	bool operator!=(const Fixed& fixed)const;

	Fixed operator+(const Fixed& fixed)const;
	Fixed operator-(const Fixed& fixed)const;
	Fixed operator*(const Fixed& fixed)const;
	Fixed operator/(const Fixed& fixed)const;

	Fixed& operator++();
	Fixed& operator--();
	Fixed operator++(int);
	Fixed operator--(int);

	static Fixed& min(Fixed& p1, Fixed& p2);
	const static Fixed& min(const Fixed& p1, const Fixed& p2);
	static Fixed& max(Fixed& p1, Fixed& p2);
	const static Fixed& max(const Fixed& p1, const Fixed& p2);
};

std::ostream& operator<<(std::ostream& out, const Fixed& fixed);

#endif