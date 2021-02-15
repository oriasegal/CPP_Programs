#include "Student.h"

Student::Student(int id, char* f, char*p)
{
	ID = id;
	familyName = f;
	privateName = p;
	course1 = 0;
	course2 = 0;
	course3 = 0;
	course4 = 0;
	course5 = 0;
}


Student::~Student()
{
}

void Student::setCourse(bool flag, int i)
{
	switch (i)
	{
	case 1:
		course1 = flag;
	case 2:
		course2 = flag;
	case 3:
		course3 = flag;
	case 4:
		course4 = flag;
	case 5:
		course5 = flag;
	default:
		break;
	}
}

bool Student::getCourse(int i)
{
	switch (i)
	{
	case 1:
		return course1;
	case 2:
		return course2;
	case 3:
		return course3;
	case 4:
		return course4;
	case 5:
		return course5;
	default:
		break;
	}
}