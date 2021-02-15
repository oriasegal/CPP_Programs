#include <iostream>
#include <cmath>
#include "circle.h"
using namespace std;
void Circle::setX()
{
	cin >> x;
}
void Circle::setY()
{
	cin >> y;
}
int Circle::getX()
{
	return x;
}
int Circle::getY()
{
	return y;
}
void Circle::setRadius()
{
	cin >> radius;
}
int Circle::getRadius()
{
	return radius;
}
float Circle::area(int radius)
{
	float const pi = 3.14;
	return pow(radius, 2)*pi;
}
float Circle::circumference(int radius)
{
	float const pi = 3.14;
	return 2 * pi*radius;
}
int Circle::checksThePoint(int newX, int newY)
{
	int distance = pow((newX - x), 2) + pow((newY - y), 2);
	if (distance > pow(radius,2)) //the point is out of the circle
		return 1;
	if (distance == pow(radius,2)) //the point is on the circle
		return 0;
	if (distance < pow(radius,2)) //the point is in the circle
		return -1;
}
