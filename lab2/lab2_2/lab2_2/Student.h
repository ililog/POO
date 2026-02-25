#pragma once
class Student {

private:
	char name[51];
	float math_grade, english_grade, history_grade;
public:
	void Init();

	const char* GetName (); //pun const ca sa nu pot modifica valoarea indicata de pointer
	float Get_MathGrade(); //nu pun const pentru ca oricum mi se da o copie a valorii, nu un pointer 
	float Get_EnglishGrade();
	float Get_HistoryGrade();

	void Set_Name(const char* student_name); //pun const ca sa pot da ca argument siruri de caractere constante 
											 //(ex: s.Set_Name("Maria") )
	void Set_MathGrade(float grade);
	void Set_EnglishGrade(float grade);
	void Set_HistoryGrade(float grade);

	float Get_AverageGrade();
};