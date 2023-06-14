#include<iostream>
#include<queue>
using namespace std;

const int MAX = 100;

int n, adj[MAX][MAX];
bool visited[MAX];

void dfs(int v) {
    visited[v] = true;
    for (int i = 0; i < n; i++) {
        if (adj[v][i] && !visited[i]) {
            dfs(i);
        }
    }
}

void bfs(int v) {
    queue<int> q;
    q.push(v);
    visited[v] = true;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i = 0; i < n; i++) {
            if (adj[u][i] && !visited[i]) {
                visited[i] = true;
                q.push(i);
            }
        }
    }
}

int findComponents() {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i); // or bfs(i)
            count++;
        }
    }
    return count;
}

int main() {
    cout << "Enter the number of vertices: ";
    cin >> n;

    cout << "Enter the adjacency matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
                cin >> adj[i][j];
        }
    }

    int count = findComponents();

    cout << "The graph has " << count << " component(s).\n";

    return 0;
}
//Time complexity: O(V^2) for adjacency matrix representation and O(V+E) for adjacency list representation.
