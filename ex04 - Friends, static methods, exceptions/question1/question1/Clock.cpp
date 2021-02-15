#include <iostream>
#include "Clock.h"
using namespace std;

Clock::Clock(int Hours, int Minutes, int Seconds) //constructor
{
	try { 
		setHours(Hours);
		setMinutes(Minutes);
		setSeconds(Seconds);
	} //sends all to "set" functions and gets back an error note if there is one.
	catch (char *str)
	{
		cout << str; //gets the error note from setHour / setMinute / setSecond and knows to change them all to 0.
		hours = 0;
		minutes = 0;
		seconds = 0;
	}
}
Clock::Clock(const Clock &c) //copy constructor - just copying to a new clock and not building one.
{
	hours = c.getHours();
	minutes = c.getMinutes();
	seconds = c.getSeconds();
}
void Clock::setHours(int Hours)
{
	//if there's an error with the hours incerted it will throw a note back to the function that called it.
		if (Hours > 23) 
			throw "Invalid time - more than 24 hours.";
		if (Hours < 0) 
			throw  "Invalid time - negative number of hours.";
		hours = Hours;
}
void Clock::setMinutes(int Minutes)
{
	//if there's an error with the minutes incerted it will throw a note back to the function that called it.
		if (Minutes > 59)
			throw "Invalid time - more than 60 minutes.";
		if (Minutes < 0)
			throw "Invalid time - negative number of minutes.";
		minutes = Minutes;
}
void Clock::setSeconds(int Seconds)
{
	//if there's an error with the seconds incerted it will throw a note back to the function that called it.
		if (Seconds > 59)
			throw "Invalid time - more than 60 seconds.";
		if (Seconds < 0)
			throw "Invalid time - negative number of seconds.";
		seconds = Seconds;
}
int Clock::getHours()const //returns back the hours saved in the *this we're at
{
	return hours;
}
int Clock::getMinutes()const //returns back the minutes saved in the *this we're at
{
	return minutes;
}
int Clock::getSeconds()const //returns back the seconds saved in the *this we're at
{
	return seconds;
}
Clock Clock::operator=(const Clock& c)
{
	hours = c.getHours();
	minutes = c.getMinutes();
	seconds = c.getSeconds();
	return (*this);
}
Clock Clock::operator+=(const int& Seconds)
{
	seconds += Seconds;
	minutes += seconds / 60;
	seconds %= 60;
	hours += minutes / 60;
	minutes %= 60;
	hours %= 24;
	return (*this);
}
ostream& operator<<(ostream& os, const Clock c)
{
	if (c.hours < 10)
		os << "0";
	os << c.hours << ":";
	if (c.minutes < 10)
		os << "0";
	os << c.minutes << ":";
	if (c.seconds < 10)
		os << "0";
	os << c.seconds;
	return os;
}
istream& operator >>(istream& is, Clock& c)
{
	int h, m, s;
	is >> h >> m >> s;
	try { //using "set" functions to set the new hours, minutes and seconds incerted. If they send back an error note it'll be cought.
		c.setHours(h);
		c.setMinutes(m);
		c.setSeconds(s);
	}
	catch (char *str) { //If there was an error with the values incerted it will print them on the screen and save all as 0.
		cout << str;
		c.hours = 0;
		c.minutes = 0;
		c.seconds = 0;
	}
	return is;
}