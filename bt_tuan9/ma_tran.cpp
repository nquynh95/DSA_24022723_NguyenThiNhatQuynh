#include <iostream>
using namespace std;

const int N = 100;

struct ma_tran_ke{
    int n;
    int adj[N][N];

    ma_tran_ke(int dinh){
        n = dinh;
        for (int i = 0; i <= n; i++)
            for (int j = 0; j <= n; j++)
                adj[i]j[j] = 0;
    }

    void canh(int u, int v){
        adj[u][v] = 1;
        adj[v][u] = 1; //đồ thị vô hướng
    }

    void print(){
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++)
                cout << adj[i][j] << " ";
            cout << "\n";
        }
    }
};
