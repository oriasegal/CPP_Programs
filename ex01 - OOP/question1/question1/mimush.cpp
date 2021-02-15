#include <iostream>
#include "rational.h"
using namespace std;

void Rational::setNumerator() 
{
	cin >> numerator;
}
int Rational::getNumerator() 
{
	return numerator;
}
void Rational::setDenominator() 
{
	cin >> denominator;
	if (denominator <= 0) //if the denominator entered isn't aproved
		denominator = 1;
}
int Rational::getDenominator() 
{
	return denominator;
}
void Rational::printFraction() //print the fractions
{
	cout << numerator << "/" << denominator << endl;
}
int Rational::reduceFraction() //calculates the reduced fractions of the fractions entered
{
	int i = 1;
	for (int k = 2; k <= numerator && k <= denominator; k++) //tries to divide it by any number from 2 uptill ot self
	{
		if (numerator%k == 0 && denominator%k == 0)
			i = k;
	}
		return i;
}
bool Rational::equal(Rational num) //checks if the fractions are equal or not
{
	int i = reduceFraction(), j = num.reduceFraction(); //helps to check also with their reduced fractions
	if ((numerator / i) == (num.numerator / j) && (denominator / i) == (num.denominator / j)) //checks if the numerators and the denominatiors are equal
		return true;
	return false;
}