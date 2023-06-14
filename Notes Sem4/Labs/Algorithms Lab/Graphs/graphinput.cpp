#include<bits/stdc++.h>
using namespace std;
#include<queue>
void adjmatrix()
{
 int n,m;  // m lines ie m edges and n vertex /nodes
 cin>>n>>m;
 int adj[n+1][m+1];
 for(int i=0;i<m;i++){
    int u,v;
    cin>>u,v;
    adj[u][v]=1;
    adj[v][u]=1; // its undirected graph

 } 
}
void adjlist(){
    int n,m;
    cin>>n>>m;
    vector<int> adj[n+1];
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u); // this line not required for directed graph 


    }
}
vector<int> BFS(int v,vector<int> adj[],int n){
    int vis[n]={0};
    vis[0]=1;
    queue<int> q;
    vector<int> bfs;
    while(!q.size()){
        int node=q.front();
        q.pop();
        bfs.push_back(node);
        for(auto i:adj[node]){
            if(!vis[i]){
                vis[i]=1;
                q.push(i);
            }
        }
    }
    return bfs;
}
vector<int> DFS(int v,vector<int> adj[], int n){
    
}  


int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
//   int t;
//   cin>>t;
//   while(t--) 
  adjmatrix();
}