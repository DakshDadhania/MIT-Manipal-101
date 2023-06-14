#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 100;

int graph[MAXN][MAXN]; // Adjacency matrix to store the graph
bool visited[MAXN]; // Array to keep track of visited nodes
vector<int> path; // Vector to keep track of the current path

void findAllCycles(int start, int current, int n) {
    visited[current] = true; // Mark the current node as visited
    path.push_back(current); // Add the current node to the path

    // If we've reached back to the starting node and the path contains more than 2 nodes, we've found a cycle
    if (start == current && path.size() > 2) {
        cout << "Cycle found: ";
        for (int i = 0; i < path.size(); i++) {
            cout << path[i] << " ";
        }
        cout << endl;
    } else {
        // Check all the neighbors of the current node
        for (int i = 0; i < n; i++) {
            if (graph[current][i] == 1) { // If there is an edge from the current node to the i-th node
                if (!visited[i]) { // If the i-th node has not been visited, recursively call the function with i as the current node
                    findAllCycles(start, i, n);
                } else if (i == start) { // If the i-th node has been visited and it is the starting node, recursively call the function with i as the current node
                    findAllCycles(start, i, n);
                }
            }
        }
    }

    visited[current] = false; // Unmark the current node as visited
    path.pop_back(); // Remove the current node from the path
}

int main() {
    int n, m, x, y;
    cin >> n >> m;

    // Read the graph
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        graph[x][y] = 1;
        //graph[y][x] = 1;
    }

    // Find all cycles starting from each node
    for (int i = 0; i < n; i++) {
        findAllCycles(i, i, n);
    }

    return 0;
}
