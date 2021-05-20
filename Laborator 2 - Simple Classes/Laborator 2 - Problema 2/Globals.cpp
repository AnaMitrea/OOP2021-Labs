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

int mathsGradesComparator(Classroom* stud1, Classroom* stud2) {
	float mathsGrade1 = stud1->getMathsGrade(), mathsGrade2 = stud2->getMathsGrade();
	if (mathsGrade1 == mathsGrade2)
		return 0;
	else {
		if (mathsGrade1 > mathsGrade2)
			return 1;
		else
			return -1;
	}	
}

int englishGradesComparator(Classroom* stud1, Classroom* stud2) {
	float englishGrade1 = stud1->getEnglishGrade(), englishGrade2 = stud2->getEnglishGrade();
	if (englishGrade1 == englishGrade2)
		return 0;
	else {
		if (englishGrade1 > englishGrade2)
			return 1;
		else
			return -1;
	}
}

int historyGradesComparator(Classroom* stud1, Classroom* stud2) {
	float historyGrade1 = stud1->getHistoryGrade(), historyGrade2 = stud2->getHistoryGrade();
	if (historyGrade1 == historyGrade2)
		return 0;
	else {
		if (historyGrade1 > historyGrade2)
			return 1;
		else
			return -1;
	}
}

int averageComparator(Classroom* stud1, Classroom* stud2) {
	float average1 = stud1->averageGrade(), average2 = stud2->averageGrade();
	if (average1 == average2)
		return 0;
	else {
		if (average1 > average2)
			return 1;
		else
			return -1;
	}
}