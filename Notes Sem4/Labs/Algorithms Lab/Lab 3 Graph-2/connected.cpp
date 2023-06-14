#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAXN = 1000;

vector<int> adj[MAXN];
bool visited[MAXN];

void bfs(int v) {
    queue<int> q;
    q.push(v);
    visited[v] = true;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i = 0; i < adj[u].size(); i++) {
            int w = adj[u][i];
            if (!visited[w]) {
                visited[w] = true;
                q.push(w);
            }
        }
    }
}

int main() {
    int n, m, x, y;
    cin >> n >>m;
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        adj[x].push_back(y);
     //   adj[y].push_back(x);
    }
    bfs(1);
    bool connected = true;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            connected = false;
            break;
        }
    }
    if (connected) {
        cout << "The graph is connected" << endl;
    } else {
        cout << "The graph is not connected" << endl;
    }
    return 0;
}
