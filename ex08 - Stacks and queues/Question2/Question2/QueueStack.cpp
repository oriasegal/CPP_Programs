#include<iostream>0
#include"QueueStack.h"
using namespace std;

void QueueStack::clear() //clears a queue for it's numbers
{
	while (!data.empty()) //while it's not empty
		data.pop(); //pops the data out of the queue
}

int QueueStack::dequeue() //after getting a queue- it pops out the number that was entered and prints it out
{
	stack<int> stk; //creats a stack of numbers
	if (data.empty()) //if the data is empty
		throw "Queue is empty"; //throws the msg
	while (!data.empty()) //while the data isn't empty
	{
		stk.push(data.top()); //pushes the new data into the stack
		data.pop(); //pops the data our of the queue
	}

	int num = stk.top(); //saves the top number of the stack in 'num' 
	stk.pop(); //pops out a number from the stack
	while (!stk.empty()) //while the stack isn't empty
	{
		data.push(stk.top()); //pushes the top number from the stack into the queue
		stk.pop(); //pops out a number from the stack
	}
	return num; //returns the number that was poped out
}

void QueueStack::enqueue(int value) //enters the entered number to the queue
{
	data.push(value); //pushes the new value into the queue
}

int QueueStack::front() //returns the first number of the queue- the number in the front
{
	stack<int> stk; 
	while (!data.empty()) //while the queue isn't empty
	{
		stk.push(data.top()); //pushes the top data from the queue into the stack
		data.pop(); //pops the data from the queue
	}

	int num = stk.top(); //saves the top number of the stack into 'num'
	while (!stk.empty()) //while the stack isn't empty
	{
		data.push(stk.top()); //pushes the top number form the stack into the queue
		stk.pop(); //pops a number from the stack
	}
	return num; //returns the number
}

bool QueueStack::isEmpty() const //returns true if the queue is empty
{
	return(data.empty()); //returns if the queue is empty or not- a boolian answer
}