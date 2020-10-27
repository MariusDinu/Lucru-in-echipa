#include "Sort.h"
#include <iostream>
#include <time.h>
#include <cstdarg> // in order to use va_start va_end macros
#include <string>
#include <sstream> 




Sort::Sort(int numberElements, int minValue, int maxValue) {
	//make a list of random numbers
	int randomNumber;
	srand((unsigned)time(0));
	for (int i = 0; i < numberElements; ++i) {
		randomNumber = (rand() % maxValue) + minValue;
		Node* newnode = new Node();
		newnode->data = randomNumber;
		newnode->next = NULL;
		if (head == NULL) {
			head = newnode;
		}
		else {
			Node* temp = head; // head is not NULL
			while (temp->next != NULL) {
				temp = temp->next; // go to end of list
			}
			temp->next = newnode;
		}
	}

}

Sort::Sort(int numberArray[], int sizeArray) { //create list using numbers from vector
	for (int i = 0; i < sizeArray; ++i) {
		Node* newnode = new Node();
		newnode->data = numberArray[i];
		newnode->next = NULL;
		if (head == NULL) {
			head = newnode;
		}
		else {
			Node* temp = head; // head is not NULL
			while (temp->next != NULL) {
				temp = temp->next; // go to end of list
			}
			temp->next = newnode;
		}
	}
}

Sort::Sort(int count, ...) { //create list using variadic paramethers
	va_list vl;
	va_start(vl, count);
	int val;
	for (int i = 0; i < count; ++i) {
		val = va_arg(vl, int);

		Node* newnode = new Node();
		newnode->data = val;
		newnode->next = NULL;
		if (head == NULL) {
			head = newnode;
		}
		else {
			Node* temp = head; // head is not NULL
			while (temp->next != NULL) {
				temp = temp->next; // go to end of list
			}
			temp->next = newnode;
		}
	}
	va_end(vl);
}

Sort::Sort(string stringList) {
	char delimiter = ',';
	string acc = "";
	
	for (int i = 0; i < stringList.size(); ++i) {
		if (stringList[i] == delimiter) {
			stringstream numberConverted(acc);
			int x = 0;
			numberConverted >> x;
			//will add x to list
			Node* newnode = new Node();
			newnode->data = x;
			newnode->next = NULL;
			if (head == NULL) {
				head = newnode;
			}
			else {
				Node* temp = head; // head is not NULL
				while (temp->next != NULL) {
					temp = temp->next; // go to end of list
				}
				temp->next = newnode;
			}
			acc = "";
		}
		else { //just traversing the string
			acc += stringList[i];
		}

	}

	//the code above won't get the last number char from string. we get it ourself
	string lastChar = stringList.substr(stringList.size() - 1, stringList.size() - 1);
	stringstream lastNumber(acc); //converting string to int
	int b = 0;
	lastNumber >> b;
	Node* newnode = new Node();
	newnode->data = b;
	newnode->next = NULL;
	Node* temp = head; // head is not NULL
	while (temp->next != NULL) {
		temp = temp->next; // go to end of list
	}
	temp->next = newnode;

}

void Sort::InsertSort(bool ascendent) {
}

void Sort::QuickSort(bool ascendent)
{
}


void swap_values(Node* node_1, Node* node_2) {
	int temp = node_1->data;
	node_1->data = node_2->data;
	node_2->data = temp;
}

void Sort::BubbleSort(bool ascendent) {
	if (ascendent == true) {
		int swapped;
		Node* leftPointer; // left pointer will always point to the start of the list
		Node* rightPointer = NULL; // right pointer will always point to the end of the list
		do {
			swapped = 0;
			leftPointer = head;
			while (leftPointer->next != rightPointer) {
				if (leftPointer->data > leftPointer->next->data) {
					swap_values(leftPointer, leftPointer->next);
					swapped = 1;
				}
				leftPointer = leftPointer->next;
			}
			rightPointer = leftPointer;

		} while (swapped);
	}
	else { //case when ascendant is false, sort in descendent order
		int swapped;
		Node* leftPointer; // left pointer will always point to the start of the list
		Node* rightPointer = NULL; // right pointer will always point to the end of the list
		do {
			swapped = 0;
			leftPointer = head;
			while (leftPointer->next != rightPointer) {
				if (leftPointer->data < leftPointer->next->data) {
					swap_values(leftPointer, leftPointer->next);
					swapped = 1;
				}
				leftPointer = leftPointer->next;
			}
			rightPointer = leftPointer;

		} while (swapped);
	}
}

void Sort::Print() {
	if (head == NULL) {
		cout << "Nu sunt elemente in lista." << endl;
	}
	else {
		
		while (head != NULL) {
			cout << head->data << " ";
			head = head->next;
		}
		cout << endl;
	}
}

int Sort::GetElementsCount() {
	int count = 0;
	if (head == NULL) {
		return count;
	}
	else {
		Node* temp = head;
		while (temp != NULL) {
			++count;
			temp = temp->next;
		}
	}
	return count;
}

int Sort::GetElementFromIndex(int index) {
	if (index > GetElementsCount()) {
		return 0;
	}
	int numberToBeReturned;
	int listIndex = 0;
	if (head == NULL) {
		return 0;
	}
	else {
		Node* temp = head;
		while (temp != NULL) {
			++listIndex;
			if (listIndex == index) {
				numberToBeReturned = temp->data;
			}
			temp = temp->next;
		}
	}
	return numberToBeReturned;
}