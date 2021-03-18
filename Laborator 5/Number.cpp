#define _CRT_SECURE_NO_WARNINGS
#include "Number.h"

Number::Number(const char* value, int base)
{
	cout << "S-a apelat constructorul!" << endl;
	number = new char[strlen(value)+1];
	memcpy(number, value, strlen(value) + 1);
	baza = base;
}

Number::~Number()
{
	cout << "[ARE EROARE] S-a apelat destructorul!" << endl;
	//delete(number);
	//number = nullptr;
}

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

void Number::SwitchBase(int newBase)
{
	// convertesc baza b in 10, apoi din 10 in baza noua.
	int length = strlen(number);
	int p = 1, i;
	int toDecimal = 0;
	for (i = length - 1; i >= 0; i--)
	{
		if (decimalValue(number[i]) >= baza)
		{
			cout << "Numar gresit!";
			break;
		}
		toDecimal = toDecimal + decimalValue(number[i]) * p;
		p = p * baza;
	}
	// toDecimal = numarul in baza 10
	char* nr = new char[101];
	i = 0;
	while(toDecimal > 0)
	{
		nr[i] = charValue(toDecimal % newBase);
		toDecimal /= newBase;
		i++;
	}
	nr[i] = '\0';
	_strrev(nr);
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
	return this->baza;
}
