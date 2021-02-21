/*
Oria Segal
Exercise no. 3 question 3
This program calculates the perimeter of a polygon given by points.
*/
#include <iostream>
#include  <valarray>
#include <cmath> 
#include "Point.h"
#include "Polygon.h"
using namespace std;
bool checkAngle(Point first, Point second)
{
	float angle;
	angle = atan2((float)first.getY() - second.getY(), (float)first.getX() - second.getX());
	angle = floor(angle * 180 / 3.1415927);
	return angle;
}
int main()
{
	int numPoints;
	int i, x, y; 
	//cout << "Enter your shape:" << endl;
	cin >> numPoints;
	Polygon newPolygon(numPoints); // creates a new shape
	for (i = 0; i < numPoints; i++) 
	{
		cin >> x >> y;
		newPolygon.setPoint(Point(x, y), i); //puts all the points in the new polygon we created
	}

	float angle, prevAngle;
	bool sameAngle = true;
	for (i = 0; i < numPoints - 1; i++) //checkes that there were no identical points entered.
	{
		angle = checkAngle(newPolygon.vertex[i], newPolygon.vertex[i + 1]);
		if (i > 0 && sameAngle)
			sameAngle = (angle == prevAngle);
		prevAngle = angle;
	}

	angle = checkAngle(newPolygon.vertex[0], newPolygon.vertex[numPoints - 1]); //checks the first and last points entered
	if (sameAngle)
		sameAngle = (angle == prevAngle);

	if (sameAngle) //if what was inserted is incorrect
		cout << newPolygon.perimeter() << endl;
	else
		cout << "ERROR" << endl;
	//system("pause");
	return 0;
}
/*
4
0 0
0 2
2 2
2 0
8
Press any key to continue . . .
*/
