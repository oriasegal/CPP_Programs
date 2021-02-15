#pragma once
using namespace std;
class String
{
private:
	char * str;
	void setString(const char* s);
public:
	String(char* s = '\0'); //defult constructor
	String(const String& s); //copy constractor
	~String(); //distructor

	char* getString() const;

	String& operator =(const String& s);
	bool operator==(const String& s) const;
	bool operator!=(const String& s);
	bool operator> (const String& s); 
	bool operator< (const String& s) const;
	bool operator<=(const String& s); 
	bool operator>=(const String& s); 
	
	int length() const;
	void print() const;
	String& insert(int index, const char* str);
};
