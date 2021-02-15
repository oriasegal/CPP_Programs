#pragma once
#include <iostream>
using namespace std;
class Rational {
private:
	int numerator; 
	int denominator;
	int reduceFraction();
public:
	void setNumerator();
	int getNumerator();
	void setDenominator();
	int getDenominator();
	void printFraction();
	bool equal(Rational num);
};
