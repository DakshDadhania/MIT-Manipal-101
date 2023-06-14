#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 1000;

vector<int> adj[MAXN];   // Adjacency list to store the graph
bool visited[MAXN];      // Array to store the visited nodes

bool dfs(int v, int t) {  // DFS function to traverse the graph
    visited[v] = true;    // Mark the node as visited
    if (v == t) {         // If the target node is found, return true
        return true;
    }
    for (int i = 0; i < adj[v].size(); i++) {  // Loop through all the neighbors of v
        int u = adj[v][i];                    // Get the neighbor of v
        if (!visited[u]) {                    // If the neighbor is not visited
            if (dfs(u, t)) {                  // Recursively check if there is a path from neighbor to target
                return true;                  // If true, return true
            }
        }
    }
    return false;                              // If no path found, return false
}

int main() {
    int n, m, x, y;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {         // Input the graph as edges
        cin >> x >> y;
        adj[x].push_back(y);
    //  adj[y].push_back(x);            // Since the graph is undirected, add edges for both vertices
    }
    int s, t;
    cout<<"Enter the vertices to find path from towards which?";
    cin >> s >> t;                      // Input the start and target vertices
    if (dfs(s, t)) {                    // Call DFS function to find if there is a path
        cout << "There is a path from " << s << " to " << t << endl;
    } else {
        cout << "There is no path from " << s << " to " << t << endl;
    }
    return 0;
}
