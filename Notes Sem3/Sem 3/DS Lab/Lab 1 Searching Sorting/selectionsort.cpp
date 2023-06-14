#include<iostream>
using namespace std;

int selectionsort(int arr[],int n){
    int temp,position;
    for(int i=0;i<n-1;i++){
        position=i;
        for(int j=i+1;j<n;j++){
            if(arr[position]>arr[j]){
                position=j;
            }
        }
        if(position!=i){
            temp=arr[i];
            arr[i]=arr[position];
            arr[position]=temp;
        }

    }
}
int main(){
    int arr[100];
    int n;
    cout<<"enter no of elements";
    cin>>n;
    cout<<"enter the elements \n";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    selectionsort(arr,n);
    for(int i=0;i<n;i++){
        cout<<" "<<arr[i];
    }
return 0;
}
