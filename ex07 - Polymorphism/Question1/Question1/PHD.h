#pragma once
#include"Student.h"

class PHD :public Student
{
private:
	int researchHours;
public:
	PHD(int id, const char* name, const char* lastName, int courses, int researchHours); //constructor

	void setResearchHours(int); //sets the of research hours the student does
	int getResearchHours(); //returns the number of research hours the student does
	void print(); //prints the student's personal details
	bool milga(); //checks if the student is eligible for a scholarship
	string studType() { return "PHD"; } //returns the kind of student 
}; 

