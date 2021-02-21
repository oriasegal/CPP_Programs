/*
Oria Segal
Exercise no. 2 question 2
This program sets different dates acording to what operators we are using.
*/
#include "Date.h"
#include <iostream>
using namespace std;
void printAns(int ans)
{
	if (ans == 0)
		cout << "false";
	else
		cout << "true";
}
int main()
{
	int day, month, year, choice, num;
	char slash;
	Date date, date1, date2, date3;
	bool ans, ans2, ans3;

	cout << "Enter a date" << endl;
	cin >> day >> slash >> month >> slash >> year;
	date.setDate(day, month, year);
	date.print();
	do {
		cout << "What do you want to do" << endl;
		cin >> choice;

		switch (choice)
		{
		case 1: //set date
			cout << "Enter a date" << endl;
			cin >> day >> slash >> month >> slash >> year;
			date.setDate(day, month, year);
			date.print();
			break;
		case 2: //++date
			(++date).print();
			break;
		case 3: //date++
			(date++).print();
			break;
		case 4: //+=
			cout << "Enter #days" << endl;
			cin >> num;
			(date += num).print();
			break;
		case 5: //>
			cout << "Enter a date" << endl;
			cin >> day >> slash >> month >> slash >> year;
			date1.setDate(day, month, year);
			ans = (date > date1);
			cout << ">:";
			printAns(ans);
			cout << endl;
			break;
		case 6: //<
			cout << "Enter a date" << endl;
			cin >> day >> slash >> month >> slash >> year;
			date2.setDate(day, month, year);
			ans2 = (date < date2);
			cout << "<:";
			printAns(ans2);
			cout << endl;
			break;
		case 7: //==
			cout << "Enter a date" << endl;
			cin >> day >> slash >> month >> slash >> year;
			date3.setDate(day, month, year);
			ans3 = (date == date3);
			cout << "==:";
			printAns(ans3);
			cout << endl;
			break;
		case -1: //exit
			break;
		}
	} while (choice != (-1));
	//system("pause");
	return 0;
}
/*
Enter a date
- 5 / 1 / 2012
Error day
1 / 1 / 2012
What do you want to do
1
Enter a date
5 / 7 / 2010
5 / 7 / 2010
What do you want to do
2
6 / 7 / 2010
What do you want to do
3
6 / 7 / 2010
What do you want to do
4
Enter #days
7
14 / 7 / 2010
What do you want to do
5
Enter a date
14 / 7 / 2010
> :0
What do you want to do
7
Enter a date
14 / 7 / 2010
== : 1
What do you want to do
- 1
Press any key to continue . . .
*/
