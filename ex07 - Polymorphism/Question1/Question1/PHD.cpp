#include <iostream>
#include <string>
#include <cstring>
#include "PHD.h"
#include"MA.h"
#include "BA.h"
#include "Student.h"
using namespace std;
PHD::PHD(int ID, const char* NAME, const char* LASTNAME, int COURSES, int RESEARCHHOURS) :Student(ID, NAME, LASTNAME, COURSES) //constructor
{
	setResearchHours(RESEARCHHOURS);
}
void PHD::setResearchHours(int RESEARCHHOURS) //sets the number of research hours the student does
{
	researchHours = RESEARCHHOURS;
}
int PHD::getResearchHours() //returns the number of research hours the student does
{
	return researchHours;
}
void PHD::print() //prints the student's personal details
{
	Student::print(); //uses the Student's printing function
	cout << "hours: " << researchHours << endl;
}
bool PHD::milga() //checks if the choosen student is eligible for a scholarship
{
	return((courses == 2) && (researchHours > 25)); //the student will get the scholarship if he's taking 2 courses and if he does more tem 25 research hours
}

