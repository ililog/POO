#include "Canvas.h"
#include<iostream>
#include<cmath>
using namespace std;

Canvas::Canvas(int width, int height) : width(width), height(height) {
	matrix = new char* [height];
	for (int i = 0; i < height; i++) {
		matrix[i] = new char[width];
	}
	Clear();
}

Canvas:: ~Canvas() {
	for (int i = 0; i < height; i++) {
		delete[] matrix[i];
	}
	delete[] matrix;
}

void Canvas::Clear() {
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			matrix[i][j] = ' ';
		}
	}
}

void Canvas::Print() {
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			cout << matrix[i][j];
		}
		cout << '\n';
	}
}

void Canvas::SetPoint(int x, int y, char ch) {
	if (0 <= x && x < width && 0 <= y && y < height) {
		matrix[y][x] = ch;
	}
}

void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch) {
	int dx = abs(x2 - x1), dy = -abs(y2 - y1);
	int dir_x, dir_y;
	if (x1 < x2) dir_x = 1; else dir_x = -1;
	if (y1 < y2) dir_y = 1; else dir_y = -1;
	
	int error = dx + dy; //dx - |dy|

	while (true) {
		SetPoint(x1, y1, ch);

		if (x2 == x1 && y2 == y1) break;

		int e2 = 2 * error;

		if (e2 >= dy) {
			error += dy; //cu cat ma departez de linie?
			x1 += dir_x;
		}
		if (e2 <= dx) {
			error += dx;
			y1 += dir_y;
		}
	}
}

void Canvas::DrawRect(int left, int top, int right, int bottom, char ch) {
	DrawLine(left, top, right, top, ch);
	DrawLine(left, bottom, right, bottom, ch);
	DrawLine(left, bottom, left, top, ch);
	DrawLine(right, bottom, right, top, ch);
}

void Canvas::FillRect(int left, int top, int right, int bottom, char ch) {
	for (int y = top; y <= bottom; y++) {
		for (int x = left; x <= right; x++) {
			SetPoint(x, y, ch);
		}
	}
}

void Canvas::DrawCircle(int x, int y, int ray, char ch) {
	int cosinus = 0;
	int sinus = ray; //pornesc de la pi/2
	int error = 3 - 2 * ray;

	while (sinus >= cosinus) { //ma opresc la pi/4

		//desenez in toate cele 8 felii
		SetPoint(x + cosinus, y + sinus, ch);
		SetPoint(x - cosinus, y + sinus, ch);
		SetPoint(x + cosinus, y - sinus, ch);
		SetPoint(x - cosinus, y - sinus, ch);
		SetPoint(x + sinus, y + cosinus, ch);
		SetPoint(x - sinus, y + cosinus, ch);
		SetPoint(x + sinus, y - cosinus, ch);
		SetPoint(x - sinus, y - cosinus, ch);

		cosinus++; 
		if (error > 0) { //punct inafara cercului
			sinus--;
			error += 4 * (cosinus - sinus) + 10; //merg in dreapta-jos
		}
		else {
			error += 4 * cosinus + 6; //merg in dreapta 
		}
	}
}

void Canvas::FillCircle(int x, int y, int ray, char ch) {
	for (int i = y - ray; i <= y + ray; i++) {
		for (int j = x - ray; j <= x + ray; j++) {
			int dx = j - x;
			int dy = i - y;
			if (dx * dx + dy * dy <= ray * ray) {
				SetPoint(j, i, ch);
			}
		}
	}
}