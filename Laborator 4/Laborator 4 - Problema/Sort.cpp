#include "Sort.h"

Sort::Sort(int number, int min, int max)  // Constr 1
{
	cout << "Am apelat constructorul 1!" << endl;
	this->left = 0;
	this->right = number - 1;
	this->vec = new int[number];
	this->counter = number;
	srand((unsigned)time(0));   // daca nu utilizez srand, la fiecare executie va fi aceeasi secv de nr
	for (int i = 0; i < number; i++)
	{ 
		this->vec[i] = rand() % (max - min + 1) + min;  // generez numere intre max si min
	}
}

Sort::Sort() : counter{ 10 }, left{ 0 }, right{ 9 }  // Constr 2
{
	cout << "Am apelat constructorul 2!" << endl;
	vec = new int[counter] {9,1,0,2,6,100,3,54,67,4};
}

Sort::Sort(int v[], int num) // constr 3
{
	cout << "Am apelat constructorul 3!" << endl;
	this->vec = new int[num];
	for (int i = 0; i < num; i++)
	{
		this->vec[i] = v[i];
	}
	this->counter = num;
	this->left = 0;
	this->right = num - 1;
}

Sort::Sort(int num, ...)  // constructorul 4
{
	cout << "Am apelat constructorul 4!" << endl;
	this->vec = new int[num];
	this->counter = num;
	this->left = 0, this->right = num - 1;
	va_list vl;
	va_start(vl, num);
	for (int i = 0; i < num; i++)
	{
		int val = va_arg(vl, int);
		this->vec[i] = val;
	}
	va_end(vl);
}

Sort::Sort(char sir[])  // Constructorul 5
{
	cout << "Am apelat constructorul 5!" << endl;
	int num = 0;
	// aflu de cate elemente am nev in vector
	for (int i = 0; i < strlen(sir); i++)
	{
		if (sir[i] == ',')
		{
			num++;
		}
	}
	this->counter = num + 1;
	this->vec = new int[num + 1];
	
	int nr = 0, j = 0, i = 0;
	for (i = 0; i < strlen(sir); i++)
	{
		if (sir[i] != ',')
		{
			nr *= 10;
			nr += (sir[i] - '0');
		}
		else
		if(sir[i] == ',')
		{
			this->vec[j] = nr;
			j++;
			nr = 0;
		}
	}
	if (sir[i] == '\0')
	{
		this->vec[j] = (int)nr;
	}
	this->left = 0;
	this->right = num;
}

Sort::~Sort() 
{
	cout << "Am apelat destructorul!" << endl;
}

void Sort::InsertSort(bool ascendent)
{
	int x;
	for (int i = 1; i < this->counter; i++)
	{
		x = this->vec[i];
		int j;
		if (ascendent == true)
		{
			for (j = i - 1; j >= 0 && this->vec[j] > x; j--)
			{
				this->vec[j + 1] = this->vec[j];
			}
			this->vec[j + 1] = x;
		}
		else
		{
			for (j = i - 1; j >= 0 && this->vec[j] < x; j--)
			{
				this->vec[j + 1] = this->vec[j];
			}
			this->vec[j + 1] = x;
		}
	}
}

int Sort::partition(int l, int r)
{
	int pivot = this->vec[r];
	int i = l - 1;
	for (int j = l; j <= r - 1; j++)
	{
		if (this->vec[j] < pivot)
		{
			i++;
			int aux = this->vec[i];
			this->vec[i] = this->vec[j];
			this->vec[j] = aux;
		}
	}
	int aux = this->vec[i + 1];
	this->vec[i + 1] = this->vec[r];
	this->vec[r] = aux;
	return (i + 1);
}

void Sort::QuickSort(int l, int r, bool ascendent)
{
	if (ascendent == true)
	{
		if (l < r)
		{
			int poz = partition(l, r);
			QuickSort(l, poz - 1, ascendent);
			QuickSort(poz + 1, r, ascendent);
		}
	}
	else
	{
		// descrescator
	}
}

void Sort::BubbleSort(bool ascendent)
{
	for (int i = 0; i < this->counter - 1; i++)
	{
		for (int j = 0; j < this->counter - i - 1; j++)
		{
			if (ascendent == true)
			{
				if (this->vec[j] > this->vec[j + 1])
				{
					int aux = this->vec[j];
					this->vec[j] = this->vec[j + 1];
					this->vec[j + 1] = aux;
				}
			}
			else
			{
				if (this->vec[j] < this->vec[j + 1])
				{
					int aux = this->vec[j];
					this->vec[j] = this->vec[j + 1];
					this->vec[j + 1] = aux;
				}
			}
		}
	}
}

void Sort::Print()
{
	for (int i = 0; i < this->counter; i++)
		cout << this->vec[i] << ' ';
	cout << endl;
}

int Sort::GetElementsCount()
{
	return this->counter;
}

int Sort::GetElementFromIndex(int index)
{
	return this->vec[index];
}