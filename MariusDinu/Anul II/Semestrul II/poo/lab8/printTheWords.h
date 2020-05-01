#pragma once

void printTheWords(priority_queue<pair<string, int>, vector<pair<string, int>>, CompareWords> &pqWords)
{

	while (pqWords.empty() == false)
	{
		cout << pqWords.top().first << " => ";
		cout << pqWords.top().second << endl;
		pqWords.pop();
	}

	cout << endl;
}