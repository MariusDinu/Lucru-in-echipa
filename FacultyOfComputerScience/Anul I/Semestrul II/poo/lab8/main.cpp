#include "readSentenceFromFile.h"
#include "addWordsToPriorityQueue.h"
#include "printTheWords.h"
#include "CompareWords.h"

using namespace std;

int main()
{
	map<string, int> Words;
	
	//priority_queue<pair<string, int>, vector<pair<string, int>>, CompareWords> pqWords;

	readSentenceFromFile(Words);

	//addWordsToPriorityQueue(Words, pqWords);

	//printTheWords(pqWords);

	return 0;
}