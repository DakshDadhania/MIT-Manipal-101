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
        int min = 0;
        for(int j=i+1;j<n;j++){
            if(arr[min]>arr[j]){
                min=j;
            }
        }

        if(arr[min]!=arr[i]){
            int temp = arr[i];
            arr[i]=arr[min];
            arr[min]=temp;
        }

    }

  cout<<"selection sort sorted array: ";
    for(i=0;i<n;i++)
        cout<<arr[i]<<" ";


    return 0;
}
