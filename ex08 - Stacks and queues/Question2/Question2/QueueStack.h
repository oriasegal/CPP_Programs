#pragma once
#include<stack>
#include"Queue.h"
using namespace std;

class QueueStack : public Queue
{
protected:
	stack<int> data; 

public:
	QueueStack() {}; //constructor

	void clear()override; //clears a queue for it's numbers (overriding the other "clear" function)
	int dequeue()override; //after getting a queue- it pops out the number that was entered and prints it out (overriding the other "dequeue" function)
	void enqueue(int value)override; //enters the entered number to the queue (overriding the other "enqueue" function)
	int front()override; //returns the first number of the queue- the number in the front (overriding the other "front" function)
	bool isEmpty() const override; //returns true if the queue is empty (overriding the other "isEmpty" function)
};