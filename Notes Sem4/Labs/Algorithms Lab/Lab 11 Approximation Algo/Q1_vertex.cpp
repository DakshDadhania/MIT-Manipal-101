#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1005;

int n, m, ans = INT_MAX;
vector<int> G[MAXN];
bool vis[MAXN], used[MAXN];

void dfs(int u) {
    vis[u] = true;
    for (auto v : G[u]) {
        if (!vis[v]) {
            dfs(v);
            used[u] |= !used[v];
        } else {
            used[u] |= !used[v];
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    for (int i = 1; i <= n; ++i) {
        if (!vis[i]) {
            dfs(i);
            if (used[i]) {
                ans++;
            }
        }
    }
    cout << ans << endl;
    for (int i = 1; i <= n; ++i) {
        if (used[i]) {
            cout << i << " ";
        }
    }
    return 0;
}
