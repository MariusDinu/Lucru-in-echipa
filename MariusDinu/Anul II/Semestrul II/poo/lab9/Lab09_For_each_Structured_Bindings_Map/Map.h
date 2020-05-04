#pragma once
#include "Pair.h"

template <class K, class V>

class Map
{
public:
	Pair<K, V> p_vector[100];
	
	int lastIndex = -1;


	V& operator[](K key)
	{

		if (lastIndex >= 0)
		{
			for (int index = 0; index <= lastIndex; index++)
			{
				if (p_vector[index].key == key)
					return p_vector[index].value;
			}
		}
		lastIndex++;
		p_vector[lastIndex].pair_Index = lastIndex;
		this->p_vector[lastIndex].key = key;
		return p_vector[lastIndex].value;
	}



	Pair<K, V>* begin() { return &p_vector[0]; }
	Pair<K, V>* end() { return &p_vector[lastIndex + 1]; }

	void Set(V value, K key)
	{
		bool isFind = false;
		if (lastIndex >= 0)
		{
			for (int index = 0; index <= lastIndex; index++)
			{
				if (p_vector[index].key == key)
				{
					V* ptr = &(this->p_vector[index].value);
					*ptr = value;			//se asociaza unei chei existente alta valoare
					
					isFind = true;
				
				}
					
			}
		}

		if(isFind==false)
		{
			lastIndex++;
			p_vector[lastIndex].pair_Index = lastIndex;
			this->p_vector[lastIndex].key = key;
			this->p_vector[lastIndex].value = value;
		}
		
	}

	bool Get(const K& key, V value)
	{
		bool isFind = false;
		int index = 0;
		if (lastIndex >= 0)
		{
			while(isFind!=true && index<=lastIndex)
			{
			
				if (p_vector[index].key == key)
				{
					V* ptr = &(this->p_vector[index].value);
					*ptr = value;			
					isFind = true;
				}

				index++;
			}
		}
		
		return isFind;
	}

	int Count()
	{
		return (lastIndex + 1);
	}
	
	void Clear()
	{
		for (int index = 0; index <= lastIndex; index++)
		{
			V* ptr = &(this->p_vector[index].value);
			*ptr = nullptr;

			this->p_vector[index].key = 0;
		}
		
		lastIndex = -1;
	}

	bool Delete(const K& key)
	{
		bool isFind = false;
		int index = 0;
		V nextValue;
		V* ptr = nullptr;
		K nextKey;

		if (lastIndex >= 0)
		{
			while (isFind != true && index <= lastIndex)
			{

				if (p_vector[index].key == key)
				{
					for (int anotherIndex = index; anotherIndex <= index; anotherIndex++)
					{
						nextValue = this->p_vector[anotherIndex+1].value;
						ptr = &(this->p_vector[anotherIndex].value);
						*ptr = nextValue;
						nextKey = this->p_vector[anotherIndex + 1].key;
						this->p_vector[anotherIndex].key = nextKey;
						this->p_vector[anotherIndex].pair_Index = anotherIndex;
					}
					


					isFind = true;
				}

				index++;
			}
		}
		
		if (isFind == true)
		{
			ptr = &(this->p_vector[lastIndex].value);
			*ptr = nullptr;
			this->p_vector[lastIndex].key = 0;

			lastIndex--;
		}
		

		return isFind;
	}

	bool Includes(const Map<K, V>& map)
	{
		bool isFind;

		if (map.lastIndex > this->lastIndex)
			return false;

		for (int indexOfmap = 0; indexOfmap <= map.lastIndex; indexOfmap++)
		{
			isFind = false;
			for (int index = 0; index <= this->lastIndex; index++)
			{
				if (map.p_vector[indexOfmap].key == this->p_vector[index].key)
					isFind = true;
			}
			if (isFind == false)
				return false;
		}

		return true;
	}

};