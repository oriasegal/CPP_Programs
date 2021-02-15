#include "String.h"
#include<iostream>
#include<string.h>
#include<cstring>
#pragma warning (disable:4996)
#include "String.h"
#include<iostream>
using namespace std;

void String::setString(const char* s)
{
	if (s)
	{
		int len = strlen(s);
		str = new char[len + 1];
		strcpy(str, s);
	}
	else str = NULL;
}

String::String(char* s) //defult constructor
{
	setString(s);
}
String::String(const String& s) //copy constructor
{
	setString(s.getString());
}
String::~String() //distructor
{
	if (str)
		delete[] str;
	str = NULL;
}
char* String:: getString() const
{
	return str;
}

String& String::operator =(const String& s)
{
	if (str)
		delete[] str;
	setString(s.getString());
	return *this;
}
bool String::operator==(const String& s) const
{
	if (!strcmp(str, s.getString()))
		return true;
	else
		return false;
}
bool String::operator< (const String& s) const
{
	return strcmp(str, s.getString()) < 0;
}
bool String::operator!=(const String& s)
{ 
	return !operator==(s); 
}
bool String::operator> (const String& s)
{ 
	//return(!(*this < s) && strcmp(str, s.getString()));
	return (!operator< (s)) && (operator!= (s)); 
}
bool String::operator<=(const String& s)
{ 
	//return(*this < s || !(strcmp(str, s.getString())));
	return !operator> (s); 
}
bool String::operator>=(const String& s)
{ 
	//return(*this > s || !(strcmp(str, s.getString())));
	return !operator< (s); 
}
int String::length() const
{
	return strlen(str);
}
void String::print() const
{
	if (str) 
		cout << str;
}
String& String::insert(int index, const char* newStr)
{
	char temp[30];
	strcpy(temp, newStr);
	strcat(temp, str + index);
	strcpy(str + index, temp);
	return (*this);
}

//if (index > length())
	//{
	//	cout << "ERROR" << endl;
	//	return *this;
	//}

	//int newlen = strlen(newStr) + length();
	//char* temp = new char[newlen + 1];

	//strcpy(temp, str, index); //first part
	//temp[index] = '\0';
	//strcat(temp, newStr); //second part
	//strcat(temp, str + index); //third part

	//delete[] str; //delete the old string
	//setString(temp); //set the new string
	//delete[] temp; //delete the temp string
	//return *this;
