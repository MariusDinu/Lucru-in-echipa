#pragma once
#include <map>
#include <utility>
#include <fstream>
#include <iostream>
#include <set>


using namespace std;

void readSentenceFromFile(map<string, int>& Words)
{

	fstream fileStream;
	fileStream.open("D:\programe\visual studio space-work\lab8\text.txt", ios::out | ios::in); //se deschide fisierul "text.txt" pentru scriere si citire

	streamoff position;  //se poate utiliza si long long ca tip de date

	string str;		//se creeaza un sir vid
	char ch;
	set<char> separators = {' ', ',', '?', '!', '.' }; 
	map<string, int>::iterator it;

	while (fileStream.get(ch))
	{
		if (separators.count(ch) == 0)
		{
			str.push_back((char)tolower(ch)); //se construieste caracter cu caracter sirul de caractere
		}
		else
		{	
			while (fileStream.get(ch) && separators.count(ch)); // se abordeaza cazul in care exista mai multi separatori consecutivi in text
			position = fileStream.tellp();
			fileStream.seekp(position - 1); //se schimba pozitia cursorului din fisieul text cu o pozitie in urma

			if (Words.count(str) == 0)
			{
				Words[str] = 1;
			}
			else
				Words[str] += 1;

			str.erase();
		}

	}
	

	fileStream.close();

}