using namespace std;
#include <iostream>
#include "Canvas.h"

int main()
{
    Canvas canvas(60, 20);

    canvas.DrawRect(2, 2, 20, 8, '#');
    canvas.FillRect(5, 4, 17, 6, '*');
    canvas.DrawLine(25, 2, 50, 8, '-');
    canvas.DrawCircle(40, 10, 5, 'O');
    canvas.FillCircle(15, 14, 4, '@');
    canvas.SetPoint(30, 15, 'X');
    cout << "Desenul initial\n";
    canvas.Print();
    canvas.Clear();
    cout << "Desenul dupa stergere\n";
    canvas.Print();

    return 0;
}
