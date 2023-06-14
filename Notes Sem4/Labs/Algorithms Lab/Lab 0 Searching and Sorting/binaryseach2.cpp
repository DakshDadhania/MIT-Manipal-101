#include<iostream>
//iterative binary search
using namespace std;
int binarysearch(int arr[], int h, int l,int ele){
    while(h>=l){
    int mid=(h+l)/2;
    if(arr[mid]==ele){
        return mid;
    }
    else if(arr[mid]>ele){
        h=mid-1;
    }
    else {
        l=mid+1;
    }
    }
    return -2;
}
int main(){
    cout<<"Binary Search program \n";
    cout<<"Enter the no of elements in the array \n";
    int h;
    cin>>h;
    int arr[h];
    int l=0;
    for(int i=0;i<h;i++){
        cout<<"Enter "<<i+1<<"th element";
        cin>>arr[i];
    }
    cout<<"Enter the element to be searched? ";
    int ele;
    cin>>ele;

    cout<<"Element at position "<<binarysearch(arr,h-1,l,ele)+1;
    return 0;
}
