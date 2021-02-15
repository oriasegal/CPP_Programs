#pragma once
using namespace std;
class Circle {
private:
	int radius;
	int x;
	int y;
public:
	void setX();
	int getX();
	void setY();
	int getY();
	void setRadius();
	int getRadius();

	float area(int radius);
	float circumference(int radius);

	int checksThePoint(int x, int y);

};


