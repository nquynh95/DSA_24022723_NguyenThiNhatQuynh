#include <iostream>
#include <string>
using namespace std;

const int MAX = 1000;

struct SymbolTable {
    string keys[MAX];
    string values[MAX];
    int n;

    SymbolTable() : n(0) {}

    //kiểm tra bảng rỗng
    bool isEmpty() {
        return n == 0;
    }

    //trả về số lượng cặp khóa - giá trị trong bảng
    int size() {
        return n;
    }

    //kiểm tra có giá trị nào được nối với khóa
    bool contains(string key) {
        for (int i = 0; i < n; i++)
            if (keys[i] == key) return true;
        return false;
    }

    //lấy giá trị được nối với khóa
    string get(string key) {
        for (int i = 0; i < n; i++)
            if (keys[i] == key)
                return values[i];
        return "null";
    }

    //đặt một cặp khóa - giá trị vào bẩng
    void put(string key, string value) {
        if (value == "null") return;

        for (int i = 0; i < n; i++) {
            if (keys[i] == key) {
                values[i] = value;
                return;
            }
        }

        if (n >= MAX) {
            return;
        }

        keys[n] = key;
        values[n] = value;
        n++;
    }

    //xoa khóa
    void deleteKey(string key) {
        for (int i = 0; i < n; i++) {
            if (keys[i] == key) {
                for (int j = i; j < n - 1; j++) {
                    keys[j] = keys[j + 1];
                    values[j] = values[j + 1];
                }
                n--;
                return;
            }
        }
    }

    //các khóa trong bảng
    void printKeys() {
        for (int i = 0; i < n; i++)
            cout << keys[i] << " ";
    }
};

int main() {

}

