/*
Oria Segal
209338193
Homework no. 1 question 1
This program gets two fractions and chacks if they are equal or not.
*/
#include "rational.h"
using namespace std;
int main() {
	Rational num1, num2;
	char ch;
	cout << "enter two rational numbers" << endl;
	num1.setNumerator();
	cin >> ch;
	num1.setDenominator();
	cout << " ";
	num2.setNumerator();
	cin >> ch;
	num2.setDenominator();

	if (num2.equal(num1) == true) //if they are equal
		cout << "equal" << endl;
	else
	{
		cout << "different" << endl;
		num1.printFraction();
		num2.printFraction();
	}
	//system("pause");
	return 0;
}
/*
enter two rational numbers
3/9 3/6
 different
3/9
3/6
Press any key to continue . . .
*/