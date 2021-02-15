#include<iostream>
#include<cstring>
#include<string>
#include"Student.h"
#pragma warning (disable:4996)
using namespace std;

Student::Student(int ID, const char* NAME, const char* LASTNAME, int COURSES) //constructor
{
	setId(ID); //sets the id number of the student
	setName(NAME); //sets the first name of the student
	setLastName(LASTNAME); //sets the last name of the student
	setCourses(COURSES); //sets the number of courses the student is taking
}

Student::Student() //defualt constructor
{
	id = 0;
	name = NULL;
	lastName = NULL;
	courses = 0;
}
Student::~Student() //destructor
{
	if (name)
		delete[]name;
	if (lastName)
		delete[]lastName;
}
void Student::setId(int ID) //sets the student's id number
{
	id = ID;
}
int Student::getId() //returns the student's id number
{
	return id;
}
void Student::setName(const char* NAME) //sets the first name of the student as an array
{
	if (NAME) //if the name sent isn't empty
	{
		int len = strlen(NAME) + 1; //counts the number of letters in the name to make the fitting array
		name = new char[len];
		strcpy(name, NAME);
	}
}
char* Student::getName()const //returns the name of the student
{
	return name;
}
void Student::setLastName(const char* LASTNAME) //sets the last name of the student as an array
{
	if (LASTNAME) //if the name sent isn't empty
	{
		int len = strlen(LASTNAME) + 1; //counts the number of letters in the name to make the fitting array
		lastName = new char[len];
		strcpy(lastName, LASTNAME);
	}
}
char* Student::getLastName()const //returns the last name of the student
{
	return lastName;
}
void Student::setCourses(int COURSES) //sets the number of the courses the student is taking
{
	courses = COURSES;
}
int Student::getCourses() //returns the number of courses
{
	return courses;
}
bool Student::milga() //checks if the choosen student is eligible for a scholarship 
{
	if (courses >= 10) //if the student has at least 10 courses it will send true
		return 1;
}
void Student::print() //print the student's personal details
{
	cout << "ID: " << this->id << endl;
	cout << "first name: " << this->name << endl;
	cout << "last name: " << this->lastName << endl;
	cout << "num courses: " << this->courses << endl;
}

