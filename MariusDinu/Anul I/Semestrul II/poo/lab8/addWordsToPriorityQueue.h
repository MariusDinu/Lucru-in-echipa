#pragma once
#include "CompareWords.h"
#include <queue>

void addWordsToPriorityQueue(map<string, int>& Words, priority_queue<pair<string, int>, vector<pair<string, int>>, CompareWords> &pqWords)
{
	map<string, int>::iterator it;

	for (it = Words.begin(); it != Words.end(); it++)
	{
		pair<string, int> strPair(it->first, it->second);
		pqWords.push(strPair);
	}

	
}