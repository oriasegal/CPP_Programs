/*
Oria Segal
Exercise no. 10
This program is using a binary file to make different functions with a student's data.
*/

#include <iostream>
#include <fstream>
using namespace std;

struct student //structure that keeps the data of each student
{
	int id; //the number of the student - this is the main key
	char firstName[20]; 
	char lastName[20]; 
	bool Courses[5]; //a bool value. Contains true or false for 5 courses
	student() //default function. Initializes a student
	{
		id = 0; //sets id as 0
		for (int i = 0; i < 5; i++) 
			Courses[i] = 0; //inserts the value 0 into all the courses' indexs
	}
};

bool searchRecord(int id, fstream& f) //the function checks whether the "Record" exists or not
{
	f.seekg((id - 1) * sizeof(student), ios::beg); //moves the pointer to the next id
	student s;
	f.read((char*)&s, sizeof(student)); //reads from the file
	if (s.id == 0) //if the id isn't 0
		return true;
	return false;
}

/*Adding a student. Function accepts a parameter pointer a binary file.
The function receives the data for students from standard input (keyboard).
If the resulting number of student still does not appear in the data file -
the file will be added to student information.*/
void newStudent(fstream& f)
{
	student s;
	cout << "Enter data for student: (id,first name,lest name,courses)" << endl; cin >> s.id >> s.firstName >> s.lastName;
	for (int i = 0; i < 5; i++) 
		cin >> s.Courses[i]; //prints out the courses' array 
	if (searchRecord(s.id, f)) //if searchRecord returns true- if the "record" exists
	{
		f.seekp((s.id - 1) * sizeof(student)); //moves the pointer to the next id
		f.write((char*)&s, sizeof(student)); //writes into the file
	}
	else
		cout << "student" << s.id << " is exists\n"; //prints out that this student exists already
}

/*Deleting a student. The function receives a pointer to a binary file as a
parameter and the second parameter, which is number of student. The function
deletes the file number is was received as a parameter student. (Note - You
can format the primary key of the record only).*/
void deleteRecord(fstream &deleteFromFl)
{
	cout << "Enter id to delete" << endl; 
	int tmpId; 
	cin >> tmpId;
	if (!searchRecord(tmpId, deleteFromFl)) //if searchRecord returns false (and as a whole it's true)
	{
		student blankStudent; //new student
		deleteFromFl.seekp((tmpId - 1) * sizeof(student)); //moves the pointer to the new id using the tmpId
		deleteFromFl.write((char*)&blankStudent, sizeof(student)); //deletes from the file the student's id
		cout << "student " << tmpId << " deleted.\n";
	}
	else 
		cout << "student " << tmpId << " is empty.\n";
}

/*Update listing. The function receives a pointer to a binary file as a parameter and
the second parameter, which is number of student. If the number of student listed in
the data file, the function would absorb values for 5 courses standardinput and update
the list of selected courses of student number is was received as a parameter.*/
void UpdateCourses(fstream &f, int _id)
{
	f.seekg((_id - 1) * sizeof(student)); //moves the pointer
	student stu;
	f.read((char*)&stu, sizeof(student)); //reads from the file
	if (!searchRecord(_id, f)) //if searchRecord returns false (and as a whole it's true)
	{
		cout << "enter true or false for courses:" << endl;
		for (int i = 0; i < 5; i++) 
			cin >> stu.Courses[i]; //enters true or false to each cours for this student
		f.write((char*)&stu, sizeof(student)); //writes it into the file
	}
	else 
		cout << "student " << _id << " is empty.\n";
}

