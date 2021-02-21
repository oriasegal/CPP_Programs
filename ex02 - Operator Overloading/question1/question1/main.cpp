/*
Oria Segal
Exercise no. 2 question 1
This program does different math problems between 2 rational numbers with different operators.
*/
#include "Rational.h"
using namespace std;
int main() {

	int numerator, denominator;
	char ch;

	cout << "Enter two rational numbers" << endl;
	cout << "a: ";
	cin >> numerator >> ch >> denominator;
	Rational a(numerator, denominator);

	cout << "b: ";
	cin >> numerator >> ch >> denominator;
	Rational b(numerator, denominator);

	cout << "b-a: ";
	(b - a).printFraction(); //prints the fraction after the calculation b-a

	cout << "a!=b: " << ((a != b) ? "true" : "false") << endl; //prints the fraction after the calculation a!=b

	cout << "a<b: " << ((a < b) ? "true" : "false") << endl; //prints the fraction after the calculation a<b

	cout << "a>b: " << ((a > b) ? "true" : "false") << endl; //prints the fraction after the calculation a>b

	cout << "a>=b: " << ((a >= b) ? "true" : "false") << endl; //prints the fraction after the calculation a>=b

	cout << "a++: ";
	(a++).printFraction(); //prints the fraction after the calculation a++

	cout << "--a: ";
	(--a).printFraction(); //prints the fraction after the calculation --a

	cout << "a--: ";
	(a--).printFraction(); //prints the fraction after the calculation a--

	b = a;

	cout << "b-a: ";
	(b - a).printFraction(); //prints the fraction after the calculation b-a

	cout << "b/a: ";
	(b / a).printFraction(); //prints the fraction after the calculation b/a

	cout << "a!=b: " << ((a != b) ? "true" : "false") << endl; //prints the fraction after the calculation a!=b

	cout << "a<b: " << ((a < b) ? "true" : "false") << endl; //prints the fraction after the calculation a<b

	cout << "a>=b: " << ((a >= b) ? "true" : "false") << endl; //prints the fraction after the calculation a>=b

	//system("pause");
	return 0;
}
