#pragma once
#include<iostream>
using namespace std;
class Polygon
{
protected:
	int numSides;
	int *sides;

public:
	Polygon(); //defualt constructor
	Polygon(int); //constructor- gets the number of sides
	Polygon(const Polygon&); //copy constructor

	int getnumSides()const; //gets the number of sides the polygon has
	int* getSides()const; //builds an array of all the sides' lengths
	int circumference() const; //calculates the circumference of the polygon
	bool operator==(const Polygon &p)const; //the function returns if they are equal or not
};
