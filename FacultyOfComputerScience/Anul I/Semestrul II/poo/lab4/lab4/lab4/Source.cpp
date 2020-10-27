#include "Sort.h"
#include <iostream>
#include <time.h>
#include <string>
#include <sstream> 
using namespace std;

int main() {

	int b[4] = { 1, 3, 4, 5 };
	Sort p(8, 3, 40);
	Sort m(12);
	Sort a(b, 4);
	Sort s("12,13,56,73,84");
	p.Print(); 
	a.Print();
	s.Print();

	
	
	


}