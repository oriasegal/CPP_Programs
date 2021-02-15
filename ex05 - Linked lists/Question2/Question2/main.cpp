/*
Oria Segal
209338193
Homework no. 5 question 2
This program has 2 functions- one merges two lists to a new sorted list, and one takes the meged list and makes sure that the numbers are used only once.
*/
#include <iostream>
#include "List.h"
using namespace std;

List merge(const List &lst1, const List &lst2) //gets two sorted lists and merges them to one. returns the meged list
{
	List l = lst1;
	List l2 = lst2;
	while (!l2.isEmpty()) //while l2 is empty
	{
		l.insert(l2.firstElement()); //puts the first element of the first list in the new one
		l2.removeFirst(); //deletes the element that was moved
	}
	return l; //returns the merged list
}
void makeSet(List &lst) //gets a meged list and removes any elements that are used more then once
{
	List lst1 = lst;
	int num, num1;
	if (!lst.isEmpty()) //if lst is empty
		num = lst1.firstElement();
	lst1.removeFirst();
	while (!lst1.isEmpty()) //while lst1 is empty
	{
		num1 = lst1.firstElement();
		if (num == num1) //if it's used already
			lst.remove(num);
		lst1.removeFirst();
		num = num1;
	}
}

int main()
{
	List lst1, lst2, mergedList;

	cout << "enter sorted values for the first list:" << endl;
	cin >> lst1;
	cout << "enter sorted values for the second list:" << endl;
	cin >> lst2;

	mergedList = merge(lst1, lst2);
	cout << "the new merged list: " << mergedList << endl;

	makeSet(mergedList);
	cout << "the new merged set: " << mergedList << endl;

	return 0;
	//system("pause");
}