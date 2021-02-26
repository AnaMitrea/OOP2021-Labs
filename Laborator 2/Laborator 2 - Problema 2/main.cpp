#include "Classroom.h"
#include "Globals.h"

int main() {
	Classroom stud1;
	Classroom stud2;

	char studName1[50] = "Ion";
	char studName2[50] = "Ana";

	stud1.setName(studName1);
	stud2.setName(studName2);

	cout << namesComparator(&stud1, &stud2) << "\n";

	return 0;
}