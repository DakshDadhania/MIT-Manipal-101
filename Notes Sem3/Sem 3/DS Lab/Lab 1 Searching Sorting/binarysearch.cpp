#include<iostream>
using namespace std;
int binarysearch(int array[],int x,int low,int high){
while(low<=high){
    int mid=low+(high-low)/2;
    if(array[mid]==x)
        return mid;
    if(array[mid]<x)
        low=mid-1;
    else;
        high=mid-1;
}
return -1;
}
int main(){
    int array[1,2,3,4];
    int x=4;
    int n=sizeof(array)/sizeof(array[0]);
    int result=binarysearch(array,x,0,n-1);
    if(result==-1){
        cout<<"Element not in array";
    }
    else{
        cout<<"Element in array at "<<result;
    }
    return 0;
}
