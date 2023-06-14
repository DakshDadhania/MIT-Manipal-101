#include<iostream>
using namespace std;
void merge(int *arr,int s,int e){
    int mid=(s+e)/2;
    int len1=mid-s+1;
    int len2=e-mid;

    int *k=new int[len1];
    int *l=new int[len2];
    int ll=s;
    for(int i=0;i<len1;i++){
        k[i]=arr[ll++];
    }

    for(int i=0;i<len2;i++){
        l[i]=arr[ll++];
    }

    int index1=0;
    int index2=0;
    ll=s;
    while(index1<len1 && index2<len2){
        if(k[index1]<l[index2]){
            arr[ll++]=k[index1++];

        }
        else{
            arr[ll++]=l[index2++];

        }
    }
    while(index1<len1){
        arr[ll++]=k[index1++];

    }
    while(index2<len2){
        arr[ll++]=l[index2++];
    }



}
void mergesort(int *arr,int s, int e){
    if(s>=e){
        return ;
    }
    int mid=(s+e)/2;
    mergesort(arr,s,mid);

    mergesort(arr,mid+1,e);

    merge(arr,s,e);

}
int main(){
    int arr[]={1,2,3435,32,342,4,4,52,5,46,2,4,3,2,542};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<n;
    mergesort(arr,0,n-1);

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;

}