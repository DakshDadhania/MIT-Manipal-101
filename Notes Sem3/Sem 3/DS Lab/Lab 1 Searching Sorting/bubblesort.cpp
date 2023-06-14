#include<iostream>
using namespace std;
void bubblesort(int array[],int n){
for(int j=0;j<n-1;j++){
    for(int i=0;i<n-j-1;i++){
       if(array[i]>array[i+1]){
        int temp=array[i];
        array[i]=array[i+1];
        array[i+1]=temp;
       }
    }
}
}
int main(){
    int data[100];
    cout<<"Enter the no of elements ";
    int n;
    cin>>n;
    cout<<"Enter the elements \n";
    for(int i=0;i<n;i++){
        cin>>data[i];
    }
    bubblesort(data,n);
    cout<<"Sorted array";
    for(int i=0;i<n;i++){
        cout<<" "<<data[i];
    }
    return 0;
}
