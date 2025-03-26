#include "Fixed.hpp"

int main( void )
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	return 0;
	}


/* int main() {
	Fixed a(42);
	Fixed b(42.42f);
	Fixed c(1234);
	Fixed d(1234.4321f);
	
	std::cout << "a: " << a << '\n';
	std::cout << "b: " << b << '\n';
	std::cout << "c: " << c << '\n';
	std::cout << "d: " << d << '\n';

	// Testing Comparison Operators
	std::cout << "\nComparison Operators:\n";
	std::cout << "(a > b): " << (a > b) << "\n";
	std::cout << "(a < b): " << (a < b) << "\n";
	std::cout << "(a >= b): " << (a >= b) << "\n";
	std::cout << "(a <= b): " << (a <= b) << "\n";
	std::cout << "(a == b): " << (a == b) << "\n";
	std::cout << "(a != b): " << (a != b) << "\n";
	
	// Testing Arithmetic Operators
	std::cout << "\nArithmetic Operators:\n";
	Fixed sum = a + b;
	Fixed diff = a - b;
	Fixed prod = a * b;
	Fixed quot = a / b;
	std::cout << "(a + b): " << sum << "\n";
	std::cout << "(a - b): " << diff << "\n";
	std::cout << "(a * b): " << prod << "\n";
	std::cout << "(a / b): " << quot << "\n";
	
	// Testing Increment/Decrement Operators
	std::cout << "\nIncrement/Decrement Operators:\n";
	Fixed e = a;
	std::cout << "Pre-increment: " << ++e << "\n";
	std::cout << "Post-increment: " << e++ << "\n";
	std::cout << "After Post-increment: " << e << "\n";
	
	Fixed f = a;
	std::cout << "Pre-decrement: " << --f << "\n";
	std::cout << "Post-decrement: " << f-- << "\n";
	std::cout << "After Post-decrement: " << f << "\n";
	
	// Testing Static min and max Functions
	std::cout << "\nStatic min and max Functions:\n";
	std::cout << "Min of a and b: " << Fixed::min(a, b) << "\n";
	std::cout << "Max of a and b: " << Fixed::max(a, b) << "\n";
	std::cout << "Min of c and d: " << Fixed::min(c, d) << "\n";
	std::cout << "Max of c and d: " << Fixed::max(c, d) << "\n";
	
	return 0;
} */