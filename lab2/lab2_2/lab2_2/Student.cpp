using namespace std;
#define _CRT_SECURE_NO_WARNINGS
#include<cstring>
#include "Student.h"

void Student::Init() {
	name[0] = 0;
	math_grade = 0.0f;
	english_grade = 0.0f;
	history_grade = 0.0f;
}

const char* Student::GetName() {
	return name;
}

float Student::Get_MathGrade() {
	return math_grade;
}

float Student::Get_EnglishGrade() {
	return english_grade;
}

float Student::Get_HistoryGrade() {
	return history_grade;
}

void Student::Set_Name(const char* student_name) {
	strncpy(name, student_name, 50);
	name[50] = 0;
}

void Student::Set_MathGrade(float grade) {
	if (1.0f <= grade && grade <= 10.0) {
		math_grade = grade;
	}
}

void Student::Set_EnglishGrade(float grade) {
	if (1.0f <= grade && grade <= 10.0) {
		english_grade = grade;
	}
}

void Student::Set_HistoryGrade(float grade) {
	if (1.0f <= grade && grade <= 10.0) {
		history_grade = grade;
	}
}

float Student::Get_AverageGrade() {
	float valid_values[3];
	int nr_valid = 0;
	if (math_grade > 0.0f) {
		valid_values[nr_valid++] = math_grade;
	}
	if (english_grade > 0.0f) {
		valid_values[nr_valid++] = english_grade;
	}
	if (history_grade > 0.0f) {
		valid_values[nr_valid++] = history_grade;
	}
	float sum = 0.0f;
	for (int i = 0; i < nr_valid; i++) {
		sum = sum + valid_values[i];
	}
	if (nr_valid > 0) {
		return sum / (float)(nr_valid);
	}
	return 0;
}