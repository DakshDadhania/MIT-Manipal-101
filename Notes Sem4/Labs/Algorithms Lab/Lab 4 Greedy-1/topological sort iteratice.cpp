#include <iostream>
#include <stack>
using namespace std;

const int MAX = 100; // maximum number of vertices

int adj[MAX][MAX], visited[MAX], n; // adjacency matrix, visited array, and number of vertices

void dfs(int v, stack<int> &st) {
    visited[v] = 1; // mark the current vertex as visited
    for (int i = 0; i < n; i++) {
        if (adj[v][i] && !visited[i]) { // if there is an edge from the current vertex to i and i is not visited
            dfs(i, st); // recursively call dfs on i
        }
    }
    st.push(v); // push the current vertex to the stack after visiting all of its neighbors
}
    
void topologicalSort() {
    stack<int> st; // create a stack to store the vertices in topologically sorted order
    for (int i = 0; i < n; i++) {
        if (!visited[i]) { // if the current vertex has not been visited
            dfs(i, st); // call dfs on the current vertex
        }
    }
    while (!st.empty()) { // pop the vertices from the stack to get the topologically sorted order
        cout << st.top() << " ";
        st.pop();
    }
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
        adj[x][y] = 1; // set the corresponding element in the adjacency matrix to 1 to indicate an edge from x to y
    }
    cout << "Topological sort: ";
    topologicalSort(); // call the topologicalSort function
    cout << endl;
    return 0;
}
