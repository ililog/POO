#pragma once
template<typename T>

class TreeNode {
private:
	T value;
	TreeNode<T>* parent;
	TreeNode<T>** children;
	int no_children;
	int capacity;

	void expand_capacity() {
		capacity *= 2;
		TreeNode<T>** newchildren = new TreeNode<T>*[capacity];
		for (int i = 0; i < no_children; i++) {
			newchildren[i] = children[i];
		}
		delete[] children;
		children = newchildren;
	}
public:
	TreeNode(const T& val, TreeNode<T>* p = nullptr) { //am creat un nod cu potentialul de a avea 2 fii
		value = val;
		parent = p;
		no_children = 0; capacity = 2;
		children = new TreeNode<T>*[capacity];
	}

	~TreeNode() {
		for (int i = 0; i < no_children; i++) { //trebuie sa sterg fiecare obiect in parte
			delete children[i];
		}
		delete[] children;
	}

	const T& get_value() const {
		return value;
	}

	TreeNode<T>* get_parent() const {
		return parent;
	}
	
	int get_no_children() const {
		return no_children;
	}

	TreeNode<T>* get_child(int index) const {
		if (0 <= index && index < no_children) {
			return children[index];
		}
		return nullptr;
	}

	void add_child(TreeNode<T>* child) {
		if (no_children == capacity) expand_capacity();
		children[no_children++] = child;
	}

	void insert_child(TreeNode<T>* child, int index) {
		if (index < 0) index = 0;
		if (index > no_children) index = no_children;
		if (no_children == capacity) expand_capacity();

		for (int i = no_children; i > index; i--) {
			children[i] = children[i - 1];
		}
		children[index] = child;
		no_children++;
	}

	void remove_child(TreeNode<T>* child) {
		for (int i = 0; i < no_children; i++) {
			if (children[i] == child) {
				for (int j = i; j < no_children-1; j++) {
					children[j] = children[j + 1];
				}
				no_children--;
				break;
			}
		}
	}

	void swap_children(int i, int j) {
		TreeNode<T>* t = children[i];
		children[i] = children[j];
		children[j] = t;
	}
};

template<typename T>
class Tree {
private:
	TreeNode<T>* root;

	TreeNode<T>* private_find(TreeNode<T>* current, const T& val, bool (*cmp)(const T&, const T&)) const {
		if (current == nullptr) return nullptr;
		bool match = 0;
		if (cmp != nullptr) {
			match = cmp(val, current->get_value());
		}
		else {
			match = (val == current->get_value());
		}
		if (match == 1) return current;
		int num_children = current->get_no_children();
		for (int i = 0; i < num_children; i++) {
			TreeNode<T>* rez = private_find(current->get_child(i), val, cmp);
			if (rez != nullptr) return rez;
		}
		return nullptr;
	}
public:
	Tree() : root(nullptr) {}
	~Tree() {
		delete root;
	}
	void add_node(TreeNode<T>* parent, const T& value) {
		TreeNode<T>* newNode = new TreeNode<T>(value, parent);
		if (parent == nullptr) {
			if (root) delete root;
			root = newNode;
		}
		else {
			parent->add_child(newNode);
		}
	}

	TreeNode<T>* get_node(TreeNode<T>* parent, int child_index) const {
		if (parent == nullptr) parent = root;
		if (0 <= child_index && child_index < parent->get_no_children()) {
			return parent->get_child(child_index);
		}
		return nullptr;
	}

	void delete_node(TreeNode<T>* node) {
		if (!node) return;

		if (node->get_parent()) {
			node->get_parent()->remove_child(node);
		}
		if (node == root) {
			root = nullptr;
		}
		delete node;
	}

	void insert(TreeNode<T>* parent, const T& value, int child_index) {
		if (parent == nullptr) {
			add_node(nullptr, value); // inserez in radacina
			return;
		}
		TreeNode<T>* newNode = new TreeNode<T>(value, parent);
		parent->insert_child(newNode, child_index);
	}

	int count(TreeNode<T>* node) const {
		if (node == nullptr) node = root;

		if (node == nullptr) return 0;

		int direct_children = node->get_no_children();
		int total = direct_children;
		for (int i = 0; i < direct_children; i++) {
			total += count(node->get_child(i));
		}
		return total;
	}

	TreeNode<T>* find(const T& val, bool (*cmp)(const T&, const T&) = nullptr) const {
		return private_find(root, val, cmp);
	}

	void sort(TreeNode<T>* parent, bool (*cmp)(const T&, const T&) = nullptr) {
		if (parent == nullptr) {
			parent = root;
		}
		int n = parent->get_no_children();
		if (!parent || n <= 1) return;

		for (int i = 0; i < n - 1; i++){
			for (int j = i + 1; j < n; j++) {
				T vali = parent->get_child(i)->get_value();
				T valj = parent->get_child(j)->get_value();
				bool flag = 0;
				if (cmp != nullptr) {
					if (cmp(vali, valj)) flag = 1;
				}
				else {
					if (vali < valj) flag = 1;
				}
				if (flag) {
					parent->swap_children(i, j);
				}
			}
		}

	}
};