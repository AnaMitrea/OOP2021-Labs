#include "Template.h"

int main()
{
	VectorTemplate<int> arr;

	cout << "Push item" << endl;
	arr.push(5);
	arr.Print();

	cout << "Push item" << endl;
	arr.push(10);
	arr.Print();

	cout << "Push item" << endl;
	arr.push(0);
	arr.Print();

	cout << "Push item" << endl;
	arr.push(200);
	arr.Print();

	cout << "Push item" << endl;
	arr.push(4);
	arr.Print();

	cout << "Push item" << endl;
	arr.push(67);
	arr.Print();

	cout << "Pop last item" << endl;
	arr.pop();
	arr.Print();

	cout << "Removing item from index 2" << endl;
	arr.remove(2);
	arr.Print();

	cout << "Inserting item in index 3" << endl;
	arr.insert(999, 3);
	arr.Print();

	cout << "Get method" << endl;
	arr.getElement(1);

	cout << "Set method" << endl;
	arr.setElement(44, 1);
	arr.Print();

	cout << "Counting elements" << endl;
	cout << arr.countElements();

	return 0;
}