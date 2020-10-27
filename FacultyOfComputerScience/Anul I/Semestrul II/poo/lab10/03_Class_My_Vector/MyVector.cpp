#include "MyVector.h"
#include <iostream>

using namespace std;

bool MyVector::Add(int value)
{
	if (size < 100)
	{
		this->values[size] = value;
		this->size++;
		return true;
	}
	else 
		return false;
}

bool MyVector::Delete(int index)
{
	if (size > 0 && (index>=0 &&index<size))
	{
		for (int i = index; i<this->size-1; i++)
		{
			this->values[i] = this->values[i + 1];
		}

		this->size--;
		return true;
	}
	else
		return false;
}

void MyVector::Print()
{
	for (int index = 0; index < this->size; index++)
		cout << values[index] << endl;
	cout << endl;
}

void MyVector::Iterate(void (*Change)(int& x))
{
	for (int index = 0; index < this->size; index++)
		 Change(this->values[index]);
}

void MyVector::Filter(bool (*Match)(int value))
{
	for (int index = 0; index < this->size; index++)
	{
		if (Match(this->values[index]))
			Delete(index);
	}
}

MyVector::~MyVector()
{
	delete values;
}