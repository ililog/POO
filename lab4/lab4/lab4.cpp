#include <iostream>
#include "Sort.h"
using namespace std;

int main()
{
    cout << "Random constructor, Insert Sort (Ascendent)\n";
    Sort s1(10, 1, 100);
    s1.Print();
    s1.InsertSort(true);
    s1.Print();
    cout << "Element count: " << s1.GetElementsCount() << '\n';
    cout << "Element at index 3: " << s1.GetElementFromIndex(3) << "\n\n";

    cout << "Initializer list constructor, Bubble Sort (Descendent)\n";
    Sort s2({ 45, 12, 78, 4, 99, 23 });
    s2.Print();
    s2.BubbleSort(false);
    s2.Print();
    cout << "Element count: " << s2.GetElementsCount() << "\n\n";

    cout << "Existing array constructor, QuickSort (Ascendent)\n";
    int arr[] = { 33, 11, 88, 55, 22 };
    Sort s3(arr, 5);
    s3.Print();
    s3.QuickSort(true);
    s3.Print();
    cout << "Element count: " << s3.GetElementsCount() << "\n\n";

    std::cout << "Variadic constructor, Insert Sort (Descendent)\n";
    Sort s4(6, 10, 50, 20, 40, 30, 60);
    s4.Print();
    s4.InsertSort(false);
    s4.Print();
    cout << "Element count: " << s4.GetElementsCount() << "\n\n";

    cout << "String Constructor, QuickSort (Descendent)\n";
    Sort s5("10,40,100,5,70");
    s5.Print();
    s5.QuickSort(false);
    s5.Print();
    cout << "Element count: " << s5.GetElementsCount() << '\n';

    return 0;
}