#pragma once
#include <iostream>
using namespace std;
class Employee {
private:
	int id;
	char name[21];
	float paymentPerHour;
	int workHours;
	int extraHours;
public:
	void setId(int id);
	int getId();
	void setName(char *name);
	char* getName();
	void setPaymentPerHour(float payment);
	float getPaymentPerHour();
	void setWorkHours(int hours);
	int getWorkHours();
	void setExtraHours(int extra);
	int getExtraHours();
	float salary();
};
