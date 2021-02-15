#include<iostream>
#include "List.h"
using namespace std;
List::Link::Link(int val, Link* nxt) : value(val), next(nxt) {} //link constructor
List::Link::Link(const Link& source) : value(source.value), next(source.next) {} //link copy constructor
List::List() : head(NULL) {} //list constructor
List::List(const List &l) //list copy constructor
{
	Link *src, *trg; //define two pointers one for each list,src - source, trg - new list//

	if (l.head == NULL) //if source is empty list//
		head = NULL;
	else //list is not empty//
	{
		//create first element in list//
		head = new Link(l.head->value, NULL);

		//two pointers will each get beginning of list//
		src = l.head;
		trg = head;
		//go over source list until end of list//
		while (src->next != NULL)
		{
			//create new Link, and attach to end of new list//
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
bool List::search(const  int &val) const //checks if the number that was sent is in the list 
{
	for (Link* p = head; p != NULL; p = p->next) //goes throw all the elements in the list
		if (val == p->value) //if it's the same number
			return true;
	return false; //when the number isn't found
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
void List::addEnd(int val) //adds a new link to the list with the number sent
{
	if (isEmpty())
		add(val);
	else
	{
		Link *l = head;
		while (l->next != NULL)
			l = l->next;
		l->next = new Link(val, NULL);
	}
}
List List::operator=(const List& myList) // operator = -will copy one list to the other.
{
	if (myList.isEmpty())
	{
		head = NULL;
		return (*this);
	}
	add(myList.firstElement());
	Link *src;
	src = myList.head;
	while (src->next != NULL)
	{
		src = src->next;
		addEnd(src->value);
	}
	return(*this);
}
ostream& operator<< (ostream& os, List l) //operator << -gets an ostream parameter and prints the list that was sent
{
	List l2 = l;
	while (l2.head != NULL) //while the head of the list isn't pointing at NULL- while the list isn't empty
	{
		os << l2.firstElement() << " "; //prints the first element of the list
		l2.removeFirst(); //removes the first element and moves to the next one to continue printing
	}
	return os;
}
istream& operator>>(istream& is, List &l) //operator >> -gets an istream parameter and writes in the new list
{
	int val1, val2;
	is >> val1 >> val2;
	while (val1 <= val2)
	{
		l.addEnd(val1); //uses the func addEnd to add the numbers to the list
		val1 = val2;
		is >> val2;
	}
	l.addEnd(val1); //uses the func addEnd to add the last number to the list
	return is;
}
void List::insert(int key) //inserts the number that was sent to the list
{
	Link *l = head;
	Link *temp;
	if (isEmpty() || l->value > key)
		add(key);
	else
	{
		while (l->next != NULL && (l->next)->value <= key)
			l = l->next;
		if (l->next == NULL)
			addEnd(key);
		else {
			temp = new Link(key, l->next);
			l->next = temp;
		}
	}
}
void List::remove(int key) //removes the link that the number that was sent is an element in it.
{
	Link *l = head;
	Link *temp;
	if (isEmpty() || l->value > key)
		throw "value not found";
	if (l->value == key)
		removeFirst();
	else {
		while (l->next != NULL && (l->next)->value < key)
			l = l->next;
		if (l->next == NULL)
			throw "value not found";
		if ((l->next)->value > key)
			throw "value not found";
		Link *temp = l->next;
		l->next = (l->next)->next;
		delete temp;
	}
}