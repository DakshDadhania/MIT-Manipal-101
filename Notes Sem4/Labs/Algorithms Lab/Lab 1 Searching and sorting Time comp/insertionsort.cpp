#include<iostream>
using namespace std;
int count=0;
void insertionsort(int arr[],int n){
    for(int i=0;i<n;i++){
            count++;
            count++;
        int key=arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>key){
                count++;
            arr[j+1]=arr[j];
            count++;
            j--;
        }
        count++;
        arr[j+1]=key;
    }
    count++;
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
    insertionsort(arr,n);

    for(int i=0;i<n;i++){
        cout<<"Enter the "<<i+1<<"th element -";
        cout<<arr[i]<<"\n";
    }

      cout<<"\n"<<"No of steps for the ->"<< n<<" -> elements is -> "<<count;
       cout<<"\n"<<" The time complexicity is n^2 where n = "<<n;
    return 0;
}
