#include "Point.hpp"

int	main()
{

	if (bsp( Point(1, 1), Point(4, 2), Point(3, 6), Point(3, 3)))
		std::cout << "Point is inside triangle\n";
	else
		std::cout << "Point outside/on edge/ is vertix\n";
	return(0);
}