#include <iostream>
#include "Literals.h"
using namespace std;


int main()
{
	float a = 300;
	cout << "a in Kelvin este " << a;
	a = 300_Kelvin;
	cout << " si in Celsius este " << a << endl;
	float b = 120;
	cout << "b in Fahrenheit este " << b;
	b = 120_Fahrenheit;
	cout << " si in Celsius este " << b << endl;
	
	return 0;
}