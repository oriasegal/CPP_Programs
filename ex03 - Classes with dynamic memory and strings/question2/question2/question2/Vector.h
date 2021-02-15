#pragma once
class Vector
{
private:
	int *numbers;
	int size;
	int capacity;
	int error;
public:

	Vector(); //constructor
	Vector(int); //default constructor

	Vector(const Vector&v);  //copy constructor
	~Vector(); //destructor

	Vector operator =(const Vector & V);
	bool operator==(const Vector & v);
	int & operator[](int idx);
	Vector operator +(const Vector& v)const;
	int operator *(const Vector& v) const;

	void setCapacity(int newCapacity);
	int getCapacity()const;
	int getSize()const;
	const int* getNumbers()const;

	void print()const;
	void clear();
	void delLast();
	void insert(int val);
};