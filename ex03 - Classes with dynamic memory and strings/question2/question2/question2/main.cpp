/*
Oria Segal
209338193
Homework no. 3 question 2
This program does different tasks with the vectors we enter acording to what case, what operator we choose to use.
*/
#include "Vector.h"
#include <iostream>
using namespace std;

enum options
{
	stop, assignment, isEqual, mult, add, clear, delLast
	//		0	1:=	   2:==	3:* 4:+ 5	6  
};

int main()
{
	Vector  v1(10), v2(10), v3;
	for (int i = 1; i <= 4; i++)
	{
		v1.insert(i);
		v2.insert(i + 4);
	}

	int choice, val;
	cout << "enter your choice 0-6\n";
	cin >> choice;

	while (choice)
	{
		switch (choice)
		{
		case assignment:
			v3 = v1;
			break;
		case isEqual:
			if (v1 == v2)
				cout << "v1==v2\n";
			else
				cout << "v1!=v2\n";
			break;
		case mult:
			cout << "v1*v2=" << v1 * v2 << endl;
			break;
		case add:
			v3 = v1 + v2;
			break;
		case clear:
			v1.clear();
			break;
		case delLast:
			v2.delLast();
			break;
		default: cout << "ERROR";
		}
		v1.print();
		v2.print();
		v3.print();
		cout << "enter your choice 0-6\n";
		cin >> choice;
	}

	//system("pause");
	return 0;
}

