#include <iostream>
#include "Tree.h"
bool isGreaterThan(const int& param, const int& node_val) {
    return node_val > param;
}

bool isLessThan(const int& param, const int& node_val) {
    return node_val < param;
}

int main() {
    Tree<int> myTree;

    myTree.add_node(nullptr, 100);

    TreeNode<int>* root = myTree.find(100);
    std::cout << "Root: " << root->get_value() << '\n';

    myTree.add_node(root, 30);
    myTree.add_node(root, 20);
    myTree.add_node(root, 10);
    myTree.sort(root, isLessThan);
    std::cout << "Ordered first level: ";
    for (int i = 0; i < root->get_no_children(); i++) {
        std::cout << root->get_child(i)->get_value() << " ";
    }
    std::cout << '\n';
    
    myTree.insert(root, 15, 1);

    TreeNode<int>* child_10 = myTree.get_node(root, 0); 
    myTree.add_node(child_10, 5);
    myTree.add_node(child_10, 7);
    std::cout << "Ordered first level: ";
    for (int i = 0; i < root->get_no_children(); i++) {
        std::cout << root->get_child(i)->get_value() << " ";
    }
    std::cout << '\n';

    std::cout << "Second level: ";
    for (int i = 0; i < child_10->get_no_children(); i++) {
        std::cout << child_10->get_child(i)->get_value() << " ";
    }
    std::cout << '\n';

    std::cout << "Total descendants in the tree: " << myTree.count(nullptr) << "\n\n";

    TreeNode<int>* exactMatch = myTree.find(15);
    if (exactMatch != nullptr) {
        std::cout << "Node value equal to 15: " << exactMatch->get_value() << "\n";
    }

    TreeNode<int>* customMatch = myTree.find(25, isGreaterThan);
    if (customMatch != nullptr) {
        std::cout << "Node value greater than 25: " << customMatch->get_value() << "\n\n";
    }

    myTree.delete_node(child_10);

    std::cout << "Deleted node 10 and its children\n";
    std::cout << "Total descendants left in the tree: " << myTree.count(nullptr) << "\n";
    
    return 0;
}