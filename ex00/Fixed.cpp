#include "Fixed.hpp"


const int Fixed::m_FractionalBits = 8;

Fixed::Fixed(): m_FixedPoint(0) {std::cout << "Default constructor called\n";}

Fixed::Fixed(const Fixed& copy): m_FixedPoint(copy.getRawBits())
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

int Fixed::getRawBits( void ) const 
{
	std::cout << "getRawBits member function called\n";
	return m_FixedPoint;
}

void Fixed::setRawBits( int const raw ) {m_FixedPoint = raw;}