#include <bits/stdc++.h>
using namespace std;

// function to find the vertex with the maximum distance value
int findMaxVertex(bool *visited, int *distance, int v)
{
    int maxIndex = -1, maxVal = INT_MIN;

    // loop through all the vertices
    for (int i = 0; i < v; i++)
    {
        // if the vertex is unvisited and its distance value is greater than the maximum value
        if (!visited[i] && distance[i] > maxVal)
        {
            // update the maximum value and index
            maxVal = distance[i];
            maxIndex = i;
        }
    }

    // return the index of the vertex with the maximum distance value
    return maxIndex;
}

int main()
{
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
    for (int i = 0; i < e; i++)
    {
        int l, r, w;
        cin >> l >> r >> w;
        adj[l][r] = -w; // negate the edge weight
        adj[r][l] = -w; // for an undirected graph
    }

    // create the visited array and initialize all vertices to unvisited
    bool *visited = new bool[v];
    for (int i = 0; i < v; i++)
        visited[i] = false;

    // read the starting vertex
    int sv;
    cout << "Enter start vertex: ";
    cin >> sv;

    // create the distance array and initialize all vertices to minus infinity
    int *distance = new int[v];
    for (int i = 0; i < v; i++)
        if (i == sv)
            distance[i] = 0;
        else
            distance[i] = INT_MIN;

    // loop through all the vertices
    for (int i = 0; i < v; i++)
    {
        // find the vertex with the maximum distance value among the unvisited vertices
        int curr = findMaxVertex(visited, distance, v);
        visited[curr] = true;
        // update the distance value of all the adjacent vertices if it can be increased
        for (int j = 0; j < v; j++)
            if (!visited[j] && adj[curr][j] != 0)
                if (distance[j] < distance[curr] + adj[curr][j])
                {
                    distance[j] = distance[curr] + adj[curr][j];
                }
    }
    // print the distance of all the vertices from the starting vertex
    cout << "Vertex    Distance from source\n";
    for (int i = 0; i < v; i++)
    {
        if (distance[i] == INT_MIN)
            cout << i << "        "
                 << "INFINITY\n";
        else
            cout << i << "        " << distance[i] << "\n";
    }

    // update the distance value of all the adjacent vertices if it can be increased
    for (int j = 0; j < v; j++)
    {
        if (!visited[j] && adj[curr][j] != 0)
        {
            if (distance[j] < distance[curr] + adj[curr][j])
            {
                distance[j] = distance[curr] + adj[curr][j];
            }
        }
    }
    // print the distance of all the vertices from the starting vertex
    cout << "Vertex    Distance from source\n";
    for (int i = 0; i < v; i++)
    {
        if (distance[i] == INT_MIN)
            cout << i << "        "
                 << "INFINITY\n";
        else
            cout << i << "        " << distance[i] << "\n";
    }

    return 0;
}