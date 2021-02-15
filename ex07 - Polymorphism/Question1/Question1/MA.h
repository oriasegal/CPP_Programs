#pragma once
#include"BA.h"

class MA :public BA
{
private:
	bool research; //is the student a part of a research 
public:
	MA(int id, const char* name, const char* lastName, int courses, float* grades, bool research); //constructor
	MA() {}; //default constructor

	void setResearch(bool research); //sets the value 1 if the student is a part of a research 
	bool getResearch(); //returns the value saves acording to rather he is a part of a research or not
	void print(); //prints the student's personal details
	bool milga(); //checks if the student is eligible for a scholarship
	string studType() { return "MA"; } //returns the kind of student 
};


