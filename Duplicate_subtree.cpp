#include <iostream>
#include <unordered_map>
#include <string>

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int data) : data(data), left(nullptr), right(nullptr) {}
};

std::string inorder(Node* root, std::unordered_map<std::string, int>& m) {
    if (root == nullptr) {
        return "";
    }

    std::string s = "(";
    s += inorder(root->left, m);
    s += std::to_string(root->data);
    s += inorder(root->right, m);
    s += ")";
    
    if (m.find(s) != m.end() && m[s] == 1) {
        std::cout << root->data << " ";
    }

    if (m.find(s) != m.end()) {
        m[s] += 1;
    } else {
        m[s] = 1;
    }

    return s;
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->left = new Node(2);
    root->right->left->left = new Node(4);

    std::unordered_map<std::string, int> m;
    inorder(root, m);

    // Clean up dynamically allocated memory
    delete root->right->left->left;
    delete root->right->left;
    delete root->left->left;
    delete root->left;
    delete root;

    return 0;
}
