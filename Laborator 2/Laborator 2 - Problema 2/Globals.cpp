#pragma once
#include "Globals.h"

int namesComparator(Classroom* stud1, Classroom* stud2) {
	char name1[50];
	strcpy_s(name1, stud1->getName());
	char name2[50];
	strcpy_s(name2, stud2->getName());
	
	if (strcmp(name1, name2) == 0)
		return 0;
	else
		if (strcmp(name1, name2) > 0)
			return 1;
		else
			return -1;
}


