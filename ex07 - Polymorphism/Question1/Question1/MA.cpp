#include <iostream>
#include <string>
#include <cstring>
#include"MA.h"
#include "BA.h"
#include "Student.h"
using namespace std;

MA::MA(int ID, const char* NAME, const char* LASTNAME, int COURSES, float* GRADES, bool RESEARCH):BA(ID, NAME, LASTNAME, COURSES, GRADES) //constructor- using the BA constructor
{
	setResearch(RESEARCH);
}
void MA::setResearch(bool RESEARCH) //checks if the student is taking a part in a research and sets the boolian answer
{
	research = RESEARCH;
}
bool MA::getResearch() //returns 1 if the student is a part of a research
{
	return research;
}
void MA::print() //prints the student's personal details
{
	BA::print(); //uses the BA's printing function
	cout << "research: ";
	if (research) //if the student is taking a part in a research 
		cout << "yes" << endl;
	else
		cout << "no" << endl;
}
bool MA::milga() //checks if the choosen student is eligible for a scholarship 
{
	return((courses >= 7) && (average() > 90) && (research)); //the student will get the scholarship if his average is above 90, if he's taking at least 7 courses and if he's a part of a research
}

