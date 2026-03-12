#pragma once
using namespace std;
#include<initializer_list>

class Sort
{
    // data members
    int count;
    int* v;
    void QuickSort2(int st, int dr, bool ascendent);
    int Partition(int st, int dr, bool ascendent);
public:
    // constuctors
    Sort(int count, int min, int max); //random values in [min,max]
    Sort(initializer_list<int> L); //initializer list
    Sort(int* p, int count); //existing vector
    Sort(int count, ...); //variadic parameters
    Sort(const char* s); //from a string
    ~Sort();

    //sorting methods
    void InsertSort(bool ascendent = false);
    void QuickSort(bool ascendent = false);
    void BubbleSort(bool ascendent = false);

    //utilities
    void Print();
    int  GetElementsCount();
    int  GetElementFromIndex(int index);
};
