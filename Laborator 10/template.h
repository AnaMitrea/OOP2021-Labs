#pragma once
#include <iostream>
#include <exception>
using namespace std;

class excp_OutOfRange : public exception
{
	virtual const char* what() const throw()
	{
		return "Index out of range!";
	}
};

class excp_InvalidIndex : public exception
{
	virtual const char* what() const throw()
	{
		return "Invalid Index!";
	}
};

class Compare
{
public:
	virtual int CompareElements(void* e1, void* e2) = 0;
};

template<class T>
class ArrayIterator
{
public:
	T* Current;
	T operator*()
	{
		return *Current;
	}
	ArrayIterator& operator ++ ()
	{
		Current++;
		return *this;
	}
	ArrayIterator& operator -- ()
	{
		Current--;
		return *this;
	}
	bool operator= (ArrayIterator<T>& obj)
	{
		return (Current == obj.Current);
	}
	bool operator!=(ArrayIterator<T>& obj)
	{
		return (Current != obj.Current);
	}
};

template<class T>
class Array
{
private:
	T** List; // lista cu pointeri la obiecte de tipul T*
	int Capacity; // dimensiunea listei de pointeri
	int Size; // cate elemente sunt in lista
public:
	Array() // Lista nu e alocata, Capacity si Size = 0
	{
		Capacity = 0;
		Size = 0;
	}
	~Array() // destructor
	{
		for (int i = 0; i < Size; i++)
			delete List[i];
		delete[] List;
	}
	Array(int capacity) // Lista e alocata cu 'capacity' elemente
	{
		if (Size == 0)
		{
			List = (T**)malloc(sizeof(T*) * capacity);
		}
		else
		{
			List = (T**)realloc(List, sizeof(T*) * capacity);
		}
	}
	Array(const Array<T>& otherArray) // constructor de copiere
	{
		Capacity = otherArray.Capacity;
		Size = otherArray.Size;
		List = (T**)malloc(sizeof(T*) * Capacity);

		for (int i = 0; i < Size; i++)
			List[i] = otherArray.List[i];
	}
	
	T& operator[] (int index) // arunca exceptie daca index este out of range
	{
		try
		{
			excp_OutOfRange excp;
			if (index > Capacity || index < 0)
				throw excp;
			return List[index];
		}
		catch(exception& e)
		{
			cout << "Exception: " << e.what() << endl;
		}
	}

	const Array<T>& operator+=(const T& newElem) // adauga un element de tipul T la sfarsitul listei si returneaza this
	{
		if (Size < Capacity)
		{
			List[Size++] = newElem;
		}
		else
		{
			Capacity++;
			List = (T**)realloc(List, sizeof(T*) * Capacity);
			List[Size++] = newElem;
		}
		return *this;
	}
	const Array<T>& Insert(int index, const T& newElem) // adauga un element pe pozitia index, retureaza this. Daca index e invalid arunca o exceptie
	{
		try
		{
			excp_InvalidIndex excp;
			if (index > Capacity)
				throw excp;
			if (Size >= Capacity)
			{
				Capacity++;
				List = (T**)realloc(List, sizeof(T*) * Capacity);
			}
			for (int i = Size; i >= index; i--)
			{
				List[i + 1] = List[i];
			}
			List[index] = newElem;
			Size++;
			return *this;
		}
		catch (exception& e)
		{
			cout << "Exception: " << e.what() << endl;
		}
	}
	const Array<T>& Delete(int index) // sterge un element de pe pozitia index, returneaza this. Daca index e invalid arunca o exceptie
	{
		try 
		{
			excp_InvalidIndex excp;
			if (index > Size || index < 0)
				throw excp;
			for (int i = index; i < Size; i++)
				List[i] = List[i + 1];
			Size--;
			return *this;
		}
		catch (exception& e)
		{
			cout << "Exception: " << e.what() << endl;
		}
	}
	bool operator=(const Array<T>& otherArray)
	{
		List = (T**)realloc(List, (otherArray.Capacity + 1) * sizeof(T*));
		Size = otherArray.Size;
		Capacity = otherArray.Capacity;

		for (int i = 0; i < Size; i++)
			List[i] = otherArray.List[i];
		return true;
	}

	void Sort() // sorteaza folosind comparatia intre elementele din T
	{
		T* aux;
		for (int i = 0; i < Size - 1; i++)
		{
			for (int j = i + 1; j < Size; j++)
			{
				aux = List[i];
				List[i] = List[j];
				List[j] = aux;
			}
		}
	}

	int BinarySearch(const T& elem) // cauta un element folosind binary search in Array
	{
		int left = 0, right = Size - 1;
		while (left < right)
		{
			int middle = (left + right) / 2;
			if (List[middle] == elem)
				return middle;
			if (List[middle] < elem)
				right = middle - 1;
			else
				left = middle + 1;
		}
		return -1;
	}

	int Find(const T& elem) // cauta un element in Array
	{
		for (int i = 0; i < Size; i++)
			if (List[i] == elem)
				return elem;
		return -1;
	}
	int GetSize()
	{
		return Size;
	}
	int GetCapacity()
	{
		return Capacity;
	}

	ArrayIterator<T> begin()
	{
		ArrayIterator<T> aux;
		aux.Current = &List[0];
		return aux;
	}
	ArrayIterator<T> end()
	{
		ArrayIterator<T> aux;
		aux.Current = &List[Size];
		return aux;
	}
};