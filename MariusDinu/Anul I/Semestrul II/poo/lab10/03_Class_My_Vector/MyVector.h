#pragma once

class MyVector
{
private:
	//alocare dinamica de memorie
	int* values = new int[100];
	int size=0;
public:

	bool Add(int);
	bool Delete(int index);

	void Iterate(void (*Change)(int& x));
	void Filter(bool (*Match)(int value));

	void Print();
	
	~MyVector();
};