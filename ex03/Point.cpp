#include "Point.hpp"

Point::Point(): x(Fixed(0)), y(Fixed(0)){}
Point::Point(const float InitX, const float InitY): x(Fixed(InitX)), y(Fixed(InitY)){}
Point::Point(const Point& point): x(point.x), y(point.y){}
Point& Point::operator=(const Point&){return *this;}
Point::~Point(){}

Point Point::operator-(const Point& coordinate) const
{
	Fixed res_x = x - coordinate.x;
	Fixed res_y = y - coordinate.y;

	return Point(res_x.toFloat(), res_y.toFloat());
}

float Point::getX() const {return x.toFloat();}
float Point::getY() const {return y.toFloat();}

float CrossProduct(const Point& p1, const Point& p2)
{
	return (p1.getX() * p2.getY() - p1.getY() * p2.getX());
}