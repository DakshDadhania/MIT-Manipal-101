#include <iostream>
#include <queue>
// To check if a graph is connected, we can perform a traversal (BFS or DFS) starting from any vertex and see if we are able to visit all other vertices. If we are able to visit all vertices, then the graph is connected. Otherwise, it is not connected.
using namespace std;

void bfs(int a[][10], int n, int source, bool visited[]) {
    queue<int> q;
    visited[source] = true;
    q.push(source);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v = 1; v <= n; v++) {
            if (a[u][v] && !visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
}

bool is_connected(int a[][10], int n) {
    bool visited[n + 1] = {false};
    bfs(a, n, 1, visited);

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            return false;
        }
    }
    return true;
}


int main() {
    int n, e;
    cout << "Enter the number of vertices: ";
    cin >> n;
    int a[10][10] = {0};

    cout << "Enter the number of edges: ";
    cin >> e;

    cout << "Enter the edges:\n";
    for (int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        a[u][v] = 1;
        a[v][u] = 1;
    }

    if (is_connected(a, n)) {
        cout << "The graph is connected.\n";
    } else {
        cout << "The graph is not connected.\n";
    }

    return 0;
}
