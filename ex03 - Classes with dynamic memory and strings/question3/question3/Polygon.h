#pragma once
#include "Point.h"
using namespace std;
class Polygon
{
public:
	Point *vertex;
	int numVertices;

	Polygon(int num); //default constructor
	Polygon(const Polygon& p); //copy constructor
	~Polygon(); //destructor

	void setPoint(Point point, int index);
	double perimeter();
};
