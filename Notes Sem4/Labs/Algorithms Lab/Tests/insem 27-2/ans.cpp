#include<iostream>
#include<stack>
using namespace std;

void printPaths(int v, int A[][10], int start, int k) {
    bool visited[10] = {false};
    stack<pair<int,string>> s;
    s.push({start,to_string(start)});
    while (!s.empty()) {
        int curr = s.top().first;
        string path = s.top().second;
        s.pop();
        visited[curr] = true;
        if (path.length() >= k) {
            cout << path << endl;
            
        }
        for (int i = 1; i <= v; i++) {
            if (A[curr][i] == 1 && !visited[i]) {
                s.push({i,path+to_string(i)});
            }
        }
    }
}

int main() {
    int v, e, start;
    cout << "Enter no of vertices and edges: ";
    cin >> v >> e;
    int A[10][10] = {0};
    cout << "Enter edges:\n";
    for (int i = 0; i < e; i++) {
        int x, y;
        cin >> x >> y;
        A[x][y] = 1;
    }
    cout << "Enter starting vertex: ";
    cin >> start;
    cout << "Paths of length 3 or greater from vertex " << start << ":\n";
    printPaths(v, A, start, 3);
    return 0;
}
