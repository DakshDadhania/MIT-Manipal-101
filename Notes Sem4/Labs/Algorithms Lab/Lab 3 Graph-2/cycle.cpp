#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 1000;

vector<int> adj[MAXN];
bool visited[MAXN];
int parent[MAXN];

bool dfs(int v) {
    visited[v] = true;
    for (int i = 0; i < adj[v].size(); i++) {
        int u = adj[v][i];
        if (!visited[u]) {
            parent[u] = v;
            if (dfs(u)) {
                return true;
            }
        } else if (parent[v] != u) {
            return true;
        }
    }
    return false;
}

int main() {
    int n, m, x, y;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    bool cycle = false;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            if (dfs(i)) {
                cycle = true;
                break;
            }
        }
    }
    if (cycle) {
        cout << "The graph contains a cycle" << endl;
    } else {
        cout << "The graph does not contain a cycle" << endl;
    }
    return 0;
}
