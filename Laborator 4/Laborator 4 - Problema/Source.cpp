#define _CRT_SECURE_NO_WARNINGS
#include "Sort.h"

int main()
{
	Sort obj1(8,1,50);
	cout << "Primul vector initial (generat random) este: ";
	obj1.Print();
	cout << endl;

	cout << "Primul vector sortat cu Insert Sort: ";
	obj1.InsertSort(false);
	obj1.Print();
	cout << endl;

	Sort obj2;
	cout << "Al doilea vector initial (generat prin lista de initializare) este: ";
	obj2.Print();
	cout << endl;

	cout << "Al doilea vector sortat cu Bubble Sort: ";
	obj2.BubbleSort(true);
	obj2.Print();
	cout << endl;

	int v[5] = { 1,20,5,6,0 };
	Sort obj3(v, 5);
	cout << "Al treilea vector initial (generat din alt vector) este: ";
	obj3.Print();
	cout << endl;

	cout << "Al treilea vector sortat cu Insert Sort: ";
	obj3.InsertSort(true);
	obj3.Print();
	cout << endl;

	Sort obj4(6, 10, 30, 0, 1, 4, 6);
	cout << "Al patrulea vector initial (generat cu var) este: ";
	obj4.Print();
	cout << endl;

	char sir[15] = "10,40,100,5,70";
	Sort obj5(sir);
	cout << "Al cincilea vector initial (generat cu sir de char) este: ";
	obj5.Print();
	cout << endl;

	cout << "Al cincilea vector sortat cu Bubble Sort: ";
	obj5.BubbleSort(true);
	obj5.Print();
	cout << endl;

	return 0;
}