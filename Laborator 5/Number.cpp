#define _CRT_SECURE_NO_WARNINGS
#include "Number.h"

int decimalValue(char ch)
{
	if (ch >= '0' && ch <= '9')
		return (int)ch - '0';
	else
		return (int)ch - 'A' + 10;
}

char charValue(int decimalNumber)
{
	if (decimalNumber >= 0 && decimalNumber <= 9)
		return (char)(decimalNumber + '0');
	else
		return (char)(decimalNumber - 10 + 'A');
}

Number::Number(const char* value, int base)
{
	cout << "[ THE CONSTRUCTOR ]" << endl;
	number = new char[strlen(value)+1];
	memcpy(number, value, strlen(value) + 1);
	if (base >= 2 && base <= 16)
	{
		baza = base;
		// Convertire nr din baza b in baza 10
		int length = strlen(number);
		int p = 1, i;
		int toDecimal = 0;
		for (i = length - 1; i >= 0; i--)
		{
			if (decimalValue(number[i]) >= baza)
			{
				cout << "Wrong Number! Please insert another number.";
				decimal = -1;
				break;
			}
			toDecimal = toDecimal + decimalValue(number[i]) * p;
			p = p * baza;
		}
		// toDecimal = numarul in baza 10
		decimal = toDecimal;
		cout << "The Decimal Number of " << number << " is " << decimal << "." <<endl;
	}
	else
		cout << "Error! Insert a base between 2 and 16!" << endl;
}

Number::~Number()
{
	cout <<  "[ THE DESTRUCTOR ]" << endl;
	delete [] number;
	number = nullptr;
}

/*
* Number::Number(const Number& object)
{
	cout << "Copy constructor" << endl;
	strcpy(number, object.number);
	baza = object.baza;
}

Number::Number(const Number&& object)
{
	cout << "Move constructor" << endl;
	strcpy(number, object.number);
	baza = object.baza;
}

Number& Number::operator=(Number&& object)
{
	cout << "Move assignment operator" << endl;
	strcpy(number, object.number);
	baza = object.baza;
	return *this;
}
*/

bool Number::operator<(Number object)
{
	return false;
}

bool Number::operator>(Number object)
{
	return false;
}

bool Number::operator<=(Number object)
{
	return false;
}

void Number::SwitchBase(int newBase)
{
	// convertesc baza b in 10, apoi din 10 in baza noua.
	char* nr = new char[101];
	int i = 0, decimalNum = decimal;
	while(decimalNum > 0)
	{
		nr[i] = charValue(decimalNum % newBase);
		decimalNum /= newBase;
		i++;
	}
	nr[i] = '\0';
	_strrev(nr);
	int size = strlen(nr) + 1;
	number = (char*)realloc(number, size);
	memcpy(number, nr, strlen(nr) + 1);
	baza = newBase;
}

void Number::Print()
{
	cout << "The number is: ";
	for (unsigned int i = 0; i < strlen(number); i++)
	{
		cout << number[i];
	}
	cout << endl;
}

int Number::GetDigitsCount()
{
	return strlen(number);
}

int Number::GetBase()
{
	return baza;
}
