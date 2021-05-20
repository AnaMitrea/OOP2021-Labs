#include "Number.h"

int main()
{
	Number nr1("16", 10);
	//cout << "The number of digits is " << nr1.GetDigitsCount() << " and the base is " << nr1.GetBase() << endl;
	//nr1.SwitchBase(3);
	//cout << "The number of digits is " << nr1.GetDigitsCount() << " and the base is " << nr1.GetBase() << endl;
	//nr1.Print();

	Number nr2("10", 2);
	Number nr3("F", 16);
	nr3.Print();
	//nr3 = 255;
	//nr3.Print();
	/*
		cout << "--Comparison of two objects--> ";
	if (nr1 > nr2)
		cout << " The first number is greater than the second one." << endl;
	else
		if (nr1 < nr2)
			cout << " The second number is greater then the first one." << endl;
		else
			cout << " The numbers are equal." << endl;
	*/

	//nr2+=nr1;   // nr2 = nr2 + nr1, adica 10+16 = 26 in b10 apoi 26-> baza 16 e 1A
	//nr2.Print();

	//--nr1;
	//nr1.Print();
	//nr1--;
	//nr1.Print();

	//nr3 = nr1 + nr2;
	//Number nr3("-3", 10);
	//nr3.Print();
	//nr3 = nr1 - nr2;
	//nr3.Print();
	
	return 0;
}