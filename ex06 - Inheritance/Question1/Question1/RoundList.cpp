#include<iostream>
#include"RoundList.h"
using namespace std;
RoundList::RoundList(const RoundList& l) :List(l) //copy constructor- uses the regular list's copy constructor and conects the last element to the first to make it a rounded list
{
	Link *l1 = head;
	while (l1->next != NULL) //while it's not the end of the list
		l1 = l1->next;
	l1->next = head; //the last elemet points to the head to make it round
}
void RoundList::addToEnd(int val) //gets a number and adds it to the end of the list 
{
	if (isEmpty())
		add(val); //if the list is empty it uses the regular add function- sends the value to the function that adds it and builds a new list
	else
	{
		Link *l = head;
		while (l->next != head)
			l = l->next;
		l->next = new Link(val, head);
	}
}
int RoundList::search(int n) //gets an index that represents a place in the list and returns the value in this place
{
	if (isEmpty()) //if the list is empty it returns -1
		return -1;
	Link *l = head;
	while (n != 0) //while it's not at the first place
	{
		l = l->next;
		n--;
	}
	return l->value;
}
void RoundList::add(int value) //adds a value to the begining of a list (can also create a new list by making the value the head)
{
	if (isEmpty()) //if the list is empty
	{
		List::add(value);
		head->next = head;
	}
	else
	{
		List::add(value);
		Link *l = head->next;
		while (l->next != head->next)
			l = l->next;
		l->next = head;
	}
}
void RoundList::removeFirst() //gets a list and removes it's first element (uses the list's remiveFirst function)
{
	Link *l1 = head;
	if (isEmpty()) //if the list is empty and there is nothing to remove
		throw "the List is empty, no Elements to remove";
	if (l1->next == l1) //if there is only one elmenet in the list
	{
		List::removeFirst();
		head = NULL; //the head is pointing at nothing- at null
	}
	else
	{
		List::removeFirst();
		Link *l = head;
		while (l->next != l1)
			l = l->next;
		l->next = head;
	}
}
void RoundList::clear() //making the rounded list not rounded- like a regular list and them uses the list's function clear to delete all the elements 
{
	if (!isEmpty())
	{
		Link *l = head;
		while (l->next != head)
			l = l->next;
		l->next = NULL;
		List::clear();
	}
}
RoundList::~RoundList() //destructor
{
	clear(); //uses clear to destruct the list
}