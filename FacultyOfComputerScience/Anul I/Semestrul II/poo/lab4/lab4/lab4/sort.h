#pragma once
#include <string>
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
};

class Sort {
private:
    Node* head;
public:
    Sort(int numberElements, int minValue, int maxValue);
    Sort(int numberArray[], int sizeArray); //create list using numbers from vector
    Sort(int count, ...); //create list using variadic parameters
    Sort(string stringList); //cream lista folosind string 
    // add constuctors
    void InsertSort(bool ascendent = false);
    void QuickSort(bool ascendent = false);
    void BubbleSort(bool ascendent = false);
    void Print();
    int  GetElementsCount();
    int  GetElementFromIndex(int index);
};



