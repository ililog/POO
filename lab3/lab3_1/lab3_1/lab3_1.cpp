using namespace std;
#include <iostream>
#include "Math.h"

int main()
{
    cout << "Add(2,3) = " << Math::Add(2, 3) << '\n';
    cout << "Add(2,3,4) = " << Math::Add(2, 3, 4) << '\n';
    cout << "Add(2.4,3.9) = " << Math::Add(2.4, 3.9) << '\n';
    cout << "Add(2.4,3.9,5.1) = " << Math::Add(2.4, 3.9, 5.1) << '\n';

    cout << "Mul(2,3) = " << Math::Mul(2, 3) << '\n';
    cout << "Mul(2,3,4) = " << Math::Mul(2, 3, 4) << '\n';
    cout << "Mul(2.4,3.9) = " << Math::Mul(2.4, 3.9) << '\n';
    cout << "Mul(2.4,3.9,5.1) = " << Math::Mul(2.4, 3.9, 5.1) << '\n';
       
    cout << "VariadicAdd(1,2,3,4,5,6) = " << Math::Add(1,2,3,4,5,6) << '\n';

    char* rez = Math::Add("123 ", "456");
    cout << "StringAdd: " << rez << '\n';
    return 0;
}