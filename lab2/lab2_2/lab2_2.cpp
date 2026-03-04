using namespace std;
#include <iostream>
#include "Student.h"
#include "Compare.h"

int main()
{
    Student A, B;
    
    A.Set_Name("Andreea");
    A.Set_MathGrade(4.5f);
    A.Set_EnglishGrade(9.0f);
    A.Set_HistoryGrade(10.0f);
    
    B.Set_Name("Bianca");
    B.Set_MathGrade(5.0f);
    B.Set_EnglishGrade(7.5f);
    B.Set_HistoryGrade(2.7f);

    cout << A.GetName() << "\n";
    cout << "Medie: " << A.Get_AverageGrade() << '\n';
    cout << "Mate: " << A.Get_MathGrade() << '\n';
    cout << "Engleza: " << A.Get_EnglishGrade() << '\n';
    cout << "Istorie: " << A.Get_HistoryGrade() << '\n';
    cout << '\n';

    cout << B.GetName() << "\n";
    cout << "Medie: " << B.Get_AverageGrade() << '\n';
    cout << "Mate: " << B.Get_MathGrade() << '\n';
    cout << "Engleza: " << B.Get_EnglishGrade() << '\n';
    cout << "Istorie: " << B.Get_HistoryGrade() << '\n';
    cout << '\n';

    cout << "Comparatie nume: " << Compare_Names(A, B) << '\n';
    cout << "Comparatie note mate: " << Compare_Math_Grades(A, B) << '\n';
    cout << "Comparatie note engleza: " << Compare_English_Grades(A, B) << '\n';
    cout << "Comparatie note istorie: " << Compare_History_Grades(A, B) << '\n';
    cout << "Comparatie medie: " << Compare_Average_Grades(A, B) << '\n';
    cout << '\n';

    return 0;
}