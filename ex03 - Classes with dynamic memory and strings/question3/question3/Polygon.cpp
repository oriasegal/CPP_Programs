#include <iostream>
#include "Point.h"
#include "Polygon.h"
#include <cmath>
using namespace std;
Polygon::Polygon(int num)
{
	numVertices = num;
	vertex = new Point[numVertices];
}
Polygon::Polygon(const Polygon& p) //copy constructor
{
	numVertices = p.numVertices;
	vertex = new Point[numVertices];  // Allocate the points in a dynamic array
	for (int i = 0; i < numVertices; i++)  // Now copy the points from the "old" array
		vertex[i] = p.vertex[i];
}
Polygon::~Polygon() //destructor
{
	delete[] vertex;
}
void Polygon::setPoint(Point point, int index)
{
	vertex[index] = point;
}
double Polygon::perimeter()
{
	int i;
	float sum = 0.0;
	for (i = 0; i < numVertices - 1; i++)
		sum += vertex[i].distance(vertex[i + 1]);
	sum += vertex[numVertices - 1].distance(vertex[0]); // Go from the last to the first
	return floor(sum + 0.5); // round to nearest whole number
}