#include<iostream>
using namespace std;
int main(){
    int a[100][100],b[100][100],c[100][100],n;
    cout<<"Enter the order of matrix:";
    cin>>n;
    cout<<"Enter matrix a";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }
    cout<<"enter 2 nd matrix:";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>b[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(a[i][j]>b[i][j]){
                c[i][j]=a[i][j];
            }
            else{
                c[i][j]=b[i][j];
            }
        }
    }
     for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<c[i][j]<<" ";
        }
        cout<<"\n";
    }

    return 0;
}
