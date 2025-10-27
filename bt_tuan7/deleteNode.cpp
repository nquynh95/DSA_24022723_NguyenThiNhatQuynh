#include <iostream>
using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;
    Node(int k) : key(k), left(nullptr), right(nullptr) {}
};

Node* deleteNode(Node* root, int key) {
    if (!root) return nullptr;

    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else {
        //node cần xóa tìm thấy mà không có con
        if (!root->left && !root->right) {
            delete root;
            return nullptr;
        }
        //node có 1 con
        else if (!root->left) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if (!root->right) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        //có 2 con
        else {
            // tìm node nhỏ nhất bên phải
            Node* succ = root->right;
            while (succ->left) succ = succ->left;
            root->key = succ->key;
            root->right = deleteNode(root->right, succ->key);
        }
    }
    return root;
}

int main() {
}
