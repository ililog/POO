#pragma once
template <typename K, typename V>
class MapElement {
public:
	K key;
	V value;
	int index;
};

template <typename K, typename V>
class Map {
private:
	MapElement<K, V>* data;
	int size;
	int capacity;

	void expand_capacity() {
		capacity = 2 * capacity;
		MapElement<K, V>* new_data = new MapElement<K, V>[capacity];
		for (int i = 0; i < size; i++) {
			new_data[i] = data[i];
		}
		delete[] data;
		data = new_data;
	}
public:
	Map() : size(0), capacity(1) {
		data = new MapElement<K, V> [1];
	}
	~Map() {
		delete[] data;
	}
	MapElement<K, V>* begin() const {
		return data;
	}
	MapElement<K, V>* end() const {
		return data + size;
	}

	V& operator[](const K& key) {
		for (int i = 0; i < size; i++) {
			if (data[i].key == key) {
				return data[i].value;
			}
		}
		if (size == capacity) expand_capacity();
		data[size].key = key;
		data[size].index = size;
		data[size].value = V();
		return data[size++].value;
	}

	void Set(const K& key, const V& value) {
		(*this)[key] = value;
	}

	bool Get(const K& key, V& value) const {
		for (int i = 0; i < size; i++) {
			if (data[i].key == key) {
				value = data[i].value;
				return true;
			}
		}
		return false;
	}

	int Count() const {
		return size;
	}

	void Clear() {
		delete[] data;
		data = new MapElement<K, V>[1];
		size = 0;
		capacity = 1;
	}

	bool Delete(const K& key) {
		for (int i = 0; i < size; i++) {
			if (data[i].key == key) {
				for (int j = i; j < size - 1; j++) {
					data[j] = data[j + 1];
					data[j].index = j;
				}
				size--;
				return true;
			}
		}
		return false;
	}

	bool Includes(const Map<K, V>& map) const {
		for (auto i = map.begin(); i != map.end(); i++) {
			bool found = 0;
			for (int j = 0; j < size; j++) {
				if (data[j].key == i->key) {
					found = 1;
					break;
				}
			}
			if (!found) return false;
		}
		return true;
	}
};