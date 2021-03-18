#include "Number.h"

int main()
{
	Number nr1("1101", 2);
	cout << "The number of digits is " << nr1.GetDigitsCount() << " and the base is " << nr1.GetBase() << endl;
	nr1.SwitchBase(3);
	cout << "The number of digits is " << nr1.GetDigitsCount() << " and the base is " << nr1.GetBase() << endl;
	nr1.Print();

	Number nr2("2A4", 16);

	cout << "--Comparison of two numbers--> ";
	if (nr1 > nr2)
		cout << " The first number is greater than the second one." << endl;
	else
		if (nr1 < nr2)
			cout << " The second number is greater then the first one." << endl;
		else
			cout << " The numbers are equal." << endl;



	return 0;
}