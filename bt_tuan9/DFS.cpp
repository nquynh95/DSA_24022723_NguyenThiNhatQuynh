#include <iostream>
#include <vector>
using namespace std;

const int N = 100;
vector<int> adj[N];
int visited[N];

void dfs(int s) {
    stack<int> st;
    st.push(s);
    visited[s] = 1;

    while (!st.empty()) {
        int v = st.top();
        st.pop();

        for (int u : adj[v]) {
            if (!visited[u]) {
                visited[u] = 1;
                st.push(u);
            }
        }
    }
}
