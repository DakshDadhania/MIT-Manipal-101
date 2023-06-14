#include<iostream>
using namespace std;
void bubblesort(int W[],int pos[],int n){
    int i,j;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(W[j]>W[j+1]){
                int temp1=W[j];
                W[j]=W[j+1];
                W[j+1]=W[j];
                temp1=pos[j];
                pos[j]=pos[j+1];
                pos[j+1]=pos[j];
            }
        }
    }
}
int main(){
    int n,c;
    cout<<"Enter the value of no of items";
    cin>>n;
    cout<<"Enter the total capacity";
    cin>>c;
    int P[n];
   int W[n];
   int X[n]={0};
   int pos[n];
   cout<<"Enter the weights, price"<<endl;
   for(int i=0;i<n;i++){
    cin>>W[i]>>P[i];
    pos[i]=i;
   }
   int PbyW[n];
   for(int i=0;i<n;i++){
    PbyW[i]=P[i]/W[i];
   }
   bubblesort(PbyW,pos,n);
   for(int i=0;i<n && W[i]<=c;i++){
    X[pos[i]]=1;
    c-=W[i];
   }
   cout<<"selected items";
   for(int i=0;i<n;i++){
    cout<<X[i]<<" ";
   }
}
