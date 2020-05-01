#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Canvas.h"
#include "Math.h"
using namespace std;

int main() {

	/*Math a;
	cout << a.Add(2 , 4)<<endl;
	cout << a.Add(2 , 4 , 4) << endl;
	cout << a.Add(2.5 , 4.7) << endl;
	cout << a.Add(3.2,5.8 ,6.0) << endl;
	cout << a.Mul(2 , 4) << endl;
	cout << a.Mul(2 ,(int)4.0 , 6) << endl;
	cout << a.Mul(2.7, 4.3) << endl;
	cout << a.Mul(5.4, 4.7, 6.2) << endl;
	cout << a.Add(8, 1, 2, 3, 4, 5, 6, 7, 8) << endl;
	cout << a.Add("Ana ", "are mere") << endl;
	*/
	 Canvas desen(15, 15);
	 //desen.DrawCircle(5,5,3,'b');
	//desen.FillCircle(3, 3, 3, 'b'); 
	desen.DrawRect(4, 2, 10, 5, 'a');
	//desen.FillRect(4, 2, 10, 5, 'a');
	//desen.SetPoint(3, 4, 'a');
	//desen.DrawLine(3, 3, 6, 3, 'a');
	desen.Print();
	//desen.Clear();
	return 0;



}
