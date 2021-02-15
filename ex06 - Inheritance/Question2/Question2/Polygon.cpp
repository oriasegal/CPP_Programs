#include<iostream>
#include"Polygon.h"
using namespace std;

Polygon::Polygon(int num) :numSides(num) //constructor
{
	sides = new int[num]; //builds an array for all the different sides
	if (num > 4) //if there are more then 4 sides
	{
		cout << "enter sides for polygon:\n";
		for (int i = 0; i < num; i++) //builds acording to the numbers entered
			cin >> sides[i];
	}
}
Polygon::Polygon(const Polygon& p) //copy constructor
{
	numSides = p.getnumSides(); //uses the constructor 
	sides = new int[numSides]; //builds a new array for the sides
	for (int i = 0; i < numSides; i++) //builds acording to the numbers entered
		sides[i] = p.getSides()[i];
}
Polygon::Polygon() //default constructor.
{
	sides = NULL;
	numSides = 0; //has no sides yet
}
int Polygon::getnumSides()const //returns the number of sides the polygon has
{
	return numSides;
}
int* Polygon::getSides()const //returns the array that has all the sides and the lengths of them
{
	return sides;
}
int Polygon::circumference() const //calculates the circumference of the polygon and returns it's value
{
	int sum = 0;
	for (int i = 0; i < numSides; i++)
		sum += sides[i]; //sums all the sides together
	return sum;
}
bool Polygon::operator==(const Polygon &p)const //returns true if the number of sides are equal and if the circumferences are equal, else- returns false
{
	return(numSides == p.getnumSides() && circumference() == p.circumference()); //checks if they are equal
}