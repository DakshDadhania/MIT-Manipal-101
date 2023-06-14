#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

const int MAX_N = 100000;
int head[MAX_N], nxt[MAX_N], to[MAX_N], cnt;

void add_edge(int u, int v) {
    nxt[++cnt] = head[u];
    head[u] = cnt;
    to[cnt] = v;
}

void bfs(int start) {
    queue<int> q;
    bool visited[MAX_N] = {false};
    int level[MAX_N] = {0};
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int i = head[node]; i != 0; i = nxt[i]) {
            int next = to[i];
            if (!visited[next]) {
                visited[next] = true;
                level[next] = level[node] + 1;
                q.push(next);

                if (level[next] >= 4) {
                    cout << next << endl;
                }
            }
        }
    }
}

int main() {
    int n, m;
    cout << "Enter no of vertices and edges: ";
    cin >> n >> m;

    cnt = 0;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        add_edge(u, v);
    }

    cout << "Enter starting vertex: ";
    int start;
    cin >> start;

    bfs(start);

    return 0;
}
