#include<iostream>
#include"Vector.h"
using namespace std;

Vector::Vector() //constructor
{
	capacity = 10;
	numbers = new int[10];
	size = 0;
}
Vector::Vector(int newCapacity) //default constructor
{
	capacity = newCapacity;
	numbers = new int[newCapacity];
	size = 0;
}
Vector::Vector(const Vector&v)//copy constructor
{
	capacity = v.getCapacity();
	numbers = new int[v.getCapacity()];
	const int *n1 = v.getNumbers();
	for (int i = 0; i < v.getSize(); i++)
		numbers[i] = n1[i];
	size = v.getSize();
}
Vector::~Vector() //destructor
{
	if (size)
		delete[] numbers;
}
Vector Vector::operator =(const Vector & v)
{
	const int *n1 = v.getNumbers();
	setCapacity(v.getCapacity());
	for (int i = 0; i < v.getSize(); i++)
		numbers[i] = n1[i];
	size = v.getSize();
	return(*this);
}
bool Vector::operator==(const Vector & v)
{
	const int *n1 = v.getNumbers();
	if (v.getSize() != size)
		return false;
	for (int i = 0; i < size; i++)
		if (numbers[i] != n1[i])
			return false;
	return true;
}
int & Vector::operator[](int idx)
{
	if (idx >= 0 && idx <= size)
		return numbers[idx];
	else
	{
		cout << "ERROR\n";
	}
}
Vector Vector::operator +(const Vector& v)const
{
	const int *n1 = v.getNumbers();
	Vector c = *this;
	c.setCapacity(capacity + v.getCapacity());
	for (int i = 0; i < v.getSize(); i++)
		c.insert(n1[i]);
	return c;
}
int Vector::operator *(const Vector& v) const
{
	int sum = 0;
	const int *n1 = v.getNumbers();
	if (size == v.getSize())
	{
		Vector c(size);
		for (int i = 0; i < size; i++)
			sum += numbers[i] * n1[i];
		return sum;
	}
	else
	{
		cout << "ERROR\n";
		return -1000000000;
	}
}

void Vector::setCapacity(int newCapacity)
{
	if (size > newCapacity)
		return;
	capacity = newCapacity;
	int* n1 = new int[capacity];
	for (int i = 0; i < size; i++)
		n1[i] = numbers[i];
	if (size)
		delete[]numbers;
	numbers = n1;
}
int Vector::getCapacity()const
{
	return capacity;
}
int Vector::getSize()const
{
	return size;
}
const int* Vector::getNumbers()const
{
	return numbers;
}

void Vector::print()const
{
	cout << "capacity: " << capacity << " size: " << size << " val ";
	for (int i = 0; i < size; i++)
		cout << numbers[i] << " ";
	cout << endl;
}
void Vector::clear()
{
	if (size)
		delete[] numbers;
	size = 0;
}
void Vector::delLast()
{
	if (!size)
	{
		cout << "ERROR\n";
		return;
	}
	size--;
}
void Vector::insert(int val)
{
	{
		if (size == capacity)
		{
			cout << "ERROR\n";
			return;
		}
		size++;
		numbers[size - 1] = val;
	}
}