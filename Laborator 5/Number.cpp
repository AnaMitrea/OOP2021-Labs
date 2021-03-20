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

int charToDecimal(const char* value)
{
	int toDecimal = 0, p = 1;
	for (int i = strlen(value) - 1; i >= 0; i--)
	{
		toDecimal = toDecimal + decimalValue(value[i]) * p;
		p = p * 10;
	}
	return toDecimal;
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

Number::Number(const Number& object)
{
	cout << "[ COPY CONSTRUCTOR ]" << endl;
	number = new char[strlen(object.number) + 1];
	memcpy(number, object.number, strlen(object.number) + 1);
	baza = object.baza;
	decimal = -1;

	if (baza >= 2 && baza <= 16)
	{
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
	}
	else
		cout << "Error! Insert a base between 2 and 16!" << endl;
}

Number::Number(Number&& object)
{
	cout << "[ MOVE CONSTRUCTOR ]" << endl;
	char* temp = object.number;
	object.number = nullptr;
	number = new char[strlen(temp) + 1];
	memcpy(number, temp, strlen(temp) + 1);
	baza = object.baza;
	decimal = -1;

	if (baza >= 2 && baza <= 16)
	{
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
	}
	else
		cout << "Error! Insert a base between 2 and 16!" << endl;
}

Number& Number::operator=(int value)
{
	// convertesc value la baza obiectului
	char num[101];
	int index = 0;
	while (value > 0)
	{
		num[index++] = charValue(value % baza);
		value /= baza;
	}
	num[index] = '\0';
	_strrev(num);
	int size = index;
	number = (char*)realloc(number, size);
	memcpy(number, num, size);
	//return (*this);
}

Number& Number::operator=(const char* value)
{
	// convertesc value la baza obiectului
	int toDecimal = 0, p = 1;
	// from char to decimal
	for (int i = strlen(value) - 1; i >= 0; i--)
	{
		if (decimalValue(value[i]) >= baza)
		{
			cout << "Wrong Number! Please insert another number.";
			decimal = -1;
			break;
		}
		toDecimal = toDecimal + decimalValue(value[i]) * p;
		p = p * baza;
	}
	//from decimal to char to the base of the object
	char* nr = new char[101];
	int i = 0;
	if (toDecimal == 0)
	{
		nr[i] = '0';
		i++;
	}
	while (toDecimal > 0)
	{
		nr[i] = charValue(toDecimal % baza);
		toDecimal /= baza;
		i++;
	}
	nr[i] = '\0';
	_strrev(nr);
	number = (char*)realloc(number, strlen(nr) + 1);
	memcpy(number, nr, strlen(nr) + 1);
	decimal = charToDecimal(value);
	//return (*this);
}

/*
Number& Number::operator=(Number&& object) noexcept
{
	cout << "Move assignment operator" << endl;
	if (this != &object)
	{
		delete[] number;
		int size = strlen(object.number) + 1;
		//number = (char*)realloc(number, size);
		memcpy(number, object.number, size);
		baza = object.baza;

		object.number = nullptr;
		object.baza = 0;
		object.decimal = 0;
	}
	return *this;
}
*/


Number Number::operator+(Number& object)
{
	cout << "-Addition operator-" << endl;
	// fac suma in baza 10 a celor doua numere apoi o convertesc la baza mai mare

	int res = decimal + object.decimal;
	int i = 0, biggerBase;
	char* nr = new char[101];  // in nr voi avea rezultatul sumei in baza mai mare

	if (baza > object.baza)
		biggerBase = baza;
	else
		biggerBase = object.baza;

	if (res == 0)
	{
		nr[i] = '0';
		i++;
	}
	while (res > 0)
	{
		nr[i] = charValue(res % biggerBase);
		res /= biggerBase;
		i++;
	}
	nr[i] = '\0';
	_strrev(nr);
	return Number(nr, biggerBase);
}

void Number::operator+=(Number& object)
{
	cout << "-Addition operator 2-" << endl;
	// fac suma in baza 10 a celor doua numere apoi o convertesc la baza mai mare

	int res = decimal + object.decimal;
	int i = 0;
	char* nr = new char[101];  // in nr voi avea rezultatul sumei in baza mai mare

	if (res == 0)
	{
		nr[i] = '0';
		i++;
	}
	while (res > 0)
	{
		nr[i] = charValue(res % baza);
		res /= baza;
		i++;
	}
	nr[i] = '\0';
	_strrev(nr);

	int size = strlen(nr) + 1;
	number = (char*)realloc(number, size);
	memcpy(number, nr, strlen(nr) + 1);
	cout << "din functia +=: " << number << " in baza " << baza << endl;
}

Number Number::operator-(Number& object)
{
	cout << "-Substraction operator-" << endl;
	// fac dif in baza 10 a celor doua numere apoi o convertesc la baza mai mare

	int res = decimal - object.decimal;
	int i = 0, biggerBase;
	char* nr = new char[101];  // in nr voi avea rezultatul diferentei in baza mai mare
	bool negative = false;

	if (res < 0)
		negative = true;

	if (baza > object.baza)
		biggerBase = baza;
	else
		biggerBase = object.baza;

	if (negative == true)
		res = -res;
	if (res == 0)
	{
		nr[i] = '0';
		i++;
	}
	while (res > 0) // conversie in baza mai mare
	{
		nr[i] = charValue(res % biggerBase);
		res /= biggerBase;
		i++;
	}
	if (negative == true)
	{
		nr[i] = '-';
		nr[i + 1] = '\0';
		_strrev(nr);
	}
	else
	{
		nr[i] = '\0';
		_strrev(nr);
	}
	return Number(nr,biggerBase);
}

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
	if (decimalNum == 0)
	{
		nr[i] = '0';
		i++;
	}
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
