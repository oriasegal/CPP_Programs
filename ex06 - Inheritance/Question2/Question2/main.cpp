/*
Oria Segal
Exercise no. 6 question 2
This program builds polygons, checks if they are triangles or rectangles and can also check if they are equal by side's numbers or length.
*/
#include<iostream>
#include"Polygon.h"
#include"Rectangle.h"
#include"Triangle.h"
using namespace std;

int main()
{
	int sides, side1, side2, side3;
	cout << "enter number of sides for polygon 1:\n";
	cin >> sides;
	Polygon p1(sides);
	if (sides <= 4)
	{
		cout << "enter sides for polygon:\n";
		if (sides == 3) //if it's a triangle it will send the values to the Triangle's constructor
		{
			cin >> side1 >> side2 >> side3;
			Triangle t1(side1, side2, side3);
			p1 = t1;
		}
		if (sides == 4) //if it's a rectangle it will send the values to the Rectangle's constructor
		{
			cin >> side1 >> side2;
			Rectangle r1(side1, side2);
			p1 = r1;
		}

	}
	cout << "enter number of sides for polygon 2:\n";
	try {
		cin >> sides;
		if (sides != p1.getnumSides()) //will check if they are equal. if not will print out the next text
			throw "not equal\n";
		Polygon p2(sides); //builds a polygon
		if (sides <= 4) //if there are 4 or less sides to the polygon
		{
			cout << "enter sides for polygon:\n";
			if (sides == 3) //if it's a triangle it will send the values to the Triangle's constructor
			{
				cin >> side1 >> side2 >> side3;
				Triangle t1(side1, side2, side3);
				p2 = t1;
			}
			if (sides == 4) //if it's a rectangle it will send the values to the Rectangle's constructor
			{
				cin >> side1 >> side2;
				Rectangle r1(side1, side2);
				p2 = r1;
			}

		}
		if (p1 == p2) //checks if they are equal
			throw "equal\n";
		else
			throw "not equal\n";
	}

	catch (const char *str)
	{
		cout << str; //prints out the texts, if were sent any
	}
	//system("pause");
	return 0;
}
