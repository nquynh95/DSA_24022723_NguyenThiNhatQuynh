#include <iostream>
using namespace std;

const int MAX = 1000;

struct BinaryHeap {
    int a[MAX];
    int n;
    BinaryHeap() : n(0) {}

    bool isEmpty() {//O(1)
        return n == 0;
    }
    int size() {//O(1)
        return n;
    }
    int max() {//O(1)
        return a[0];
    )

    //di chuyển phần tử lên trên
    void swim(int i) { //O(log n)
        while (i > 0) {
            int parent = (i - 1) / 2;
            if (a[i] <= a[parent]) break;
            swap(a[i], a[parent]);
            i = parent;
        }
    }

    //chuyển phần tử xuống
    void sink(int i) {
        while (2 * i + 1 < n) {
            int left = 2 * i + 1;
            int right = 2 * i + 2;
            int largest = i;
            // So sánh với con trái
            if (a[left] > a[largest])
                largest = left;
            // So sánh với con phải (nếu tồn tại)
            if (right < n && a[right] > a[largest])
                largest = right;
            // Nếu node hiện tại đã là lớn nhất thì dừng
            if (largest == i) break;
            swap(a[i], a[largest]);
            i = largest;
        }
    }

    void insert(int value) { //O(log n)
        a[++n] = value;
        swim(n);
    }

    int delMax() { //O(log n)
        if (isEmpty()) return -1;
        int maxVal = a[0];
        swap(a[0], a[n--]);
        sink(1);
        return maxVal;
    }
};

int main() {

}
