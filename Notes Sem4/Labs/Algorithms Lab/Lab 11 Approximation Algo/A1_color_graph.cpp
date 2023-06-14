#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m; // number of vertices and edges

    vector<vector<int>> adj(n);
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    if(n <= 4) {
        cout << n << "\n"; // planar graph with n vertices needs at most n colors
        return 0;
    }

    vector<int> colors(n, -1);
    colors[0] = 0; // assign first vertex color 0

    for(int i = 1; i < n; i++) {
        vector<bool> used(n, false);
        for(int j = 0; j < adj[i].size(); j++) {
            int v = adj[i][j];
            if(colors[v] != -1) {
                used[colors[v]] = true;
            }
        }
        for(int j = 0; j < 4; j++) {
            if(!used[j]) {
                colors[i] = j;
                break;
            }
        }
    }

    int max_color = 0;
    for(int i = 0; i < n; i++) {
        max_color = max(max_color, colors[i]);
    }

    cout << max_color + 1 << "\n"; // minimum number of colors needed is the maximum color + 1

    return 0;
}
