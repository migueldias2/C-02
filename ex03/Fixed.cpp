#include "Fixed.hpp"

const int Fixed::m_FractionalBits = 8;

Fixed::Fixed(): m_FixedPoint(0) {}

Fixed::Fixed(const int point):m_FixedPoint(point * 1 << m_FractionalBits){}

Fixed::Fixed(const float point):m_FixedPoint(roundf(point * (1 << m_FractionalBits))){}

Fixed::Fixed(const Fixed& copy):m_FixedPoint(copy.getRawBits()){}

Fixed& Fixed::operator=(const Fixed& other) 
{
	if (this == &other)
		return *this;
	m_FixedPoint = other.getRawBits();
	return *this;
}
Fixed::~Fixed(){}

int Fixed::getRawBits( void ) const {return m_FixedPoint;}

void Fixed::setRawBits( int const raw ) {m_FixedPoint = raw;}

float Fixed::toFloat( void ) const {return (float)(m_FixedPoint) / (1 << m_FractionalBits);}

int Fixed::toInt( void ) const {return m_FixedPoint >> m_FractionalBits;}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed)
{
	out << fixed.toFloat();
	//out << std::fixed << std::setprecision(6) << fixed.toFloat();
	return out;
}

//ex02

bool Fixed::operator>(const Fixed& fixed){return (m_FixedPoint > fixed.m_FixedPoint);}
bool Fixed::operator>=(const Fixed& fixed){return (m_FixedPoint >= fixed.m_FixedPoint);}
bool Fixed::operator<(const Fixed& fixed) {return (m_FixedPoint < fixed.m_FixedPoint);}
bool Fixed::operator<=(const Fixed& fixed){return (m_FixedPoint <= fixed.m_FixedPoint);}
bool Fixed::operator==(const Fixed& fixed){return (m_FixedPoint == fixed.m_FixedPoint);}
bool Fixed::operator!=(const Fixed& fixed){return (m_FixedPoint != fixed.m_FixedPoint);}

Fixed Fixed::operator+(const Fixed& fixed){return Fixed(this->toFloat() + fixed.toFloat());}
Fixed Fixed::operator-(const Fixed& fixed) const {return Fixed(this->toFloat() - fixed.toFloat());}
Fixed Fixed::operator*(const Fixed& fixed){return Fixed(this->toFloat() * fixed.toFloat());}
Fixed Fixed::operator/(const Fixed& fixed)
{
	if (fixed.m_FixedPoint == 0)
	{
		std::cerr << "Division by 0\n";
		return Fixed();
	}
	return Fixed(this->toFloat() / fixed.toFloat());
}
Fixed& Fixed::operator++()
{
	++m_FixedPoint;
	return *this;
}
Fixed& Fixed::operator--()
{
	--m_FixedPoint;
	return *this;
}
Fixed  Fixed::operator++(int)
{
	Fixed temp(*this);
	++m_FixedPoint;
	return temp;
}
Fixed  Fixed::operator--(int)
{
	Fixed temp(*this);
	--m_FixedPoint;
	return temp;
}

Fixed& Fixed::min(Fixed& p1, Fixed& p2){return p1.m_FixedPoint > p2.m_FixedPoint ? p2 : p1;}
const Fixed& Fixed::min(const Fixed& p1, const Fixed& p2){return p1.m_FixedPoint > p2.m_FixedPoint ? p2 : p1;}
Fixed& Fixed::max(Fixed& p1, Fixed& p2){return p1.m_FixedPoint > p2.m_FixedPoint ? p1 : p2;}
const Fixed& Fixed::max(const Fixed& p1, const Fixed& p2){return p1.m_FixedPoint > p2.m_FixedPoint ? p1 : p2;}