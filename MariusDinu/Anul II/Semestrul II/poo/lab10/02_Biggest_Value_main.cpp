#include <list>
#include <iostream>

using namespace std;


int main()
{
	list<int> listOfNumbers = { 0, 3, 9, -29, -6, 34, 1, 55, 99, 56};
	list<int>::iterator it;
	it = listOfNumbers.begin();
	int biggestNumber=*it;

	auto result = [&, biggestNumber]() mutable
	{
		for (it = (++listOfNumbers.begin()); it != listOfNumbers.end(); it++)
		{
			if (biggestNumber < (*it))
			{
				biggestNumber = (*it);
			}
		}
		return biggestNumber;
	};

	biggestNumber = result();

	cout << "Biggest number: " << biggestNumber<<endl;
	return 0;
}