#pragma once
#include <iostream>
#include <stdlib.h>
using namespace std;

template<typename T>
bool comparator1(T nr1, T nr2)
{
	if (nr1 < nr2)
		return true;
	return false;
}

template<typename T>
bool comparator2(T nr1, T nr2)
{
	if (nr1 > nr2)
		return true;
	return false;
}

template<typename T>
bool equal(T nr1, T nr2)
{
	if (nr1 == nr2)
		return true;
	return false;
}

template <class T>
class VectorTemplate
{
	int currentSize;
	T* arr;
public:
	VectorTemplate();
	~VectorTemplate();
	void push(T variable);
	T pop();
	void remove(int position);
	void insert(T element, int position);
	T* getElement(int position);
	void setElement(T element, int position);
	int countElements();
	void sort(bool (*callback)(T, T));
	void firstIndexOf(T element, bool (*callback)(T, T));
	void Print();
};

template<class T>
inline VectorTemplate<T>::VectorTemplate()
{
	currentSize = 0;
	arr = (T*)(malloc(currentSize * sizeof(T)));
}

template<class T>
inline VectorTemplate<T>::~VectorTemplate()
{
	free(arr);
	/*
	* sau
	* delete[] ar;;
	* arr = nullptr;
	*/
}

template<class T>
inline void VectorTemplate<T>::push(T variable) // la sf vect
{
	//realocare de memorie cu inca o pozitie pt push
	/*
	currentSize++;
	arr = (T*)(malloc(currentSize * sizeof(T)));
	arr[currentSize++] = variable;
	arr = (T*)(realloc(arr, currentSize * sizeof(T)));
	*/
	if (currentSize == 0)
	{
		arr = (T*)(malloc(1 * sizeof(T)));
		arr[currentSize] = variable;
		currentSize++;
	}
	else
	{
		arr = (T*)(realloc(arr, (currentSize + 1) * sizeof(T)));
		arr[currentSize] = variable;
		currentSize++;
	}
}

template<class T>
inline T VectorTemplate<T>::pop()
{
	return arr[currentSize - 1];
}

template<class T>
inline void VectorTemplate<T>::remove(int position)
{
	for (int i = position; i < currentSize - 1; i++)
	{
		arr[i] = arr[i + 1];
	}
	currentSize--;
	arr = (T*)realloc(arr, currentSize * sizeof(T));
}

template<class T>
inline void VectorTemplate<T>::insert(T element, int position)
{
	currentSize++;
	arr = (T*)realloc(arr, (currentSize + 1) * sizeof(T));
	for (int i = currentSize; i > position; i--)
	{
		arr[i] = arr[i - 1];
	}
	arr[position] = element;
}

template<class T>
inline T* VectorTemplate<T>::getElement(int position)
{
	return &arr[position];
}

template<class T>
inline void VectorTemplate<T>::setElement(T element, int position)
{
	arr[position] = element;
}

template<class T>
inline int VectorTemplate<T>::countElements()
{
	return currentSize;
}

template<class T>
inline void VectorTemplate<T>::sort(bool(*callback)(T, T))
{
	for (int i = 0; i < currentSize - 1; i++)
	{
		for (int j = i + 1; j < currentSize; j++)
		{
			if (callback == nullptr)
			{
				if (arr[i] < arr[j])
				{
					T aux = arr[i];
					arr[i] = arr[j];
					arr[j] = aux;
				}
			}
			else
			{
				if (callback(arr[i], arr[j]))
				{
					T aux = arr[i];
					arr[i] = arr[j];
					arr[j] = aux;
				}
			}
		}
	}
}

template<class T>
inline void VectorTemplate<T>::firstIndexOf(T element, bool (*callback)(T, T))
{
	bool found = false;
	for (int i = 0; i < currentSize; i++)
	{
		if (callback == nullptr)
		{
			if (arr[i] == element)
			{
				cout << "First index of element " << element << " is " << i << endl;
				found = true;
				break;
			}
		}
		else
		{
			if (callback(arr[i], element))
			{
				cout << "First index of element " << element << " is " << i << endl;
				found = true;
				break;
			}
		}
	}
	if (found == false)
		cout << "Element " << element << " was not found in the array!" << endl;
}

template<class T>
inline void VectorTemplate<T>::Print()
{
	cout << "The array is: ";
	for (int i = 0; i < currentSize; i++)
	{
		cout << arr[i] << ' ';
	}
	cout << endl;
}