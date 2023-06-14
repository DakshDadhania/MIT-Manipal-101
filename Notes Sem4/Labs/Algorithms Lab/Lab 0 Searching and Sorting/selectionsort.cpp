#include<iostream>
using namespace std;
void swap(int* a,int* b){
    int* p=a;
    a=b;
    b=p;
}
void selectionsort(int arr[],int n){
    int i, j, minn;
    for (i = 0; i < n-1; i++)
    {
        minn= i;
        for (j = i+1; j <   n; j++)
        {if (arr[j] < arr[minn])
            minn = j;
        }
        if(minn!=i)
            swap(arr[minn], arr[i]);
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
    selectionsort(arr,n);
    for(int i=0;i<n;i++){
        cout<<"Enter the "<<i+1<<"th element -";
        cout<<arr[i]<<"\n";
    }
    return 0;
}
