#include <iostream>
#include "Account.h" 
using namespace std;

int Account::sumWithdraw = 0; //the sum of the withdrawa starts at 0.
float Account::sumDeposit = 0; //the sum of the deposits starts at 0.
Account::Account(const int &AccountNumber, const int &Code, const int &Balance) //constructor
{
	accountNumber = AccountNumber;
	code = Code;
	balance = Balance;
}
void Account::setBalance(const float& Balance)
{
	balance = Balance;
}
int Account::getAccountNumber()const
{
	return accountNumber;
}
int Account::getCode()const
{
	return code;
}
float Account::getBalance()const
{
	return balance;
}
void Account::withdraw(int sum) //gives permission to draw money from the account. If not- prints an error note on the screen.
{
	if (balance - sum < -6000)
		throw "ERROR: cannot have less than - 6000 NIS!";
	if (sum > 2500)
		throw "ERROR: cannot withdraw more than 2500 NIS!";
	if (sum < 0)
		throw 0;
	balance -= sum; //updating the balance acording to the money that was drawn.
	sumWithdraw += sum; //updating the withdraw sum acording to the money that was drawn.
}
void Account::deposit(float sum) //gives permission to make a diposit from the account. If not- prints an error note on the screen.
{
	if (sum > 10000)
		throw "ERROR: cannot deposit more than 10000 NIS!";
	balance += sum; //updating the balance acording to the deposit that was made.
	sumDeposit += sum; //updating the deposits sum acording to the deposit that was made.
}
int Account::getSumWithdraw() //return the sum of all the money that was drawn.
{
	return sumWithdraw;
}
float Account::getSumDeposit() //returns the sum of all the checks that were deposited.
{
	return sumDeposit;
}
istream& operator>>(istream& is, Account& a)
{
	is >> a.accountNumber >> a.code;
	a.balance = 0;
	return is;
}