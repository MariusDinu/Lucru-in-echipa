#pragma once
#include <stdio.h>
#include <string.h>
#include "Tree.h"
template <class T>

class Vector
{
private:
	T *v = nullptr;
	int length = 0, lastIndex = -1;

public:

	void push(T value)
	{
		resizeAllocatedSpace();
		lastIndex++;
		v[lastIndex] = value;
	}
	
	T pop()
	{
		return v[lastIndex];
	}

	void remove(int index)
	{
		for (int i = index; i < lastIndex; i++)
			v[i] = v[i + 1];
		lastIndex--;
	}

	void insert(T value, int index)
	{
		resizeAllocatedSpace();
		for (int i = lastIndex + 1; i > index; i--)
			v[i] = v[i - 1];

		lastIndex++;
		v[index] = value;
	}

	void resizeAllocatedSpace()
	{
		if (length == 0)
		{
			length = 1;
			v = new T[length];
		}
		else if (length - 1 <= lastIndex)
		{
			length *= 2;
			T* newptr = new T[length];

			for (int index = 0; index <= lastIndex; index++)
				newptr[index] = v[index];

			delete[] v;
			v = newptr;
		}
	}

	static bool isGreater(T x, T y)
	{
		return (x > y);
	}

	static bool isSmaller(T x, T y)
	{
		return (x < y);
	}

	void sort(bool (*fptr)(T, T))
	{
		T aux;
		unsigned int k = 0;

		for (int i = 0; i <= this->lastIndex; i++)
		{
			for(int j = 1; j <= this->lastIndex - k; j++)
			{
				if ((*fptr)(v[j-1], v[j]))  //compare(v[j-1], v[j])
				{
					aux = v[j - 1];
					v[j - 1] = v[j];
					v[j] = aux;
				}
			}
			k++;
		}
	}

	const T& get(int index)
	{
		return v[index];
	}

	int count()
	{
		return (lastIndex + 1);
	}

	void print()
	{
		for (int index = 0; index <= lastIndex; index++)
		{
			printf("v[%d]=", index);
			printf("%d\n", v[index]);
		}
	}

};
 
//functia templet
template<>
class Vector <Tree>
{
private:
	Tree* v = nullptr;
	int length = 0, lastIndex = -1;
public:

	void push(Tree value)
	{
		resizeAllocatedSpace();
		lastIndex++;
		v[lastIndex] = value;
	}

	Tree pop()
	{
		return v[lastIndex];
	}

	void remove(int index)
	{
		for (int i = index; i < lastIndex; i++)
			v[i] = v[i + 1];
		lastIndex--;
	}

	void insert(Tree value, int index)
	{
		resizeAllocatedSpace();
		for (int i = lastIndex + 1; i > index; i--)
			v[i] = v[i - 1];

		lastIndex++;
		v[index] = value;
	}

	void resizeAllocatedSpace()
	{
		if (length == 0)
		{
			length = 1;
			v = new Tree[length];
		}
		else if (length - 1 <= lastIndex)
		{
			length *= 2;
			Tree* newptr = new Tree[length];

			for (int index = 0; index <= lastIndex; index++)
				newptr[index] = v[index];

			delete[] v;
			v = newptr;
		}
	}

	static bool isSmaller(Tree x, Tree y)
	{

		return (x.getHeight() < y.getHeight());
	}

	static bool isGreater(Tree x, Tree y)
	{

		return (x.getHeight() > y.getHeight());
	}

	static bool isLengthOfTheSpeciesNameLarger(Tree x, Tree y)
	{
		int lengthOfx;
		int lengthOfy;
		if (x.getSpecies() == nullptr)
			lengthOfx = 0;
		else
			lengthOfx = strlen(x.getSpecies());

		if (y.getSpecies() == nullptr)
			lengthOfy = 0;
		else
			lengthOfy = strlen(y.getSpecies());

		return (lengthOfx > lengthOfy);
	}

	void sort(bool (*fptr)(Tree, Tree))
	{
		Tree aux;
		unsigned int k = 0;

		for (int i = 0; i <= this->lastIndex; i++)
		{
			for (int j = 1; j <= this->lastIndex - k; j++)
			{
				if ((*fptr)(v[j - 1], v[j]))  //compare(v[j-1], v[j])
				{
					aux = v[j - 1];
					v[j - 1] = v[j];
					v[j] = aux;
				}
			}
			k++;
		}
	}

	static bool isEqual(Tree x, Tree y)
	{
		int lengthOfx, lengthOfy;
		if (x.getSpecies() == nullptr)
			lengthOfx = 0;
		else
			lengthOfx = strlen(x.getSpecies());

		if (y.getSpecies() == nullptr)
			lengthOfy = 0;
		else
			lengthOfy = strlen(y.getSpecies());

		if ((lengthOfx!=lengthOfy) || (x.getHeight()!=x.getHeight()))
			return false;
		return true;
	}

	int firstIndexOf(Tree t, bool (*fptr)(Tree, Tree))
	{
		for (unsigned index=0; index <= lastIndex; index++)
			if (isEqual(t, v[index]))
				return index;
		return -1;
	}

	const Tree& get(int index)
	{
		return v[index];
	}


	void print()
	{
		for (int index = 0; index <= lastIndex; index++)
		{

			printf("v[%d]=", index);
			printf(" %f ", v[index].getHeight());
			printf(" %s\n", v[index].getSpecies());
		}
	}
};