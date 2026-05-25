#pragma once
#include<iostream>
#include<exception>
using namespace std;

class OutOfRangeException : public exception {
    virtual const char* what() const throw() {
        return "Index out of bounds";
    }
};

class Compare //interfata
{
public:
    virtual int CompareElements(void* e1, void* e2) = 0;
};

template<class T>
class ArrayIterator
{
private:
    T** List;
    int Current; // pozitia curenta
    int Size; //size of list
public:
    ArrayIterator() : List(nullptr), Current(0), Size(0) {}
    ArrayIterator(T** list, int current, int size) : List(list), Current(current), Size(size) {}
    ArrayIterator& operator ++ () {
        Current++;
        return *this;
    }
    ArrayIterator& operator -- () {
        Current--;
        return *this;
    }
    bool operator= (ArrayIterator<T>& other) {
        List = other.List;
        Current = other.Current;
        Size = other.Size;
        return true;
    }
    bool operator!=(ArrayIterator<T>& other) {
        return Current != other.Current; //pozitii diferite
    }
    T* GetElement() {
        if (Current < 0 || Current >= Size) return nullptr;
        return List[Current];
    }
};
template<class T>
class Array
{
private:
    T** List; // lista cu pointeri la obiecte de tipul T*
    int Capacity; // dimensiunea listei de pointeri
    int Size; // cate elemente sunt in lista
    void expand_capacity(int req) {
        if (req <= Capacity) return;
        if (Capacity == 0) Capacity = 1;
        while (Capacity < req) {
            Capacity *= 2;
        }
        T** newList = new T* [Capacity];
        for (int i = 0; i < Size; i++) {
            newList[i] = List[i];
        }
        delete[] List;
        List = newList;
    }
public:
    Array() : List(nullptr), Capacity(0), Size(0){} // Lista nu e alocata, Capacity si Size = 0
    ~Array() { // destructor
        for (int i = 0; i < Size; i++) delete List[i];
        delete[] List;
    } 
    Array(int capacity) : Capacity(capacity), Size(0){ // Lista e alocata cu 'capacity' elemente
        List = new T * [Capacity];
    } 
    Array(const Array<T>& otherArray) { // constructor de copiere
        Capacity = otherArray.Capacity;
        Size = otherArray.Size;
        List = new T* [Capacity];
        for (int i = 0; i < Size; i++) {
            List[i] = new T(*otherArray.List[i]);
        }
    } 

    T& operator[] (int index) { // arunca exceptie daca index este out of range
        if (index < 0 || index >= Size) {
            throw OutOfRangeException();
        }
        return *(List[index]);
    }
    const Array<T>& operator+=(const T& newElem) { // adauga un element de tipul T la sfarsitul listei si returneaza this
        expand_capacity(Size+1);
        List[Size++] = new T(newElem);
        return *this;
    }
    const Array<T>& Insert(int index, const T& newElem) { // adauga un element pe pozitia index, retureaza this. Daca index e invalid arunca o exceptie
        if (index < 0 || index > Size) {
            throw OutOfRangeException();
        }
        expand_capacity(Size + 1);
        for (int i = Size; i > index; i--) {
            List[i] = List[i - 1];
        }
        List[index] = new T(newElem);
        Size++;
        return *this;
    }
    const Array<T>& Insert(int index, const Array<T> otherArray) { // adauga o lista pe pozitia index, retureaza this. Daca index e invalid arunca o exceptie
        if (index < 0 || index > Size) {
            throw OutOfRangeException();
        }
        expand_capacity(Size + otherArray.Size);
        for (int i = Size - 1; i >= index; i--) {
            List[i + otherArray.Size] = List[i];
        }
        for (int i = 0; i < otherArray.Size; i++) {
            List[index + i] = new T(*otherArray.List[i]);
        }
        Size += otherArray.Size;
        return *this;
    }
    const Array<T>& Delete(int index) { // sterge un element de pe pozitia index, returneaza this. Daca index e invalid arunca o exceptie
        if (index < 0 || index >= Size) {
            throw OutOfRangeException();
        }
        delete List[index];
        for (int i = index; i < Size - 1; i++) {
            List[i] = List[i + 1];
        }
        Size--;
        return *this;
    }
    bool operator=(const Array<T>& otherArray) {
        if (this == &otherArray) return true;

        for (int i = 0; i < Size; i++) {
            delete List[i];
        }
        delete[] List;
        Capacity = otherArray.Capacity;
        Size = otherArray.Size;
        List = new T* [Capacity];
        for (int i = 0; i < Size; i++) {
            List[i] = new T(*otherArray.List[i]);
        }
        return true;
    }

