#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int n) : data(n), next(nullptr) {}
};

struct LinkedList {
    Node* head;
    LinkedList() : head(nullptr) {}

    //truy cập, O(n)
    int get(int i) {
        Node* current = head;
        for (int j = 0; j < i; j++) {
            current = current->next;
        }
        return current->data;
    }

    //chèn vào đầu, O(1)
    void insertHead(int n) {
        Node* newNode = new Node(n);
        newNode->next = head;
        head = newNode;
    }

    //chèn vào cuối, O(n)
    void insertTail(int n) {
        Node* newNode = new Node(n);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }

    //chèn vào vị trí i, O(n)
    void insertAt(int i, int n) {
        if (i == 0) {
            insertHead(n);
            return;
        }
        Node* newNode = new Node(n);
        Node* current = head;
        for (int j = 0; j < i - 1; j++) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }

    //xóa đầu, O(1)
    void deleteHead() {
        if (!head) return;
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    //xóa cuối, O(n)
    void deleteTail() {
        if (!head) return;
        if (!head->next) {
            delete head;
            head = nullptr;
            return;
        }
        Node* current = head;
        while(current->next->next) {
            current = current->next;
        }
        delete current->next;
        current->next = nullptr;
    }

    //xóa vị trí i, O(n)
    void deleteAt(int i) {
        if (i == 0) {
            deleteHead();
            return;
        }
        Node* current = head;
        for(int j = 0; j < i-1; j++) {
            current = current->next;
        }
        Node* temp = current->next;
        current->next = temp->next;
        delete temp;
    }

    //duyệt xuôi, O(n)
    void traverse() {
        Node* current = head;
        while(current) {
            cout << current->data << " ";
            current = current->next;
        }
    }

    //duyệt ngược (đệ quy), O(n)
    void traverseReverse(Node* current) {
        if (!current) return;
        traverseReverse(current->next);
        cout << current->data << " ";
    }

    void traverseReverse() {
        traverseReverse(head);
    }
};

int main() {

    return 0;
}

