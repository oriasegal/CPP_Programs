#pragma once
#include <iostream>
#include <string>
#include"Student.h"

class BA :public Student
{
	//protected:
	float* grades;
	int size;
public:
	BA(int id, const char* name, const char* lastName, int courses, float* grades); //constructor
	BA(); //default constructor
	~BA(); //destructor

	void setGrades(const float* &grades, int); //sets an array of all the student's grades
	float* getGrades(); //returns the grades' array, the grades' list
	int getSize(); //returns the size of the greades' array, the number of grades
	virtual void print(); //prints the student's personal details
	virtual float average(); //calculates the average of the student's grades, a virtual function 
	virtual bool milga(); //checks if the student is eligible for a scholarship
	string studType() { return "BA"; } //returns the kind of student 
};