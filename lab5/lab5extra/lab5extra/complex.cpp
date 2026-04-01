#include "complex.h"
#include<stdio.h>
Complex::Complex() : Complex(0,0){}

Complex::Complex(double real, double imag) {
	real_data = real;
	imag_data = imag;
}

bool Complex::is_real() const {
	return (imag() == 0.0);
}

double Complex::real() const {
	return real_data;
}

double Complex::imag() const {
	return imag_data;
}

double Complex::abs() const {
	return sqrt(real() * real() + imag() * imag());
}

Complex Complex::conjugate() const {
	return { real(), -imag() };
}

Complex& Complex::operator()(double real, double imag) {
	this->real_data = real;
	this->imag_data = imag;
	return *this;
}

Complex& Complex::operator++() {
	this->real_data++;
	return *this;
}
Complex Complex::operator++(int) {
	Complex old = *this;
	++(*this);
	return old;
}
Complex& Complex::operator--() {
	this->real_data--;
	return *this;
}
Complex Complex::operator--(int){
	Complex old = *this;
	--(*this);
	return old;
}

Complex operator+(const Complex& l, const Complex& r) {
	double a = l.real() + r.real();
	double b = l.imag() + r.imag();
	Complex x(a, b);
	return x;
}
Complex operator+(const Complex& l, double r) {
	double a = l.real() + r;
	double b = l.imag();
	Complex x(a, b);
	return x;
}
Complex operator+(double l, const Complex& r) {
	double a = r.real() + l;
	double b = r.imag();
	Complex x(a, b);
	return x;
}

Complex operator-(const Complex& l, const Complex& r) {
	double a = l.real() - r.real();
	double b = l.imag() - r.imag();
	Complex x(a, b);
	return x;
}
Complex operator-(const Complex& l, double r) {
	double a = l.real() - r;
	double b = l.imag();
	Complex x(a, b);
	return x;
}
Complex operator-(double l, const Complex& r) {
	double a = l - r.real();
	double b = -r.imag();
	Complex x(a, b);
	return x;
}

Complex operator*(const Complex& l, const Complex& r) {
	double a = l.real() * r.real() - l.imag() * r.imag();
	double b = l.real() * r.imag() + l.imag() * r.real();
	Complex x(a, b);
	return x;
}
Complex operator*(const Complex& l, double r) {
	double a = l.real() * r;
	double b = l.imag() * r;
	Complex x(a, b);
	return x;
}
Complex operator*(double l, const Complex& r) {
	double a = l * r.real();
	double b = l * r.imag();
	Complex x(a, b);
	return x;
}

bool operator==(const Complex& l, const Complex& r) {
	return (l.real() == r.real() && l.imag() == r.imag());
}

bool operator!=(const Complex& l, const Complex& r) {
	return (l.real() != r.real() || l.imag() != r.imag());
}

Complex operator-(const Complex& obj) {
	Complex x(-obj.real(), -obj.imag());
	return x;
}

std::ostream& operator<<(std::ostream& out, const Complex& complex) {
	double a = complex.real();
	double b = complex.imag();
	if (a == 0.0 && b == 0.0) {
		out << "0";
		return out;
	}
	if (a == 0) {
		out << b << "i";
		return out;
	}
	if (b == 0) {
		out << a;
		return out;
	}
	out << a;
	if (b < 0) out << " - " << abs(b) << "i";
	else out << " + " << abs(b) << "i";
	return out;
}