#pragma once
using namespace std;
class Date 
{
public:
	int day;
	int month;
	int year;
	Date(int newDay, int newMonth, int newYear); //copy constarcor
	Date() {}; //default constractor

	void setDate(int newDay, int newMonth, int newYear);
	int getDay()const;
	int getMonth()const;
	int getYear()const;

	Date operator ++(); //befor a
	Date operator ++(int i); //after a
	bool operator ==(const Date &date)const;
	Date operator +=(int num);
	bool operator>(Date &date);
	bool operator<(Date &date);

	void print();
};
