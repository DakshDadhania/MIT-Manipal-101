#include<iostream>
using namespace std;
int count=0;
void swap(int* a,int* b){
    int* p=a;
    a=b;
    b=p;
}
void selectionsort(int arr[],int n){
    count++;
    int i, j, minn;
    for (i = 0; i < n-1; i++)
    {
        count++;
        count++;
        minn= i;
        for (j = i+1; j <   n; j++)
            count++;
        {
            if (arr[j] < arr[minn])
                {   count++;
                    minn = j;

                }
        }
        count++;
        count++;
        if(minn!=i)
        {
            count++;
             swap(arr[minn], arr[i]);
        }


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
    selectionsort(arr,n);
    for(int i=0;i<n;i++){
        cout<<"Enter the "<<i+1<<"th element -";
        cout<<arr[i]<<"\n";
    }

      cout<<"\n"<<"No of steps for the ->"<< n<<" -> elements is -> "<<count;
      cout<<"\n"<<" The time complexicity is n^2 where n = "<<n;
    return 0;
}
