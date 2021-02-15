/*
Oria Segal
209338193
Homework no. 1 question 3
This program prints out the circles' and area and also tells us if the piont we entered is on, in or out of one of the circles.
*/
#include <iostream>
#include "circle.h"
using namespace std;
int main()
{
	Circle A, B, C, D;
	char ch;
	cout << "enter the center point and radius of 3 circles" << endl;
	A.setX();
	A.setY();
	A.setRadius();
	B.setX();
	B.setY();
	B.setRadius();
	C.setX();
	C.setY();
	C.setRadius();

	int rA = A.getRadius(), rB = B.getRadius(), rC = C.getRadius();
	cout << "area A: " << A.area(rA)<< " " << "B: " << B.area(rB) << " " << "C: " << C.area(rC) << endl; //prints out all the 3 circles' areas
	cout << "hekef A: " << A.circumference(rA) << " " << "B: " << B.circumference(rB) << " " << "C: " << C.circumference(rC) << endl; //prints out all the 3 circles' circumferences

	int x, y;
	D.setX();
	D.setY();
	x = D.getX();
	y = D.getY();

	int countA = 0, countB = 0, countC = 0;
	while (x!=0 || y!=0) //only while this isn't the point (0,0)
	{
		if (A.checksThePoint(x,y) == 0 || A.checksThePoint(x,y) == -1)
			countA++;
		if (B.checksThePoint(x,y) == 0 || B.checksThePoint(x,y) == -1)
			countB++;
		if (C.checksThePoint(x,y) == 0 || C.checksThePoint(x,y) == -1)
			countC++;
		
		D.setX();
		D.setY();
		x = D.getX();
		y = D.getY();
	}
	cout << "num of points in circle A:" << countA << " B:" << countB << " C:" << countC << endl;

	//system("pause");
	return 0;
}