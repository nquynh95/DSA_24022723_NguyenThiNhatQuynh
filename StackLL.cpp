#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int n) : data(n), next(nullptr) {}
};

struct LinkedList {
    Node* head;
    int size;
    LinkedList() : head(nullptr), size(0) {}

    void insertHead(int x) {
        Node* newNode = new Node(x);
        newNode->next = head;
        head = newNode;
        size++;
    }
    int deleteHead() {
        if (!head) return -1;
        Node* temp = head;
        int val = temp->data;
        head = head->next;
        delete temp;
        size--;
        return val;
    }
    bool isEmpty() {
        return head == nullptr;
    }
    int getSize() {
        return size;
    }
    int getHead() {
        if (!head) return -1;
        return head->data;
    }
};

struct Stack {
    LinkedList list;

    bool isEmpty() {
        return list.isEmpty();
    }
    void push(int item) {
        list.insertHead(item);
    }
    int pop() {
        return list.deleteHead();
    }
    int size() {
        return list.getSize();
    }
    int top() {
        return list.getHead();
    }
};

int main() {

}
