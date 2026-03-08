#define _CRT_SECURE_NO_WARNINGS
#include "Math.h"
#include<cstdarg>
#include<cstring>
#include<cstdlib>

int Math::Add(int a, int b) {
	return a + b;
}
int Math::Add(int a, int b, int c) {
	return a + b + c;
}
int Math::Add(double a, double b) {
	return (int)(a + b);
}
int Math::Add(double a, double b, double c) {
	return (int)(a + b + c);
}

int Math::Mul(int a, int b) {
	return a * b;
}
int Math::Mul(int a, int b, int c) {
	return a * b * c;
}
int Math::Mul(double a, double b) {
	return (int)(a * b);
}
int Math::Mul(double a, double b, double c) {
	return (int)(a * b * c);
}
int Math::Add(int count, ...) {
	va_list args; 
	va_start(args, count); //pointer la primul argument de dupa count
	int sum = 0;
	for (int i = 0; i < count; i++) {
		sum += va_arg(args, int); //adun argumentul curent, iar pointerul e mutat mai departe
	}
	va_end(args); //reseteaza pointerul args la null
	return sum;
}
char* Math::Add(const char* s1, const char* s2) {
	if (s1 == nullptr || s2 == nullptr) return nullptr;
	int l1 = strlen(s1), l2 = strlen(s2);
	char* result = (char*)malloc(l1 + l2 + 1); //aloc memorie 
	strcpy(result, s1);
	strcat(result, s2);
	return result;
}