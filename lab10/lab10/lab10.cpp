#include <iostream>
#include <exception>
#include "Array.h"
using namespace std;

int main()
{
    Array<int> arr;

    // Adding items safely
    arr += 10;
    arr += 20;
    arr += 30;

    cout << "Normal insert successful. Size: " << arr.GetSize() << endl;

    try {
        cout << "Trying to access arr[1]..." << endl;
        cout << "arr[1] = " << arr[1] << endl; // Should work

        cout << "Trying to insert at index 100..." << endl;
        arr.Insert(100, 99); // Will throw!
    }
    catch (exception& e) {
        cout << "Exception Caught: " << e.what() << endl;
    }

    try {
        cout << "\nTrying to delete index -1..." << endl;
        arr.Delete(-1); // Will throw!
    }
    catch (exception& e) {
        cout << "Exception Caught: " << e.what() << endl;
    }

    return 0;
}
   