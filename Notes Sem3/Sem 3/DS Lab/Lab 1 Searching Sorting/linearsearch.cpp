#include<iostream>
using namespace std;
int linearsearch(int arr[],int n,int x){
for(int i=0;i<n;i++){
    if(arr[i]==x){
        return i;
    }
}
return -1;
}
int main(){
    int array[]={2,4,0,1,9};
    int x=1;
    int n=sizeof(array)/sizeof(array[0]);
    int result=linearsearch(array,n,x);
    if(result==-1){
        cout<<"Element not in array";
    }
    else{
        cout<<"Element in array at "<<result;
    }
    return 0;
}
