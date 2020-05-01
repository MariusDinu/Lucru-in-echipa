#include "Vector.h"
#include <iostream>
#include <stdlib.h>
using namespace std;

int main()
{
	cout << "Aici am apelat metoda push\n";
	Vector<int> t;
	for (int index = 0; index < 5; index++)
	{
		t.push(rand()%100);
	}

	t.print();
	cout<<"returnez ultm elm "<<t.pop()<<endl;
	t.remove(3);
	cout << "After remove\n";
	t.print();
	t.insert(2000, 2);
	cout << "After insertion\n";
	t.print();
	bool (*fptr)(int, int) = &(Vector<int>::isSmaller);
	t.sort(fptr);
	cout<<"After sort\n";
	t.print();
	int index = 4;
    cout<<"Elementul de la indexul "<<index<<" este "<<t.get(index)<<endl;
	cout << "Numarul de elemente din vector este " << t.count() << endl;

	Vector<Tree> vtrees;
	Tree t1(4.1, true), t2("willow", 3.f), t3("apple tree", 2.5f), t0(1.f), t5("Xmas Tree", 3.2, true);

	vtrees.push(t1);
	vtrees.push(t2);
	vtrees.push(t3);
	vtrees.push(t0);
	vtrees.push(t5);
	
	cout << endl;
	cout << "Sortare dupa inaltime descendent :" << endl;
	bool (*ptr)(Tree, Tree) = &(Vector<Tree>::isSmaller);
	vtrees.sort(ptr);
	vtrees.print();
	cout << endl;
	cout << "Sortare dupa lungimea denumirii speciei:" << endl;

	bool (*newptr)(Tree, Tree) = &(Vector<Tree>::isLengthOfTheSpeciesNameLarger);
	vtrees.sort(newptr);
	vtrees.print();

	bool (*newptr1)(Tree, Tree) = &(Vector<Tree>::isEqual);
	cout<<"\nPrima aparitie a lui t5 (Xmas Tree) este la indexul:"<<vtrees.firstIndexOf(t5, newptr1)<<endl;

	
	return 0;
}