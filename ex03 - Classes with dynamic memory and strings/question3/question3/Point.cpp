#include <iostream>
#include "Point.h"
#include <cmath>
using namespace std;
Point::Point(int newX, int newY)
{
	x = newX;
	y = newY;
}
void Point::setX(int newX)
{
	x = newX;
}
int Point::getX()
{
	return x;
}
void Point::setY(int newY)
{
	y = newY;
}
int Point::getY()
{
	return y;
}
float Point::distance(Point point)
{
	int xd =  x - point.getX();
	int yd = y - point.getY();
	float distance = sqrt((float)(pow(xd,2) + pow(yd,2)));
	return distance;
}