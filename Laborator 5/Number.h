#pragma once
#include <iostream>
#include <cstring>
using namespace std;

class Number
{
	char* number;
	int baza;
public:
	Number(const char* value, int base); // where base is between 2 and 16
	~Number();
	Number(const Number& object);
	// add operators and copy/move constructor
	void SwitchBase(int newBase);
	void Print();
	int  GetDigitsCount(); // returns the number of digits for the current number
	int  GetBase(); // returns the current base
};