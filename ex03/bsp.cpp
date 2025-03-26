#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	Point AB(b-a);
	Point Apoint(point-a); 
	float cp1 = CrossProduct(AB, Apoint);
	if (cp1 == 0) return false;

	Point BC(c-b);
	Point Bpoint(point-b);
	float cp2 = CrossProduct(BC, Bpoint);
	if (cp2 == 0) return false;

	Point CA(a-c);
	Point Cpoint(point-c);
	float cp3 = CrossProduct(CA, Cpoint);
	if (cp3 == 0) return false;

	if ((cp1 > 0 && cp2 > 0 && cp3 > 0) || (cp1 < 0 && cp2 < 0 && cp3 < 0))
		return true;
	return false;
}