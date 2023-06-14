#include <iostream>
using namespace std;
int arr[100];
int n=0;
void merge(int a[],int low,int mid,int high){
   int n=0;
    int left=low,right=mid+1;
    while(left<=mid && right<=high){
        if(a[left]<=a[right]){
            arr[n]=a[left];
            n++;
            left++;
        }
        else{
            arr[n]=a[right];
            n++;
            right++;
        }
    }
    while(left<=mid){
        arr[n]=a[left];;
        n++;
        left++;
    }
    while(right<=high){
        arr[n]=a[right];
        n++;
        right++;

    }
    for(int i=low;i<=high;i++){
        a[i]=arr[i-low];
    }
}

void mergesort(int a[], int low, int high)
{
    if(low>=high){
       return;
    }
    int mid = (low + high) / 2;
    mergesort(a, low, mid);
    mergesort(a, mid + 1, high);
    merge(a,low,mid,high);
}

int main(){
    int a[]={1,2,6,232,2,36,45,73,45,2,2,56,32};
   
    int n=13;
    mergesort(a,0,n-1);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
     return 0;
}

//Time comp- O(nlogn)

//spcae comp- O(n)