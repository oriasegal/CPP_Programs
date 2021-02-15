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
String::String (const String& s)//copy constractor
{
	setString(s.getString());
}
String:: ~String() //distructor
{
	if (str)
		delete[] str;
	str = NULL;
}
char*  String::getString() const
{
	return str;
}
void  String::print() const
{
	if (str)
		cout << str;
}

