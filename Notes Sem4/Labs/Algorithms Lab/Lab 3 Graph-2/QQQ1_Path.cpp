#include<iostream>
#include<stack>

using namespace std;
stack<int> stk;

void path(int start,int end,int a[][10],int v,int e,int visited[]){
    visited[start]=1;
    stk.push(start);
    if(start==end){
        while(!stk.empty()){
            cout<<stk.top()<<" ";
            stk.pop();}}
    else{
        for(int i=1;i<=v;i++){
            if(a[start][i]==1 && visited[i]==0){
                path(i,end,a,v,e,visited);
            }}}
    visited[start]=0;
    stk.pop();
}
int main(){
    int v,e;
   
    int a[10][10];
    cout<<"Enter the no of vertices and edges"<<endl;
    cin>>v>>e;
    for(int i=1;i<=v;i++){
        for(int j=1;j<=v;j++){
            a[i][j]=0;
        }
    }
    cout<<"Enter the edges"<<endl;
    for(int i=0;i<e;i++){
        int x,y;
        cin>>x>>y;
        a[x][y]=1;
        // a[y][x]=1;
    }
    for(int i=1;i<=v;i++){
        for(int j=1;j<=v;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"Enter the source and destination"<<endl;
    int start,end;
    cin>>start>>end;
    int visited[11]={0};
    path(start,end,a,v,e,visited);

    return 0;
}