#include <iostream>
#include <string>
#include <cstring>
#include "BA.h"
#include "Student.h"
using namespace std;

BA::BA(int ID, const char* NAME, const char* LASTNAME, int COURSES, float* GRADES) :Student(ID, NAME, LASTNAME, COURSES) //constructor
{
	int SIZE = COURSES;
	grades = new float[SIZE]; //builds a new array with all the student's grades
	for (int i = 0; i < SIZE; i++)
		grades[i] = GRADES[i]; //copies the grades entered
	size = SIZE;
}
BA::~BA() //destructor
{
	if (size) //if it's not empty
		delete[]grades; //deletes all grades
}
void BA::setGrades(const float* &GRADES, int SIZE) //sets the grades in an array
{
	grades = new float[SIZE];
	size = SIZE;
	for (int i = 0; i < size; i++)
		grades[i] = GRADES[i]; //insetrs the grades by order into the array
}
float* BA::getGrades() //returns the list of grades
{
	return grades;
}
int BA::getSize() //returns the size of the grades' list
{
	return size;
}
void BA::print() //prints the student's personal details
{
	Student::print(); //uses the Student's printing function
	cout << "grades: ";
	for (int i = 0; i < size; i++)
		cout << grades[i] << " ";
	cout << endl;
}
float BA::average() //returns the average of the student's grades
{
	float sum = 0;
	for (int i = 0; i < size; i++)
		sum += grades[i]; //sums all the grades
	return(sum / size); //claculates the average and returns it
}
bool BA::milga() //checks if the choosen student is eligible for a scholarship 
{
	return (courses >= 10 && average() > 95); //if the average of the student's grades is above 95 and he's taking at least 10 courses
}


