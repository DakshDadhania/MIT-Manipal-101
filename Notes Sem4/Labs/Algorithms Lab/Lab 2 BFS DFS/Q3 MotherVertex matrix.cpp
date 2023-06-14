#include<iostream>
using namespace std;
int n;
int motherve(int w,int visited[],int arr[][20]){
    int u,v,i;
    int count=0;
    for(i=1;i<n+1;i++){
        visited[i]=0;
    }
    int s[20],top=-1;
    s[++top]=w;
    visited[w]=1;
    while(top!=-1){
        u=s[top--];
        count++;
        for(v=1;v<=n+1;v++){
            if(arr[u][v]==1 && visited[v]==0){
                s[++top]=v;
                visited[v]=1;
            }
        }
    }
    return count;
}
int main(){
    int m;
    cout<<"Enter the no of vertices";
    cin>>m;
    n=m;
    int adjmat[20][20],i,j;
    for(i=1;i<=m;i++){
        for(j=1;j<=m;j++){
           adjmat[i][j]=0;
        }
    }
    int u,v;
    cout<<"Enter the position of vertices that are adjacent";
    for(i=1;i<=m;i++){
        for(j=1;j<n+1;j++){
            cin>>u>>v;
            if(u>0 & v>0)
                adjmat[u][v]=1;
            else    
                break;
        }
        if(u<1 || v<1)
            break;
}
cout<<"Adjacency matrix";
for(i=1;i<=m;i++){
    for(j=1;j<=m;j++){
        cout<<adjmat[i][j]<<" ";
    }
    cout<<endl;
}
int visited[n];
for(i=1;i<=n;i++){
    visited[i]=0;
}
for(i=1;i<n+1;i++){
    if(motherve(i,visited,adjmat)==n){
            cout<<"Mother vertex is "<<i;
            break;
        }
    }
    return 0;
}