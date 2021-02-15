#include<iostream>
#include "List.h"
using namespace std;

List::Link::Link(int val, Link* nxt) : value(val), next(nxt) {} //link constructor
List::Link::Link(const Link& source) : value(source.value), next(source.next) {} //link copy constructor
List::List() : head(NULL) {} //list constructor
List::List(const List &l) //list copy constructor
{
	Link *src, *trg; //define two pointers one for each list,src - source, trg - new list

	if (l.head == NULL) //if source is empty list
		head = NULL;
	else //list is not empty
	{
		//create first element in list
		head = new Link(l.head->value, NULL);

		//two pointers will each get beginning of list
		src = l.head;
		trg = head;
		//go over source list until end of list
		while (src->next != NULL)
		{
			//create new Link, and attach to end of new list
			trg->next = new Link((src->next)->value, NULL);
			src = src->next;
			trg = trg->next;
		}
	}
}
List::~List() //list destructor
{
	clear();
}
void List::clear() //empties the list
{
	Link* next;
	for (Link * p = head; p != NULL; p = next)
	{
		next = p->next;
		p->next = NULL;
		delete p;
	}
	head = NULL; //marks that the list has no elements in it
}
bool List::isEmpty() const //checks if the list is empty- if the head is pointing at NULL and if it is- returns true
{
	return head == NULL;
}
void List::add(int val) //adds a new number to the begining of a linked list
{
	head = new Link(val, head);
	if (head == NULL) //if the list is empty
		throw "failed in memory allocation";
}
int List::firstElement() const //gets the list and returns it's first element
{
	if (isEmpty()) //if the func isEmpty returns true- the list is empty and there's nothing to return
		throw "the List is empty, no first Element";
	return head->value;
}
void List::removeFirst() //gets a list and removes it's first element
{
	if (head != NULL) //makes sure that the list isn't empty
	{
		Link* p = head; //saves a pointer to the element it's removing
		head = head->next; //head points at next element
		p->next = NULL;
		delete p; //deletes the element it removed from the memory
	}
}