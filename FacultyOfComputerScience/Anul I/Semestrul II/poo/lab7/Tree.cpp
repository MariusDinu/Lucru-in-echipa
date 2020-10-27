#include "Tree.h"
#pragma warning(disable:4996)
#include <string.h>

Tree::Tree()
{
	this->height = 0.f;
	this->isConifer = false;
}

Tree::Tree(const char* species, float height)
{
	this->species = new char[strlen(species)+1];
	strcpy(this->species, species);
	this->species[strlen(species)] = '\0';
	this->height = height;
}

Tree::Tree(float height)
{
	this->height = height;
}

Tree::Tree(float height, bool isConifer)
{
	this->height = height;
	this->isConifer = isConifer;
}

Tree::Tree(const char* species, float height, bool isConifer)
{
	this->species = new char[strlen(species) + 1];
	strcpy(this->species, species);
	this->species[strlen(species)] = '\0';
	this->height = height;
	this->isConifer = isConifer;
}

float Tree::getHeight()
{
	return this->height;
}

char* Tree::getSpecies()
{
	return this->species;
}
