#include <iostream>
using namespace std;

struct PriorityQueue {
    int a[1000];
    int n;
    PriorityQueue(): n(0) {}

    int max() {
        return a[0];
    }

    bool isEmpty() {
        return n == 0;
    }

    int size() {
        return n;
    }

    void insert(int value) {
        int i = n - 1;
        while (i >= 0 && a[i] < value) {
            a[i + 1] = a[i];
            i--;
        }
        a[i + 1] = value;
        n++;
    }

    int delMax() {
        if (isEmpty()) return -1;
        int maxVal = a[0];
        for (int i = 0; i < n - 1; i++) {
            a[i] = a[i + 1];
        }
        n--;
        return maxVal;
    }
};

int main() {
    return 0;
}
