#include "Template.h"

int main()
{
	cout << "[ INT ARRAY ] " << endl;
	VectorTemplate<int> arr;
	cout << "Push item" << endl;
	arr.push(5);
	arr.Print();
	cout << endl;

	cout << "Push item" << endl;
	arr.push(10);
	arr.Print();
	cout << endl;

	cout << "Push item" << endl;
	arr.push(0);
	arr.Print();
	cout << endl;

	cout << "Push item" << endl;
	arr.push(200);
	arr.Print();
	cout << endl;

	cout << "Push item" << endl;
	arr.push(4);
	arr.Print();
	cout << endl;

	cout << "Push item" << endl;
	arr.push(67);
	arr.Print();
	cout << endl;

	cout << "Pop last item: ";
	cout << arr.pop() << endl;

	cout << "Removing item from index 2" << endl;
	arr.remove(2);
	arr.Print();
	cout << endl;

	cout << "Inserting item in index 3" << endl;
	arr.insert(999, 3);
	arr.Print();
	cout << endl;

	cout << "Inserting item in index 2" << endl;
	arr.insert(24, 2);
	arr.Print();
	cout << endl;

	cout << "Get reference of arr[1]: " << arr.getElement(1) << endl;

	cout << "Set Element 1000 on position 0: " << endl;
	arr.setElement(1000, 0);
	arr.Print();
	cout << endl;

	cout << "Counting elements: " << arr.countElements() << endl;

	cout << "Descending sort" << endl;
	arr.sort(comparator1);  // sortare descrescataore daca n am nullptr in callback
	arr.Print();

	cout << "Ascending sort" << endl;
	arr.sort(comparator2);
	arr.Print();

	cout << "Finding the element" << endl;
	arr.firstIndexOf(667, equal);
	arr.firstIndexOf(5, equal);

	/*
	Ce afiseaza:
	Push item
	The array is: 5

	Push item
	The array is: 5 10

	Push item
	The array is: 5 10 0

	Push item
	The array is: 5 10 0 200

	Push item
	The array is: 5 10 0 200 4

	Push item
	The array is: 5 10 0 200 4 67

	Pop last item: 67
	Removing item from index 2
	The array is: 5 10 200 4 67

	Inserting item in index 3
	The array is: 5 10 200 999 4 67

	Inserting item in index 2
	The array is: 5 10 24 200 999 4 67

	Get reference of arr[1]: 00A24E7C
	Set Element 1000 on position 0:
	The array is: 1000 10 24 200 999 4 67

	Counting elements: 7
	Descending sort
	The array is: 1000 999 200 67 24 10 4
	Ascending sort
	The array is: 4 10 24 67 200 999 1000
	Finding the element
	Element 667 was not found in the array!
	Element 5 was not found in the array!
	*/

	cout << endl << endl << "[ CHAR ARRAY ]" << endl;

	VectorTemplate<char> str;
	cout << "Push item" << endl;
	str.push('a');
	str.Print();
	cout << endl;

	cout << "Push item" << endl;
	str.push('k');
	str.Print();
	cout << endl;

	cout << "Push item" << endl;
	str.push('c');
	str.Print();
	cout << endl;

	cout << "Push item" << endl;
	str.push('P');
	str.Print();
	cout << endl;

	cout << "Push item" << endl;
	str.push('9');
	str.Print();
	cout << endl;

	cout << "Push item" << endl;
	str.push('L');
	str.Print();
	cout << endl;

	cout << "Pop last item: ";
	cout << str.pop() << endl;

	cout << "Removing item from index 2" << endl;
	str.remove(2);
	str.Print();
	cout << endl;

	cout << "Inserting item in index 3" << endl;
	str.insert('G', 3);
	str.Print();
	cout << endl;

	cout << "Inserting item in index 2" << endl;
	str.insert('$', 2);
	str.Print();
	cout << endl;

	cout << "Get reference of arr[1]: " << str.getElement(1) << endl;

	cout << "Set Element '6' on position 0: " << endl;
	str.setElement('6', 0);
	str.Print();
	cout << endl;

	cout << "Counting elements: " << str.countElements() << endl;

	cout << "Descending sort" << endl;
	str.sort(comparator1);  // sortare descrescataore daca n am nullptr in callback
	str.Print();

	cout << "Ascending sort" << endl;
	str.sort(comparator2);
	str.Print();

	cout << "Finding the element" << endl;
	str.firstIndexOf('6', equal);
	str.firstIndexOf('%', equal);

	/*
	Ce afiseaza:
	Push item
	The array is: a

	Push item
	The array is: a k

	Push item
	The array is: a k c

	Push item
	The array is: a k c P

	Push item
	The array is: a k c P 9

	Push item
	The array is: a k c P 9 L

	Pop last item: L
	Removing item from index 2
	The array is: a k P 9 L

	Inserting item in index 3
	The array is: a k P G 9 L

	Inserting item in index 2
	The array is: a k $ P G 9 L

	Get reference of arr[1]: k$PG9L═²²²²uø
	Set Element '6' on position 0:
	The array is: 6 k $ P G 9 L

	Counting elements: 7
	Descending sort
	The array is: k P L G 9 6 $
	Ascending sort
	The array is: $ 6 9 G L P k
	Finding the element
	First index of element 6 is 1
	Element % was not found in the array!
	*/

	return 0;
}