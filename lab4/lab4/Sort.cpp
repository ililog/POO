#include "Sort.h"
#include<stdlib.h> //pt rand
#include<cstdarg> //pt args
#include<cstring>
#include<iostream>
using namespace std;

Sort::Sort(int count, int min, int max) {
	this->count = count;
	this->v = new int[count];
	if (min > max) {
		swap(min, max);
	}
	for (int i = 0; i < count; i++) {
		this->v[i] = min + (max - min) * (rand() % RAND_MAX);
	}
}

Sort::Sort(initializer_list<int> L) {
	this->count = L.size();
	this->v = new int[this->count];

	int i = 0;
	for (int x : L) {
		this->v[i] = x; i++;
	}
}
Sort::Sort(int* p, int count) {
	this->count = count;
	this->v = new int[count];
	for (int i = 0; i < count; i++) {
		this->v[i] = p[i];
	}
}
Sort::Sort(int count, ...) {
	this->count = count;
	this->v = new int[count];

	va_list args;
	va_start(args, count);
	for (int i = 0; i < count; i++) {
		this->v[i] = va_arg(args, int);
	}
	va_end(args);
}
Sort::Sort(const char* s) {
	int l = strlen(s);

	this->count = 1;
	for (int i = 0; i < l; i++) {
		if (s[i] == ',') {
			this->count++;
		}
	}
	this->v = new int[this->count];

	int numar = 0, poz = 0;
	for (int i = 0; i < l; i++) {
		if (s[i] != ',') {
			numar = numar * 10 + s[i] - '0';
		}
		else {
			this->v[poz++] = numar;
			numar = 0;
		}
	}
	this->v[poz++] = numar;
}
Sort::~Sort() {
	delete[] this->v;
}

void Sort::Print() {
	for (int i = 0; i < count; i++) {
		cout << v[i] << ' ';
	}
	cout << '\n';
}
int Sort::GetElementsCount() {
	return count;
}
int Sort::GetElementFromIndex(int index) {
	if (!(0 <= index && index < count)) {
		return -1;
	}
	return v[index];
}

void Sort::InsertSort(bool ascendent) {
	for (int i = 1; i < count; i++) {
		int current = v[i];
		int j = i - 1;
		if (ascendent == true) {
			while (j >= 0 && v[j] > current) {
				v[j + 1] = v[j];
				j--;
			}
		}
		else {
			while (j >= 0 && v[j] < current) {
				v[j + 1] = v[j];
				j--;
			}
		}
		v[j + 1] = current;
	}
}

int Sort::Partition(int st, int dr, bool ascendent) {
	int pivot = v[st];
	int i = st;
	for (int j = st + 1; j <= dr; j++) {
		if (ascendent) {
			if (v[j] < pivot) {
				i++;
				swap(v[i], v[j]);
			}
		}
		else {
			if (v[j] > pivot) {
				i++;
				swap(v[i], v[j]);
			}
		}
	}
	swap(v[st], v[i]);
	return i;
}

void Sort::QuickSort2(int st, int dr, bool ascendent) {
	if (st >= dr) return;
	int pivot_position = Partition(st, dr, ascendent);
	QuickSort2(st, pivot_position - 1, ascendent);
	QuickSort2(pivot_position + 1, dr, ascendent);
}

void Sort::QuickSort(bool ascendent) {
	QuickSort2(0, count - 1, ascendent);
}
void Sort::BubbleSort(bool ascendent) {
	for (int i = 0; i < count - 1; i++) {
		bool ok = 0;
		for (int j = 0; j < count - i - 1; j++) {
			if (ascendent == true) {
				if (v[j] > v[j + 1]) {
					swap(v[j], v[j + 1]);
					ok = 1;
				}
			}
			else {
				if (v[j] < v[j + 1]) {
					swap(v[j], v[j + 1]);
					ok = 1;
				}
			}

		}
		if (!ok) break;
	}
}