#include "Fixed.hpp"

const int Fixed::m_FractionalBits = 8;

Fixed::Fixed(): m_FixedPoint(0) {std::cout << "Default constructor called\n";}

Fixed::Fixed(const int point): m_FixedPoint(point * 1 << m_FractionalBits)
{
	std::cout << "Int constructor called\n";
}

Fixed::Fixed(const float point): m_FixedPoint(roundf(point * (1 << m_FractionalBits)))
{
	std::cout << "Float constructor called\n";
}

Fixed::Fixed(const Fixed& copy):m_FixedPoint(copy.getRawBits())
{
	std::cout << "Copy constructor called\n";
}

Fixed& Fixed::operator=(const Fixed& other) 
{
	std::cout << "Copy assignment operator called\n";
	if (this == &other)
		return *this;
	m_FixedPoint = other.getRawBits();
	return *this;
}
Fixed::~Fixed(){std::cout << "Destructor called\n";}

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