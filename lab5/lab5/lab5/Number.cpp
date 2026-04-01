#define _CRT_SECURE_NO_WARNINGS
#include<cstring>
#include<iostream>
#include "Number.h"
using namespace std;

Number::Number(const char* value, int base) : value(nullptr), base(base) {
	CopyString(value);
}

Number::Number(int value) : value(nullptr), base(10) {
	TransformFromBase10(value, 10);
}

Number::Number(const Number& toCopy): base(toCopy.base), value(nullptr) {
	CopyString(toCopy.value);
}

Number::Number(Number&& toMove) : base(toMove.base), value(toMove.value) {
	toMove.base = 0;
	toMove.value = nullptr;
}

Number::~Number() {
	delete[] value;
}

Number& Number::operator=(const Number& other) {
	if (this == &other) return *this;
	base = other.base;
	CopyString(other.value);
	return *this;
}
Number& Number::operator=(int value) {
	TransformFromBase10(value, base);
	return *this;
}
Number& Number::operator=(const char* value) {
	CopyString(value);
	return *this;
}

char Number::operator[](int index) const {
	if (0 <= index && index < GetDigitsCount()) {
		return value[index];
	}
	return 0;
}

void Number::CopyString(const char* str) {
	delete[] this->value;
	this->value = new char[strlen(str) + 1];
	strcpy(this->value, str);
}
void Number::TransformFromBase10(int nr, int newbase) {
	base = newbase;
	if (nr == 0) {
		CopyString("0");
		return;
	}

	char temp[32];
	int l = 0;

	if (base <= 10) { //nu trebuie sa pun litere
		while (nr) {
			temp[l++] = (char)(nr % base + '0');
			nr /= base;
		}
	}
	else {
		while (nr) {
			int cif = nr % base;
			if (cif <= 9) temp[l++] = (char)(nr % base + '0');
			else temp[l++] = (char)(nr % base - 10 + 'A');
			nr /= base;
		}
	}

	temp[l] = 0;
	for (int i = 0; i < l / 2; i++) {
		swap(temp[i], temp[l - i - 1]);
	}
	CopyString(temp);
}

int Number::TranformToBase10() const {
	int l = GetDigitsCount();
	int nr = 0;
	int putere = 1;
	for (int i = l - 1; i >= 0; i--) {
		if ('0' <= value[i] && value[i] <= '9') {
			nr = nr + putere*(value[i] - '0');
		}
		else {
			nr = nr + putere*(value[i] - 'A' + 10);
		}
		putere *= base;
	}
	return nr;
}

void Number::SwitchBase(int newBase) {
	if (base == newBase) return;
	int val10 = TranformToBase10();
	TransformFromBase10(val10, newBase);
}

void Number::Print() const{
	printf("%s\n", value);
}

int Number::GetDigitsCount() const{
	if (value == nullptr) return 0;
	return strlen(value);
}

int Number::GetBase() const{
	return base;
}

Number operator+(const Number& n1, const Number& n2) {
	int maxbase = max(n1.base, n2.base);
	int sum = n1.TranformToBase10() + n2.TranformToBase10();
	Number x(0);
	x.TransformFromBase10(sum, maxbase);
	return x;
}

Number operator-(const Number& n1, const Number& n2) {
	int maxbase = max(n1.base, n2.base);
	int dif = n1.TranformToBase10() - n2.TranformToBase10();
	if (dif < 0) dif = 0;
	Number x(0);
	x.TransformFromBase10(dif, maxbase);
	return x;
}

Number& Number::operator+=(const Number& other) {
	*this = *this + other;
	return *this;
}

Number& Number::operator--() {
	int l = GetDigitsCount();
	if (value != nullptr && l > 0) {
		for (int i = 0; i < l; i++) {
			value[i] = value[i + 1];
		}
	}
	return *this;
}

Number Number::operator--(int) {
	int l = GetDigitsCount();
	Number copy(*this);
	if (value != nullptr && l > 0) {
		value[l - 1] = 0;
	}
	return copy;
}

bool operator>(const Number& n1, const Number& n2) {
	return n1.TranformToBase10() > n2.TranformToBase10();
}
bool operator<(const Number& n1, const Number& n2) {
	return n1.TranformToBase10() < n2.TranformToBase10();
}
bool operator>=(const Number& n1, const Number& n2) {
	return n1.TranformToBase10() >= n2.TranformToBase10();
}
bool operator<=(const Number& n1, const Number& n2) {
	return n1.TranformToBase10() <= n2.TranformToBase10();
}
bool operator==(const Number& n1, const Number& n2) {
	return n1.TranformToBase10() == n2.TranformToBase10();
}
bool operator!=(const Number& n1, const Number& n2) {
	return n1.TranformToBase10() != n2.TranformToBase10();
}