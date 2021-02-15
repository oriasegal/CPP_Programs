/*
Oria Segal
209338193
Homework no. 6 question 1
This program is using the List program I made befor and by inheritance it can use some of it's functions and valuses.
*/
#include "RoundList.h"
#include <iostream>
using namespace std;

enum CHOICES
{
	EXIT, ADD, ADD_TO_END, REMOVE_FIRST, SEARCH, CLEAR, EMPTY
};
int main()
{

	RoundList ls1;
	int choice;
	cout << "Enter your choice: ";
	cin >> choice;
	while (choice != EXIT)
	{
		int num;
		try {
			switch (choice)
			{
			case ADD:
				cout << "Enter 5 numbers: ";
				for (int i = 0; i < 5; i++)
				{
					cin >> num;
					ls1.add(num);
				}
				break;

			case ADD_TO_END:
				cout << "Enter 5 numbers: ";
				for (int i = 0; i < 5; i++)
				{
					cin >> num;
					ls1.addToEnd(num);
				}
				break;

			case REMOVE_FIRST:
				ls1.removeFirst();
				break;

			case SEARCH: cout << "Enter a number: ";
				cin >> num;
				cout << ls1.search(num) << endl;
				break;
			case CLEAR:
				ls1.clear();
				break;

			case EMPTY:
				if (ls1.isEmpty())
					cout << "Empty" << endl;
				else
					cout << "Not empty" << endl;
				break;

			default:
				cout << "ERROR!" << endl;
			}
		}

		catch (char *str)
		{
			cout << str << endl;
		}
		cout << "Enter your choice: ";
		cin >> choice;
	}
	//system("pause");
	return 0;
}
