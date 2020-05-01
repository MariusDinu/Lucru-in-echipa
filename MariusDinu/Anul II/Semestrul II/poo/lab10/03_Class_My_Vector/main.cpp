#include <iostream>
#include "MyVector.h"
using namespace std;

int main()
{
	MyVector mVec;
	mVec.Add(90);
	mVec.Add(-34);
	mVec.Add(3);
	mVec.Add(34);
	mVec.Add(-42);
	mVec.Add(12);
	mVec.Add(-2);
	mVec.Add(123);
	mVec.Print();
	

	auto Change = [](int& x) mutable 
	{
		x = 2 * x + 5;
	};

	auto Match = [](int value)
	{
		return (value % 3) == 0;
	};

	
	mVec.Filter(Match);
	cout << "After filtration:" << endl;
	mVec.Print();

	mVec.Iterate(Change);
	cout << "After the change:" << endl;
	mVec.Print();

	

	return 0;
}