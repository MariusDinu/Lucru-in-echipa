#pragma once

class Tree
{
private:
	float height;
	bool isConifer=false;
	char* species = nullptr;
public:
	Tree();
	Tree(const char*, float);
	Tree(const char*, float, bool);
	Tree(float);
	Tree(float, bool);
	float getHeight();
	char* getSpecies();
};