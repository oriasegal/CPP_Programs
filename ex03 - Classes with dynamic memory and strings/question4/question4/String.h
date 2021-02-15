#pragma once
using namespace std;
class String
{
private:
	char * str;

public:
	String(char* s = '\0'); //defult constructor
	String(const String& s); //copy constractor
	~String(); //distructor

	void setString(const char* s);
	char* getString() const;

	void print() const;
};