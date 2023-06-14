#include<iostream>
//iterative binary search
int count=0;
using namespace std;
int binarysearch(int arr[], int h, int l,int ele){
    while(h>=l){

    count++;
    count++;
    int mid=(h+l)/2;

    if(arr[mid]==ele){
            count++;
        return mid;
    }
    else if(arr[mid]>ele){
        count++;
        h=mid-1;
    }
    else {
        count++;
        l=mid+1;
    }
    }
    count++;

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

      cout<<"\n"<<"No of steps for the ->"<< h<<" -> elements is -> "<<count;
       cout<<"\n"<<" The time complexicity is log n where n = "<<h;
    return 0;
}
