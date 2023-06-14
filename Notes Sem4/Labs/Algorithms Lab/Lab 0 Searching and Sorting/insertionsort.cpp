#include<iostream>
using namespace std;
void swap(int* a,int* b){
    int* p=a;
    a=b;
    b=p;
}
void insertionsort(int arr[],int n){
    for(int i=0;i<n;i++){
        int key=arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
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
    insertionsort(arr,n);
    for(int i=0;i<n;i++){
        cout<<"Enter the "<<i+1<<"th element -";
        cout<<arr[i]<<"\n";
    }
    return 0;
}
