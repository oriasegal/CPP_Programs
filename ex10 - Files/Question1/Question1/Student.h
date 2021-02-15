#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Student
{
	int ID;
	char* familyName;
	char* privateName;
	bool course1;
	bool course2;
	bool course3;
	bool course4;
	bool course5;

public:
	Student(int id = 0, char* f = " ", char*p = " ");
	~Student();
	int getID() { return ID; }
	void setCourse(bool flag, int i);
	bool getCourse(int i);

	char* getPrivateName() { return privateName; }
	char* getFamilyName() { return familyName; }
};