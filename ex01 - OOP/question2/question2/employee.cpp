#include <iostream>
#include "employee.h"
using namespace std;

void Employee::setId(int id)
{
	Employee::id= id;
}
int Employee::getId()
{
	return id;
}
void Employee::setName(char *name)
{
	for(int i=0; i<21; i++)
	Employee::name[i]=name[i];
}
char* Employee::getName()
{
	return name;
}
void Employee::setPaymentPerHour(float payment)
{
	Employee::paymentPerHour= payment;
}
float Employee::getPaymentPerHour()
{
	return paymentPerHour;
}
void Employee::setWorkHours(int hours)
{
	Employee::workHours=hours;
}
int Employee::getWorkHours()
{
	return workHours;
}
void Employee::setExtraHours(int extra)
{
	Employee::extraHours=extra;
}
int Employee::getExtraHours()
{
	return extraHours;
}
float Employee::salary()
{
	int workHours= getWorkHours(), extraHours= getExtraHours();
	float paymentPerHour= getPaymentPerHour();
	float total = workHours * paymentPerHour + 1.5*extraHours*paymentPerHour;
	return total;
}