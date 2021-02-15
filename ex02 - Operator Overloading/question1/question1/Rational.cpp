#include <iostream>
#include "Rational.h"
using namespace std;
Rational::Rational(int newNumerator, int newDenominator)
{
	numerator = newNumerator;
	if (newDenominator == 0)
	{
		cout << "ERROR" << endl;
		denominator = 1;
	}
	else
		denominator = newDenominator;
}

void Rational::setNumerator(int newNumerator)
{
	numerator = newNumerator;
}
int Rational::getNumerator()
{
	return numerator;
}
void Rational::setDenominator(int newDenomenator)
{
	denominator = newDenomenator;
	if (denominator != 0) //if the denominator entered isn't aproved
		denominator = newDenomenator;
	else
	{
		cout << "ERROR" << endl;
		denominator = 1;
	}
}
int Rational::getDenominator()
{
	return denominator;
}
void Rational::printFraction() //print the fractions
{
	if (numerator == 0 || denominator == 1)
		cout << numerator << endl;
	else
	{
		int i = 1; 
		if (numerator < 0)
			numerator *= (-1);
		if (denominator < 0)
			denominator *= (-1);
		for (int k = 2; k <= numerator && k <= denominator; k++)
		{
			if (numerator%k == 0 && denominator%k == 0)
				i = k;
		}
		numerator /= i;
		denominator /= i;
		if (numerator == 0 || denominator == 1)
			cout << numerator << endl;
		else
			cout << numerator << "/" << denominator << endl;
	}
}
Rational Rational::operator+(Rational num)
{
	Rational tmp;
	tmp.setNumerator(numerator*num.getDenominator() + num.getNumerator()*denominator);
	tmp.setDenominator(denominator*num.getDenominator());
	return tmp;
}
Rational Rational::operator-(Rational num)
{
	Rational tmp;
	tmp.setNumerator(numerator*num.getDenominator() - (num.getNumerator()*denominator));
	tmp.setDenominator(denominator*num.getDenominator());
	return tmp;
}
Rational Rational::operator/(Rational num)
{
	Rational tmp;
	tmp.setNumerator(numerator*num.getDenominator());
	tmp.setDenominator(denominator*num.getNumerator());
	return tmp;
}
bool Rational::operator>= (const Rational&num)const
{
	if (((float)numerator / denominator >= (float)num.numerator / num.denominator))
		return true;
	return false;
}
bool Rational::operator<= (const Rational&num)const
{
	if (((float)numerator / denominator <= (float)num.numerator / num.denominator))
		return true;
	return false;
}
bool Rational:: operator> (const Rational&num)const
{
	if (((float)numerator / denominator > (float)num.numerator / num.denominator))
		return true;
	return false;
}
bool Rational::operator< (const Rational&num)const
{
	if (((float)numerator / denominator < (float)num.numerator / num.denominator))
		return true;
	return false;
}
bool Rational::operator!= (const Rational& num)const
{
	return !(numerator == num.numerator && denominator == num.denominator);
}
Rational Rational::operator-(int num) const
{
	int newNumerator = numerator * (num*denominator);
	return Rational(newNumerator, denominator);

}
Rational Rational::operator++() //prefix
{
	numerator = numerator + denominator;
	return *this;
}
Rational Rational::operator++(int notused) //postfix
{
	Rational temp(numerator, denominator);
	numerator += denominator;
	return temp;
}
Rational Rational::operator--() //prefix
{
	numerator = numerator - denominator;
	return *this;
}
Rational Rational::operator--(int notused) //postfix
{
	Rational temp(numerator, denominator);
	numerator -= denominator;
	return temp;
}
