#include "NumberList.h"
#include <stdlib.h>
#include <stdio.h>
using namespace std;

int main()
{
	NumberList obiect;
	obiect.Init();
	int x = 5;
	obiect.Add(x);
	obiect.Add(6);
	obiect.Add(2);
	printf("Vectorul meu este: ");
	obiect.Print();
	obiect.Sort();
	printf("Vectorul meu dupa sortare este: ");
	obiect.Print();
	
	system("pause");
	return 0;
}