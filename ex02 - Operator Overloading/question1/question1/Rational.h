#pragma once
#include <iostream>
using namespace std;
class Rational {
public:
	int numerator;
	int denominator;

	Rational() {};  //default constarcor
	Rational(int numerator, int denominator); //copy constractor

	void setNumerator(int numerator);
	int getNumerator();
	void setDenominator(int denomenator);
	int getDenominator();
	void printFraction();
	int reduceFraction(int numerator, int denominator);

	Rational operator+(Rational);
	Rational operator-(Rational);
	Rational operator/(Rational);
	bool operator>= (const Rational&)const;
	bool operator<= (const Rational&)const;
	bool operator> (const Rational&)const;
	bool operator< (const Rational&)const;
	bool operator!= (const Rational&)const;
	Rational operator-(int num)const;
	Rational operator++();
	Rational operator++(int);
	Rational operator--();
	Rational operator--(int);
};