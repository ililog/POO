using namespace std;
#include <iostream>
#include "canvas.h"
#include<cstdarg>

Canvas::Canvas(int lines, int columns) : width(columns), height(lines) {
	matrix = new char*[height];
	for (int i = 0; i < height; i++) {
		matrix[i] = new char[width];
	}
	clear();
}

Canvas::~Canvas() {
	for (int i = 0; i < height; i++) {
		delete[] matrix[i];
	}
	delete[] matrix;
}

void Canvas::clear() {
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			matrix[i][j] = ' ';
		}
	}
}

void Canvas::print() const{
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			cout << matrix[i][j];
		}
		cout << '\n';
	}
}

void Canvas::set_pixel(int x, int y, char value) {
	if (0 <= x && x < height && 0 <= y && y < width) {
		matrix[x][y] = value;
	}
}

void Canvas::set_pixels(int count, ...) {
	va_list args;
	va_start(args, count);
	for (int i = 0; i < count; i++) {
		int x = va_arg(args, int);
		int y = va_arg(args, int);
		char value = (char)(va_arg(args, int)); //char a fost promovat la int si trebuie sa facem reverse
		set_pixel(x, y, value);
	}
	va_end(args);
}