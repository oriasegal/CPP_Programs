#pragma once
#include <iostream>
using namespace std;
class Account
{
	int accountNumber;
	int code;
	float balance;

public:
	Account(const int &accountNumber = 0, const int &code = 0, const int &balance = 0);// constructor

	void setBalance(const float&);
	int getAccountNumber()const;
	int getCode()const;
	float getBalance()const;

	friend istream& operator >> (istream& is, Account&);

	void withdraw(int);
	void deposit(float);

	static int getSumWithdraw();
	static float getSumDeposit();
	static int sumWithdraw;
	static float sumDeposit;
};