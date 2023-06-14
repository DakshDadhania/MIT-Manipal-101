#include <bits/stdc++.h>
using namespace std;

const int MAX = 100;

int graph[MAX][MAX], n;
int max_independent_set = 0, curr_independent_set = 0;
bool visited[MAX];

bool isSafe(int v) {
    for (int i = 0; i < n; i++) {
        if (graph[v][i] && visited[i]) {
            return false;
        }
    }
    return true;
}

void maxIndependentSet(int v) {
    if (v == n) {
        if (curr_independent_set > max_independent_set) {
            max_independent_set = curr_independent_set;
        }
        return;
    }
    if (isSafe(v)) {
        visited[v] = true;
        curr_independent_set++;
        maxIndependentSet(v+1);
        curr_independent_set--;
        visited[v] = false;
    }
    maxIndependentSet(v+1);
}

int main() {
    cout << "Enter the number of vertices: ";
    cin >> n;

    cout << "Enter the adjacency matrix of the graph:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }

    maxIndependentSet(0);

    cout << "The maximum independent set of the given graph has " << max_independent_set << " vertices." << endl;

    return 0;
}
