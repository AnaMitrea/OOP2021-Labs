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
	Number(const char* value, int base); // constructor
	~Number();  //destructor
	Number(const Number& object);  // copy constructor
	Number(Number&& object); // move constructor
	
	//Number& operator=(Number&& object);	// move assignment operator ???
	Number& operator=(int value);  // object = nr
	Number& operator=(const char* value); // object = sir caractere
	
	Number operator+(Number& object);  // Addition operator
	void operator+=(Number& object);
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