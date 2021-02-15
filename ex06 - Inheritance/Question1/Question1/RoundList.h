#pragma once
#include"List.h"
class RoundList :public List
{
public:
	RoundList() :List() { }; //constructor
	RoundList(const RoundList&); //copy constructor
	~RoundList(); //destructor

	void addToEnd(int val); //adds an ekement to the end of the rounded list
	int search(int n); //searchs a number in the list by getting it's place as an int
	void add(int value); //adds a number to the begining of a list
	void removeFirst(); //removes the first elemnt of the list
	void clear(); //clears the list
};
