#include "template.h"

int main()
{
	// nu compileaza
	Array<int> obj(10);
	obj += 5;
	obj += 66;
	cout << obj[1];
	return 0;
}