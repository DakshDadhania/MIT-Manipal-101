#include <iostream>
using namespace std;

int main(){
    int arr[10],n,i;
    cout<<"enter the size of the of array: ";
    cin>>n;

    cout<<"enter the array elements: ";
    for(i=0;i<n;i++)
        cin>>arr[i];


 for(i=0;i<n-1;i++){
    for(int j=i;j<n;j++){
        if(arr[j]>arr[j+1]){
            int temp = arr[j];
            arr[j]=arr[j+1];
            arr[j+1]=temp;
        }
    }
 }

    cout<<"bubble sort sorted array: ";
    for(i=0;i<n;i++)
        cout<<arr[i]<<" ";

 return 0;
}
