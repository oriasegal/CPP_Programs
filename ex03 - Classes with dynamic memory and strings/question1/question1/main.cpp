/*
Oria Segal
Exercise no. 3 question 1
This program combines two strings into one using an inserted number.
*/
#include<cstring>
#include<string>
#pragma warning (disable:4996)
#include "String.h"
#include<iostream>
using namespace std;

int main()
{
	char c1[20], c2[20];
	int  position;

	cin >> c1 >> c2 >> position;

	String a(c1), b(c2);
	if (a > b)
		cout << "a>b\n";
	else 
		if (a < b)
			cout << "a<b\n";
		else
			cout << "a=b\n";

	if (position < 0) 
	{
		cout << "ERROR" << endl;
		return 0;
	}
	else
	{
		b.insert(position, a.getString());
		b.print();
		cout << endl;
	}

	//system("pause");
	return 0;
}
/*
World
Hello
5
a > b
HelloWorld
Press any key to continue . . .
*/
