#include<iostream>
#include"Triangle.h"
Triangle::Triangle(int side1, int side2, int side3) :Polygon(3) //constructor- it uses the polygon's constructor- gets three sides' arrays and makes a triangle
{
	sides[0] = side1;
	sides[1] = side2;
	sides[2] = side3;

	//in a triangle each side can have a different length.
}