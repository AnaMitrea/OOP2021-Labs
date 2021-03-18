#include "Number.h"

int main()
{
	Number nr1("140", 5);
	nr1.Print();
	cout << "The number of digits: " << nr1.GetDigitsCount() << " and base: " << nr1.GetBase() << endl;
	nr1.SwitchBase(13);
	nr1.Print();
	cout << "The number of digits: " << nr1.GetDigitsCount() << " and base: " << nr1.GetBase() << endl;


	return 0;
}