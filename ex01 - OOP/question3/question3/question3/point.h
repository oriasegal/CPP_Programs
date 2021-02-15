#pragma once
#include <iostream>
using namespace std;
class Point {
private:
	int x;
	int y;

public:
	int getX() const { return x; }
	int getY() const { return y; }
	void setX(int x);
	void setY(int y);
	Point(int X = 0, int Y = 0) {}; //default constructor
	//Point(int X, int Y) {};  //constructor
	void print(int x, int y);
};
//default constructor
//Point(int X = 0, int Y = 0);

//copy constructor
//   Point (const Point& p);