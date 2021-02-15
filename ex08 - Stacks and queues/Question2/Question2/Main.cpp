/*
Oria Segal
209338193
Homework no. 8 question 2
This program uses the Queue and the Queue Stack to print the main file.
*/
#include <iostream>
#include "QueueStack.h"
using namespace std;

int main() 
{
	Queue* Q;
	Q = new QueueStack(); //create a new QueueStack
	try 
	{
		for (int i = 0; i < 10; i++) //enters numbers into the QueueStack 
			Q->enqueue(i);
	}
	catch (const char* msg) //chatches one of the messeges
	{
		cout << msg; //prints the msg that was caught
	}

	cout << "first on Q is: " << Q->front() << endl; //prints the first number in the queue
	cout << "take out 2 elemets:" << endl;
	cout << Q->dequeue() << ' ' << Q->dequeue() << endl; //removes 2 numbers from the QueueStack and prints them
	cout << "first on Q is: " << Q->front() << endl; //prints the first number after the change
	
	Q->enqueue(8); 
	Q->enqueue(9);
	
	while (!Q->isEmpty()) //clears the QueueStack and prints all the numbers
		cout << Q->dequeue() << " "; //prints each number
	
	//system("pause");
	return 0;
}