#pragma once
#include<iostream>
using namespace std;
class List
{
public:
	class Link
	{
	public:
		int value;
		Link * next;

		Link(int linkValue = 0, Link * nextPtr = NULL); //constructor
		Link(const Link &); //copy constructor
		~Link() {} //destructor
	};

private:
	Link* head;
public:
	List(); //default constructor
	List(const List&); //copy constructor
	~List(); //destructor

	void add(int value); //insert element into list
	int firstElement() const; //return value of first element
	bool search(const int &value) const; //searchs for a number in the list
	bool isEmpty() const; //checks if the list is empty
	void removeFirst(); //removes first elemnt from list
	void clear(); //clears list
	void addEnd(int val); //

	friend ostream& operator<<(ostream& os, const List l); //print elements in  list
	friend istream& operator>>(istream& is, List &l); //inserts numbers to the list
	List operator=(const List& MyList);

	void insert(int key); //inserts a number to a list
	void remove(int key); //removes a number from a list
};