/*Course listing examination. Function accepts a parameter pointer a binary file, the second
parameter, which is a number of students, and the third parameter which is course number (1 to 5).
If the number of student listed in the data file, and marking the course for student registration
this indicator that truth, this function returns true. Otherwise - function returns false.*/
bool listingInvestigation(fstream &f, int _id, int numCourse/*1-5*/)
{
	if (!searchRecord(_id, f)) //if searchRecord returns false (and as a whole it's true)
	{
		cout << "Student not found" << endl;
		return 0;
	}
	f.seekg((_id - 1) * sizeof(student)); //moves the pointer to the next id
	student stu;
	f.read((char*)&stu, sizeof(student)); //reads from the filr
	if (stu.id != 0) //if the student's id number isn't 0
	{
		if (stu.Courses[numCourse]) //if the student's courses' array isn't empty
			return true;
		return false;
	}
	else 
		return false;
}

/*Print student information. Function accepts a parameter pointer a binary file, and the second parameter
that constitutes a number student. If the a number existing student data file, the function prints to
standard output (screen) the student information: name, surname and for each course, if the student signed
up for will be printed: Y, otherwise, printed: N.*/
void printStudent(fstream &f, int _id)
{
	f.seekg((_id - 1) * sizeof(student), ios::beg); //moves the pointer
	student stu;
	f.read((char *)&stu, sizeof(student)); //reads from the file
	if (!searchRecord(_id, f)) //if searchRecord returns false (and as a whole it's true)
	{
		cout << stu.firstName << " " << stu.lastName << " " << endl;
		for (int i = 0; i < 5; i++) 
		{
			if (stu.Courses[i]) //if the student's courses' array isn't empty
				cout << "Y" << " " << endl;
			else
				cout << "N" << " " << endl;
		}
	}
	else
		cout << "student not found" << endl;
}

/*Print a list of students in the course. Function accepts a parameter pointer a binary file, and the second
parameter that constitutes course number (1 to 5). The function prints to standard output (screen) the students'
information (name and surname), registered in the course, whose number is passed as a parameter.*/
void StudentsInTheCourse(fstream &f, int numCourse)
{
	for (int i = 1; i < 100; i++)
	{
		f.seekg((i - 1) * sizeof(student), ios::beg); //moves the pointer
		student stu;
		f.read((char *)&stu, sizeof(student)); //reads from the file
		if (stu.id) //if the student's id number isn't 0
			if (stu.Courses[numCourse]) //if the student's courses' array isn't empty
				cout << stu.firstName << " " << stu.lastName << endl;
	}
}

void create() //creates a 'student' file
{
	ofstream stu("students.dat", ios::binary); //opens the file
	if (!stu) //if the file is not open
		cout << "not open" << endl;
	student s;  //empty record
	for (int i = 0; i < 100; i++)
		stu.write((char*)&s, sizeof(student)); //writes into the file
}

//The main program
int main()
{
	int choice, id, co;
	fstream fout("students.dat", ios::binary | ios::in | ios::out); //opens a file
	create(); //uses the create function to create a new 'student' file
	cout << "enter your choise:"; 
	cin >> choice;
	
	while (choice) //while the choice isn't 0
	{
		switch (choice)
		{
		
		case 1://Adding a student
			newStudent(fout); 
			break;
		
		case 2://Deleting a student
			deleteRecord(fout);
			break;
		
		case 3://Update listing.
			cout << "enter id:" << endl; 
			cin >> id;
			UpdateCourses(fout, id);
			break;
		
		case 4://Course listing examination.
			cout << "enter id and number course: " << endl;
			cin >> id >> co;
			if (listingInvestigation(fout, id, co))
				cout << "true" << endl;
			else
				cout << "false" << endl;
			break;
		
		case 5://Print student information
			cout << "enter id:" << endl; 
			cin >> id;
			printStudent(fout, id);
			break;
		
		case 6://Print a list of students in the course.
			cout << "enter number course:" << endl; 
			cin >> co;
			StudentsInTheCourse(fout, co);
			break;
	
		case 0:
			break;
		
		default:
			cout << "ERROR" << endl;
			break;
		}
		cout << "enter your choise:"; 
		cin >> choice;
	}
	
	fout.close(); //closes the file after using it 
	
	//system("pause");
	return 0;
}
