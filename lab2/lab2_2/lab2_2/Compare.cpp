#include "Compare.h"
#include<cstring>

int Compare_Names(Student& A, Student& B) {
	int rez = strcmp(A.GetName(), B.GetName());
	if (rez == 0) return 0;
	if (rez > 0) return 1;
	return -1;
}

int Compare_Math_Grades(Student& A, Student& B) {
	float grade1 = A.Get_MathGrade();
	float grade2 = B.Get_MathGrade();
	if (grade1 == grade2) return 0;
	if (grade1 > grade2) return 1;
	return -1;
}

int Compare_English_Grades(Student& A, Student& B) {
	float grade1 = A.Get_EnglishGrade();
	float grade2 = B.Get_EnglishGrade();
	if (grade1 == grade2) return 0;
	if (grade1 > grade2) return 1;
	return -1;
}

int Compare_History_Grades(Student& A, Student& B) {
	float grade1 = A.Get_HistoryGrade();
	float grade2 = B.Get_HistoryGrade();
	if (grade1 == grade2) return 0;
	if (grade1 > grade2) return 1;
	return -1;
}
int Compare_Average_Grades(Student& A, Student& B) {
	float grade1 = A.Get_AverageGrade();
	float grade2 = B.Get_AverageGrade();
	if (grade1 == grade2) return 0;
	if (grade1 > grade2) return 1;
	return -1;
}