#include <iostream>
#include <vector>
using namespace std;

struct canh {
    int u, v;
};

struct ds_canh {
    int n;
    vector<canh> canh;

    ds_canh(int dinh) {
        n = dinh;
    }

    void tcanh(int u, int v) {
        canh.push_back({u, v});
    }

    void print() {
        for (auto &c : canh)
            cout << "(" << c.u << "," << c.v << ")\n";
    }
};

