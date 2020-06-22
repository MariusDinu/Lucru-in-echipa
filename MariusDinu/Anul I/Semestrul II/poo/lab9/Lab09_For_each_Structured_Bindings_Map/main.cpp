#include "Map.h"
#include <stdio.h>
#include <iostream>

using namespace std;

int main()
{
	Map<int, const char*> m;
	m[10] = "C++";
	m[20] = "test";
	m[30] = "Poo";


	for (auto [key, value, index] : m)
	{
		printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
	}

	m[20] = "result";

	for (auto [key, value, index] : m)
	{
		printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
	}

										//dupa codul din laborator
	m.Set("another result", 30);		//cheii 30 i se asociaza valoarea "another result"
	
	m.Delete(20); //se sterge cheia 20

	printf("\nAfter delete 20:\n");
	for (auto [key, value, index] : m)
	{
		printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
	}

	m.Get(20, "result 2");

	printf("\n");
	for (auto [key, value, index] : m)
	{
		printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
	}

	printf("\nExists key 50? %d\n", m.Get(50, "result 2"));

	printf("Number of elements in Map is: %d\n", m.Count());

	m.Clear();
	printf("After clear method:\n\n");
	for (auto [key, value, index] : m)
	{
		printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
	}

	
	printf("After new values:\n");
	m[10]="zece";
	m[20] = "douazeci";
	m[30] = "treizeci";
	m[40] = "patruzeci";

	for (auto [key, value, index] : m)
	{
		printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
	}

	

	//se creeaza un alt obiect de tip Map
	
	Map<int, const char*> m1;

	m1[10] = "zece";
	m1[30] = "treizeci";

	printf("\nm1 is included in m: %d", m.Includes(m1));

	Map<int, const char*> m2;
	m2[23] = "douazeci si trei";
	m2[10] = "zece";

	printf("\nm2 is included in m: %d", m.Includes(m2));
	return 0;
}