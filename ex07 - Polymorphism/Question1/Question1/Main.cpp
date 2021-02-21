/*
Oria Segal
Exercise no. 7
This is a program that is using 4 different classes that are using each other to organize a list of different students in an academic school.
*/

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <string>
#include "PHD.h"
#include "MA.h"
using namespace std;

enum option
{
	stop, //End the program.
	addNewStudent, //add new student.
	milgaList, //print details of all students that eligible for a scholarship.
	mostResearch, //print name of the student that deals with the most hours of study.
	countMilgaBA, //print students of BA that eligible for a scholarship.
	noResearchMA, //print name of students of MA that no deals whit study.
	overheadStudent, //print if exists student that learning 15 courses.
	removePHDFailers, //delete students of PHD do not study any course. 
};

//the function gets vector and add student.
void add(vector<Student*>& vec)
{
	float* grades;
	int tmp, id, numCourse, numOfHoursInResearch;
	bool research;
	char* firstName = new char[20];
	char* lastName = new char[20];
	Student* tmpStu;
	cout << "enter 1 to add a BA student\n";
	cout << "enter 2 to add a MA student\n";
	cout << "enter 3 to add a PHD student\n";
	cin >> tmp;
	cout << "enter id, first name, last name and number Of Courses\n";
	cin >> id >> firstName >> lastName >> numCourse;
	switch (tmp)
	{
	case 1:
		cout << "enter " << numCourse << " grades\n";
		grades = new float[numCourse];
		for (int i = 0; i < numCourse; i++)
			cin >> grades[i]; 
		tmpStu = new BA(id, firstName, lastName, numCourse, grades);
		break;
	case 2:
		cout << "enter " << numCourse << " grades\n";
		grades = new float[numCourse];
		for (int i = 0; i < numCourse; i++)
			cin >> grades[i];
		cout << "enter 1 if the student does research and 0 if not\n";
		cin >> research;
		tmpStu = new MA(id, firstName, lastName, numCourse, grades, research);
		break;
	case 3:
		cout << "enter number of research hours\n";
		cin >> numOfHoursInResearch;
		tmpStu = new PHD(id, firstName, lastName, numCourse, numOfHoursInResearch);
		break;
	default:cout << "error" << endl;
		break;
	}
	vec.push_back(tmpStu);
}

//print details of all students that eligible for a scholarship.
void milga(vector<Student*>& vec)
{
	vector<Student*>::iterator itS;
	for (itS = vec.begin(); itS != vec.end(); itS++)
	{
		if ((*itS)->milga())
			((*itS))->print();
	}
}

//return the PHD that deals with the most hours of study.
Student* mostResearchHours(vector<Student*>& vec)
{
	Student*tmp = NULL;
	int numResearch = 0;
	vector<Student*>::iterator itS;
	for (itS = vec.begin(); itS != vec.end(); itS++)
	{
		if ((*itS)->studType() == "PHD")
			if (((PHD*)(*itS))->getResearchHours() > numResearch)
			{
				numResearch = ((PHD*)(*itS))->getResearchHours();
				tmp = ((PHD*)(*itS));
			}
	}
	return tmp;
}

int main()
{
	string tmp;
	Student* s;
	vector<Student*>vec;
	vector<Student*>::iterator itS;
	
	int op, mone = 0, mone2 = 0;
	bool exists = 0;
	
	cout << "enter 0-7\n";
	cin >> op;
	
	while (op != stop)
	{
		switch (op)
		{
		
		case addNewStudent://add new student 
			add(vec);                  
			break;
		
		case milgaList://print details of all students that eligible for a scholarship.
			milga(vec);
			break;
		
		case mostResearch://print name of the student(PHD) that deals with the most hours of study.
			s = mostResearchHours(vec);
			if (s)
			{
				cout << "PHD studnet with most research hours: ";
				cout << s->getName() << ' ' << s->getLastName() << endl;
			}
			break;
		
		case countMilgaBA://print students of BA that eligible for a scholarship.
			cout << "#BA students for milga: ";
			cout << count_if(vec.begin(), vec.end(), [](Student *s)
			{
				return (s->studType() == "BA") && s->milga();
			}) << endl;
			break;
		
		case noResearchMA://print name of students of MA that no deals whit study.
			cout << "list of no research MA students : ";
			for_each(vec.begin(), vec.end(), [](Student *x) 
			{
				if (x->studType() == "MA" && !((MA*)x)->getResearch())
					cout << ((MA*)x)->getName() << " " << ((MA*)x)->getLastName() << endl; 
			});
			break;
		
		case overheadStudent://print if exists student that learning 15 courses.
			cout << (any_of(vec.begin(), vec.end(), [](Student *s)
			{
				return s->getCourses() > 15;
			}) ? "there is a stedent that " : "no student ");
			cout << "takes more than 15 courses\n";
			break;

		case removePHDFailers://delete students of PHD do not study any course. 
			vec.erase(remove_if(vec.begin(), vec.end(), [](Student *s)
			{
				return s->studType() == "PHD" && s->getCourses() == 0;
			}), vec.end());
			for_each(vec.begin(), vec.end(), [](Student *s) {s->print(); });
			break;
		
		};
		
		cout << "enter 0-7\n";
		cin >> op;
	}
	
	//system("pause");
	return 0;
}
