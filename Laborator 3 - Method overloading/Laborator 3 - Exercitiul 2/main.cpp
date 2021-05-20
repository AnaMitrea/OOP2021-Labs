#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include "Canvas.h"
using namespace std;

int main()
{
	Canvas obj(50,50);
	
	obj.DrawCircle(25, 25, 10, '.');
	obj.Print();
	obj.FillCircle(25, 25, 10, '.');
	obj.Print();
	obj.DrawRect(10, 10, 30, 30, '.');
	obj.Print();
	obj.FillRect(10, 10, 30, 30, '.');
	obj.Print();
	obj.DrawLine(1, 6, 25, 30, '.');
	obj.Print();

	return 0;
}
