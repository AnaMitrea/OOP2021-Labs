#include "Classroom.h"

void Classroom::setName(char studName[50]) {
	strcpy_s(this->name, studName);
}

char* Classroom::getName() {
	return this->name;
}

void Classroom::setMathsGrade(float grade) {
	if (grade >= 1 && grade <= 10) {
		this->mathsGrade = grade;
	}
}

float Classroom::getMathsGrade() {
	return this->mathsGrade;
}

void Classroom::setEnglishGrade(float grade) {
	if (grade >= 1 && grade <= 10) {
		this->englishGrade = grade;
	}	
}
float Classroom::getEnglishGrade() {
	return this->englishGrade;
}

void Classroom::setHistoryGrade(float grade) {
	if (grade >= 1 && grade <= 10) {
		this->historyGrade = grade;
	}
}

float Classroom::getHistoryGrade() {
	return this->historyGrade;
}

float Classroom::averageGrade() {
	float average = (this->mathsGrade + this->englishGrade + this->historyGrade) / 3;
	return average;
}

Classroom::Classroom() {
	cout << "Am apelat constructorul pentru clasa Classroom\n";
	this->mathsGrade = 0;
	this->englishGrade = 0;
	this->historyGrade = 0;
}

Classroom::~Classroom() {
	cout << "Am apelat destructorul pentru clasa Classroom\n";
}