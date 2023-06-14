#include <iostream>
#include <stack>
using namespace std;

void printAllPaths(int v, int e, int A[][10], int visited[], int path[], int start, int pathLen) {
    stack<int> s;
    s.push(start);
    visited[start] = true;

    while (!s.empty()) {
        int curr = s.top();
        bool hasUnvisitedNeighbor = false;
        for (int i = 1; i <= v; i++) {
            if (A[curr][i] && !visited[i]) {
                s.push(i);
                visited[i] = true;
                path[pathLen++] = i;
                hasUnvisitedNeighbor = true;
                break;
            }
        }
        if (!hasUnvisitedNeighbor) {
            if (pathLen >= 3 && path[0] == 1) {
                for (int i = 0; i < pathLen; i++) {
                    cout << path[i];
                }
                cout << endl;
            }
            s.pop();
            visited[curr] = false;
            pathLen--;
        }
    }
}

int main() {
    int v, e;
    cout << "Enter no of vertices and edges: ";
    cin >> v >> e;
    int A[10][10] = {0};
    int visited[10] = {0};
    int path[10] = {0};
    cout << "Enter edges: " << endl;
    for (int i = 1; i <= e; i++) {
        int x, y;
        cin >> x >> y;
        A[x][y] = 1;
    }
    cout << "Enter starting vertex: ";
    int start;
    cin >> start;

    for (int i = 3; i <= v; i++) {
        printAllPaths(v, e, A, visited, path, start, 1);
    }
    return 0;
}
