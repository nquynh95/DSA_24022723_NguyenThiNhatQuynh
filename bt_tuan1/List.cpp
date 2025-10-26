#include <iostream>
using namespace std;

const int MAX = 1000;

struct List {
    int a[MAX];
    int size;

    List() : size(0) {}

    //truy cập, O(1)
    int get(int i) {
        if (i < 0 || i >= size) return -1;
        return a[i];
    }

    //chèn đầu, O(n)
    void insertHead(int n) {
        for (int i = size; i > 0; i--) {
            a[i] = a[i-1];
        }
        a[0] = n;
        size++;
    }

    //chèn cuối, O(1)
    void insertTail(int n) {
        a[size++] = n;
    }

    //chèn vị trí i, O(n)
    void insertAt(int i, int n) {
        if (i < 0 || i > size) return;
        for (int j = size; j > i; j--) {
            a[j] = a[j-1];
        }
        a[i] = n;
        size++;
    }

    //xóa đầu, O(n)
    void deleteHead() {
        if (size == 0) return;
        for (int i = 0; i < size-1; i++) {
            a[i] = a[i+1];
        }
        size--;
    }

    //xóa cuối, O(1)
    void deleteTail() {
        if (size == 0) return;
        size--;
    }

    //xóa vị trí i, O(n)
    void deleteAt(int i) {
        if (i < 0 || i >= size) return;
        for (int j = i; j < size-1; j++) {
            a[j] = a[j+1];
        }
        size--;
    }

    //duyệt xuôi, O(n)
    void traverse() {
        for (int i = 0; i < size; i++) {
            cout << a[i] << " ";
        }
    }

    //duyệt ngược (đệ quy), O(n)
    void traverseReverse() {
        for (int i = size-1; i >= 0; i--) {
            cout << a[i] << " ";
        }
    }
};

int main() {

    return 0;
}
