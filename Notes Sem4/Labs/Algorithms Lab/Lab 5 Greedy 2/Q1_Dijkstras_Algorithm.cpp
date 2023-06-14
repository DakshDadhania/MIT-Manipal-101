#include <bits/stdc++.h>
using namespace std;

// function to find the vertex with the minimum distance value
int findMinVertex(bool *visited, int *distance, int v) {
    int minIndex, minVal = INT_MAX;

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
        adj[l][r] = w;
    }

    // create the visited array and initialize all vertices to unvisited
    bool *visited = new bool[v];
    for (int i = 0; i < v; i++)
        visited[i] = false;

    // read the starting vertex
    int sv;
    cout << "Enter start vertex: ";
    cin >> sv;

    // create the distance array and initialize all vertices to infinity
    int *distance = new int[v];
    distance[sv] = 0;
    for (int i = 0; i < v; i++)
        if (i != sv)
            distance[i] = INT_MAX;

    // loop through all the vertices
    for (int i = 0; i < v; i++) {
        // find the vertex with the minimum distance value among the unvisited vertices
        int curr = findMinVertex(visited, distance, v);
        cout<<curr<<" ";
        visited[curr] = true;
        // update the distance value of all the adjacent vertices if it can be reduced
        for (int j = 0; j < v; j++)
            if (!visited[j] && adj[curr][j] != 0)
                if (distance[j] > distance[curr] + adj[curr][j])
                    distance[j] = distance[curr] + adj[curr][j];
    }

    // print the shortest distance from the starting vertex to all other vertices
    for (int i = 0; i < v; i++) {
        cout << i << " -> ";
        if (distance[i] == INT_MAX)
            cout << "unreachable"
                 << "\n";
        else
            cout << distance[i] << "\n";
    }

    return 0;
}
