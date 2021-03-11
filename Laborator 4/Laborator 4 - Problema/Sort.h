#pragma once
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <stdarg.h>
#include <cstring>
using namespace std;

class Sort
{
    int counter;
    int* vec;
public:
    Sort(int number, int min, int max);  // constructorul 1
    Sort(); // constructorul 2
    Sort(int v[], int num); // constructorul 3
    Sort(int num, ...);  // constructorul 4
    Sort(char sir[]); // constructorul 5
    ~Sort();
    void InsertSort(bool ascendent = false);
    int partition(int l, int r, int ascendent = false);
    void QuickSort(int l, int r, bool ascendent = false);
    void BubbleSort(bool ascendent = false);
    void Print();
    int  GetElementsCount();
    int  GetElementFromIndex(int index);
};

