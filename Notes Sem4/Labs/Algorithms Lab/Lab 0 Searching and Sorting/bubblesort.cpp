#include<iostream>
using namespace std;
void swap(int* a,int* b){
    int* p=a;
    a=b;
    b=p;
}
void bubblesort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j+1]<arr[j]){
                swap(arr[j+1],arr[j]);
            }
        }
    }
}
int main(){
    int n;
    cout<<"Enter the no of elements in array";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cout<<"Enter the "<<i+1<<"th element";
        cin>>arr[i];
    }
    bubblesort(arr,n);
    for(int i=0;i<n;i++){
        cout<<"Enter the "<<i+1<<"th element -";
        cout<<arr[i]<<"\n";
    }
    return 0;
}
