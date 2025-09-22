#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
    Node(int n) : data(n), prev(nullptr), next(nullptr) {}
};

struct DoublyList {
    Node* head;
    Node* tail;
    DoublyList() : head(nullptr), tail(nullptr) {}

    //truy cập, O(n)
    int get(int i) {
        Node* current = head;
        for (int j = 0; j < i; j++) {
            current = current->next;
        }
        return current->data;
    }

    //chèn đầu, O(1)
    void insertHead(int n) {
        Node* newNode = new Node(n);
        if (!head) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    //chèn cuối, O(1)
    void insertTail(int n) {
        Node* newNode = new Node(n);
        if (!tail) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    //chèn vào vị trí i, O(n)
    void insertAt(int i, int n) {
        if (i == 0) {
            insertHead(n);
            return;
        }
        Node* current = head;
        for (int j = 0; j < i-1 && current; j++) {
            current = current->next;
        }
        if (current == tail) {
            insertTail(n);
            return;
        }
        Node* newNode = new Node(n);
        newNode->next = current->next;
        newNode->prev = current;
        current->next->prev = newNode;
        current->next = newNode;
    }

    //xóa đầu, O(1)
    void deleteHead() {
        if (!head) return;
        Node* temp = head;
        head = head->next;
        if (head) head->prev = nullptr;
        else tail = nullptr;
        delete temp;
    }

    //xóa cuối, O(1)
    void deleteTail() {
        if (!tail) return;
        Node* temp = tail;
        tail = tail->prev;
        if (tail) tail->next = nullptr;
        else head = nullptr;
        delete temp;
    }

    //xóa vị trí i, O(n)
    void deleteAt(int i) {
        if (i == 0) {
            deleteHead();
            return;
        }
        Node* current = head;
        for (int j = 0; j < i && current; j++) {
            current = current->next;
        }
        if (current == tail) {
            deleteTail();
            return;
        }
        current->prev->next = current->next;
        current->next->prev = current->prev;
        delete current;
    }

    //duyệt xuôi, O(n)
    void traverse() {
        Node* current = head;
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
    }

    //duyệt ngược, O(n)
    void traverseReverse() {
        Node* current = tail;
        while (current) {
            cout << current->data << " ";
            current = current->prev;
        }
    }
};

int main() {

    return 0;
}