    void Sort() { // sorteaza folosind comparatia intre elementele din T
        for (int i = 0; i < Size - 1; i++) {
            for (int j = i + 1; j < Size; j++) {
                if (*List[j] < *List[i]) {
                    T* aux = List[i];
                    List[i] = List[j];
                    List[j] = aux;
                }
            }
        }
    }
    void Sort(int(*compare)(const T&, const T&)) { // sorteaza folosind o functie de comparatie
        for (int i = 0; i < Size - 1; i++) {
            for (int j = i + 1; j < Size; j++) {
                if (compare(*List[j], *List[i]) > 0) {
                    T* aux = List[i];
                    List[i] = List[j];
                    List[j] = aux;
                }
            }
        }
    }
    void Sort(Compare* comparator) { // sorteaza folosind un obiect de comparatie
        if (comparator == nullptr) return;
        for (int i = 0; i < Size - 1; i++) {
            for (int j = i + 1; j < Size; j++) {
                if (comparator->CompareElements(*List[j],*List[i]) > 0) {
                    T* aux = List[i];
                    List[i] = List[j];
                    List[j] = aux;
                }
            }
        }
    }
    // functii de cautare - returneaza pozitia elementului sau -1 daca nu exista
    int BinarySearch(const T& elem) { // cauta un element folosind binary search in Array
        int st = 0, dr = Size - 1;
        while (st <= dr) {
            int mid = (st + dr) / 2;
            if (*List[mid] == elem) {
                return mid;
            }
            if (*List[mid] < elem) st = mid + 1;
            else dr = mid - 1;
        }
        return -1;
    }
    int BinarySearch(const T& elem, int(*compare)(const T&, const T&)) {//  cauta un element folosind binary search si o functie de comparatie
        int st = 0, dr = Size - 1;
        while (st <= dr) {
            int mid = (st + dr) / 2;
            if (compare(*List[mid], elem) == 0) {
                return mid;
            }
            if (compare(*List[mid], elem) < 0) st = mid + 1;
            else dr = mid - 1;
        }
        return -1;
    }
    int BinarySearch(const T& elem, Compare* comparator) {//  cauta un element folosind binary search si un comparator
        int st = 0, dr = Size - 1;
        while (st <= dr) {
            int mid = (st + dr) / 2;
            if (comparator->CompareElements(*List[mid], elem) == 0) {
                return mid;
            }
            if (comparator->CompareElements(*List[mid], elem) < 0) st = mid + 1;
            else dr = mid - 1;
        }
        return -1;
    }
    int Find(const T& elem) { // cauta un element in Array
        for (int i = 0; i < Size; i++) {
            if (*List[i] == elem) return i;
        }
        return -1;
    }
    int Find(const T& elem, int(*compare)(const T&, const T&)) {//  cauta un element folosind o functie de comparatie
        for (int i = 0; i < Size; i++) {
            if (compare(*List[i],elem) == 0) return i;
        }
        return -1;
    }
    int Find(const T& elem, Compare* comparator) {//  cauta un element folosind un comparator
        if (comparator == nullptr) return -1;
        for (int i = 0; i < Size; i++) {
            if (comparator->CompareElements(List[i], elem) == 0) return i;
        }
        return -1;
    }
    int GetSize() {
        return Size;
    }
    int GetCapacity() {
        return Capacity;
    }

    ArrayIterator<T> GetBeginIterator() {
        return ArrayIterator<T>(List, 0, Size);
    }
    ArrayIterator<T> GetEndIterator() {
        return ArrayIterator<T>(List, Size, Size);
    }
};
