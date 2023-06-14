#include <bits/stdc++.h>
using namespace std;

const int MAX = 100;
int n, maxclique;
int graph[MAX][MAX];
int d[MAX];
bool v[MAX];

bool is_clique(int b) {
    for (int i = 1; i < b; i++) {
        for (int j = i + 1; j < b; j++) {
            if (graph[v[i]][v[j]] == 0) {
                return false;
            }
        }
    }
    return true;
}

int bound(int i, int l) {
    int cnt = 0;
    for (int j = i + 1; j <= n; j++) {
        if (graph[v[i]][j]) {
            cnt++;
        }
    }
    return l + cnt;
}

void maxCliques(int i, int l) {
    if (i > n) {
        if (is_clique(l)) {
            maxclique = max(maxclique, l);
        }
        return;
    }
    v[l + 1] = i;
    if (is_clique(l + 1)) {
        maxclique = max(maxclique, l + 1);
        maxCliques(i + 1, l + 1);
    }
    if (bound(i, l) > maxclique) {
        maxCliques(i + 1, l);
    }
}

int main() {
    int edges[][2] = { { 1, 2 }, { 2, 3 }, { 3, 1 }, { 4, 2 } };
    int size = 4;
    n = 4;
    for (int i = 0; i < size; i++) {
        graph[edges[i][0]][edges[i][1]] = 1;
        graph[edges[i][1]][edges[i][0]] = 1;
        d[edges[i][0]]++;
        d[edges[i][1]]++;
    }
    maxclique = 1;
    maxCliques(1, 0);
    cout << "Maximum Clique Size: " << maxclique << endl;
    return 0;
}
