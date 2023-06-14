#include <iostream>
#include <vector>
#include <stack>
using namespace std;

const int MAXN = 100005;
vector<int> adj[MAXN], radj[MAXN];
bool visited[MAXN];
stack<int> st;

void dfs1(int u) {
    visited[u] = true;
    for (int i = 0; i < adj[u].size(); i++) {
        int neighbor = adj[u][i];
        if (!visited[neighbor]) {
            dfs1(neighbor);
        }
    }
    st.push(u);
}

void dfs2(int u, vector<int>& component) {
    visited[u] = true;
    component.push_back(u);
    for (int i = 0; i < radj[u].size(); i++) {
        int neighbor = radj[u][i];
        if (!visited[neighbor]) {
            dfs2(neighbor, component);
        }
    }
}

void findSCC(int n) {
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs1(i);
        }
    }
    for (int i = 1; i <= n; i++) {
        visited[i] = false;
    }
    while (!st.empty()) {
        int u = st.top();
        st.pop();
        if (!visited[u]) {
            vector<int> component;
            dfs2(u, component);
            cout << "SCC: ";
            for (int i = 0; i < component.size(); i++) {
                cout << component[i] << " ";
            }
            cout << endl;
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        radj[v].push_back(u);
    }
    findSCC(n);
    return 0;
}
//Time complexity: O(V+E) for adjacency list representation.
