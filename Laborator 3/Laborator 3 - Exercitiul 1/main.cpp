#include <iostream>
#include "Math.h"
using namespace std;

int main() 
{
	cout << "int + int: " << Math::Add(2, 3) << endl;
	cout << "int + int + int: " << Math::Add(2, 3, 4) << endl;
	cout << "double + double: " << Math::Add(2.50, 3.80) << endl;
	cout << "double + double + double: " << Math::Add(2.54, 3.04, 4.98) << endl;
	cout << "int * int: " << Math::Mul(2, 3) << endl;
	cout << "int * int * int: " << Math::Mul(2, 3, 5) << endl;
	cout << "double * double: " << Math::Mul(5.945, 40.97) << endl;
	cout << "double * double * double: " << Math::Mul(5.47, 66.8, 98.121) << endl;
	cout << "suma de lista de int: " << Math::Add(5, 4,5,6,7,8) << endl;
	cout << "concatenare 2 siruri: " << Math::Add("Ana", "-Maria") << endl;
	return 0;
}