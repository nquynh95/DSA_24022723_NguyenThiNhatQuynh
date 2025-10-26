#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int n) : data(n), next(nullptr) {}
};

struct LinkedList {
    Node* head;
    Node* tail;
    int size;
    LinkedList() : head(nullptr), tail(nullptr), size(0) {}

    void insertTail(int x) {
        Node* newNode = new Node(x);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    }
    int deleteHead() {
        if (!head) return -1;
        Node* temp = head;
        int val = temp->data;
        head = head->next;
        if (!head) tail = nullptr;
        delete temp;
        size--;
        return val;
    }
    bool isEmpty() {
        return head == nullptr;
    }
    int getHead() {
        if (!head) return -1;
        return head->data;
    }
    int getSize() {
        return size;
    }
};

struct Queue {
    LinkedList list;

    bool isEmpty() {
        return list.isEmpty();
    }
    void enqueue(int item) {
        list.insertTail(item);
    }
    int dequeue() {
        return list.deleteHead();
    }
    int peek() {
        return list.getHead();
    }
    int size() {
        return list.getSize();
    }
};

int main() {

}
