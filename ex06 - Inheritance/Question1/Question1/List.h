#pragma once
#include<iostream>
using namespace std;
class List
{
protected:
	class Link
	{
	public:
		int value;
		Link * next;

		Link(int linkValue, Link * nextPtr); //constructor
		Link(const Link &); //copy constructor
	};

protected:
	Link* head;
public:
	List(); //default constructor
	List(const List&); //copy constructor
	~List(); //destructor

	void add(int value); //insert element into list
	int firstElement() const; //return value of first element
	bool isEmpty() const; //checks if the list is empty
	void removeFirst(); //removes first elemnt from list
	void clear(); //clears list
};

