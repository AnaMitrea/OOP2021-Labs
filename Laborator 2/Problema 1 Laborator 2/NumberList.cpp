#include "NumberList.h"
#include <stdio.h>

void NumberList::Init() {
	this->count = 0;
}

bool NumberList::Add(int x) {
	if (this->count >= 10)
		return false;
	this->numbers[count] = x;
	this->count++;
}

void NumberList::Sort() {
	for (int i = 0; i < count - 1; i++) {
		for (int j = i + 1; j < count; j++) {
			if (this->numbers[i] > this->numbers[j]) {
				int aux = this->numbers[i];
				this->numbers[i] = this->numbers[j];
				this->numbers[j] = aux;
			}
		}
	}
}

void NumberList::Print() {
	printf("Vectorul este: ");
	for (int i = 0; i < count; i++) {
		printf("%d", this->numbers[i]);
		printf(" ");
	}
	printf("\n");
}

