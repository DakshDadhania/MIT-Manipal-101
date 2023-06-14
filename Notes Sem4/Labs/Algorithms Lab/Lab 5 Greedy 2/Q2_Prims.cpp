#include <bits/stdc++.h>
using namespace std;

// function to find the vertex with the minimum distance value
int findMinVertex(bool *visited, int *distance, int v) {
    int minIndex = -1, minVal = INT_MAX;

    // loop through all the vertices
    for (int i = 0; i < v; i++) {
        // if the vertex is unvisited and its distance value is smaller than the minimum value
        if (!visited[i] && distance[i] < minVal) {
            // update the minimum value and index
            minVal = distance[i];
            minIndex = i;
        }
    }

    // return the index of the vertex with the minimum distance value
    return minIndex;
}

int main() {
    // read the number of vertices and edges
    int v, e;
    cin >> v >> e;

    // create the adjacency matrix
    int **adj = new int *[v];
    for (int i = 0; i < v; i++)
        adj[i] = new int[v];
    for (int i = 0; i < v; i++)
        for (int j = 0; j < v; j++)
            adj[i][j] = 0;

    // read the edges and weights and update the adjacency matrix
    for (int i = 0; i < e; i++) {
        int l, r, w;
        cin >> l >> r >> w;
        adj[l][r] = adj[r][l] = w;
    }

    // create the visited array and initialize all vertices to unvisited
    bool *visited = new bool[v];
    for (int i = 0; i < v; i++)
        visited[i] = false;

    // create the distance array and initialize all vertices to infinity
    int *distance = new int[v];
    for (int i = 0; i < v; i++)
        distance[i] = INT_MAX;

    // create the parent array to store the minimum spanning tree
    int *parent = new int[v];
    parent[0] = -1;

    // set the distance of the starting vertex to 0
    distance[0] = 0;

    // loop through all the vertices
    for (int i = 0; i < v - 1; i++) {
        // find the vertex with the minimum distance value among the unvisited vertices
        int curr = findMinVertex(visited, distance, v);
        visited[curr] = true;

        // update the distance value and parent of all the adjacent vertices if it can be reduced
        for (int j = 0; j < v; j++) {
            if (!visited[j] && adj[curr][j] != 0 && adj[curr][j] < distance[j]) {
                
                parent[j] = curr;
                cout<<parent[j]<<endl;
                distance[j] = adj[curr][j];
            }
        }
    }

    // print the minimum spanning tree
    cout << "Edges\tWeight\n";
    for (int i = 1; i < v; i++)
        cout << parent[i] << " - " << i << "\t" << adj[i][parent[i]] << "\n";

    return 0;
}
