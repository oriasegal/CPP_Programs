#pragma once
#include <iostream>
using namespace std;
class Clock
{
	int hours;
	int minutes;
	int seconds;

public:
	//Clock() { int hours = 0; int minutes = 0; int seconds = 0; } //default constructor
	Clock(int Hours = 0, int Minuets = 0, int Seconds = 0); //constructor
	Clock(const Clock &c); //copy constructor

	void setHours(int);
	void setMinutes(int);
	void setSeconds(int);
	int getHours()const;
	int getMinutes()const;
	int getSeconds()const;

	Clock operator=(const Clock& c);
	Clock operator += (const int& seconds);

	friend ostream& operator<<(ostream& os, const Clock c);
	friend istream& operator >>(istream& is, Clock& c);
};