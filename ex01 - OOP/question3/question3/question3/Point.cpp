#include <iostream>
#include "point.h"
using namespace std;

void Point::setX()
{
	cin >> x;
}
void Point::setY(int y)
{
	cin >> y;
}
/*Point::Point(int X, int Y)
{
	x = X;
	y = Y;
}*/
void Point::print(int x, int y)
{
	cout << x << " " << y << endl;
}