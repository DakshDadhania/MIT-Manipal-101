#include<iostream>
using namespace std;
void printarray(int array[],int n){
for(int i=0;i<n;i++){
    cout<<array[i]<<" ";
    }
    cout<<endl;
}
void insertionsort(int array[],int n){
    for(int i=1;i<n;i++){
        int key=array[i];
        int j=i-1;
        while(key<array[j]&& j>=0){
            array[j+1]=array[j];
            j--;
        }
        array[j+1]=key;
    }
}

int main(){
int arr[100];
    int n;
    cout<<"enter no of elements";
    cin>>n;
    cout<<"enter the elements \n";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    insertionsort(arr,n);
    for(int i=0;i<n;i++){
        cout<<" "<<arr[i];
    }
return 0;

}
