#include <string>
#include <vector>
#include <iostream>
#include <functional>
using namespace std;

//prototipul functiei Sort
void Sort(vector<string>&, function<bool(string, string)>&);


int main() {
	vector<string> words = {"The", "future", "is", "not", "set","There", "is", "no", "fate", "but","we", "make", "for", "ourselves", "John", "Connor"};
	vector<string>::iterator it;
	
	for (it = words.begin(); it<words.end(); it++)
	{
		cout << *it << endl;
	}

	function<bool(string, string)> CmpFunction;
	
	CmpFunction = [](string s1, string s2)->bool
	{
		if (s1.length() > s2.length())
		{
			return true;
		}
		else if (s1.length() == s2.length())
		{
			if (s1 > s2)
				return true;
			else
				return false;
		}
		else 
			return false;
	};

	
	cout << endl;
	
	//Apelul functiei de sortare
	Sort(words, CmpFunction);

	for (it = words.begin(); it < words.end(); it++)
	{
		cout << *it << endl;
	}

	return 0;
}

void Sort(vector<string>& v, function<bool(string, string)>& compareFunction){
	string aux;
	unsigned int k = 0;
	for (unsigned int i = 0; i < v.size() - 1; i++)
	{
		for (unsigned int j = 0; j < v.size() - 1 - k; j++)
		{
			if (compareFunction(v[j], v[j + 1]))
			{
				aux = v[j];
				v[j] = v[j + 1];
				v[j + 1] = aux;
			}
		}
		k++;
	}
}