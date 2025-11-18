#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int N = 100;
vector<int> adj[N];
int visited[N];

void bfs(int s) {
    queue<int> q;
    visited[s] = 1;
    q.push(s);

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        for (int u : adj[v]) {
            if (!visited[u]) {
                visited[u] = 1;
                q.push(u);
            }
        }
    }
}
