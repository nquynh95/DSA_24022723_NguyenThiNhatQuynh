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
    int deleteTail() {
        if (size == 0) return -1;
        return a[--size];
    }
    bool isEmpty() {
        return size == 0;
    }
    int getSize() {
        return size;
    }
    int getTail() {
        if (size == 0) return -1;
        return a[size - 1];
    }
};

struct Stack {
    List list;

    bool isEmpty() {
        return list.isEmpty();
    }
    void push(int item) {
        list.insertTail(item);
    }
    int pop() {
        return list.deleteTail();
    }
    int size() {
        return list.getSize();
    }
    int top() {
        return list.getTail();
    }
};

int main() {

}

