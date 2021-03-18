#include "Number.h"

int main()
{
	Number nr1("2A4", 16);
	cout << "The number of digits: " << nr1.GetDigitsCount() << " and the base: " << nr1.GetBase() << endl;
	nr1.SwitchBase(2);
	cout << "The number of digits: " << nr1.GetDigitsCount() << " and the base: " << nr1.GetBase() << endl;
	nr1.Print();

	Number nr2("11", 10);

	return 0;
}