#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point
{
private:
	const Fixed x;
	const Fixed y;
	Point& operator=(const Point&);
public:
	Point();
	Point(const float InitX, const float InitY);
	Point(const Point& point);
	~Point();
	Point operator-(const Point& coordinate) const;
	float getX() const;
	float getY() const;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);
float CrossProduct(const Point& p1, const Point& p2);

#endif