/*
Oria Segal
209338193
Homework no. 1 question 2
This program gets a list of all the workers' info and tels us who has the highest salary and who worked the most hours.
*/
#include "employee.h"
#include <cstring>
using namespace std;
int main()
{
	Employee listOfEmployees[50], *pEmployee;
	int id, workHours, extraHours, numOfEmployees = 0, i, j, k;
	char name[21];
	float paymentPerHour;
	cout << "enter details, to end enter 0" << endl;
	cin >> id;
	pEmployee = listOfEmployees; // points to the first employee

	while (id != 0) //while the id enterd isn't 0 we will continue to enter the rest of the info and read the next id.
	{
		cin >> name;
		cin >> paymentPerHour;
		if (paymentPerHour < 0)
		{
			cout << "ERROR" << endl;

		}
		cin >> workHours;
		if (workHours < 0)
		{
			cout << "ERROR" << endl;

		}
		cin >> extraHours;
		if (extraHours < 0)
		{
			cout << "ERORR" << endl;

		}
		pEmployee->setId(id);
		pEmployee->setName(name);
		pEmployee->setPaymentPerHour(paymentPerHour);
		pEmployee->setWorkHours(workHours);
		pEmployee->setExtraHours(extraHours);

		numOfEmployees++; //adds one more to the count of employees
		pEmployee++; // points to the next employee
		cin >> id;
	}

	int highest = 0;
	for (int i = 1; i < numOfEmployees; i++)
	{
		if (listOfEmployees[i].salary() > listOfEmployees[highest].salary()) // if the salary of the selected worker is higher then the previous one we checked
			highest = i;
	}
	cout << "highest salary: " << listOfEmployees[highest].getId() << "\t" << listOfEmployees[highest].getName() << endl;

	int hardest = 0;
	for (int i = 1; i < numOfEmployees; i++)
	{
		if ((listOfEmployees[i].getWorkHours() + listOfEmployees[i].getExtraHours()) > (listOfEmployees[hardest].getWorkHours() + listOfEmployees[hardest].getExtraHours()))
			// if the sum of the selected worker's work hours is bigger then the previous one we checked
			hardest = i;
	}
	cout << "hardest worker: " << listOfEmployees[hardest].getId() << "\t" << listOfEmployees[hardest].getName() << endl;

	//system("pause");
	return 0;
}
/*
enter details, to end enter 0
1 aaa 100 40 5
2 bbb 100 30 4
3 ccc 150 40 2
0
highest salary: 3 ccc
hardest worker: 1 aaa
Press any key to continue . . .
*/