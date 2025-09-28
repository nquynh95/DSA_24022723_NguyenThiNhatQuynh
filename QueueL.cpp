#include <iostream>
using namespace std;

const int MAX = 1000;

struct List {
    int a[MAX];
    int size;
    List() : size(0) {}

    void insertTail(int n) {
        if (size < MAX) a[size++] = n;
    }
    int deleteHead() {
        if (size == 0) return -1;
        int val = a[0];
        for (int i = 0; i < size - 1; i++) {
            a[i] = a[i + 1];
        }
        size--;
        return val;
    }
    bool isEmpty() {
        return size == 0;
    }
    int getHead() {
        if (size == 0) return -1;
        return a[0];
    }
    int getSize() {
        return size;
    }
};

struct Queue {
    List list;

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

