#include<iostream>
using namespace std;
void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
int fun(int a[], int low,int high){
    int pivot=a[low];
    int i=low;
    int j=high;
    while(i<j){
        while(a[i]<=pivot && i<=high-1){
            i++;
        }
        while (a[j]>pivot && j>=low+1)
        {
            j--;
        }
        if(i<j){
            swap(a[i],a[j]);
        }
        
    }
    swap(a[j],a[low]);

    return j;


}
void quick(int a[],int low,int high){
    if (low<high){
        int partition=fun(a,low,high);
        quick(a,low,partition-1);
        quick(a,partition+1,high);
    }
}
int main(){
     int a[]={1,2,6,232,2,36,45,73,45,2,2,56,32};
   cout<<"hi";
    int n=13;
    quick(a,0,n-1);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    return 0;

}



//time comp- O(nlong)
//space comp- O(1)