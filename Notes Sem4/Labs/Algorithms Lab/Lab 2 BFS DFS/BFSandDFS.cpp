#include <iostream>
#include <queue>
#include <stack>
using namespace std;
int mothervertex(int t,int visited[],int a[][10],int v){
    int count=0;

    for(int i=1;i<=v+1;i++){
        visited[i]=0;
    }
    stack<int> stk;
    stk.push(t);
    visited[t]=1;
    while(!stk.empty()){
        int u=stk.top();
        stk.pop();
        count++;
        for(int i=1;i<=v;i++){
            if(a[u][i]==1 && visited[i]==0){
                stk.push(i);
                visited[i]=1;
            }
        }
    }
    return count;
}
void BFS(int v, int e, int visited[], int start, int a[][10])
{
    queue<int> q;
    visited[start] = 1;
    q.push(start);
    while (!q.empty())
    {
        int w;
        w = q.front();
        q.pop();

        for (int u = 1; u <= v; u++)
        {
            if (a[w][u] == 1 && visited[u] == 0)
            {
                q.push(u);
                visited[u] = 1;
            }
        }
        cout << w << " -> ";
    }
}
// recursive bfs not possible in adj matrix

void DFS(int v, int a[][10], int visited[], int n)
{
    int u;
    cout << v << " ";
    visited[v] = 1;
    for (u = 1; u <= n; u++)
    {
        if (!visited[u] && a[v][u] == 1)
            DFS(u, a, visited, n);
    }
}
void dfs(int source, int arr[][10], int visited[], int n)
{
    int u, v, i;
    for (i = 1; i <= n + 1; i++)
    {
        visited[i] = 0;
    }
    stack<int> stk;
    stk.push(source);

    visited[source] = 1;
    while (!stk.empty())
    {
        u = stk.top();
        stk.pop();
        cout << u << " ";
        for (v = 1; v <= n; v++)
        {
            if (arr[u][v] == 1 && visited[v] == 0)
            {
                stk.push(v);
                visited[v] = 1;
            }
        }
    }
}

int main()
{

    int n, A[10][10], v, e;
    cout << "Enter the no of vertices";
    cin >> v;
    cout << "Enter the no of edges ";
    cin >> e;
    for (int i = 0; i <= v; i++)
    {
        for (int j = 0; j <= v; j++)
        {
            A[i][j] = 0;
        }
    }

    int p, q;
    for (int i = 1; i <= e; i++)
    {
        cout << "enter source";
        cin >> p;
        cout << "enter destination";
        cin >> q;
        A[p][q] = 1;
      //  A[q][p] = 1; for mother vertex only directed graph works
    }
    int Btransp[10][10];
    for (int i = 0; i <= v; i++)
    {
        for (int j = 0; j <= v; j++)
        {
            Btransp[j][i] = A[i][j];
        }
    }
    for (int i = 1; i <= v; i++)
    {
        for (int j = 1; j <= v; j++)
        {
            cout << A[i][j] << " ";
        }
        cout << "\n";
    }

    cout << "Enter starting vertex";
    int start;
    cin >> start;
    int visited[v + 1] = {0};
    cout << "BFS for the graph \n";
    BFS(v, e, visited, start, A);
    cout << "\n";
    cout << "The Transpose of the graph matrix";
    cout << "\n";
    for (int i = 1; i <= v; i++)
    {
        for (int j = 1; j <= v; j++)
        {

            cout << Btransp[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n"
         << "DFS For the graph  ";
    dfs(start, A, visited, v);


    cout<<"\n"<<"\n";
    for(int i=1;i<=v;i++){
        if(mothervertex(i,visited,A,v)==v){
                cout<<"Mother vertex is "<<i;
                break;
            }
    }
    return 0;
}
