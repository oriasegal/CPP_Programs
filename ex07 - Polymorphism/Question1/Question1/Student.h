#pragma once
#include <iostream>
#include<cstring>
#include<string>
#pragma warning (disable:4996)

class Student
{
protected:
	int id;
	char* name;
	char* lastName;
	int courses;

public:
	Student(int ID = 0, const char* name = NULL, const char* lastName = NULL, int Courses = 0); //cnstructor 
	Student(); //defualt constructor
	virtual ~Student(); //virtual distructor

	void setId(int id); //sets the id of the student
	int getId(); //returns the student's id
	void setName(const char*); //sets the first name of the student
	char* getName()const; //returns the first name of the student
	void setLastName(const char*); //sets the last name of the student
	char* getLastName()const; //returns the last name of the student
	void setCourses(int); //sets the number of courses the student is taking
	int getCourses(); //returns the number of courses the student is taking
	virtual void print() = 0; //prints the student's details, a virtual function ***to add =0 after the )
	virtual bool milga() = 0; //checks if the student is eligible for a scholarship, a virtual function

	virtual string studType() = 0; //returns the kind of student 
};


