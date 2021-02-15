#pragma once
using namespace std;
class Point
{
public:
	int x;
	int y;
	
	Point() {}; //default constructor
	Point(int newX, int newY); //copy constructor

	void setX(int newX);
	int getX();
	void setY(int newY);
	int getY();
	float distance(Point point);
};