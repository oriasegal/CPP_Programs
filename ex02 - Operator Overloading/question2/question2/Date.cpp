#include <iostream>
#include "Date.h"
using namespace std;

Date::Date(int newDay, int newMonth, int newYear) //copy cinstractor
{
	if (newDay >= 1 && newDay <= 30)
		day = newDay;
	else
	{
		cout << "Error day" << endl;
		day = 1;
	}
	if (newMonth >= 1 && newMonth <= 12)
		month = newMonth;
	else
	{
		cout << "Error month" << endl;
		month = 1;
	}
	if (newYear >= 1970 && newYear <= 2099)
		year = newYear;
	else
	{
		cout << "Error year" << endl;
		year = 1970;
	}
}
void Date::setDate(int newDay, int newMonth, int newYear)
{
	if (newDay >= 1 && newDay <= 30)
		day = newDay;
	else
	{
		cout << "Error day" << endl;
		day = 1;
	}
	if (newMonth >= 1 && newMonth <= 12)
		month = newMonth;
	else
	{
		cout << "Error month" << endl;
		month = 1;
	}
	if (newYear >= 1970 && newYear <= 2099)
		year = newYear;
	else
	{
		cout << "Error year" << endl;
		year = 1970;
	}
}
int Date::getDay()const
{
	return day;
}
int Date::getMonth()const
{
	return month;
}
int Date::getYear()const
{
	return year;
}
void Date::print()
{
	cout << day << "/" << month << "/" << year << endl;
}
Date Date::operator++() //++date
{
	day += 1;
	if (day > 30)
	{
		day = 1;
		month++;
		if (month > 12)
		{
			month = 1;
			year++;
		}
	}
	return *this;
}
Date Date::operator++(int i) //date++
{
	Date temp = *this;
	++(*this);
	return temp;
}
bool Date::operator==(const Date &date)const
{
	if (day == date.day && month == date.month && year == date.year)
		return true;
	return false;
}
Date Date::operator +=(int num)
{
	day += num; 
	if (day > 30)
	{
		day = num;
		month++;
		if (month > 12)
		{
			month = 1; 
			year++;
		}
	}
	return *this;
}

bool Date::operator>(Date &date)
{
	if (year > date.year)
		return true;
	if ((month > date.month) && (year == date.year))
		return true;
	if ((day > date.day) && (month == date.month))
		return true;
	return false;
}
bool Date::operator<(Date &date)
{
	if (year < date.year)
		return true;
	if ((month < date.month) && (year == date.year))
		return true;
	if ((day < date.day) && (month == date.month))
		return true;
	return false;
}
