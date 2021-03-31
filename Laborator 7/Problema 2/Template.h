#pragma once
#include <iostream>
using namespace std;

template <class T>
class VectorTemplate
{
	int currentSize;
	int index;
	T* arr;
public:
	VectorTemplate();
	~VectorTemplate();
	void push(T variable);
	T pop();
	void remove(int position);
	void insert(T element, int position);
	//void sort() cu callback
	T* getElement(int position);
	void setElement(T element, int position);
	int countElements();
	// int firstIndexOf(T element, functia de callback)
	void Print();
};

template<class T>
VectorTemplate<T>::VectorTemplate()
{
	currentSize = 0;
	arr = new T[currentSize + 1];
	index = 0;
}

template<class T>
VectorTemplate<T>::~VectorTemplate()
{
	delete[] arr;
	arr = 0;
}

template<class T>
void VectorTemplate<T>::push(T variable) // la sf vect
{
	// trebuie sa fac realocare de memorie cu inca o pozitie pt push
	currentSize++;
	arr = (T*)realloc(arr, currentSize);
	arr[index] = variable;
	index++;
}

template<class T>
T VectorTemplate<T>::pop()
{
	return arr[currentSize - 1];
}

template<class T>
void VectorTemplate<T>::remove(int position)
{
	for (int i = position; i < currentSize; i++)
	{
		arr[i] = arr[i + 1];
	}
	currentSize--;
	arr = (T*)realloc(arr, currentSize);
}

template<class T>
void VectorTemplate<T>::insert(T element, int position)
{
	currentSize++;
	arr = (T*)realloc(arr, currentSize);
	for (int i = currentSize; i > position; i--)
	{
		arr[i] = arr[i - 1];
	}
	arr[position] = element;
}

template<class T>
T* VectorTemplate<T>::getElement(int position)
{
	return &arr[position];
}

template<class T>
void VectorTemplate<T>::setElement(T element, int position)
{
	arr[position] = element;
}

template<class T>
int VectorTemplate<T>::countElements()
{
	return currentSize;
}

template<class T>
void VectorTemplate<T>::Print()
{
	cout << "The array is: ";
	for (int i = 0; i < currentSize; i++)
	{
		cout << arr[i] << ' ';
	}
	cout << endl;
}
