#include<iostream>
using namespace std;
void sort(int* arr,int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if (*(arr + j) > *(arr + j+1)) {
 
                int t = *(arr + j);
                *(arr + j) = *(arr + j+1);
                *(arr + j+1) = t;
            }
        }
    }
    for (int i = 0; i < n; i++)
        cout<< *(arr + i)<<" ";
}
int main(){
    int n ;
    cout<<"Enter no of elements in array?\n";
    cin>>n;
    int arr[n] ;
    for(int i=0;i<n;i++){
        cout<<"Enter element"<<i+1<<" :";
        cin>>arr[i];
    }
    cout<<"\nSorted array :";
    sort(arr, n);
    return 0;
}