#include "Classroom.h"
#include "Globals.h"

int main() {
	Classroom stud1,stud2;

	char studName1[50] = "Andreea";
	char studName2[50] = "Andrei";

	stud1.setName(studName1);
	stud2.setName(studName2);

	stud1.setMathsGrade(8.7);
	stud2.setMathsGrade(5);

	stud1.setEnglishGrade(8.5);
	stud2.setEnglishGrade(9.9);
	
	stud1.setHistoryGrade(10);
	stud2.setHistoryGrade(10);

	// 1 -> stud1 > stud2 ; 0 -> stud1 = stud2 ; -1 -> stud1 < stud2
	cout << "Compararea celor doua nume: " << namesComparator(&stud1, &stud2) << "\n";
	cout << "Compararea celor doua note la matematica: " << mathsGradesComparator(&stud1, &stud2) << "\n";
	cout << "Compararea celor doua note la engleza: " << englishGradesComparator(&stud1, &stud2) << "\n";
	cout << "Compararea celor doua note la istorie: " << historyGradesComparator(&stud1, &stud2) << "\n";
	cout << "Compararea celor doua medii: " << averageComparator(&stud1, &stud2) << "\n";

	return 0;
}