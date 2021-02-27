#pragma once
#include <cstring>
#include <iostream>
using namespace std;

class Classroom
{
	char name[50];
	float mathsGrade, englishGrade, historyGrade;

public:
	//Classroom();
	//~Classroom();

	void setName(char studName[50]);
	char* getName();

	void setMathsGrade(float grade);
	float getMathsGrade();

	void setEnglishGrade(float grade);
	float getEnglishGrade();

	void setHistoryGrade(float grade);
	float getHistoryGrade();

	float averageGrade();
};

