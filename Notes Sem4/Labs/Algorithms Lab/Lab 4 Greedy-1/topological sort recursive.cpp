#include <iostream>
#include <vector>
#include <stack>
using namespace std;

const int MAX = 100;

int adj[MAX][MAX], visited[MAX], n;

void dfs(int v, vector<int> &res) {
    visited[v] = 1;
    for (int i = 0; i < n; i++) {
        if (adj[v][i] && !visited[i]) {
            dfs(i, res);
        }
    }
    res.push_back(v);
}

vector<int> topologicalSort() {
    vector<int> res;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i, res);
        }
    }
    reverse(res.begin(), res.end());
    return res;
}

int main() {
    int e, x, y;
    cout << "Enter the number of vertices: ";
    cin >> n;
    cout << "Enter the number of edges: ";
    cin >> e;
    for (int i = 0; i < e; i++) {
        cout << "Enter edge (x, y): ";
        cin >> x >> y;
        adj[x][y] = 1;
    }
    vector<int> sorted = topologicalSort();
    cout << "Topological sort: ";
    for (int i = 0; i < sorted.size(); i++) {
        cout << sorted[i] << " ";
    }
    cout << endl;
    return 0;
}
