#include<bits/stdc++.h>
using namespace std;
#define V 100

int graph[V][V];

int primMST(int n)
{
    int parent[n];
    int key[n];
    bool mstSet[n];
    for (int i = 0; i < n; i++)
    {
        key[i] = INT_MAX;
        mstSet[i] = false;
    }
    key[0] = 0;
    parent[0] = -1;
    for (int count = 0; count < n-1; count++)
    {
        int u = -1;
        for(int i = 0; i < n; i++)
        {
            if(!mstSet[i] && (u == -1 || key[i] < key[u]))
                u = i;
        }
        mstSet[u] = true;
        for(int v = 0; v < n; v++)
        {
            if(graph[u][v] && !mstSet[v] && graph[u][v] < key[v])
            {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }
    int cost = 0;
    for(int i = 1; i < n; i++)
    {
        cost += graph[i][parent[i]];
    }
    return cost;
}

int main()
{
    int n;
    cout << "Enter the number of vertices: ";
    cin >> n;
    cout << "Enter the adjacency matrix:\n";
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> graph[i][j];
        }
    }
    int mst_cost = primMST(n);
    cout << "Minimum Spanning Tree cost: " << mst_cost << endl;
    int tsp_cost = 2*mst_cost;
    cout << "Approximate TSP cost using MST: " << tsp_cost << endl;
    return 0;
}
