#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 100;

int graph[MAXN][MAXN]; // adjacency matrix representation of the graph
bool visited[MAXN]; // array to keep track of visited nodes during traversal
vector<int> path; // vector to store the current path being traversed

// Recursive function to find all paths from start to end
void findAllPaths(int start, int end, int n) {
    visited[start] = true; // mark the current node as visited
    path.push_back(start); // add the current node to the path vector
    if (start == end) { // if we have reached the end node
        // print the path to the console
        for (int i = 0; i < path.size(); i++) {
            cout << path[i] << " ";
        }
        cout << endl;
    } else {
        // iterate over all neighbors of the current node
        for (int i = 0; i < n; i++) {
            if (graph[start][i] == 1 && !visited[i]) { // if the neighbor has not been visited
                findAllPaths(i, end, n); // recursively traverse the neighbor node
            }
        }
    }
    visited[start] = false; // backtrack by unmarking the current node as visited
    path.pop_back(); // remove the current node from the path vector
}

int main() {
    int n, m, x, y;
    cin >> n >> m; // read the number of nodes and edges in the graph
    for (int i = 0; i < m; i++) {
        cin >> x >> y; // read the endpoints of each edge
        graph[x][y] = 1; // mark the edge in the adjacency matrix
        graph[y][x] = 1; // mark the edge in the adjacency matrix (assuming the graph is undirected)
    }
    int s, t;
    cin >> s >> t; // read the start and end nodes for the path traversal
    findAllPaths(s, t, n); // find all paths from start to end
    return 0;
}

//input
//6 7
//0 1
//0 2
//1 3
//1 4
//2 4
//3 5
//4 5
//0 5
