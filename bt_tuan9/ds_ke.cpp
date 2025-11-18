#include <iostream>
#include <vector>
using namespace std;

const int N = 100;

struct ds_ke {
    int n;
    vector<int> adj[N];

    ds_ke(int dinh) {
        n = dinh;
    }

    void dinhke(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u); //đồ thị vô hướng
    }

    void print() {
        for (int i = 1; i <= n; i++) {
            cout << i << ": ";
            for (int v : adj[i]) cout << v << " ";
            cout << "\n";
        }
    }
};

