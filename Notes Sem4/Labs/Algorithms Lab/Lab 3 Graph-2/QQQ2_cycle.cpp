#include<iostream>
#include<stack>

using namespace std;
stack<int> stk;

void cycle(int start,int current,int a[][10],int v,int e,int visited[]){
    visited[current]=1;
    stk.push(current);
    if(start==current && stk.size()>2){
        cout<<"cycle found"<<"\n";
        while(!stk.empty()){
            cout<<stk.top()<<" ";
            stk.pop();
        }
    }
    else{
        for(int i=1;i<=v;i++){
            if(a[current][i]==1 && visited[i]==0){
                cycle(start,i,a,v,e,visited);
            }
        }
    }
    //backtrcking
    visited[current]=0;
    stk.pop();
}
int main(){
    int v,e;
    cout<<"Enter the no of vertices and edges";
    cin>>v>>e;
    int a[10][10];
    for(int i=0;i<=v;i++){
        for(int j=0;j<=v;j++){
            a[i][j]=0;
        }
    }
   
    for(int i=0;i<e;i++){
        int x,y;
        cin>>x>>y;
        a[x][y]=1;
        
    }
     for(int i=1;i<=v;i++){
        for(int j=1;j<=v;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
  
    int visited[11]={0};
   
   for(int i=0;i<=v;i++){
        for(int j=0;j<=v;j++){
            cycle(i,j,a,v,e,visited);
        }
   }

}