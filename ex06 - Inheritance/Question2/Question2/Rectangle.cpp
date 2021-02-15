#include<iostream>
#include"Rectangle.h"
Rectangle::Rectangle(int side1, int side2) :Polygon(4) //constructor- it uses the polygon's constructor- gets two sides' arrays and makes a rectangle 
{
	sides[0] = side1;
	sides[1] = side2;
	sides[2] = side1;
	sides[3] = side2;

	//in a rectangle each pair of parallel side are equal
}