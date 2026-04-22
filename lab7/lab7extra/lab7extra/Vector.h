#pragma once
template<typename T>
class Vector {
private:
	T* elements;
	int size;
	int capacity;

	void expand_capacity() {
		capacity *= 2;
		T* new_elements = new T[capacity];
		for (int i = 0; i < size; i++) {
			new_elements[i] = elements[i];
		}
		delete[] elements;
		elements = new_elements;
	}
public:
	Vector() : size(0), capacity(1) {
		elements = new T[capacity];
	}
	Vector(const Vector& other) : size(other.size), capacity(other.capacity) {
		elements = new T[capacity];
		for (int i = 0; i < size; i++) {
			elements[i] = other.elements[i];
		}
	}
	
	Vector(const Vector&& other) : size(other.size), capacity(other.capacity) {
		other.size = 0;
		other.capacity = 0;
		delete[] other.elements; other.elements = nullptr;
	}
	
	~Vector() {
		delete elements;
	}

	T& operator[](int index) const {
		return elements[index];
	}
	
	void insert(int poz, T val) {
		if (poz < 0 || poz > size) return;
		if (size == capacity) expand_capacity();
		for (int i = size; i > poz; i--) {
			elements[i] = elements[i - 1];
		}
		elements[poz] = val;
		size++;
	}

	void remove(int poz) {
		if (poz < 0 || poz > size) return;
		if (size == 0) return;
		for (int i = poz; i < size - 1; i++) {
			elements[i] = elements[i + 1];
		}
		size--;
	}

	void sort(int (*cmp)(T, T)) {
		for (int i = 0; i < size - 1; i++) {
			for (int j = i + 1; j < size; j++) {
				if (cmp(elements[i], elements[j]) == 1) {
					T temp = elements[i];
					elements[i] = elements[j];
					elements[j] = temp;
				}
			}
		}
	}

	void sort() {
		for (int i = 0; i < size - 1; i++) {
			for (int j = i + 1; j < size; j++) {
				if (elements[i] < elements[j]) {
					T temp = elements[i];
					elements[i] = elements[j];
					elements[j] = temp;
				}
			}
		}
	}

	void print() const {
		for (int i = 0; i < size; i++) {
			std::cout << elements[i] << ' ';
		}
		std::cout << '\n';
	}
};