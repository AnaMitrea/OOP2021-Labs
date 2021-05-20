#pragma once
#include <iostream>
using namespace std;

template <class K, class V>
class Map
{
	struct element
	{
		K key;
		V value;
		int index;		
	} *vec;
	int count;
	int max_size;

public:
	Map()
	{
		count = 0;
		max_size = 0;
		vec = NULL;
	}
	void reallocMem()
	{
		if (max_size == 0)
		{
			max_size++;
			vec = (element*)malloc(sizeof(element) * max_size);
		}
		else
		{
			max_size+=2;
			vec = (element*)realloc(vec, sizeof(element) * max_size);
		}
	}
	V& operator[] (const K KEY)
	{
		for (int i = 0; i < count; i++)
		{
			if (vec[i].key == KEY)
				return vec[i].value;
		}

		if (count == max_size)
		{
			reallocMem();
		}
		vec[count].index = count;
		vec[count].key = KEY;
		count++;
		return vec[count - 1].value;
	}
	void Set(K KEY, V val)
	{
		for (int i = 0; i < count; i++)
		{
			if (vec[i].key == KEY)
				vec[i].value = val;
		}
	}
	element* begin()
	{
		return &vec[0];
	}
	element* end()
	{
		return &vec[max_size];
	}
	bool Get(const K& Key, V& Value)
	{
		for (int i = 0; i < count; i++)
		{
			if (vec[i].key == Key)
			{
				Value = vec[i].value;
				return true;
			}
		}
		return false;
	}
	int Count()
	{
		return max_size;
	}
	void Clear()
	{
		for (int i = 0; i < count; i++)
		{
			vec[i].key = NULL;
			vec[i].value = NULL;
			vec[i].index = NULL;
		}
	}
	bool Delete(const K& Key)
	{
		for (int i = 0; i < count; i++)
		{
			if (vec[i].key == Key)
			{
				for (int j = i; j < count; j++)
				{
					vec[j] = vec[j + 1];
					vec[j].index--;
				}
				count--;
				max_size--;
				return true;
			}
		}
		return false;
	}
	void mapSort()
	{
		for (int i = 0; i < count; i++)
		{
			for (int j = i + 1; j < count; j++)
			{
				if (vec[i].key > vec[j].key)
				{
					element aux = vec[i];
					vec[i] = vec[j];
					vec[j] = aux;
				}
			}
		}
		for (int i = 0; i < count; i++)
		{
			vec[i].index = i;
		}
	}
	bool Includes(Map<K, V>& map)
	{
		//map.mapSort();
		int elemCount = 0;
		V aux;
		if (this->count > map.count) // caut in map-ul la care apelez functia
		{
			for (int i = 0; i < this->count; i++)
			{
				if (map.Get(vec[i].key, aux) == 1)
					elemCount++;
			}
			if (elemCount == map.count)
				return true;
			else
				return false;
		}
		else
		{
			for (int i = 0; i < map.count; i++)  // caut in map-ul trimis ca parametru
			{
				// caut pas cu pas cheia din map in this
				if (this->Get(map.vec[i].key, aux) == 1) 
					elemCount++;	
			}
			if (elemCount == this->count)
				return true;
			else
				return false;
		}
		
	}
};
