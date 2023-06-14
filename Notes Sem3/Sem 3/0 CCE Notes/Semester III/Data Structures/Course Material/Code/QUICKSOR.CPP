#include<iostream>

using namespace std;
int partition(int *,int,int);
void print(int a[],int n);

void quick(int a[],int low, int high, int n)
{
 int pivot,i,j,temp;
 if(low<high)
 {
  i=low;
  j=high+1;
  pivot=a[low];
  do
  {
   do
   {
    i++;
   }while(a[i]<pivot);
   do
   {
    j--;
   }while(a[j]>pivot);
   if(i<j)
   {
    temp=a[i];
    a[i]=a[j];
    a[j]=temp;
    cout<<"\nI and J change: \n \n";
    print(a, n);
   }
  }while(i<j);
  temp=a[low];
  a[low]=a[j];
  a[j]=temp;
   cout<<"\nPivot change: \n \n";
  print(a, n);
  quick(a,low,j-1, n);

  quick(a,j+1,high, n);
 }
}

void print(int a[],int n)
{
     static int coun = 1;
 cout<<"\n"<< coun++;
 for(int i=0;i<n;i++)
   cout<<a[i]<<"   ";
}

int main()
{

 int a[20], low, high,n;
 cout<<"Enter the number of elements:  ";
 cin>>n;
 low=0;
 high=n-1;
 cout<<"Enter the elements: ";
 for(int i=0;i<n;i++)
   cin>>a[i];
 cout<<"Calling quick sort function:";

 quick(a,low,high, n);

 print(a,n);
 return 0;
}
