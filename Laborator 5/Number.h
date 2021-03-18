#pragma once
#include <iostream>
#include <cstring>
using namespace std;

class Number
{
	char* number;
	int decimal;
	int baza;
public:
	Number(const char* value, int base); // where base is between 2 and 16
	~Number();
	//Number(const Number& object);  // copy constructor
	//Number(const Number&& object); // move constructor
	//Number& operator=(Number&& object);	// move assignment operator ???

	Number operator+(Number& object);  // Addition operator
	Number operator-(Number& object);  // Substraction operator
	// Negate operator
	// Index operator

	// Relation operators
	bool operator<(Number& object);
	bool operator>(Number& object);
	bool operator<=(Number& object);
	bool operator>=(Number& object);
	bool operator==(Number& object);

	void operator--();        //--nr
	void operator--(int nr);  //nr--

	void SwitchBase(int newBase);
	void Print();
	int  GetDigitsCount(); // returns the number of digits for the current number
	int  GetBase(); // returns the current base
};