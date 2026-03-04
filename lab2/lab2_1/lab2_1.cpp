#include<iostream>
#include"NumberList.h"
using namespace std;

int main() {

    NumberList L;
    L.Init();

    L.Add(4);
    L.Add(1);
    L.Add(3);
    L.Add(2);

    cout << "Lista L inainte de sortare: ";
    L.Print();

    L.Sort();
    cout << "Lista L dupa sortare: ";
    L.Print();

    return 0;
}