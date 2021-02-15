#include "Student.h"

void initializeStudent(fstream& file)
{
	Student s; // empty object
	for (int i = 0; i < 100; i++)
	{
		file.write((char*)&s, sizeof(s));
	}
}

int enterChoice();
int getNum();
void newStudent(fstream & f);
void updateStudent(fstream & f, int num);
void deleteStudent(fstream & f, int num);
bool registrationForCourse(fstream &f, int num, int i);
void printStudent(fstream &f, int num);
void printStudentByCourse(fstream &f, int i);


int main()
{
	fstream file("file.txt");
	initializeStudent(file); // initialize file at 100 empty Student
	int choice = enterChoice();
	int tmp, i;

	while (choice != 0)
	{
		switch (choice)
		{
		case 1:
			newStudent(file); // add a new student to the file
			break;
		case 2:
			cout << "Enter num of student: "; cin >> tmp;
			deleteStudent(file, tmp); // remove student from file
			break;
		case 3:
			cout << "Enter num of student: "; cin >> tmp;
			updateStudent(file, tmp); // update a student courses
			break;
		case 4:
			cout << "Enter num of student: \n"; cin >> tmp;
			cout << "Enter num of course: \n"; cin >> i;
			cout << (registrationForCourse(file, tmp, i));
			break;
		case 5:
			cout << "Enter num of student: \n"; cin >> tmp;
			printStudent(file, tmp); // print student details
			break;
		case 6:
			cout << "Enter num of course: \n"; cin >> i;
			printStudentByCourse(file, i);
			break;
		default:
			break;
		}
	}
	return 0;
}

int enterChoice()
{
	//system("CLS");
	cout << "\nEnter your choice" << endl
		<< "1 - add a new student to the file" << endl
		<< "2 - remove student from file" << endl
		<< "3 - update a student courses" << endl
		<< "4 - to know if the student registare for a course" << endl
		<< "5 - print student details" << endl
		<< "6 - print student that in course i" << endl
		<< "0 - end program\n? "; int menuChoice; cin >> menuChoice;
	return menuChoice;
}

int getNum()
{
	int studentNumber;

	cout << "Enter student number (1 - 100): "; cin >> studentNumber;
	while (studentNumber < 1 || studentNumber > 100)
	{
		cout << "ERROR\n";
		cout << "Enter student number (1 - 100): "; cin >> studentNumber;
	}
	return studentNumber;
}

void newStudent(fstream & f)
{
	Student s;
	int num = getNum();
	f.seekg((num - 1) * sizeof(s));
	f.read((char *)&s, sizeof(s));

	if (s.getID() == 0)
	{
		char familyName[20];
		char privateName[20];
		cout << "Enter familyName and privateName: "; cin >> familyName >> privateName;
		Student s1(num, familyName, privateName);
		f.seekp((num - 1) * sizeof(s1));
		f.write((char*)&s1, sizeof(s1));
	}
	else cout << "Account #" << num << " already contains information.\n";
}

void deleteStudent(fstream & f, int num)
{
	Student s;
	f.seekg((num - 1) * sizeof(s));
	f.read((char*)&s, sizeof(s));
	if (s.getID() != 0)
	{
		Student s1; // Empty object
		f.seekp((num - 1) * sizeof(s1));
		f.write((char*)&s1, sizeof(s1));
		cout << "Account #" << num << " deleted.\n";
	}
	else
		cout << "ERROR! Account #" << num << " is empty.\n";
}

void updateStudent(fstream & f, int num)
{
	char flag;
	Student s;
	f.seekg((num - 1) * sizeof(s));
	f.read((char*)&s, sizeof(s));
	if (s.getID() != 0)
	{
		for (int i = 0; i < 5; i++)
		{
			cout << "Enter value of coures " << i + 1 << " (0/1): "; cin >> flag;
			s.setCourse(flag, i + 1);
		}
		f.seekp((num - 1) * sizeof(s));
		f.write((char*)&s, sizeof(s));
		cout << "Account #" << num << " updated.\n";
	}
	else
		cout << "ERROR! Account #" << num << " is empty.\n";
}

bool registrationForCourse(fstream & f, int num, int i)
{
	Student s;
	f.seekg((num - 1) * sizeof(s));
	f.read((char*)&s, sizeof(s));
	if (s.getID() != 0)
	{
		return s.getCourse(i);
	}
	else
		cout << "ERROR! Account #" << num << " is empty.\n";
	return 0;
}

void printStudent(fstream &f, int num)
{
	Student s;
	f.seekg((num - 1) * sizeof(s));
	f.read((char*)&s, sizeof(s));
	if (s.getID() != 0)
	{
		cout << "Name: " << s.getPrivateName() << endl;
		cout << "Family name: " << s.getFamilyName() << endl;
		for (int i = 0; i < 5; i++)
		{
			cout << "Course " << i;
			cout << (s.getCourse(i + 1) ? ": Y\n" : ": N\n");
		}
	}
	else
		cout << "ERROR! Account #" << num << " is empty.\n";
}

void printStudentByCourse(fstream &f, int i)
{
	cout << "The Students are takes part in Course " << i << ":\n";
	Student s;
	for (int j = 0; i < 100; j++)
	{
		f.seekg((i) * sizeof(s));
		f.read((char*)&s, sizeof(s));
		if (s.getCourse(i))
		{
			cout << s.getPrivateName() << " " << s.getFamilyName() << endl;
		}
	}
}