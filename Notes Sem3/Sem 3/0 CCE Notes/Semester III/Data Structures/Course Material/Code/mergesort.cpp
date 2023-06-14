#include<iostream>
//#include<conio.h>
//#include<process.h>
#define MAX 20
using namespace std;

void mergesort(int a[],int sort1[], int i, int m, int n)
{
 int j,k,t;
 j=m+1;
 k=i;
 while(i<=m && j<=n)
 {
  if(a[i]<=a[j])
      sort1[k++]=a[i++];
  else
      sort1[k++]=a[j++];
 }
 while(i<=m)
   sort1[k++]=a[i++];
 while(j<=n)
   sort1[k++]=a[j++];
}



void merge_pass(int a[], int sort1[], int n, int len)
{
 int i, j;
 for(i=0;i<=n-2*len;i=i+2*len)
   mergesort(a,sort1,i,i+len-1,i+2*len-1);
 if(i+len<n)
   mergesort(a,sort1,i,i+len-1,n-1);
 else
   for(j=i;j<n;j++)
      sort1[j]=a[j];
}



void merge1(int a[], int n)
{
 int len=1;
 int s[MAX];
 while(len<n)
 {
  merge_pass(a,s,n,len);
  len=len*2;
  merge_pass(s,a,n,len);
  len=len*2;
 }
}


int main()
{
    int n;
    cout<<"How many elements? ";
    cin>>n;
   int a[n];
   cout<<"\nEnter the elements: ";
   for(int i=0; i<n;i++)
    cin>>a[i];
   cout<<"\nBefore Merge sort: ";
   for(int i=0; i<n;i++)
    cout<<a[i]<<"   ";
   merge1(a, n);
   cout<<"\nAfter Merge sort: ";
   for(int i=0; i<n;i++)
    cout<<a[i]<<"   ";
   return 0;
}
