/*
Oria Segal
209338193
Homework no. 4 question 1
This program runs a bank with all it's functions.
*/
#include <iostream>
using namespace std;
#include "Clock.h"
#include "Account.h"

enum action
{
	stop,
	balance,
	deposit,
	withdraw,
	sumDeposit,
	sumWithdraw
};
action menu()
{
	cout << "enter 1 to get account balance" << endl;
	cout << "enter 2 to deposit money" << endl;
	cout << "enter 3 to withdraw money" << endl;
	cout << "enter 4 to see the sum of all withdraws" << endl;
	cout << "enter 5 to see the sum of all Deposits" << endl;
	cout << "enter 0 to stop" << endl;
	int x;
	cin >> x;
	return (action)x;
}
int findAccount(Account* bank, int size) //chaecks if the account is in the list.
{
	int number, code;
	cout << "please enter account number: ";
	cin >> number;
	int i = 0;
	while (i < size && bank[i].getAccountNumber() != number) //goes throw all the accounts' list.
		i++;
	if (i == size) //if we got to the end of the list and didn't find the number that was entered- an error will apear.
		throw "ERROR: no such account number!\n";
	cout << "please enter the code: ";
	cin >> code; 
	if (bank[i].getCode() !=code) //if the code is not as asked- an error note will apear.
		throw "ERROR: wrong code!\n";
		return i; //returns the index of the account with the code that was entered.
}
void printTransaction(Account a, action ac, Clock& c) //prints out all the details asked.
{
	cout << c << "\t"; //prints the exact time of transaction.
	;
	switch (ac)
	{
	case balance: //if chose balance- prints out the account number and the current balance.
		cout << "account #: " << a.getAccountNumber() << "\t"; 
		cout << "balance: " << a.getBalance() << endl;
		break;
	case deposit: //if chose deposit- goes to the next case (withdraw).
	case withdraw: //if chose withdraw- prints out the account number and the new current balance.
		cout << "account #: " << a.getAccountNumber() << "\t";
		cout << "new balance: " << a.getBalance() << endl;
		break;
	case sumDeposit: //if chose sumDeposit- prints out the sum of all the deposits made. 
		cout << "sum of all deposits: " << Account::getSumDeposit() << endl;
		break;
	case sumWithdraw: //if chose sumWithdraw- prints out the sum of all the withdraws made. 
		cout << "sum of all withdraws: " << Account::getSumWithdraw() << endl;
		break;
	}
}
void getBalance(Account* bank, int size, Clock& c)
{
	int i = findAccount(bank, size); //finds the account, if found- the function sends back the index of the account in the list of all accounts.
	c += 20; //adds 20 seconds to the clock.
	printTransaction(bank[i], balance, c); //prints out the current balance of the account.
}
void cashDeposit(Account* bank, int size, Clock& c)
{
	int i = findAccount(bank, size); //finds the account, if found- the function sends back the index of the account in the list of all accounts.
	float amount;
	cout << "enter the amount of the check: ";
	cin >> amount; 
	bank[i].deposit(amount); //makes the deposit from the account and changes the amount in it.
	c += 30; //adds 30 seconds to the clock.
	printTransaction(bank[i], deposit, c); //prints out the deposit made from the account.
}
void cashWithdraw(Account* bank, int size, Clock& c)
{
	int i = findAccount(bank, size); //finds the account, if found- the function sends back the index of the account in the list of all accounts.
	float amount;
	cout << "enter the amount of money to withdraw: ";
	cin >> amount;
	bank[i].withdraw(amount); //makes the wuthdraw and changes the amount in this account.
	c += 50; //adds 50 seconds to the clock.
	printTransaction(bank[i], withdraw, c); //prints out the withdraw case- account number and current balance.  
}
int main()
{
	Clock c(8);
	Account bank[10];
	cout << "enter account number and code for 10 accounts:\n";
	for (int i = 0; i < 10; i++) //adds 10 acoounts and 10 codes to the list.
	{
		try {
			cin >> bank[i];
			for (int j = 0; j < i; j++)
				if (bank[i].getAccountNumber() == bank[j].getAccountNumber())
					throw "ERROR: account number must be unique!\n"; //an error note for an invalid accounts number.
			if (bank[i].getCode() > 9999 || bank[i].getCode() < 1000) //if the code is invalid- not 4 numbers starting with 0
				throw "ERROR: code must be of 4 digits!\n";

		}
		catch (const char* msg)
		{
			cout << c << '\t' << msg;
			i--;
		}
	}
	action ac = menu();
	while (ac)
	{
		try {
			switch (ac)
			{
			case balance:
				getBalance(bank, 10, c);
				break;
			case withdraw:
				cashWithdraw(bank, 10, c);
				break;
			case deposit:
				cashDeposit(bank, 10, c);
				break;
			case sumDeposit:
				c += 60;
				printTransaction(bank[0], sumDeposit, c);
				break;
			case sumWithdraw:
				c += 60;
				printTransaction(bank[0], sumWithdraw, c);
			}
		}
		catch(const char *str)
		{
			cout << c << '\t' << str;
		}
		catch (...)
		{ }
		ac = menu();
	}
	return 0;
}