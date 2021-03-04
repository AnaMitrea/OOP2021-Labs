#include "Math.h"
#include <cstdarg>
#include <cstring>
#include <stdlib.h>

int Math::Add(int x, int y) {
	return x + y;
}

int Math::Add(int x, int y, int z) {
	return x + y + z;
}
int Math::Add(double x , double y) {
	return x + y;
}
int Math::Add(double x, double y, double z) {
	return x + y + z;
}

int Math::Mul(int x, int y) {
	return x * y;
}

int Math::Mul(int x, int y, int z) {
	return x * y * z;
}

int Math::Mul(double x, double y) {
	return x * y;
}

int Math::Mul(double x, double y, double z) {
	return x * y * z;
}
int Math::Add(int count, ...) {
	va_list vl;
	va_start(vl, count);
	int sum = 0;
	for (int i = 0; i < count; i++) {
		sum += va_arg(vl, int);
	}
	va_end(vl);
	return sum;
}

char* Math::Add(const char* str1, const char* str2) {
	if (str1 == nullptr || str2 == nullptr)
		return nullptr;
	int size = strlen(str1) + strlen(str2) + 1;
	char* str = (char*)(malloc(size * sizeof(char)));
	memset(str, 0, size * sizeof(char));
	memcpy(str, str1, strlen(str1));
	memcpy(str + strlen(str1), str2, strlen(str2));
	return str;
}

// METODA V2
/*
char* Math::Add(const char* str1, const char* str2) {
	if (str1 == nullptr || str2 == nullptr)
		return nullptr;
	char* aux = new char[strlen(str1) + strlen(str2) + 1];
	aux[0] = 0;
	strcat(aux, str1);
	strcat(aux, str2);
	return aux;
}
*/