#include<iostream>
#include <stack>
using namespace std;
void path(int v,int e,int A[][10],int visited[],int start,int cnt){
    stack<int> s;
   for(int i=0;i<10;i++){
        visited[i]=0;
    }
    s.push(start);
    visited[start]=1;
    while(!s.empty()){
        int x=s.top();
        s.pop();
        cout<<x<<" ";
        cnt--;
        if(cnt==0){
            break;
        }
        for(int i=1;i<=v;i++){
            if(A[x][i]==1 && visited[i]==0){
                s.push(i);
                visited[i]=1;
            }
        }
    }
}
int main(){
    int v,e;
    cout<<"Enter no of vertices and edges";
    cin>>v>>e;
    int A[10][10];
    int visited[10]={0};
    for(int i=0;i<=v;i++){
        for(int j=0;j<=v;j++){
            A[i][j]=0;
        }
    }
    for(int i=1;i<=e;i++){
        int x,y;
        cin>>x>>y;
        A[x][y]=1;
       
    }
    cout<<"Enter start vertex";
    int start;
    cin>>start;

    for(int i=2;i<=v;i++){
            path(v,e,A,visited,1,i);
            cout<<endl;
    }
    return 0;


}