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

char* Number::operator+(Number& object)
{
	cout << "-Addition operator-" << endl;
	// fac suma in baza 10 a celor doua numere apoi o convertesc la baza mai mare

	int res = decimal + object.decimal;
	int i = 0;
	char* nr = new char[101];  // in nr voi avea rezultatul sumei in baza mai mare
	if (baza > object.baza)
	{
		while (res > 0)
		{
			nr[i] = charValue(res % baza);
			res /= baza;
			i++;
		}
		nr[i] = '\0';
		_strrev(nr);
		return nr;
	}
	else
	{
		while (res > 0)
		{
			nr[i] = charValue(res % object.baza);
			res /= object.baza;
			i++;
		}
		nr[i] = '\0';
		_strrev(nr);
		return nr;
	}
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

bool Number::operator<(Number& object)
{
	if(decimal < object.decimal)
		return true;
	return false;
}

bool Number::operator>(Number& object)
{
	if (decimal > object.decimal)
		return true;
	return false;
}

bool Number::operator<=(Number& object)
{
	if (decimal <= object.decimal)
		return true;
	return false;
}

bool Number::operator>=(Number& object)
{
	if (decimal >= object.decimal)
		return true;
	return false;
}

bool Number::operator==(Number& object)
{
	if (decimal == object.decimal)
		return true;
	return false;
}

void Number::operator--()
{
	cout << "Prefix form of op --" << endl;
	strcpy(number, number + 1);
	// fac iar conversia numarului in baza 10 deoarece s-a schimbat
	int length = strlen(number);
	int p = 1, i;
	decimal = 0;
	for (i = length - 1; i >= 0; i--)
	{
		decimal = decimal + decimalValue(number[i]) * p;
		p = p * baza;
	}
}

void Number::operator--(int nr)
{
	cout << "Postfix form of op --" << endl;
	_strrev(number);
	strcpy(number, number + 1);
	_strrev(number);
	// fac iar conversia numarului in baza 10 deoarece s-a schimbat
	int length = strlen(number);
	int p = 1, i;
	decimal = 0;
	for (i = length - 1; i >= 0; i--)
	{
		decimal = decimal + decimalValue(number[i]) * p;
		p = p * baza;
	}
}

void Number::SwitchBase(int newBase)
{
	// convertesc din baza 10 in baza noua.
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
	cout << "Number: ";
	for (unsigned int i = 0; i < strlen(number); i++)
	{
		cout << number[i];
	}
	cout << endl;
	cout << "Decimal number: " << decimal << endl;
}

int Number::GetDigitsCount()
{
	return strlen(number);
}

int Number::GetBase()
{
	return baza;
}
