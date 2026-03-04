#include "NumberList.h"
#include<iostream>
#include<algorithm>
using namespace std;


void NumberList::Init() {
    count = 0; //initial am 0 elemente
}

bool NumberList::Add(int x) {
    if (count >= 10) { //am deja 10 elemente (maximul)
        return false;
    }
    numbers[count++] = x; //adaug numarul
    return true;
}

void NumberList::Sort() {
    sort(numbers, numbers + count);
}

void NumberList::Print() {
    for (int i = 0; i < count; i++) {
        cout << numbers[i] << ' ';
    }
    cout << '\n';
}