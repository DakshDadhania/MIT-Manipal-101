#include<iostream>
//recursive binary search
using namespace std;
int binarysearch(int arr[], int h, int l,int ele){
    int mid=(h+l)/2;
    if(l>h){
        return -2;
    }
    if(arr[mid]==ele){
        return mid;
    }
    else if(arr[mid]>ele){
        binarysearch(arr,mid-1,l,ele);
    }
    else {
        binarysearch(arr,h,mid+1,ele);
    }

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
