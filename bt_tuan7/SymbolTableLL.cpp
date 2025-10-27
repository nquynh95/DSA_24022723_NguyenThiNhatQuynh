#include <iostream>
#include <string>
using namespace std;

struct Node {
    string key;
    string value;
    Node* next;
    Node(string k, string v) : key(k), value(v), next(nullptr) {}
};

struct SymbolTable {
    Node* head;
    int n;

    SymbolTable() : head(nullptr), n(0) {}

    //kiểm tra bảng rỗng
    bool isEmpty() {
        return head == nullptr;
    }

    //trả về số lượng cặp khóa - giá trị trong bảng
    int size() {
        return n;
    }

    //kiểm tra có giá trị nào được nối với khóa
    bool contains(string key) {
        Node* p = head;
        while (p) {
            if (p->key == key) return true;
            p = p->next;
        }
        return false;
    }

    //lấy giá trị được nối với khóa
    string get(string key) {
        //trả về null nếu không thấy key
        Node* p = head;
        while (p) {
            if (p->key == key) return p->value;
            p = p->next;
        }
        return "null";
    }

    //đặt một cặp khóa - giá trị vào bẩng
    void put(string key, string value) {
        if (value == "null") return;

        Node* p = head;
        while (p) {
            //ghi đè giá trị mới lên giá trị cũ
            if (p->key == key) {
                p->value = value;
                return;
            }
            p = p->next;
        }

        Node* newNode = new Node(key, value);
        newNode->next = head;
        head = newNode;
        n++;
    }

    //xóa khóa
    void deleteKey(string key) {
        Node* p = head;
        Node* prev = nullptr;

        while (p) {
            if (p->key == key) {
                if (prev) prev->next = p->next;
                else head = p->next;
                delete p;
                n--;
                return;
            }
            prev = p;
            p = p->next;
        }
    }

    //các khóa trong bảng
    void keys() {
        Node* p = head;
        while (p) {
            cout << p->key << " ";
            p = p->next;
        }
    }
};

int main() {
}
